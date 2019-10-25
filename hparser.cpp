#include <string>
#include <list>
#include <map>
#include "ast.h"
#include "hparser.h"
#include <memory>


using namespace std;
using namespace AST;

int HParser::parse() {
  ast_ = program();
  return 0;
}


ProgramNode* HParser::program() {
  match_token(LNG::TN::t_program);
  string name = token_.text;
  match_token(LNG::TN::t_identifier);
  match_token(LNG::TN::t_semicolon);
  scope_ = "";
  auto block_node = main_block();
  match_token(LNG::TN::t_dot);
  match_token(LNG::TN::t_eoi);
  return new ProgramNode(name, block_node);
}


BlockNode* HParser::main_block() {
  auto var_decl = variable_declarations();
  cout << "variable declarations done in main block" << endl;
  auto call_decl = callable_declarations();
  cout << "callable declarations done in main block" << endl;
  auto cstmt = compound_statement();
  return new BlockNode(var_decl, call_decl, cstmt);
}


VariableDeclarationsNode* HParser::variable_declarations( ) {
  if (match_token_if(LNG::TN::t_var)) {
    list<VariableDeclNode *> declarations;
    auto decl = variable_declaration();
    declarations.push_back(decl);
    match_token(LNG::TN::t_semicolon);
    while (token(LNG::TN::t_identifier)) {
      decl = variable_declaration();
      declarations.push_back(decl);
      match_token(LNG::TN::t_semicolon);
    }
    return new VariableDeclarationsNode(declarations);
  }
  return nullptr;
}


VariableDeclNode* HParser::variable_declaration( ) {
  list<string> identifiers;
  do {
    identifiers.push_back(token_.text);
    match_token(LNG::TN::t_identifier);
  } while (match_token_if(LNG::TN::t_comma));
  match_token(LNG::TN::t_colon);
  LNG::DataType data_type = type();
  for (auto &id : identifiers) {
    auto entry = symbol_table_.lookup(scope_, id);
    if (entry != nullptr) {
      error(token_.loc, "Duplicate identifier '" + id + "'");
    }
    symbol_table_.add_var(scope_, id, data_type);
  }
  return new VariableDeclNode(identifiers, data_type);
}


LNG::DataType HParser::type() {
  LNG::SimpleDataType sdt = LNG::SimpleDataType::tVoid;
  int from = 0, to = 0;
  if (match_token_if(LNG::TN::t_array)) {
    match_token(LNG::TN::t_lbracket);
    std::unique_ptr<IntegerExprNode> p_from(integer_constant());
    from = p_from.get()->get_value();
    match_token(LNG::TN::t_subrange);
    std::unique_ptr<IntegerExprNode> p_to(integer_constant());
    to = p_to.get()->get_value();
    match_token(LNG::TN::t_rbracket);
    match_token(LNG::TN::t_of);
  }
  sdt = simple_type();
  return Language::DataType(sdt, from, to);
}


LNG::SimpleDataType HParser::simple_type() {
  LNG::SimpleDataType sdt = LNG::SimpleDataType::tVoid;
  if (match_token_if(LNG::TN::t_boolean)) {
    sdt = LNG::SimpleDataType::tBoolean;
  } else if (match_token_if(LNG::TN::t_real)) {
    sdt = LNG::SimpleDataType::tReal;
  } else {
    match_token(LNG::TN::t_integer);
    sdt = LNG::SimpleDataType::tInteger;
  }
  return sdt;
}


StringExprNode* HParser::string_constant() {
  const string text = token_.text;
  match_token(LNG::TN::t_string_l);
  return new StringExprNode(text);
}


IntegerExprNode* HParser::integer_constant() {
  int number = 0;
  if (token_.name == LNG::TN::t_integer_l) {
    number = std::stoi(token_.text);
    match_token(LNG::TN::t_integer_l);
  } else {
    error(token_.loc, "Expected integer constant.");
  }
  return new IntegerExprNode(number);
}


VariableNode* HParser::variable_lvalue(SymbolTable::Entry& entry, const string& identifier ) {
  string variable_name;
  ExprNode *expr = nullptr;
  if (identifier.empty()) {
    variable_name = token_.text;
    match_token(LNG::TN::t_identifier);
  } else variable_name = identifier;
  if ( entry.data_type.is_array() ) {
    match_token(LNG::TN::t_lbracket);
    expr = expression();
    match_token(LNG::TN::t_rbracket);
  }
  return new VariableNode(variable_name, expr);
}


CompoundStmtNode* HParser::compound_statement() {
  list<StmtNode *> statements;
  match_token(LNG::TN::t_begin);
  do {
    statements.push_back(statement());
  } while (match_token_if(LNG::TN::t_semicolon));
  match_token(LNG::TN::t_end);
  return new CompoundStmtNode(statements);
}


StmtNode* HParser::statement() {
  StmtNode *stmt = nullptr;
  if (token(LNG::TN::t_identifier)) {
    auto entry = symbol_table_.lookup("", token_.text);
    if (entry != nullptr && entry->entry_type == SymbolTable::EntryType::sProcedure) {
      stmt = procedure_call_statement();
    } else {
      stmt = assignment_statement();
    }
  } else if (token(LNG::TN::t_begin)) {
    stmt = compound_statement();
  } else if (token(LNG::TN::t_if)) {
    stmt = if_statement();
  } else if (token(LNG::TN::t_while)) {
    stmt = while_statement();
  } else if (token(LNG::TN::t_read) || token(LNG::TN::t_read) ) {
    stmt = read_statement();
  } else if (token(LNG::TN::t_write) || token( LNG::TN::t_writeln)) {
    stmt = write_statement();
  } else {
    stmt = empty_statement();
  }
  return stmt;
}


AssignmentStmtNode* HParser::assignment_statement(string identifier ) {
  if (identifier.empty()) {
    identifier = token_.text;
    match_token(LNG::TN::t_identifier);
  }
  auto entry = symbol_table_.lookup(scope_, identifier);
  if (entry == nullptr && !scope_.empty()) {
    entry = symbol_table_.lookup("", identifier);
  }
  if (entry == nullptr) {
    error(token_.loc, "Undeclared identifier \"" + token_.text + "\"");
  }
  VariableNode *var = variable_lvalue(*entry, identifier);
  match_token(LNG::TN::t_assign);

  ExprNode *expr = expression();
  return new AssignmentStmtNode(var, expr);
}


EmptyStmtNode* HParser::empty_statement() {
  cout << "====> SymbolTable in empty" << endl;
  for ( auto entry : symbol_table_.get() ) {
    cout << entry.first << ' ' << entry.second.str() << endl;
  }
  return new EmptyStmtNode();
}


ReadStmtNode* HParser::read_statement( ) {
  bool newline = false;
  if (match_token_if(LNG::TN::t_readln)) {
    newline = true;
  } else {
    match_token(LNG::TN::t_read);
  }
  match_token(LNG::TN::t_lparenthesis);
  auto entry = symbol_table_.lookup(scope_, token_.text);
  if (entry == nullptr && !scope_.empty()) {
    entry = symbol_table_.lookup("", token_.text);
  }
  if (entry == nullptr) {
    error(token_.loc, "Identifier not found \"" + token_.text + "\"");
  }
  auto var = variable_lvalue( *entry );
  match_token(LNG::TN::t_rparenthesis);
  return new ReadStmtNode(var, newline);
}


WriteStmtNode* HParser::write_statement( ) {
  ExprNode *expr = nullptr;
  bool newline = false;
  if (match_token_if(LNG::TN::t_writeln)) {
    newline = true;
  } else {
    match_token(LNG::TN::t_write);
  }
  match_token(LNG::TN::t_lparenthesis);
  if (token(LNG::TN::t_string_l)) {
    expr = string_constant();
  } else {
    expr = expression();
  }
  match_token(LNG::TN::t_rparenthesis);
  return new WriteStmtNode(expr, newline);
}


ExprNode* HParser::actual_parameter() {
  return expression();
}


ExprNode* HParser::expression() {
  static map<LNG::TN, LNG::EO> relational_op = {
      {LNG::TN::t_eq, LNG::EO::o_eq},
      {LNG::TN::t_neq, LNG::EO::o_neq},
      {LNG::TN::t_lt, LNG::EO::o_lt},
      {LNG::TN::t_lteq, LNG::EO::o_lteq},
      {LNG::TN::t_gt, LNG::EO::o_gt},
      {LNG::TN::t_gteq, LNG::EO::o_gteq}};

  auto expr = simple_expression();
  auto it = operator_in(relational_op);
  while (it != relational_op.end()) {
    auto expr_rhs = simple_expression();
    expr = new OpExprNode(it->second, expr, expr_rhs);
    it = operator_in(relational_op);
  }
  return expr;
}


ExprNode* HParser::factor() {
  ExprNode *expr = nullptr;
  if (token(LNG::TN::t_identifier)) {
    auto entry = symbol_table_.lookup(scope_, token_.text);
    if (entry == nullptr && !scope_.empty()) {
      entry = symbol_table_.lookup("", token_.text);
    }
    if (entry == nullptr) {
      error(token_.loc, "Identifier not found \"" + token_.text + "\"");
    }
    if (entry->entry_type == SymbolTable::EntryType::sFunction) {
      string identifier(token_.text);
      match_token(LNG::TN::t_identifier);
      expr = function_call(identifier);
    } else {
      expr = variable_rvalue( *entry );
    }
  } else if (token(LNG::TN::t_lparenthesis)) {
    match_token(LNG::TN::t_lparenthesis);
    expr = expression();
    match_token(LNG::TN::t_rparenthesis);
  } else {
    expr = constant();
  }
  return expr;
}


ExprNode* HParser::constant() {
  ExprNode *expr = nullptr;
  if (token(LNG::TN::t_true) || token(LNG::TN::t_false)) {
    expr = boolean_constant();
  } else if (token(LNG::TN::t_real_l)) {
    expr = real_constant();
  } else {
    expr = integer_constant();
  }
  return expr;
}


//////////////////////////////////////////////////////////////////////////////


ProcedureDeclNode* HParser::procedure_declaration() {
  //match_token(LNG::TN::t_procedure);
  string identifier(token_.text);
  scope_ = identifier;
  match_token(LNG::TN::t_identifier);
  auto params = optional_parameters();
  string signature = "";
  cout << "before the for" << endl;
  if(params != nullptr){
    for(auto i : params->get_declarations()){
      cout << "in first for line 327" << endl;
      cout << "i type: " << i->get_data_type().str() << endl;
      int count = 0;
      for(auto j : i->get_identifiers()){
        cout << "j: " << j << endl;
        count++;
      }
      for(int k = 0; k < count; k++){
        signature += i->get_data_type().str() +  ",";
      }
    }
  }
  if(signature != ""){
    signature = signature.substr(0, signature.length()-1);
  }
  symbol_table_.add_procedure(identifier, signature);   // TO DO: Implement ... set signature
  match_token(LNG::TN::t_semicolon);
  auto block_node = block();
  match_token(LNG::TN::t_semicolon);
  scope_ = "";
  return new ProcedureDeclNode(identifier, params, block_node);
}


//////////////////////////////////////////////////////////////////////////////

CallableDeclarationsNode* HParser::callable_declarations() {

  bool loop = true;
  list<CallableDeclNode *> declarations;
  /* TO DO: Implement ... */
  while(loop){
    if(match_token_if(LNG::TN::t_procedure)){
      cout << "line 356 done" << endl;
      auto procedure = procedure_declaration();
      cout << "line 358 done" << endl;
      declarations.push_back(procedure);
    }
    else if(match_token_if(LNG::TN::t_function)){
      auto function = function_declaration();
      declarations.push_back(function);
    }
    else{
      cout << "loop false" << endl;
      loop = false;
    }
  }
  return new CallableDeclarationsNode(declarations);
}


VariableDeclarationsNode* HParser::optional_parameters() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */

  if(match_token_if(LNG::TN::t_lparenthesis)){
    list<VariableDeclNode*> declarations;
    auto list = parameter_list();
    declarations.push_back(list);
    while(match_token_if(LNG::TN::t_semicolon)){
      auto newList = parameter_list();
      declarations.push_back(newList);
    }
    match_token(LNG::TN::t_rparenthesis);
    return new VariableDeclarationsNode(declarations);
  }
  return nullptr;
}


VariableDeclNode* HParser::parameter_list() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  std::list<std::string> idenitfiers;
  string identifier1(token_.text);
  match_token(LNG::TN::t_identifier);
  idenitfiers.push_back(identifier1);
  while(match_token_if(LNG::TN::t_comma)){
    string newIdentifier(token_.text);
    match_token(LNG::TN::t_identifier);
    idenitfiers.push_back(newIdentifier);
  }
  match_token(LNG::TN::t_colon);
  auto dType = simple_type();
  LNG::DataType newType = LNG::DataType(dType);
  auto expr = new VariableDeclNode(idenitfiers, newType);
  return expr;
}


FunctionDeclNode* HParser::function_declaration() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */

  //match_token(LNG::TN::t_function);
  string identifier(token_.text);
  scope_ = identifier;
  match_token(LNG::TN::t_identifier);
  auto params = optional_parameters();
  match_token(LNG::TN::t_colon);
  auto type = simple_type();
  LNG::DataType dType = LNG::DataType(type);
  match_token(LNG::TN::t_semicolon);
  string signature = "";
  if(params != nullptr){
    for(auto i : params->get_declarations()){
      cout << "i type: " << i->get_data_type().str() << endl;
      int count = 0;
      for(auto j : i->get_identifiers()){
        cout << "j: " << j << endl;
        count++;
      }
      for(int k = 0; k < count; k++){
        signature += i->get_data_type().str() +  ",";
      }
    }
  }
  if(signature != ""){
    signature = signature.substr(0, signature.length()-1);
  }
  // add signature to the symbol table
  symbol_table_.add_function(identifier, signature, dType);

  auto block_node = block();
  match_token(LNG::TN::t_semicolon);
  scope_ = "";

  cout << "returning from function declaration"  << endl;
  auto retVal = new FunctionDeclNode(identifier, params, block_node, dType);
  return retVal;
}


BlockNode* HParser::block() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  auto vars = variable_declarations();
  auto statements = compound_statement();
  auto retVal = new BlockNode(vars, statements);
  cout << "returnging from block: " << endl;
  return retVal;
}


IfStmtNode* HParser::if_statement() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  match_token(LNG::TN::t_if);
  auto expr = expression();
  match_token(LNG::TN::t_then);
  auto ifStatement = statement();
  StmtNode *elseStateMnt  = nullptr;
  if (match_token_if(LNG::TN::t_else)) {
    elseStateMnt = statement();
  }
  IfStmtNode* retVal = new IfStmtNode(expr, ifStatement, elseStateMnt);
  return retVal;
}

OptionalArgumentsNode* HParser::optional_arguments(){
  if(match_token_if(LNG::TokenName::t_lparenthesis)){
    list<ExprNode*> list;
    auto expr = expression();
    list.push_back(expr);
    while(match_token_if(LNG::TokenName::t_comma)){
      auto newExpr = expression();
      list.push_back(newExpr);
    }
    match_token(LNG::TN::t_rparenthesis);
    return new OptionalArgumentsNode(list);
  }
  return nullptr;
}

ProcedureCallStmtNode* HParser::procedure_call_statement(const string &identifier ) {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  string name = identifier;
  auto args = optional_arguments();
  return new ProcedureCallStmtNode(name, args->get_list());
}

WhileStmtNode* HParser::while_statement() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  match_token(LNG::TN::t_while);
  auto expr = expression();
  match_token(LNG::TN::t_do);
  auto state = statement();
  auto retVal = new WhileStmtNode(expr, state);
  return retVal;
}


VariableExprNode* HParser::variable_rvalue(SymbolTable::Entry& entry ) {
  /* TO DO: Implement ... */
  ExprNode *expr = nullptr;
  std::string identifier(token_.text);
  match_token(LNG::TN::t_identifier);
  if(entry.data_type.is_array()){
    match_token(LNG::TN::t_lbracket);
    expr = expression();
    match_token(LNG::TN::t_rbracket);
  }
  return new VariableExprNode(identifier, expr);
}


ExprNode* HParser::simple_expression() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  /* term <Add op> te rm */

  static map<LNG::TN, LNG::EO> add_op = {
      {LNG::TN::t_plus, LNG::EO::o_plus},
      {LNG::TN::t_minus, LNG::EO::o_minus},
      {LNG::TN::t_or, LNG::EO::o_or}};

  auto t = term();
  auto it = operator_in(add_op);
  while(it != add_op.end()){
    auto t_rhs = term();
    t =  new OpExprNode(it->second, t, t_rhs);
    it = operator_in(add_op);
  }
  return t;
}


ExprNode* HParser::term() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  static map<LNG::TN, LNG::EO> mult_op ={
      {LNG::TN::t_multiply, LNG::EO::o_multiply},
      {LNG::TN::t_divide, LNG::EO::o_divide},
      {LNG::TN::t_div, LNG::EO::o_div},
      {LNG::TN::t_and, LNG::EO::o_and}
  };

  ExprNode *expr = complemented_factor();
  auto it = operator_in(mult_op);
  while(it != mult_op.end()){
    auto t_rhs = complemented_factor();
    expr = new OpExprNode(it->second, expr, t_rhs);
    it = operator_in(mult_op);
  }
  return expr;
}


ExprNode* HParser::complemented_factor() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  ExprNode *expr = signed_factor();
  if(match_token_if(LNG::TN::t_not)){
    expr = new OpExprNode(Language::ExprOperator::o_not, nullptr, expr);
  }
  return expr;
}


ExprNode* HParser::signed_factor() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  ExprNode *expr = nullptr;
  if(match_token_if(LNG::TN::t_minus)){
    expr = factor();
    expr = new OpExprNode(Language::ExprOperator::o_minus, nullptr, expr);
  }
  else{
    expr = factor();
  }
  return expr;
}


BooleanExprNode* HParser::boolean_constant() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  if(match_token_if(LNG::TN::t_boolean)){
    bool n = bool(token_.name);
    auto node = new BooleanExprNode(n);
    return node;
  }
  return nullptr;
}


RealExprNode* HParser::real_constant() {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  if(match_token_if(LNG::TN::t_real)){
    float n = float(token_.name);
    auto node = new RealExprNode(n);
    return node;
  }
  return nullptr;
}


FunctionCallExprNode* HParser::function_call(const string &identifier ) {
  /* TO DO: Implement ... */
  /* Note that in all methods that you are to implement, you most likely have to change the return value. */
  auto args = optional_arguments();
  return new FunctionCallExprNode(identifier, args->get_list());
}
