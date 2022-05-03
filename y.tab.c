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
#include <array>
#include <iterator>
#include <algorithm>

#define YYSTYPE atributos

using namespace std;

int mainStatus = 0;
int var_temp_qnt;
int var_lace_qnt;
int var_cond_qnt;
int var_linha_qnt = 1;
int var_lace_name_qnt = 0;
int controleLoop = 0;
int controleFunction = 0;

string error = "";
string warning = "";
string contLinha = "1";

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string valor;
	string index;
};

typedef struct
{
	string nomeVariavel;
	string tipoVariavel; 
	string labelVariavel;
	string valorVariavel;
}	TIPO_SIMBOLO;

typedef struct
{
	string tipoVariavel; 
	string labelVariavel;
	string valor;
}	TIPO_TEMP;

typedef struct
{
	string nomeLaco;
	string tipoLaco;
	string fimLaco;
	string inicioLaco;
	int contexto;
}	TIPO_LOOP;

typedef struct
{
	string nomeFunction;
	string tipoReturn;
	string inicioFunction;
	string fimFunction;
	vector<TIPO_SIMBOLO> parameters;
	string retornoTipo = "";
	string retornoLabel = "";
}	TIPO_FUNCTION;

vector<TIPO_LOOP> tabelaLoop;
vector<TIPO_FUNCTION> tabelaFunction;
vector<TIPO_SIMBOLO> parametersChamada;
vector<vector<TIPO_SIMBOLO>> mapa;
int contextoGlobal;
vector<TIPO_TEMP> tabelaTemp;
string atribuicaoVariavel;
string atribuicaoVariavelGlobais;
string traducaoFunction;

int yylex(void);
void yyerror(string);
int getContexto();
string gentempcode();
string genLacecode();
string genCondcode();
string genLaceNameCode();
void verificarVariavelRepetida(string variavel);
TIPO_SIMBOLO getSimbolo(string variavel);
void addSimbolo(string variavel, string tipo, string label);
void addString(string variavel, string tipo, string label);
int addTempString(string label, string tipo);
int getSize(string str);
void addTemp(string label, string tipo);
void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2);
void atualizarContexto(int num);
void contadorDeLinha();
void pushContexto();
void popContexto();
void pushLoop(string tipo);
void pushFunction();
TIPO_FUNCTION getFunction();
TIPO_LOOP getLace(string nome);
TIPO_LOOP getLaceBreak();
TIPO_FUNCTION getFunctionChamada(string nome);
void verificarAtributoRelacional(atributos tipo_1);

#line 178 "y.tab.c"

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
    TK_STRING = 263,
    TK_VOID = 264,
    TK_FUNCTION = 265,
    TK_MAIN = 266,
    TK_ID = 267,
    TK_TIPO_INT = 268,
    TK_TIPO_FLOAT = 269,
    TK_TIPO_CHAR = 270,
    TK_TIPO_BOOLEAN = 271,
    TK_TIPO_STRING = 272,
    TK_MAIOR_IGUAL = 273,
    TK_MENOR_IGUAL = 274,
    TK_IGUAL_IGUAL = 275,
    TK_DIFERENTE = 276,
    TK_MAIS_MAIS = 277,
    TK_MENOS_MENOS = 278,
    TK_OU = 279,
    TK_E = 280,
    TK_MAIS_IGUAL = 281,
    TK_MENOS_IGUAL = 282,
    TK_IF = 283,
    TK_ELSE = 284,
    TK_WHILE = 285,
    TK_FOR = 286,
    TK_DO = 287,
    TK_SWITCH = 288,
    TK_CASE = 289,
    TK_BREAK = 290,
    TK_CONTINUE = 291,
    TK_PRINT = 292,
    TK_SCAN = 293,
    TK_RETURN = 294,
    TK_ERROR = 295
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_TRUE 261
#define TK_FALSE 262
#define TK_STRING 263
#define TK_VOID 264
#define TK_FUNCTION 265
#define TK_MAIN 266
#define TK_ID 267
#define TK_TIPO_INT 268
#define TK_TIPO_FLOAT 269
#define TK_TIPO_CHAR 270
#define TK_TIPO_BOOLEAN 271
#define TK_TIPO_STRING 272
#define TK_MAIOR_IGUAL 273
#define TK_MENOR_IGUAL 274
#define TK_IGUAL_IGUAL 275
#define TK_DIFERENTE 276
#define TK_MAIS_MAIS 277
#define TK_MENOS_MENOS 278
#define TK_OU 279
#define TK_E 280
#define TK_MAIS_IGUAL 281
#define TK_MENOS_IGUAL 282
#define TK_IF 283
#define TK_ELSE 284
#define TK_WHILE 285
#define TK_FOR 286
#define TK_DO 287
#define TK_SWITCH 288
#define TK_CASE 289
#define TK_BREAK 290
#define TK_CONTINUE 291
#define TK_PRINT 292
#define TK_SCAN 293
#define TK_RETURN 294
#define TK_ERROR 295

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   541

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
       2,     2,     2,    52,     2,     2,     2,    56,     2,     2,
      42,    43,    54,    41,    45,    49,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    44,
      51,    53,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   130,   133,   137,   142,   160,   177,   181,
     185,   188,   193,   199,   203,   207,   225,   242,   259,   277,
     290,   302,   313,   324,   332,   343,   348,   353,   358,   363,
     368,   371,   374,   384,   393,   406,   499,   503,   507,   511,
     515,   519,   525,   571,   611,   620,   629,   651,   669,   672,
     675,   714,   720,   725,   729,   738,   749,   757,   765,   773,
     781,   789,   797,   805,   813,   822,   881,   921,   981,   997,
    1003,  1009,  1017,  1025,  1032,  1039,  1046,  1053,  1060,  1064
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_REAL", "TK_CHAR",
  "TK_TRUE", "TK_FALSE", "TK_STRING", "TK_VOID", "TK_FUNCTION", "TK_MAIN",
  "TK_ID", "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_CHAR",
  "TK_TIPO_BOOLEAN", "TK_TIPO_STRING", "TK_MAIOR_IGUAL", "TK_MENOR_IGUAL",
  "TK_IGUAL_IGUAL", "TK_DIFERENTE", "TK_MAIS_MAIS", "TK_MENOS_MENOS",
  "TK_OU", "TK_E", "TK_MAIS_IGUAL", "TK_MENOS_IGUAL", "TK_IF", "TK_ELSE",
  "TK_WHILE", "TK_FOR", "TK_DO", "TK_SWITCH", "TK_CASE", "TK_BREAK",
  "TK_CONTINUE", "TK_PRINT", "TK_SCAN", "TK_RETURN", "TK_ERROR", "'+'",
  "'('", "')'", "';'", "','", "'{'", "'}'", "':'", "'-'", "'>'", "'<'",
  "'!'", "'='", "'*'", "'/'", "'%'", "$accept", "S", "FUNSSAO",
  "DECLAFUNC", "PARAMETERS", "PARAMETER", "BLOCO", "COMANDOS", "CASES",
  "CASE", "COMANDO", "DECLARACAO", "TIPOS", "E", "CHAMADAS", "CHAMADA",
  "RELACIONAL", "ATRIBUICAO", "M", "P", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    43,    40,    41,    59,    44,   123,   125,    58,    45,
      62,    60,    33,    61,    42,    47,    37
};
# endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     209,   -91,   184,   -50,     6,   -91,   -91,   -91,   -91,    18,
     209,   -23,   -14,    19,    -3,   -91,    40,   312,    14,   -91,
     -91,   184,   209,   -91,   209,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,    11,    15,    21,    25,    28,   312,   312,   490,
     -91,   -91,    24,   -91,    29,    31,   -91,    13,   -91,   -91,
     -91,   -91,   312,   312,   312,   312,    64,   -11,   490,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   131,
     131,   131,    35,    35,   184,    96,    39,   -91,   310,   338,
     347,    47,   -91,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   -91,   -91,   -91,   -91,   250,   -91,   -91,
     -91,   312,   -91,   -91,   -91,   -91,   -91,    15,    21,    49,
      50,    52,    35,    54,    57,    58,   312,   250,    56,   250,
      60,   355,   -91,   312,   312,    16,    75,   131,   -91,   -91,
     383,   -91,   -91,   -91,   -91,   -91,   392,   401,    65,    66,
      69,    70,   -91,   300,    35,    76,   312,   312,    62,   150,
     429,   250,    35,   490,    74,   438,    88,   300,   -91,   200,
     -91,   250,   312,    79,   122,    81,    88,   250,   446,   300,
     -91,   -91,   474,   250,    83,   250,   -91,   -91,   250,   250,
     482,    35,   -91,   250,   -91,   -91,   -91,   250,   250,   -91,
     -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    41,     0,     0,    36,    37,    38,    40,    39,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     1,
       5,     9,     0,    35,     0,     7,    71,    72,    73,    75,
      76,    74,    77,     0,     0,     0,     0,     0,     0,    65,
      48,    49,    51,    69,     0,     0,     8,    10,     3,     4,
      44,    45,    53,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,    52,     0,     0,
       0,     0,    70,    58,    59,    60,    61,    62,    63,    56,
      57,    42,    43,    77,    66,    67,    68,    26,     2,     6,
      11,     0,    50,    47,    46,    78,    79,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    26,
       0,     0,    55,     0,     0,     0,     0,     0,    32,    33,
       0,    14,    12,    13,    31,    30,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,    26,
       0,    26,     0,     0,    48,     0,    28,     0,    18,    26,
      21,    26,     0,     0,     0,     0,    28,    26,     0,     0,
      15,    23,     0,    26,     0,    26,    27,    20,    26,    26,
       0,     0,    22,    26,    25,    19,    17,    26,    26,    29,
      16,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,    44,   -91,   -91,   -91,    59,   -57,   -90,   -34,   -91,
     -91,     1,   140,   -17,   -91,    43,     3,     2,   -91,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    45,    46,   117,   118,   165,   166,
     119,   120,    13,   121,    76,    77,    40,    41,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    12,    14,    17,    94,    95,    96,    59,    60,    61,
      62,    12,    14,    63,    64,    98,    99,    18,    19,    21,
      57,    58,    47,    12,    14,    12,    14,   131,     3,   133,
      22,    23,    82,    50,    51,    75,    78,    79,    80,    65,
      66,    24,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    25,    52,    20,   126,    44,    53,    74,   158,
     138,   160,   141,    54,    17,    67,    48,    55,    49,   170,
      56,   171,    72,    68,    73,    47,    81,   177,    69,    70,
      71,    97,   102,   182,    75,   184,   149,   151,   185,   186,
     106,   123,   124,   189,   125,   161,   127,   190,   191,   130,
     167,   128,   129,   132,   134,   140,   136,   137,   156,   145,
     146,   147,   179,   148,    59,    60,    61,    62,   162,   152,
      63,    64,   164,   173,   188,   174,   150,   139,   175,   153,
     155,   183,   176,   100,    26,    27,    28,    29,    30,    31,
     168,   101,    16,    93,   122,   172,    65,    66,     0,   154,
       0,     0,   180,    26,    27,    28,    29,    30,    31,     1,
       0,     0,    32,   107,   108,     6,     7,     8,    35,    36,
       0,     0,     0,    37,     0,     0,     0,     0,   109,   157,
     110,   111,   112,   113,     0,   114,   115,    35,    36,   116,
       0,     0,    37,     1,     0,     0,    97,    15,     5,     6,
       7,     8,    38,    26,    27,    28,    29,    30,    31,     1,
       0,     0,    32,   107,   108,     6,     7,     8,     1,     2,
       0,     3,     4,     5,     6,     7,     8,     0,   109,   169,
     110,   111,   112,   113,     0,   114,   115,    35,    36,   116,
       0,     0,    37,     0,     0,     0,    97,     0,     0,     0,
       0,     0,    38,    26,    27,    28,    29,    30,    31,     1,
       0,     0,    32,   107,   108,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
     110,   111,   112,   113,     0,   114,   115,    35,    36,   116,
       0,     0,    37,     0,     0,     0,    97,     0,     0,     0,
       0,     0,    38,    26,    27,    28,    29,    30,    31,     0,
       0,     0,    32,    33,    34,    26,    27,    28,    29,    30,
      31,     0,     0,     0,    32,    33,    34,     0,    59,    60,
      61,    62,     0,     0,    63,    64,     0,    35,    36,     0,
       0,     0,    37,     0,     0,     0,    97,     0,     0,    35,
      36,     0,    38,   103,    37,     0,    59,    60,    61,    62,
      65,    66,    63,    64,    38,    59,    60,    61,    62,     0,
       0,    63,    64,    59,    60,    61,    62,     0,     0,    63,
      64,   104,     0,     0,     0,     0,     0,     0,    65,    66,
     105,     0,     0,     0,     0,     0,     0,    65,    66,   135,
       0,    59,    60,    61,    62,    65,    66,    63,    64,     0,
      59,    60,    61,    62,     0,     0,    63,    64,     0,    59,
      60,    61,    62,     0,     0,    63,    64,   142,     0,     0,
       0,     0,     0,    65,    66,   143,     0,     0,     0,     0,
       0,     0,    65,    66,   144,     0,     0,    59,    60,    61,
      62,    65,    66,    63,    64,     0,    59,    60,    61,    62,
       0,     0,    63,    64,    59,    60,    61,    62,     0,     0,
      63,    64,     0,   159,     0,     0,     0,     0,     0,    65,
      66,   163,     0,     0,     0,     0,     0,     0,    65,    66,
     178,     0,    59,    60,    61,    62,    65,    66,    63,    64,
      59,    60,    61,    62,     0,     0,    63,    64,    59,    60,
      61,    62,     0,     0,    63,    64,     0,   181,     0,     0,
       0,     0,     0,     0,    65,    66,   187,     0,     0,     0,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
      65,    66
};

static const yytype_int16 yycheck[] =
{
      17,     0,     0,    53,    69,    70,    71,    18,    19,    20,
      21,    10,    10,    24,    25,    72,    73,    11,     0,    42,
      37,    38,    21,    22,    22,    24,    24,   117,    12,   119,
      44,    12,    43,    22,    23,    52,    53,    54,    55,    50,
      51,    44,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    12,    42,    10,   112,    42,    42,    45,   149,
      44,   151,   127,    42,    53,    41,    22,    42,    24,   159,
      42,   161,    43,    49,    43,    74,    12,   167,    54,    55,
      56,    46,    43,   173,   101,   175,   143,   144,   178,   179,
      43,    42,    42,   183,    42,   152,    42,   187,   188,   116,
     157,    44,    44,    47,    44,    30,   123,   124,    46,    44,
      44,    42,   169,    43,    18,    19,    20,    21,    44,    43,
      24,    25,    34,    44,   181,     3,   143,   125,    47,   146,
     147,    48,   166,    74,     3,     4,     5,     6,     7,     8,
     157,    45,     2,    12,   101,   162,    50,    51,    -1,   146,
      -1,    -1,   169,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    14,    15,    16,    17,    37,    38,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    42,     9,    -1,    -1,    46,    13,    14,    15,
      16,    17,    52,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    14,    15,    16,    17,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    -1,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    52,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    52,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    13,    14,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    -1,    18,    19,
      20,    21,    -1,    -1,    24,    25,    -1,    37,    38,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    37,
      38,    -1,    52,    43,    42,    -1,    18,    19,    20,    21,
      50,    51,    24,    25,    52,    18,    19,    20,    21,    -1,
      -1,    24,    25,    18,    19,    20,    21,    -1,    -1,    24,
      25,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    44,
      -1,    18,    19,    20,    21,    50,    51,    24,    25,    -1,
      18,    19,    20,    21,    -1,    -1,    24,    25,    -1,    18,
      19,    20,    21,    -1,    -1,    24,    25,    44,    -1,    -1,
      -1,    -1,    -1,    50,    51,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    43,    -1,    -1,    18,    19,    20,
      21,    50,    51,    24,    25,    -1,    18,    19,    20,    21,
      -1,    -1,    24,    25,    18,    19,    20,    21,    -1,    -1,
      24,    25,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,
      51,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      44,    -1,    18,    19,    20,    21,    50,    51,    24,    25,
      18,    19,    20,    21,    -1,    -1,    24,    25,    18,    19,
      20,    21,    -1,    -1,    24,    25,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    44,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    12,    13,    14,    15,    16,    17,    58,
      59,    60,    68,    69,    74,    13,    69,    53,    11,     0,
      58,    42,    44,    12,    44,    12,     3,     4,     5,     6,
       7,     8,    12,    13,    14,    37,    38,    42,    52,    70,
      73,    74,    75,    76,    42,    61,    62,    68,    58,    58,
      22,    23,    42,    42,    42,    42,    42,    70,    70,    18,
      19,    20,    21,    24,    25,    50,    51,    41,    49,    54,
      55,    56,    43,    43,    45,    70,    71,    72,    70,    70,
      70,    12,    43,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    12,    76,    76,    76,    46,    63,    63,
      62,    45,    43,    43,    43,    43,    43,    13,    14,    28,
      30,    31,    32,    33,    35,    36,    39,    63,    64,    67,
      68,    70,    72,    42,    42,    42,    63,    42,    44,    44,
      70,    64,    47,    64,    44,    44,    70,    70,    44,    74,
      30,    76,    44,    43,    43,    44,    44,    42,    43,    63,
      70,    63,    43,    70,    73,    70,    46,    29,    64,    44,
      64,    63,    44,    43,    34,    65,    66,    63,    70,    29,
      64,    64,    70,    44,     3,    47,    65,    64,    44,    63,
      70,    43,    64,    48,    64,    64,    64,    44,    63,    64,
      64,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    59,    60,    61,    61,
      62,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      67,    67,    67,    67,    67,    68,    69,    69,    69,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     3,     2,     5,     3,     1,     0,
       1,     3,     3,     2,     2,     7,    10,     9,     6,     9,
       8,     6,     8,     7,    10,     8,     0,     2,     0,     4,
       2,     2,     2,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     2,     4,     4,     1,     1,
       4,     1,     1,     0,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     4
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
#line 122 "sintatica.y"
                        {
				if(error == "")
					cout << "\n/*Compilador SDDSEAD*/\n\n" + warning + "\n"<< "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n" + atribuicaoVariavelGlobais + "\n" + traducaoFunction  + "\nint main(void)\n{\n" <<  atribuicaoVariavel + "\n" + yyvsp[0].traducao << "\treturn 0;\n}" << endl;
				else{
					cout << "\n" + warning + "\n";
					yyerror(error);
				} 
			}
#line 1682 "y.tab.c"
    break;

  case 3:
#line 131 "sintatica.y"
                        {
			}
#line 1689 "y.tab.c"
    break;

  case 4:
#line 134 "sintatica.y"
                        {
				traducaoFunction += yyvsp[-2].traducao;
			}
#line 1697 "y.tab.c"
    break;

  case 5:
#line 138 "sintatica.y"
                        {
			}
#line 1704 "y.tab.c"
    break;

  case 6:
#line 143 "sintatica.y"
                        {
				TIPO_FUNCTION function = getFunction();

				int size = tabelaFunction.size() - 1;
				tabelaFunction[size].nomeFunction = yyvsp[-4].label;

				if((function.retornoLabel == "") && (yyvsp[-4].tipo != "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Função não apresenta um retorno.\n";
				else if((function.retornoLabel != "") && (yyvsp[-4].tipo == "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Função void não poder conter um retorno.\n";
				else if(yyvsp[-4].tipo != function.retornoTipo && (yyvsp[-4].tipo != "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo de return não condiz com o tipo da função.\n";

				traducaoFunction += yyvsp[0].traducao + "\tEndFunc" + ";\n\n";
			}
#line 1724 "y.tab.c"
    break;

  case 7:
#line 161 "sintatica.y"
                   {
			   int size = tabelaFunction.size() - 1;
			   for(int i = size; i >= 0; i--)
			   {
				   if(yyvsp[0].label == tabelaFunction[i].nomeFunction)
				   {
						error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome de função já existe.\n";
				   }
			   }

			   traducaoFunction += "    _" + yyvsp[0].label + ":\n";
			   yyval.label = yyvsp[0].label;
			   yyval.tipo = yyvsp[-1].tipo;
		   }
#line 1743 "y.tab.c"
    break;

  case 8:
#line 178 "sintatica.y"
                   {
		   }
#line 1750 "y.tab.c"
    break;

  case 9:
#line 181 "sintatica.y"
                   {
		   }
#line 1757 "y.tab.c"
    break;

  case 10:
#line 186 "sintatica.y"
                    {
		    }
#line 1764 "y.tab.c"
    break;

  case 11:
#line 189 "sintatica.y"
                    {
		    }
#line 1771 "y.tab.c"
    break;

  case 12:
#line 194 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
			}
#line 1779 "y.tab.c"
    break;

  case 13:
#line 200 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1787 "y.tab.c"
    break;

  case 14:
#line 204 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1795 "y.tab.c"
    break;

  case 15:
#line 208 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-4]);
				yyval.label = gentempcode();

				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + yyval.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				}

				string cond = genCondcode();

				yyval.traducao = yyvsp[-4].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-4].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto "+ cond + "\n" + 
				yyvsp[-2].traducao + "\t" + cond + "\n" + yyvsp[0].traducao;
			}
#line 1817 "y.tab.c"
    break;

  case 16:
#line 226 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-7]);
				yyval.label = gentempcode();
				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + yyval.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				}
				string cond = genCondcode();

				yyval.traducao = yyvsp[-7].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-7].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto ELSE;" + "\n" + 
				yyvsp[-5].traducao + "\tgoto " + cond + "\n" + "\tELSE:\n" + yyvsp[-2].traducao
				+ "\t" + cond +"\n" + yyvsp[0].traducao;
			}
#line 1838 "y.tab.c"
    break;

  case 17:
#line 243 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-6]);
				yyval.label = gentempcode();
				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + yyval.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				}
				string cond = genCondcode();

				yyval.traducao = yyvsp[-6].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-6].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto ELSE;\n" + yyvsp[-4].traducao
				+ "\tgoto "+cond+"\n" + "\tELSE:\n" + yyvsp[-1].traducao + "\t"+cond+"\n" +
				yyvsp[0].traducao;
			}
#line 1859 "y.tab.c"
    break;

  case 18:
#line 260 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-3]);
				yyval.label = gentempcode();

				if(!mainStatus){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + yyval.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				}

				string cond = genCondcode();

				yyval.traducao = yyvsp[-3].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-3].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto " + cond + "\n"
				+ yyvsp[-1].traducao + "\t" + cond + "\n" + yyvsp[0].traducao;
			}
#line 1881 "y.tab.c"
    break;

  case 19:
#line 278 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-6]);
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				string cond = genCondcode();

				yyval.traducao = yyvsp[-6].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-6].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto ELSE;\n" + yyvsp[-4].traducao +
				"\tgoto " + cond + "\n" + "\tELSE:\n" + yyvsp[-2].traducao
				+ "\t" + cond +"\n" + yyvsp[0].traducao ;
			}
#line 1898 "y.tab.c"
    break;

  case 20:
#line 291 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-5]);
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				string cond = genCondcode();

				yyval.traducao = yyvsp[-5].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-5].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto ELSE;\n" + yyvsp[-3].traducao +
				"\tgoto " + cond + "\n" + "\tELSE:\n" + yyvsp[-1].traducao + "\t"+cond+"\n" + yyvsp[0].traducao;
			}
#line 1914 "y.tab.c"
    break;

  case 21:
#line 303 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-3]);
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				TIPO_LOOP loop = getLace(yyvsp[-5].label);

				yyval.traducao = loop.inicioLaco + yyvsp[-3].traducao + "\t" + yyval.label + " = !" +
				yyvsp[-3].label + ";\n" + "\tIF(" + yyval.label + ") goto " + loop.fimLaco + "\n" +
				yyvsp[-1].traducao + "\tgoto " + loop.inicioLaco + "\n\t" + loop.fimLaco + "\n" + yyvsp[0].traducao;
			}
#line 1929 "y.tab.c"
    break;

  case 22:
#line 314 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-3]);
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				TIPO_LOOP loop = getLace(yyvsp[-7].label);

				yyval.traducao = loop.inicioLaco + yyvsp[-6].traducao + yyvsp[-3].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-3].label + ";\n" + "\tIF(" + yyval.label +") goto " 
				+ loop.fimLaco  + "\n" + "\tgoto " + loop.inicioLaco + "\n\t" + loop.fimLaco +" \n"+ yyvsp[0].traducao;
			}
#line 1944 "y.tab.c"
    break;

  case 23:
#line 325 "sintatica.y"
                        {
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				TIPO_LOOP loop = getLace(yyvsp[-6].label); 

				yyval.traducao = loop.inicioLaco + yyvsp[-1].traducao + "\t" + "goto " + loop.inicioLaco + "\n\t" + loop.fimLaco +"\n" + yyvsp[0].traducao;
			}
#line 1956 "y.tab.c"
    break;

  case 24:
#line 333 "sintatica.y"
                        {
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				string lace = genLacecode();
				string cond = genCondcode();

				yyval.traducao = yyvsp[-7].traducao + lace + yyvsp[-5].traducao + "\t" + yyval.label + 
				" = !" + yyvsp[-5].label + ";\n\t" + "if(" + yyval.label + ") goto "+ cond + "\n" + 
				yyvsp[-1].traducao + yyvsp[-3].traducao + "\tgoto " + lace + "\n\t"+ cond +"\n" + yyvsp[0].traducao;
			}
#line 1971 "y.tab.c"
    break;

  case 25:
#line 344 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao + yyvsp[0].traducao;
			}
#line 1979 "y.tab.c"
    break;

  case 26:
#line 348 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1987 "y.tab.c"
    break;

  case 27:
#line 354 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1995 "y.tab.c"
    break;

  case 28:
#line 358 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 2003 "y.tab.c"
    break;

  case 29:
#line 364 "sintatica.y"
                        {
			}
#line 2010 "y.tab.c"
    break;

  case 30:
#line 369 "sintatica.y"
                        {
			}
#line 2017 "y.tab.c"
    break;

  case 31:
#line 372 "sintatica.y"
                        {
			}
#line 2024 "y.tab.c"
    break;

  case 32:
#line 375 "sintatica.y"
                        {
				if(controleLoop == 0)
				{
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Break não existente em um loop.\n";
				} else {
					TIPO_LOOP loop = getLaceBreak();
					yyval.traducao = "\tgoto " + loop.fimLaco + "\n";
				}
			}
#line 2038 "y.tab.c"
    break;

  case 33:
#line 385 "sintatica.y"
                        {
				if(controleLoop == 0){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Continue não existente em um loop.\n";
				} else {
					TIPO_LOOP loop = getLaceBreak();
					yyval.traducao = "\tgoto " + loop.inicioLaco + "\n";
				}
			}
#line 2051 "y.tab.c"
    break;

  case 34:
#line 394 "sintatica.y"
                        {
				if(controleFunction == 0){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Return não está dentro de uma função.\n";
				}
				
				int size = tabelaFunction.size() - 1;
				tabelaFunction[size].retornoLabel = yyvsp[-1].label;
				tabelaFunction[size].retornoTipo = yyvsp[-1].tipo;
				yyval.traducao += yyvsp[-1].traducao + "\tReturn " + yyvsp[-1].label + ";\n";
			}
#line 2066 "y.tab.c"
    break;

  case 35:
#line 407 "sintatica.y"
                        {
				if(yyvsp[-1].tipo == "void")
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Void não é um tipo declarável.\n";

				if(yyvsp[-1].tipo != "string"){
					int indiceTopo = tabelaFunction.size() - 1;
					if(controleFunction > 0 && getContexto() == 0){

						TIPO_SIMBOLO simb;
						simb.nomeVariavel = yyvsp[0].label;
						simb.tipoVariavel = yyvsp[-1].tipo;
						simb.labelVariavel = gentempcode();

						if(tabelaFunction[indiceTopo].parameters.size() == 0)
						{
							tabelaFunction[indiceTopo].parameters.push_back(simb);

						} else {
							for (int i = tabelaFunction[indiceTopo].parameters.size(); i >= 0; i--)
							{
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == yyvsp[0].label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome do parâmetro '" + yyvsp[0].label + "' ja utilizado na função.\n";
								}	
							}
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						}
						traducaoFunction = traducaoFunction + "\t" + simb.tipoVariavel + " " + simb.labelVariavel +";\n";
						
					} else {

						if(controleFunction > 0 && getContexto() > 0){
							int indiceTopoParameters = tabelaFunction[indiceTopo].parameters.size();
							for (int i = indiceTopoParameters; i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == yyvsp[0].label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Váriavel '" + yyvsp[0].label + "' não poderá ser de declarada nesta função.\n";
								}	
							}
						}

						verificarVariavelRepetida(yyvsp[0].label);
						addSimbolo(yyvsp[0].label, yyvsp[-1].tipo, gentempcode());
						yyval.traducao = "";
						yyval.label = "";
					}
				} else {
					int indiceTopo = tabelaFunction.size() - 1;
					if(controleFunction > 0 && getContexto() == 0){
						TIPO_SIMBOLO simb;
						simb.nomeVariavel = yyvsp[0].label;
						simb.tipoVariavel = yyvsp[-1].tipo;
						simb.labelVariavel = gentempcode();

						if(tabelaFunction[indiceTopo].parameters.size() == 0)
						{
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						} else {
							for (int i = tabelaFunction[indiceTopo].parameters.size(); i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == yyvsp[0].label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome do parâmetro '" + yyvsp[0].label + "' ja utilizado na função.\n";
								}	
							}
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						}
						traducaoFunction = traducaoFunction + "\t" + "char" + " *" + simb.labelVariavel + ";\n";
					} else {
						if(controleFunction > 0 && getContexto() > 0){
							int indiceTopoParameters = tabelaFunction[indiceTopo].parameters.size();
							for (int i = indiceTopoParameters; i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == yyvsp[0].label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Váriavel '" + yyvsp[0].label + "' não poderá ser de declarada nesta função.\n";
								}	
							}
						}

						string label = gentempcode();
						verificarVariavelRepetida(yyvsp[0].label);
						addString(yyvsp[0].label, "string", label);
						yyval.traducao = "";
						yyval.tipo = "string";
						yyval.label = "\tstrcpy(" + label + ", " + "\0" + ");\n";
					}
				}
			}
#line 2161 "y.tab.c"
    break;

  case 36:
#line 500 "sintatica.y"
                        {
				yyval.tipo = "int";
			}
#line 2169 "y.tab.c"
    break;

  case 37:
#line 504 "sintatica.y"
                        {
				yyval.tipo = "float";
			}
#line 2177 "y.tab.c"
    break;

  case 38:
#line 508 "sintatica.y"
                        {
				yyval.tipo = "char";
			}
#line 2185 "y.tab.c"
    break;

  case 39:
#line 512 "sintatica.y"
                        {
				yyval.tipo = "string";
			}
#line 2193 "y.tab.c"
    break;

  case 40:
#line 516 "sintatica.y"
                        {
				yyval.tipo = "boolean";
			}
#line 2201 "y.tab.c"
    break;

  case 41:
#line 520 "sintatica.y"
                        {
				yyval.tipo = "void";
			}
#line 2209 "y.tab.c"
    break;

  case 42:
#line 526 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;
				
				cout << yyvsp[-2].tipo;

				if(yyvsp[-2].tipo == "string" && yyvsp[0].tipo == "string"){
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Concatenação de string em breve.\n";
				}

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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
#line 2259 "y.tab.c"
    break;

  case 43:
#line 572 "sintatica.y"
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
#line 2303 "y.tab.c"
    break;

  case 44:
#line 612 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-1].label);
				if(variavel_1.tipoVariavel == "char" || variavel_1.tipoVariavel == "string" || variavel_1.tipoVariavel == "boolean" || variavel_1.tipoVariavel == "float"){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo inválido para operação unária.\n";
				}
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}
#line 2316 "y.tab.c"
    break;

  case 45:
#line 621 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-1].label);
				if(variavel_1.tipoVariavel == "char" || variavel_1.tipoVariavel == "string" || variavel_1.tipoVariavel == "boolean" || variavel_1.tipoVariavel == "float"){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo inválido para operação unária.\n";
				}
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " - 1" + ";\n";
			}
#line 2329 "y.tab.c"
    break;

  case 46:
#line 630 "sintatica.y"
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
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha +  ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\n\033[1;31mError\033[0m - Linha " + contLinha +  ": Casting inválido";
				}
			}
#line 2355 "y.tab.c"
    break;

  case 47:
#line 652 "sintatica.y"
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
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha +  ": as variáveis já apresentam o mesmo tipo.\n";
				}else{
					error += "\033[1;31mError\033[0m - Linha " + contLinha +  ": Casting inválido\n";
				}
			}
#line 2377 "y.tab.c"
    break;

  case 48:
#line 670 "sintatica.y"
                        {
			}
#line 2384 "y.tab.c"
    break;

  case 49:
#line 673 "sintatica.y"
                        {
			}
#line 2391 "y.tab.c"
    break;

  case 50:
#line 676 "sintatica.y"
                        {
				TIPO_FUNCTION aux = getFunctionChamada(yyvsp[-3].label);
				int index;
				int j = parametersChamada.size() - 1;
				string params;

				for(int k = tabelaFunction.size() - 1; k >= 0; k--)
				{
					if(tabelaFunction[k].nomeFunction == yyvsp[-3].label){
						index = k;
						break;
					}
				}

				if(aux.parameters.size() != parametersChamada.size())
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Quantidade de parâmetros inválida.\n";
				else{
					for(int i = 0; i < aux.parameters.size(); i++)
					{
						if(aux.parameters[i].tipoVariavel != parametersChamada[j].tipoVariavel)
						{
							error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m O parâmetro da função '" + aux.parameters[i].nomeVariavel + "' recebe tipo diferente.\n";
						} else {
							tabelaFunction[index].parameters[i].valorVariavel = parametersChamada[j].labelVariavel;
							params += "\tparam " + parametersChamada[j].labelVariavel + ";\n";
						}
						j--;
					}
				}
				
				yyval.traducao += yyvsp[-1].traducao + params;
				yyval.tipo = aux.retornoTipo; 
			    yyval.label = "call " + aux.nomeFunction + ", " + std::to_string(parametersChamada.size());

				while( parametersChamada.size() != 0){
					parametersChamada.pop_back();
				}
			}
#line 2434 "y.tab.c"
    break;

  case 51:
#line 715 "sintatica.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2442 "y.tab.c"
    break;

  case 52:
#line 721 "sintatica.y"
                   {
			   yyval.traducao = yyvsp[0].traducao;
		   }
#line 2450 "y.tab.c"
    break;

  case 53:
#line 725 "sintatica.y"
                   {
		   }
#line 2457 "y.tab.c"
    break;

  case 54:
#line 730 "sintatica.y"
                   {
			   TIPO_SIMBOLO aux;
			   aux.tipoVariavel = yyvsp[0].tipo;
			   aux.labelVariavel = yyvsp[0].label;
			   parametersChamada.push_back(aux);

			   yyval.traducao = yyvsp[0].traducao;
		   }
#line 2470 "y.tab.c"
    break;

  case 55:
#line 739 "sintatica.y"
                   {
			   TIPO_SIMBOLO aux;
			   aux.tipoVariavel = yyvsp[-2].tipo;
			   aux.labelVariavel = yyvsp[-2].label;
			   parametersChamada.push_back(aux);

			   yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao; 
		   }
#line 2483 "y.tab.c"
    break;

  case 56:
#line 750 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
			}
#line 2495 "y.tab.c"
    break;

  case 57:
#line 758 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
			}
#line 2507 "y.tab.c"
    break;

  case 58:
#line 766 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
			}
#line 2519 "y.tab.c"
    break;

  case 59:
#line 774 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
			}
#line 2531 "y.tab.c"
    break;

  case 60:
#line 782 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
			}
#line 2543 "y.tab.c"
    break;

  case 61:
#line 790 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
			}
#line 2555 "y.tab.c"
    break;

  case 62:
#line 798 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
			}
#line 2567 "y.tab.c"
    break;

  case 63:
#line 806 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
			}
#line 2579 "y.tab.c"
    break;

  case 64:
#line 814 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + "!" + yyvsp[0].label + ";\n";
			}
#line 2590 "y.tab.c"
    break;

  case 65:
#line 823 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[-2].label);

				string traduzir;
				if(variavel.tipoVariavel == yyvsp[0].tipo){
					if(yyvsp[0].tipo == "string"){

						traduzir = yyvsp[-2].traducao
						+ "\tstrcpy(" + yyvsp[0].label +", " + yyvsp[0].valor +");\n\t" + 
						variavel.labelVariavel + " = " + "(char*) malloc(" + yyvsp[0].index +");" +
						"\n\tstrcpy(" + variavel.labelVariavel +", " + yyvsp[0].label +");\n";

						if(getContexto() != 0)
							yyval.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
							
					} else {
						traduzir = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				    	variavel.labelVariavel + " = " + yyvsp[0].label + ";\n";
						if(getContexto() != 0)
							yyval.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
					}
				}
				else if (variavel.tipoVariavel == "int" & yyvsp[0].tipo == "float")
				{
					yyval.label = gentempcode();
					addTemp(yyval.label, "int");
					traduzir = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (int) " + yyvsp[0].label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + yyval.label + ";\n";

					if(getContexto() != 0)
							yyval.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
				}
				else if (variavel.tipoVariavel == "float" & yyvsp[0].tipo == "int")
				{
					yyval.label = gentempcode();
					addTemp(yyval.label, "float");
					traduzir = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + yyval.label + ";\n";

					if(getContexto() != 0)
							yyval.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Atribuição inválida, tipos diferentes.\n";
				}
			}
#line 2651 "y.tab.c"
    break;

  case 66:
#line 882 "sintatica.y"
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
#line 2695 "y.tab.c"
    break;

  case 67:
#line 922 "sintatica.y"
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação inválida, divisão por 0.\n";
				}
			}
#line 2759 "y.tab.c"
    break;

  case 68:
#line 982 "sintatica.y"
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos inválidos para %, (ou presença de float).\n";
				}
			}
#line 2779 "y.tab.c"
    break;

  case 69:
#line 998 "sintatica.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2787 "y.tab.c"
    break;

  case 70:
#line 1004 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
				yyval.tipo = yyvsp[-1].tipo;
				yyval.label = yyvsp[-1].label;
			}
#line 2797 "y.tab.c"
    break;

  case 71:
#line 1010 "sintatica.y"
                        {
				yyval.tipo = "int";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				yyval.valor = yyvsp[0].label;
			}
#line 2809 "y.tab.c"
    break;

  case 72:
#line 1018 "sintatica.y"
                        {
				yyval.tipo = "float";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				yyval.valor = yyvsp[0].label;
			}
#line 2821 "y.tab.c"
    break;

  case 73:
#line 1026 "sintatica.y"
                        {
				yyval.tipo = "char";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2832 "y.tab.c"
    break;

  case 74:
#line 1033 "sintatica.y"
                        {
				yyval.tipo = "string";
				yyval.label = gentempcode();
				yyval.traducao = "\tstrcpy(" + yyval.label +", " + yyvsp[0].valor + ");\n";
				yyval.index = std::to_string(addTempString(yyval.label, yyval.valor));
			}
#line 2843 "y.tab.c"
    break;

  case 75:
#line 1040 "sintatica.y"
                        {
				yyval.tipo = "boolean";
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";	
			}
#line 2854 "y.tab.c"
    break;

  case 76:
#line 1047 "sintatica.y"
                        {
				yyval.tipo = "boolean";
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";		
			}
#line 2865 "y.tab.c"
    break;

  case 77:
#line 1054 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[0].label);
				yyval.tipo = variavel.tipoVariavel;
				yyval.label = variavel.labelVariavel;
				yyval.traducao = "";
			}
#line 2876 "y.tab.c"
    break;

  case 78:
#line 1061 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + "\t" + "cout << " + yyvsp[-1].label + ";\n";
			}
#line 2884 "y.tab.c"
    break;

  case 79:
#line 1065 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[-1].label);
				yyval.traducao = yyvsp[-1].traducao + "\t" "STD::CIN >> " + variavel.labelVariavel + ";\n";
			}
#line 2893 "y.tab.c"
    break;


#line 2897 "y.tab.c"

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
#line 1070 "sintatica.y"


#include "lex.yy.c"

int yyparse();
int getContexto(){
	return mapa.size() - 1;
}

string gentempcode(){
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);	
}

string genLacecode(){
	var_lace_qnt++;
	return "_L" + std::to_string(var_lace_qnt) + ":";	
}

string genCondcode(){
	var_cond_qnt++;
	return "FIM_IF_" + std::to_string(var_cond_qnt) + ":";
}

string genLaceNameCode(){
	var_lace_name_qnt++;
	return "loop_" + std::to_string(var_lace_name_qnt);
}

void verificarVariavelRepetida(string variavel){

	int contexto = mapa.size() - 1;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	tabelaSimbolos = mapa[contexto];

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
		{
			error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m A variável '" + variavel + "' já existe.\n";
		}
	}
}

TIPO_SIMBOLO getSimbolo(string variavel){

	int contexto = mapa.size() - 1;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	tabelaSimbolos = mapa[contexto];

	while(contexto >= 0)
	{
		for (int i = tabelaSimbolos.size() - 1; i >= 0; i--)
		{
			if(tabelaSimbolos[i].nomeVariavel == variavel)
			{
				return tabelaSimbolos[i];
			}				
		}
		
		contexto -= 1;
		if(contexto >= 0){
			tabelaSimbolos = mapa[contexto];
		}
	}

	if(controleFunction > 0){

		int sizeFunctions = tabelaFunction.size() - 1;
		int sizeFunctionsParameters = tabelaFunction[sizeFunctions].parameters.size();

		for (int i = sizeFunctionsParameters; i >= 0; i--)
		{
			if(tabelaFunction[sizeFunctions].parameters[i].nomeVariavel == variavel)
			{
				return tabelaFunction[sizeFunctions].parameters[i];
			}				
		}
		
	}

	error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m A variável '" + variavel + "' não foi instanciada.\n";
}

void addSimbolo(string variavel, string tipo, string label){
	
	TIPO_SIMBOLO valor;

	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;

	int contexto = mapa.size() - 1;
	mapa[contexto].push_back(valor);

	if(valor.tipoVariavel == "boolean"){
		valor.tipoVariavel = "int";
	}


	if(controleFunction > 0)
	{
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";

	}else if(contexto == 0 && controleFunction == 0)
	{
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais  + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";

	} else 
	{
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	}
}

void addString(string variavel, string tipo, string label){
	TIPO_SIMBOLO valor;
	
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;

	int contexto = mapa.size() - 1;
	mapa[contexto].push_back(valor);

	valor.tipoVariavel = "char";
	if(controleFunction > 0){
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	} else if(contexto == 0 && controleFunction == 0){
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	} else {
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	}
}

void addTemp(string label, string tipo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = tipo;
	tabelaTemp.push_back(valor);

	if(valor.tipoVariavel == "boolean"){
		valor.tipoVariavel = "int";
	}

	int contexto = getContexto();

	if(controleFunction > 0)
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	else if(contexto == 0 && controleFunction == 0)
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	else
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

int addTempString(string label, string conteudo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = "string";
	valor.valor = conteudo;
	tabelaTemp.push_back(valor);
	valor.tipoVariavel = "char";

	int size = getSize(conteudo) - 1;
	int contexto = mapa.size() - 1;

	if(controleFunction > 0){
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	} else if(contexto == 0 && controleFunction == 0){
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	} else {
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	}
	return size;
}

int getSize(string str){
	int i = 0;
	while (str[i] != '\0')
		i++;

	return i;
}

void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2){
	if((tipo_1.tipo == "char" || tipo_2.tipo == "char") || (tipo_1.tipo == "string" || tipo_2.tipo == "string"))
	{
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação relacional inválida.\n";
	}
}

void verificarAtributoRelacional(atributos tipo_1){
	if(tipo_1.tipo == "char" || tipo_1.tipo == "string" || tipo_1.tipo == "void")
	{
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação relacional inválida.\n";
	}
}

int main(int argc, char* argv[]){
	var_temp_qnt = 0;
	contextoGlobal = 0;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	mapa.push_back(tabelaSimbolos);
	yyparse();
	return 0;
}

void pushContexto(){
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	mapa.push_back(tabelaSimbolos);
}

void popContexto(){
	mapa.pop_back();

	if(controleLoop != 0)
		controleLoop--;

	if(controleFunction != 0)
		controleFunction--;
}

void pushLoop(string tipo){

	controleLoop++;
	int size = tabelaLoop.size();
	TIPO_LOOP aux;
	aux.nomeLaco = "loop_" + std::to_string(var_lace_name_qnt);
	aux.tipoLaco = tipo;

	if(tipo == "while" && size != 0)
	{
		if(!(tabelaLoop[size - 1].tipoLaco == "do"))
		{
			aux.fimLaco = genCondcode();
			aux.inicioLaco = genLacecode();
			aux.contexto = getContexto();
			tabelaLoop.push_back(aux);
		}

	} else {
		aux.fimLaco = genCondcode();
		aux.inicioLaco = genLacecode();
		aux.contexto = mapa.size();
		tabelaLoop.push_back(aux);
	}
}

TIPO_LOOP getLace(string nome){

	for (int i = tabelaLoop.size() - 1; i >= 0; i--)
	{ 
		if(tabelaLoop[i].nomeLaco == nome)
		{
			return tabelaLoop[i];
		}
	}
}

TIPO_LOOP getLaceBreak(){
	int size = tabelaLoop.size();
	return tabelaLoop[size - 1];
}

void pushFunction(){
	TIPO_FUNCTION aux;
	aux.inicioFunction = genLacecode();
	aux.fimFunction = genLacecode();
	tabelaFunction.push_back(aux);
	controleFunction++;
}

TIPO_FUNCTION getFunction(){
	int size = tabelaFunction.size() - 1;
	return tabelaFunction[size];
}

TIPO_FUNCTION getFunctionChamada(string nome){

	TIPO_FUNCTION aux;
	int achou = 0;

	for(int i = 0; i < tabelaFunction.size(); i++){
		if(tabelaFunction[i].nomeFunction == nome){
			aux = tabelaFunction[i];
			achou = 1;
		}
	}

	if(achou == 0)
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome da função não existe.\n";
	return aux;
}

void contadorDeLinha(){
	var_linha_qnt++;
	contLinha = std::to_string(var_linha_qnt);
}

void yyerror(string MSG){
	cout << MSG << endl;
	exit (0);
}
