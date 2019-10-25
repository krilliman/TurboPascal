#ifndef TURBOPASCAL_SA_VISITOR_H
#define TURBOPASCAL_SA_VISITOR_H

#include "ast.h"
#include <stack>
#include "symbol_table.h"
#include <string>
#include <error.h>
#include <vector>
using namespace AST;
using namespace std;
class SemanticAnalysisVisitor : public Visitor {
 public:
  explicit SemanticAnalysisVisitor(SymbolTable table) : table_(table){};
  virtual void visit( const IntegerExprNode* node )override {
    stringStack_.push("integer");
  }
  virtual void visit( const RealExprNode* node )override{

    stringStack_.push("real");
  }
  virtual void visit( const BooleanExprNode* node )override{
    stringStack_.push("boolean");
  }
  virtual void visit( const StringExprNode* node )override{
    stringStack_.push("string");
  }
  virtual void visit( const OpExprNode* node )override{
    auto rhs = node->get_rhs();
    auto lhs = node->get_lhs();
    string stackLHS, stackRHS = "";
    if(lhs != nullptr){
      accept(lhs);
      stackLHS = stringStack_.top(); stringStack_.pop();
    }
    if(rhs != nullptr) {
      accept(rhs);
      stackRHS = stringStack_.top();stringStack_.pop();
    }
    if(lhs == nullptr){
      stringStack_.push(stackRHS);
    }
    else{
      //o_eq, o_gt, o_gteq, o_neq, o_lt, o_lteq
      static map<LNG::ExprOperator, int> relational_op = {
          {LNG::ExprOperator::o_eq, 0},
          {LNG::ExprOperator::o_gt, 0},
          {LNG::ExprOperator::o_gteq, 0},
          {LNG::ExprOperator::o_neq, 0},
          {LNG::ExprOperator::o_lt, 0},
          {LNG::ExprOperator::o_lteq, 0}
      };
      auto it = relational_op.find(node->get_op());
      if(stackLHS == stackRHS){
        if(it == relational_op.end()){
          stringStack_.push(stackLHS);
        }
      }
      else{
        cout << "exiting in opExprNode" << endl;
        exit(0);
      }
    }
  }
  virtual void visit( const VariableExprNode* node ) override{
    auto n = table_.lookup("",node->get_name());

    if(n == nullptr){
      cout << "n is a nullptr" << endl;
    }
    stringStack_.push(n->data_type.str());

  }
  virtual void visit( const FunctionCallExprNode* node )override{
    string name = node->get_name();
    string signature = table_.lookup("",name)->signature;
    vector<string> tokens;
    string token;
    char delim = ',';
    stringstream stream(signature);
    while(getline(stream, token, delim)){
        tokens.push_back(token);
    }
    auto args = node->get_arguments();
    int argsSize = node->get_arguments().size();
    if(argsSize != tokens.size()){
      cout << "The argument list not of the same size" << endl;
      cout << "callSize: " << argsSize << " ,  actualSize: " << tokens.size() << endl;
      exit(0);
    }
    int counter = 0;
    for(auto i : args){
      accept(i);
      string topOfStack = stringStack_.top();stringStack_.pop();

      if(topOfStack != tokens[counter]){
        cout << "type miss match " << topOfStack << " != " << tokens[counter] << endl;
        exit(0);
      }
      counter ++;
    }
    stringStack_.push(table_.lookup("",name)->data_type.str());
  }

  virtual void visit( const AssignmentStmtNode* node )override{
    accept(node->get_var());
    string stackLHS = stringStack_.top();stringStack_.pop();
    accept(node->get_expr());
    string stackRHS = stringStack_.top();stringStack_.pop();
    if(stackLHS != stackRHS){
      cout << "exiting in assignmentNode" << endl;
      cout << stackLHS << " not equal to " << stackRHS << endl;
      exit(0);
    }
  }
  virtual void visit( const EmptyStmtNode* node )override{

  }
  virtual void visit( const CompoundStmtNode* node )override{
    auto list = node->get_stmts();
    for(auto i : list){
      accept(i);
    }
  }
  virtual void visit( const IfStmtNode* node ) override{
    accept(node->get_expr());
    accept(node->get_stmt_if());
    if(node->get_stmt_else() != nullptr){
      accept(node->get_stmt_else());
    }
  }
  virtual void visit( const ProcedureCallStmtNode* node ) override{
    string name = node->get_name();
    string signature = table_.lookup("",name)->signature;
    vector<string> tokens;
    string token;
    char delim = ',';
    stringstream stream(signature);
    while(getline(stream, token, delim)){
      tokens.push_back(token);
    }
    auto args = node->get_arguments();
    int argsSize = node->get_arguments().size();
    if(argsSize != tokens.size()){
      cout << "The argument list not of the same size" << endl;
      cout << "callSize: " << argsSize << " ,  actualSize: " << tokens.size() << endl;
      exit(0);
    }
    int counter = 0;
    for(auto i : args){
      accept(i);
      string topOfStack = stringStack_.top();stringStack_.pop();
      if(topOfStack != tokens[counter]){
        cout << "type miss match " << topOfStack << " != " << tokens[counter] << endl;
        exit(0);
      }
      counter ++;
    }
    stringStack_.push(table_.lookup("",name)->data_type.str());
  }
  virtual void visit( const WhileStmtNode* node ) override{
    accept(node->get_expr());
    accept(node->get_stmt());

  }
  virtual void visit( const ReadStmtNode* node ) override{
    accept(node->get_arg());

  }
  virtual void visit( const WriteStmtNode* node ) override{
    accept(node->get_expr());
    string topOfTheStack = stringStack_.top();stringStack_.pop();
    if(stringStack_.size() != 0){
      cout << "more than one argument was given" << endl;
      exit(0);
    }
  }

  virtual void visit( const VariableNode* node ) override{
    string name = node->get_name();
    string lookup = table_.lookup("", name)->data_type.str();
    stringStack_.push(lookup);
  }
  virtual void visit( const VariableDeclNode* node ) override{
  }
  virtual void visit( const ProcedureDeclNode* node )override{
    accept(node->get_block());
  }
  virtual void visit( const FunctionDeclNode* node )override{
    string name = node->get_name();
    auto it = table_.lookup("",name)->signature;
    accept(node->get_block());
  }
  virtual void visit( const VariableDeclarationsNode* node ) override{
    auto list = node->get_declarations();
    for(auto i : list){
      accept(i);
    }
  }
  virtual void visit( const CallableDeclarationsNode* node ) override{
    for(auto i : node->get_declarations()){
      accept(i);
    }
  }
  virtual void visit( const BlockNode* node ) override{
    if (node->get_var_decl() != nullptr)  // Could legitimately be a nullprt.
      accept(node->get_var_decl());
    accept(node->get_call_decl());
    accept(node->get_stmt());

  }
  virtual void visit( const ProgramNode* node ) override{
    accept(node->get_block());
    cout << "type checking successful" << endl;
  }
  virtual void visit( const OptionalArgumentsNode* node)override {
    for(auto i : node->get_list()){
      accept(i);
    }
  }

  void accept(const AST::Node *node) {
    if (node != nullptr) node->accept(*this);
  }

 private:
  std::stack<int> intStack_;
  std::stack<bool > boolStack_;
  std::stack<float > floatStack_;
  std::stack<std::string> stringStack_;
  SymbolTable table_;

};

#endif //TURBOPASCAL_SA_VISITOR_H
