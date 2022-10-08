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

    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <vector>
    #include <string.h>

    #define add_tac($$, $1, $2, $3) {strcpy($$.type, $1.type);\
        sprintf($$.lexeme, "@t%d", variable_count);\
        variable_count++;\
        tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($2.lexeme) + " " + string($3.lexeme) + " " + string($$.type));}
    
    #include <iostream>
    #include <string>
    #include <unordered_map>
    #include <stack>

    using namespace std;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int yytext();

    bool check_declaration(string variable);

    struct var_info {
        string data_type;
        int size;   // for arrays
        int isArray;
        int line_number; 
    };

    vector<string> tac;
    unordered_map<string, struct var_info> symbol_table;

    int variable_count = 0;
    int label_counter = 0;

    vector<string> sem_errors;

    int temp_index;
    int temp_label;

    stack<int> loop_continue, loop_break;

    // for array declaration with initialization
    string curr_array;
    int arr_index=0;

    extern int countn;

    // struct func_table{
    //     string type;
    //     int num_params;

    // };
    // unordered_map<string, struct func_info> fun_table;

    typedef struct node{
        char* id;
        char* data_type;
        int size;
        char* type;     // category : keyword K; variable V; Constant C; Functions V
        int line_number;
    } func_symbol_table; // 100 entries allowed as of now

    int func_ind = 0;
    int func_arg = 0;
    int func_arg_ind = 0;
    int param_ind = 0;
    char curr_func_name[50];
    int curr_func_ind = 0;

    struct func_table{
        char name[50];
        char type[50];
        int num_of_param;
        int count;
        func_symbol_table st[1000];
    } func_table[50];

#line 149 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    CHAR = 259,
    FLOAT = 260,
    STRING = 261,
    VOID = 262,
    RETURN = 263,
    INT_NUM = 264,
    FLOAT_NUM = 265,
    ID = 266,
    LEFTSHIFT = 267,
    RIGHTSHIFT = 268,
    LE = 269,
    GE = 270,
    EQ = 271,
    NE = 272,
    GT = 273,
    LT = 274,
    AND = 275,
    OR = 276,
    NOT = 277,
    ADD = 278,
    SUBTRACT = 279,
    DIVIDE = 280,
    MULTIPLY = 281,
    MODULO = 282,
    BITAND = 283,
    BITOR = 284,
    NEGATION = 285,
    XOR = 286,
    STR = 287,
    CHARACTER = 288,
    CC = 289,
    OC = 290,
    CS = 291,
    OS = 292,
    CF = 293,
    OF = 294,
    COMMA = 295,
    COLON = 296,
    SCOL = 297,
    OUTPUT = 298,
    INPUT = 299,
    SWITCH = 300,
    CASE = 301,
    BREAK = 302,
    DEFAULT = 303,
    IF = 304,
    ELIF = 305,
    ELSE = 306,
    WHILE = 307,
    FOR = 308,
    CONTINUE = 309,
    ASSIGN = 310
  };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define FLOAT 260
#define STRING 261
#define VOID 262
#define RETURN 263
#define INT_NUM 264
#define FLOAT_NUM 265
#define ID 266
#define LEFTSHIFT 267
#define RIGHTSHIFT 268
#define LE 269
#define GE 270
#define EQ 271
#define NE 272
#define GT 273
#define LT 274
#define AND 275
#define OR 276
#define NOT 277
#define ADD 278
#define SUBTRACT 279
#define DIVIDE 280
#define MULTIPLY 281
#define MODULO 282
#define BITAND 283
#define BITOR 284
#define NEGATION 285
#define XOR 286
#define STR 287
#define CHARACTER 288
#define CC 289
#define OC 290
#define CS 291
#define OS 292
#define CF 293
#define OF 294
#define COMMA 295
#define COLON 296
#define SCOL 297
#define OUTPUT 298
#define INPUT 299
#define SWITCH 300
#define CASE 301
#define BREAK 302
#define DEFAULT 303
#define IF 304
#define ELIF 305
#define ELSE 306
#define WHILE 307
#define FOR 308
#define CONTINUE 309
#define ASSIGN 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 84 "parser.y" /* yacc.c:355  */

    struct node { 
        char lexeme[100];
        int line_number;
        char type[100];
        char if_body[5];
        char elif_body[5];
		char else_body[5];
        char loop_body[5];
        char parentNext[5];
        char case_body[5];
        char id[5];
        char temp[5];
        int nParams;
    } node;

#line 316 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 333 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   122,   123,   126,   126,   134,   134,   151,
     152,   155,   158,   161,   166,   170,   175,   176,   179,   180,
     181,   182,   183,   184,   185,   186,   191,   196,   197,   201,
     206,   215,   220,   224,   224,   231,   231,   238,   247,   252,
     255,   258,   265,   268,   271,   274,   277,   280,   283,   286,
     289,   292,   295,   298,   301,   304,   307,   310,   313,   316,
     319,   324,   329,   334,   339,   349,   356,   361,   366,   372,
     373,   374,   375,   378,   382,   386,   392,   397,   405,   408,
     414,   405,   423,   428,   435,   423,   440,   443,   444,   447,
     452,   456,   447,   466,   470,   473,   476,   473,   491,   492,
     495,   501,   495,   519,   523,   535,   519,   546,   574,   575,
     576,   579
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CHAR", "FLOAT", "STRING", "VOID",
  "RETURN", "INT_NUM", "FLOAT_NUM", "ID", "LEFTSHIFT", "RIGHTSHIFT", "LE",
  "GE", "EQ", "NE", "GT", "LT", "AND", "OR", "NOT", "ADD", "SUBTRACT",
  "DIVIDE", "MULTIPLY", "MODULO", "BITAND", "BITOR", "NEGATION", "XOR",
  "STR", "CHARACTER", "CC", "OC", "CS", "OS", "CF", "OF", "COMMA", "COLON",
  "SCOL", "OUTPUT", "INPUT", "SWITCH", "CASE", "BREAK", "DEFAULT", "IF",
  "ELIF", "ELSE", "WHILE", "FOR", "CONTINUE", "ASSIGN", "$accept",
  "Program", "func_list", "func", "$@1", "func_prefix", "$@2",
  "func_data_type", "param_list", "param", "stmt_list", "stmt",
  "declaration", "$@3", "arr_values", "$@4", "return_stmt", "data_type",
  "expr", "postfix_expr", "unary_expr", "primary_expr", "unary_op",
  "const", "assign", "if_stmt", "$@5", "$@6", "$@7", "elif_stmt", "$@8",
  "$@9", "$@10", "else_stmt", "switch_stmt", "$@11", "$@12", "$@13",
  "case_stmt_list", "case_stmt", "$@14", "$@15", "default_stmt",
  "while_loop_stmt", "$@16", "$@17", "for_loop_stmt", "$@18", "$@19",
  "$@20", "func_call", "arg_list", "arg", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -172

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-172)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -172,     4,     8,  -172,  -172,   165,  -172,  -172,  -172,  -172,
       5,    25,  -172,   154,  -172,   121,  -172,  -172,    -3,  -172,
    -172,  -172,  -172,  -172,   121,    15,    16,  -172,    11,  -172,
    -172,    40,    34,    52,   154,  -172,    63,   102,    -1,  -172,
    -172,  -172,    -4,  -172,    73,  -172,  -172,  -172,  -172,  -172,
      59,    10,   407,   121,   121,   121,   292,   121,   105,    88,
    -172,    91,    92,   107,  -172,  -172,  -172,  -172,    36,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,  -172,  -172,  -172,
    -172,    81,   121,   407,    94,    89,   217,   407,  -172,   315,
     100,   128,   121,   121,    37,    99,   143,  -172,   121,    56,
      56,   123,   123,   520,   520,   123,   123,   447,   427,    95,
      95,  -172,  -172,  -172,   504,   467,   487,     3,  -172,   142,
     242,  -172,   121,   106,   113,   118,  -172,   338,   361,   121,
    -172,   130,    83,  -172,    81,   134,  -172,  -172,   121,  -172,
    -172,   139,  -172,  -172,   267,   121,    -9,  -172,  -172,   138,
     407,   136,   141,   147,   106,   197,  -172,  -172,   140,   144,
     154,   154,  -172,   149,   179,  -172,  -172,   144,   153,   156,
     107,    39,   181,   160,   148,  -172,  -172,  -172,   168,   166,
     167,  -172,    39,   178,   189,   199,  -172,   205,   210,  -172,
     154,  -172,  -172,   200,   213,  -172,    39,   230,  -172,   237,
     235,  -172,   154,  -172,   234,   121,   154,   238,   154,   384,
     239,  -172,  -172,  -172,  -172,   250,   154,   259,  -172,   199,
    -172
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     5,     1,     3,     0,    39,    41,    40,    10,
       0,     0,     9,    17,     7,     0,    73,    74,    66,    71,
      69,    70,    72,    75,     0,     0,     0,    89,     0,    78,
     100,     0,     0,     0,    17,    18,     0,     0,     0,    62,
      60,    61,     0,    67,     0,    22,    27,    23,    24,    63,
       0,    66,    38,   110,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,    26,     6,    16,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    66,    65,
      19,    13,     0,   111,     0,   109,     0,    76,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    58,
      59,    46,    47,    50,    51,    49,    48,    52,    53,    42,
      43,    45,    44,    54,    55,    56,    57,     0,    12,     0,
       0,   107,   110,    64,     0,     0,    90,     0,     0,     0,
     103,     0,     0,     8,     0,    14,    64,   108,     0,    29,
      28,     0,    79,   101,     0,     0,     0,    31,    11,     0,
      77,     0,     0,     0,     0,     0,    32,    33,     0,    94,
      17,    17,   104,     0,     0,    95,    91,    94,     0,     0,
       0,     0,     0,     0,    99,    93,    80,   102,     0,     0,
      35,    15,     0,     0,     0,    86,   105,     0,     0,    96,
      17,    92,    82,    88,     0,    34,     0,     0,    98,     0,
       0,    81,    17,    36,     0,     0,    17,     0,    17,     0,
       0,   106,    97,    83,    87,     0,    17,     0,    84,    86,
      85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,   155,
     -33,  -172,  -172,  -172,    96,  -172,  -172,    -2,   -15,  -172,
    -172,   258,  -172,  -171,   -61,  -172,  -172,  -172,  -172,    72,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,   137,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,   190,  -172
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     5,    10,    50,    11,   127,   128,
      33,    34,    35,   173,   189,   198,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    61,   162,   195,   203,
     209,   225,   229,   211,    46,    59,   151,   184,   176,   177,
     183,   207,   194,    47,    62,   163,    48,   155,   180,   204,
      49,    94,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    66,   105,    12,     3,    16,    17,    88,    -2,    56,
     190,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   199,    79,    80,    81,    82,    83,    84,    85,    23,
      86,    24,    53,   166,    54,   190,    14,   143,    93,    96,
      97,    87,    99,   144,    13,    53,   167,    92,    16,    17,
      57,    58,    55,    60,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    23,   106,   139,    63,    64,   130,   107,    79,
      80,    81,    82,    83,     6,     7,     8,   137,   138,   129,
      65,   108,    55,   142,    91,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    67,    79,    80,    81,    82,
      83,    84,    85,    68,    86,    90,   100,    93,   104,   188,
      81,    82,    83,   101,   154,   157,   102,   103,   131,   132,
      16,    17,    51,   160,   135,    69,    70,   178,   179,   136,
     165,   140,   129,    19,    20,    21,    79,    80,    81,    82,
      83,    22,   141,   145,    23,   149,    24,     6,     7,     8,
     150,   148,    15,    16,    17,    18,   156,   208,     6,     7,
       8,   159,     9,   161,   168,   169,    19,    20,    21,   217,
     170,   174,   182,   220,    22,   222,   171,    23,   181,    24,
     175,   186,   191,   227,   187,   192,   193,    25,    26,    27,
     219,    28,   196,    29,   197,   -37,    30,    31,    32,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   200,
      79,    80,    81,    82,    83,    84,    85,   201,    86,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   172,
      79,    80,    81,    82,    83,    84,    85,   205,    86,   202,
     206,   210,   212,   133,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   214,    79,    80,    81,    82,    83,
      84,    85,   215,    86,   216,   218,   221,   224,   146,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   226,
      79,    80,    81,    82,    83,    84,    85,   228,    86,   158,
      89,   230,   213,   164,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   185,    79,    80,    81,    82,    83,
      84,    85,   147,    86,     0,     0,    98,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,    79,    80,
      81,    82,    83,    84,    85,     0,    86,     0,     0,   134,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,    84,    85,     0,    86,
       0,     0,   152,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,    79,    80,    81,    82,    83,    84,
      85,     0,    86,     0,     0,   153,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    85,     0,    86,     0,     0,   223,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,    84,    85,     0,    86,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      79,    80,    81,    82,    83,    84,    85,     0,    86,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,     0,    86,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
      79,    80,    81,    82,    83,    84,     0,     0,    86,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,     0,    79,    80,    81,
      82,    83,    69,    70,    71,    72,     0,     0,    75,    76,
       0,     0,     0,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      15,    34,    63,     5,     0,     9,    10,    11,     0,    24,
     181,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   192,    23,    24,    25,    26,    27,    28,    29,    33,
      31,    35,    35,    42,    37,   206,    11,    34,    53,    54,
      55,    42,    57,    40,    39,    35,    55,    37,     9,    10,
      35,    35,    55,    42,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    33,    37,    37,    35,    42,    92,    42,    23,
      24,    25,    26,    27,     3,     4,     5,   102,   103,    91,
      38,    55,    55,   108,    35,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    42,    23,    24,    25,    26,
      27,    28,    29,    11,    31,    42,    11,   132,    11,   180,
      25,    26,    27,    35,   139,    42,    35,    35,    34,    40,
       9,    10,    11,   148,    34,    12,    13,   170,   171,    11,
     155,    42,   144,    22,    23,    24,    23,    24,    25,    26,
      27,    30,     9,    11,    33,    42,    35,     3,     4,     5,
      42,    55,     8,     9,    10,    11,    36,   200,     3,     4,
       5,    37,     7,    34,    36,    39,    22,    23,    24,   212,
      39,    41,     3,   216,    30,   218,    39,    33,    39,    35,
      46,    38,    11,   226,    38,    35,    48,    43,    44,    45,
     215,    47,    34,    49,    38,    38,    52,    53,    54,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    41,
      23,    24,    25,    26,    27,    28,    29,    38,    31,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    42,
      23,    24,    25,    26,    27,    28,    29,    42,    31,    50,
      40,    51,    39,    36,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    34,    23,    24,    25,    26,    27,
      28,    29,    35,    31,    39,    41,    38,    38,    36,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    39,
      23,    24,    25,    26,    27,    28,    29,    38,    31,   144,
      42,   229,   206,    36,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   177,    23,    24,    25,    26,    27,
      28,    29,   132,    31,    -1,    -1,    34,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    -1,    -1,    34,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    34,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    34,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,    59,    60,     3,     4,     5,     7,
      61,    63,    73,    39,    11,     8,     9,    10,    11,    22,
      23,    24,    30,    33,    35,    43,    44,    45,    47,    49,
      52,    53,    54,    66,    67,    68,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    90,    99,   102,   106,
      62,    11,    74,    35,    37,    55,    74,    35,    35,    91,
      42,    82,   100,    35,    42,    38,    66,    42,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    23,
      24,    25,    26,    27,    28,    29,    31,    42,    11,    77,
      42,    35,    37,    74,   107,   108,    74,    74,    34,    74,
      11,    35,    35,    35,    11,    80,    37,    42,    55,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    64,    65,    73,
      74,    34,    40,    36,    34,    34,    11,    74,    74,    37,
      42,     9,    74,    34,    40,    11,    36,   107,    55,    42,
      42,    92,    34,    34,    74,   103,    36,    42,    65,    37,
      74,    34,    83,   101,    36,    74,    42,    55,    36,    39,
      39,    39,    42,    69,    41,    46,    94,    95,    66,    66,
     104,    39,     3,    96,    93,    94,    38,    38,    80,    70,
      79,    11,    35,    48,    98,    84,    34,    38,    71,    79,
      41,    38,    50,    85,   105,    42,    40,    97,    66,    86,
      51,    89,    39,    70,    34,    35,    39,    66,    41,    74,
      66,    38,    66,    34,    38,    87,    39,    66,    38,    88,
      85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    60,    59,    62,    61,    63,
      63,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    69,    68,    71,    70,    70,    72,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    77,    77,    77,    78,
      78,    78,    78,    79,    79,    79,    80,    80,    82,    83,
      84,    81,    86,    87,    88,    85,    85,    89,    89,    91,
      92,    93,    90,    94,    94,    96,    97,    95,    98,    98,
     100,   101,    99,   103,   104,   105,   102,   106,   107,   107,
     107,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     5,     0,     6,     1,
       1,     3,     1,     0,     2,     7,     2,     0,     1,     2,
       2,     2,     1,     1,     1,     2,     2,     1,     5,     5,
       3,     5,     6,     0,    11,     0,     4,     1,     2,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     4,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     0,     0,
       0,    12,     0,     0,     0,    11,     0,     4,     0,     0,
       0,     0,    11,     2,     0,     0,     0,     8,     3,     0,
       0,     0,     9,     0,     0,     0,    14,     4,     3,     1,
       0,     1
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
#line 120 "parser.y" /* yacc.c:1646  */
    {}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 122 "parser.y" /* yacc.c:1646  */
    {}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 126 "parser.y" /* yacc.c:1646  */
    {
                        func_table[func_ind].count = 0;
                    }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "parser.y" /* yacc.c:1646  */
    {
                        func_ind++; 
                        tac.push_back("end:\n");
                    }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 134 "parser.y" /* yacc.c:1646  */
    {tac.push_back(string((yyvsp[0].node).lexeme) + ":"); sprintf(curr_func_name, "%s", (yyvsp[0].node).lexeme);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "parser.y" /* yacc.c:1646  */
    {

                        strcpy((yyval.node).lexeme, (yyvsp[-4].node).lexeme);
                        
                        sprintf(func_table[func_ind].name, "%s" ,(yyvsp[-4].node).lexeme);
                        sprintf(func_table[func_ind].type, "%s", (yyvsp[-5].node).type);
                        func_table[func_ind].num_of_param = (yyvsp[-1].node).nParams;


                        // checking for duplicate function names
                        for(int i=0; i<func_ind; i++){
                            if(strcmp(func_table[i].name, func_table[func_ind].name) == 0){
                                printf("Error: Duplicate function name %s", func_table[func_ind].name);
                            }
                        }
                    }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = (yyvsp[-2].node).nParams + 1;
                    }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = (yyvsp[0].node).nParams;
                    }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = 0;
                    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = 1;
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 170 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = 1;                        
                    }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 186 "parser.y" /* yacc.c:1646  */
    {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 191 "parser.y" /* yacc.c:1646  */
    {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 197 "parser.y" /* yacc.c:1646  */
    {
                        check_declaration((yyvsp[-2].node).lexeme);
                        tac.push_back("input " + string((yyvsp[-2].node).lexeme) + " " + symbol_table[string((yyvsp[-4].node).lexeme)].data_type);
                    }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 201 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-2].node).type));
                    }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 206 "parser.y" /* yacc.c:1646  */
    { 
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        symbol_table[string((yyvsp[-1].node).lexeme)] = { string((yyvsp[-2].node).type), 0, 0, countn+1 };
                    }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 215 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[-4].node).type));
                        symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), 0, 0, countn+1 };
                    }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 220 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                    }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                        curr_array = string((yyvsp[-4].node).lexeme);
                    }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme));
                        if(arr_index > symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(symbol_table[curr_array].size) + "]’");
                        }
                    }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 238 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme));
                        if(arr_index > symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(symbol_table[curr_array].size) + "]’");
                        }
                        arr_index=0;
                    }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 247 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                    }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 252 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "INT");
                    }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "FLOAT");
                    }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 258 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "CHAR");
                    }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 265 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 268 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 271 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 274 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 277 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 280 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 283 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 286 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 289 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 292 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 295 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 298 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 301 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 304 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 307 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 310 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 313 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 316 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 319 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 324 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 329 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 334 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 339 "parser.y" /* yacc.c:1646  */
    {
                        if(check_declaration(string((yyvsp[-3].node).lexeme)) && symbol_table[string((yyvsp[-3].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Variable is not an array"); 
                        }
                        strcpy((yyval.node).type, symbol_table[string((yyvsp[-3].node).lexeme)].data_type.c_str());
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-3].node).lexeme) + " [ " + string((yyvsp[-1].node).lexeme) + " ] " + " " + string((yyval.node).type));
                    }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 349 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 356 "parser.y" /* yacc.c:1646  */
    {
                        check_declaration(string((yyvsp[0].node).lexeme));
                        strcpy((yyval.node).type, symbol_table[string((yyvsp[0].node).lexeme)].data_type.c_str());
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 361 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type)); 
                    }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 366 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[-1].node).lexeme);
                    }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 378 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "INT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 382 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "FLOAT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 386 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "CHAR");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 392 "parser.y" /* yacc.c:1646  */
    {
                        check_declaration(string((yyvsp[-2].node).lexeme));
                        tac.push_back(string((yyvsp[-2].node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + symbol_table[string((yyvsp[-2].node).lexeme)].data_type);
                    }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 397 "parser.y" /* yacc.c:1646  */
    {
                        if(check_declaration(string((yyvsp[-5].node).lexeme)) && symbol_table[string((yyvsp[-5].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Variable is not an array"); 
                        }
                        tac.push_back(string((yyvsp[-5].node).lexeme) + " [ " + string((yyvsp[-3].node).lexeme) + " ] " + " = " + string((yyvsp[0].node).lexeme) + " " + symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                    }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 405 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 408 "parser.y" /* yacc.c:1646  */
    { 
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 414 "parser.y" /* yacc.c:1646  */
    {  
                        tac.push_back("GOTO " + string((yyvsp[-8].node).parentNext));
                        tac.push_back(string((yyvsp[-5].node).else_body) + ":");
                    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 418 "parser.y" /* yacc.c:1646  */
    {   
                        tac.push_back(string((yyvsp[-11].node).parentNext) + ":");
                    }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 423 "parser.y" /* yacc.c:1646  */
    {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf((yyvsp[0].node).parentNext, "%s", hold);
                    }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 428 "parser.y" /* yacc.c:1646  */
    {
                        // sprintf(icg[ic_idx++], "\nif (%s != 0) GOTO L%d else GOTO L%d\n", $4.token, label, label+1);
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 435 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).parentNext));
                        tac.push_back(string((yyvsp[-5].node).else_body) + ":");
                    }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 447 "parser.y" /* yacc.c:1646  */
    {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 452 "parser.y" /* yacc.c:1646  */
    {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme));
                    }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 456 "parser.y" /* yacc.c:1646  */
    {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 460 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("Label " + string((yyvsp[-10].node).parentNext));
                        loop_break.pop();
                    }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 466 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyvsp[-1].node).id, (yyval.node).id);
                        strcpy((yyvsp[-1].node).parentNext, (yyval.node).parentNext);
                    }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 473 "parser.y" /* yacc.c:1646  */
    {
                        // tac.push_back(string($4.if_body) + ":");
                    }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 476 "parser.y" /* yacc.c:1646  */
    {
                        char* hold = const_cast<char*>(to_string(variable_count).c_str());
                        sprintf((yyvsp[0].node).temp, "%s", hold);
                        tac.push_back("@t" + to_string(variable_count++) + " = " + (yyvsp[0].node).lexeme);
                        tac.push_back("@t" + to_string(variable_count++) + " = " + "@t" + to_string(temp_index) + " == " + "@t" + string((yyvsp[0].node).temp));
                        tac.push_back("if @t" + to_string(variable_count-1) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        tac.push_back("Label #L" + to_string(label_counter) + ":");
                        sprintf((yyvsp[0].node).case_body, "#L%d", label_counter++);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 486 "parser.y" /* yacc.c:1646  */
    {
                        // tac.push_back("Label " + string($4.parentNext) + ":");
                        tac.push_back("Label " + string((yyvsp[-4].node).parentNext) + ":");
                    }
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 495 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyvsp[0].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[0].node).loop_body) + ":");
                    }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 501 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));
                        tac.push_back("\n" + string((yyvsp[-1].node).if_body) + ":");
                        
                    }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 512 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-5].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 519 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyvsp[-3].node).loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string((yyvsp[-3].node).loop_body) + ":");
                    }
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 523 "parser.y" /* yacc.c:1646  */
    {  
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));

                        sprintf((yyvsp[-1].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[-1].node).loop_body) + ":");
                    }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 535 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-4].node).if_body) + ":");
                    }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 539 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-8].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 546 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyval.node).lexeme, (yyvsp[-3].node).lexeme);        
                        sprintf((yyval.node).lexeme, "@t%d", variable_count);
                        variable_count++;

                        // checking if function is declared
                        bool flag = false;
                        int ind = -1;
                        for(int i=0; i<func_ind; i++){
                            if((strcmp(func_table[i].name, (yyvsp[-3].node).lexeme) == 0) || (strcmp(curr_func_name, (yyvsp[-3].node).lexeme)==0)){
                                ind = i;
                                curr_func_ind = i;
                                flag = true;
                                break;
                            }
                        }
                    
                        if(!flag && (strcmp(curr_func_name, (yyvsp[-3].node).lexeme)!=0)){
                            printf("ERROR in line %d : Function %s is not declared\n", countn+1, (yyvsp[-3].node).lexeme);
                        }
                        tac.push_back(string((yyval.node).lexeme) + " = @call " + string((yyvsp[-3].node).lexeme) + " " + to_string(func_table[ind].num_of_param));
                    
                        param_ind = 0;
                        func_arg_ind = 0;
                        func_arg = 0;
                    }
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 575 "parser.y" /* yacc.c:1646  */
    {}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 576 "parser.y" /* yacc.c:1646  */
    {}
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 579 "parser.y" /* yacc.c:1646  */
    {
                        // check argument types
                        tac.push_back("@param " + to_string(param_ind++) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));

                        // if(strcmp($1.type, func_table[curr_func_ind].st[func_arg_ind++].data_type) != 0){
                        //     printf("Error in function call %s: variable type is not matched", func_table[curr_func_ind].name);
                        //     exit(0);
                        // }
                        func_arg++;
                    }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2434 "y.tab.c" /* yacc.c:1646  */
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
#line 591 "parser.y" /* yacc.c:1906  */


int main(int argc, char *argv[]) {
    /* yydebug = 1; */
    yyparse();
    for(auto x: tac)
        cout << x << endl;
    for(auto item: sem_errors)
        cout << item << endl;
    /* for(auto item: symbol_table)
        cout << item.first << "-->" << item.second.data_type << endl; */
}

bool check_declaration(string variable){
    if(symbol_table.find(variable) == symbol_table.end()){
        sem_errors.push_back("Variable not declared in line " + to_string(countn+1) + " before usage.");
        return false;
    }
    return true;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}


// Prepend # to label names
