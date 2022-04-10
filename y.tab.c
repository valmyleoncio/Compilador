/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;
int var_lace_qnt;

string error = "";
string warning = "";

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string valor;
	int linha;
};

typedef struct
{
	string nomeVariavel;
	string tipoVariavel; 
	string labelVariavel;
}	TIPO_SIMBOLO;

typedef struct
{
	string tipoVariavel; 
	string labelVariavel;
}	TIPO_TEMP;

vector<TIPO_SIMBOLO> tabelaSimbolos;
vector<vector<TIPO_SIMBOLO>> contexto;
vector<TIPO_TEMP> tabelaTemp;
string atribuicaoVariavel;

int yylex(void);
void yyerror(string);
string gentempcode();
string genLacecode();
void verificarVariavelRepetida(string variavel);
void verificarVariavelExistente(string nomeVariavel);
TIPO_SIMBOLO getSimbolo(string variavel);
void addSimbolo(string variavel, string tipo, string label);
void addTemp(string label, string tipo);
void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2);

#line 125 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_NUM = 258,
    TK_REAL = 259,
    TK_CHAR = 260,
    TK_TRUE = 261,
    TK_FALSE = 262,
    TK_MAIN = 263,
    TK_ID = 264,
    TK_TIPO_INT = 265,
    TK_TIPO_FLOAT = 266,
    TK_TIPO_CHAR = 267,
    TK_TIPO_BOOLEAN = 268,
    TK_MAIOR_IGUAL = 269,
    TK_MENOR_IGUAL = 270,
    TK_IGUAL_IGUAL = 271,
    TK_DIFERENTE = 272,
    TK_MAIS_MAIS = 273,
    TK_MENOS_MENOS = 274,
    TK_OU = 275,
    TK_E = 276,
    TK_IF = 277,
    TK_ELSE = 278,
    TK_WHILE = 279,
    TK_FOR = 280,
    TK_DO = 281,
    TK_SWITCH = 282,
    TK_CASE = 283,
    TK_BREAK = 284,
    TK_CONTINUE = 285,
    TK_ERROR = 286
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_TRUE 261
#define TK_FALSE 262
#define TK_MAIN 263
#define TK_ID 264
#define TK_TIPO_INT 265
#define TK_TIPO_FLOAT 266
#define TK_TIPO_CHAR 267
#define TK_TIPO_BOOLEAN 268
#define TK_MAIOR_IGUAL 269
#define TK_MENOR_IGUAL 270
#define TK_IGUAL_IGUAL 271
#define TK_DIFERENTE 272
#define TK_MAIS_MAIS 273
#define TK_MENOS_MENOS 274
#define TK_OU 275
#define TK_E 276
#define TK_IF 277
#define TK_ELSE 278
#define TK_WHILE 279
#define TK_FOR 280
#define TK_DO 281
#define TK_SWITCH 282
#define TK_CASE 283
#define TK_BREAK 284
#define TK_CONTINUE 285
#define TK_ERROR 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    46,     2,     2,
      33,    34,    44,    32,     2,    39,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    37,
      41,    43,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    74,    80,    84,    88,    98,   109,   120,
     130,   141,   151,   161,   173,   177,   187,   192,   197,   202,
     207,   213,   214,   221,   228,   235,   244,   284,   324,   331,
     338,   360,   378,   381,   384,   389,   397,   405,   413,   421,
     429,   437,   445,   452,   461,   491,   531,   591,   607,   612,
     618,   626,   634,   641,   648,   655
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_REAL", "TK_CHAR",
  "TK_TRUE", "TK_FALSE", "TK_MAIN", "TK_ID", "TK_TIPO_INT",
  "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOLEAN", "TK_MAIOR_IGUAL",
  "TK_MENOR_IGUAL", "TK_IGUAL_IGUAL", "TK_DIFERENTE", "TK_MAIS_MAIS",
  "TK_MENOS_MENOS", "TK_OU", "TK_E", "TK_IF", "TK_ELSE", "TK_WHILE",
  "TK_FOR", "TK_DO", "TK_SWITCH", "TK_CASE", "TK_BREAK", "TK_CONTINUE",
  "TK_ERROR", "'+'", "'('", "')'", "'{'", "'}'", "';'", "':'", "'-'",
  "'>'", "'<'", "'!'", "'='", "'*'", "'/'", "'%'", "$accept", "S", "BLOCO",
  "COMANDOS", "CASES", "CASE", "COMANDO", "E", "RELACIONAL", "ATRIBUICAO",
  "M", "P", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    43,    40,    41,   123,   125,    59,    58,    45,
      62,    60,    33,    61,    42,    47,    37
};
# endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    -5,    22,   -10,   -48,    -9,    -8,   192,   -48,   -48,
     -48,   -48,   -48,   -48,    -4,     2,     8,    20,    27,     4,
       5,     7,    -8,    15,   226,   226,   -48,    17,   192,    43,
     -48,   -48,    23,   -48,   -48,   -48,   226,    19,   226,    28,
     226,    29,    33,   226,   226,    -7,    30,    73,    48,    49,
     224,   330,   192,   -48,   226,   226,   226,   226,   226,   226,
     -48,   226,   226,   226,   226,     1,     1,     1,   330,   -48,
     232,   -48,   240,   -48,   -48,   262,   330,    51,    44,    54,
      57,    53,    64,   -48,   -48,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   -48,   -48,   -48,   -48,   -48,
     -48,    68,    -8,    66,   226,   226,    71,   124,   270,   192,
      -8,    72,   278,    84,    68,   -48,   158,   -48,   192,   226,
      78,   115,    83,    84,   192,   300,    68,   -48,   -48,   308,
     192,    85,   192,   -48,   -48,   192,   192,   318,    -8,   -48,
     192,   -48,   -48,   -48,   192,   192,    93,   -48,   -48,    87,
     -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    17,     2,    50,
      51,    52,    53,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,    17,     0,
      32,    33,    34,    48,    28,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    17,     4,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,    44,    22,
       0,    23,     0,    24,    25,     0,     0,    32,     0,     0,
       0,     0,     0,    49,     3,    37,    38,    39,    40,    41,
      42,    35,    36,    26,    27,    55,    45,    46,    47,    31,
      30,     0,     0,     0,     0,     0,     0,    17,     0,    17,
       0,    32,     0,    19,     0,     9,    17,    12,    17,     0,
       0,     0,     0,    19,    17,     0,     0,     6,    14,     0,
      17,     0,    17,    18,    11,    17,    17,     0,     0,    13,
      17,    16,    10,     8,    17,    17,     0,     7,    15,     0,
      20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,    -6,   -19,    16,   -48,   -48,   -12,   -43,    95,
     -48,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    26,    27,   122,   123,    28,    29,    30,    31,
      32,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    77,    78,     3,     9,    10,    11,    12,    13,    53,
      95,    37,    50,    51,    34,    35,    46,    39,    96,    97,
      98,     1,     4,     5,    68,     6,    70,     7,    72,    41,
      79,    75,    76,    84,    24,    38,    42,    43,    44,    36,
      45,    40,    85,    86,    87,    88,    89,    90,    47,    91,
      92,    93,    94,    52,    81,    63,    69,    54,    55,    56,
      57,   111,    64,    58,    59,    71,    73,    65,    66,    67,
      74,     9,    10,    11,    12,    13,    82,    14,    48,    49,
      60,    38,    40,    61,    62,   102,   105,    36,   115,   108,
     117,   103,    76,   112,   104,   107,   109,   127,   106,   128,
     110,    24,   125,     7,   118,   134,   113,   129,   124,   119,
      25,   139,   121,   141,   137,   130,   142,   143,   131,   132,
     136,   146,   149,   140,   150,   147,   148,     9,    10,    11,
      12,    13,   145,    14,    15,    16,    17,    18,     0,   133,
      80,     0,     0,     0,     0,     0,    19,   114,    20,    21,
      22,    23,     0,     0,     0,     0,     0,    24,     0,     7,
       0,     9,    10,    11,    12,    13,    25,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
      19,   126,    20,    21,    22,    23,     0,     0,     0,     0,
       0,    24,     0,     7,     0,     9,    10,    11,    12,    13,
      25,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    21,    22,    23,
       0,     0,     0,     0,     0,    24,     0,     7,     0,     9,
      10,    11,    12,    13,    25,    14,    48,    49,    54,    55,
      56,    57,     0,     0,    58,    59,    54,    55,    56,    57,
       0,     0,    58,    59,    54,    55,    56,    57,    83,    24,
      58,    59,     0,     0,    61,    62,    99,     0,    25,     0,
       0,     0,    61,    62,   100,     0,    54,    55,    56,    57,
      61,    62,    58,    59,    54,    55,    56,    57,     0,     0,
      58,    59,    54,    55,    56,    57,   101,     0,    58,    59,
       0,     0,    61,    62,     0,     0,     0,   116,     0,     0,
      61,    62,   120,     0,    54,    55,    56,    57,    61,    62,
      58,    59,    54,    55,    56,    57,     0,     0,    58,    59,
       0,     0,    54,    55,    56,    57,     0,   135,    58,    59,
      61,    62,   138,     0,    54,    55,    56,    57,    61,    62,
      58,    59,     0,     0,     0,   144,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,    62
};

static const yytype_int16 yycheck[] =
{
       6,    44,     9,     8,     3,     4,     5,     6,     7,    28,
       9,     9,    24,    25,    18,    19,    22,     9,    65,    66,
      67,    10,     0,    33,    36,    34,    38,    35,    40,     9,
      37,    43,    44,    52,    33,    33,     9,    33,    33,    43,
      33,    33,    54,    55,    56,    57,    58,    59,    33,    61,
      62,    63,    64,    36,    24,    32,    37,    14,    15,    16,
      17,   104,    39,    20,    21,    37,    37,    44,    45,    46,
      37,     3,     4,     5,     6,     7,     3,     9,    10,    11,
      37,    33,    33,    40,    41,    34,    33,    43,   107,   101,
     109,    37,   104,   105,    37,   101,   102,   116,    34,   118,
      34,    33,   114,    35,   110,   124,    35,   119,   114,    37,
      42,   130,    28,   132,   126,    37,   135,   136,     3,    36,
     126,   140,    29,    38,    37,   144,   145,     3,     4,     5,
       6,     7,   138,     9,    10,    11,    12,    13,    -1,   123,
      45,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      -1,     3,     4,     5,     6,     7,    42,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    -1,     3,     4,     5,     6,     7,
      42,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,     3,
       4,     5,     6,     7,    42,     9,    10,    11,    14,    15,
      16,    17,    -1,    -1,    20,    21,    14,    15,    16,    17,
      -1,    -1,    20,    21,    14,    15,    16,    17,    34,    33,
      20,    21,    -1,    -1,    40,    41,    34,    -1,    42,    -1,
      -1,    -1,    40,    41,    34,    -1,    14,    15,    16,    17,
      40,    41,    20,    21,    14,    15,    16,    17,    -1,    -1,
      20,    21,    14,    15,    16,    17,    34,    -1,    20,    21,
      -1,    -1,    40,    41,    -1,    -1,    -1,    37,    -1,    -1,
      40,    41,    34,    -1,    14,    15,    16,    17,    40,    41,
      20,    21,    14,    15,    16,    17,    -1,    -1,    20,    21,
      -1,    -1,    14,    15,    16,    17,    -1,    37,    20,    21,
      40,    41,    34,    -1,    14,    15,    16,    17,    40,    41,
      20,    21,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    48,     8,     0,    33,    34,    35,    49,     3,
       4,     5,     6,     7,     9,    10,    11,    12,    13,    22,
      24,    25,    26,    27,    33,    42,    49,    50,    53,    54,
      55,    56,    57,    58,    18,    19,    43,     9,    33,     9,
      33,     9,     9,    33,    33,    33,    49,    33,    10,    11,
      54,    54,    36,    50,    14,    15,    16,    17,    20,    21,
      37,    40,    41,    32,    39,    44,    45,    46,    54,    37,
      54,    37,    54,    37,    37,    54,    54,    55,     9,    37,
      56,    24,     3,    34,    50,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,     9,    58,    58,    58,    34,
      34,    34,    34,    37,    37,    33,    34,    49,    54,    49,
      34,    55,    54,    35,    23,    50,    37,    50,    49,    37,
      34,    28,    51,    52,    49,    54,    23,    50,    50,    54,
      37,     3,    36,    51,    50,    37,    49,    54,    34,    50,
      38,    50,    50,    50,    37,    49,    50,    50,    50,    29,
      37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      52,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     2,     1,     7,    10,     9,     6,
       9,     8,     6,     8,     7,    10,     8,     0,     2,     0,
       6,     2,     3,     3,     3,     3,     3,     3,     2,     2,
       4,     4,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 69 "sintatica.y"
                        {
				cout << "\n/*Compilador SDDSEAD*/\n\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << atribuicaoVariavel + "\n" + yyvsp[0].traducao << "\treturn 0;\n}" << endl; 
			}
#line 1549 "y.tab.c"
    break;

  case 3:
#line 75 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
			}
#line 1557 "y.tab.c"
    break;

  case 4:
#line 81 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1565 "y.tab.c"
    break;

  case 5:
#line 85 "sintatica.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 1573 "y.tab.c"
    break;

  case 6:
#line 89 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-4].tipo);

				yyval.traducao = yyvsp[-4].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-4].label + ";\n" + "\t"
				"IF(" + yyval.label + ") goto FIM_IF" + "\n" + 
				yyvsp[-2].traducao + "\tFIM_IF\n" + yyvsp[0].traducao;
			}
#line 1587 "y.tab.c"
    break;

  case 7:
#line 99 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-7].tipo);

				yyval.traducao = yyvsp[-7].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-7].label + ";\n" + "\t"
				"IF(" + yyval.label + ") goto ELSE" + "\n" + 
				yyvsp[-5].traducao + "\tgoto FIM_IF\n" + "\tELSE\n" + yyvsp[-2].traducao
				+ "\t" + "FIM_IF\n" + yyvsp[0].traducao;
			}
#line 1602 "y.tab.c"
    break;

  case 8:
#line 110 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-6].tipo);

				yyval.traducao = yyvsp[-6].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-6].label + ";\n" + "\t"
				"IF(" + yyval.label + ") goto ELSE\n" + yyvsp[-4].traducao
				+ "\tgoto FIM_IF\n" + "\tELSE\n" + yyvsp[-1].traducao + "\tFIM_IF\n" +
				yyvsp[0].traducao;
			}
#line 1617 "y.tab.c"
    break;

  case 9:
#line 121 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-3].tipo);

				yyval.traducao = yyvsp[-3].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-3].label + ";\n" + "\t"
				"IF(" + yyval.label + ") goto FIM_IF" + "\n"
				+ yyvsp[-1].traducao + "\tFIM_IF\n" + yyvsp[0].traducao;
			}
#line 1631 "y.tab.c"
    break;

  case 10:
#line 131 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-6].tipo);

				yyval.traducao = yyvsp[-6].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-6].label + ";\n" + "\t"
				"IF(" + yyval.label + ") goto ELSE\n" + yyvsp[-4].traducao +
				"\tgoto FIM_IF\n" + "\tELSE\n" + yyvsp[-2].traducao
				+ "\t" + "FIM_IF\n" + yyvsp[0].traducao ;
			}
#line 1646 "y.tab.c"
    break;

  case 11:
#line 142 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-5].tipo);

				yyval.traducao = yyvsp[-5].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-5].label + ";\n" + "\t"
				"IF(" + yyval.label + ") goto ELSE\n" + yyvsp[-3].traducao +
				"\tgoto FIM_IF\n" + "\tELSE\n" + yyvsp[-1].traducao + "\tFIM_IF\n" + yyvsp[0].traducao;
			}
#line 1660 "y.tab.c"
    break;

  case 12:
#line 152 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-3].tipo);
				string lace = genLacecode();

				yyval.traducao = lace + yyvsp[-3].traducao + "\t" + yyval.label + " = !" +
				yyvsp[-3].label + ";\n" + "\tIF(" + yyval.label + ") goto FIM_IF\n" +
				yyvsp[-1].traducao + "\tgoto " + lace + "\n\tFIM_IF\n" + yyvsp[0].traducao;
			}
#line 1674 "y.tab.c"
    break;

  case 13:
#line 162 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-3].tipo);
				string lace = genLacecode();
				
				yyval.traducao = lace + "\t" + yyvsp[-7].traducao +"\n" 
				+ yyvsp[-6].traducao + yyvsp[-3].traducao + "\t" + yyval.label + " = !" 
				+ yyvsp[-3].label + ";\n"
				+ "\tIF(" + yyval.label +") goto FIM_IF\n" + "\tgoto " + lace
				+ "\n\tFIM_IF\n"+ yyvsp[0].traducao;
			}
#line 1690 "y.tab.c"
    break;

  case 14:
#line 174 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1698 "y.tab.c"
    break;

  case 15:
#line 178 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, yyvsp[-5].tipo);
				string lace = genLacecode();

				yyval.traducao = yyvsp[-7].traducao + lace + yyvsp[-5].traducao + "\t" + yyval.label + 
				" = !" + yyvsp[-5].label + ";\n\t" + "IF(" + yyval.label + ") goto FIM_IF\n" + 
				yyvsp[-1].traducao + yyvsp[-3].traducao + "\tgoto " + lace + "\n\tFIM_IF\n" + yyvsp[0].traducao;
			}
#line 1712 "y.tab.c"
    break;

  case 16:
#line 188 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao + yyvsp[0].traducao;
			}
#line 1720 "y.tab.c"
    break;

  case 17:
#line 192 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1728 "y.tab.c"
    break;

  case 18:
#line 198 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1736 "y.tab.c"
    break;

  case 19:
#line 202 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1744 "y.tab.c"
    break;

  case 20:
#line 208 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao;
			}
#line 1752 "y.tab.c"
    break;

  case 22:
#line 215 "sintatica.y"
                        {
				verificarVariavelRepetida(yyvsp[-1].label);
				addSimbolo(yyvsp[-1].label, "int", gentempcode());
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1763 "y.tab.c"
    break;

  case 23:
#line 222 "sintatica.y"
                        {
				verificarVariavelRepetida(yyvsp[-1].label);
				addSimbolo(yyvsp[-1].label, "float", gentempcode());
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1774 "y.tab.c"
    break;

  case 24:
#line 229 "sintatica.y"
                        {
				verificarVariavelRepetida(yyvsp[-1].label);
				addSimbolo(yyvsp[-1].label, "char", gentempcode());
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1785 "y.tab.c"
    break;

  case 25:
#line 236 "sintatica.y"
                        {
				verificarVariavelRepetida(yyvsp[-1].label);
				addSimbolo(yyvsp[-1].label, "boolean", gentempcode());
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1796 "y.tab.c"
    break;

  case 26:
#line 245 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " + " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " + " + labelAux + ";\n";
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string(yyvsp[0].linha) +  ":\033[0m\033[1;39m Operandos com tipos inválidos.");
				}
			}
#line 1840 "y.tab.c"
    break;

  case 27:
#line 285 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " - " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " - " + labelAux + ";\n";
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string(yyvsp[0].linha) +  ":\033[0m\033[1;39m Operandos com tipos inválidos.");
				}
			}
#line 1884 "y.tab.c"
    break;

  case 28:
#line 325 "sintatica.y"
                        {
				verificarVariavelExistente(yyvsp[-1].label);
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-1].label);
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}
#line 1895 "y.tab.c"
    break;

  case 29:
#line 332 "sintatica.y"
                        {
				verificarVariavelExistente(yyvsp[-1].label);
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-1].label);
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " - 1" + ";\n";
			}
#line 1906 "y.tab.c"
    break;

  case 30:
#line 339 "sintatica.y"
                        {		
				yyval.label = gentempcode();
				yyval.tipo  = "float";

				addTemp(yyval.label, yyval.tipo);
				
				if(yyvsp[-1].tipo == "int")
				{	
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(float) " + yyvsp[-1].label + ";\n";  
				} else if (yyvsp[-1].tipo == "float")
				{
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(float) " + yyvsp[-1].label + ";\n";
					cout << "\n\033[1;33mWarning\033[0m - Linha " + std::to_string(yyvsp[-1].linha) +  ": Muleque burro, ja é o tipo certo.\n";
				}
				else
				{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string(yyvsp[-1].linha) +  ": Casting inválido");
				}
			}
#line 1932 "y.tab.c"
    break;

  case 31:
#line 361 "sintatica.y"
                        {	
				yyval.label = gentempcode();
				yyval.tipo  = "int";
				addTemp(yyval.label, yyval.tipo);

				if(yyvsp[-1].tipo == "float")
				{
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(int) " + yyvsp[-1].label + ";\n";
				} else if (yyvsp[-1].tipo == "int"){
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(int) " + yyvsp[-1].label + ";\n";
					cout << "\n\033[1;33mWarning\033[0m - Linha " + std::to_string(yyvsp[-1].linha) +  ": Muleque burro, ja é o tipo certo.\n";
				}else{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string(yyvsp[-1].linha) +  ": Casting inválido");
				}
			}
#line 1954 "y.tab.c"
    break;

  case 32:
#line 379 "sintatica.y"
                        {
			}
#line 1961 "y.tab.c"
    break;

  case 33:
#line 382 "sintatica.y"
                        {
			}
#line 1968 "y.tab.c"
    break;

  case 34:
#line 385 "sintatica.y"
                        {
			}
#line 1975 "y.tab.c"
    break;

  case 35:
#line 390 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
			}
#line 1987 "y.tab.c"
    break;

  case 36:
#line 398 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
			}
#line 1999 "y.tab.c"
    break;

  case 37:
#line 406 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
			}
#line 2011 "y.tab.c"
    break;

  case 38:
#line 414 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
			}
#line 2023 "y.tab.c"
    break;

  case 39:
#line 422 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
			}
#line 2035 "y.tab.c"
    break;

  case 40:
#line 430 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
			}
#line 2047 "y.tab.c"
    break;

  case 41:
#line 438 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
			}
#line 2059 "y.tab.c"
    break;

  case 42:
#line 446 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
			}
#line 2070 "y.tab.c"
    break;

  case 43:
#line 453 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + "!" + yyvsp[0].label + ";\n";
			}
#line 2081 "y.tab.c"
    break;

  case 44:
#line 462 "sintatica.y"
                        {
				verificarVariavelExistente(yyvsp[-2].label);
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[-2].label);
				if(variavel.tipoVariavel == yyvsp[0].tipo){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				    variavel.labelVariavel + " = " + yyvsp[0].label + ";\n";
				}
				else if (variavel.tipoVariavel == "int" & yyvsp[0].tipo == "float")
				{
					yyval.label = gentempcode();
					addTemp(yyval.label, "int");
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (int) " + yyvsp[0].label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + yyval.label + ";\n";
				}
				else if (variavel.tipoVariavel == "float" & yyvsp[0].tipo == "int")
				{
					yyval.label = gentempcode();
					addTemp(yyval.label, "float");
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + yyval.label + ";\n";
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string(yyvsp[0].linha) +  ": Atribuição inválida, tipos diferentes.");
				}
			}
#line 2113 "y.tab.c"
    break;

  case 45:
#line 492 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " * " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " * " + labelAux + ";\n";
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string(yyvsp[0].linha) +  ":\033[0m\033[1;39m Operandos com tipos inválidos.");
				}
			}
#line 2157 "y.tab.c"
    break;

  case 46:
#line 532 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " / " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " / " + labelAux + ";\n";
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string(yyvsp[0].linha) +  ":\033[0m\033[1;39m Operandos com tipos inválidos.");
				}

				string aux = yyvsp[0].valor;
				int cont = 0;
				int ponto = 0;

				for(int i = 0; i < aux.size(); i++)
				{
					if(aux[i] == '.')
					{
						ponto = 1;
					}
					if(aux[i] == '0')
					{
						cont++;
					}
				}

				if(cont == aux.size() || (cont + ponto) == aux.size()){
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string(yyvsp[0].linha) +  ":\033[0m\033[1;39m Operação inválida, divisão por 0.");
				}
			}
#line 2221 "y.tab.c"
    break;

  case 47:
#line 592 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "int"){
					tipoAux = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " % " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, tipoAux);
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string(yyvsp[0].linha) +  ":\033[0m\033[1;39m Operandos inválidos para %, ( ou presença de float).");
				}
			}
#line 2241 "y.tab.c"
    break;

  case 48:
#line 608 "sintatica.y"
                        {
			}
#line 2248 "y.tab.c"
    break;

  case 49:
#line 613 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
				yyval.tipo = yyvsp[-1].tipo;
				yyval.label = yyvsp[-1].label;
			}
#line 2258 "y.tab.c"
    break;

  case 50:
#line 619 "sintatica.y"
                        {
				yyval.tipo = "int";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				yyval.valor = yyvsp[0].label;
			}
#line 2270 "y.tab.c"
    break;

  case 51:
#line 627 "sintatica.y"
                        {
				yyval.tipo = "float";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				yyval.valor = yyvsp[0].label;
			}
#line 2282 "y.tab.c"
    break;

  case 52:
#line 635 "sintatica.y"
                        {
				yyval.tipo = "char";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2293 "y.tab.c"
    break;

  case 53:
#line 642 "sintatica.y"
                        {
				yyval.tipo = "boolean";
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";	
			}
#line 2304 "y.tab.c"
    break;

  case 54:
#line 649 "sintatica.y"
                        {
				yyval.tipo = "boolean";
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";		
			}
#line 2315 "y.tab.c"
    break;

  case 55:
#line 656 "sintatica.y"
                        {
				bool encontrei = false;
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[0].label);
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == yyvsp[0].label)
					{
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}	
				}

				if(!encontrei)
				{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string(yyvsp[0].linha) +  ": A variavel '" + yyvsp[0].label + "' não foi instanciada.");
				}

				yyval.tipo = variavel.tipoVariavel;
				yyval.label = variavel.labelVariavel;
				yyval.traducao = "";
			}
#line 2340 "y.tab.c"
    break;


#line 2344 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 677 "sintatica.y"


#include "lex.yy.c"

int yyparse();

string gentempcode(){
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);	
}

string genLacecode(){
	var_lace_qnt++;
	return "_L" + std::to_string(var_lace_qnt);	
}

void verificarVariavelRepetida(string variavel){

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
		{
			yyerror("Variável ja existente");
		}
	}
}

void verificarVariavelExistente(string nomeVariavel){
	bool result = false;
	for (int i = 0; i < tabelaSimbolos.size(); i++){
		if(tabelaSimbolos[i].nomeVariavel == nomeVariavel){
			result = true;
		}
	}
	
	if(!result)	{
		yyerror("\n\033[1;31mError\033[0m - Linha : A variável '" + nomeVariavel + "' não foi instanciada");

	}
}

TIPO_SIMBOLO getSimbolo(string variavel){
	for (int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
			return tabelaSimbolos[i];					
	}
}

void addSimbolo(string variavel, string tipo, string label){
	TIPO_SIMBOLO valor;
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;
	tabelaSimbolos.push_back(valor);
	if(valor.tipoVariavel == "boolean"){
		valor.tipoVariavel = "int";
	}
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void addTemp(string label, string tipo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = tipo;
	tabelaTemp.push_back(valor);
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2){
	if(tipo_1.tipo == "char" || tipo_2.tipo == "char")
	{
		yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string(tipo_1.linha) +  ": Operação relacional inválida.");
	}
}

int main(int argc, char* argv[]){
	var_temp_qnt = 0;
	yyparse();
	return 0;
}

void yyerror(string MSG){
	cout << MSG << endl;
	exit (0);
}
