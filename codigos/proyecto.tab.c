/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "proyecto.y"

	void yyerror (char *s);
	#include <stdio.h>
	#include <stdlib.h>

	int pilaOperandos [100];
	int pilaOperadores [100];
	int pilaFondoFalso [100];
	int pilaSaltos [100];
	int operadores=0,operandos=0,fondo_falso=0, saltos=0;
	
	int temp=6000;
	int mem_in=1000;
	int mem_out=2000;
	int mem_signal=3000;
	int mem_const=4000;
	
	int cuad1[1000], cuad2[1000], cuad3[1000], cuad4[1000];
	int cuad_cont=0;
	int cont;
	int cont_tranza;
	int flag=1;
		
	//-----------cubos semanticos----------------------------------------------------------//
	
	int semantica2 [5][15]=	{{-1,-1,0,1,2,3,4,5,6,7,8,9,10,11,12},
							{100,100,100,100,100,100,100,100,100,100,100,-1,100,101,100},
							{100,101,-1,100,101,101,100,100,100,101,101,-1,101,101,101},
							{101,100,101,100,101,101,100,100,100,101,101,-1,101,101,101},
							{101,101,101,100,101,101,100,100,100,101,101,-1,101,101,101}};
							
	int semantica1 [10][15]={{-1,-1,0,1,2,33,4,5,6,7,8,9,10,11,12},
							{200,200,-1,200,200,200,200,200,200,200,200,200,200,200,200},
							{200,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{200,202,-1,202,202,202,202,202,202,202,202,202,202,202,202},
							{201,200,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{201,201,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{201,202,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{202,200,202,202,202,202,202,202,202,202,202,202,202,202,202},
							{202,201,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
							{202,202,202,202,202,202,202,202,202,202,202,202,202,202,202}};
	
	//----------Fin de cubos semanticos----------------------------------------------------//
	
	//-------------------Tabla de variables------------------------------------------------//
	
	char Table_var[100][3];
	int Table_var_mem[100];
	int contab=0;
	
	//----------------Fin de tabla de variables--------------------------------------------//



/* Line 189 of yacc.c  */
#line 127 "proyecto.tab.c"

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
     entity = 258,
     is = 259,
     to = 260,
     end = 261,
     architecture = 262,
     of = 263,
     begin = 264,
     IF = 265,
     THEN = 266,
     ELSE = 267,
     CASE = 268,
     WHEN = 269,
     BREAK = 270,
     OTHER = 271,
     SHL = 272,
     SHR = 273,
     CTE_INT = 274,
     ID = 275,
     in = 276,
     out = 277,
     signal = 278,
     bit = 279,
     vector = 280
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 55 "proyecto.y"
int integer; char id; char tipos;


/* Line 214 of yacc.c  */
#line 192 "proyecto.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "proyecto.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,     2,    34,     2,
      26,    27,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    28,
      32,    30,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    16,    19,    20,    22,    23,    30,
      32,    34,    36,    41,    43,    53,    56,    57,    59,    61,
      63,    65,    66,    67,    68,    76,    77,    78,    79,    90,
      91,    96,    97,    98,   106,   107,   108,   118,   119,   120,
     130,   131,   133,   135,   138,   139,   140,   144,   145,   149,
     150,   154,   155,   159,   162,   163,   167,   168,   169,   173,
     174,   178,   179,   183,   186,   187,   188,   192,   193,   197,
     200,   201,   202,   206,   207,   211,   212,   217,   219,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    48,    -1,     3,    20,     4,    26,
      42,    27,     6,    20,    28,    -1,    44,    43,    -1,    -1,
      42,    -1,    -1,    20,    29,    45,    46,    47,    28,    -1,
      21,    -1,    22,    -1,    23,    -1,    25,    26,    19,    27,
      -1,    24,    -1,     7,     8,    20,     4,     9,    49,     6,
      20,    28,    -1,    51,    50,    -1,    -1,    49,    -1,    52,
      -1,    56,    -1,    64,    -1,    -1,    -1,    -1,    20,    53,
      30,    54,    77,    55,    28,    -1,    -1,    -1,    -1,    10,
      26,    57,    71,    27,    58,    11,    59,    49,    60,    -1,
      -1,     6,    10,    61,    28,    -1,    -1,    -1,    12,    62,
      49,     6,    10,    63,    28,    -1,    -1,    -1,    13,    20,
      65,     4,    67,     6,    13,    66,    28,    -1,    -1,    -1,
      14,    70,    29,    68,    49,    15,    28,    69,    67,    -1,
      -1,    19,    -1,    16,    -1,    77,    72,    -1,    -1,    -1,
      30,    73,    77,    -1,    -1,    31,    74,    77,    -1,    -1,
      32,    75,    77,    -1,    -1,    33,    76,    77,    -1,    83,
      79,    -1,    -1,    31,    78,    77,    -1,    -1,    -1,    34,
      80,    77,    -1,    -1,    35,    81,    77,    -1,    -1,    36,
      82,    77,    -1,    87,    84,    -1,    -1,    -1,    37,    85,
      83,    -1,    -1,    38,    86,    83,    -1,    91,    88,    -1,
      -1,    -1,    17,    89,    87,    -1,    -1,    18,    90,    87,
      -1,    -1,    26,    92,    77,    27,    -1,    93,    -1,    20,
      -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    87,   100,   103,   104,   107,   107,   111,
     112,   113,   116,   117,   120,   130,   133,   134,   137,   138,
     139,   142,   154,   156,   142,   166,   166,   166,   166,   176,
     176,   178,   186,   178,   190,   203,   190,   219,   234,   219,
     248,   251,   265,   281,   284,   285,   285,   293,   293,   301,
     301,   309,   309,   319,   320,   320,   331,   332,   332,   341,
     341,   350,   350,   361,   364,   365,   365,   374,   374,   385,
     388,   389,   389,   398,   398,   409,   409,   410,   413,   425
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "entity", "is", "to", "end",
  "architecture", "of", "begin", "IF", "THEN", "ELSE", "CASE", "WHEN",
  "BREAK", "OTHER", "SHL", "SHR", "CTE_INT", "ID", "in", "out", "signal",
  "bit", "vector", "'('", "')'", "';'", "':'", "'='", "'!'", "'<'", "'>'",
  "'&'", "'|'", "'^'", "'+'", "'-'", "$accept", "PROGRAM", "VARS", "VAR1",
  "VAR2", "VAR", "$@1", "INOUT", "TIPO", "BLOQUE", "ESTATUTO1",
  "ESTATUTO2", "ESTATUTO", "ASIGNACION", "$@2", "$@3", "$@4", "CONDIF",
  "$@5", "$@6", "$@7", "CONDIF1", "$@8", "$@9", "$@10", "CONDCASE", "$@11",
  "$@12", "CONDCASE1", "$@13", "$@14", "OPCASE", "EXPRESION", "EXPRESION1",
  "$@15", "$@16", "$@17", "$@18", "EXP", "$@19", "LOGIC1", "$@20", "$@21",
  "$@22", "LOGIC", "TERMINO1", "$@23", "$@24", "TERMINO", "FACTOR1",
  "$@25", "$@26", "FACTOR", "$@27", "VAR_CTE", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    40,    41,    59,    58,
      61,    33,    60,    62,    38,   124,    94,    43,    45
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    42,    43,    43,    45,    44,    46,
      46,    46,    47,    47,    48,    49,    50,    50,    51,    51,
      51,    53,    54,    55,    52,    57,    58,    59,    56,    61,
      60,    62,    63,    60,    65,    66,    64,    68,    69,    67,
      67,    70,    70,    71,    72,    73,    72,    74,    72,    75,
      72,    76,    72,    77,    78,    77,    79,    80,    79,    81,
      79,    82,    79,    83,    84,    85,    84,    86,    84,    87,
      88,    89,    88,    90,    88,    92,    91,    91,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     9,     2,     0,     1,     0,     6,     1,
       1,     1,     4,     1,     9,     2,     0,     1,     1,     1,
       1,     0,     0,     0,     7,     0,     0,     0,    10,     0,
       4,     0,     0,     7,     0,     0,     9,     0,     0,     9,
       0,     1,     1,     2,     0,     0,     3,     0,     3,     0,
       3,     0,     3,     2,     0,     3,     0,     0,     3,     0,
       3,     0,     3,     2,     0,     0,     3,     0,     3,     2,
       0,     0,     3,     0,     3,     0,     4,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     0,     0,     0,     5,     0,     7,     0,     6,     4,
       0,     0,     0,     0,     0,    21,     0,    16,    18,    19,
      20,     9,    10,    11,     0,     0,    25,    34,     0,     0,
      17,    15,    13,     0,     0,     3,     0,     0,    22,     0,
       0,     8,    79,    78,    75,    54,     0,    44,    56,    64,
      70,    77,    40,     0,    14,     0,     0,     0,    26,    45,
      47,    49,    51,    43,    57,    59,    61,    53,    65,    67,
      63,    71,    73,    69,     0,     0,    23,    12,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    41,     0,     0,     0,    76,    27,    46,
      48,    50,    52,    58,    60,    62,    66,    68,    72,    74,
      37,    35,    24,     0,     0,     0,     0,     0,    36,     0,
      31,    28,     0,    29,     0,    38,     0,     0,    40,    30,
       0,    39,    32,     0,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    13,    19,    14,    21,    34,    44,     7,
      26,    41,    27,    28,    38,    63,   106,    29,    46,    90,
     123,   131,   136,   134,   143,    30,    47,   125,    85,   124,
     138,   104,    56,    73,    91,    92,    93,    94,    57,    67,
      77,    95,    96,    97,    58,    80,    98,    99,    59,    83,
     100,   101,    60,    66,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int8 yypact[] =
{
       3,    26,    28,     1,    45,   -63,    42,   -63,    27,    31,
      32,    50,    29,    30,    32,    46,   -63,    53,   -63,   -63,
      -3,    15,    36,    34,    41,   -63,    56,    -3,   -63,   -63,
     -63,   -63,   -63,   -63,    -9,    35,   -63,   -63,    37,    44,
     -63,   -63,   -63,    39,    38,   -63,   -17,    64,   -63,    43,
      51,   -63,   -63,   -63,   -63,   -63,    47,   -10,     5,   -12,
      25,   -63,    55,   -17,   -63,    48,   -17,   -17,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,     8,    66,   -63,   -63,    49,   -63,
      62,   -17,   -17,   -17,   -17,   -17,   -17,   -17,    -8,    -8,
      -8,    -8,   -63,   -63,    52,    65,    54,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,    -3,    -3,    57,     7,    68,   -63,    67,
     -63,   -63,    58,   -63,    -3,   -63,    59,    73,    55,   -63,
      70,   -63,   -63,    60,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,    75,   -63,   -63,   -63,   -63,   -63,   -63,
     -27,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -48,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -62,   -63,
     -63,   -63,   -63,   -63,   -54,   -63,   -63,   -63,   -53,   -63,
     -63,   -63,   -63,   -63,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      40,    86,    52,    53,    88,    89,     1,    23,     6,    54,
      24,    52,    53,   129,    55,    42,    43,    25,    54,   130,
      69,    70,    71,    72,   102,    78,    79,   103,     5,   109,
     110,   111,   112,   113,   114,   115,    31,    32,    33,    74,
      75,    76,    81,    82,   116,   117,     4,   118,   119,     8,
       9,    11,    12,    10,    15,    20,    35,    17,    16,    22,
      36,    37,    39,    45,    49,    50,    51,    48,    62,    84,
      65,    64,   105,   108,    68,    87,   107,   133,   121,   140,
     142,   120,   122,   132,     0,   128,   135,   139,   144,    18,
     141,     0,     0,     0,     0,     0,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137
};

static const yytype_int16 yycheck[] =
{
      27,    63,    19,    20,    66,    67,     3,    10,     7,    26,
      13,    19,    20,     6,    31,    24,    25,    20,    26,    12,
      30,    31,    32,    33,    16,    37,    38,    19,     0,    91,
      92,    93,    94,    95,    96,    97,    21,    22,    23,    34,
      35,    36,    17,    18,    98,    99,    20,   100,   101,     4,
       8,    20,    20,    26,     4,     9,    20,    27,    29,     6,
      26,    20,     6,    28,    20,    26,    28,    30,     4,    14,
      19,    28,     6,    11,    27,    27,    27,    10,    13,     6,
      10,    29,    28,    15,    -1,    28,    28,    28,    28,    14,
     138,    -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    40,    41,    20,     0,     7,    48,     4,     8,
      26,    20,    20,    42,    44,     4,    29,    27,    42,    43,
       9,    45,     6,    10,    13,    20,    49,    51,    52,    56,
      64,    21,    22,    23,    46,    20,    26,    20,    53,     6,
      49,    50,    24,    25,    47,    28,    57,    65,    30,    20,
      26,    28,    19,    20,    26,    31,    71,    77,    83,    87,
      91,    93,     4,    54,    28,    19,    92,    78,    27,    30,
      31,    32,    33,    72,    34,    35,    36,    79,    37,    38,
      84,    17,    18,    88,    14,    67,    77,    27,    77,    77,
      58,    73,    74,    75,    76,    80,    81,    82,    85,    86,
      89,    90,    16,    19,    70,     6,    55,    27,    11,    77,
      77,    77,    77,    77,    77,    77,    83,    83,    87,    87,
      29,    13,    28,    59,    68,    66,    49,    49,    28,     6,
      12,    60,    15,    10,    62,    28,    61,    49,    69,    28,
       6,    67,    10,    63,    28
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 84 "proyecto.y"
    {;;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 87 "proyecto.y"
    {if((yyvsp[(2) - (9)].id)!=(yyvsp[(8) - (9)].id))
																printf("error semantico\n");
															for(cont=0; cont<contab; cont++)
																{
																	cuad1[cuad_cont]=16;
																	cuad2[cuad_cont]=Table_var_mem[cont];
																	cuad3[cuad_cont]=-1;
																	cuad4[cuad_cont]=Table_var[cont][2];
																	cuad_cont++;
																}
															;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 100 "proyecto.y"
    {;;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 103 "proyecto.y"
    {;;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 104 "proyecto.y"
    {;;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 107 "proyecto.y"
    {Table_var[contab][0]=(yyvsp[(1) - (2)].id);;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 108 "proyecto.y"
    {;;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 111 "proyecto.y"
    {Table_var[contab][1]='i';Table_var_mem[contab]=mem_in++;;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 112 "proyecto.y"
    {Table_var[contab][1]='o';Table_var_mem[contab]=mem_out++;;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 113 "proyecto.y"
    {Table_var[contab][1]='s';Table_var_mem[contab]=mem_signal++;;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 116 "proyecto.y"
    {Table_var[contab][2]=(yyvsp[(3) - (4)].integer); contab=contab+1;;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 117 "proyecto.y"
    {Table_var[contab][2]=1; contab=contab+1;;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 120 "proyecto.y"
    {if((yyvsp[(3) - (9)].id)!=(yyvsp[(8) - (9)].id))
																	printf("error semantico\n");
																FILE *f = fopen("file.txt", "w");
																  int n=cuad_cont;
																  int i;
																  for(i=0; i<n; i++)
																	fprintf(f, "%d %d %d %d\n", cuad1[i], cuad2[i], cuad3[i], cuad4[i]);	
																  fclose(f);;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 130 "proyecto.y"
    {;;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 133 "proyecto.y"
    {;;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 134 "proyecto.y"
    {;;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 137 "proyecto.y"
    {;;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 138 "proyecto.y"
    {;;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 139 "proyecto.y"
    {;;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 142 "proyecto.y"
    {for(cont=0; cont<=contab; cont++)
																if(Table_var[cont][0]==(yyvsp[(1) - (1)].id))
																	if(Table_var_mem[cont]<2000)
																	{
																		printf("error semantico\n asignacion a valor de entrada\n");
																	}
																	else
																	{
																		operandos++;
																		pilaOperandos[operandos]=Table_var_mem[cont];
																	}
															;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 154 "proyecto.y"
    {operadores++;pilaOperadores[operadores]=0;;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 156 "proyecto.y"
    {cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad3[cuad_cont]=-1;
															cuad4[cuad_cont]=pilaOperandos[operandos];operandos--;
															//operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 166 "proyecto.y"
    {fondo_falso++; pilaFondoFalso[fondo_falso]=pilaOperadores[operadores];;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 166 "proyecto.y"
    {fondo_falso--;;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 166 "proyecto.y"
    {operadores++;pilaOperadores[operadores]=15;
																																  cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																																  cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																																  cuad3[cuad_cont]=-1;
																																  cuad4[cuad_cont]=-1;
																																  cuad_cont++;
																																  saltos++;pilaSaltos[saltos]=cuad_cont-1;;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 173 "proyecto.y"
    {;;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 176 "proyecto.y"
    {cuad4[pilaSaltos[saltos]]=cuad_cont; saltos--;;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 177 "proyecto.y"
    {;;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 178 "proyecto.y"
    {operadores++;pilaOperadores[operadores]=13;
				   cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
				   cuad2[cuad_cont]=-1;
				   cuad3[cuad_cont]=-1;
				   cuad4[cuad_cont]=-1;
				   cuad_cont++;
				   cuad4[pilaSaltos[saltos]]=cuad_cont; saltos--;
				   saltos++;pilaSaltos[saltos]=cuad_cont-1;;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 186 "proyecto.y"
    {cuad4[pilaSaltos[saltos]]=cuad_cont; saltos--;;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 187 "proyecto.y"
    {;;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 190 "proyecto.y"
    {saltos++;pilaSaltos[saltos]=-5;
												for(cont=0; cont<=contab; cont++)
													if(Table_var[cont][0]==(yyvsp[(2) - (2)].id))
														if(Table_var_mem[cont]>1999&&Table_var_mem[cont]<3000)
														{
															printf("error semantico\n mal uso de variable de salida\n");
														}
														else
														{
															operandos++;
															pilaOperandos[operandos]=Table_var_mem[cont];
														}
												;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 203 "proyecto.y"
    {operandos--;
												cont_tranza=cuad_cont;
												while(cont_tranza>1)
												{	
													if(cuad1[cont_tranza]==13&&cuad4[cont_tranza]==-1)
													{
														cuad4[cont_tranza]=cuad_cont;
													}
													cont_tranza--;
												}
												//cuad4[pilaSaltos[saltos]]=cuad_cont;
												//saltos--;
												;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 216 "proyecto.y"
    {;;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 219 "proyecto.y"
    {while(pilaSaltos[saltos]!=-5)
												{	
													if(cuad1[pilaSaltos[saltos]]==14)
													{
														cuad4[pilaSaltos[saltos]]=cuad_cont+1;
													}
													saltos--;
												}
												cuad1[cuad_cont]=13;
												cuad2[cuad_cont]=-1;
												cuad3[cuad_cont]=-1;
												cuad4[cuad_cont]=-1;
												cuad_cont++;
												saltos++;pilaSaltos[saltos]=cuad_cont-1;
												;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 234 "proyecto.y"
    {if(flag==1)
													{
														cuad4[pilaSaltos[saltos]]=cuad_cont+1;
														saltos--;
														cuad1[cuad_cont]=13;
														cuad2[cuad_cont]=-1;
														cuad3[cuad_cont]=-1;
														cuad4[cuad_cont]=-1;
														cuad_cont++;
														saltos++;pilaSaltos[saltos]=cuad_cont-1;
													}
													flag=1;
												;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 247 "proyecto.y"
    {;;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 248 "proyecto.y"
    {;;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 251 "proyecto.y"
    {cuad1[cuad_cont]=1;
												cuad2[cuad_cont]=pilaOperandos[operandos];
												cuad3[cuad_cont]=(yyvsp[(1) - (1)].integer);
												cuad4[cuad_cont]=temp++;
												cuad_cont++;
												cuad1[cuad_cont]=14;
												cuad2[cuad_cont]=cuad4[cuad_cont-1];
												cuad3[cuad_cont]=-1;
												cuad4[cuad_cont]=-1;
												cuad_cont++;
												//operandos--;
												operandos++;pilaOperandos[operandos]=cuad2[cuad_cont-2];
												saltos++;pilaSaltos[saltos]=cuad_cont-1;
												;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 265 "proyecto.y"
    {cuad1[cuad_cont]=1;
												cuad2[cuad_cont]=pilaOperandos[operandos];
												cuad3[cuad_cont]=pilaOperandos[operandos];
												cuad4[cuad_cont]=temp++;
												cuad_cont++;
												cuad1[cuad_cont]=14;
												cuad2[cuad_cont]=cuad4[cuad_cont-1];
												cuad3[cuad_cont]=-1;
												cuad4[cuad_cont]=-1;
												cuad_cont++;
												//operandos--;
												operandos++;pilaOperandos[operandos]=cuad2[cuad_cont-2];
												saltos++;pilaSaltos[saltos]=cuad_cont-1;
												flag=0;;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 281 "proyecto.y"
    {;;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 284 "proyecto.y"
    {;;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 285 "proyecto.y"
    {operadores++;pilaOperadores[operadores]=1;;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 286 "proyecto.y"
    {cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad4[cuad_cont]=temp++;
															operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 293 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=4;;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 294 "proyecto.y"
    {cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad4[cuad_cont]=temp++;
															operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 301 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=5;;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 302 "proyecto.y"
    {cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad4[cuad_cont]=temp++;
															operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 309 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=6;;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 310 "proyecto.y"
    {cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
															cuad4[cuad_cont]=temp++;
															operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
															cuad_cont++;
															;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 319 "proyecto.y"
    {;;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 320 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=9;;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 321 "proyecto.y"
    {if(pilaOperadores[operadores]==7|pilaOperadores[operadores]==8|pilaOperadores[operadores]==9|pilaOperadores[operadores]==10)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=-1;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																};}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 331 "proyecto.y"
    {;;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 332 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=7;;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 333 "proyecto.y"
    {if(pilaOperadores[operadores]==7|pilaOperadores[operadores]==8|pilaOperadores[operadores]==9|pilaOperadores[operadores]==10)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																};}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 341 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=8;;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 342 "proyecto.y"
    {if(pilaOperadores[operadores]==7|pilaOperadores[operadores]==8|pilaOperadores[operadores]==9|pilaOperadores[operadores]==10)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																};}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 350 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=10;;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 351 "proyecto.y"
    {if(pilaOperadores[operadores]==7|pilaOperadores[operadores]==8|pilaOperadores[operadores]==9|pilaOperadores[operadores]==10)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																};}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 361 "proyecto.y"
    {;;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 364 "proyecto.y"
    {;;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 365 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=11;;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 366 "proyecto.y"
    {if(pilaOperadores[operadores]==11|pilaOperadores[operadores]==12)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																};}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 374 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=12;;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 375 "proyecto.y"
    {if(pilaOperadores[operadores]==11|pilaOperadores[operadores]==12)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																};}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 385 "proyecto.y"
    {;;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 388 "proyecto.y"
    {;;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 389 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=2;;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 390 "proyecto.y"
    {if(pilaOperadores[operadores]==3|pilaOperadores[operadores]==2)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																};}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 398 "proyecto.y"
    {operadores++; pilaOperadores[operadores]=3;;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 399 "proyecto.y"
    {if(pilaOperadores[operadores]==3|pilaOperadores[operadores]==2)
															{	cuad1[cuad_cont]=pilaOperadores[operadores];operadores--;
																cuad3[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad2[cuad_cont]=pilaOperandos[operandos];operandos--;
																cuad4[cuad_cont]=temp++;
																operandos++; pilaOperandos[operandos]=cuad4[cuad_cont];
																cuad_cont++;
																};}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 409 "proyecto.y"
    {fondo_falso++; pilaFondoFalso[fondo_falso]=pilaOperadores[operadores];;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 409 "proyecto.y"
    {fondo_falso--;;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 410 "proyecto.y"
    {;;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 413 "proyecto.y"
    {for(cont=0; cont<=contab; cont++)
																if(Table_var[cont][0]==(yyvsp[(1) - (1)].id))
																	if(Table_var_mem[cont]>1999&&Table_var_mem[cont]<3000)
																	{
																		printf("error semantico\n mal uso de variable de salida\n");
																	}
																	else
																	{
																		operandos++;
																		pilaOperandos[operandos]=Table_var_mem[cont];
																	}
															;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 425 "proyecto.y"
    {operandos++; pilaOperandos[operandos]=(yyvsp[(1) - (1)].integer);;}
    break;



/* Line 1464 of yacc.c  */
#line 2281 "proyecto.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 428 "proyecto.y"


int main(void)
{
	return yyparse();
}

void yyerror (char *s) {printf("%s\n", s);}
