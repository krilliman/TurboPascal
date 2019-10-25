#ifndef TURBOPASCAL_BPARSER_H
#define TURBOPASCAL_BPARSER_H
#include "parser.h"
#include "lexer.h"
#include "tpparser.h"

class BParser: public Parser {
 public:
  explicit BParser( std::istream &is, bool debug_lexer, bool debug_parser )
  : Parser( is, debug_lexer, debug_parser), lexer_(is) {
//      lexer_.get(token_);
  }

  int parse() override {
    yy::parser parser(*this);
    parser.set_debug_level( debug_parser_ );
    int res = parser.parse();
    return res;

  };

  virtual std::string get_name() const override { return "Bisonmade"; }
  SymbolTable* get_SymbolTable(){
    return &symbol_table_;
  }
  AST::Node* get_AST() {
    cout << "getting ast " << endl;
    return ast_;
  }

  Lexer lexer_;
  Lexer::Token token_;
  std::string scope_;
  SymbolTable symbol_table_;
  AST::Node* ast_;
};

#endif //TURBOPASCAL_BPARSER_H
