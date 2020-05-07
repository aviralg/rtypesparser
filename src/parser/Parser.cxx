// A Bison parser, made by GNU Bison 3.5.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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





#include "Parser.hxx"


// Unqualified %code blocks.
#line 291 "Parser.yxx"

    #include "parser/ParsingContext.hpp"
    #include "parser/Lexer.hpp"
    #undef yylex
    #define yylex lexer.yylex
// TODO op
TerminatorNodePtr create_terminator(const std::string& value,
                                    tastr::parser::Location& location,
                                    tastr::parser::ParsingContext& context) {
    TerminatorNodePtr terminator = new TerminatorNode(value);
    terminator -> set_location(location);
    return terminator;
}
// TODO op
IdentifierNodePtr create_identifier(const std::string& value,
                                    bool quoted,
                                    bool missing,
                                    tastr::parser::Location& location,
                                    tastr::parser::ParsingContext& context) {
    IdentifierNodePtr identifier = new IdentifierNode(value, quoted, missing);
    identifier -> set_location(location);
    return identifier;
}
// TODO op
OperatorNodePtr create_operator(const std::string& value,
                                tastr::parser::Location& location,
                                tastr::parser::ParsingContext& context) {
    OperatorNodePtr op = new OperatorNode(value);
    op -> set_location(location);
    return op;
}
// TODO op
SeparatorNodePtr create_separator(const std::string& value,
                                tastr::parser::Location& location,
                                tastr::parser::ParsingContext& context) {
    SeparatorNodePtr op = new SeparatorNode(value);
    op -> set_location(location);
    return op;
}

KeywordNodePtr create_keyword(const std::string& value,
                                tastr::parser::Location& location,
                                tastr::parser::ParsingContext& context) {
    KeywordNodePtr keyword = new KeywordNode(value);
    keyword -> set_location(location);
    return keyword;
}

template<typename T>
T* create_node_with_keyword(const std::string& value,
                            tastr::parser::Location& keyword_location,
                            tastr::parser::Location& node_location,
                            tastr::parser::ParsingContext& context) {
    KeywordNodePtr keyword = new KeywordNode(value);
    keyword -> set_location(keyword_location);
    T* node = new T(std::move(wrap(std::move(keyword))));
    node -> set_location(node_location);
    return node;
}

#line 106 "Parser.cxx"


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

#line 9 "Parser.yxx"
namespace tastr { namespace parser {
#line 198 "Parser.cxx"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
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
  Parser::Parser (tastr::parser::Lexer& lexer_yyarg, tastr::parser::ParsingContext& context_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      context (context_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 49: // ascalartype
        value.move< AScalarTypeNodePtr > (std::move (that.value));
        break;

      case 65: // anytype
        value.move< AnyTypeNodePtr > (std::move (that.value));
        break;

      case 60: // bytecodetype
        value.move< BytecodeTypeNodePtr > (std::move (that.value));
        break;

      case 54: // classtype
        value.move< ClassTypeNodePtr > (std::move (that.value));
        break;

      case 78: // dataframetype
        value.move< DataFrameTypeNodePtr > (std::move (that.value));
        break;

      case 55: // environmenttype
        value.move< EnvironmentTypeNodePtr > (std::move (that.value));
        break;

      case 56: // expressiontype
        value.move< ExpressionTypeNodePtr > (std::move (that.value));
        break;

      case 59: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (std::move (that.value));
        break;

      case 74: // grouptype
        value.move< GroupTypeNodePtr > (std::move (that.value));
        break;

      case 82: // identifier
        value.move< IdentifierNodePtr > (std::move (that.value));
        break;

      case 57: // languagetype
        value.move< LanguageTypeNodePtr > (std::move (that.value));
        break;

      case 76: // listtype
        value.move< ListTypeNodePtr > (std::move (that.value));
        break;

      case 51: // nascalartype
        value.move< NAScalarTypeNodePtr > (std::move (that.value));
        break;

      case 53: // classnameseq
      case 67: // typeseq
      case 69: // namedtypeseq
      case 71: // paramtypeseq
      case 72: // params
      case 77: // structelements
      case 80: // tupleelements
        value.move< NodePtr > (std::move (that.value));
        break;

      case 61: // pairlisttype
        value.move< PairlistTypeNodePtr > (std::move (that.value));
        break;

      case 50: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (std::move (that.value));
        break;

      case 62: // s4type
        value.move< S4TypeNodePtr > (std::move (that.value));
        break;

      case 52: // scalartype
        value.move< ScalarTypeNodePtr > (std::move (that.value));
        break;

      case 79: // structtype
        value.move< StructTypeNodePtr > (std::move (that.value));
        break;

      case 58: // symboltype
        value.move< SymbolTypeNodePtr > (std::move (that.value));
        break;

      case 68: // namedtype
        value.move< TagTypePairNodePtr > (std::move (that.value));
        break;

      case 81: // tupletype
        value.move< TupleTypeNodePtr > (std::move (that.value));
        break;

      case 87: // decltype
        value.move< TypeDeclarationNodePtr > (std::move (that.value));
        break;

      case 70: // paramtype
      case 73: // functiontype
      case 75: // nonconnectivetype
      case 83: // uniontype
      case 84: // intersectiontype
      case 85: // nulltype
      case 86: // type
        value.move< TypeNodePtr > (std::move (that.value));
        break;

      case 64: // unknowntype
        value.move< UnknownTypeNodePtr > (std::move (that.value));
        break;

      case 66: // vectortype
        value.move< VectorTypeNodePtr > (std::move (that.value));
        break;

      case 63: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (std::move (that.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
      case 42: // DATAFRAME
      case 43: // STRUCT
      case 44: // ANY
      case 45: // TYPEDECL
      case 46: // IDENTIFIER
      case 47: // QUOTED_IDENTIFIER
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 49: // ascalartype
        value.copy< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // anytype
        value.copy< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // classtype
        value.copy< ClassTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // dataframetype
        value.copy< DataFrameTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // expressiontype
        value.copy< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 74: // grouptype
        value.copy< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 82: // identifier
        value.copy< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // languagetype
        value.copy< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 76: // listtype
        value.copy< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // nascalartype
        value.copy< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // classnameseq
      case 67: // typeseq
      case 69: // namedtypeseq
      case 71: // paramtypeseq
      case 72: // params
      case 77: // structelements
      case 80: // tupleelements
        value.copy< NodePtr > (YY_MOVE (that.value));
        break;

      case 61: // pairlisttype
        value.copy< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // rawascalartype
        value.copy< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // s4type
        value.copy< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // scalartype
        value.copy< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // structtype
        value.copy< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // symboltype
        value.copy< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // namedtype
        value.copy< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 81: // tupletype
        value.copy< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 87: // decltype
        value.copy< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 70: // paramtype
      case 73: // functiontype
      case 75: // nonconnectivetype
      case 83: // uniontype
      case 84: // intersectiontype
      case 85: // nulltype
      case 86: // type
        value.copy< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // unknowntype
        value.copy< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // vectortype
        value.copy< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // weakreftype
        value.copy< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
      case 42: // DATAFRAME
      case 43: // STRUCT
      case 44: // ANY
      case 45: // TYPEDECL
      case 46: // IDENTIFIER
      case 47: // QUOTED_IDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 49: // ascalartype
        value.move< AScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 65: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 60: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 54: // classtype
        value.move< ClassTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 78: // dataframetype
        value.move< DataFrameTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 55: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 56: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 59: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 74: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 82: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (s.value));
        break;

      case 57: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 76: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 51: // nascalartype
        value.move< NAScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 53: // classnameseq
      case 67: // typeseq
      case 69: // namedtypeseq
      case 71: // paramtypeseq
      case 72: // params
      case 77: // structelements
      case 80: // tupleelements
        value.move< NodePtr > (YY_MOVE (s.value));
        break;

      case 61: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 50: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 62: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 52: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 79: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 58: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 68: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (s.value));
        break;

      case 81: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 87: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (s.value));
        break;

      case 70: // paramtype
      case 73: // functiontype
      case 75: // nonconnectivetype
      case 83: // uniontype
      case 84: // intersectiontype
      case 85: // nulltype
      case 86: // type
        value.move< TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 64: // unknowntype
        value.move< UnknownTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 66: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 63: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
      case 42: // DATAFRAME
      case 43: // STRUCT
      case 44: // ANY
      case 45: // TYPEDECL
      case 46: // IDENTIFIER
      case 47: // QUOTED_IDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 49: // ascalartype
        value.YY_MOVE_OR_COPY< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // anytype
        value.YY_MOVE_OR_COPY< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // bytecodetype
        value.YY_MOVE_OR_COPY< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // classtype
        value.YY_MOVE_OR_COPY< ClassTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // dataframetype
        value.YY_MOVE_OR_COPY< DataFrameTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // environmenttype
        value.YY_MOVE_OR_COPY< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // expressiontype
        value.YY_MOVE_OR_COPY< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // externalptrtype
        value.YY_MOVE_OR_COPY< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 74: // grouptype
        value.YY_MOVE_OR_COPY< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 82: // identifier
        value.YY_MOVE_OR_COPY< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // languagetype
        value.YY_MOVE_OR_COPY< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 76: // listtype
        value.YY_MOVE_OR_COPY< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // nascalartype
        value.YY_MOVE_OR_COPY< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // classnameseq
      case 67: // typeseq
      case 69: // namedtypeseq
      case 71: // paramtypeseq
      case 72: // params
      case 77: // structelements
      case 80: // tupleelements
        value.YY_MOVE_OR_COPY< NodePtr > (YY_MOVE (that.value));
        break;

      case 61: // pairlisttype
        value.YY_MOVE_OR_COPY< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // rawascalartype
        value.YY_MOVE_OR_COPY< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // s4type
        value.YY_MOVE_OR_COPY< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // scalartype
        value.YY_MOVE_OR_COPY< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // structtype
        value.YY_MOVE_OR_COPY< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // symboltype
        value.YY_MOVE_OR_COPY< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // namedtype
        value.YY_MOVE_OR_COPY< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 81: // tupletype
        value.YY_MOVE_OR_COPY< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 87: // decltype
        value.YY_MOVE_OR_COPY< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 70: // paramtype
      case 73: // functiontype
      case 75: // nonconnectivetype
      case 83: // uniontype
      case 84: // intersectiontype
      case 85: // nulltype
      case 86: // type
        value.YY_MOVE_OR_COPY< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // unknowntype
        value.YY_MOVE_OR_COPY< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // vectortype
        value.YY_MOVE_OR_COPY< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // weakreftype
        value.YY_MOVE_OR_COPY< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
      case 42: // DATAFRAME
      case 43: // STRUCT
      case 44: // ANY
      case 45: // TYPEDECL
      case 46: // IDENTIFIER
      case 47: // QUOTED_IDENTIFIER
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

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 49: // ascalartype
        value.move< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // classtype
        value.move< ClassTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // dataframetype
        value.move< DataFrameTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 74: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 82: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 76: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // nascalartype
        value.move< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // classnameseq
      case 67: // typeseq
      case 69: // namedtypeseq
      case 71: // paramtypeseq
      case 72: // params
      case 77: // structelements
      case 80: // tupleelements
        value.move< NodePtr > (YY_MOVE (that.value));
        break;

      case 61: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 81: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 87: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 70: // paramtype
      case 73: // functiontype
      case 75: // nonconnectivetype
      case 83: // uniontype
      case 84: // intersectiontype
      case 85: // nulltype
      case 86: // type
        value.move< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // unknowntype
        value.move< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
      case 42: // DATAFRAME
      case 43: // STRUCT
      case 44: // ANY
      case 45: // TYPEDECL
      case 46: // IDENTIFIER
      case 47: // QUOTED_IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 49: // ascalartype
        value.copy< AScalarTypeNodePtr > (that.value);
        break;

      case 65: // anytype
        value.copy< AnyTypeNodePtr > (that.value);
        break;

      case 60: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (that.value);
        break;

      case 54: // classtype
        value.copy< ClassTypeNodePtr > (that.value);
        break;

      case 78: // dataframetype
        value.copy< DataFrameTypeNodePtr > (that.value);
        break;

      case 55: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (that.value);
        break;

      case 56: // expressiontype
        value.copy< ExpressionTypeNodePtr > (that.value);
        break;

      case 59: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 74: // grouptype
        value.copy< GroupTypeNodePtr > (that.value);
        break;

      case 82: // identifier
        value.copy< IdentifierNodePtr > (that.value);
        break;

      case 57: // languagetype
        value.copy< LanguageTypeNodePtr > (that.value);
        break;

      case 76: // listtype
        value.copy< ListTypeNodePtr > (that.value);
        break;

      case 51: // nascalartype
        value.copy< NAScalarTypeNodePtr > (that.value);
        break;

      case 53: // classnameseq
      case 67: // typeseq
      case 69: // namedtypeseq
      case 71: // paramtypeseq
      case 72: // params
      case 77: // structelements
      case 80: // tupleelements
        value.copy< NodePtr > (that.value);
        break;

      case 61: // pairlisttype
        value.copy< PairlistTypeNodePtr > (that.value);
        break;

      case 50: // rawascalartype
        value.copy< RawAScalarTypeNodePtr > (that.value);
        break;

      case 62: // s4type
        value.copy< S4TypeNodePtr > (that.value);
        break;

      case 52: // scalartype
        value.copy< ScalarTypeNodePtr > (that.value);
        break;

      case 79: // structtype
        value.copy< StructTypeNodePtr > (that.value);
        break;

      case 58: // symboltype
        value.copy< SymbolTypeNodePtr > (that.value);
        break;

      case 68: // namedtype
        value.copy< TagTypePairNodePtr > (that.value);
        break;

      case 81: // tupletype
        value.copy< TupleTypeNodePtr > (that.value);
        break;

      case 87: // decltype
        value.copy< TypeDeclarationNodePtr > (that.value);
        break;

      case 70: // paramtype
      case 73: // functiontype
      case 75: // nonconnectivetype
      case 83: // uniontype
      case 84: // intersectiontype
      case 85: // nulltype
      case 86: // type
        value.copy< TypeNodePtr > (that.value);
        break;

      case 64: // unknowntype
        value.copy< UnknownTypeNodePtr > (that.value);
        break;

      case 66: // vectortype
        value.copy< VectorTypeNodePtr > (that.value);
        break;

      case 63: // weakreftype
        value.copy< WeakReferenceTypeNodePtr > (that.value);
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
      case 42: // DATAFRAME
      case 43: // STRUCT
      case 44: // ANY
      case 45: // TYPEDECL
      case 46: // IDENTIFIER
      case 47: // QUOTED_IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 49: // ascalartype
        value.move< AScalarTypeNodePtr > (that.value);
        break;

      case 65: // anytype
        value.move< AnyTypeNodePtr > (that.value);
        break;

      case 60: // bytecodetype
        value.move< BytecodeTypeNodePtr > (that.value);
        break;

      case 54: // classtype
        value.move< ClassTypeNodePtr > (that.value);
        break;

      case 78: // dataframetype
        value.move< DataFrameTypeNodePtr > (that.value);
        break;

      case 55: // environmenttype
        value.move< EnvironmentTypeNodePtr > (that.value);
        break;

      case 56: // expressiontype
        value.move< ExpressionTypeNodePtr > (that.value);
        break;

      case 59: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 74: // grouptype
        value.move< GroupTypeNodePtr > (that.value);
        break;

      case 82: // identifier
        value.move< IdentifierNodePtr > (that.value);
        break;

      case 57: // languagetype
        value.move< LanguageTypeNodePtr > (that.value);
        break;

      case 76: // listtype
        value.move< ListTypeNodePtr > (that.value);
        break;

      case 51: // nascalartype
        value.move< NAScalarTypeNodePtr > (that.value);
        break;

      case 53: // classnameseq
      case 67: // typeseq
      case 69: // namedtypeseq
      case 71: // paramtypeseq
      case 72: // params
      case 77: // structelements
      case 80: // tupleelements
        value.move< NodePtr > (that.value);
        break;

      case 61: // pairlisttype
        value.move< PairlistTypeNodePtr > (that.value);
        break;

      case 50: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (that.value);
        break;

      case 62: // s4type
        value.move< S4TypeNodePtr > (that.value);
        break;

      case 52: // scalartype
        value.move< ScalarTypeNodePtr > (that.value);
        break;

      case 79: // structtype
        value.move< StructTypeNodePtr > (that.value);
        break;

      case 58: // symboltype
        value.move< SymbolTypeNodePtr > (that.value);
        break;

      case 68: // namedtype
        value.move< TagTypePairNodePtr > (that.value);
        break;

      case 81: // tupletype
        value.move< TupleTypeNodePtr > (that.value);
        break;

      case 87: // decltype
        value.move< TypeDeclarationNodePtr > (that.value);
        break;

      case 70: // paramtype
      case 73: // functiontype
      case 75: // nonconnectivetype
      case 83: // uniontype
      case 84: // intersectiontype
      case 85: // nulltype
      case 86: // type
        value.move< TypeNodePtr > (that.value);
        break;

      case 64: // unknowntype
        value.move< UnknownTypeNodePtr > (that.value);
        break;

      case 66: // vectortype
        value.move< VectorTypeNodePtr > (that.value);
        break;

      case 63: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (that.value);
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
      case 42: // DATAFRAME
      case 43: // STRUCT
      case 44: // ANY
      case 45: // TYPEDECL
      case 46: // IDENTIFIER
      case 47: // QUOTED_IDENTIFIER
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
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
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
    switch (yytype)
    {
      case 3: // "|"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1664 "Parser.cxx"
        break;

      case 4: // "^"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1670 "Parser.cxx"
        break;

      case 5: // "=>"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1676 "Parser.cxx"
        break;

      case 6: // "&"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1682 "Parser.cxx"
        break;

      case 7: // ","
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1688 "Parser.cxx"
        break;

      case 8: // "(("
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1694 "Parser.cxx"
        break;

      case 9: // "("
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1700 "Parser.cxx"
        break;

      case 10: // "))"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1706 "Parser.cxx"
        break;

      case 11: // ")"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1712 "Parser.cxx"
        break;

      case 12: // "[]"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1718 "Parser.cxx"
        break;

      case 13: // "<"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1724 "Parser.cxx"
        break;

      case 14: // ">"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1730 "Parser.cxx"
        break;

      case 15: // "[["
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1736 "Parser.cxx"
        break;

      case 16: // "]]"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1742 "Parser.cxx"
        break;

      case 17: // "{{"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1748 "Parser.cxx"
        break;

      case 18: // "}}"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1754 "Parser.cxx"
        break;

      case 19: // ";"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1760 "Parser.cxx"
        break;

      case 20: // ":"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1766 "Parser.cxx"
        break;

      case 21: // "..."
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1772 "Parser.cxx"
        break;

      case 22: // "???"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1778 "Parser.cxx"
        break;

      case 23: // "null"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1784 "Parser.cxx"
        break;

      case 24: // "class"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1790 "Parser.cxx"
        break;

      case 25: // INTEGER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1796 "Parser.cxx"
        break;

      case 26: // DOUBLE
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1802 "Parser.cxx"
        break;

      case 27: // COMPLEX
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1808 "Parser.cxx"
        break;

      case 28: // CHARACTER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1814 "Parser.cxx"
        break;

      case 29: // LOGICAL
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1820 "Parser.cxx"
        break;

      case 30: // RAW
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1826 "Parser.cxx"
        break;

      case 31: // ENVIRONMENT
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1832 "Parser.cxx"
        break;

      case 32: // EXPRESSION
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1838 "Parser.cxx"
        break;

      case 33: // LANGUAGE
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1844 "Parser.cxx"
        break;

      case 34: // SYMBOL
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1850 "Parser.cxx"
        break;

      case 35: // EXTERNALPOINTER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1856 "Parser.cxx"
        break;

      case 36: // BYTECODE
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1862 "Parser.cxx"
        break;

      case 37: // PAIRLIST
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1868 "Parser.cxx"
        break;

      case 38: // S4
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1874 "Parser.cxx"
        break;

      case 39: // WEAKREF
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1880 "Parser.cxx"
        break;

      case 40: // TUPLE
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1886 "Parser.cxx"
        break;

      case 41: // LIST
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1892 "Parser.cxx"
        break;

      case 42: // DATAFRAME
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1898 "Parser.cxx"
        break;

      case 43: // STRUCT
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1904 "Parser.cxx"
        break;

      case 44: // ANY
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1910 "Parser.cxx"
        break;

      case 45: // TYPEDECL
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1916 "Parser.cxx"
        break;

      case 46: // IDENTIFIER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1922 "Parser.cxx"
        break;

      case 47: // QUOTED_IDENTIFIER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1928 "Parser.cxx"
        break;

      case 49: // ascalartype
#line 117 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AScalarTypeNodePtr > ()); }
#line 1934 "Parser.cxx"
        break;

      case 50: // rawascalartype
#line 116 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < RawAScalarTypeNodePtr > ()); }
#line 1940 "Parser.cxx"
        break;

      case 51: // nascalartype
#line 118 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NAScalarTypeNodePtr > ()); }
#line 1946 "Parser.cxx"
        break;

      case 52: // scalartype
#line 119 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ScalarTypeNodePtr > ()); }
#line 1952 "Parser.cxx"
        break;

      case 53: // classnameseq
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 1958 "Parser.cxx"
        break;

      case 54: // classtype
#line 120 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ClassTypeNodePtr > ()); }
#line 1964 "Parser.cxx"
        break;

      case 55: // environmenttype
#line 121 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < EnvironmentTypeNodePtr > ()); }
#line 1970 "Parser.cxx"
        break;

      case 56: // expressiontype
#line 122 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExpressionTypeNodePtr > ()); }
#line 1976 "Parser.cxx"
        break;

      case 57: // languagetype
#line 123 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < LanguageTypeNodePtr > ()); }
#line 1982 "Parser.cxx"
        break;

      case 58: // symboltype
#line 124 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < SymbolTypeNodePtr > ()); }
#line 1988 "Parser.cxx"
        break;

      case 59: // externalptrtype
#line 125 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExternalPointerTypeNodePtr > ()); }
#line 1994 "Parser.cxx"
        break;

      case 60: // bytecodetype
#line 126 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < BytecodeTypeNodePtr > ()); }
#line 2000 "Parser.cxx"
        break;

      case 61: // pairlisttype
#line 127 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < PairlistTypeNodePtr > ()); }
#line 2006 "Parser.cxx"
        break;

      case 62: // s4type
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < S4TypeNodePtr > ()); }
#line 2012 "Parser.cxx"
        break;

      case 63: // weakreftype
#line 129 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < WeakReferenceTypeNodePtr > ()); }
#line 2018 "Parser.cxx"
        break;

      case 64: // unknowntype
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < UnknownTypeNodePtr > ()); }
#line 2024 "Parser.cxx"
        break;

      case 65: // anytype
#line 130 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AnyTypeNodePtr > ()); }
#line 2030 "Parser.cxx"
        break;

      case 66: // vectortype
#line 132 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < VectorTypeNodePtr > ()); }
#line 2036 "Parser.cxx"
        break;

      case 67: // typeseq
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2042 "Parser.cxx"
        break;

      case 68: // namedtype
#line 134 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TagTypePairNodePtr > ()); }
#line 2048 "Parser.cxx"
        break;

      case 69: // namedtypeseq
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2054 "Parser.cxx"
        break;

      case 70: // paramtype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2060 "Parser.cxx"
        break;

      case 71: // paramtypeseq
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2066 "Parser.cxx"
        break;

      case 72: // params
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2072 "Parser.cxx"
        break;

      case 73: // functiontype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2078 "Parser.cxx"
        break;

      case 74: // grouptype
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < GroupTypeNodePtr > ()); }
#line 2084 "Parser.cxx"
        break;

      case 75: // nonconnectivetype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2090 "Parser.cxx"
        break;

      case 76: // listtype
#line 136 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ListTypeNodePtr > ()); }
#line 2096 "Parser.cxx"
        break;

      case 77: // structelements
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2102 "Parser.cxx"
        break;

      case 78: // dataframetype
#line 137 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < DataFrameTypeNodePtr > ()); }
#line 2108 "Parser.cxx"
        break;

      case 79: // structtype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < StructTypeNodePtr > ()); }
#line 2114 "Parser.cxx"
        break;

      case 80: // tupleelements
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2120 "Parser.cxx"
        break;

      case 81: // tupletype
#line 139 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TupleTypeNodePtr > ()); }
#line 2126 "Parser.cxx"
        break;

      case 82: // identifier
#line 140 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < IdentifierNodePtr > ()); }
#line 2132 "Parser.cxx"
        break;

      case 83: // uniontype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2138 "Parser.cxx"
        break;

      case 84: // intersectiontype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2144 "Parser.cxx"
        break;

      case 85: // nulltype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2150 "Parser.cxx"
        break;

      case 86: // type
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2156 "Parser.cxx"
        break;

      case 87: // decltype
#line 142 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeDeclarationNodePtr > ()); }
#line 2162 "Parser.cxx"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
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


    // User initialization code.
#line 184 "Parser.yxx"
{
    /* filename for locations here
       https://www.gnu.org/software/bison/manual/html_node/Initial-Action-Decl.html
       location stores pointer to a string allocated elsewhere and does not delete it.
       it has been disabled for now since TopLevelNode stores the filename anyways and
       properly deallocates it.
    */

    /* @$.initialize(context.get_input_stream_name()); */
}

#line 2292 "Parser.cxx"


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
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
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
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
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
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
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
      case 49: // ascalartype
        yylhs.value.emplace< AScalarTypeNodePtr > ();
        break;

      case 65: // anytype
        yylhs.value.emplace< AnyTypeNodePtr > ();
        break;

      case 60: // bytecodetype
        yylhs.value.emplace< BytecodeTypeNodePtr > ();
        break;

      case 54: // classtype
        yylhs.value.emplace< ClassTypeNodePtr > ();
        break;

      case 78: // dataframetype
        yylhs.value.emplace< DataFrameTypeNodePtr > ();
        break;

      case 55: // environmenttype
        yylhs.value.emplace< EnvironmentTypeNodePtr > ();
        break;

      case 56: // expressiontype
        yylhs.value.emplace< ExpressionTypeNodePtr > ();
        break;

      case 59: // externalptrtype
        yylhs.value.emplace< ExternalPointerTypeNodePtr > ();
        break;

      case 74: // grouptype
        yylhs.value.emplace< GroupTypeNodePtr > ();
        break;

      case 82: // identifier
        yylhs.value.emplace< IdentifierNodePtr > ();
        break;

      case 57: // languagetype
        yylhs.value.emplace< LanguageTypeNodePtr > ();
        break;

      case 76: // listtype
        yylhs.value.emplace< ListTypeNodePtr > ();
        break;

      case 51: // nascalartype
        yylhs.value.emplace< NAScalarTypeNodePtr > ();
        break;

      case 53: // classnameseq
      case 67: // typeseq
      case 69: // namedtypeseq
      case 71: // paramtypeseq
      case 72: // params
      case 77: // structelements
      case 80: // tupleelements
        yylhs.value.emplace< NodePtr > ();
        break;

      case 61: // pairlisttype
        yylhs.value.emplace< PairlistTypeNodePtr > ();
        break;

      case 50: // rawascalartype
        yylhs.value.emplace< RawAScalarTypeNodePtr > ();
        break;

      case 62: // s4type
        yylhs.value.emplace< S4TypeNodePtr > ();
        break;

      case 52: // scalartype
        yylhs.value.emplace< ScalarTypeNodePtr > ();
        break;

      case 79: // structtype
        yylhs.value.emplace< StructTypeNodePtr > ();
        break;

      case 58: // symboltype
        yylhs.value.emplace< SymbolTypeNodePtr > ();
        break;

      case 68: // namedtype
        yylhs.value.emplace< TagTypePairNodePtr > ();
        break;

      case 81: // tupletype
        yylhs.value.emplace< TupleTypeNodePtr > ();
        break;

      case 87: // decltype
        yylhs.value.emplace< TypeDeclarationNodePtr > ();
        break;

      case 70: // paramtype
      case 73: // functiontype
      case 75: // nonconnectivetype
      case 83: // uniontype
      case 84: // intersectiontype
      case 85: // nulltype
      case 86: // type
        yylhs.value.emplace< TypeNodePtr > ();
        break;

      case 64: // unknowntype
        yylhs.value.emplace< UnknownTypeNodePtr > ();
        break;

      case 66: // vectortype
        yylhs.value.emplace< VectorTypeNodePtr > ();
        break;

      case 63: // weakreftype
        yylhs.value.emplace< WeakReferenceTypeNodePtr > ();
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
      case 42: // DATAFRAME
      case 43: // STRUCT
      case 44: // ANY
      case 45: // TYPEDECL
      case 46: // IDENTIFIER
      case 47: // QUOTED_IDENTIFIER
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
#line 354 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<IntegerAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2586 "Parser.cxx"
    break;

  case 3:
#line 355 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<DoubleAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2592 "Parser.cxx"
    break;

  case 4:
#line 356 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<ComplexAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2598 "Parser.cxx"
    break;

  case 5:
#line 357 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<CharacterAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2604 "Parser.cxx"
    break;

  case 6:
#line 358 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<LogicalAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2610 "Parser.cxx"
    break;

  case 7:
#line 361 "Parser.yxx"
                                                            {   yylhs.value.as < RawAScalarTypeNodePtr > () = create_node_with_keyword<RawAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2616 "Parser.cxx"
    break;

  case 8:
#line 364 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NAScalarTypeNodePtr > () = new NAScalarTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < AScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < NAScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2627 "Parser.cxx"
    break;

  case 9:
#line 371 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < AScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < AScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2637 "Parser.cxx"
    break;

  case 10:
#line 376 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < RawAScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < RawAScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2647 "Parser.cxx"
    break;

  case 11:
#line 381 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < NAScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < NAScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2657 "Parser.cxx"
    break;

  case 12:
#line 389 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < IdentifierNodePtr > ();
                                                                yystack_[0].value.as < IdentifierNodePtr > () = nullptr;
                                                            }
#line 2666 "Parser.cxx"
    break;

  case 13:
#line 393 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < IdentifierNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2678 "Parser.cxx"
    break;

  case 14:
#line 402 "Parser.yxx"
                                                            {
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);

                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);

                                                                ParameterNode* parameters = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                                              std::move(wrap(std::move(right))),
                                                                                                              std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));
                                                                yylhs.value.as < ClassTypeNodePtr > () = new ClassTypeNode(std::move(wrap(std::move(keyword))),
                                                                                       std::move(wrap(std::move(parameters))));
                                                                yylhs.value.as < ClassTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2696 "Parser.cxx"
    break;

  case 15:
#line 418 "Parser.yxx"
                                                            {   yylhs.value.as < EnvironmentTypeNodePtr > () = create_node_with_keyword<EnvironmentTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2702 "Parser.cxx"
    break;

  case 16:
#line 421 "Parser.yxx"
                                                            {   yylhs.value.as < ExpressionTypeNodePtr > () = create_node_with_keyword<ExpressionTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);  }
#line 2708 "Parser.cxx"
    break;

  case 17:
#line 424 "Parser.yxx"
                                                            {   yylhs.value.as < LanguageTypeNodePtr > () = create_node_with_keyword<LanguageTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);    }
#line 2714 "Parser.cxx"
    break;

  case 18:
#line 427 "Parser.yxx"
                                                            {   yylhs.value.as < SymbolTypeNodePtr > () = create_node_with_keyword<SymbolTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);      }
#line 2720 "Parser.cxx"
    break;

  case 19:
#line 430 "Parser.yxx"
                                                            {   yylhs.value.as < ExternalPointerTypeNodePtr > () = create_node_with_keyword<ExternalPointerTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2726 "Parser.cxx"
    break;

  case 20:
#line 433 "Parser.yxx"
                                                            {   yylhs.value.as < BytecodeTypeNodePtr > () = create_node_with_keyword<BytecodeTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2732 "Parser.cxx"
    break;

  case 21:
#line 436 "Parser.yxx"
                                                            {   yylhs.value.as < PairlistTypeNodePtr > () = create_node_with_keyword<PairlistTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2738 "Parser.cxx"
    break;

  case 22:
#line 439 "Parser.yxx"
                                                            {   yylhs.value.as < S4TypeNodePtr > () = create_node_with_keyword<S4TypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2744 "Parser.cxx"
    break;

  case 23:
#line 442 "Parser.yxx"
                                                            {   yylhs.value.as < WeakReferenceTypeNodePtr > () = create_node_with_keyword<WeakReferenceTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2750 "Parser.cxx"
    break;

  case 24:
#line 445 "Parser.yxx"
                                                            {   yylhs.value.as < DataFrameTypeNodePtr > () = create_node_with_keyword<DataFrameTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2756 "Parser.cxx"
    break;

  case 25:
#line 448 "Parser.yxx"
                                                            {   yylhs.value.as < AnyTypeNodePtr > () = create_node_with_keyword<AnyTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2762 "Parser.cxx"
    break;

  case 26:
#line 451 "Parser.yxx"
                                                            {   yylhs.value.as < UnknownTypeNodePtr > () = create_node_with_keyword<UnknownTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2768 "Parser.cxx"
    break;

  case 27:
#line 454 "Parser.yxx"
                                                            {   yylhs.value.as < TypeNodePtr > () = create_node_with_keyword<NullTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2774 "Parser.cxx"
    break;

  case 28:
#line 457 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                yylhs.value.as < VectorTypeNodePtr > () = new VectorTypeNode(std::move(wrap(std::move(op))),
                                                                                        std::move(wrap(std::move(yystack_[1].value.as < ScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < VectorTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2785 "Parser.cxx"
    break;

  case 29:
#line 465 "Parser.yxx"
                                                            {
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);

                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);

                                                                ParameterNode* parameter = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                                             std::move(wrap(std::move(right))),
                                                                                                             std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));

                                                                yylhs.value.as < ListTypeNodePtr > () = new ListTypeNode(std::move(wrap(std::move(keyword))),
                                                                                      std::move(wrap(std::move(parameter))));

                                                                yylhs.value.as < ListTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2805 "Parser.cxx"
    break;

  case 30:
#line 482 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 2814 "Parser.cxx"
    break;

  case 31:
#line 486 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2826 "Parser.cxx"
    break;

  case 32:
#line 496 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = new EmptyNode();
                                                            }
#line 2834 "Parser.cxx"
    break;

  case 33:
#line 499 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < NodePtr > ();
                                                                yystack_[0].value.as < NodePtr > () = nullptr;
                                                            }
#line 2843 "Parser.cxx"
    break;

  case 34:
#line 504 "Parser.yxx"
                                                            {
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);

                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);

                                                                ParameterNode* parameter = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                                             std::move(wrap(std::move(right))),
                                                                                                             std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));

                                                                yylhs.value.as < StructTypeNodePtr > () = new StructTypeNode(std::move(wrap(std::move(keyword))),
                                                                                        std::move(wrap(std::move(parameter))));

                                                                yylhs.value.as < StructTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2863 "Parser.cxx"
    break;

  case 35:
#line 522 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = new EmptyNode();
                                                            }
#line 2871 "Parser.cxx"
    break;

  case 36:
#line 525 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < NodePtr > ();
                                                                yystack_[0].value.as < NodePtr > () = nullptr;
                                                            }
#line 2880 "Parser.cxx"
    break;

  case 37:
#line 531 "Parser.yxx"
                                                            {
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);

                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);

                                                                ParameterNode* parameter = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                                             std::move(wrap(std::move(right))),
                                                                                                             std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));

                                                                yylhs.value.as < TupleTypeNodePtr > () = new TupleTypeNode(std::move(wrap(std::move(keyword))),
                                                                                       std::move(wrap(std::move(parameter))));

                                                                yylhs.value.as < TupleTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2900 "Parser.cxx"
    break;

  case 38:
#line 548 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2906 "Parser.cxx"
    break;

  case 39:
#line 549 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2912 "Parser.cxx"
    break;

  case 40:
#line 550 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2918 "Parser.cxx"
    break;

  case 41:
#line 551 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2924 "Parser.cxx"
    break;

  case 42:
#line 552 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2930 "Parser.cxx"
    break;

  case 43:
#line 553 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2936 "Parser.cxx"
    break;

  case 44:
#line 554 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2942 "Parser.cxx"
    break;

  case 45:
#line 555 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2948 "Parser.cxx"
    break;

  case 46:
#line 556 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2954 "Parser.cxx"
    break;

  case 47:
#line 557 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2960 "Parser.cxx"
    break;

  case 48:
#line 558 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2966 "Parser.cxx"
    break;

  case 49:
#line 559 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2972 "Parser.cxx"
    break;

  case 50:
#line 560 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2978 "Parser.cxx"
    break;

  case 51:
#line 561 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2984 "Parser.cxx"
    break;

  case 52:
#line 562 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2990 "Parser.cxx"
    break;

  case 53:
#line 563 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2996 "Parser.cxx"
    break;

  case 54:
#line 564 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 3002 "Parser.cxx"
    break;

  case 55:
#line 565 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 3008 "Parser.cxx"
    break;

  case 56:
#line 566 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 3014 "Parser.cxx"
    break;

  case 57:
#line 567 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 3020 "Parser.cxx"
    break;

  case 58:
#line 568 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 3026 "Parser.cxx"
    break;

  case 59:
#line 569 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 3032 "Parser.cxx"
    break;

  case 60:
#line 570 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 3038 "Parser.cxx"
    break;

  case 61:
#line 571 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 3044 "Parser.cxx"
    break;

  case 62:
#line 572 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), true, false, yystack_[0].location, context);  }
#line 3050 "Parser.cxx"
    break;

  case 63:
#line 575 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr separator = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))),
                                                                                         std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))),
                                                                                         std::move(wrap(std::move(separator))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3062 "Parser.cxx"
    break;

  case 64:
#line 582 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr separator = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                IdentifierNodePtr id = create_identifier(yystack_[2].value.as < std::string > (), false, true, yystack_[2].location, context);
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(id))),
                                                                                         std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))),
                                                                                         std::move(wrap(std::move(separator))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3075 "Parser.cxx"
    break;

  case 65:
#line 592 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TagTypePairNodePtr > ();
                                                                yystack_[0].value.as < TagTypePairNodePtr > () = nullptr;
                                                            }
#line 3084 "Parser.cxx"
    break;

  case 66:
#line 596 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3096 "Parser.cxx"
    break;

  case 67:
#line 606 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 3105 "Parser.cxx"
    break;

  case 68:
#line 610 "Parser.yxx"
                                                            {   yylhs.value.as < TypeNodePtr > () = create_node_with_keyword<VarargTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 3111 "Parser.cxx"
    break;

  case 69:
#line 613 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 3120 "Parser.cxx"
    break;

  case 70:
#line 617 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3132 "Parser.cxx"
    break;

  case 71:
#line 626 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                yylhs.value.as < NodePtr > () = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3145 "Parser.cxx"
    break;

  case 72:
#line 634 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(new EmptyNode())));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3158 "Parser.cxx"
    break;

  case 73:
#line 642 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                            }
#line 3167 "Parser.cxx"
    break;

  case 74:
#line 649 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                yylhs.value.as < GroupTypeNodePtr > () = new GroupTypeNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < GroupTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3180 "Parser.cxx"
    break;

  case 75:
#line 660 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < ScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3190 "Parser.cxx"
    break;

  case 76:
#line 665 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ClassTypeNodePtr > ();
                                                                yystack_[0].value.as < ClassTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3200 "Parser.cxx"
    break;

  case 77:
#line 670 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < EnvironmentTypeNodePtr > ();
                                                                yystack_[0].value.as < EnvironmentTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3210 "Parser.cxx"
    break;

  case 78:
#line 675 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExpressionTypeNodePtr > ();
                                                                yystack_[0].value.as < ExpressionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3220 "Parser.cxx"
    break;

  case 79:
#line 680 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < LanguageTypeNodePtr > ();
                                                                yystack_[0].value.as < LanguageTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3230 "Parser.cxx"
    break;

  case 80:
#line 685 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < SymbolTypeNodePtr > ();
                                                                yystack_[0].value.as < SymbolTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3240 "Parser.cxx"
    break;

  case 81:
#line 690 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExternalPointerTypeNodePtr > ();
                                                                yystack_[0].value.as < ExternalPointerTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3250 "Parser.cxx"
    break;

  case 82:
#line 695 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < BytecodeTypeNodePtr > ();
                                                                yystack_[0].value.as < BytecodeTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3260 "Parser.cxx"
    break;

  case 83:
#line 700 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < PairlistTypeNodePtr > ();
                                                                yystack_[0].value.as < PairlistTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3270 "Parser.cxx"
    break;

  case 84:
#line 705 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < S4TypeNodePtr > ();
                                                                yystack_[0].value.as < S4TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3280 "Parser.cxx"
    break;

  case 85:
#line 710 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < WeakReferenceTypeNodePtr > ();
                                                                yystack_[0].value.as < WeakReferenceTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3290 "Parser.cxx"
    break;

  case 86:
#line 715 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < DataFrameTypeNodePtr > ();
                                                                yystack_[0].value.as < DataFrameTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3300 "Parser.cxx"
    break;

  case 87:
#line 720 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < VectorTypeNodePtr > ();
                                                                yystack_[0].value.as < VectorTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3310 "Parser.cxx"
    break;

  case 88:
#line 725 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < StructTypeNodePtr > ();
                                                                yystack_[0].value.as < StructTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3320 "Parser.cxx"
    break;

  case 89:
#line 730 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ListTypeNodePtr > ();
                                                                yystack_[0].value.as < ListTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3330 "Parser.cxx"
    break;

  case 90:
#line 735 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TupleTypeNodePtr > ();
                                                                yystack_[0].value.as < TupleTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3340 "Parser.cxx"
    break;

  case 91:
#line 740 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < GroupTypeNodePtr > ();
                                                                yystack_[0].value.as < GroupTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3350 "Parser.cxx"
    break;

  case 92:
#line 745 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < UnknownTypeNodePtr > ();
                                                                yystack_[0].value.as < UnknownTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3360 "Parser.cxx"
    break;

  case 93:
#line 750 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3370 "Parser.cxx"
    break;

  case 94:
#line 758 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3380 "Parser.cxx"
    break;

  case 95:
#line 764 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new IntersectionTypeNode(std::move(wrap(std::move(op))),
                                                                                              std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))),
                                                                                              std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3392 "Parser.cxx"
    break;

  case 96:
#line 773 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3402 "Parser.cxx"
    break;

  case 97:
#line 779 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3414 "Parser.cxx"
    break;

  case 98:
#line 786 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < AnyTypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3426 "Parser.cxx"
    break;

  case 99:
#line 795 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3436 "Parser.cxx"
    break;

  case 100:
#line 801 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new UnionTypeNode(std::move(wrap(std::move(op))),
                                                                                       std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))),
                                                                                       std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3448 "Parser.cxx"
    break;

  case 101:
#line 810 "Parser.yxx"
                                                                {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3458 "Parser.cxx"
    break;

  case 102:
#line 815 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3468 "Parser.cxx"
    break;

  case 103:
#line 822 "Parser.yxx"
                                                            {
                                                                TerminatorNodePtr terminator = create_terminator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);
                                                                yylhs.value.as < TypeDeclarationNodePtr > () = new TypeDeclarationNode(std::move(wrap(std::move(keyword))),
                                                                                             std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))),
                                                                                             std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))),
                                                                                             std::move(wrap(std::move(terminator))));
                                                                yylhs.value.as < TypeDeclarationNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3482 "Parser.cxx"
    break;

  case 104:
#line 833 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3491 "Parser.cxx"
    break;

  case 105:
#line 837 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3500 "Parser.cxx"
    break;

  case 106:
#line 843 "Parser.yxx"
                                                            {
                                                                EofNodeUPtr eof = std::make_unique<EofNode>();
                                                                eof -> set_location(yystack_[0].location);
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> set_location(yylhs.location);
                                                                node -> set_eof_node(eof);
                                                            }
#line 3512 "Parser.cxx"
    break;

  case 107:
#line 850 "Parser.yxx"
                                                            {
                                                                EofNodeUPtr eof = std::make_unique<EofNode>();
                                                                eof -> set_location(yystack_[0].location);
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> set_location(yylhs.location);
                                                                node -> set_eof_node(eof);
                                                            }
#line 3524 "Parser.cxx"
    break;


#line 3528 "Parser.cxx"

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
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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
      error_token.state = state_type (yyn);
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
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
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
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
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
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
    std::ptrdiff_t yyi = 0;
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


  const signed char Parser::yypact_ninf_ = -87;

  const signed char Parser::yytable_ninf_ = -74;

  const short
  Parser::yypact_[] =
  {
       2,   -87,   210,   -87,     3,     5,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   146,   -87,   -87,   -87,    38,   146,     0,   -87,   -87,
      -6,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,    -3,    -1,   -87,    32,
     -87,   -87,   -87,   -87,    34,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,    44,   -87,    45,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,    48,    46,   -87,    35,
     -87,    50,   -87,   -87,   -87,     1,   -87,   210,   146,   146,
     102,   -87,   146,   146,   187,   -87,   -87,    49,   -87,     4,
     -87,    52,    41,   -87,    42,    37,   -87,    53,    80,    76,
      44,   -87,   -87,   -87,   -87,   -87,   210,   -87,   146,   -87,
     -87,   146,   102,   -87,   146,   -87,   -87,   -87,   -87,   -87
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,   106,     0,   104,     0,     0,    60,    58,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    56,    55,    57,    59,    61,
      62,     0,   107,   105,     1,     0,     0,     0,    26,    27,
       0,     2,     3,     4,     5,     6,     7,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,    24,     0,
      25,     9,    10,    11,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    92,   102,    87,     0,    99,
      91,    94,    89,    86,    88,    90,   101,    96,    93,     0,
       8,     0,    72,    68,    69,     0,    67,     0,    35,     0,
      32,    28,     0,     0,     0,   103,    74,     0,    71,     0,
      12,    36,     0,    30,     0,     0,    65,    33,     0,     0,
      98,    97,    73,   100,    95,    70,     0,    14,     0,    37,
      29,     0,     0,    34,     0,    13,    31,    64,    66,    63
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -87,    62,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -86,   -87,   -87,
     -33,   -87,    -7,   -87,   -87,   -83,   -87,     6,   -87,   -87,
     -87,   -87,   -87,   -87,    -2,   -87,   -87,   -87,   -30,    98,
     -87,   -87
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    61,    62,    63,    64,   109,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   111,
     116,   117,    94,    95,    78,    79,    80,    81,    82,   118,
      83,    84,   112,    85,   119,    86,    87,    88,    96,     3,
       4,     5
  };

  const short
  Parser::yytable_[] =
  {
      31,    89,     1,    32,    35,    34,    91,    97,   107,    36,
      98,   126,    99,    37,    92,   108,   120,   122,   127,   121,
     123,    93,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   100,   101,     2,     2,   -73,
     102,   103,   104,    35,   105,   129,   130,   131,    36,   128,
     132,   106,    37,    41,    42,    43,    44,    45,   113,   114,
      93,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   133,   110,   134,    90,   136,   138,
     125,   137,    33,     0,   139,     0,   115,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,   135,     7,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      35,     0,     0,     0,     0,    36,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    35,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     6,     0,     7,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30
  };

  const short
  Parser::yycheck_[] =
  {
       2,    31,     0,     0,     4,     0,    36,    13,     7,     9,
      13,     7,    13,    13,    14,    14,   102,   103,    14,   102,
     103,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    13,    12,    45,    45,     5,
       5,     3,     6,     4,    19,    14,    14,    20,     9,     7,
       7,    11,    13,    25,    26,    27,    28,    29,    98,    99,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    14,    97,    20,    35,   128,   132,
     107,   131,     4,    -1,   134,    -1,     4,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,   126,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       4,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     4,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    21,    -1,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     0,    45,    87,    88,    89,    21,    23,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    82,     0,    87,     0,     4,     9,    13,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    49,    50,    51,    52,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    72,    73,
      74,    75,    76,    78,    79,    81,    83,    84,    85,    86,
      49,    86,    14,    21,    70,    71,    86,    13,    13,    13,
      13,    12,     5,     3,     6,    19,    11,     7,    14,    53,
      82,    67,    80,    86,    86,     4,    68,    69,    77,    82,
      65,    73,    65,    73,    75,    70,     7,    14,     7,    14,
      14,    20,     7,    14,    20,    82,    86,    86,    68,    86
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    48,    49,    49,    49,    49,    49,    50,    51,    52,
      52,    52,    53,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    78,    65,    64,    85,    66,    76,
      67,    67,    77,    77,    79,    80,    80,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    84,    84,    73,    73,    73,    83,
      83,    86,    86,    87,    88,    88,    89,    89
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     3,     0,     1,     4,     0,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     1,     1,     1,
       3,     3,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     3,     1,
       3,     1,     1,     4,     1,     2,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"|\"", "\"^\"", "\"=>\"",
  "\"&\"", "\",\"", "\"((\"", "\"(\"", "\"))\"", "\")\"", "\"[]\"",
  "\"<\"", "\">\"", "\"[[\"", "\"]]\"", "\"{{\"", "\"}}\"", "\";\"",
  "\":\"", "\"...\"", "\"???\"", "\"null\"", "\"class\"", "INTEGER",
  "DOUBLE", "COMPLEX", "CHARACTER", "LOGICAL", "RAW", "ENVIRONMENT",
  "EXPRESSION", "LANGUAGE", "SYMBOL", "EXTERNALPOINTER", "BYTECODE",
  "PAIRLIST", "S4", "WEAKREF", "TUPLE", "LIST", "DATAFRAME", "STRUCT",
  "ANY", "TYPEDECL", "IDENTIFIER", "QUOTED_IDENTIFIER", "$accept",
  "ascalartype", "rawascalartype", "nascalartype", "scalartype",
  "classnameseq", "classtype", "environmenttype", "expressiontype",
  "languagetype", "symboltype", "externalptrtype", "bytecodetype",
  "pairlisttype", "s4type", "weakreftype", "unknowntype", "anytype",
  "vectortype", "typeseq", "namedtype", "namedtypeseq", "paramtype",
  "paramtypeseq", "params", "functiontype", "grouptype",
  "nonconnectivetype", "listtype", "structelements", "dataframetype",
  "structtype", "tupleelements", "tupletype", "identifier", "uniontype",
  "intersectiontype", "nulltype", "type", "decltype", "decllist", "start", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   354,   354,   355,   356,   357,   358,   361,   364,   371,
     376,   381,   389,   393,   402,   418,   421,   424,   427,   430,
     433,   436,   439,   442,   445,   448,   451,   454,   457,   465,
     482,   486,   496,   499,   504,   522,   525,   531,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   575,   582,   592,   596,   606,   610,   613,
     617,   626,   634,   642,   649,   660,   665,   670,   675,   680,
     685,   690,   695,   700,   705,   710,   715,   720,   725,   730,
     735,   740,   745,   750,   758,   764,   773,   779,   786,   795,
     801,   810,   815,   822,   833,   837,   843,   850
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
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

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
    };
    const int user_token_number_max_ = 302;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 9 "Parser.yxx"
} } // tastr::parser
#line 4099 "Parser.cxx"

#line 859 "Parser.yxx"


void tastr::parser::Parser::error(const location_type& location, const std::string& message) {
    context.get_parse_result().set_error(location, message);
}
