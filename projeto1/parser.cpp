/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include "ast.h"
#include <iostream>
#include "structures.h"
#include <string>
	
	AST::Block *programRoot; /* the root node of our program AST:: */
	Structures::SymbolTable* simbolTable = new Structures::SymbolTable(); /*The simble table of the program*/
	std::string* ultimoId = nullptr;
	Structures::FuncParams* ultimoParam = nullptr;
	
	extern int yylex();
	extern void yyerror(const char *s, ...);





#line 85 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 20 "parser.y" /* yacc.c:355  */

#include "structures.h"
	

#line 120 "parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_ID = 258,
    T_INT = 259,
    T_DOUBLE = 260,
    T_TRUE = 261,
    T_FALSE = 262,
    T_PLUS = 263,
    T_MULT = 264,
    T_NL = 265,
    T_ATRIB = 266,
    T_MINUS = 267,
    T_DIV = 268,
    T_IGUAL = 269,
    T_DIFERENTE = 270,
    T_MAIOR = 271,
    T_MENOR = 272,
    T_MAIOR_IGUAL = 273,
    T_MENOR_IGUAL = 274,
    T_NOT = 275,
    T_PAREN_L = 276,
    T_PAREN_R = 277,
    T_AND = 278,
    T_OR = 279,
    T_COLCH_L = 280,
    T_COLCH_R = 281,
    T_POINT = 282,
    T_TINT = 283,
    T_TDOUBLE = 284,
    T_TBOOL = 285,
    T_WHILE = 286,
    T_END = 287,
    T_DO = 288,
    T_IF = 289,
    T_THEN = 290,
    T_ELSE = 291,
    T_DEF = 292,
    T_TYPE = 293,
    T_VIRGULA = 294,
    T_DECL = 295,
    T_FUNC = 296,
    T_RETURN = 297,
    T_FUNCDECL = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "parser.y" /* yacc.c:355  */

	char* identifier;
	int integer;
	double ddouble;
	AST::Node *node;
	AST::Block *block;
	AST::Operation operation;
	bool boolean;
	Structures::Types type;
	Structures::SymbolTable* scope;
	Structures::FuncParams* funcParams;


#line 190 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 207 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   440

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    88,    89,    93,    94,    95,    96,    97,
     102,   107,   111,   115,   132,   133,   138,   139,   140,   145,
     146,   147,   150,   160,   163,   166,   172,   173,   174,   177,
     184,   192,   195,   205,   206,   211,   212,   213,   214,   220,
     221,   222,   223,   227,   228,   232,   233,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   252,   253,   258,
     259,   260,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ID", "T_INT", "T_DOUBLE", "T_TRUE",
  "T_FALSE", "T_PLUS", "T_MULT", "T_NL", "T_ATRIB", "T_MINUS", "T_DIV",
  "T_IGUAL", "T_DIFERENTE", "T_MAIOR", "T_MENOR", "T_MAIOR_IGUAL",
  "T_MENOR_IGUAL", "T_NOT", "T_PAREN_L", "T_PAREN_R", "T_AND", "T_OR",
  "T_COLCH_L", "T_COLCH_R", "T_POINT", "T_TINT", "T_TDOUBLE", "T_TBOOL",
  "T_WHILE", "T_END", "T_DO", "T_IF", "T_THEN", "T_ELSE", "T_DEF",
  "T_TYPE", "T_VIRGULA", "T_DECL", "T_FUNC", "T_RETURN", "T_FUNCDECL",
  "$accept", "program", "lines", "line", "declFunc", "defFunc", "idFunc",
  "fnewScope", "funclines", "paramList", "cmd", "conds", "newscope",
  "enewscope", "killscope", "killcscope", "componentDecl", "decl", "expr",
  "varAr", "var", "value", "unOp", "type", "op", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      68,    89,  -135,  -135,  -135,  -135,   400,   400,   -24,   -14,
      72,    68,  -135,  -135,  -135,  -135,    27,   400,   410,    80,
      98,    34,  -135,  -135,  -135,  -135,   400,   400,   400,   236,
    -135,  -135,   212,    69,   126,   126,  -135,  -135,   108,    98,
     283,    87,    91,    79,  -135,    12,   420,   112,   118,   156,
     302,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,   400,  -135,   115,    93,    81,
    -135,   103,   122,    14,  -135,   109,     1,   400,   420,  -135,
     135,   132,   127,  -135,    68,   184,    68,  -135,  -135,   157,
     158,   119,  -135,   159,   400,   164,   321,   150,  -135,   154,
     420,    13,     3,   117,   140,  -135,   162,   163,   159,  -135,
      15,   340,   175,  -135,   176,   187,   169,  -135,  -135,  -135,
      55,    78,  -135,  -135,   126,   126,    50,  -135,   201,  -135,
     400,   400,  -135,  -135,   174,   177,    68,   205,  -135,  -135,
      46,   172,    64,  -135,  -135,   359,   378,  -135,  -135,    45,
      87,   178,    35,   126,   211,   208,  -135,  -135,  -135,  -135,
      35,  -135,   182,  -135,  -135,   189,   190,  -135,   230,  -135,
     400,  -135,   262
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     5,    60,    59,    61,     0,     0,     0,     0,
       0,     2,     3,     6,    20,    19,     0,     0,     0,     0,
       0,    52,    47,    48,    49,    50,     0,     0,     0,     0,
      39,    51,     0,     0,     0,     0,     1,     4,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,    42,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    29,     0,    29,     0,     0,     0,
       8,     0,     0,     0,    21,     0,     0,     0,     0,    37,
       0,     0,    54,    40,     0,     0,     0,    29,    31,     0,
       0,     0,    35,     0,     0,     0,     0,     0,    46,    53,
       0,     0,     0,     0,     0,    12,     0,     0,     0,    43,
       0,     0,     0,    24,     0,     0,     0,    31,    31,    30,
       0,     0,    33,     9,    16,    16,     0,    38,     0,    23,
       0,     0,    56,    55,     0,     0,     0,     0,    32,    34,
       0,     0,     0,    36,    44,     0,     0,    26,    27,     0,
       0,     0,     0,     0,     0,     0,    22,    25,    31,     7,
      13,    14,     0,    17,    10,     0,     0,    15,     0,    28,
       0,    18,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   -79,   -10,  -135,  -135,  -135,  -135,  -135,   113,
    -134,  -135,   -51,  -135,  -109,  -135,  -135,   -92,    -7,   131,
     195,   -16,  -135,   -31,  -135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    70,    68,   106,   166,   160,   140,
      13,    14,    84,   136,   104,   151,   121,    15,    29,   110,
      45,    30,    31,    16,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    37,    42,    69,    71,   101,     1,   102,   134,   135,
      40,   122,    94,     2,    33,    86,     1,    34,   161,    48,
      49,    50,    79,     2,    92,   127,   167,    35,    95,   139,
      81,     3,     4,     5,     6,   118,   103,     7,     1,   119,
       8,     3,     4,     5,     6,   117,     9,     7,     1,   165,
       8,    80,    38,    80,   128,     2,     9,   149,    85,    46,
     143,    47,    97,     3,     4,     5,     6,    39,   152,     7,
      96,     1,    36,     3,     4,     5,     6,   158,     2,     7,
     137,   120,     8,    43,   116,   153,   155,   111,     9,   128,
      77,    37,    37,   141,   141,    20,     3,     4,     5,     6,
      17,    44,     7,   153,    78,     8,     3,     4,     5,    67,
     138,     9,    72,    75,    18,    82,    19,    76,    87,    51,
     120,    89,   162,   145,   146,    88,    52,    53,   -57,    20,
      54,    55,    56,    57,    58,    59,    60,    61,    98,    37,
     -57,    62,    63,    90,   -57,     3,     4,     5,    91,    93,
     -57,   -57,   100,   -57,     3,     4,     5,    51,    99,   108,
     105,   107,   109,   172,    52,    53,   -58,   112,    54,    55,
      56,    57,    58,    59,    60,    61,   114,   123,   -58,    62,
      63,   115,   -58,   124,   125,    51,   130,   131,   -58,   -58,
     132,   -58,    52,    53,   -41,   133,    54,    55,    56,    57,
      58,    59,    60,    61,   144,   147,   -41,    62,    63,   150,
     -41,   148,   154,    51,   163,   159,   -41,   -41,   164,   -41,
      52,    53,   168,   169,    54,    55,    56,    57,    58,    59,
      60,    61,   170,   171,    73,    62,    63,    51,   142,   126,
       0,     0,     0,     0,    52,    53,     0,    66,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
      63,     0,     0,    51,     0,     0,     0,     0,     0,    64,
      52,    53,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,    51,    62,    63,     0,     0,     0,
       0,    52,    53,    74,   -11,    54,    55,    56,    57,    58,
      59,    60,    61,    51,     0,     0,    62,    63,     0,     0,
      52,    53,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    51,     0,    83,    62,    63,     0,     0,    52,
      53,   113,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    51,     0,     0,    62,    63,     0,     0,    52,    53,
     129,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      51,     0,     0,    62,    63,     0,     0,    52,    53,   156,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    51,
       0,     0,    62,    63,     0,     0,    52,    53,   157,     0,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    62,    63,    21,    22,    23,    24,    25,     0,     0,
       0,     0,    26,    21,    41,    23,    24,    25,     0,     0,
      27,    28,    26,    21,    22,    23,    24,    25,     0,     0,
      27,     0,    26,     0,     0,     0,     0,     0,     0,     0,
      27
};

static const yytype_int16 yycheck[] =
{
       7,    11,    18,    34,    35,    84,     3,    86,   117,   118,
      17,   103,    11,    10,    38,    66,     3,    41,   152,    26,
      27,    28,    10,    10,    10,    10,   160,    41,    27,   121,
      46,    28,    29,    30,    31,    32,    87,    34,     3,    36,
      37,    28,    29,    30,    31,    32,    43,    34,     3,   158,
      37,    39,    25,    39,    39,    10,    43,   136,    65,    25,
      10,    27,    78,    28,    29,    30,    31,    40,    22,    34,
      77,     3,     0,    28,    29,    30,    31,    32,    10,    34,
      25,     3,    37,     3,   100,    39,    22,    94,    43,    39,
      11,   101,   102,   124,   125,    40,    28,    29,    30,    31,
      11,     3,    34,    39,    25,    37,    28,    29,    30,    40,
      32,    43,     4,    26,    25,     3,    27,    26,     3,     1,
       3,    40,   153,   130,   131,    32,     8,     9,    10,    40,
      12,    13,    14,    15,    16,    17,    18,    19,     3,   149,
      22,    23,    24,    40,    26,    28,    29,    30,    26,    40,
      32,    33,    25,    35,    28,    29,    30,     1,    26,    40,
       3,     3,     3,   170,     8,     9,    10,     3,    12,    13,
      14,    15,    16,    17,    18,    19,    26,    37,    22,    23,
      24,    27,    26,    21,    21,     1,    11,    11,    32,    33,
       3,    35,     8,     9,    10,    26,    12,    13,    14,    15,
      16,    17,    18,    19,     3,    31,    22,    23,    24,     4,
      26,    34,    40,     1,     3,    37,    32,    33,    10,    35,
       8,     9,    40,    34,    12,    13,    14,    15,    16,    17,
      18,    19,    42,     3,    39,    23,    24,     1,   125,   108,
      -1,    -1,    -1,    -1,     8,     9,    -1,    35,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    33,
       8,     9,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,     1,    23,    24,    -1,    -1,    -1,
      -1,     8,     9,    10,    32,    12,    13,    14,    15,    16,
      17,    18,    19,     1,    -1,    -1,    23,    24,    -1,    -1,
       8,     9,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,     1,    -1,    22,    23,    24,    -1,    -1,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,     1,    -1,    -1,    23,    24,    -1,    -1,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
       1,    -1,    -1,    23,    24,    -1,    -1,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,     1,
      -1,    -1,    23,    24,    -1,    -1,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    23,    24,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,     3,     4,     5,     6,     7,    -1,    -1,
      20,    21,    12,     3,     4,     5,     6,     7,    -1,    -1,
      20,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    28,    29,    30,    31,    34,    37,    43,
      45,    46,    47,    54,    55,    61,    67,    11,    25,    27,
      40,     3,     4,     5,     6,     7,    12,    20,    21,    62,
      65,    66,    62,    38,    41,    41,     0,    47,    25,    40,
      62,     4,    65,     3,     3,    64,    25,    27,    62,    62,
      62,     1,     8,     9,    12,    13,    14,    15,    16,    17,
      18,    19,    23,    24,    33,    68,    35,    40,    49,    67,
      48,    67,     4,    64,    10,    26,    26,    11,    25,    10,
      39,    65,     3,    22,    56,    62,    56,     3,    32,    40,
      40,    26,    10,    40,    11,    27,    62,    65,     3,    26,
      25,    46,    46,    56,    58,     3,    50,     3,    40,     3,
      63,    62,     3,    10,    26,    27,    65,    32,    32,    36,
       3,    60,    61,    37,    21,    21,    63,    10,    39,    10,
      11,    11,     3,    26,    58,    58,    57,    25,    32,    61,
      53,    67,    53,    10,     3,    62,    62,    31,    34,    46,
       4,    59,    22,    39,    40,    22,    10,    10,    32,    37,
      52,    54,    67,     3,    10,    58,    51,    54,    40,    34,
      42,     3,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      48,    49,    50,    51,    52,    52,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    56,
      57,    58,    59,    60,    60,    61,    61,    61,    61,    62,
      62,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     9,     3,     6,
       7,    10,     1,     0,     1,     2,     0,     3,     5,     1,
       1,     4,     9,     7,     6,     9,     8,     8,    11,     0,
       0,     0,     0,     1,     2,     4,     7,     4,     7,     1,
       3,     3,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     3,     6,     6,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 83 "parser.y" /* yacc.c:1646  */
    { programRoot = (yyvsp[0].block); }
#line 1453 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "parser.y" /* yacc.c:1646  */
    { (yyval.block) = new AST::Block(); (yyval.block)->lines.push_back((yyvsp[0].node)); }
#line 1459 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[0].node) != NULL) (yyvsp[-1].block)->lines.push_back((yyvsp[0].node)); }
#line 1465 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1471 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1477 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = simbolTable->insertCompound((yyvsp[-5].identifier),(yyvsp[-1].scope),(yyvsp[-3].block));}
#line 1483 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); /*std::cout << "[byson]Declaracao de funcao" <<std::endl;*/}
#line 1489 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-3].node); std::cout << "[byson]Definicao de funcao" <<std::endl;}
#line 1495 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = simbolTable->insertFunction( (yyvsp[-4].identifier), (yyvsp[-2].funcParams), (yyvsp[-6].type) );}
#line 1501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = simbolTable->pai->assignFunction((yyvsp[-7].identifier),(yyvsp[-3].block),(yyvsp[-5].funcParams));}
#line 1507 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.identifier) = (yyvsp[0].identifier); ultimoId = new std::string((yyvsp[0].identifier));}
#line 1513 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "parser.y" /* yacc.c:1646  */
    {
	Structures::SymbolTable* newScope = new Structures::SymbolTable;
	newScope->updatePai(simbolTable);
//	AST::Variable * astParams = Structures::FuncParams::convertParams(ultimoParam);
	while (ultimoParam != nullptr){
		newScope->insertId( ultimoParam->nome,nullptr, ultimoParam->tipo,false);
		newScope->assignVariable(ultimoParam->nome);
		ultimoParam = ultimoParam->proximo;
	}
	simbolTable = newScope;
}
#line 1529 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.block) = new AST::Block; (yyval.block)->lines.push_back((yyvsp[0].node));}
#line 1535 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 133 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].node) != NULL) (yyvsp[-1].block)->lines.push_back((yyvsp[0].node));}
#line 1541 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.funcParams) = nullptr; ultimoParam = (yyval.funcParams);}
#line 1547 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.funcParams) = new Structures::FuncParams((yyvsp[-2].type),(yyvsp[0].identifier)); ultimoParam = (yyval.funcParams);}
#line 1553 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.funcParams) = new Structures::FuncParams((yyvsp[-2].type),(yyvsp[0].identifier),(yyvsp[-4].funcParams)); ultimoParam = (yyval.funcParams);}
#line 1559 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1565 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1571 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 147 "parser.y" /* yacc.c:1646  */
    {AST::Node* node = simbolTable->assignVariable((yyvsp[-3].identifier));
								(yyval.node) = new AST::BinOp(node,AST::oassign,(yyvsp[-1].node)); }
#line 1578 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "parser.y" /* yacc.c:1646  */
    {
	
	//===============POR ALGUM MOTIVO N ESTÁ FUNCIONANDO ESSA REGRA

	std::cout << "entrou na regra bugada" << std::endl;
	//$$= new AST::Node();
	AST::Node* node = simbolTable->assignVariable((yyvsp[-8].identifier),(yyvsp[-6].node),(yyvsp[-3].identifier));
	(yyval.node) = new AST::BinOp(node,AST::oassign,(yyvsp[-1].node));
}
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 160 "parser.y" /* yacc.c:1646  */
    {AST::Node* node = simbolTable->assignVariable((yyvsp[-6].identifier),(yyvsp[-4].node));
								(yyval.node) = new AST::BinOp(node,AST::oassign,(yyvsp[-1].node)); }
#line 1599 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 163 "parser.y" /* yacc.c:1646  */
    {AST::Node* node = simbolTable->assignVariable((yyvsp[-5].identifier),(yyvsp[-3].identifier));
								(yyval.node) = new AST::BinOp(node,AST::oassign,(yyvsp[-1].node));}
#line 1606 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 166 "parser.y" /* yacc.c:1646  */
    {AST::Node* node = simbolTable->assignVariable((yyvsp[-8].identifier),(yyvsp[-6].identifier),(yyvsp[-4].node));
								(yyval.node) = new AST::BinOp(node,AST::oassign,(yyvsp[-1].node));}
#line 1613 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AST::Loop((yyvsp[-6].node),(yyvsp[-3].block));}
#line 1619 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AST::Conditional((yyvsp[-6].node), (yyvsp[-3].block),NULL);}
#line 1625 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AST::Conditional((yyvsp[-9].node), (yyvsp[-6].block), (yyvsp[-3].block));}
#line 1631 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 177 "parser.y" /* yacc.c:1646  */
    {Structures::SymbolTable* newScope = new Structures::SymbolTable;

	   newScope->updatePai(simbolTable);

	   simbolTable = newScope;	  
	}
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 184 "parser.y" /* yacc.c:1646  */
    {Structures::SymbolTable* escopoPai = simbolTable->pai;

	    Structures::SymbolTable* newScope = new Structures::SymbolTable;
	    newScope->updatePai(escopoPai);
	    simbolTable = newScope;    

	    }
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 192 "parser.y" /* yacc.c:1646  */
    {Structures::SymbolTable* escopoPai = simbolTable->pai;
	   simbolTable = escopoPai;}
#line 1661 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 195 "parser.y" /* yacc.c:1646  */
    {
	Structures::SymbolTable* escopoPai = simbolTable->pai;
	(yyval.scope) = simbolTable;
	simbolTable = escopoPai;

}
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.block) = new AST::Block(); (yyval.block)->lines.push_back((yyvsp[0].node)); }
#line 1678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 206 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[0].node) != NULL) (yyvsp[-1].block)->lines.push_back((yyvsp[0].node)); }
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);simbolTable->updateTypes((yyvsp[-1].node), (yyvsp[-3].type));}
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 212 "parser.y" /* yacc.c:1646  */
    {simbolTable->updateTypesAndSize((yyvsp[-1].node), (yyvsp[-6].type), (yyvsp[-4].integer)); (yyval.node) = (yyvsp[-1].node); }
#line 1696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);simbolTable->updateTypes((yyvsp[-1].node), Structures::Types::compound,(yyvsp[-3].identifier));}
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);simbolTable->updateTypesAndSize((yyvsp[-1].node), Structures::Types::compound,(yyvsp[-4].integer),(yyvsp[-6].identifier));}
#line 1708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 221 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].node)->hasParentheses = true; (yyval.node) = (yyvsp[-1].node); }
#line 1720 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AST::BinOp((yyvsp[-2].node),(yyvsp[-1].operation),(yyvsp[0].node));}
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 223 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.node) = (yyvsp[-1].node); }
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = simbolTable->insertId((yyvsp[0].identifier),NULL,Structures::Types::tInteger,true); }
#line 1738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.node)= simbolTable->insertId((yyvsp[0].identifier),(yyvsp[-2].node),Structures::Types::tInteger,true); }
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = simbolTable->insertId((yyvsp[0].identifier),NULL,Structures::Types::tInteger,false); }
#line 1750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 233 "parser.y" /* yacc.c:1646  */
    {(yyval.node)= simbolTable->insertId((yyvsp[0].identifier),(yyvsp[-2].node),Structures::Types::tInteger,false); }
#line 1756 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AST::Integer((yyvsp[0].integer)); }
#line 1762 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AST::Double((yyvsp[0].ddouble));}
#line 1768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 241 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AST::Boolean(true);}
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 242 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AST::Boolean(false);}
#line 1780 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1786 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 244 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = simbolTable->getIdentifier((yyvsp[0].identifier));}
#line 1792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = simbolTable->getIdentifier((yyvsp[-3].identifier),(yyvsp[-1].node));}
#line 1798 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = simbolTable->getIdentifier((yyvsp[-2].identifier),(yyvsp[0].identifier));}
#line 1804 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = simbolTable->getIdentifier((yyvsp[-5].identifier),(yyvsp[-3].identifier),(yyvsp[-1].node));}
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 248 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = simbolTable->getIdentifier((yyvsp[-5].identifier),(yyvsp[-3].node),(yyvsp[0].identifier));}
#line 1816 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AST::UnaryOp(AST::ominus,(yyvsp[0].node));}
#line 1822 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new AST::UnaryOp(AST::onot,(yyvsp[0].node));}
#line 1828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 258 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=Structures::Types::tDouble;}
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=Structures::Types::tInteger;}
#line 1840 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=Structures::Types::tBool;}
#line 1846 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::oplus;}
#line 1852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::omult;}
#line 1858 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 267 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::ominus;}
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 268 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::odiv;}
#line 1870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::oequal;}
#line 1876 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::odifferent;}
#line 1882 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::ogreater;}
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 272 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::oless;}
#line 1894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::ogreatereq;}
#line 1900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::olesseq;}
#line 1906 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::oor;}
#line 1912 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.operation) = AST::oand;}
#line 1918 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1922 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 279 "parser.y" /* yacc.c:1906  */



