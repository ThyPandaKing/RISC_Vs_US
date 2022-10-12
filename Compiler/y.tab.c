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
    bool function_check(string variable, int flag);
    bool type_check(string type1, string type2);

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
    stack<pair<string, vector<string>>> func_call_id;

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

    vector<string> reserved = {"int", "float", "char", "void", "if", "elif", "else", "for", "while", "break", "continue", "main", "return", "switch", "case", "input", "output"};


#line 144 "y.tab.c"

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
#line 74 "parser.y"

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

#line 324 "y.tab.c"

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
  YYSYMBOL_func_prefix = 60,               /* func_prefix  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_func_data_type = 62,            /* func_data_type  */
  YYSYMBOL_param_list = 63,                /* param_list  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
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
  YYSYMBOL_107_21 = 107,                   /* $@21  */
  YYSYMBOL_arg_list = 108,                 /* arg_list  */
  YYSYMBOL_arg = 109                       /* arg  */
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
#define YYLAST   540

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

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
       0,   110,   110,   112,   113,   116,   121,   120,   133,   136,
     141,   141,   149,   155,   160,   167,   168,   171,   172,   173,
     174,   175,   176,   177,   178,   183,   188,   189,   193,   198,
     209,   216,   222,   222,   231,   231,   238,   247,   252,   255,
     258,   265,   268,   271,   274,   277,   280,   283,   286,   289,
     292,   295,   298,   301,   304,   307,   310,   313,   316,   319,
     324,   329,   334,   339,   349,   356,   361,   366,   372,   373,
     374,   375,   378,   382,   386,   392,   397,   405,   408,   414,
     405,   423,   428,   435,   423,   440,   443,   444,   447,   452,
     456,   447,   466,   470,   473,   476,   473,   491,   492,   495,
     501,   495,   519,   523,   535,   519,   546,   546,   562,   577,
     588,   591
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
  "ASSIGN", "$accept", "Program", "func_list", "func", "func_prefix",
  "$@1", "func_data_type", "param_list", "$@2", "param", "stmt_list",
  "stmt", "declaration", "$@3", "arr_values", "$@4", "return_stmt",
  "data_type", "expr", "postfix_expr", "unary_expr", "primary_expr",
  "unary_op", "const", "assign", "if_stmt", "$@5", "$@6", "$@7",
  "elif_stmt", "$@8", "$@9", "$@10", "else_stmt", "switch_stmt", "$@11",
  "$@12", "$@13", "case_stmt_list", "case_stmt", "$@14", "$@15",
  "default_stmt", "while_loop_stmt", "$@16", "$@17", "for_loop_stmt",
  "$@18", "$@19", "$@20", "func_call", "$@21", "arg_list", "arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-107)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -107,     8,   117,  -107,  -107,  -107,  -107,  -107,  -107,    -7,
      30,  -107,   106,  -107,    65,  -107,  -107,    -4,  -107,  -107,
    -107,  -107,  -107,    65,    15,    18,  -107,    36,  -107,  -107,
      59,    57,    63,   106,  -107,    60,    97,    -2,  -107,  -107,
    -107,    -5,  -107,    70,  -107,  -107,  -107,  -107,  -107,    78,
      46,   416,    65,    65,    83,   301,    65,   121,    99,  -107,
     107,   108,   124,  -107,  -107,  -107,  -107,    42,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,  -107,  -107,  -107,  -107,
      32,    65,   226,   416,    65,  -107,   324,   110,   134,    65,
      65,    -3,   104,   138,  -107,    65,    20,    20,    80,    80,
     160,   160,    80,    80,   456,   436,   100,   100,  -107,  -107,
    -107,   513,   476,   496,   114,   118,   143,   251,   101,   416,
     127,   122,   123,   125,  -107,   347,   370,    65,  -107,   130,
     186,  -107,   128,  -107,  -107,    65,  -107,    65,  -107,  -107,
     129,  -107,  -107,   276,    65,   -35,  -107,    32,   416,  -107,
     131,   132,   142,   101,   206,  -107,  -107,  -107,   145,   106,
     106,  -107,   149,  -107,  -107,   145,   139,   151,   124,    39,
     157,   146,  -107,  -107,  -107,   135,   155,   158,    39,   154,
     170,   166,  -107,   194,   216,  -107,   106,  -107,  -107,   207,
     220,  -107,    39,   227,  -107,   225,   234,  -107,   106,  -107,
     240,    65,   106,   245,   106,   393,   246,  -107,  -107,  -107,
    -107,   247,   106,   260,  -107,   166,  -107
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    38,    40,    39,     9,     3,     0,
       0,     8,    16,     6,     0,    72,    73,    65,    70,    68,
      69,    71,    74,     0,     0,     0,    88,     0,    77,    99,
       0,     0,     0,    16,    17,     0,     0,     0,    61,    59,
      60,     0,    66,     0,    21,    26,    22,    23,    62,     0,
      65,    37,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,     5,    15,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    65,    64,    18,
      13,     0,     0,    75,   110,    67,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    57,    58,    45,    46,
      49,    50,    48,    47,    51,    52,    41,    42,    44,    43,
      53,    54,    55,    56,     0,    10,     0,     0,    63,   111,
       0,   109,     0,     0,    89,     0,     0,     0,   102,     0,
       0,     7,     0,    14,    63,     0,   107,   110,    28,    27,
       0,    78,   100,     0,     0,     0,    30,    13,    76,   108,
       0,     0,     0,     0,     0,    31,    32,    11,    93,    16,
      16,   103,     0,    94,    90,    93,     0,     0,     0,     0,
       0,    98,    92,    79,   101,     0,     0,    34,     0,     0,
       0,    85,   104,     0,     0,    95,    16,    91,    81,    87,
       0,    33,     0,     0,    97,     0,     0,    80,    16,    35,
       0,     0,    16,     0,    16,     0,     0,   105,    96,    82,
      86,     0,    16,     0,    83,    85,    84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,  -107,  -107,  -107,  -107,   152,  -107,  -107,
     -32,  -107,  -107,  -107,   109,  -107,  -107,     0,   -14,  -107,
    -107,   244,  -107,  -106,   -59,  -107,  -107,  -107,  -107,    81,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,   133,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,   163,  -107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    49,    10,   124,   142,   125,
      32,    33,    34,   172,   186,   194,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    60,   161,   191,   199,
     205,   221,   225,   207,    45,    58,   150,   181,   174,   175,
     180,   203,   190,    46,    61,   162,    47,   154,   178,   200,
      48,    54,   130,   131
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    65,    11,   102,    15,    16,    87,   165,     3,    55,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     166,    78,    79,    80,    81,    82,    83,    84,    22,    85,
      23,  -106,    12,    52,   137,     4,     5,     6,    92,    93,
      86,    13,    96,    78,    79,    80,    81,    82,    15,    16,
      56,    53,    53,    57,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    22,   187,    15,    16,    50,   127,    59,   103,
     129,  -106,   195,    91,   104,   135,   136,    18,    19,    20,
     126,   140,    68,    69,    62,    21,   187,   105,    22,    63,
      23,    64,    66,    78,    79,    80,    81,    82,    67,     4,
       5,     6,    89,    90,    14,    15,    16,    17,    94,   185,
       4,     5,     6,   153,     7,    80,    81,    82,    18,    19,
      20,   158,    97,   129,    98,   101,    21,   176,   177,    22,
     164,    23,    99,   100,   133,   134,   138,   139,   141,    24,
      25,    26,   -12,    27,   143,    28,   145,   126,    29,    30,
      31,   146,   147,   160,   204,   148,   155,   149,   157,   192,
     168,   169,    68,    69,    70,    71,   213,   183,    74,    75,
     216,   170,   218,    78,    79,    80,    81,    82,   179,   184,
     223,   173,   188,   193,   189,   196,   -36,   215,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   197,    78,
      79,    80,    81,    82,    83,    84,   198,    85,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   156,    78,
      79,    80,    81,    82,    83,    84,   201,    85,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   171,    78,
      79,    80,    81,    82,    83,    84,   202,    85,   206,   208,
     211,   210,   128,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   212,    78,    79,    80,    81,    82,    83,
      84,   214,    85,   217,   220,    88,   222,   144,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   224,    78,
      79,    80,    81,    82,    83,    84,   226,    85,   182,   167,
     159,   209,   163,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,     0,    95,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,     0,   132,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
       0,   151,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,     0,   152,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,     0,   219,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    68,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,     0,    78,
      79,    80,    81,    82,    83,     0,     0,    85,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,     0,    78,    79,    80,    81,
      82
};

static const yytype_int16 yycheck[] =
{
      14,    33,     2,    62,     9,    10,    11,    42,     0,    23,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      55,    23,    24,    25,    26,    27,    28,    29,    33,    31,
      35,    35,    39,    37,    37,     3,     4,     5,    52,    53,
      42,    11,    56,    23,    24,    25,    26,    27,     9,    10,
      35,    55,    55,    35,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    33,   179,     9,    10,    11,    91,    42,    37,
      94,    35,   188,    37,    42,    99,   100,    22,    23,    24,
      90,   105,    12,    13,    35,    30,   202,    55,    33,    42,
      35,    38,    42,    23,    24,    25,    26,    27,    11,     3,
       4,     5,    42,    35,     8,     9,    10,    11,    35,   178,
       3,     4,     5,   137,     7,    25,    26,    27,    22,    23,
      24,   145,    11,   147,    35,    11,    30,   169,   170,    33,
     154,    35,    35,    35,    34,    11,    42,     9,    34,    43,
      44,    45,    34,    47,    11,    49,    55,   157,    52,    53,
      54,    34,    40,    34,   196,    42,    36,    42,    40,    34,
      39,    39,    12,    13,    14,    15,   208,    38,    18,    19,
     212,    39,   214,    23,    24,    25,    26,    27,    39,    38,
     222,    46,    35,    38,    48,    41,    38,   211,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    38,    23,
      24,    25,    26,    27,    28,    29,    50,    31,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    42,    23,
      24,    25,    26,    27,    28,    29,    42,    31,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    42,    23,
      24,    25,    26,    27,    28,    29,    40,    31,    51,    39,
      35,    34,    36,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    39,    23,    24,    25,    26,    27,    28,
      29,    41,    31,    38,    38,    41,    39,    36,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    38,    23,
      24,    25,    26,    27,    28,    29,   225,    31,   175,   157,
     147,   202,    36,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    34,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    34,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    -1,    34,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    -1,    -1,    34,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    57,    58,     0,     3,     4,     5,     7,    59,    60,
      62,    73,    39,    11,     8,     9,    10,    11,    22,    23,
      24,    30,    33,    35,    43,    44,    45,    47,    49,    52,
      53,    54,    66,    67,    68,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    90,    99,   102,   106,    61,
      11,    74,    37,    55,   107,    74,    35,    35,    91,    42,
      82,   100,    35,    42,    38,    66,    42,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    23,    24,
      25,    26,    27,    28,    29,    31,    42,    11,    77,    42,
      35,    37,    74,    74,    35,    34,    74,    11,    35,    35,
      35,    11,    80,    37,    42,    55,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    63,    65,    73,    74,    36,    74,
     108,   109,    34,    34,    11,    74,    74,    37,    42,     9,
      74,    34,    64,    11,    36,    55,    34,    40,    42,    42,
      92,    34,    34,    74,   103,    36,    42,    40,    74,   108,
      34,    83,   101,    36,    74,    42,    55,    63,    39,    39,
      39,    42,    69,    46,    94,    95,    66,    66,   104,    39,
      96,    93,    94,    38,    38,    80,    70,    79,    35,    48,
      98,    84,    34,    38,    71,    79,    41,    38,    50,    85,
     105,    42,    40,    97,    66,    86,    51,    89,    39,    70,
      34,    35,    39,    66,    41,    74,    66,    38,    66,    34,
      38,    87,    39,    66,    38,    88,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    61,    60,    62,    62,
      64,    63,    63,    63,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    69,    68,    71,    70,    70,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    76,    77,    77,    77,    78,    78,
      78,    78,    79,    79,    79,    80,    80,    82,    83,    84,
      81,    86,    87,    88,    85,    85,    89,    89,    91,    92,
      93,    90,    94,    94,    96,    97,    95,    98,    98,   100,
     101,    99,   103,   104,   105,   102,   107,   106,   108,   108,
     108,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     0,     6,     1,     1,
       0,     4,     1,     0,     2,     2,     0,     1,     2,     2,
       2,     1,     1,     1,     2,     2,     1,     5,     5,     3,
       5,     6,     0,    11,     0,     4,     1,     2,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     4,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     0,     0,     0,
      12,     0,     0,     0,    11,     0,     4,     0,     0,     0,
       0,    11,     2,     0,     0,     0,     8,     3,     0,     0,
       0,     9,     0,     0,     0,    14,     0,     5,     3,     1,
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
#line 110 "parser.y"
                              {}
#line 1635 "y.tab.c"
    break;

  case 3: /* func_list: func_list func  */
#line 112 "parser.y"
                                   {}
#line 1641 "y.tab.c"
    break;

  case 5: /* func: func_prefix OF stmt_list CF  */
#line 116 "parser.y"
                                                {
                        tac.push_back("end:\n");
                    }
#line 1649 "y.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 121 "parser.y"
                    {   
                        if(func_table.find(string((yyvsp[0].node).lexeme)) != func_table.end()){
                            sem_errors.push_back("Error: Duplicate function name - " + string((yyvsp[0].node).lexeme));
                        }
                        tac.push_back(string((yyvsp[0].node).lexeme) + ":"); 
                        curr_func_name = string((yyvsp[0].node).lexeme);
                    }
#line 1661 "y.tab.c"
    break;

  case 7: /* func_prefix: func_data_type ID $@1 OC param_list CC  */
#line 128 "parser.y"
                                     {
                        func_table[curr_func_name].return_type = string((yyvsp[-5].node).type);
                        func_table[curr_func_name].num_params = (yyvsp[-1].node).nParams;
                    }
#line 1670 "y.tab.c"
    break;

  case 8: /* func_data_type: data_type  */
#line 133 "parser.y"
                              {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                    }
#line 1678 "y.tab.c"
    break;

  case 9: /* func_data_type: VOID  */
#line 136 "parser.y"
                           {
                        sprintf((yyval.node).type, "void");
                    }
#line 1686 "y.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 141 "parser.y"
                          {
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));                       
                    }
#line 1696 "y.tab.c"
    break;

  case 11: /* param_list: param $@2 COMMA param_list  */
#line 146 "parser.y"
                                     {
                        (yyval.node).nParams = (yyvsp[0].node).nParams + 1;
                    }
#line 1704 "y.tab.c"
    break;

  case 12: /* param_list: param  */
#line 149 "parser.y"
                            {
                        (yyval.node).nParams = 1;
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));
                    }
#line 1715 "y.tab.c"
    break;

  case 13: /* param_list: %empty  */
#line 155 "parser.y"
                      {
                        (yyval.node).nParams = 0;
                    }
#line 1723 "y.tab.c"
    break;

  case 14: /* param: data_type ID  */
#line 160 "parser.y"
                                 {
                        (yyval.node).nParams = 1;
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 1733 "y.tab.c"
    break;

  case 24: /* stmt: BREAK SCOL  */
#line 178 "parser.y"
                                 {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
#line 1743 "y.tab.c"
    break;

  case 25: /* stmt: CONTINUE SCOL  */
#line 183 "parser.y"
                                    {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }
#line 1753 "y.tab.c"
    break;

  case 27: /* stmt: INPUT OC ID CC SCOL  */
#line 189 "parser.y"
                                           {
                        check_declaration((yyvsp[-2].node).lexeme);
                        tac.push_back("input " + string((yyvsp[-2].node).lexeme) + " " + symbol_table[string((yyvsp[-4].node).lexeme)].data_type);
                    }
#line 1762 "y.tab.c"
    break;

  case 28: /* stmt: OUTPUT OC expr CC SCOL  */
#line 193 "parser.y"
                                             {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-2].node).type));
                    }
#line 1770 "y.tab.c"
    break;

  case 29: /* declaration: data_type ID SCOL  */
#line 198 "parser.y"
                                      { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        multiple_declaration(string((yyvsp[-1].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)] = { string((yyvsp[-2].node).type), 0, 0, countn+1 };
                    }
#line 1781 "y.tab.c"
    break;

  case 30: /* declaration: data_type ID ASSIGN expr SCOL  */
#line 209 "parser.y"
                                                    {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[-4].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), 0, 0, countn+1 };
                    }
#line 1793 "y.tab.c"
    break;

  case 31: /* declaration: data_type ID OS INT_NUM CS SCOL  */
#line 216 "parser.y"
                                                      {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                    }
#line 1804 "y.tab.c"
    break;

  case 32: /* $@3: %empty  */
#line 222 "parser.y"
                                                        {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                        curr_array = string((yyvsp[-4].node).lexeme);
                    }
#line 1816 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 231 "parser.y"
                          {
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(symbol_table[curr_array].size) + "]’");
                        }
                    }
#line 1827 "y.tab.c"
    break;

  case 36: /* arr_values: const  */
#line 238 "parser.y"
                            {
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(symbol_table[curr_array].size) + "]’");
                        }
                        arr_index=0;
                    }
#line 1839 "y.tab.c"
    break;

  case 37: /* return_stmt: RETURN expr  */
#line 247 "parser.y"
                                {
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                    }
#line 1847 "y.tab.c"
    break;

  case 38: /* data_type: INT  */
#line 252 "parser.y"
                        {
                        strcpy((yyval.node).type, "INT");
                    }
#line 1855 "y.tab.c"
    break;

  case 39: /* data_type: FLOAT  */
#line 255 "parser.y"
                            {
                        strcpy((yyval.node).type, "FLOAT");
                    }
#line 1863 "y.tab.c"
    break;

  case 40: /* data_type: CHAR  */
#line 258 "parser.y"
                           {
                        strcpy((yyval.node).type, "CHAR");
                    }
#line 1871 "y.tab.c"
    break;

  case 41: /* expr: expr ADD expr  */
#line 265 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1879 "y.tab.c"
    break;

  case 42: /* expr: expr SUBTRACT expr  */
#line 268 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1887 "y.tab.c"
    break;

  case 43: /* expr: expr MULTIPLY expr  */
#line 271 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1895 "y.tab.c"
    break;

  case 44: /* expr: expr DIVIDE expr  */
#line 274 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1903 "y.tab.c"
    break;

  case 45: /* expr: expr LE expr  */
#line 277 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1911 "y.tab.c"
    break;

  case 46: /* expr: expr GE expr  */
#line 280 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1919 "y.tab.c"
    break;

  case 47: /* expr: expr LT expr  */
#line 283 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1927 "y.tab.c"
    break;

  case 48: /* expr: expr GT expr  */
#line 286 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1935 "y.tab.c"
    break;

  case 49: /* expr: expr EQ expr  */
#line 289 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1943 "y.tab.c"
    break;

  case 50: /* expr: expr NE expr  */
#line 292 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1951 "y.tab.c"
    break;

  case 51: /* expr: expr AND expr  */
#line 295 "parser.y"
                                    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1959 "y.tab.c"
    break;

  case 52: /* expr: expr OR expr  */
#line 298 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1967 "y.tab.c"
    break;

  case 53: /* expr: expr MODULO expr  */
#line 301 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1975 "y.tab.c"
    break;

  case 54: /* expr: expr BITAND expr  */
#line 304 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1983 "y.tab.c"
    break;

  case 55: /* expr: expr BITOR expr  */
#line 307 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1991 "y.tab.c"
    break;

  case 56: /* expr: expr XOR expr  */
#line 310 "parser.y"
                                    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 1999 "y.tab.c"
    break;

  case 57: /* expr: expr LEFTSHIFT expr  */
#line 313 "parser.y"
                                          {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2007 "y.tab.c"
    break;

  case 58: /* expr: expr RIGHTSHIFT expr  */
#line 316 "parser.y"
                                           {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2015 "y.tab.c"
    break;

  case 59: /* expr: unary_expr  */
#line 319 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2025 "y.tab.c"
    break;

  case 60: /* expr: primary_expr  */
#line 324 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2035 "y.tab.c"
    break;

  case 61: /* expr: postfix_expr  */
#line 329 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2044 "y.tab.c"
    break;

  case 62: /* postfix_expr: func_call  */
#line 334 "parser.y"
                              {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2053 "y.tab.c"
    break;

  case 63: /* postfix_expr: ID OS expr CS  */
#line 339 "parser.y"
                                  {
                        if(check_declaration(string((yyvsp[-3].node).lexeme)) && func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Variable is not an array"); 
                        }
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].data_type.c_str());
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-3].node).lexeme) + " [ " + string((yyvsp[-1].node).lexeme) + " ] " + " " + string((yyval.node).type));
                    }
#line 2066 "y.tab.c"
    break;

  case 64: /* unary_expr: unary_op primary_expr  */
#line 349 "parser.y"
                                          {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2076 "y.tab.c"
    break;

  case 65: /* primary_expr: ID  */
#line 356 "parser.y"
                       {
                        check_declaration(string((yyvsp[0].node).lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type.c_str());
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2086 "y.tab.c"
    break;

  case 66: /* primary_expr: const  */
#line 361 "parser.y"
                            {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type)); 
                    }
#line 2096 "y.tab.c"
    break;

  case 67: /* primary_expr: OC expr CC  */
#line 366 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[-1].node).lexeme);
                    }
#line 2105 "y.tab.c"
    break;

  case 72: /* const: INT_NUM  */
#line 378 "parser.y"
                            {
                        strcpy((yyval.node).type, "INT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2114 "y.tab.c"
    break;

  case 73: /* const: FLOAT_NUM  */
#line 382 "parser.y"
                                {
                        strcpy((yyval.node).type, "FLOAT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2123 "y.tab.c"
    break;

  case 74: /* const: CHARACTER  */
#line 386 "parser.y"
                                {
                        strcpy((yyval.node).type, "CHAR");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2132 "y.tab.c"
    break;

  case 75: /* assign: ID ASSIGN expr  */
#line 392 "parser.y"
                                   {
                        check_declaration(string((yyvsp[-2].node).lexeme));
                        tac.push_back(string((yyvsp[-2].node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type);
                    }
#line 2141 "y.tab.c"
    break;

  case 76: /* assign: ID OS expr CS ASSIGN expr  */
#line 397 "parser.y"
                                              {
                        if(check_declaration(string((yyvsp[-5].node).lexeme)) && func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Line no " + to_string(countn+1) + " : Variable is not an array"); 
                        }
                        tac.push_back(string((yyvsp[-5].node).lexeme) + " [ " + string((yyvsp[-3].node).lexeme) + " ] " + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                    }
#line 2152 "y.tab.c"
    break;

  case 77: /* $@5: %empty  */
#line 405 "parser.y"
                        {
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2160 "y.tab.c"
    break;

  case 78: /* $@6: %empty  */
#line 408 "parser.y"
                               { 
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2171 "y.tab.c"
    break;

  case 79: /* $@7: %empty  */
#line 414 "parser.y"
                                    {  
                        tac.push_back("GOTO " + string((yyvsp[-8].node).parentNext));
                        tac.push_back(string((yyvsp[-5].node).else_body) + ":");
                    }
#line 2180 "y.tab.c"
    break;

  case 80: /* if_stmt: IF $@5 OC expr CC $@6 OF stmt_list CF $@7 elif_stmt else_stmt  */
#line 418 "parser.y"
                                         {   
                        tac.push_back(string((yyvsp[-11].node).parentNext) + ":");
                    }
#line 2188 "y.tab.c"
    break;

  case 81: /* $@8: %empty  */
#line 423 "parser.y"
                         {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf((yyvsp[0].node).parentNext, "%s", hold);
                    }
#line 2198 "y.tab.c"
    break;

  case 82: /* $@9: %empty  */
#line 428 "parser.y"
                               {
                        // sprintf(icg[ic_idx++], "\nif (%s != 0) GOTO L%d else GOTO L%d\n", $4.token, label, label+1);
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2210 "y.tab.c"
    break;

  case 83: /* $@10: %empty  */
#line 435 "parser.y"
                                    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).parentNext));
                        tac.push_back(string((yyvsp[-5].node).else_body) + ":");
                    }
#line 2219 "y.tab.c"
    break;

  case 88: /* $@11: %empty  */
#line 447 "parser.y"
                           {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2229 "y.tab.c"
    break;

  case 89: /* $@12: %empty  */
#line 452 "parser.y"
                          {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme));
                    }
#line 2238 "y.tab.c"
    break;

  case 90: /* $@13: %empty  */
#line 456 "parser.y"
                                         {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
#line 2247 "y.tab.c"
    break;

  case 91: /* switch_stmt: SWITCH $@11 OC ID $@12 CC OF case_stmt_list $@13 default_stmt CF  */
#line 460 "parser.y"
                                    {
                        tac.push_back("Label " + string((yyvsp[-10].node).parentNext));
                        loop_break.pop();
                    }
#line 2256 "y.tab.c"
    break;

  case 92: /* case_stmt_list: case_stmt case_stmt_list  */
#line 466 "parser.y"
                                             {
                        strcpy((yyvsp[-1].node).id, (yyval.node).id);
                        strcpy((yyvsp[-1].node).parentNext, (yyval.node).parentNext);
                    }
#line 2265 "y.tab.c"
    break;

  case 94: /* $@14: %empty  */
#line 473 "parser.y"
                         {
                        // tac.push_back(string($4.if_body) + ":");
                    }
#line 2273 "y.tab.c"
    break;

  case 95: /* $@15: %empty  */
#line 476 "parser.y"
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
#line 2288 "y.tab.c"
    break;

  case 96: /* case_stmt: CASE $@14 OC const $@15 CC COLON stmt_list  */
#line 486 "parser.y"
                                       {
                        // tac.push_back("Label " + string($4.parentNext) + ":");
                        tac.push_back("Label " + string((yyvsp[-4].node).parentNext) + ":");
                    }
#line 2297 "y.tab.c"
    break;

  case 99: /* $@16: %empty  */
#line 495 "parser.y"
                          {
                        sprintf((yyvsp[0].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[0].node).loop_body) + ":");
                    }
#line 2307 "y.tab.c"
    break;

  case 100: /* $@17: %empty  */
#line 501 "parser.y"
                    {
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));
                        tac.push_back("\n" + string((yyvsp[-1].node).if_body) + ":");
                        
                    }
#line 2322 "y.tab.c"
    break;

  case 101: /* while_loop_stmt: WHILE $@16 OC expr CC $@17 OF stmt_list CF  */
#line 512 "parser.y"
                    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-5].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2333 "y.tab.c"
    break;

  case 102: /* $@18: %empty  */
#line 519 "parser.y"
                                       {
                        sprintf((yyvsp[-3].node).loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string((yyvsp[-3].node).loop_body) + ":");
                    }
#line 2342 "y.tab.c"
    break;

  case 103: /* $@19: %empty  */
#line 523 "parser.y"
                              {  
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));

                        sprintf((yyvsp[-1].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[-1].node).loop_body) + ":");
                    }
#line 2359 "y.tab.c"
    break;

  case 104: /* $@20: %empty  */
#line 535 "parser.y"
                              {
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-4].node).if_body) + ":");
                    }
#line 2368 "y.tab.c"
    break;

  case 105: /* for_loop_stmt: FOR OC assign SCOL $@18 expr SCOL $@19 assign CC $@20 OF stmt_list CF  */
#line 539 "parser.y"
                                    {
                        tac.push_back("GOTO " + string((yyvsp[-8].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-8].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2379 "y.tab.c"
    break;

  case 106: /* $@21: %empty  */
#line 546 "parser.y"
                       {
                        func_call_id.push({string((yyvsp[0].node).lexeme), func_table[string((yyvsp[0].node).lexeme)].param_types});
                        }
#line 2387 "y.tab.c"
    break;

  case 107: /* func_call: ID $@21 OC arg_list CC  */
#line 549 "parser.y"
                                        {
                        strcpy((yyval.node).type, func_table[string((yyvsp[-4].node).lexeme)].return_type.c_str());
                        func_call_id.pop();
                        sprintf((yyval.node).lexeme, "@t%d", variable_count);
                        variable_count++;

                        // checking if function is declared
                        

                        tac.push_back(string((yyval.node).lexeme) + " = @call " + string((yyvsp[-4].node).lexeme) + " " + func_table[string((yyvsp[-4].node).lexeme)].return_type + " " + to_string(func_table[string((yyvsp[-4].node).lexeme)].num_params));
                    }
#line 2403 "y.tab.c"
    break;

  case 108: /* arg_list: arg COMMA arg_list  */
#line 562 "parser.y"
                                       {
                        // cout << string($1.lexeme) << endl;
                        // cout << "here" << string($1.type) << endl;
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        // cout << "there" << type << endl;
                        func_call_id.top().second.pop_back();
                        cout << (yyvsp[-2].node).lexeme << ": " << endl;
                        cout << string((yyvsp[-2].node).type) << endl;
                        cout << type << endl;
                        if(type_check(string((yyvsp[-2].node).type), type)) {
                            cout << "hiiiiiiiiiii" << endl;
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 2423 "y.tab.c"
    break;

  case 109: /* arg_list: arg  */
#line 577 "parser.y"
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
#line 2439 "y.tab.c"
    break;

  case 111: /* arg: expr  */
#line 591 "parser.y"
                         {
                        tac.push_back("param " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
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

#line 596 "parser.y"


int main(int argc, char *argv[]) {
    /* yydebug = 1; */
    yyparse();
    for(auto x: tac)
        cout << x << endl;
    for(auto item: sem_errors)
        cout << item << endl;
    /* for(auto item: func_table[curr_func_name].symbol_table)
        cout << item.first << "-->" << item.second.data_type << endl; */
}

bool check_declaration(string variable){
    if(func_table[curr_func_name].symbol_table.find(variable) == func_table[curr_func_name].symbol_table.end()){
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
