/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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
    #include<algorithm>

    using namespace std;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int yytext();

    bool check_declaration(string variable);
    bool multiple_declaration(string variable);
    bool is_reserved_word(string id);

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

    vector<string> reserved = {"int", "float", "char", "void", "if", "elif", "else", "for", "while", "break", "continue", "main", "return", "switch", "case", "input", "output"};

#line 159 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    CHAR = 259,                    /* CHAR  */
    FLOAT = 260,                   /* FLOAT  */
    STRING = 261,                  /* STRING  */
    VOID = 262,                    /* VOID  */
    RETURN = 263,                  /* RETURN  */
    INT_NUM = 264,                 /* INT_NUM  */
    FLOAT_NUM = 265,               /* FLOAT_NUM  */
    ID = 266,                      /* ID  */
    LEFTSHIFT = 267,               /* LEFTSHIFT  */
    RIGHTSHIFT = 268,              /* RIGHTSHIFT  */
    LE = 269,                      /* LE  */
    GE = 270,                      /* GE  */
    EQ = 271,                      /* EQ  */
    NE = 272,                      /* NE  */
    GT = 273,                      /* GT  */
    LT = 274,                      /* LT  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    NOT = 277,                     /* NOT  */
    ADD = 278,                     /* ADD  */
    SUBTRACT = 279,                /* SUBTRACT  */
    DIVIDE = 280,                  /* DIVIDE  */
    MULTIPLY = 281,                /* MULTIPLY  */
    MODULO = 282,                  /* MODULO  */
    BITAND = 283,                  /* BITAND  */
    BITOR = 284,                   /* BITOR  */
    NEGATION = 285,                /* NEGATION  */
    XOR = 286,                     /* XOR  */
    STR = 287,                     /* STR  */
    CHARACTER = 288,               /* CHARACTER  */
    CC = 289,                      /* CC  */
    OC = 290,                      /* OC  */
    CS = 291,                      /* CS  */
    OS = 292,                      /* OS  */
    CF = 293,                      /* CF  */
    OF = 294,                      /* OF  */
    COMMA = 295,                   /* COMMA  */
    COLON = 296,                   /* COLON  */
    SCOL = 297,                    /* SCOL  */
    OUTPUT = 298,                  /* OUTPUT  */
    INPUT = 299,                   /* INPUT  */
    SWITCH = 300,                  /* SWITCH  */
    CASE = 301,                    /* CASE  */
    BREAK = 302,                   /* BREAK  */
    DEFAULT = 303,                 /* DEFAULT  */
    IF = 304,                      /* IF  */
    ELIF = 305,                    /* ELIF  */
    ELSE = 306,                    /* ELSE  */
    WHILE = 307,                   /* WHILE  */
    FOR = 308,                     /* FOR  */
    CONTINUE = 309,                /* CONTINUE  */
    ASSIGN = 310                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#line 89 "parser.y"

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

#line 339 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_INT_NUM = 9,                    /* INT_NUM  */
  YYSYMBOL_FLOAT_NUM = 10,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_LEFTSHIFT = 12,                 /* LEFTSHIFT  */
  YYSYMBOL_RIGHTSHIFT = 13,                /* RIGHTSHIFT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NE = 17,                        /* NE  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_ADD = 23,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 24,                  /* SUBTRACT  */
  YYSYMBOL_DIVIDE = 25,                    /* DIVIDE  */
  YYSYMBOL_MULTIPLY = 26,                  /* MULTIPLY  */
  YYSYMBOL_MODULO = 27,                    /* MODULO  */
  YYSYMBOL_BITAND = 28,                    /* BITAND  */
  YYSYMBOL_BITOR = 29,                     /* BITOR  */
  YYSYMBOL_NEGATION = 30,                  /* NEGATION  */
  YYSYMBOL_XOR = 31,                       /* XOR  */
  YYSYMBOL_STR = 32,                       /* STR  */
  YYSYMBOL_CHARACTER = 33,                 /* CHARACTER  */
  YYSYMBOL_CC = 34,                        /* CC  */
  YYSYMBOL_OC = 35,                        /* OC  */
  YYSYMBOL_CS = 36,                        /* CS  */
  YYSYMBOL_OS = 37,                        /* OS  */
  YYSYMBOL_CF = 38,                        /* CF  */
  YYSYMBOL_OF = 39,                        /* OF  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_SCOL = 42,                      /* SCOL  */
  YYSYMBOL_OUTPUT = 43,                    /* OUTPUT  */
  YYSYMBOL_INPUT = 44,                     /* INPUT  */
  YYSYMBOL_SWITCH = 45,                    /* SWITCH  */
  YYSYMBOL_CASE = 46,                      /* CASE  */
  YYSYMBOL_BREAK = 47,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 48,                   /* DEFAULT  */
  YYSYMBOL_IF = 49,                        /* IF  */
  YYSYMBOL_ELIF = 50,                      /* ELIF  */
  YYSYMBOL_ELSE = 51,                      /* ELSE  */
  YYSYMBOL_WHILE = 52,                     /* WHILE  */
  YYSYMBOL_FOR = 53,                       /* FOR  */
  YYSYMBOL_CONTINUE = 54,                  /* CONTINUE  */
  YYSYMBOL_ASSIGN = 55,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_Program = 57,                   /* Program  */
  YYSYMBOL_func_list = 58,                 /* func_list  */
  YYSYMBOL_func = 59,                      /* func  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_func_prefix = 61,               /* func_prefix  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_func_data_type = 63,            /* func_data_type  */
  YYSYMBOL_param_list = 64,                /* param_list  */
  YYSYMBOL_param = 65,                     /* param  */
  YYSYMBOL_stmt_list = 66,                 /* stmt_list  */
  YYSYMBOL_stmt = 67,                      /* stmt  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_69_3 = 69,                      /* $@3  */
  YYSYMBOL_arr_values = 70,                /* arr_values  */
  YYSYMBOL_71_4 = 71,                      /* $@4  */
  YYSYMBOL_return_stmt = 72,               /* return_stmt  */
  YYSYMBOL_data_type = 73,                 /* data_type  */
  YYSYMBOL_expr = 74,                      /* expr  */
  YYSYMBOL_postfix_expr = 75,              /* postfix_expr  */
  YYSYMBOL_unary_expr = 76,                /* unary_expr  */
  YYSYMBOL_primary_expr = 77,              /* primary_expr  */
  YYSYMBOL_unary_op = 78,                  /* unary_op  */
  YYSYMBOL_const = 79,                     /* const  */
  YYSYMBOL_assign = 80,                    /* assign  */
  YYSYMBOL_if_stmt = 81,                   /* if_stmt  */
  YYSYMBOL_82_5 = 82,                      /* $@5  */
  YYSYMBOL_83_6 = 83,                      /* $@6  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_elif_stmt = 85,                 /* elif_stmt  */
  YYSYMBOL_86_8 = 86,                      /* $@8  */
  YYSYMBOL_87_9 = 87,                      /* $@9  */
  YYSYMBOL_88_10 = 88,                     /* $@10  */
  YYSYMBOL_else_stmt = 89,                 /* else_stmt  */
  YYSYMBOL_switch_stmt = 90,               /* switch_stmt  */
  YYSYMBOL_91_11 = 91,                     /* $@11  */
  YYSYMBOL_92_12 = 92,                     /* $@12  */
  YYSYMBOL_93_13 = 93,                     /* $@13  */
  YYSYMBOL_case_stmt_list = 94,            /* case_stmt_list  */
  YYSYMBOL_case_stmt = 95,                 /* case_stmt  */
  YYSYMBOL_96_14 = 96,                     /* $@14  */
  YYSYMBOL_97_15 = 97,                     /* $@15  */
  YYSYMBOL_default_stmt = 98,              /* default_stmt  */
  YYSYMBOL_while_loop_stmt = 99,           /* while_loop_stmt  */
  YYSYMBOL_100_16 = 100,                   /* $@16  */
  YYSYMBOL_101_17 = 101,                   /* $@17  */
  YYSYMBOL_for_loop_stmt = 102,            /* for_loop_stmt  */
  YYSYMBOL_103_18 = 103,                   /* $@18  */
  YYSYMBOL_104_19 = 104,                   /* $@19  */
  YYSYMBOL_105_20 = 105,                   /* $@20  */
  YYSYMBOL_func_call = 106,                /* func_call  */
  YYSYMBOL_arg_list = 107,                 /* arg_list  */
  YYSYMBOL_arg = 108                       /* arg  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   127,   128,   131,   131,   139,   139,   156,
     157,   160,   163,   166,   171,   175,   180,   181,   184,   185,
     186,   187,   188,   189,   190,   191,   196,   201,   202,   206,
     211,   222,   229,   235,   235,   244,   244,   251,   260,   265,
     268,   271,   278,   281,   284,   287,   290,   293,   296,   299,
     302,   305,   308,   311,   314,   317,   320,   323,   326,   329,
     332,   337,   342,   347,   352,   362,   369,   374,   379,   385,
     386,   387,   388,   391,   395,   399,   405,   410,   418,   421,
     427,   418,   436,   441,   448,   436,   453,   456,   457,   460,
     465,   469,   460,   479,   483,   486,   489,   486,   504,   505,
     508,   514,   508,   532,   536,   548,   532,   559,   587,   588,
     589,   592
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "CHAR", "FLOAT",
  "STRING", "VOID", "RETURN", "INT_NUM", "FLOAT_NUM", "ID", "LEFTSHIFT",
  "RIGHTSHIFT", "LE", "GE", "EQ", "NE", "GT", "LT", "AND", "OR", "NOT",
  "ADD", "SUBTRACT", "DIVIDE", "MULTIPLY", "MODULO", "BITAND", "BITOR",
  "NEGATION", "XOR", "STR", "CHARACTER", "CC", "OC", "CS", "OS", "CF",
  "OF", "COMMA", "COLON", "SCOL", "OUTPUT", "INPUT", "SWITCH", "CASE",
  "BREAK", "DEFAULT", "IF", "ELIF", "ELSE", "WHILE", "FOR", "CONTINUE",
  "ASSIGN", "$accept", "Program", "func_list", "func", "$@1",
  "func_prefix", "$@2", "func_data_type", "param_list", "param",
  "stmt_list", "stmt", "declaration", "$@3", "arr_values", "$@4",
  "return_stmt", "data_type", "expr", "postfix_expr", "unary_expr",
  "primary_expr", "unary_op", "const", "assign", "if_stmt", "$@5", "$@6",
  "$@7", "elif_stmt", "$@8", "$@9", "$@10", "else_stmt", "switch_stmt",
  "$@11", "$@12", "$@13", "case_stmt_list", "case_stmt", "$@14", "$@15",
  "default_stmt", "while_loop_stmt", "$@16", "$@17", "for_loop_stmt",
  "$@18", "$@19", "$@20", "func_call", "arg_list", "arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-172)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
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
static const yytype_int8 yydefact[] =
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
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     5,    10,    50,    11,   127,   128,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: func_list  */
#line 125 "parser.y"
                              {}
#line 1652 "y.tab.c"
    break;

  case 3: /* func_list: func_list func  */
#line 127 "parser.y"
                                   {}
#line 1658 "y.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 131 "parser.y"
                    {
                        func_table[func_ind].count = 0;
                    }
#line 1666 "y.tab.c"
    break;

  case 6: /* func: $@1 func_prefix OF stmt_list CF  */
#line 134 "parser.y"
                                                {
                        func_ind++; 
                        tac.push_back("end:\n");
                    }
#line 1675 "y.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 139 "parser.y"
                                      {tac.push_back(string((yyvsp[0].node).lexeme) + ":"); sprintf(curr_func_name, "%s", (yyvsp[0].node).lexeme);}
#line 1681 "y.tab.c"
    break;

  case 8: /* func_prefix: func_data_type ID $@2 OC param_list CC  */
#line 139 "parser.y"
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
#line 1702 "y.tab.c"
    break;

  case 11: /* param_list: param_list COMMA param  */
#line 160 "parser.y"
                                           {
                        (yyval.node).nParams = (yyvsp[-2].node).nParams + 1;
                    }
#line 1710 "y.tab.c"
    break;

  case 12: /* param_list: param  */
#line 163 "parser.y"
                            {
                        (yyval.node).nParams = (yyvsp[0].node).nParams;
                    }
#line 1718 "y.tab.c"
    break;

  case 13: /* param_list: %empty  */
#line 166 "parser.y"
                      {
                        (yyval.node).nParams = 0;
                    }
#line 1726 "y.tab.c"
    break;

  case 14: /* param: data_type ID  */
#line 171 "parser.y"
                                 {
                        (yyval.node).nParams = 1;
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 1735 "y.tab.c"
    break;

  case 15: /* param: data_type ID OS CS COLON INT ID  */
#line 175 "parser.y"
                                                      {
                        (yyval.node).nParams = 1;                        
                    }
#line 1743 "y.tab.c"
    break;

  case 25: /* stmt: BREAK SCOL  */
#line 191 "parser.y"
                                 {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
#line 1753 "y.tab.c"
    break;

  case 26: /* stmt: CONTINUE SCOL  */
#line 196 "parser.y"
                                    {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }
#line 1763 "y.tab.c"
    break;

  case 28: /* stmt: INPUT OC ID CC SCOL  */
#line 202 "parser.y"
                                           {
                        check_declaration((yyvsp[-2].node).lexeme);
                        tac.push_back("input " + string((yyvsp[-2].node).lexeme) + " " + symbol_table[string((yyvsp[-4].node).lexeme)].data_type);
                    }
#line 1772 "y.tab.c"
    break;

  case 29: /* stmt: OUTPUT OC expr CC SCOL  */
#line 206 "parser.y"
                                             {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-2].node).type));
                    }
#line 1780 "y.tab.c"
    break;

  case 30: /* declaration: data_type ID SCOL  */
#line 211 "parser.y"
                                      { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        multiple_declaration(string((yyvsp[-1].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        symbol_table[string((yyvsp[-1].node).lexeme)] = { string((yyvsp[-2].node).type), 0, 0, countn+1 };
                    }
#line 1791 "y.tab.c"
    break;

  case 31: /* declaration: data_type ID ASSIGN expr SCOL  */
#line 222 "parser.y"
                                                    {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[-4].node).type));
                        symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), 0, 0, countn+1 };
                    }
#line 1803 "y.tab.c"
    break;

  case 32: /* declaration: data_type ID OS INT_NUM CS SCOL  */
#line 229 "parser.y"
                                                      {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                    }
#line 1814 "y.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 235 "parser.y"
                                                        {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                        curr_array = string((yyvsp[-4].node).lexeme);
                    }
#line 1826 "y.tab.c"
    break;

  case 35: /* $@4: %empty  */
#line 244 "parser.y"
                          {
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme));
                        if(arr_index > symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(symbol_table[curr_array].size) + "]’");
                        }
                    }
#line 1837 "y.tab.c"
    break;

  case 37: /* arr_values: const  */
#line 251 "parser.y"
                            {
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme));
                        if(arr_index > symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(symbol_table[curr_array].size) + "]’");
                        }
                        arr_index=0;
                    }
#line 1849 "y.tab.c"
    break;

  case 38: /* return_stmt: RETURN expr  */
#line 260 "parser.y"
                                {
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                    }
#line 1857 "y.tab.c"
    break;

  case 39: /* data_type: INT  */
#line 265 "parser.y"
                        {
                        strcpy((yyval.node).type, "INT");
                    }
#line 1865 "y.tab.c"
    break;

  case 40: /* data_type: FLOAT  */
#line 268 "parser.y"
                            {
                        strcpy((yyval.node).type, "FLOAT");
                    }
#line 1873 "y.tab.c"
    break;

  case 41: /* data_type: CHAR  */
#line 271 "parser.y"
                           {
                        strcpy((yyval.node).type, "CHAR");
                    }
#line 1881 "y.tab.c"
    break;

  case 42: /* expr: expr ADD expr  */
#line 278 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1889 "y.tab.c"
    break;

  case 43: /* expr: expr SUBTRACT expr  */
#line 281 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1897 "y.tab.c"
    break;

  case 44: /* expr: expr MULTIPLY expr  */
#line 284 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1905 "y.tab.c"
    break;

  case 45: /* expr: expr DIVIDE expr  */
#line 287 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1913 "y.tab.c"
    break;

  case 46: /* expr: expr LE expr  */
#line 290 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1921 "y.tab.c"
    break;

  case 47: /* expr: expr GE expr  */
#line 293 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1929 "y.tab.c"
    break;

  case 48: /* expr: expr LT expr  */
#line 296 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1937 "y.tab.c"
    break;

  case 49: /* expr: expr GT expr  */
#line 299 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1945 "y.tab.c"
    break;

  case 50: /* expr: expr EQ expr  */
#line 302 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1953 "y.tab.c"
    break;

  case 51: /* expr: expr NE expr  */
#line 305 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1961 "y.tab.c"
    break;

  case 52: /* expr: expr AND expr  */
#line 308 "parser.y"
                                    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1969 "y.tab.c"
    break;

  case 53: /* expr: expr OR expr  */
#line 311 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1977 "y.tab.c"
    break;

  case 54: /* expr: expr MODULO expr  */
#line 314 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1985 "y.tab.c"
    break;

  case 55: /* expr: expr BITAND expr  */
#line 317 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1993 "y.tab.c"
    break;

  case 56: /* expr: expr BITOR expr  */
#line 320 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2001 "y.tab.c"
    break;

  case 57: /* expr: expr XOR expr  */
#line 323 "parser.y"
                                    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2009 "y.tab.c"
    break;

  case 58: /* expr: expr LEFTSHIFT expr  */
#line 326 "parser.y"
                                          {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2017 "y.tab.c"
    break;

  case 59: /* expr: expr RIGHTSHIFT expr  */
#line 329 "parser.y"
                                           {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2025 "y.tab.c"
    break;

  case 60: /* expr: unary_expr  */
#line 332 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2035 "y.tab.c"
    break;

  case 61: /* expr: primary_expr  */
#line 337 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2045 "y.tab.c"
    break;

  case 62: /* expr: postfix_expr  */
#line 342 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2054 "y.tab.c"
    break;

  case 63: /* postfix_expr: func_call  */
#line 347 "parser.y"
                              {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2063 "y.tab.c"
    break;

  case 64: /* postfix_expr: ID OS expr CS  */
#line 352 "parser.y"
                                  {
                        if(check_declaration(string((yyvsp[-3].node).lexeme)) && symbol_table[string((yyvsp[-3].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Variable is not an array"); 
                        }
                        strcpy((yyval.node).type, symbol_table[string((yyvsp[-3].node).lexeme)].data_type.c_str());
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-3].node).lexeme) + " [ " + string((yyvsp[-1].node).lexeme) + " ] " + " " + string((yyval.node).type));
                    }
#line 2076 "y.tab.c"
    break;

  case 65: /* unary_expr: unary_op primary_expr  */
#line 362 "parser.y"
                                          {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2086 "y.tab.c"
    break;

  case 66: /* primary_expr: ID  */
#line 369 "parser.y"
                       {
                        check_declaration(string((yyvsp[0].node).lexeme));
                        strcpy((yyval.node).type, symbol_table[string((yyvsp[0].node).lexeme)].data_type.c_str());
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2096 "y.tab.c"
    break;

  case 67: /* primary_expr: const  */
#line 374 "parser.y"
                            {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type)); 
                    }
#line 2106 "y.tab.c"
    break;

  case 68: /* primary_expr: OC expr CC  */
#line 379 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[-1].node).lexeme);
                    }
#line 2115 "y.tab.c"
    break;

  case 73: /* const: INT_NUM  */
#line 391 "parser.y"
                            {
                        strcpy((yyval.node).type, "INT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2124 "y.tab.c"
    break;

  case 74: /* const: FLOAT_NUM  */
#line 395 "parser.y"
                                {
                        strcpy((yyval.node).type, "FLOAT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2133 "y.tab.c"
    break;

  case 75: /* const: CHARACTER  */
#line 399 "parser.y"
                                {
                        strcpy((yyval.node).type, "CHAR");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2142 "y.tab.c"
    break;

  case 76: /* assign: ID ASSIGN expr  */
#line 405 "parser.y"
                                   {
                        check_declaration(string((yyvsp[-2].node).lexeme));
                        tac.push_back(string((yyvsp[-2].node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + symbol_table[string((yyvsp[-2].node).lexeme)].data_type);
                    }
#line 2151 "y.tab.c"
    break;

  case 77: /* assign: ID OS expr CS ASSIGN expr  */
#line 410 "parser.y"
                                              {
                        if(check_declaration(string((yyvsp[-5].node).lexeme)) && symbol_table[string((yyvsp[-5].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Variable is not an array"); 
                        }
                        tac.push_back(string((yyvsp[-5].node).lexeme) + " [ " + string((yyvsp[-3].node).lexeme) + " ] " + " = " + string((yyvsp[0].node).lexeme) + " " + symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                    }
#line 2162 "y.tab.c"
    break;

  case 78: /* $@5: %empty  */
#line 418 "parser.y"
                        {
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2170 "y.tab.c"
    break;

  case 79: /* $@6: %empty  */
#line 421 "parser.y"
                               { 
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2181 "y.tab.c"
    break;

  case 80: /* $@7: %empty  */
#line 427 "parser.y"
                                    {  
                        tac.push_back("GOTO " + string((yyvsp[-8].node).parentNext));
                        tac.push_back(string((yyvsp[-5].node).else_body) + ":");
                    }
#line 2190 "y.tab.c"
    break;

  case 81: /* if_stmt: IF $@5 OC expr CC $@6 OF stmt_list CF $@7 elif_stmt else_stmt  */
#line 431 "parser.y"
                                         {   
                        tac.push_back(string((yyvsp[-11].node).parentNext) + ":");
                    }
#line 2198 "y.tab.c"
    break;

  case 82: /* $@8: %empty  */
#line 436 "parser.y"
                         {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf((yyvsp[0].node).parentNext, "%s", hold);
                    }
#line 2208 "y.tab.c"
    break;

  case 83: /* $@9: %empty  */
#line 441 "parser.y"
                               {
                        // sprintf(icg[ic_idx++], "\nif (%s != 0) GOTO L%d else GOTO L%d\n", $4.token, label, label+1);
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2220 "y.tab.c"
    break;

  case 84: /* $@10: %empty  */
#line 448 "parser.y"
                                    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).parentNext));
                        tac.push_back(string((yyvsp[-5].node).else_body) + ":");
                    }
#line 2229 "y.tab.c"
    break;

  case 89: /* $@11: %empty  */
#line 460 "parser.y"
                           {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2239 "y.tab.c"
    break;

  case 90: /* $@12: %empty  */
#line 465 "parser.y"
                          {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme));
                    }
#line 2248 "y.tab.c"
    break;

  case 91: /* $@13: %empty  */
#line 469 "parser.y"
                                         {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
#line 2257 "y.tab.c"
    break;

  case 92: /* switch_stmt: SWITCH $@11 OC ID $@12 CC OF case_stmt_list $@13 default_stmt CF  */
#line 473 "parser.y"
                                    {
                        tac.push_back("Label " + string((yyvsp[-10].node).parentNext));
                        loop_break.pop();
                    }
#line 2266 "y.tab.c"
    break;

  case 93: /* case_stmt_list: case_stmt case_stmt_list  */
#line 479 "parser.y"
                                             {
                        strcpy((yyvsp[-1].node).id, (yyval.node).id);
                        strcpy((yyvsp[-1].node).parentNext, (yyval.node).parentNext);
                    }
#line 2275 "y.tab.c"
    break;

  case 95: /* $@14: %empty  */
#line 486 "parser.y"
                         {
                        // tac.push_back(string($4.if_body) + ":");
                    }
#line 2283 "y.tab.c"
    break;

  case 96: /* $@15: %empty  */
#line 489 "parser.y"
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
#line 2298 "y.tab.c"
    break;

  case 97: /* case_stmt: CASE $@14 OC const $@15 CC COLON stmt_list  */
#line 499 "parser.y"
                                       {
                        // tac.push_back("Label " + string($4.parentNext) + ":");
                        tac.push_back("Label " + string((yyvsp[-4].node).parentNext) + ":");
                    }
#line 2307 "y.tab.c"
    break;

  case 100: /* $@16: %empty  */
#line 508 "parser.y"
                          {
                        sprintf((yyvsp[0].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[0].node).loop_body) + ":");
                    }
#line 2317 "y.tab.c"
    break;

  case 101: /* $@17: %empty  */
#line 514 "parser.y"
                    {
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));
                        tac.push_back("\n" + string((yyvsp[-1].node).if_body) + ":");
                        
                    }
#line 2332 "y.tab.c"
    break;

  case 102: /* while_loop_stmt: WHILE $@16 OC expr CC $@17 OF stmt_list CF  */
#line 525 "parser.y"
                    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-5].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2343 "y.tab.c"
    break;

  case 103: /* $@18: %empty  */
#line 532 "parser.y"
                                       {
                        sprintf((yyvsp[-3].node).loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string((yyvsp[-3].node).loop_body) + ":");
                    }
#line 2352 "y.tab.c"
    break;

  case 104: /* $@19: %empty  */
#line 536 "parser.y"
                              {  
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));

                        sprintf((yyvsp[-1].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[-1].node).loop_body) + ":");
                    }
#line 2369 "y.tab.c"
    break;

  case 105: /* $@20: %empty  */
#line 548 "parser.y"
                              {
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-4].node).if_body) + ":");
                    }
#line 2378 "y.tab.c"
    break;

  case 106: /* for_loop_stmt: FOR OC assign SCOL $@18 expr SCOL $@19 assign CC $@20 OF stmt_list CF  */
#line 552 "parser.y"
                                    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-8].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2389 "y.tab.c"
    break;

  case 107: /* func_call: ID OC arg_list CC  */
#line 559 "parser.y"
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
#line 2420 "y.tab.c"
    break;

  case 109: /* arg_list: arg  */
#line 588 "parser.y"
                          {}
#line 2426 "y.tab.c"
    break;

  case 110: /* arg_list: %empty  */
#line 589 "parser.y"
                      {}
#line 2432 "y.tab.c"
    break;

  case 111: /* arg: expr  */
#line 592 "parser.y"
                         {
                        // check argument types
                        tac.push_back("@param " + to_string(param_ind++) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));

                        // if(strcmp($1.type, func_table[curr_func_ind].st[func_arg_ind++].data_type) != 0){
                        //     printf("Error in function call %s: variable type is not matched", func_table[curr_func_ind].name);
                        //     exit(0);
                        // }
                        func_arg++;
                    }
#line 2447 "y.tab.c"
    break;


#line 2451 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 604 "parser.y"


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

bool multiple_declaration(string variable){
    if(!(symbol_table.find(variable) == symbol_table.end())){
        sem_errors.push_back("redeclaration of '" + variable + "' in line " + to_string(countn+1));
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

void yyerror(const char* msg) {
    sem_errors.push_back("syntax error in line " + to_string(countn+1));
    for(auto item: sem_errors)
        cout << item << endl;
    fprintf(stderr, "%s\n", msg);
    exit(1);
}


// Prepend # to label names
