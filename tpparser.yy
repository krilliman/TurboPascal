%require "3.2"
%language "c++"

%code requires
{
#include <string>
#include "common.h"
#include "ast.h"
class BParser;
}

%parse-param { BParser& prs }
%lex-param { BParser& prs }
%locations
%define api.value.type variant
%define api.token.constructor
%define parse.assert
%define parse.trace
%define parse.error verbose

%code
{
  using namespace std;
  using namespace AST;
  #include "bparser.h"
  namespace yy
  {
    // Return the next token.
    auto yylex ( BParser& prs ) -> parser::symbol_type
    {
        prs.lexer_.get( prs.token_ );
        yy::position pos( nullptr, prs.token_.loc.line, prs.token_.loc.col );
        parser::location_type loc( pos, pos );

        switch ( prs.token_.name ) {
        case LNG::TN::t_assign:     return parser::make_t_assign(loc);
        case LNG::TN::t_divide:     return parser::make_t_divide(loc);
        case LNG::TN::t_eq:         return parser::make_t_eq(loc);
        case LNG::TN::t_gt:         return parser::make_t_gt(loc);
        case LNG::TN::t_gteq:       return parser::make_t_gteq(loc);
        case LNG::TN::t_lt:         return parser::make_t_lt(loc);
        case LNG::TN::t_lteq:       return parser::make_t_lteq(loc);
        case LNG::TN::t_minus:      return parser::make_t_minus(loc);
        case LNG::TN::t_multiply:   return parser::make_t_multiply(loc);
        case LNG::TN::t_neq:        return parser::make_t_neq(loc);
        case LNG::TN::t_plus:       return parser::make_t_plus(loc);

        case LNG::TN::t_colon:          return parser::make_t_colon(loc);
        case LNG::TN::t_comma:          return parser::make_t_comma(loc);
        case LNG::TN::t_dot:            return parser::make_t_dot(loc);
        case LNG::TN::t_lbracket:       return parser::make_t_lbracket(loc);
        case LNG::TN::t_lparenthesis:   return parser::make_t_lparenthesis(loc);
        case LNG::TN::t_rbracket:       return parser::make_t_rbracket(loc);
        case LNG::TN::t_rparenthesis:   return parser::make_t_rparenthesis(loc);
        case LNG::TN::t_subrange:       return parser::make_t_subrange(loc);
        case LNG::TN::t_semicolon:      return parser::make_t_semicolon(loc);

        case LNG::TN::t_and:        return parser::make_t_and(loc);
        case LNG::TN::t_array:      return parser::make_t_array(loc);
        case LNG::TN::t_begin:      return parser::make_t_begin(loc);
        case LNG::TN::t_boolean:    return parser::make_t_boolean(loc);
        case LNG::TN::t_div:        return parser::make_t_div(loc);
        case LNG::TN::t_do:         return parser::make_t_do(loc);
        case LNG::TN::t_else:       return parser::make_t_else(loc);
        case LNG::TN::t_end:        return parser::make_t_end(loc);
        case LNG::TN::t_false:      return parser::make_t_false(loc);
        case LNG::TN::t_function:   return parser::make_t_function(loc);
        case LNG::TN::t_if:         return parser::make_t_if(loc);
        case LNG::TN::t_integer:    return parser::make_t_integer(loc);
        case LNG::TN::t_not:        return parser::make_t_not(loc);
        case LNG::TN::t_of:         return parser::make_t_of(loc);
        case LNG::TN::t_or:         return parser::make_t_or(loc);
        case LNG::TN::t_procedure:  return parser::make_t_procedure(loc);
        case LNG::TN::t_program:    return parser::make_t_program(loc);
        case LNG::TN::t_read:       return parser::make_t_read(loc);
        case LNG::TN::t_readln:     return parser::make_t_readln(loc);
        case LNG::TN::t_real:       return parser::make_t_real(loc);
        case LNG::TN::t_then:       return parser::make_t_then(loc);
        case LNG::TN::t_true:       return parser::make_t_true(loc);
        case LNG::TN::t_var:        return parser::make_t_var(loc);
        case LNG::TN::t_while:      return parser::make_t_while(loc);
        case LNG::TN::t_write:      return parser::make_t_write(loc);
        case LNG::TN::t_writeln:    return parser::make_t_writeln(loc);

        case LNG::TN::t_identifier: return parser::make_t_identifier(prs.token_.text, loc);

        case LNG::TN::t_integer_l:  return parser::make_t_integer_l(prs.token_.text, loc);
        case LNG::TN::t_real_l:     return parser::make_t_real_l(prs.token_.text, loc);
        case LNG::TN::t_string_l:   return parser::make_t_string_l(prs.token_.text, loc);

        case LNG::TN::t_eoi:        return parser::make_t_eoi(loc);
        default:                    return parser::make_t_unknown(loc);
        }
    }
  }
}

%nonassoc   t_assign;
%left       t_divide;
%nonassoc   t_eq;
%nonassoc   t_gt;
%nonassoc   t_gteq;
%nonassoc   t_lt;
%nonassoc   t_lteq;
%left       t_minus;
%left       t_multiply;
%nonassoc   t_neq;
%left       t_plus;

%token  t_colon;
%token  t_comma;
%token  t_dot;
%token  t_lbracket;
%token  t_lparenthesis;
%token  t_rbracket;
%token  t_rparenthesis;
%token  t_subrange;
%token  t_semicolon;

%left   t_and;
%token  t_array;
%token  t_begin;
%token  t_boolean;
%token  t_div;
%token  t_do;
%token  t_else;
%token  t_end;
%token  t_false;
%token  t_function;
%token  t_if;
%token  t_integer;
%right  t_not;
%token  t_of;
%left   t_or;
%token  t_procedure;
%token  t_program;
%token  t_read;
%token  t_readln;
%token  t_real;
%token  t_then;
%token  t_true;
%token  t_var;
%token  t_while;
%token  t_write;
%token  t_writeln;

%token  t_identifier;
%token  t_integer_l;
%token  t_real_l;
%token  t_string_l;

%token  t_eoi 0;
%token  t_unknown

%type <std::string> t_identifier
%type <std::string> t_integer_l
%type <std::string> t_real_l
%type <std::string> t_string_l


%type <AST::BlockNode*> main_block

%type <AST::VariableDeclarationsNode*> variable_declarations
%type <std::list<AST::VariableDeclNode*>> list_variable_declaration
%type <AST::VariableDeclNode*> variable_declaration
%type <std::list<std::string>> list_identifier

%type <LNG::DataType> type
%type <LNG::DataType> array_type
%type <LNG::TN::t_subrange> sub_range
%type <LNG::SimpleDataType> simple_type



%type <AST::VariableNode*> variable_lvalue
%type <AST::VariableNode*> variable_rvalue




%type <AST::CallableDeclarationsNode*> callable_declarations
%type <std::list<AST::CallableDeclNode*>> callable_declarations_list
%type <AST::ProcedureDeclNode*> procedure_declarations
%type <AST::FunctionDeclNode*> function_declaration
%type <AST::VariableDeclarationsNode*> opt_params
%type <AST::VariableDeclNode*> parameter_list
%type <std::list<std::string>> parameters
%type <std::list<AST::VariableDeclNode*>> list_parameterList_declaration
%type <AST::BlockNode*> block

%type <AST::CompoundStmtNode*> statements
%type <std::list<AST::StmtNode*>> list_statement
%type <AST::CompoundStmtNode*> compound_statement
%type <AST::StmtNode*> statement
%type <AST::StmtNode*> simple_statement
%type <AST::EmptyStmtNode*> empty_statement
%type <AST::AssignmentStmtNode*> assignment_statement
%type <AST::ProcedureCallStmtNode*> procedure_statement
%type <AST::ReadStmtNode*> read_statement
%type <AST::VariableNode*> input_variable
%type <AST::WriteStmtNode*> write_statement
%type <AST::ExprNode*> output_value
%type <AST::StmtNode*> structured_statement
%type <AST::IfStmtNode*> if_statement
%type <AST::WhileStmtNode*> while_statement


%type <AST::ExprNode*> expression
%type <AST::ExprNode*> simple_expression
%type <AST::ExprNode*> simple_expressions
%type <AST::ExprNode*> term
%type <AST::ExprNode*> terms
%type <AST::ExprNode*> complemented_factor
%type <AST::ExprNode*> complemented_factors
%type <AST::ExprNode*> signed_factor
%type <AST::ExprNode*> factor


%type <AST::FunctionCallExprNode*> function_call
%type <AST::OptionalArgumentsNode*> optional_arguments
%type <std::list<AST::ExprNode*>> arguments_list
%type <AST::ExprNode*> argument



%type <Language::ExprOperator> rel_op
%type <Language::ExprOperator> add_op
%type <Language::ExprOperator> mult_op
%type <Language::ExprOperator> sign



%type <AST::VariableExprNode*> variable
%type <AST::VariableExprNode*> indexed_variable
%type <std::string> array_variable
%type <std::string> variable_identifier
%type <std::string> entire_variable
%type <std::string> procedure_identifier
%type <std::string> function_identifier
%type <std::string> identifier


%type <AST::ExprNode*> constant
%type <AST::IntegerExprNode*> integer_constant
%type <AST::RealExprNode*>   real_constant
%type <AST::BooleanExprNode*>   boolean_constant
%type <AST::StringExprNode*>   string_constant





%%
program:
    t_program identifier t_semicolon
    main_block
    t_dot
    {
    prs.ast_ = new AST::ProgramNode( $2, $4 );
    prs.set_AST( new AST::ProgramNode( $2, $4 ) );
    }
;

main_block:
    variable_declarations
    callable_declarations
    compound_statement
    { $$ = new AST::BlockNode( $1, $2, $3 ); }   // NOTE
;

variable_declarations:
    t_var list_variable_declaration
    { $$ = new AST::VariableDeclarationsNode( $2 ); }
    |
    empty_statement
    { $$ = nullptr; }
;

list_variable_declaration:
    list_variable_declaration variable_declaration t_semicolon
    { $1.push_back( $2 ); $$ = $1; }
    |
    variable_declaration t_semicolon
    { std::list<AST::VariableDeclNode*> lst; lst.push_back( $1 ); $$ = lst; }
;

variable_declaration:
    list_identifier t_colon type
    {
    LNG::DataType newType = LNG::DataType($3);
    for(auto i : $1){
        prs.symbol_table_.add_var(prs.scope_, i, newType);
    }
    $$ = new AST::VariableDeclNode( $1, $3 );
    }
;

list_identifier:
    list_identifier t_comma identifier
    {
    $1.push_back( $3 ); $$ = $1;
    }
    |
    identifier
    { std::list<std::string> lst; lst.push_back( $1 ); $$ = lst; }
;

type:
    simple_type     { $$ = LNG::DataType($1); }
    |
    array_type      { $$ = $1; }
;

simple_type:
    t_integer       { $$ = LNG::SimpleDataType::tInteger; }
    |
    t_boolean       { $$ = LNG::SimpleDataType::tBoolean; }
    |
    t_real          { $$ = LNG::SimpleDataType::tReal; }
;

array_type:
    t_array
    t_lbracket
    t_integer_l
    t_subrange
    t_integer_l
    t_rbracket
    t_of
    simple_type
    { $$ = $$ = LNG::DataType( $8, std::stoi($3), std::stoi($5) ); }
;

statements:
    compound_statement
    {$$ = $1;}
;

compound_statement:
    t_begin
    list_statement
    t_end
    { $$ = new AST::CompoundStmtNode($2); };
;

list_statement:
    list_statement t_semicolon statement
    { $1.push_back( $3 ); $$ = $1; }
    |
    statement
    { std::list<AST::StmtNode*> lst; lst.push_back( $1 ); $$ = lst; }
;

////////////////////////////////////////////////////////////////////////////////////////
//
// Your implementation. Note that the existing entires below are only placeholders,
// which you need to replace with proper code.
//
////////////////////////////////////////////////////////////////////////////////////////



procedure_declarations:
    t_procedure
    procedure_identifier
    opt_params
    t_semicolon
    block
    t_semicolon
    {
    prs.scope_ = $2;
    AST::ProcedureDeclNode* node = new AST::ProcedureDeclNode( $2, $3, $5);
    std::string signature = "";
    if($3 != nullptr){
        for(auto i : $3->get_declarations()){
            int count = 0;
            for(auto j : i->get_identifiers()){
                count++;
            }
            for(int k = 0; k < count; k++){
                signature += i->get_data_type().str() +  ",";
            }
        }
        signature = signature.substr(0, signature.length()-1);
    }
    prs.symbol_table_.add_procedure($2, signature);
    prs.scope_ = "";
    $$ = node;
    }
;

function_declaration:
    t_function
    function_identifier
    opt_params
    t_colon
    simple_type
    t_semicolon
    block
    t_semicolon
    {
    prs.scope_ = $2;
    LNG::DataType newType = LNG::DataType($5);
    AST::FunctionDeclNode* node = new AST::FunctionDeclNode( $2, $3, $7, newType);
    std::string signature = "";
    if($3 != nullptr){
        for(auto i : $3->get_declarations()){
            int count = 0;
            for(auto j : i->get_identifiers()){
                count++;
            }
            for(int k = 0; k < count; k++){
                signature += i->get_data_type().str() +  ",";
            }
        }
        signature = signature.substr(0, signature.length()-1);
    }
    prs.symbol_table_.add_function($2, signature, newType);
    prs.scope_ = "";
    $$ = node;
    }
;

opt_params:
    t_lparenthesis list_parameterList_declaration t_rparenthesis
    {$$ = new AST::VariableDeclarationsNode($2);}
    |
    {$$ = nullptr;}
;

parameter_list:
    parameters t_colon simple_type
    {
    LNG::DataType newType = LNG::DataType($3);
    $$ = new AST::VariableDeclNode($1, newType);
    }
;

parameters:
    parameters t_comma identifier
    {$1.push_back($3); $$ = $1;}
    |
    identifier
    {std::list<std::string> lst; lst.push_back($1); $$ = lst;}
;



list_parameterList_declaration:
    list_parameterList_declaration  t_semicolon parameter_list
    {$1.push_back($3); $$ = $1;}
    |
    empty_statement
    {
    std::list<AST::VariableDeclNode*> lst;
    $$ = lst;
    }
    |
    parameter_list
    {std::list<AST::VariableDeclNode*> lst; lst.push_back($1); $$ = lst;}

;

callable_declarations:
    callable_declarations_list {$$ = new CallableDeclarationsNode($1);}
;

callable_declarations_list:
    callable_declarations_list procedure_declarations   { $1.push_back($2); $$ = $1; }
    |
    callable_declarations_list function_declaration   { $1.push_back($2); $$ = $1; }
    |
    {std::list<AST::CallableDeclNode*> lst; $$ = lst;}
;


input_variable:
    variable_lvalue         { $$ = $1; }
;

read_statement:
    t_read
    input_variable
    { $$ = new AST::ReadStmtNode( $2 ); }
    |
    t_readln
    input_variable
    { $$ = new AST::ReadStmtNode( $2, true); }
;

write_statement:
    t_write
    t_lparenthesis
    output_value
    t_rparenthesis
    {$$ = new AST::WriteStmtNode( $3 );}
    |
    t_writeln
    t_lparenthesis
    output_value
    t_rparenthesis
    { $$ = new AST::WriteStmtNode( $3, true); }
;

procedure_statement:
    procedure_identifier optional_arguments
    { $$ = new AST::ProcedureCallStmtNode( $1, $2->get_list() ); }
;

optional_arguments:
    empty_statement
    {
    std::list<AST::ExprNode*> lst;
    $$ = new AST::OptionalArgumentsNode(lst);
    }
    |
    t_lparenthesis arguments_list t_rparenthesis
    { $$ = new AST::OptionalArgumentsNode($2); }
;

sub_range:
    t_integer
    t_subrange
    t_integer
    {$$ = LNG::TN::t_subrange;}
;

arguments_list:
    arguments_list t_comma argument
    {$1.push_back($3); $$ = $1;}
    |
    expression
    {std::list<AST::ExprNode*> lst; lst.push_back($1); $$ = lst;}
;

simple_statement:
    assignment_statement    { $$ = $1; }
    |
    empty_statement         { $$ = $1; }
    |
    procedure_statement     { $$ = $1; }
    |
    read_statement          { $$ = $1; }
    |
    write_statement         { $$ = $1; }
;

if_statement:
    t_if expression t_then statement 
    { $$ = new AST::IfStmtNode($2, $4); }
    |
    t_if expression t_then statement t_else statement
    { $$ = new AST::IfStmtNode($2, $4, $6); }
;

while_statement:
    t_while expression t_do statement
    { $$ = new AST::WhileStmtNode($2, $4); }
;

structured_statement:
    compound_statement      { $$ = $1; }
    |
    if_statement            { $$ = $1; }
    |
    while_statement         { $$ = $1; }
;

statement:
    simple_statement        { $$ = $1; }
    |
    structured_statement    { $$ = $1; }
;

empty_statement:
    { $$ = new AST::EmptyStmtNode(); }
;

assignment_statement:
    variable_lvalue
    t_assign
    expression
    { $$ = new AST::AssignmentStmtNode( $1, $3); }
    |
    function_identifier
    t_assign
    expression
    {
    AST::VariableNode* node = new AST::VariableNode($1);
    $$ = new AST::AssignmentStmtNode(node, $3);
    }
;


variable_lvalue:
    variable
    {
    $$ = new VariableNode($1->get_name(), $1->get_expr());
    }
;

expression:
    simple_expressions
    { $$ = $1; }
;

simple_expressions:
    simple_expression rel_op simple_expression simple_expressions
    {
    ExprNode* expr = new AST::OpExprNode($2, $1, $3);
    $$ = expr;
    }
    |
    simple_expression rel_op simple_expression
    {
    ExprNode* expr =  new AST::OpExprNode($2, $1, $3);
    $$ = expr;
    }
    |
    simple_expression
    {$$ = $1;}

;

simple_expression:
   terms
   {$$ = $1;}
;
terms:
    term add_op terms
    {$$ = new AST::OpExprNode($2,$1,$3);}
    |
    term
    {$$ = $1;}

;
term:
    complemented_factors
    {$$ = $1;}
;

complemented_factors:
    complemented_factor mult_op complemented_factors
    {$$ = new AST::OpExprNode($2,$1,$3);}
    |
    complemented_factor
    {$$ = $1;}

;

complemented_factor:
    signed_factor
    {$$ = $1;}
    |
    t_not
    signed_factor
    {
        AST::ExprNode *expr = new AST::OpExprNode(Language::ExprOperator::o_not, nullptr, $2);
        $$ = expr;
    }
;
signed_factor:
    factor
    {$$ = $1;}
    |
    sign
    factor
    {
        if($1 == Language::ExprOperator::o_minus){
            AST::ExprNode *expr = new AST::OpExprNode(Language::ExprOperator::o_minus, nullptr, $2);
            $$ = expr;
        }
        else{
            $$ = $2;
        }
    }
;
factor:
    variable_rvalue
    {
    $$ = $1->get_expr();
    }
    |
    constant
    {$$ = $1;}
    |
    t_lparenthesis
    expression
    t_rparenthesis
    {$$ = $2;}
    |
    function_call
    {$$ = $1;}

;

block:
    variable_declarations
    statements
    {$$ = new AST::BlockNode($1, $2);}
;
output_value:
    string_constant
    {$$ = $1;}
    |
    expression
    {$$ = $1;}

;

function_call:
    function_identifier
    optional_arguments
    {
        $$ = new AST::FunctionCallExprNode($1, $2->get_list());
    }
;
identifier:
    t_identifier
    {std::string retval(prs.token_.text); $$ = retval;}
;

argument:
    expression
    {$$ = $1;}
;

function_identifier:
    identifier
    {$$ = $1;}
;

procedure_identifier:
    identifier
    {$$ = $1;}
;

variable_identifier:
    identifier
    {$$ = $1;}
;

entire_variable:
    variable_identifier
    {$$ = $1;}
;
array_variable:
    entire_variable
    {$$ = $1;}
;

variable_rvalue:
    variable
    {
    AST::VariableNode* node = new AST::VariableNode($1->get_name(), $1);
    $$ =  node;
    }
;

variable:
    identifier
    {$$ = new AST::VariableExprNode($1);}
    |
    indexed_variable
    {
    $$ = $1;
    }
;

indexed_variable:
    array_variable
    t_lbracket
    expression
    t_rbracket
    {$$ = new AST::VariableExprNode($1, $3);}
;


constant:
    integer_constant
    {$$ = $1;}
    |
    real_constant
    {$$ = $1;}
    |
    boolean_constant
    {$$ = $1;}
;

integer_constant:
    t_integer_l
    {
    int tmp = std::stoi(prs.token_.text);
    $$ = new IntegerExprNode(tmp);
    }
;

real_constant:
    t_real_l
    {
    float tmp = std::stof(prs.token_.text);
    $$ = new RealExprNode(tmp);
    }
;

boolean_constant:
    t_boolean
    {
    bool tmp = bool(prs.token_.name);
    $$ = new BooleanExprNode(tmp);
    }
;
string_constant:
    t_string_l
    {
    std::string s(prs.token_.text);
    $$ = new StringExprNode(s);
    }
;

mult_op:
    t_multiply
    {$$ = Language::ExprOperator::o_multiply;}
    |
    t_divide
    {$$ = Language::ExprOperator::o_divide;}
    |
    t_div
    {$$ = Language::ExprOperator::o_div;}
    |
    t_and
    {$$ = Language::ExprOperator::o_and;}
;

add_op:
    t_plus
    {$$ = Language::ExprOperator::o_plus;}
    |
    t_minus
    {$$ = Language::ExprOperator::o_minus;}
    |
    t_or
    {$$ = Language::ExprOperator::o_or;}
;

rel_op:
    t_eq
    {$$ = Language::ExprOperator::o_eq;}
    |
    t_gt
    {$$ = Language::ExprOperator::o_gt;}
    |
    t_gteq
    {$$ = Language::ExprOperator::o_gteq;}
    |
    t_lt
    {$$ = Language::ExprOperator::o_lt;}
    |
    t_lteq
    {$$ = Language::ExprOperator::o_lteq;}
;
sign:
    t_minus
    {$$ = Language::ExprOperator::o_minus;}
    |
    t_plus
    {$$ = Language::ExprOperator::o_plus;}
;
%%

  namespace yy
  {
    // Report an error to the user.
    auto parser::error(const location_type& l, const std::string &msg) -> void {
        std::cerr << msg << " at (" << l.begin.line << ',' << l.begin.column << ")\n";
    }
  }
