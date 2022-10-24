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
        string lt=string($1.type);\
        string rt=string($3.type);\
        if((lt == "CHAR" && rt == "INT") || (rt == "CHAR" && lt == "INT")){\
            strcpy($$.type, "INT");\
        }\
        else if((lt == "FLOAT" && rt == "INT") || (rt == "FLOAT" && lt == "INT")){\
            strcpy($$.type, "FLOAT");\
        }\
        else if((lt == "FLOAT" && rt == "FLOAT") || (lt == "INT" && rt == "INT") || (lt == "CHAR" && rt == "CHAR")){\
            strcpy($$.type, $1.type);\
        }\
        else{\
            sem_errors.push_back("Cannot convert between CHAR and FLOAT in line : " + to_string(countn+1));\
        }}
    
    #include <iostream>
    #include <string>
    #include <unordered_map>
    #include<map>
    #include <stack>
    #include<algorithm>
    #include<fstream>

    using namespace std;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int yytext();

    bool check_declaration(string variable);
    bool check_scope(string variable);
    bool multiple_declaration(string variable);
    bool is_reserved_word(string id);
    bool function_check(string variable, int flag);
    bool type_check(string type1, string type2);
    bool check_type(string l, string r);

    struct var_info {
        string data_type;
        int scope;
        int size;   // for arrays
        int isArray;
        int line_number; 
    };

    vector<string> tac;
    unordered_map<string, struct var_info> symbol_table;
    map<string, string> temp_map;

    int variable_count = 0;
    int label_counter = 0;

    vector<string> sem_errors;

    int temp_index;
    int temp_label;

    stack<int> loop_continue, loop_break;
    stack<pair<string, vector<string>>> func_call_id;
    stack<int> scope_history;
    int scope_counter = 0;

    // for array declaration with initialization
    string curr_array;
    int arr_index=0;

    extern int countn;

    struct func_info{
        string return_type;
        int num_params;
        vector<string> param_types;
        unordered_map<string, struct var_info> symbol_table;
    };

    unordered_map<string, struct func_info> func_table;
    string curr_func_name;
    vector<string> curr_func_param_type;

    vector<string> reserved = {"int", "float", "char", "string", "void", "if", "elif", "else", "for", "while", "break", "continue", "main", "return", "switch", "case", "input", "output"};


#line 160 "y.tab.c" /* yacc.c:339  */

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
#line 95 "parser.y" /* yacc.c:355  */

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

#line 327 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 344 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   557

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

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
       0,   131,   131,   133,   134,   138,   137,   147,   146,   159,
     162,   167,   167,   175,   181,   186,   192,   193,   196,   197,
     198,   199,   200,   201,   202,   203,   208,   213,   214,   219,
     222,   228,   234,   241,   249,   255,   255,   264,   264,   272,
     282,   288,   291,   294,   301,   305,   309,   331,   353,   359,
     365,   369,   373,   377,   383,   401,   419,   441,   445,   449,
     463,   466,   469,   474,   479,   484,   489,   500,   507,   513,
     525,   531,   532,   533,   534,   537,   541,   545,   551,   558,
     567,   570,   577,   579,   567,   589,   594,   602,   605,   589,
     611,   614,   614,   615,   618,   623,   627,   618,   637,   641,
     644,   647,   644,   662,   663,   666,   672,   682,   666,   693,
     697,   709,   714,   693,   725,   725,   741,   753,   764,   767
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
  "func_data_type", "param_list", "$@3", "param", "stmt_list", "stmt",
  "declaration", "$@4", "arr_values", "$@5", "return_stmt", "data_type",
  "expr", "postfix_expr", "unary_expr", "primary_expr", "unary_op",
  "const", "assign", "if_stmt", "$@6", "$@7", "$@8", "$@9", "elif_stmt",
  "$@10", "$@11", "$@12", "$@13", "else_stmt", "$@14", "switch_stmt",
  "$@15", "$@16", "$@17", "case_stmt_list", "case_stmt", "$@18", "$@19",
  "default_stmt", "while_loop_stmt", "$@20", "$@21", "$@22",
  "for_loop_stmt", "$@23", "$@24", "$@25", "$@26", "func_call", "$@27",
  "arg_list", "arg", YY_NULLPTR
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

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -115

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,     4,    72,  -111,  -111,  -111,  -111,  -111,  -111,   -29,
      22,  -111,  -111,  -111,    89,     3,    31,   219,  -111,  -111,
      -3,  -111,  -111,  -111,  -111,  -111,   219,    16,    19,  -111,
      41,  -111,  -111,    39,    44,    50,    89,  -111,    47,    97,
      -1,  -111,  -111,  -111,    -4,  -111,    67,  -111,  -111,  -111,
    -111,  -111,    32,    55,    45,   433,   219,   219,    81,   318,
     167,   106,    83,  -111,    86,    96,   124,  -111,  -111,  -111,
    -111,    65,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
    -111,  -111,  -111,  -111,   110,   111,   129,   114,   219,   243,
     433,   219,  -111,   115,   341,   139,   137,   219,   219,    48,
     121,   165,  -111,   219,    21,    21,   102,   102,   221,   221,
     102,   102,   473,   453,    79,    79,  -111,  -111,  -111,   530,
     493,   513,  -111,   135,  -111,   138,   268,   126,   433,   145,
     142,   143,   144,   150,  -111,   364,   387,   219,  -111,   148,
     141,    32,  -111,  -111,   219,  -111,   219,  -111,  -111,  -111,
     159,  -111,  -111,   293,   219,   -34,  -111,  -111,   433,  -111,
     156,   157,   164,   126,   196,  -111,  -111,   152,  -111,  -111,
    -111,   166,  -111,  -111,   152,    89,    89,   124,    40,   169,
     158,  -111,   180,   188,   197,   194,   199,    40,   209,   213,
    -111,  -111,  -111,   211,   225,  -111,    89,  -111,   223,   236,
    -111,    40,   242,  -111,  -111,   226,  -111,  -111,   237,   255,
     259,  -111,    89,    89,   219,  -111,   262,  -111,   410,    89,
    -111,  -111,   263,   264,  -111,  -111,    89,   277,  -111,   223,
    -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    41,    43,    42,    10,     3,     0,
       0,     9,     5,     7,    17,     0,     0,     0,    75,    76,
      68,    73,    71,    72,    74,    77,     0,     0,     0,    94,
       0,    80,   105,     0,     0,     0,    17,    18,     0,     0,
       0,    64,    62,    63,     0,    69,     0,    22,    27,    23,
      24,    65,    14,     0,    68,    40,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,    26,     6,    16,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    68,    67,    19,     0,    11,     0,     0,     0,     0,
      78,   118,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    60,    61,    48,    49,    52,    53,
      51,    50,    54,    55,    44,    45,    47,    46,    56,    57,
      58,    59,     8,     0,    15,     0,     0,    66,   119,     0,
     117,     0,     0,     0,    95,     0,     0,     0,   109,     0,
       0,    14,    32,    66,     0,   115,   118,    30,    29,    28,
       0,    81,   106,     0,     0,     0,    33,    12,    79,   116,
       0,     0,     0,     0,     0,    34,    35,    99,    82,   107,
     110,     0,   100,    96,    99,    17,    17,     0,     0,     0,
     104,    98,     0,     0,     0,     0,    37,     0,     0,     0,
      83,   108,   111,     0,     0,   101,    17,    97,    90,     0,
      36,     0,     0,   103,    85,    93,   112,    38,     0,     0,
       0,    84,    17,    17,     0,    91,     0,   102,     0,    17,
     113,    86,     0,     0,    92,    87,    17,     0,    88,    90,
      89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   151,  -111,
    -111,   -35,  -111,  -111,  -111,   112,  -111,  -111,     1,   -17,
    -111,  -111,   281,  -111,  -110,   -64,  -111,  -111,  -111,  -111,
    -111,    87,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,   179,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   171,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,    14,     9,    15,    10,    94,   133,
      95,    35,    36,    37,   181,   195,   204,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    64,   171,   185,
     208,   215,   219,   233,   236,   239,   221,   229,    48,    62,
     160,   190,   183,   184,   189,   212,   199,    49,    65,   172,
     186,    50,   164,   187,   209,   222,    51,    58,   139,   140
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    69,   110,    11,     3,    18,    19,    91,   175,    59,
      12,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   176,    82,    83,    84,    85,    86,    87,    88,    25,
      89,    26,  -114,    13,    56,     4,     5,     6,    52,    99,
     100,    90,    53,   104,    82,    83,    84,    85,    86,    18,
      19,    60,    57,    96,    61,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    25,    66,     4,     5,     6,   196,     7,
    -114,   136,    98,    63,   138,   147,    67,   205,    68,    70,
     145,   146,     4,     5,     6,    16,   150,    17,    18,    19,
      20,   196,   111,    57,    84,    85,    86,   112,    71,    93,
      97,    21,    22,    23,    72,    73,   101,   105,   106,    24,
     113,   107,    25,   194,    26,    82,    83,    84,    85,    86,
     163,   108,    27,    28,    29,   109,    30,   168,    31,   138,
     134,    32,    33,    34,   132,   -13,   135,   174,   144,   141,
     192,   193,    96,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   148,    82,    83,    84,    85,    86,    87,
      88,   213,    89,   143,   149,   151,    18,    19,    54,   155,
     152,   154,   156,   166,   165,   157,   158,   226,   227,    21,
      22,    23,   159,   170,   232,   177,   178,    24,   182,   103,
      25,   237,    26,   179,   197,   188,   198,   228,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   200,    82,
      83,    84,    85,    86,    87,    88,   201,    89,    18,    19,
      54,   202,   203,    72,    73,    74,    75,   -39,   180,    78,
      79,    21,    22,    23,    82,    83,    84,    85,    86,    24,
     206,   207,    25,   210,    26,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   211,    82,    83,    84,    85,
      86,    87,    88,   214,    89,   216,   218,   220,   223,   137,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
     224,    82,    83,    84,    85,    86,    87,    88,   225,    89,
     230,   234,   167,   235,   153,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   238,    82,    83,    84,    85,
      86,    87,    88,   217,    89,    92,   240,   169,     0,   173,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,    82,    83,    84,    85,    86,    87,    88,     0,    89,
       0,     0,   102,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   191,    82,    83,    84,    85,    86,    87,
      88,     0,    89,     0,     0,   142,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,    82,    83,    84,
      85,    86,    87,    88,     0,    89,     0,     0,   161,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,    83,    84,    85,    86,    87,    88,     0,    89,     0,
       0,   162,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,    82,    83,    84,    85,    86,    87,    88,
       0,    89,     0,     0,   231,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,    82,    83,    84,    85,
      86,    87,    88,     0,    89,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,     0,    82,    83,    84,    85,
      86,    87,    88,     0,    89,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,     0,    89,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    82,    83,    84,    85,
      86,    87,     0,     0,    89,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,     0,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
      17,    36,    66,     2,     0,     9,    10,    11,    42,    26,
      39,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    55,    23,    24,    25,    26,    27,    28,    29,    33,
      31,    35,    35,    11,    37,     3,     4,     5,    35,    56,
      57,    42,    11,    60,    23,    24,    25,    26,    27,     9,
      10,    35,    55,    52,    35,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    33,    35,     3,     4,     5,   188,     7,
      35,    98,    37,    42,   101,    37,    42,   197,    38,    42,
     107,   108,     3,     4,     5,     6,   113,     8,     9,    10,
      11,   211,    37,    55,    25,    26,    27,    42,    11,    42,
      55,    22,    23,    24,    12,    13,    35,    11,    35,    30,
      55,    35,    33,   187,    35,    23,    24,    25,    26,    27,
     147,    35,    43,    44,    45,    11,    47,   154,    49,   156,
      11,    52,    53,    54,    34,    34,    32,   164,    11,    34,
     185,   186,   151,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    42,    23,    24,    25,    26,    27,    28,
      29,   206,    31,    34,     9,    40,     9,    10,    11,    34,
      42,    55,    40,    42,    36,    42,    42,   222,   223,    22,
      23,    24,    42,    34,   229,    39,    39,    30,    46,    32,
      33,   236,    35,    39,    35,    39,    48,   224,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    38,    23,
      24,    25,    26,    27,    28,    29,    38,    31,     9,    10,
      11,    34,    38,    12,    13,    14,    15,    38,    42,    18,
      19,    22,    23,    24,    23,    24,    25,    26,    27,    30,
      41,    38,    33,    42,    35,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    40,    23,    24,    25,    26,
      27,    28,    29,    50,    31,    39,    34,    51,    41,    36,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      35,    23,    24,    25,    26,    27,    28,    29,    39,    31,
      38,    38,   151,    39,    36,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    38,    23,    24,    25,    26,
      27,    28,    29,   211,    31,    44,   239,   156,    -1,    36,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    34,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   184,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    34,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    34,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    -1,    34,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,     3,     4,     5,     7,    59,    61,
      63,    74,    39,    11,    60,    62,     6,     8,     9,    10,
      11,    22,    23,    24,    30,    33,    35,    43,    44,    45,
      47,    49,    52,    53,    54,    67,    68,    69,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    94,   103,
     107,   112,    35,    11,    11,    75,    37,    55,   113,    75,
      35,    35,    95,    42,    83,   104,    35,    42,    38,    67,
      42,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    23,    24,    25,    26,    27,    28,    29,    31,
      42,    11,    78,    42,    64,    66,    74,    55,    37,    75,
      75,    35,    34,    32,    75,    11,    35,    35,    35,    11,
      81,    37,    42,    55,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    34,    65,    11,    32,    75,    36,    75,   114,
     115,    34,    34,    34,    11,    75,    75,    37,    42,     9,
      75,    40,    42,    36,    55,    34,    40,    42,    42,    42,
      96,    34,    34,    75,   108,    36,    42,    64,    75,   114,
      34,    84,   105,    36,    75,    42,    55,    39,    39,    39,
      42,    70,    46,    98,    99,    85,   106,   109,    39,   100,
      97,    98,    67,    67,    81,    71,    80,    35,    48,   102,
      38,    38,    34,    38,    72,    80,    41,    38,    86,   110,
      42,    40,   101,    67,    50,    87,    39,    71,    34,    88,
      51,    92,   111,    41,    35,    39,    67,    67,    75,    93,
      38,    34,    67,    89,    38,    39,    90,    67,    38,    91,
      87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    60,    59,    62,    61,    63,
      63,    65,    64,    64,    64,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    69,    69,    70,    69,    72,    71,    71,
      73,    74,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    77,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    80,    81,    81,
      83,    84,    85,    86,    82,    88,    89,    90,    91,    87,
      87,    93,    92,    92,    95,    96,    97,    94,    98,    98,
     100,   101,    99,   102,   102,   104,   105,   106,   103,   108,
     109,   110,   111,   107,   113,   112,   114,   114,   114,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     5,     0,     6,     1,
       1,     0,     4,     1,     0,     2,     2,     0,     1,     2,
       2,     2,     1,     1,     1,     2,     2,     1,     5,     5,
       5,     3,     5,     5,     6,     0,    11,     0,     4,     1,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     4,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     6,
       0,     0,     0,     0,    13,     0,     0,     0,     0,    12,
       0,     0,     5,     0,     0,     0,     0,    11,     2,     0,
       0,     0,     8,     3,     0,     0,     0,     0,    10,     0,
       0,     0,     0,    15,     0,     5,     3,     1,     0,     1
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
#line 131 "parser.y" /* yacc.c:1646  */
    {}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 133 "parser.y" /* yacc.c:1646  */
    {}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "parser.y" /* yacc.c:1646  */
    {
                        scope_history.push(++scope_counter);
                    }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 141 "parser.y" /* yacc.c:1646  */
    {
                        scope_history.pop();
                        tac.push_back("end:\n");
                    }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 147 "parser.y" /* yacc.c:1646  */
    {   
                        if(func_table.find(string((yyvsp[0].node).lexeme)) != func_table.end()){
                            sem_errors.push_back("Error: Duplicate function name - " + string((yyvsp[0].node).lexeme));
                        }
                        tac.push_back(string((yyvsp[0].node).lexeme) + ":"); 
                        curr_func_name = string((yyvsp[0].node).lexeme);
                    }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 154 "parser.y" /* yacc.c:1646  */
    {
                        func_table[curr_func_name].return_type = string((yyvsp[-5].node).type);
                        func_table[curr_func_name].num_params = (yyvsp[-1].node).nParams;
                    }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                    }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 162 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyval.node).type, "void");
                    }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "parser.y" /* yacc.c:1646  */
    {
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));                       
                    }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 172 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = (yyvsp[0].node).nParams + 1;
                    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 175 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = 1;
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));
                    }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = 0;
                    }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 186 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node).nParams = 1;
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);                    }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 203 "parser.y" /* yacc.c:1646  */
    {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 208 "parser.y" /* yacc.c:1646  */
    {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 214 "parser.y" /* yacc.c:1646  */
    {
                        check_declaration(string((yyvsp[-2].node).lexeme));
                        check_scope(string((yyvsp[-2].node).lexeme));
                        tac.push_back("input " + string((yyvsp[-2].node).lexeme) + " " + symbol_table[string((yyvsp[-4].node).lexeme)].data_type);
                    }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 219 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-2].node).type));
                    }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 222 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " STR");
                    }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 228 "parser.y" /* yacc.c:1646  */
    { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        multiple_declaration(string((yyvsp[-1].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)] = { string((yyvsp[-2].node).type), scope_counter, 0, 0, countn+1 };
                    }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 234 "parser.y" /* yacc.c:1646  */
    {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        tac.push_back("- STR " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " STR");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { "STR", string((yyvsp[-1].node).lexeme).length(), 0, countn+1 };
                    }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 241 "parser.y" /* yacc.c:1646  */
    {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        check_type(string((yyvsp[-4].node).type), string((yyvsp[-1].node).type));
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[-4].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), scope_counter, 0, 0, countn+1 };
                    }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 249 "parser.y" /* yacc.c:1646  */
    {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                    }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 255 "parser.y" /* yacc.c:1646  */
    {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                        curr_array = string((yyvsp[-4].node).lexeme);
                    }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 264 "parser.y" /* yacc.c:1646  */
    {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]’");
                        }
                    }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 272 "parser.y" /* yacc.c:1646  */
    {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]’");
                        }
                        arr_index=0;
                    }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 282 "parser.y" /* yacc.c:1646  */
    {
                        check_type(func_table[curr_func_name].return_type, string((yyvsp[0].node).type));
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].return_type);
                    }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 288 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "INT");
                    }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 291 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "FLOAT");
                    }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 294 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "CHAR");
                    }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 301 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 305 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 309 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string t0="@t" + to_string(++variable_count);
                        string t1="@t" + to_string(++variable_count);
                        string t2="@t" + to_string(++variable_count);
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string c = string((yyvsp[0].node).lexeme);
                        string dtype = string((yyval.node).type);
                        
                        tac.push_back(a + " = 0 " + dtype);
                        tac.push_back(t0 + " = 0 " + dtype);
                        tac.push_back(t2 + " = 1 " + dtype);
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t1 + " = " + t0 + " < " + c +  "  " + dtype);
                        tac.push_back("if " + t1 + " GOTO " + "#L" + to_string(label_counter+1) + " else GOTO " + "#L" + to_string(label_counter+2));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(a + " = " + a + " + " + b +  "  " + dtype);
                        tac.push_back(t0 + " = " + t0 + " + " + t2 +  "  " + dtype);
                        tac.push_back("GOTO #L" + to_string(label_counter-1));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 331 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string t0="@t" + to_string(++variable_count);
                        string t1="@t" + to_string(++variable_count);
                        string t2="@t" + to_string(++variable_count);
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string c = string((yyvsp[0].node).lexeme);
                        string dtype = string((yyval.node).type);
                        
                        tac.push_back(a + " = 0 " + dtype);
                        tac.push_back(t0 + " = " + b + " " + dtype);
                        tac.push_back(t2 + " = 1 " + dtype);
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t1 + " = " + t0 + " >= " + c +  "  " + dtype);
                        tac.push_back("if " + t1 + " GOTO " + "#L" + to_string(label_counter+1) + " else GOTO " + "#L" + to_string(label_counter+2));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(a + " = " + a + " + " + t2 +  "  " + dtype);
                        tac.push_back(t0 + " = " + t0 + " - " + c +  "  " + dtype);
                        tac.push_back("GOTO #L" + to_string(label_counter-1));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                    }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 353 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = "@t" + to_string(++variable_count);
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " > " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ! " + temp + " " + string((yyval.node).type)); 
                    }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 359 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = "@t" + to_string(++variable_count);
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " < " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ! " + temp + " " + string((yyval.node).type)); 
                    }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 365 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 369 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 373 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 377 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = "@t" + to_string(++variable_count);
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " == " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ! " + temp + " " + string((yyval.node).type)); 
                    }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 383 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string l0 = "#L" + to_string(++label_counter);
                        string l1 = "#L" + to_string(++label_counter);
                        string l2 = "#L" + to_string(++label_counter);
                        string l3 = "#L" + to_string(++label_counter);
                        string dtype = string((yyval.node).type);

                        tac.push_back("if " + string((yyvsp[-2].node).lexeme) + " GOTO " + l3 + " else GOTO " + l1);
                        tac.push_back(l3 + ":");
                        tac.push_back("if " + string((yyvsp[0].node).lexeme) + " GOTO " + l0 + " else GOTO " + l1);
                        tac.push_back(l0 + ":");
                        tac.push_back(string((yyval.node).lexeme) + " = 1 " + dtype);
                        tac.push_back("GOTO " + l2);
                        tac.push_back(l1 + ":");
                        tac.push_back(string((yyval.node).lexeme) + " = 0 " + dtype);
                        tac.push_back(l2 + ":");
                    }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 401 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string l0 = "#L" + to_string(++label_counter);
                        string l1 = "#L" + to_string(++label_counter);
                        string l2 = "#L" + to_string(++label_counter);
                        string l3 = "#L" + to_string(++label_counter);
                        string dtype = string((yyval.node).type);

                        tac.push_back("if " + string((yyvsp[-2].node).lexeme) + " GOTO " + l0 + " else GOTO " + l3);
                        tac.push_back(l3 + ":");
                        tac.push_back("if " + string((yyvsp[0].node).lexeme) + " GOTO " + l0 + " else GOTO " + l1);
                        tac.push_back(l0 + ":");
                        tac.push_back(string((yyval.node).lexeme) + " = 1 " + dtype);
                        tac.push_back("GOTO " + l2);
                        tac.push_back(l1 + ":");
                        tac.push_back(string((yyval.node).lexeme) + " = 0 " + dtype);
                        tac.push_back(l2 + ":");
                    }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 419 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string t0="@t" + to_string(++variable_count);
                        string t1="@t" + to_string(++variable_count);
                        string t2="@t" + to_string(++variable_count);
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string c = string((yyvsp[0].node).lexeme);
                        string dtype = string((yyval.node).type);
                        
                        tac.push_back(a + " = 0 " + dtype);
                        tac.push_back(t0 + " = " + b + " " + dtype);
                        tac.push_back(t2 + " = 1 " + dtype);
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t1 + " = " + t0 + " >= " + c +  "  " + dtype);
                        tac.push_back("if " + t1 + " GOTO " + "#L" + to_string(label_counter+1) + " else GOTO " + "#L" + to_string(label_counter+2));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t0 + " = " + t0 + " - " + c +  "  " + dtype);
                        tac.push_back("GOTO #L" + to_string(label_counter-1));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(a + " = " + t0 +  "  " + dtype);
                    }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 441 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 445 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 449 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string b_= "@t" + to_string(++variable_count);
                        string c = string((yyvsp[0].node).lexeme);
                        string c_= "@t" + to_string(++variable_count);

                        tac.push_back(b_ + " = ! " + b + " " + string((yyvsp[-2].node).type));
                        tac.push_back(c_ + " = ! " + c + " " + string((yyvsp[0].node).type));
                        tac.push_back("@t" + to_string(++variable_count) + " = " + b + " & " + c_ + " " + string((yyval.node).type));
                        tac.push_back("@t" + to_string(++variable_count) + " = " + b_ + " & " + c + " " + string((yyval.node).type));
                        tac.push_back(a + " = " + "@t" + to_string(variable_count-1) + " | " + "@t" + to_string(variable_count));
                    }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 463 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 466 "parser.y" /* yacc.c:1646  */
    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 469 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 474 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 479 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 484 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 489 "parser.y" /* yacc.c:1646  */
    {
                        if(check_declaration(string((yyvsp[-3].node).lexeme)) && func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Variable is not an array"); 
                        }
                        check_scope(string((yyvsp[-3].node).lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].data_type.c_str());
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-3].node).lexeme) + " [ " + string((yyvsp[-1].node).lexeme) + " ] " + " " + string((yyval.node).type));
                    }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 500 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 507 "parser.y" /* yacc.c:1646  */
    {
                        check_declaration(string((yyvsp[0].node).lexeme));
                        check_scope(string((yyvsp[0].node).lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type.c_str());
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 513 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count);
                        if(temp_map[string((yyvsp[0].node).lexeme)] == ""){
                            tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type)); 
                            temp_map[string((yyvsp[0].node).lexeme)] = string((yyval.node).lexeme);
                            variable_count++;
                        }
                        else{
                            tac.push_back(temp_map[string((yyvsp[0].node).lexeme)] + " = " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type)); 
                        }
                    }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 525 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[-1].node).lexeme);
                    }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 537 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "INT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 541 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "FLOAT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 545 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, "CHAR");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 551 "parser.y" /* yacc.c:1646  */
    {
                        check_type(func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type, string((yyvsp[0].node).type));
                        check_declaration(string((yyvsp[-2].node).lexeme));
                        check_scope(string((yyvsp[-2].node).lexeme));
                        tac.push_back(string((yyvsp[-2].node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type);
                    }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 558 "parser.y" /* yacc.c:1646  */
    {
                        check_type(func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type, string((yyvsp[0].node).type));
                        if(check_declaration(string((yyvsp[-5].node).lexeme)) && func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Line no " + to_string(countn+1) + " : Variable is not an array"); 
                        }
                        check_scope(string((yyvsp[-5].node).lexeme));
                        tac.push_back(string((yyvsp[-5].node).lexeme) + " [ " + string((yyvsp[-3].node).lexeme) + " ] " + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                    }
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 567 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 570 "parser.y" /* yacc.c:1646  */
    { 
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 577 "parser.y" /* yacc.c:1646  */
    {
                      scope_history.push(++scope_counter);  
                    }
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 579 "parser.y" /* yacc.c:1646  */
    {  
                        scope_history.pop(); 
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 584 "parser.y" /* yacc.c:1646  */
    {   
                        tac.push_back(string((yyvsp[-12].node).parentNext) + ":");
                    }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 589 "parser.y" /* yacc.c:1646  */
    {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf((yyvsp[0].node).parentNext, "%s", hold);
                    }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 594 "parser.y" /* yacc.c:1646  */
    {
                        // sprintf(icg[ic_idx++], "\nif (%s != 0) GOTO L%d else GOTO L%d\n", $4.token, label, label+1);
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 602 "parser.y" /* yacc.c:1646  */
    {
                        scope_history.push(++scope_counter);
                    }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 605 "parser.y" /* yacc.c:1646  */
    {
                        scope_history.pop();
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 614 "parser.y" /* yacc.c:1646  */
    {scope_history.push(++scope_counter);}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 614 "parser.y" /* yacc.c:1646  */
    {scope_history.pop();}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 618 "parser.y" /* yacc.c:1646  */
    {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 623 "parser.y" /* yacc.c:1646  */
    {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme));
                    }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 627 "parser.y" /* yacc.c:1646  */
    {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 631 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("Label " + string((yyvsp[-10].node).parentNext));
                        loop_break.pop();
                    }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 637 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyvsp[-1].node).id, (yyval.node).id);
                        strcpy((yyvsp[-1].node).parentNext, (yyval.node).parentNext);
                    }
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 644 "parser.y" /* yacc.c:1646  */
    {
                        // tac.push_back(string($4.if_body) + ":");
                    }
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 647 "parser.y" /* yacc.c:1646  */
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
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 657 "parser.y" /* yacc.c:1646  */
    {
                        // tac.push_back("Label " + string($4.parentNext) + ":");
                        tac.push_back("Label " + string((yyvsp[-4].node).parentNext) + ":");
                    }
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 666 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyvsp[0].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[0].node).loop_body) + ":");
                    }
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 672 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));
                        tac.push_back("\n" + string((yyvsp[-1].node).if_body) + ":");
                        
                    }
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 682 "parser.y" /* yacc.c:1646  */
    {
                        scope_history.push(++scope_counter);
                    }
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 685 "parser.y" /* yacc.c:1646  */
    {
                        scope_history.pop();
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-6].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 693 "parser.y" /* yacc.c:1646  */
    {
                        sprintf((yyvsp[-3].node).loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string((yyvsp[-3].node).loop_body) + ":");
                    }
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 697 "parser.y" /* yacc.c:1646  */
    {  
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));

                        sprintf((yyvsp[-1].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[-1].node).loop_body) + ":");
                    }
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 709 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-4].node).if_body) + ":");
                    }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 714 "parser.y" /* yacc.c:1646  */
    {
                        scope_history.push(++scope_counter);
                    }
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 717 "parser.y" /* yacc.c:1646  */
    {
                        scope_history.pop();
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-9].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 725 "parser.y" /* yacc.c:1646  */
    {
                        func_call_id.push({string((yyvsp[0].node).lexeme), func_table[string((yyvsp[0].node).lexeme)].param_types});
                        }
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 728 "parser.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.node).type, func_table[string((yyvsp[-4].node).lexeme)].return_type.c_str());
                        func_call_id.pop();
                        sprintf((yyval.node).lexeme, "@t%d", variable_count);
                        variable_count++;

                        // checking if function is declared
                        

                        tac.push_back(string((yyval.node).lexeme) + " = @call " + string((yyvsp[-4].node).lexeme) + " " + func_table[string((yyvsp[-4].node).lexeme)].return_type + " " + to_string(func_table[string((yyvsp[-4].node).lexeme)].num_params));
                    }
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 741 "parser.y" /* yacc.c:1646  */
    {
                        // cout << string($1.lexeme) << endl;
                        // cout << "here" << string($1.type) << endl;
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        // cout << "there" << type << endl;
                        func_call_id.top().second.pop_back();
                        // cout << type << endl;
                        if(type_check(string((yyvsp[-2].node).type), type)) {
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 753 "parser.y" /* yacc.c:1646  */
    {
                        // cout << string($1.lexeme) << endl;
                        // cout << "here" << string($1.type) << endl;
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        // cout << "there" << type << endl;
                        func_call_id.top().second.pop_back();
                        if(type_check(string((yyvsp[0].node).type), type)) {
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 767 "parser.y" /* yacc.c:1646  */
    {
                        tac.push_back("param " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                    }
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2681 "y.tab.c" /* yacc.c:1646  */
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
#line 772 "parser.y" /* yacc.c:1906  */


int main(int argc, char *argv[]) {
    /* yydebug = 1; */
    yyparse();
    for(auto x: tac)
        cout << x << endl;
    for(auto item: sem_errors)
        cout << item << endl;
    /* for(auto item: func_table[curr_func_name].symbol_table)
        cout << item.first << "-->" << item.second.data_type << endl; */
    // cout << endl << "Symbol table" << endl;
    // for(auto item : func_table["main"].symbol_table){
    //     cout << item.first << " ---> " << item.second.scope <<endl;
    // }

    // for(auto i: temp_map){
    //     cout << i.first << " --- " << i.second << endl;
    // }

}

bool check_declaration(string variable){
    if(func_table[curr_func_name].symbol_table.find(variable) == func_table[curr_func_name].symbol_table.end()){
        sem_errors.push_back("Variable not declared in line " + to_string(countn+1) + " before usage.");
        return false;
    }
    return true;
}

bool check_scope(string variable){
    int var_scope = func_table[curr_func_name].symbol_table[variable].scope;
    // int curr_scope = scope_counter;
    stack<int> temp_stack(scope_history);
    while(!temp_stack.empty()){
        if(temp_stack.top() == var_scope){
            return false;
        }
        temp_stack.pop();
    }
    sem_errors.push_back("Scope of variable '" + variable +"' not marching in line " + to_string(countn+1) + ".");
    return true;
}

bool multiple_declaration(string variable){
    if(!(func_table[curr_func_name].symbol_table.find(variable) == func_table[curr_func_name].symbol_table.end())){
        sem_errors.push_back("redeclaration of '" + variable + "' in line " + to_string(countn+1));
        return false;
    }
    return true;
}

bool check_type(string l, string r){
    if(r == "FLOAT" && l == "CHAR"){
        sem_errors.push_back("Cannot convert type FLOAT to CHAR in line " + to_string(countn+1));
        return false;
    }
    if(l == "FLOAT" && r == "CHAR"){
        sem_errors.push_back("Cannot convert typr CHAR to FLOAT in line " + to_string(countn+1));
        return false;
    }
    return true;
}

bool is_reserved_word(string id){
    for(auto &item: id){
        item = tolower(item);
    }
    auto iterator = find(reserved.begin(), reserved.end(), id);
    if(iterator != reserved.end()){
        sem_errors.push_back("usage of reserved keyword '" + id + "' in line " + to_string(countn+1));
        return true;
    }
    return false;
}

bool type_check(string type1, string type2) {
    if((type1 == "FLOAT" and type2 == "CHAR") or (type1 == "CHAR" and type2 == "FLOAT")) {
        return true;
    }
    return false;
}

void yyerror(const char* msg) {
    sem_errors.push_back("syntax error in line " + to_string(countn+1));
    for(auto item: sem_errors)
        cout << item << endl;
    fprintf(stderr, "%s\n", msg);
    exit(1);
}


// check if void functions has return type
// deal with scope for function arguments
// deal with scope for arrays
// scope in switch statement


// check for f user-defined variables in if-goto statements
