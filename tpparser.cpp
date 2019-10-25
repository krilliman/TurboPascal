// A Bison parser, made by GNU Bison 3.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "tpparser.h"


// Unqualified %code blocks.
#line 22 "tpparser.yy"

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

#line 121 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 215 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (BParser& prs_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      prs (prs_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 87: // assignment_statement
        value.YY_MOVE_OR_COPY< AST::AssignmentStmtNode* > (YY_MOVE (that.value));
        break;

      case 56: // main_block
      case 98: // block
        value.YY_MOVE_OR_COPY< AST::BlockNode* > (YY_MOVE (that.value));
        break;

      case 114: // boolean_constant
        value.YY_MOVE_OR_COPY< AST::BooleanExprNode* > (YY_MOVE (that.value));
        break;

      case 73: // callable_declarations
        value.YY_MOVE_OR_COPY< AST::CallableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 64: // statements
      case 65: // compound_statement
        value.YY_MOVE_OR_COPY< AST::CompoundStmtNode* > (YY_MOVE (that.value));
        break;

      case 86: // empty_statement
        value.YY_MOVE_OR_COPY< AST::EmptyStmtNode* > (YY_MOVE (that.value));
        break;

      case 89: // expression
      case 90: // simple_expressions
      case 91: // simple_expression
      case 92: // terms
      case 93: // term
      case 94: // complemented_factors
      case 95: // complemented_factor
      case 96: // signed_factor
      case 97: // factor
      case 99: // output_value
      case 102: // argument
      case 111: // constant
        value.YY_MOVE_OR_COPY< AST::ExprNode* > (YY_MOVE (that.value));
        break;

      case 100: // function_call
        value.YY_MOVE_OR_COPY< AST::FunctionCallExprNode* > (YY_MOVE (that.value));
        break;

      case 68: // function_declaration
        value.YY_MOVE_OR_COPY< AST::FunctionDeclNode* > (YY_MOVE (that.value));
        break;

      case 82: // if_statement
        value.YY_MOVE_OR_COPY< AST::IfStmtNode* > (YY_MOVE (that.value));
        break;

      case 112: // integer_constant
        value.YY_MOVE_OR_COPY< AST::IntegerExprNode* > (YY_MOVE (that.value));
        break;

      case 79: // optional_arguments
        value.YY_MOVE_OR_COPY< AST::OptionalArgumentsNode* > (YY_MOVE (that.value));
        break;

      case 78: // procedure_statement
        value.YY_MOVE_OR_COPY< AST::ProcedureCallStmtNode* > (YY_MOVE (that.value));
        break;

      case 67: // procedure_declarations
        value.YY_MOVE_OR_COPY< AST::ProcedureDeclNode* > (YY_MOVE (that.value));
        break;

      case 76: // read_statement
        value.YY_MOVE_OR_COPY< AST::ReadStmtNode* > (YY_MOVE (that.value));
        break;

      case 113: // real_constant
        value.YY_MOVE_OR_COPY< AST::RealExprNode* > (YY_MOVE (that.value));
        break;

      case 81: // simple_statement
      case 84: // structured_statement
      case 85: // statement
        value.YY_MOVE_OR_COPY< AST::StmtNode* > (YY_MOVE (that.value));
        break;

      case 115: // string_constant
        value.YY_MOVE_OR_COPY< AST::StringExprNode* > (YY_MOVE (that.value));
        break;

      case 59: // variable_declaration
      case 70: // parameter_list
        value.YY_MOVE_OR_COPY< AST::VariableDeclNode* > (YY_MOVE (that.value));
        break;

      case 57: // variable_declarations
      case 69: // opt_params
        value.YY_MOVE_OR_COPY< AST::VariableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 109: // variable
      case 110: // indexed_variable
        value.YY_MOVE_OR_COPY< AST::VariableExprNode* > (YY_MOVE (that.value));
        break;

      case 75: // input_variable
      case 88: // variable_lvalue
      case 108: // variable_rvalue
        value.YY_MOVE_OR_COPY< AST::VariableNode* > (YY_MOVE (that.value));
        break;

      case 83: // while_statement
        value.YY_MOVE_OR_COPY< AST::WhileStmtNode* > (YY_MOVE (that.value));
        break;

      case 77: // write_statement
        value.YY_MOVE_OR_COPY< AST::WriteStmtNode* > (YY_MOVE (that.value));
        break;

      case 61: // type
      case 63: // array_type
        value.YY_MOVE_OR_COPY< LNG::DataType > (YY_MOVE (that.value));
        break;

      case 62: // simple_type
        value.YY_MOVE_OR_COPY< LNG::SimpleDataType > (YY_MOVE (that.value));
        break;

      case 116: // mult_op
      case 117: // add_op
      case 118: // rel_op
      case 119: // sign
        value.YY_MOVE_OR_COPY< Language::ExprOperator > (YY_MOVE (that.value));
        break;

      case 74: // callable_declarations_list
        value.YY_MOVE_OR_COPY< std::list<AST::CallableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 80: // arguments_list
        value.YY_MOVE_OR_COPY< std::list<AST::ExprNode*> > (YY_MOVE (that.value));
        break;

      case 66: // list_statement
        value.YY_MOVE_OR_COPY< std::list<AST::StmtNode*> > (YY_MOVE (that.value));
        break;

      case 58: // list_variable_declaration
      case 72: // list_parameterList_declaration
        value.YY_MOVE_OR_COPY< std::list<AST::VariableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 60: // list_identifier
      case 71: // parameters
        value.YY_MOVE_OR_COPY< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
      case 101: // identifier
      case 103: // function_identifier
      case 104: // procedure_identifier
      case 105: // variable_identifier
      case 106: // entire_variable
      case 107: // array_variable
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 87: // assignment_statement
        value.move< AST::AssignmentStmtNode* > (YY_MOVE (that.value));
        break;

      case 56: // main_block
      case 98: // block
        value.move< AST::BlockNode* > (YY_MOVE (that.value));
        break;

      case 114: // boolean_constant
        value.move< AST::BooleanExprNode* > (YY_MOVE (that.value));
        break;

      case 73: // callable_declarations
        value.move< AST::CallableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 64: // statements
      case 65: // compound_statement
        value.move< AST::CompoundStmtNode* > (YY_MOVE (that.value));
        break;

      case 86: // empty_statement
        value.move< AST::EmptyStmtNode* > (YY_MOVE (that.value));
        break;

      case 89: // expression
      case 90: // simple_expressions
      case 91: // simple_expression
      case 92: // terms
      case 93: // term
      case 94: // complemented_factors
      case 95: // complemented_factor
      case 96: // signed_factor
      case 97: // factor
      case 99: // output_value
      case 102: // argument
      case 111: // constant
        value.move< AST::ExprNode* > (YY_MOVE (that.value));
        break;

      case 100: // function_call
        value.move< AST::FunctionCallExprNode* > (YY_MOVE (that.value));
        break;

      case 68: // function_declaration
        value.move< AST::FunctionDeclNode* > (YY_MOVE (that.value));
        break;

      case 82: // if_statement
        value.move< AST::IfStmtNode* > (YY_MOVE (that.value));
        break;

      case 112: // integer_constant
        value.move< AST::IntegerExprNode* > (YY_MOVE (that.value));
        break;

      case 79: // optional_arguments
        value.move< AST::OptionalArgumentsNode* > (YY_MOVE (that.value));
        break;

      case 78: // procedure_statement
        value.move< AST::ProcedureCallStmtNode* > (YY_MOVE (that.value));
        break;

      case 67: // procedure_declarations
        value.move< AST::ProcedureDeclNode* > (YY_MOVE (that.value));
        break;

      case 76: // read_statement
        value.move< AST::ReadStmtNode* > (YY_MOVE (that.value));
        break;

      case 113: // real_constant
        value.move< AST::RealExprNode* > (YY_MOVE (that.value));
        break;

      case 81: // simple_statement
      case 84: // structured_statement
      case 85: // statement
        value.move< AST::StmtNode* > (YY_MOVE (that.value));
        break;

      case 115: // string_constant
        value.move< AST::StringExprNode* > (YY_MOVE (that.value));
        break;

      case 59: // variable_declaration
      case 70: // parameter_list
        value.move< AST::VariableDeclNode* > (YY_MOVE (that.value));
        break;

      case 57: // variable_declarations
      case 69: // opt_params
        value.move< AST::VariableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 109: // variable
      case 110: // indexed_variable
        value.move< AST::VariableExprNode* > (YY_MOVE (that.value));
        break;

      case 75: // input_variable
      case 88: // variable_lvalue
      case 108: // variable_rvalue
        value.move< AST::VariableNode* > (YY_MOVE (that.value));
        break;

      case 83: // while_statement
        value.move< AST::WhileStmtNode* > (YY_MOVE (that.value));
        break;

      case 77: // write_statement
        value.move< AST::WriteStmtNode* > (YY_MOVE (that.value));
        break;

      case 61: // type
      case 63: // array_type
        value.move< LNG::DataType > (YY_MOVE (that.value));
        break;

      case 62: // simple_type
        value.move< LNG::SimpleDataType > (YY_MOVE (that.value));
        break;

      case 116: // mult_op
      case 117: // add_op
      case 118: // rel_op
      case 119: // sign
        value.move< Language::ExprOperator > (YY_MOVE (that.value));
        break;

      case 74: // callable_declarations_list
        value.move< std::list<AST::CallableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 80: // arguments_list
        value.move< std::list<AST::ExprNode*> > (YY_MOVE (that.value));
        break;

      case 66: // list_statement
        value.move< std::list<AST::StmtNode*> > (YY_MOVE (that.value));
        break;

      case 58: // list_variable_declaration
      case 72: // list_parameterList_declaration
        value.move< std::list<AST::VariableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 60: // list_identifier
      case 71: // parameters
        value.move< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
      case 101: // identifier
      case 103: // function_identifier
      case 104: // procedure_identifier
      case 105: // variable_identifier
      case 106: // entire_variable
      case 107: // array_variable
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 87: // assignment_statement
        value.move< AST::AssignmentStmtNode* > (that.value);
        break;

      case 56: // main_block
      case 98: // block
        value.move< AST::BlockNode* > (that.value);
        break;

      case 114: // boolean_constant
        value.move< AST::BooleanExprNode* > (that.value);
        break;

      case 73: // callable_declarations
        value.move< AST::CallableDeclarationsNode* > (that.value);
        break;

      case 64: // statements
      case 65: // compound_statement
        value.move< AST::CompoundStmtNode* > (that.value);
        break;

      case 86: // empty_statement
        value.move< AST::EmptyStmtNode* > (that.value);
        break;

      case 89: // expression
      case 90: // simple_expressions
      case 91: // simple_expression
      case 92: // terms
      case 93: // term
      case 94: // complemented_factors
      case 95: // complemented_factor
      case 96: // signed_factor
      case 97: // factor
      case 99: // output_value
      case 102: // argument
      case 111: // constant
        value.move< AST::ExprNode* > (that.value);
        break;

      case 100: // function_call
        value.move< AST::FunctionCallExprNode* > (that.value);
        break;

      case 68: // function_declaration
        value.move< AST::FunctionDeclNode* > (that.value);
        break;

      case 82: // if_statement
        value.move< AST::IfStmtNode* > (that.value);
        break;

      case 112: // integer_constant
        value.move< AST::IntegerExprNode* > (that.value);
        break;

      case 79: // optional_arguments
        value.move< AST::OptionalArgumentsNode* > (that.value);
        break;

      case 78: // procedure_statement
        value.move< AST::ProcedureCallStmtNode* > (that.value);
        break;

      case 67: // procedure_declarations
        value.move< AST::ProcedureDeclNode* > (that.value);
        break;

      case 76: // read_statement
        value.move< AST::ReadStmtNode* > (that.value);
        break;

      case 113: // real_constant
        value.move< AST::RealExprNode* > (that.value);
        break;

      case 81: // simple_statement
      case 84: // structured_statement
      case 85: // statement
        value.move< AST::StmtNode* > (that.value);
        break;

      case 115: // string_constant
        value.move< AST::StringExprNode* > (that.value);
        break;

      case 59: // variable_declaration
      case 70: // parameter_list
        value.move< AST::VariableDeclNode* > (that.value);
        break;

      case 57: // variable_declarations
      case 69: // opt_params
        value.move< AST::VariableDeclarationsNode* > (that.value);
        break;

      case 109: // variable
      case 110: // indexed_variable
        value.move< AST::VariableExprNode* > (that.value);
        break;

      case 75: // input_variable
      case 88: // variable_lvalue
      case 108: // variable_rvalue
        value.move< AST::VariableNode* > (that.value);
        break;

      case 83: // while_statement
        value.move< AST::WhileStmtNode* > (that.value);
        break;

      case 77: // write_statement
        value.move< AST::WriteStmtNode* > (that.value);
        break;

      case 61: // type
      case 63: // array_type
        value.move< LNG::DataType > (that.value);
        break;

      case 62: // simple_type
        value.move< LNG::SimpleDataType > (that.value);
        break;

      case 116: // mult_op
      case 117: // add_op
      case 118: // rel_op
      case 119: // sign
        value.move< Language::ExprOperator > (that.value);
        break;

      case 74: // callable_declarations_list
        value.move< std::list<AST::CallableDeclNode*> > (that.value);
        break;

      case 80: // arguments_list
        value.move< std::list<AST::ExprNode*> > (that.value);
        break;

      case 66: // list_statement
        value.move< std::list<AST::StmtNode*> > (that.value);
        break;

      case 58: // list_variable_declaration
      case 72: // list_parameterList_declaration
        value.move< std::list<AST::VariableDeclNode*> > (that.value);
        break;

      case 60: // list_identifier
      case 71: // parameters
        value.move< std::list<std::string> > (that.value);
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
      case 101: // identifier
      case 103: // function_identifier
      case 104: // procedure_identifier
      case 105: // variable_identifier
      case 106: // entire_variable
      case 107: // array_variable
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (prs));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 87: // assignment_statement
        yylhs.value.emplace< AST::AssignmentStmtNode* > ();
        break;

      case 56: // main_block
      case 98: // block
        yylhs.value.emplace< AST::BlockNode* > ();
        break;

      case 114: // boolean_constant
        yylhs.value.emplace< AST::BooleanExprNode* > ();
        break;

      case 73: // callable_declarations
        yylhs.value.emplace< AST::CallableDeclarationsNode* > ();
        break;

      case 64: // statements
      case 65: // compound_statement
        yylhs.value.emplace< AST::CompoundStmtNode* > ();
        break;

      case 86: // empty_statement
        yylhs.value.emplace< AST::EmptyStmtNode* > ();
        break;

      case 89: // expression
      case 90: // simple_expressions
      case 91: // simple_expression
      case 92: // terms
      case 93: // term
      case 94: // complemented_factors
      case 95: // complemented_factor
      case 96: // signed_factor
      case 97: // factor
      case 99: // output_value
      case 102: // argument
      case 111: // constant
        yylhs.value.emplace< AST::ExprNode* > ();
        break;

      case 100: // function_call
        yylhs.value.emplace< AST::FunctionCallExprNode* > ();
        break;

      case 68: // function_declaration
        yylhs.value.emplace< AST::FunctionDeclNode* > ();
        break;

      case 82: // if_statement
        yylhs.value.emplace< AST::IfStmtNode* > ();
        break;

      case 112: // integer_constant
        yylhs.value.emplace< AST::IntegerExprNode* > ();
        break;

      case 79: // optional_arguments
        yylhs.value.emplace< AST::OptionalArgumentsNode* > ();
        break;

      case 78: // procedure_statement
        yylhs.value.emplace< AST::ProcedureCallStmtNode* > ();
        break;

      case 67: // procedure_declarations
        yylhs.value.emplace< AST::ProcedureDeclNode* > ();
        break;

      case 76: // read_statement
        yylhs.value.emplace< AST::ReadStmtNode* > ();
        break;

      case 113: // real_constant
        yylhs.value.emplace< AST::RealExprNode* > ();
        break;

      case 81: // simple_statement
      case 84: // structured_statement
      case 85: // statement
        yylhs.value.emplace< AST::StmtNode* > ();
        break;

      case 115: // string_constant
        yylhs.value.emplace< AST::StringExprNode* > ();
        break;

      case 59: // variable_declaration
      case 70: // parameter_list
        yylhs.value.emplace< AST::VariableDeclNode* > ();
        break;

      case 57: // variable_declarations
      case 69: // opt_params
        yylhs.value.emplace< AST::VariableDeclarationsNode* > ();
        break;

      case 109: // variable
      case 110: // indexed_variable
        yylhs.value.emplace< AST::VariableExprNode* > ();
        break;

      case 75: // input_variable
      case 88: // variable_lvalue
      case 108: // variable_rvalue
        yylhs.value.emplace< AST::VariableNode* > ();
        break;

      case 83: // while_statement
        yylhs.value.emplace< AST::WhileStmtNode* > ();
        break;

      case 77: // write_statement
        yylhs.value.emplace< AST::WriteStmtNode* > ();
        break;

      case 61: // type
      case 63: // array_type
        yylhs.value.emplace< LNG::DataType > ();
        break;

      case 62: // simple_type
        yylhs.value.emplace< LNG::SimpleDataType > ();
        break;

      case 116: // mult_op
      case 117: // add_op
      case 118: // rel_op
      case 119: // sign
        yylhs.value.emplace< Language::ExprOperator > ();
        break;

      case 74: // callable_declarations_list
        yylhs.value.emplace< std::list<AST::CallableDeclNode*> > ();
        break;

      case 80: // arguments_list
        yylhs.value.emplace< std::list<AST::ExprNode*> > ();
        break;

      case 66: // list_statement
        yylhs.value.emplace< std::list<AST::StmtNode*> > ();
        break;

      case 58: // list_variable_declaration
      case 72: // list_parameterList_declaration
        yylhs.value.emplace< std::list<AST::VariableDeclNode*> > ();
        break;

      case 60: // list_identifier
      case 71: // parameters
        yylhs.value.emplace< std::list<std::string> > ();
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
      case 101: // identifier
      case 103: // function_identifier
      case 104: // procedure_identifier
      case 105: // variable_identifier
      case 106: // entire_variable
      case 107: // array_variable
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 258 "tpparser.yy"
    {
    prs.ast_ = new AST::ProgramNode( yystack_[3].value.as < std::string > (), yystack_[1].value.as < AST::BlockNode* > () );
    prs.set_AST( new AST::ProgramNode( yystack_[3].value.as < std::string > (), yystack_[1].value.as < AST::BlockNode* > () ) );
    }
#line 1297 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 3:
#line 268 "tpparser.yy"
    { yylhs.value.as < AST::BlockNode* > () = new AST::BlockNode( yystack_[2].value.as < AST::VariableDeclarationsNode* > (), yystack_[1].value.as < AST::CallableDeclarationsNode* > (), yystack_[0].value.as < AST::CompoundStmtNode* > () ); }
#line 1303 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 4:
#line 273 "tpparser.yy"
    { yylhs.value.as < AST::VariableDeclarationsNode* > () = new AST::VariableDeclarationsNode( yystack_[0].value.as < std::list<AST::VariableDeclNode*> > () ); }
#line 1309 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 5:
#line 276 "tpparser.yy"
    { yylhs.value.as < AST::VariableDeclarationsNode* > () = nullptr; }
#line 1315 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 6:
#line 281 "tpparser.yy"
    { yystack_[2].value.as < std::list<AST::VariableDeclNode*> > ().push_back( yystack_[1].value.as < AST::VariableDeclNode* > () ); yylhs.value.as < std::list<AST::VariableDeclNode*> > () = yystack_[2].value.as < std::list<AST::VariableDeclNode*> > (); }
#line 1321 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 7:
#line 284 "tpparser.yy"
    { std::list<AST::VariableDeclNode*> lst; lst.push_back( yystack_[1].value.as < AST::VariableDeclNode* > () ); yylhs.value.as < std::list<AST::VariableDeclNode*> > () = lst; }
#line 1327 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 8:
#line 289 "tpparser.yy"
    {
    LNG::DataType newType = LNG::DataType(yystack_[0].value.as < LNG::DataType > ());
    for(auto i : yystack_[2].value.as < std::list<std::string> > ()){
        prs.symbol_table_.add_var(prs.scope_, i, newType);
    }
    yylhs.value.as < AST::VariableDeclNode* > () = new AST::VariableDeclNode( yystack_[2].value.as < std::list<std::string> > (), yystack_[0].value.as < LNG::DataType > () );
    }
#line 1339 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 9:
#line 300 "tpparser.yy"
    {
    yystack_[2].value.as < std::list<std::string> > ().push_back( yystack_[0].value.as < std::string > () ); yylhs.value.as < std::list<std::string> > () = yystack_[2].value.as < std::list<std::string> > ();
    }
#line 1347 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 10:
#line 305 "tpparser.yy"
    { std::list<std::string> lst; lst.push_back( yystack_[0].value.as < std::string > () ); yylhs.value.as < std::list<std::string> > () = lst; }
#line 1353 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 11:
#line 309 "tpparser.yy"
    { yylhs.value.as < LNG::DataType > () = LNG::DataType(yystack_[0].value.as < LNG::SimpleDataType > ()); }
#line 1359 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 12:
#line 311 "tpparser.yy"
    { yylhs.value.as < LNG::DataType > () = yystack_[0].value.as < LNG::DataType > (); }
#line 1365 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 13:
#line 315 "tpparser.yy"
    { yylhs.value.as < LNG::SimpleDataType > () = LNG::SimpleDataType::tInteger; }
#line 1371 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 14:
#line 317 "tpparser.yy"
    { yylhs.value.as < LNG::SimpleDataType > () = LNG::SimpleDataType::tBoolean; }
#line 1377 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 15:
#line 319 "tpparser.yy"
    { yylhs.value.as < LNG::SimpleDataType > () = LNG::SimpleDataType::tReal; }
#line 1383 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 16:
#line 331 "tpparser.yy"
    { yylhs.value.as < LNG::DataType > () = yylhs.value.as < LNG::DataType > () = LNG::DataType( yystack_[0].value.as < LNG::SimpleDataType > (), std::stoi(yystack_[5].value.as < std::string > ()), std::stoi(yystack_[3].value.as < std::string > ()) ); }
#line 1389 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 17:
#line 336 "tpparser.yy"
    {yylhs.value.as < AST::CompoundStmtNode* > () = yystack_[0].value.as < AST::CompoundStmtNode* > ();}
#line 1395 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 18:
#line 343 "tpparser.yy"
    { yylhs.value.as < AST::CompoundStmtNode* > () = new AST::CompoundStmtNode(yystack_[1].value.as < std::list<AST::StmtNode*> > ()); }
#line 1401 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 19:
#line 348 "tpparser.yy"
    { yystack_[2].value.as < std::list<AST::StmtNode*> > ().push_back( yystack_[0].value.as < AST::StmtNode* > () ); yylhs.value.as < std::list<AST::StmtNode*> > () = yystack_[2].value.as < std::list<AST::StmtNode*> > (); }
#line 1407 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 20:
#line 351 "tpparser.yy"
    { std::list<AST::StmtNode*> lst; lst.push_back( yystack_[0].value.as < AST::StmtNode* > () ); yylhs.value.as < std::list<AST::StmtNode*> > () = lst; }
#line 1413 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 21:
#line 370 "tpparser.yy"
    {
    prs.scope_ = yystack_[4].value.as < std::string > ();
    AST::ProcedureDeclNode* node = new AST::ProcedureDeclNode( yystack_[4].value.as < std::string > (), yystack_[3].value.as < AST::VariableDeclarationsNode* > (), yystack_[1].value.as < AST::BlockNode* > ());
    std::string signature = "";
    if(yystack_[3].value.as < AST::VariableDeclarationsNode* > () != nullptr){
        for(auto i : yystack_[3].value.as < AST::VariableDeclarationsNode* > ()->get_declarations()){
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
    prs.symbol_table_.add_procedure(yystack_[4].value.as < std::string > (), signature);
    prs.scope_ = "";
    yylhs.value.as < AST::ProcedureDeclNode* > () = node;
    }
#line 1438 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 22:
#line 401 "tpparser.yy"
    {
    prs.scope_ = yystack_[6].value.as < std::string > ();
    LNG::DataType newType = LNG::DataType(yystack_[3].value.as < LNG::SimpleDataType > ());
    AST::FunctionDeclNode* node = new AST::FunctionDeclNode( yystack_[6].value.as < std::string > (), yystack_[5].value.as < AST::VariableDeclarationsNode* > (), yystack_[1].value.as < AST::BlockNode* > (), newType);
    std::string signature = "";
    if(yystack_[5].value.as < AST::VariableDeclarationsNode* > () != nullptr){
        for(auto i : yystack_[5].value.as < AST::VariableDeclarationsNode* > ()->get_declarations()){
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
    prs.symbol_table_.add_function(yystack_[6].value.as < std::string > (), signature, newType);
    prs.scope_ = "";
    yylhs.value.as < AST::FunctionDeclNode* > () = node;
    }
#line 1464 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 23:
#line 426 "tpparser.yy"
    {yylhs.value.as < AST::VariableDeclarationsNode* > () = new AST::VariableDeclarationsNode(yystack_[1].value.as < std::list<AST::VariableDeclNode*> > ());}
#line 1470 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 24:
#line 428 "tpparser.yy"
    {yylhs.value.as < AST::VariableDeclarationsNode* > () = nullptr;}
#line 1476 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 25:
#line 433 "tpparser.yy"
    {
    LNG::DataType newType = LNG::DataType(yystack_[0].value.as < LNG::SimpleDataType > ());
    yylhs.value.as < AST::VariableDeclNode* > () = new AST::VariableDeclNode(yystack_[2].value.as < std::list<std::string> > (), newType);
    }
#line 1485 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 26:
#line 441 "tpparser.yy"
    {yystack_[2].value.as < std::list<std::string> > ().push_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::list<std::string> > () = yystack_[2].value.as < std::list<std::string> > ();}
#line 1491 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 27:
#line 444 "tpparser.yy"
    {std::list<std::string> lst; lst.push_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::list<std::string> > () = lst;}
#line 1497 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 28:
#line 451 "tpparser.yy"
    {yystack_[2].value.as < std::list<AST::VariableDeclNode*> > ().push_back(yystack_[0].value.as < AST::VariableDeclNode* > ()); yylhs.value.as < std::list<AST::VariableDeclNode*> > () = yystack_[2].value.as < std::list<AST::VariableDeclNode*> > ();}
#line 1503 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 29:
#line 454 "tpparser.yy"
    {
    std::list<AST::VariableDeclNode*> lst;
    yylhs.value.as < std::list<AST::VariableDeclNode*> > () = lst;
    }
#line 1512 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 30:
#line 460 "tpparser.yy"
    {std::list<AST::VariableDeclNode*> lst; lst.push_back(yystack_[0].value.as < AST::VariableDeclNode* > ()); yylhs.value.as < std::list<AST::VariableDeclNode*> > () = lst;}
#line 1518 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 31:
#line 465 "tpparser.yy"
    {yylhs.value.as < AST::CallableDeclarationsNode* > () = new CallableDeclarationsNode(yystack_[0].value.as < std::list<AST::CallableDeclNode*> > ());}
#line 1524 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 32:
#line 469 "tpparser.yy"
    { yystack_[1].value.as < std::list<AST::CallableDeclNode*> > ().push_back(yystack_[0].value.as < AST::ProcedureDeclNode* > ()); yylhs.value.as < std::list<AST::CallableDeclNode*> > () = yystack_[1].value.as < std::list<AST::CallableDeclNode*> > (); }
#line 1530 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 33:
#line 471 "tpparser.yy"
    { yystack_[1].value.as < std::list<AST::CallableDeclNode*> > ().push_back(yystack_[0].value.as < AST::FunctionDeclNode* > ()); yylhs.value.as < std::list<AST::CallableDeclNode*> > () = yystack_[1].value.as < std::list<AST::CallableDeclNode*> > (); }
#line 1536 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 34:
#line 473 "tpparser.yy"
    {std::list<AST::CallableDeclNode*> lst; yylhs.value.as < std::list<AST::CallableDeclNode*> > () = lst;}
#line 1542 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 35:
#line 478 "tpparser.yy"
    { yylhs.value.as < AST::VariableNode* > () = yystack_[0].value.as < AST::VariableNode* > (); }
#line 1548 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 36:
#line 484 "tpparser.yy"
    { yylhs.value.as < AST::ReadStmtNode* > () = new AST::ReadStmtNode( yystack_[0].value.as < AST::VariableNode* > () ); }
#line 1554 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 37:
#line 488 "tpparser.yy"
    { yylhs.value.as < AST::ReadStmtNode* > () = new AST::ReadStmtNode( yystack_[0].value.as < AST::VariableNode* > (), true); }
#line 1560 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 38:
#line 496 "tpparser.yy"
    {yylhs.value.as < AST::WriteStmtNode* > () = new AST::WriteStmtNode( yystack_[1].value.as < AST::ExprNode* > () );}
#line 1566 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 39:
#line 502 "tpparser.yy"
    { yylhs.value.as < AST::WriteStmtNode* > () = new AST::WriteStmtNode( yystack_[1].value.as < AST::ExprNode* > (), true); }
#line 1572 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 40:
#line 507 "tpparser.yy"
    { yylhs.value.as < AST::ProcedureCallStmtNode* > () = new AST::ProcedureCallStmtNode( yystack_[1].value.as < std::string > (), yystack_[0].value.as < AST::OptionalArgumentsNode* > ()->get_list() ); }
#line 1578 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 41:
#line 512 "tpparser.yy"
    {
    std::list<AST::ExprNode*> lst;
    yylhs.value.as < AST::OptionalArgumentsNode* > () = new AST::OptionalArgumentsNode(lst);
    }
#line 1587 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 42:
#line 518 "tpparser.yy"
    { yylhs.value.as < AST::OptionalArgumentsNode* > () = new AST::OptionalArgumentsNode(yystack_[1].value.as < std::list<AST::ExprNode*> > ()); }
#line 1593 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 43:
#line 530 "tpparser.yy"
    {yystack_[2].value.as < std::list<AST::ExprNode*> > ().push_back(yystack_[0].value.as < AST::ExprNode* > ()); yylhs.value.as < std::list<AST::ExprNode*> > () = yystack_[2].value.as < std::list<AST::ExprNode*> > ();}
#line 1599 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 44:
#line 533 "tpparser.yy"
    {std::list<AST::ExprNode*> lst; lst.push_back(yystack_[0].value.as < AST::ExprNode* > ()); yylhs.value.as < std::list<AST::ExprNode*> > () = lst;}
#line 1605 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 45:
#line 537 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::AssignmentStmtNode* > (); }
#line 1611 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 46:
#line 539 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::EmptyStmtNode* > (); }
#line 1617 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 47:
#line 541 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::ProcedureCallStmtNode* > (); }
#line 1623 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 48:
#line 543 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::ReadStmtNode* > (); }
#line 1629 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 49:
#line 545 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::WriteStmtNode* > (); }
#line 1635 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 50:
#line 550 "tpparser.yy"
    { yylhs.value.as < AST::IfStmtNode* > () = new AST::IfStmtNode(yystack_[2].value.as < AST::ExprNode* > (), yystack_[0].value.as < AST::StmtNode* > ()); }
#line 1641 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 51:
#line 553 "tpparser.yy"
    { yylhs.value.as < AST::IfStmtNode* > () = new AST::IfStmtNode(yystack_[4].value.as < AST::ExprNode* > (), yystack_[2].value.as < AST::StmtNode* > (), yystack_[0].value.as < AST::StmtNode* > ()); }
#line 1647 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 52:
#line 558 "tpparser.yy"
    { yylhs.value.as < AST::WhileStmtNode* > () = new AST::WhileStmtNode(yystack_[2].value.as < AST::ExprNode* > (), yystack_[0].value.as < AST::StmtNode* > ()); }
#line 1653 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 53:
#line 562 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::CompoundStmtNode* > (); }
#line 1659 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 54:
#line 564 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::IfStmtNode* > (); }
#line 1665 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 55:
#line 566 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::WhileStmtNode* > (); }
#line 1671 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 56:
#line 570 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::StmtNode* > (); }
#line 1677 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 57:
#line 572 "tpparser.yy"
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::StmtNode* > (); }
#line 1683 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 58:
#line 576 "tpparser.yy"
    { yylhs.value.as < AST::EmptyStmtNode* > () = new AST::EmptyStmtNode(); }
#line 1689 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 59:
#line 583 "tpparser.yy"
    { yylhs.value.as < AST::AssignmentStmtNode* > () = new AST::AssignmentStmtNode( yystack_[2].value.as < AST::VariableNode* > (), yystack_[0].value.as < AST::ExprNode* > ()); }
#line 1695 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 60:
#line 588 "tpparser.yy"
    {
    AST::VariableNode* node = new AST::VariableNode(yystack_[2].value.as < std::string > ());
    yylhs.value.as < AST::AssignmentStmtNode* > () = new AST::AssignmentStmtNode(node, yystack_[0].value.as < AST::ExprNode* > ());
    }
#line 1704 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 61:
#line 597 "tpparser.yy"
    {
    yylhs.value.as < AST::VariableNode* > () = new VariableNode(yystack_[0].value.as < AST::VariableExprNode* > ()->get_name(), yystack_[0].value.as < AST::VariableExprNode* > ()->get_expr());
    }
#line 1712 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 62:
#line 604 "tpparser.yy"
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1718 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 63:
#line 609 "tpparser.yy"
    {
    ExprNode* expr = new AST::OpExprNode(yystack_[2].value.as < Language::ExprOperator > (), yystack_[3].value.as < AST::ExprNode* > (), yystack_[1].value.as < AST::ExprNode* > ());
    yylhs.value.as < AST::ExprNode* > () = expr;
    }
#line 1727 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 64:
#line 615 "tpparser.yy"
    {
    ExprNode* expr =  new AST::OpExprNode(yystack_[1].value.as < Language::ExprOperator > (), yystack_[2].value.as < AST::ExprNode* > (), yystack_[0].value.as < AST::ExprNode* > ());
    yylhs.value.as < AST::ExprNode* > () = expr;
    }
#line 1736 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 65:
#line 621 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1742 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 66:
#line 627 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1748 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 67:
#line 631 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = new AST::OpExprNode(yystack_[1].value.as < Language::ExprOperator > (),yystack_[2].value.as < AST::ExprNode* > (),yystack_[0].value.as < AST::ExprNode* > ());}
#line 1754 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 68:
#line 634 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1760 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 69:
#line 639 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1766 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 70:
#line 644 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = new AST::OpExprNode(yystack_[1].value.as < Language::ExprOperator > (),yystack_[2].value.as < AST::ExprNode* > (),yystack_[0].value.as < AST::ExprNode* > ());}
#line 1772 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 71:
#line 647 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1778 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 72:
#line 653 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1784 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 73:
#line 657 "tpparser.yy"
    {
        AST::ExprNode *expr = new AST::OpExprNode(Language::ExprOperator::o_not, nullptr, yystack_[0].value.as < AST::ExprNode* > ());
        yylhs.value.as < AST::ExprNode* > () = expr;
    }
#line 1793 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 74:
#line 664 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1799 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 75:
#line 668 "tpparser.yy"
    {
        if(yystack_[1].value.as < Language::ExprOperator > () == Language::ExprOperator::o_minus){
            AST::ExprNode *expr = new AST::OpExprNode(Language::ExprOperator::o_minus, nullptr, yystack_[0].value.as < AST::ExprNode* > ());
            yylhs.value.as < AST::ExprNode* > () = expr;
        }
        else{
            yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();
        }
    }
#line 1813 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 76:
#line 680 "tpparser.yy"
    {
    yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::VariableNode* > ()->get_expr();
    }
#line 1821 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 77:
#line 685 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1827 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 78:
#line 690 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[1].value.as < AST::ExprNode* > ();}
#line 1833 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 79:
#line 693 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::FunctionCallExprNode* > ();}
#line 1839 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 80:
#line 700 "tpparser.yy"
    {yylhs.value.as < AST::BlockNode* > () = new AST::BlockNode(yystack_[1].value.as < AST::VariableDeclarationsNode* > (), yystack_[0].value.as < AST::CompoundStmtNode* > ());}
#line 1845 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 81:
#line 704 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::StringExprNode* > ();}
#line 1851 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 82:
#line 707 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1857 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 83:
#line 714 "tpparser.yy"
    {
        yylhs.value.as < AST::FunctionCallExprNode* > () = new AST::FunctionCallExprNode(yystack_[1].value.as < std::string > (), yystack_[0].value.as < AST::OptionalArgumentsNode* > ()->get_list());
    }
#line 1865 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 84:
#line 720 "tpparser.yy"
    {std::string retval(prs.token_.text); yylhs.value.as < std::string > () = retval;}
#line 1871 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 85:
#line 725 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > ();}
#line 1877 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 86:
#line 730 "tpparser.yy"
    {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1883 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 87:
#line 735 "tpparser.yy"
    {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1889 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 88:
#line 740 "tpparser.yy"
    {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1895 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 89:
#line 745 "tpparser.yy"
    {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1901 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 90:
#line 749 "tpparser.yy"
    {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1907 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 91:
#line 754 "tpparser.yy"
    {
    AST::VariableNode* node = new AST::VariableNode(yystack_[0].value.as < AST::VariableExprNode* > ()->get_name(), yystack_[0].value.as < AST::VariableExprNode* > ());
    yylhs.value.as < AST::VariableNode* > () =  node;
    }
#line 1916 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 92:
#line 762 "tpparser.yy"
    {yylhs.value.as < AST::VariableExprNode* > () = new AST::VariableExprNode(yystack_[0].value.as < std::string > ());}
#line 1922 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 93:
#line 765 "tpparser.yy"
    {
    yylhs.value.as < AST::VariableExprNode* > () = yystack_[0].value.as < AST::VariableExprNode* > ();
    }
#line 1930 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 94:
#line 775 "tpparser.yy"
    {yylhs.value.as < AST::VariableExprNode* > () = new AST::VariableExprNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < AST::ExprNode* > ());}
#line 1936 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 95:
#line 781 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::IntegerExprNode* > ();}
#line 1942 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 96:
#line 784 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::RealExprNode* > ();}
#line 1948 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 97:
#line 787 "tpparser.yy"
    {yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::BooleanExprNode* > ();}
#line 1954 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 98:
#line 792 "tpparser.yy"
    {
    int tmp = std::stoi(prs.token_.text);
    yylhs.value.as < AST::IntegerExprNode* > () = new IntegerExprNode(tmp);
    }
#line 1963 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 99:
#line 800 "tpparser.yy"
    {
    float tmp = std::stof(prs.token_.text);
    yylhs.value.as < AST::RealExprNode* > () = new RealExprNode(tmp);
    }
#line 1972 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 100:
#line 808 "tpparser.yy"
    {
    bool tmp = bool(prs.token_.name);
    yylhs.value.as < AST::BooleanExprNode* > () = new BooleanExprNode(tmp);
    }
#line 1981 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 101:
#line 815 "tpparser.yy"
    {
    std::string s(prs.token_.text);
    yylhs.value.as < AST::StringExprNode* > () = new StringExprNode(s);
    }
#line 1990 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 102:
#line 823 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_multiply;}
#line 1996 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 103:
#line 826 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_divide;}
#line 2002 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 104:
#line 829 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_div;}
#line 2008 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 105:
#line 832 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_and;}
#line 2014 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 106:
#line 837 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_plus;}
#line 2020 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 107:
#line 840 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_minus;}
#line 2026 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 108:
#line 843 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_or;}
#line 2032 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 109:
#line 848 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_eq;}
#line 2038 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 110:
#line 851 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_gt;}
#line 2044 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 111:
#line 854 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_gteq;}
#line 2050 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 112:
#line 857 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_lt;}
#line 2056 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 113:
#line 860 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_lteq;}
#line 2062 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 114:
#line 864 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_minus;}
#line 2068 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;

  case 115:
#line 867 "tpparser.yy"
    {yylhs.value.as < Language::ExprOperator > () = Language::ExprOperator::o_plus;}
#line 2074 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"
    break;


#line 2078 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -143;

  const signed char parser::yytable_ninf_ = -89;

  const short
  parser::yypact_[] =
  {
     -34,   -37,    15,  -143,     6,  -143,    -8,   -37,    27,  -143,
    -143,   -37,     9,    35,  -143,  -143,    45,    -5,    41,  -143,
      95,   -37,    65,  -143,   -37,   -37,  -143,  -143,  -143,    68,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,    22,   -37,   -37,
      22,    56,    73,  -143,    25,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,    98,    13,   114,   102,  -143,
    -143,   110,  -143,  -143,  -143,   112,  -143,   112,    78,  -143,
    -143,    22,  -143,    43,  -143,  -143,    88,  -143,   117,  -143,
       4,  -143,    76,  -143,  -143,  -143,   115,   102,  -143,  -143,
    -143,  -143,  -143,  -143,    58,  -143,  -143,   115,  -143,   105,
      16,    16,    65,  -143,    22,    22,    22,  -143,  -143,    22,
     -37,   122,   116,   118,   120,  -143,    65,  -143,  -143,  -143,
    -143,  -143,    22,  -143,  -143,  -143,    22,  -143,  -143,  -143,
    -143,    22,  -143,  -143,    65,  -143,  -143,   121,  -143,   123,
    -143,  -143,  -143,    44,  -143,   125,  -143,    74,    38,  -143,
    -143,    20,    -8,    92,  -143,   119,    22,  -143,  -143,  -143,
    -143,  -143,    22,  -143,  -143,    20,   -37,  -143,   -37,   127,
      45,   128,   126,    65,  -143,  -143,  -143,  -143,  -143,  -143,
      -8,  -143,  -143,  -143,   111,  -143,   129,    20,  -143,  -143
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,    84,     0,     1,    58,     0,     0,    34,
       5,     4,     0,     0,    10,     2,     0,    31,     0,     7,
       0,     0,    58,     3,     0,     0,    32,    33,     6,     0,
      14,    13,    15,     8,    11,    12,     9,     0,     0,     0,
       0,     0,     0,    53,     0,    48,    49,    47,    56,    54,
      55,    57,    20,    46,    45,     0,    87,     0,    58,    89,
      90,     0,    61,    93,    86,    24,    87,    24,     0,   114,
     115,     0,   100,     0,    98,    99,     0,    62,    65,    66,
      68,    69,    71,    72,    74,    79,    86,    58,    76,    91,
      77,    95,    96,    97,     0,    36,    35,    92,    37,     0,
       0,     0,    58,    18,     0,     0,     0,    40,    41,     0,
      58,     0,     0,     0,     0,    73,    58,   109,   110,   111,
     112,   113,     0,   107,   106,   108,     0,   103,   102,   105,
     104,     0,    83,    75,    58,   101,    82,     0,    81,     0,
      19,    59,    60,     0,    44,     0,    30,     0,     0,    29,
      27,     0,    58,     0,    78,    50,    64,    67,    70,    52,
      38,    39,     0,    42,    94,     0,     0,    23,     0,     0,
       0,     0,     0,    58,    63,    85,    43,    25,    26,    28,
      58,    80,    17,    21,     0,    51,     0,     0,    22,    16
  };

  const short
  parser::yypgoto_[] =
  {
    -143,  -143,  -143,   146,  -143,   142,  -143,  -143,  -142,  -143,
    -143,   -14,  -143,  -143,  -143,    91,   -13,  -143,  -143,  -143,
    -143,   124,  -143,  -143,  -143,    72,  -143,  -143,  -143,  -143,
    -143,   -98,    -6,  -143,    57,   -27,     5,    40,    34,  -143,
      33,  -143,    94,    71,   -11,    69,  -143,     0,  -143,   -16,
     147,  -143,  -143,  -143,  -143,   -19,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     8,   170,    11,    12,    13,    33,    34,    35,
     181,    43,    44,    26,    27,   111,   146,   147,   148,    16,
      17,    95,    45,    46,    47,   107,   143,    48,    49,    50,
      51,    52,    53,    54,    55,   136,    77,    78,    79,    80,
      81,    82,    83,    84,   171,   137,    85,    86,   176,    87,
      58,    59,    60,    61,    88,    89,    63,    90,    91,    92,
      93,   138,   131,   126,   122,    94
  };

  const short
  parser::yytable_[] =
  {
      10,     4,    23,    62,   140,     1,    57,    14,    65,   169,
      76,    14,     3,    99,   123,     5,   -86,   124,   155,    62,
      62,    36,    56,   177,    64,    66,    69,    24,     6,    70,
     -88,    19,    69,    25,    71,    70,   159,     7,    97,    97,
      71,   125,    72,    15,   114,   189,    30,   102,    72,    20,
      21,    73,   108,    69,    31,   103,    70,    73,   167,   162,
     168,    71,    32,    28,   163,     3,    74,    75,   135,    72,
      22,     3,    74,    75,   100,   185,    71,   141,   142,   144,
     127,   108,   145,    62,    72,    68,    57,   128,   165,   166,
      22,   101,     3,    74,    75,    96,    96,    62,    37,   129,
      57,   104,    56,   130,   149,    38,    39,     3,    74,    75,
     150,    40,    41,    42,     3,    62,    56,   105,    57,    29,
     106,    30,   117,   118,   119,   120,   121,   109,   113,    31,
     110,   116,   -88,   134,    56,   175,   151,    32,   152,   153,
     154,   160,   172,   161,   164,   184,    10,   187,   173,   180,
     183,   188,     9,    18,    62,   179,   182,    57,   112,   132,
     157,   174,   156,    98,   158,   133,   178,   115,   150,   186,
     139,     0,    67,    56,    10
  };

  const short
  parser::yycheck_[] =
  {
       6,     1,    16,    22,   102,    39,    22,     7,    24,   151,
      37,    11,    49,    40,    10,     0,     3,    13,   116,    38,
      39,    21,    22,   165,    24,    25,    10,    32,    22,    13,
      17,    22,    10,    38,    18,    13,   134,    45,    38,    39,
      18,    37,    26,    16,    71,   187,    26,    22,    26,    14,
      15,    35,    58,    10,    34,    30,    13,    35,    20,    15,
      22,    18,    42,    22,    20,    49,    50,    51,    52,    26,
      25,    49,    50,    51,    18,   173,    18,   104,   105,   106,
       4,    87,   109,   102,    26,    17,   102,    11,    14,    15,
      25,    18,    49,    50,    51,    38,    39,   116,    33,    23,
     116,     3,   102,    27,   110,    40,    41,    49,    50,    51,
     110,    46,    47,    48,    49,   134,   116,     3,   134,    24,
      18,    26,     5,     6,     7,     8,     9,    17,    50,    34,
      18,    43,    17,    28,   134,   162,    14,    42,    22,    21,
      20,    20,    50,    20,    19,    19,   152,    36,    29,    22,
      22,    22,     6,    11,   173,   168,   170,   173,    67,    87,
     126,   156,   122,    39,   131,    94,   166,    73,   168,   180,
     101,    -1,    25,   173,   180
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    39,    55,    49,   101,     0,    22,    45,    56,    57,
      86,    58,    59,    60,   101,    16,    73,    74,    59,    22,
      14,    15,    25,    65,    32,    38,    67,    68,    22,    24,
      26,    34,    42,    61,    62,    63,   101,    33,    40,    41,
      46,    47,    48,    65,    66,    76,    77,    78,    81,    82,
      83,    84,    85,    86,    87,    88,   101,   103,   104,   105,
     106,   107,   109,   110,   101,   103,   101,   104,    17,    10,
      13,    18,    26,    35,    50,    51,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   100,   101,   103,   108,   109,
     111,   112,   113,   114,   119,    75,    88,   101,    75,    89,
      18,    18,    22,    30,     3,     3,    18,    79,    86,    17,
      18,    69,    69,    50,    89,    96,    43,     5,     6,     7,
       8,     9,   118,    10,    13,    37,   117,     4,    11,    23,
      27,   116,    79,    97,    28,    52,    89,    99,   115,    99,
      85,    89,    89,    80,    89,    89,    70,    71,    72,    86,
     101,    14,    22,    21,    20,    85,    91,    92,    94,    85,
      20,    20,    15,    20,    19,    14,    15,    20,    22,    62,
      57,    98,    50,    29,    90,    89,   102,    62,   101,    70,
      22,    64,    65,    22,    19,    85,    98,    36,    22,    62
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    54,    55,    56,    57,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    62,    62,    63,    64,    65,    66,
      66,    67,    68,    69,    69,    70,    71,    71,    72,    72,
      72,    73,    74,    74,    74,    75,    76,    76,    77,    77,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      82,    82,    83,    84,    84,    84,    85,    85,    86,    87,
      87,    88,    89,    90,    90,    90,    91,    92,    92,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      98,    99,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   109,   110,   111,   111,   111,   112,   113,
     114,   115,   116,   116,   116,   116,   117,   117,   117,   118,
     118,   118,   118,   118,   119,   119
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     5,     3,     2,     1,     3,     2,     3,     3,
       1,     1,     1,     1,     1,     1,     8,     1,     3,     3,
       1,     6,     8,     3,     0,     3,     3,     1,     3,     1,
       1,     1,     2,     2,     0,     1,     2,     2,     4,     4,
       2,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     6,     4,     1,     1,     1,     1,     1,     0,     3,
       3,     1,     1,     4,     3,     1,     1,     3,     1,     1,
       3,     1,     1,     2,     1,     2,     1,     1,     3,     1,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "t_eoi", "error", "$undefined", "t_assign", "t_divide", "t_eq", "t_gt",
  "t_gteq", "t_lt", "t_lteq", "t_minus", "t_multiply", "t_neq", "t_plus",
  "t_colon", "t_comma", "t_dot", "t_lbracket", "t_lparenthesis",
  "t_rbracket", "t_rparenthesis", "t_subrange", "t_semicolon", "t_and",
  "t_array", "t_begin", "t_boolean", "t_div", "t_do", "t_else", "t_end",
  "t_false", "t_function", "t_if", "t_integer", "t_not", "t_of", "t_or",
  "t_procedure", "t_program", "t_read", "t_readln", "t_real", "t_then",
  "t_true", "t_var", "t_while", "t_write", "t_writeln", "t_identifier",
  "t_integer_l", "t_real_l", "t_string_l", "t_unknown", "$accept",
  "program", "main_block", "variable_declarations",
  "list_variable_declaration", "variable_declaration", "list_identifier",
  "type", "simple_type", "array_type", "statements", "compound_statement",
  "list_statement", "procedure_declarations", "function_declaration",
  "opt_params", "parameter_list", "parameters",
  "list_parameterList_declaration", "callable_declarations",
  "callable_declarations_list", "input_variable", "read_statement",
  "write_statement", "procedure_statement", "optional_arguments",
  "arguments_list", "simple_statement", "if_statement", "while_statement",
  "structured_statement", "statement", "empty_statement",
  "assignment_statement", "variable_lvalue", "expression",
  "simple_expressions", "simple_expression", "terms", "term",
  "complemented_factors", "complemented_factor", "signed_factor", "factor",
  "block", "output_value", "function_call", "identifier", "argument",
  "function_identifier", "procedure_identifier", "variable_identifier",
  "entire_variable", "array_variable", "variable_rvalue", "variable",
  "indexed_variable", "constant", "integer_constant", "real_constant",
  "boolean_constant", "string_constant", "mult_op", "add_op", "rel_op",
  "sign", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   255,   255,   265,   272,   275,   280,   283,   288,   299,
     304,   309,   311,   315,   317,   319,   323,   335,   340,   347,
     350,   364,   393,   425,   428,   432,   440,   443,   450,   453,
     459,   465,   469,   471,   473,   478,   482,   486,   492,   498,
     506,   511,   517,   529,   532,   537,   539,   541,   543,   545,
     549,   552,   557,   562,   564,   566,   570,   572,   576,   580,
     585,   596,   603,   608,   614,   620,   626,   630,   633,   638,
     643,   646,   652,   655,   663,   666,   679,   684,   687,   692,
     698,   703,   706,   712,   719,   724,   729,   734,   739,   744,
     748,   753,   761,   764,   771,   780,   783,   786,   791,   799,
     807,   814,   822,   825,   828,   831,   836,   839,   842,   847,
     850,   853,   856,   859,   863,   866
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2615 "/mnt/c/Users/Kristmann Ingi/Documents/Uni/Compilers/GitHub/TurboPascal/cmake-build-debug/../tpparser.cpp"

#line 869 "tpparser.yy"


  namespace yy
  {
    // Report an error to the user.
    auto parser::error(const location_type& l, const std::string &msg) -> void {
        std::cerr << msg << " at (" << l.begin.line << ',' << l.begin.column << ")\n";
    }
  }
