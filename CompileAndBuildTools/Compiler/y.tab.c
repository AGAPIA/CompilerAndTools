
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "calc3.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3_defs.h"
#include "calc3_utils.h"
#include "NodeTypes.h"
#include "InputTypes.h"

/* prototypes */

extern "C"
{
	int yylex(void);
	void yyerror(char *s);
}

extern "C" 	FILE *yyin;



/* Line 189 of yacc.c  */
#line 95 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NIL = 258,
     LISTEN = 259,
     READ = 260,
     SPEAK = 261,
     WRITE = 262,
     COMPOSITION_DIAGONAL = 263,
     COMPOSITION_VERTICAL = 264,
     COMPOSITION_HORIZONTAL = 265,
     WHILE = 266,
     IF = 267,
     PRINT = 268,
     MODULE = 269,
     FOR = 270,
     FOR_S = 271,
     FOR_T = 272,
     FOR_ST = 273,
     WHILE_S = 274,
     WHILE_T = 275,
     WHILE_ST = 276,
     AND = 277,
     OR = 278,
     DTYPE_INT = 279,
     DTYPE_BOOL = 280,
     DTYPE_FLOAT = 281,
     DTYPE_STRING = 282,
     DTYPE_ARRAY = 283,
     INTEGER = 284,
     IDENTIFIER_LOW = 285,
     IDENTIFIER_BIG = 286,
     FLOAT = 287,
     IFX = 288,
     ELSE = 289,
     EXPR_WITHOUT_BOOL = 290,
     NE = 291,
     EQ = 292,
     LE = 293,
     GE = 294,
     UMINUS = 295
   };
#endif
/* Tokens.  */
#define NIL 258
#define LISTEN 259
#define READ 260
#define SPEAK 261
#define WRITE 262
#define COMPOSITION_DIAGONAL 263
#define COMPOSITION_VERTICAL 264
#define COMPOSITION_HORIZONTAL 265
#define WHILE 266
#define IF 267
#define PRINT 268
#define MODULE 269
#define FOR 270
#define FOR_S 271
#define FOR_T 272
#define FOR_ST 273
#define WHILE_S 274
#define WHILE_T 275
#define WHILE_ST 276
#define AND 277
#define OR 278
#define DTYPE_INT 279
#define DTYPE_BOOL 280
#define DTYPE_FLOAT 281
#define DTYPE_STRING 282
#define DTYPE_ARRAY 283
#define INTEGER 284
#define IDENTIFIER_LOW 285
#define IDENTIFIER_BIG 286
#define FLOAT 287
#define IFX 288
#define ELSE 289
#define EXPR_WITHOUT_BOOL 290
#define NE 291
#define EQ 292
#define LE 293
#define GE 294
#define UMINUS 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "calc3.y"

    int iValue;                 /* integer value */
    int iDataType;				/* for data types */
    float fValue;				/* float value */
    void *pNodeModule;			/* node module - program  --- Node */
    void *pExpression;			/* NodeExpression */
    void *pBlockInput;			/* InputBlock*/
    void *pInputItem;			/* IInputItem */
    void *pProcessInput;		/* BaseProcessInput */
    void *pAsignment;			/* Asignment */
    void *pProgramNode;			/* Program node */
    struct ProgramInput pInput;		/* Input */
    struct ProgramOutput pOutput;		/* Output*/
    char identifier[MAX_IDENTIFIER_SIZE];		/* identifier */



/* Line 214 of yacc.c  */
#line 229 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 254 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   382

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    36,    45,    43,    54,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    50,
      38,    56,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    39,    40,    41,    42,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    18,    27,    36,    38,
      40,    44,    46,    48,    50,    59,    63,    65,    69,    75,
      77,    79,    81,    83,    85,    87,    89,    91,    95,    99,
     100,   105,   109,   110,   119,   120,   133,   141,   149,   157,
     165,   173,   181,   182,   186,   189,   191,   199,   207,   219,
     227,   231,   233,   235,   237,   242,   246,   249,   253,   257,
     261,   265,   267,   271,   275,   279,   283,   287,   291,   295,
     299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    59,    60,    -1,    60,    -1,
      14,    31,    61,    48,    63,    49,    62,    -1,    48,     4,
      64,    49,    48,     5,    64,    49,    -1,    48,     6,    64,
      49,    48,     7,    64,    49,    -1,    69,    -1,    73,    -1,
      64,    50,    65,    -1,    65,    -1,     3,    -1,    66,    -1,
      51,    51,    66,    50,    36,    52,    53,    36,    -1,    66,
      54,    67,    -1,    67,    -1,    30,    55,    68,    -1,    30,
      55,    68,    52,    53,    -1,    24,    -1,    25,    -1,    27,
      -1,    26,    -1,    28,    -1,    31,    -1,    75,    -1,    67,
      -1,    69,    10,    69,    -1,    69,     9,    69,    -1,    -1,
      69,     8,    69,    70,    -1,    51,    69,    36,    -1,    -1,
      12,    51,    77,    36,    48,    69,    49,    71,    -1,    -1,
      12,    51,    77,    36,    48,    69,    49,    34,    48,    69,
      49,    72,    -1,    19,    51,    77,    36,    48,    69,    49,
      -1,    21,    51,    77,    36,    48,    69,    49,    -1,    20,
      51,    77,    36,    48,    69,    49,    -1,    16,    51,    76,
      36,    48,    69,    49,    -1,    18,    51,    76,    36,    48,
      69,    49,    -1,    17,    51,    76,    36,    48,    69,    49,
      -1,    -1,    73,    74,    50,    -1,    74,    50,    -1,    75,
      -1,    11,    51,    77,    36,    48,    73,    49,    -1,    12,
      51,    77,    36,    48,    73,    49,    -1,    12,    51,    77,
      36,    48,    73,    49,    34,    48,    73,    49,    -1,    15,
      51,    76,    36,    48,    73,    49,    -1,    30,    56,    76,
      -1,    29,    -1,    32,    -1,    30,    -1,    30,    52,    76,
      53,    -1,    51,    76,    36,    -1,    44,    76,    -1,    76,
      43,    76,    -1,    76,    44,    76,    -1,    76,    45,    76,
      -1,    76,    46,    76,    -1,    77,    -1,    76,    38,    76,
      -1,    76,    37,    76,    -1,    76,    42,    76,    -1,    76,
      41,    76,    -1,    76,    39,    76,    -1,    76,    40,    76,
      -1,    76,    22,    76,    -1,    76,    23,    76,    -1,    51,
      77,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    84,    84,    88,    89,    93,    97,   111,   119,   120,
     124,   125,   126,   130,   131,   135,   136,   140,   141,   145,
     146,   147,   148,   149,   153,   154,   155,   156,   157,   158,
     158,   159,   160,   160,   161,   161,   162,   163,   164,   165,
     166,   167,   168,   172,   173,   177,   178,   179,   180,   181,
     185,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   203,   204,   205,   206,   207,   208,   209,   210,
     211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NIL", "LISTEN", "READ", "SPEAK",
  "WRITE", "COMPOSITION_DIAGONAL", "COMPOSITION_VERTICAL",
  "COMPOSITION_HORIZONTAL", "WHILE", "IF", "PRINT", "MODULE", "FOR",
  "FOR_S", "FOR_T", "FOR_ST", "WHILE_S", "WHILE_T", "WHILE_ST", "AND",
  "OR", "DTYPE_INT", "DTYPE_BOOL", "DTYPE_FLOAT", "DTYPE_STRING",
  "DTYPE_ARRAY", "INTEGER", "IDENTIFIER_LOW", "IDENTIFIER_BIG", "FLOAT",
  "IFX", "ELSE", "EXPR_WITHOUT_BOOL", "')'", "'>'", "'<'", "NE", "EQ",
  "LE", "GE", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'{'", "'}'", "';'",
  "'('", "'['", "']'", "','", "':'", "'='", "$accept", "agapiacode",
  "modules_list", "module", "module_input", "module_output", "module_body",
  "processinputlist", "singleproceslist", "simplevariablelist", "variable",
  "datatype", "program", "$@1", "$@2", "$@3", "stmt_list", "statement",
  "asignment", "expr", "boolean_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    41,    62,    60,   291,
     292,   293,   294,    43,    45,    42,    47,   295,   123,   125,
      59,    40,    91,    93,    44,    58,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    61,    62,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    69,    69,    69,    69,    69,    70,
      69,    69,    71,    69,    72,    69,    69,    69,    69,    69,
      69,    69,    69,    73,    73,    74,    74,    74,    74,    74,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     7,     8,     8,     1,     1,
       3,     1,     1,     1,     8,     3,     1,     3,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     0,
       4,     3,     0,     8,     0,    12,     7,     7,     7,     7,
       7,     7,     0,     3,     2,     1,     7,     7,    11,     7,
       3,     1,     1,     1,     4,     3,     2,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     0,     0,
       0,    42,    12,     0,     0,     0,    11,    13,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      42,     0,    26,     8,     9,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,    42,    42,    42,     0,
       0,     0,    45,    44,    19,    20,    22,    21,    23,    17,
       0,     0,    10,    15,    51,    53,    52,     0,     0,     0,
      61,    61,     0,    61,     0,     0,     0,    61,    61,    61,
      50,     0,    31,     0,     5,    29,    28,    27,     0,    43,
       0,     0,     0,     0,    56,     0,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
      30,    61,    18,     0,     0,     0,    55,    70,    68,    69,
      63,    62,    66,    67,    65,    64,    57,    58,    59,    60,
       0,    42,     0,    42,    42,    42,    42,    42,    42,     0,
       0,     0,     0,     6,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,    46,
      32,    47,    49,    39,    41,    40,    36,    38,    37,     0,
      14,     0,    33,     0,     0,    42,     0,     0,     0,     0,
       7,    34,    48,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    94,    31,    15,    16,    17,
      32,    69,   166,   130,   192,   203,   167,    35,    54,    79,
      83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
      -9,    -2,    24,    -9,  -102,   -14,  -102,  -102,    33,    10,
       8,   161,  -102,   -16,     9,   -28,  -102,    11,  -102,    16,
      18,    31,    53,    71,    72,    74,    78,    81,    -1,  -102,
      96,    62,  -102,    92,   352,    70,    80,   134,    94,    85,
       6,    94,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,    84,   200,  -102,   107,    96,    96,    96,    91,
      88,   113,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   112,
     -19,   160,  -102,  -102,  -102,   115,  -102,   330,   330,   312,
     133,   135,   230,  -102,   241,   266,   277,   138,   139,   157,
     312,   330,  -102,   164,  -102,    92,   189,  -102,   330,  -102,
     148,   169,     8,   330,  -102,   302,   170,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   163,
     166,   171,   175,   176,   177,   178,   181,   182,   184,     8,
    -102,   195,  -102,   202,    35,   205,  -102,  -102,  -102,  -102,
     194,   194,   194,   194,   194,   194,     4,     4,    73,    73,
     352,   161,   352,    96,    96,    96,    96,    96,    96,   187,
      60,   207,   165,  -102,  -102,   172,     7,   183,   185,    34,
      37,    54,    79,    82,    89,    96,   208,   352,   197,  -102,
     223,   225,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   253,
    -102,   213,  -102,   214,     8,    96,   352,    69,    97,   192,
    -102,  -102,  -102,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,   262,  -102,  -102,  -102,  -101,   250,   254,
      -8,  -102,    -5,  -102,  -102,  -102,    -7,   -31,   -11,   -37,
     -30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -46
static const yytype_int16 yytable[] =
{
      36,   134,    18,    61,    34,     1,    33,    82,    84,    85,
      86,    12,    80,    81,    90,    56,    57,    58,    87,    88,
      89,    39,    40,    62,     6,    53,   107,   108,   160,     5,
      18,   101,    18,    73,     8,    41,    13,    10,    13,    37,
     104,   105,    56,    57,    58,    56,    57,    58,   106,   117,
     118,    95,    96,    97,    37,    51,   180,    14,    11,    14,
      38,   128,    56,    57,    58,    41,   135,    42,   131,    43,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    44,   183,   163,    40,   184,    56,    57,    58,
      56,    57,    58,   197,    18,   107,   108,    56,    57,    58,
      56,    57,    58,   185,    45,    56,    57,    58,    52,   176,
      40,    55,    22,    23,    24,    25,    26,    27,   200,    40,
      63,    18,    46,    47,    13,    48,    28,    29,   186,    49,
     -45,   187,    50,    71,    61,    91,    61,    61,   188,    62,
      36,    62,    98,   165,    51,   168,   201,    30,   169,   170,
     171,   172,   173,   174,    62,    93,    62,    62,    64,    65,
      66,    67,    68,    99,   100,   102,    62,   103,    61,   119,
     129,   120,    19,    20,   125,   126,    21,    22,    23,    24,
      25,    26,    27,    19,    59,    62,    18,    21,    62,   199,
     198,    28,    29,   127,    19,    59,    19,    59,    21,    58,
      21,   132,    60,    19,    59,   133,   137,    21,    56,    57,
      58,   150,    30,    60,   151,    60,   107,   108,   178,   152,
     159,   179,    60,   153,   154,   155,   156,   107,   108,   157,
     158,   161,   181,   190,   182,   175,    92,   115,   116,   117,
     118,   202,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   107,   108,   162,   177,   189,   191,   164,   193,
     194,   195,   196,   107,   108,     7,   121,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   122,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   107,   108,
      72,     0,    70,     0,     0,     0,     0,     0,     0,   107,
     108,     0,   123,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   124,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,   136,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    74,
      75,     0,    76,    19,    59,     0,     0,    21,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
       0,    78,    60
};

static const yytype_int16 yycheck[] =
{
      11,   102,    10,    34,    11,    14,    11,    44,    45,    46,
      47,     3,    42,    43,    51,     8,     9,    10,    48,    49,
      50,    49,    50,    34,     0,    30,    22,    23,   129,    31,
      38,    50,    40,    41,    48,    54,    30,     4,    30,    55,
      77,    78,     8,     9,    10,     8,     9,    10,    78,    45,
      46,    56,    57,    58,    55,    56,    49,    51,    48,    51,
      51,    91,     8,     9,    10,    54,   103,    51,    98,    51,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    51,    49,    49,    50,    49,     8,     9,    10,
       8,     9,    10,   194,   102,    22,    23,     8,     9,    10,
       8,     9,    10,    49,    51,     8,     9,    10,    12,    49,
      50,    49,    16,    17,    18,    19,    20,    21,    49,    50,
      50,   129,    51,    51,    30,    51,    30,    31,    49,    51,
      50,    49,    51,    48,   165,    51,   167,   168,    49,   150,
     151,   152,    51,   150,    56,   152,    49,    51,   153,   154,
     155,   156,   157,   158,   165,    48,   167,   168,    24,    25,
      26,    27,    28,    50,    52,     5,   177,    52,   199,    36,
       6,    36,    11,    12,    36,    36,    15,    16,    17,    18,
      19,    20,    21,    11,    12,   196,   194,    15,   199,   196,
     195,    30,    31,    36,    11,    12,    11,    12,    15,    10,
      15,    53,    30,    11,    12,    36,    36,    15,     8,     9,
      10,    48,    51,    30,    48,    30,    22,    23,    53,    48,
      36,    49,    30,    48,    48,    48,    48,    22,    23,    48,
      48,    36,    49,    36,    49,    48,    36,    43,    44,    45,
      46,    49,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    22,    23,    52,    48,    48,    34,    53,    34,
       7,    48,    48,    22,    23,     3,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    22,    23,
      40,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    29,
      30,    -1,    32,    11,    12,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    58,    59,    60,    31,     0,    60,    48,    61,
       4,    48,     3,    30,    51,    64,    65,    66,    67,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    30,    31,
      51,    63,    67,    69,    73,    74,    75,    55,    51,    49,
      50,    54,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    56,    12,    69,    75,    49,     8,     9,    10,    12,
      30,    74,    75,    50,    24,    25,    26,    27,    28,    68,
      66,    48,    65,    67,    29,    30,    32,    44,    51,    76,
      77,    77,    76,    77,    76,    76,    76,    77,    77,    77,
      76,    51,    36,    48,    62,    69,    69,    69,    51,    50,
      52,    50,     5,    52,    76,    76,    77,    22,    23,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    77,     6,
      70,    77,    53,    36,    64,    76,    36,    36,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    36,
      64,    36,    52,    49,    53,    73,    69,    73,    73,    69,
      69,    69,    69,    69,    69,    48,    49,    48,    53,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    48,
      36,    34,    71,    34,     7,    48,    48,    64,    69,    73,
      49,    49,    49,    72
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 84 "calc3.y"
    { printf("Agapia code confirmed \n\n"); exit(0); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 88 "calc3.y"
    { printf("Module confirmed \n\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 93 "calc3.y"
    { ABSTFactory::CreateAgapiaNode((yyvsp[(2) - (7)].identifier), (yyvsp[(3) - (7)].pInput), (yyvsp[(2) - (7)].identifier), (yyvsp[(7) - (7)].pOutput)); printf("module detected \n\n"); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 98 "calc3.y"
    { 
			(yyval.pInput).north = (yyvsp[(3) - (8)].pBlockInput);
			(yyval.pInput).west = (yyvsp[(7) - (8)].pBlockInput);
			
			printf(" module input detected \n\n"); 
			InputBlock* pIB = (InputBlock*) (yyvsp[(3) - (8)].pBlockInput); 
			pIB->PrintDebugInfo(0); 
			pIB = (InputBlock*) (yyvsp[(7) - (8)].pBlockInput); 
			pIB->PrintDebugInfo(0); 			
		}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 112 "calc3.y"
    {
		
			printf(" module output detected \n\n"); InputBlock* pIB = (InputBlock*) (yyvsp[(3) - (8)].pBlockInput); pIB->PrintDebugInfo(0); pIB = (InputBlock*) (yyvsp[(7) - (8)].pBlockInput); pIB->PrintDebugInfo(0);
		}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 119 "calc3.y"
    { (yyval.pNodeModule) = (yyvsp[(1) - (1)].pNodeModule); printf("module body - PROGRAM detected "); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 120 "calc3.y"
    { printf("module body - STATEMENTS detected "); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 124 "calc3.y"
    { InputBlock* pIB = (InputBlock*) (yyvsp[(1) - (3)].pBlockInput); pIB->AddInput((BaseProcessInput*)(yyvsp[(3) - (3)].pBlockInput)); (yyval.pBlockInput) = pIB; printf(" processinputlist detected \n\n"); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 125 "calc3.y"
    { InputBlock* pIB = new InputBlock(); pIB->AddInput((BaseProcessInput*)(yyvsp[(1) - (1)].pBlockInput)); (yyval.pBlockInput) = pIB; printf(" processinputlist detected \n\n"); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 126 "calc3.y"
    { InputBlock* pIB = new InputBlock(); (yyval.pBlockInput) = pIB; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 130 "calc3.y"
    { (yyval.pBlockInput) = (yyvsp[(1) - (1)].pProcessInput); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 131 "calc3.y"
    { VectorProcessItem* pVPI = new VectorProcessItem(); pVPI->SetItemType((SimpleProcessItem*)(yyvsp[(3) - (8)].pProcessInput)); (yyval.pBlockInput) = pVPI; }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 135 "calc3.y"
    { SimpleProcessItem* pSPI = (SimpleProcessItem*) (yyvsp[(1) - (3)].pProcessInput); pSPI->AddItem((IDataTypeItem*)(yyvsp[(3) - (3)].pInputItem)); (yyval.pProcessInput) = pSPI; printf(" simplevariablelist detected \n\n"); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 136 "calc3.y"
    { SimpleProcessItem* pSPI = new SimpleProcessItem(); pSPI->AddItem((IDataTypeItem*)(yyvsp[(1) - (1)].pInputItem)); (yyval.pProcessInput) = pSPI; printf(" simplevariablelist detected \n\n"); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 140 "calc3.y"
    { (yyval.pInputItem) = ItemTypeFactory::CreateInputItem((yyvsp[(3) - (3)].iDataType), (yyvsp[(1) - (3)].identifier), false); printf(" variable detected \n\n"); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 141 "calc3.y"
    { (yyval.pInputItem) = ItemTypeFactory::CreateInputItem((yyvsp[(3) - (5)].iDataType), (yyvsp[(1) - (5)].identifier), true); printf(" variable detected \n\n"); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 145 "calc3.y"
    { (yyval.iDataType) = (yyvsp[(1) - (1)].iDataType); printf("Type number is %d\n", (yyvsp[(1) - (1)].iDataType)); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 146 "calc3.y"
    { (yyval.iDataType) = (yyvsp[(1) - (1)].iDataType); printf("Type number is %d\n", (yyvsp[(1) - (1)].iDataType)); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 147 "calc3.y"
    { (yyval.iDataType) = (yyvsp[(1) - (1)].iDataType); printf("Type number is %d\n", (yyvsp[(1) - (1)].iDataType)); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 148 "calc3.y"
    { (yyval.iDataType) = (yyvsp[(1) - (1)].iDataType); printf("Type number is %d\n", (yyvsp[(1) - (1)].iDataType)); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 149 "calc3.y"
    { (yyval.iDataType) = (yyvsp[(1) - (1)].iDataType); printf("Type number is %d\n", (yyvsp[(1) - (1)].iDataType)); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 153 "calc3.y"
    { (yyval.pNodeModule) = ABSTFactory::CreateProgramRef((yyvsp[(1) - (1)].identifier)); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 154 "calc3.y"
    { (yyval.pNodeModule) = (yyvsp[(1) - (1)].pAsignment); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 155 "calc3.y"
    { (yyval.pNodeModule) = ABSTFactory::CreateDeclarationProgram((yyvsp[(1) - (1)].pInputItem)); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 156 "calc3.y"
    { (yyval.pNodeModule) = ABSTFactory::CreateIntermediateProgram((yyvsp[(1) - (3)].pNodeModule), (yyvsp[(3) - (3)].pNodeModule), E_COMP_HORIZONTAL); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 157 "calc3.y"
    { (yyval.pNodeModule) = ABSTFactory::CreateIntermediateProgram((yyvsp[(1) - (3)].pNodeModule), (yyvsp[(3) - (3)].pNodeModule), E_COMP_VERTICAL); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 158 "calc3.y"
    { }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 158 "calc3.y"
    { (yyval.pNodeModule) = ABSTFactory::CreateIntermediateProgram((yyvsp[(1) - (4)].pNodeModule), (yyvsp[(3) - (4)].pNodeModule), E_COMP_DIAGONAL); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 159 "calc3.y"
    { (yyval.pNodeModule) = (yyvsp[(2) - (3)].pNodeModule); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 160 "calc3.y"
    {}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 160 "calc3.y"
    { (yyval.pNodeModule) = ABSTFactory::CreateIFProgram((yyvsp[(3) - (8)].pExpression), (yyvsp[(6) - (8)].pNodeModule), NULL); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 161 "calc3.y"
    { }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 161 "calc3.y"
    { (yyval.pNodeModule) = ABSTFactory::CreateIFProgram((yyvsp[(3) - (12)].pExpression), (yyvsp[(6) - (12)].pNodeModule), (yyvsp[(10) - (12)].pNodeModule)); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 162 "calc3.y"
    { }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 163 "calc3.y"
    { }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 164 "calc3.y"
    { }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 165 "calc3.y"
    { }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 166 "calc3.y"
    { }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 167 "calc3.y"
    { }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 168 "calc3.y"
    { }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 177 "calc3.y"
    { printf("Asignment statement detected\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 178 "calc3.y"
    { printf("simple while detected\n"); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 179 "calc3.y"
    {}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 180 "calc3.y"
    {}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 181 "calc3.y"
    { printf("simple for detected\n"); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 185 "calc3.y"
    { (yyval.pAsignment) = ABSTFactory::CreateAsignmentProgram((yyvsp[(1) - (3)].identifier), (yyvsp[(3) - (3)].pExpression)); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 189 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateAtomicExpression((yyvsp[(1) - (1)].iValue)); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 190 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateAtomicExpression((yyvsp[(1) - (1)].fValue)); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 191 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateAtomicExprIdentifier((yyvsp[(1) - (1)].identifier)); printf("expressions \n"); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 192 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateArrayAccessExpression((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].pExpression)); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 193 "calc3.y"
    { (yyval.pExpression) = (yyvsp[(2) - (3)].pExpression); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 194 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateValueExpression((yyvsp[(2) - (2)].pExpression), NULL, E_UNARYMINUS); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 195 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateValueExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_OP_PLUS); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 196 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateValueExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_OP_MINUS);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 197 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateValueExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_OP_MULT);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 198 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateValueExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_OP_DIV);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 199 "calc3.y"
    { (yyval.pExpression) = (yyvsp[(1) - (1)].pExpression); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 203 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateBooleanExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_SMALL_THAN);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 204 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateBooleanExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_BIG_THAN);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 205 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateBooleanExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_BIG_OR_EQUAL_THAN);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 206 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateBooleanExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_SMALL_OR_EQUAL_THAN);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 207 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateBooleanExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_DIFFERENT);}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 208 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateBooleanExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_EQUAL);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 209 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateBooleanExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_AND);}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 210 "calc3.y"
    { (yyval.pExpression) = ABSTFactory::CreateBooleanExpression((yyvsp[(1) - (3)].pExpression), (yyvsp[(3) - (3)].pExpression), E_OR);}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 211 "calc3.y"
    { (yyval.pExpression) = (yyvsp[(2) - (3)].pExpression);}
    break;



/* Line 1455 of yacc.c  */
#line 2160 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 214 "calc3.y"



void yyerror(char *s) 
{
	fprintf(stdout, "Line %d, Column %d: Too long identifier. A maximum of %d is allowed !\n", yylloc.first_line, yylloc.first_column, MAX_IDENTIFIER_SIZE);
    fprintf(stdout, "%s\n", s);
}

int main(void) {

	FILE *f = fopen("input.txt", "r");
	yyin = f;
    yyparse();
    return 0;
}


