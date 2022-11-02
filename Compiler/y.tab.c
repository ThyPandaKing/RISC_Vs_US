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


#line 164 "y.tab.c"

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
#line 94 "parser.y"

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

#line 344 "y.tab.c"

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
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_param = 66,                     /* param  */
  YYSYMBOL_stmt_list = 67,                 /* stmt_list  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_70_4 = 70,                      /* $@4  */
  YYSYMBOL_arr_values = 71,                /* arr_values  */
  YYSYMBOL_72_5 = 72,                      /* $@5  */
  YYSYMBOL_return_stmt = 73,               /* return_stmt  */
  YYSYMBOL_data_type = 74,                 /* data_type  */
  YYSYMBOL_expr = 75,                      /* expr  */
  YYSYMBOL_postfix_expr = 76,              /* postfix_expr  */
  YYSYMBOL_unary_expr = 77,                /* unary_expr  */
  YYSYMBOL_primary_expr = 78,              /* primary_expr  */
  YYSYMBOL_unary_op = 79,                  /* unary_op  */
  YYSYMBOL_const = 80,                     /* const  */
  YYSYMBOL_assign = 81,                    /* assign  */
  YYSYMBOL_if_stmt = 82,                   /* if_stmt  */
  YYSYMBOL_83_6 = 83,                      /* $@6  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_85_8 = 85,                      /* $@8  */
  YYSYMBOL_86_9 = 86,                      /* $@9  */
  YYSYMBOL_elif_stmt = 87,                 /* elif_stmt  */
  YYSYMBOL_88_10 = 88,                     /* $@10  */
  YYSYMBOL_89_11 = 89,                     /* $@11  */
  YYSYMBOL_90_12 = 90,                     /* $@12  */
  YYSYMBOL_91_13 = 91,                     /* $@13  */
  YYSYMBOL_else_stmt = 92,                 /* else_stmt  */
  YYSYMBOL_93_14 = 93,                     /* $@14  */
  YYSYMBOL_switch_stmt = 94,               /* switch_stmt  */
  YYSYMBOL_95_15 = 95,                     /* $@15  */
  YYSYMBOL_96_16 = 96,                     /* $@16  */
  YYSYMBOL_97_17 = 97,                     /* $@17  */
  YYSYMBOL_case_stmt_list = 98,            /* case_stmt_list  */
  YYSYMBOL_case_stmt = 99,                 /* case_stmt  */
  YYSYMBOL_100_18 = 100,                   /* $@18  */
  YYSYMBOL_101_19 = 101,                   /* $@19  */
  YYSYMBOL_default_stmt = 102,             /* default_stmt  */
  YYSYMBOL_while_loop_stmt = 103,          /* while_loop_stmt  */
  YYSYMBOL_104_20 = 104,                   /* $@20  */
  YYSYMBOL_105_21 = 105,                   /* $@21  */
  YYSYMBOL_106_22 = 106,                   /* $@22  */
  YYSYMBOL_for_loop_stmt = 107,            /* for_loop_stmt  */
  YYSYMBOL_108_23 = 108,                   /* $@23  */
  YYSYMBOL_109_24 = 109,                   /* $@24  */
  YYSYMBOL_110_25 = 110,                   /* $@25  */
  YYSYMBOL_111_26 = 111,                   /* $@26  */
  YYSYMBOL_func_call = 112,                /* func_call  */
  YYSYMBOL_113_27 = 113,                   /* $@27  */
  YYSYMBOL_arg_list = 114,                 /* arg_list  */
  YYSYMBOL_arg = 115                       /* arg  */
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
#define YYLAST   557

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

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
       0,   130,   130,   132,   133,   137,   136,   146,   145,   158,
     161,   166,   166,   174,   180,   185,   191,   192,   195,   196,
     197,   198,   199,   200,   201,   202,   207,   212,   213,   218,
     221,   227,   233,   240,   248,   254,   254,   263,   263,   271,
     281,   287,   290,   293,   300,   304,   308,   330,   352,   358,
     364,   368,   372,   376,   382,   400,   418,   440,   444,   448,
     462,   465,   468,   473,   478,   483,   488,   499,   514,   520,
     532,   538,   539,   540,   541,   544,   548,   552,   558,   565,
     574,   577,   584,   586,   574,   596,   601,   609,   612,   596,
     618,   621,   621,   622,   625,   630,   634,   625,   644,   648,
     651,   654,   651,   669,   670,   673,   679,   689,   673,   700,
     704,   716,   721,   700,   732,   732,   748,   760,   771,   774
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
  "func_prefix", "$@2", "func_data_type", "param_list", "$@3", "param",
  "stmt_list", "stmt", "declaration", "$@4", "arr_values", "$@5",
  "return_stmt", "data_type", "expr", "postfix_expr", "unary_expr",
  "primary_expr", "unary_op", "const", "assign", "if_stmt", "$@6", "$@7",
  "$@8", "$@9", "elif_stmt", "$@10", "$@11", "$@12", "$@13", "else_stmt",
  "$@14", "switch_stmt", "$@15", "$@16", "$@17", "case_stmt_list",
  "case_stmt", "$@18", "$@19", "default_stmt", "while_loop_stmt", "$@20",
  "$@21", "$@22", "for_loop_stmt", "$@23", "$@24", "$@25", "$@26",
  "func_call", "$@27", "arg_list", "arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-115)

#define yytable_value_is_error(Yyn) \
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
static const yytype_int8 yydefact[] =
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
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,    14,     9,    15,    10,    94,   133,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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
#line 130 "parser.y"
                              {}
#line 1670 "y.tab.c"
    break;

  case 3: /* func_list: func_list func  */
#line 132 "parser.y"
                                   {}
#line 1676 "y.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 137 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 1684 "y.tab.c"
    break;

  case 6: /* func: func_prefix OF $@1 stmt_list CF  */
#line 140 "parser.y"
                    {
                        scope_history.pop();
                        tac.push_back("end:\n");
                    }
#line 1693 "y.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 146 "parser.y"
                    {   
                        if(func_table.find(string((yyvsp[0].node).lexeme)) != func_table.end()){
                            sem_errors.push_back("Error: Duplicate function name - " + string((yyvsp[0].node).lexeme));
                        }
                        tac.push_back(string((yyvsp[0].node).lexeme) + ":"); 
                        curr_func_name = string((yyvsp[0].node).lexeme);
                    }
#line 1705 "y.tab.c"
    break;

  case 8: /* func_prefix: func_data_type ID $@2 OC param_list CC  */
#line 153 "parser.y"
                                     {
                        func_table[curr_func_name].return_type = string((yyvsp[-5].node).type);
                        func_table[curr_func_name].num_params = (yyvsp[-1].node).nParams;
                    }
#line 1714 "y.tab.c"
    break;

  case 9: /* func_data_type: data_type  */
#line 158 "parser.y"
                              {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                    }
#line 1722 "y.tab.c"
    break;

  case 10: /* func_data_type: VOID  */
#line 161 "parser.y"
                           {
                        sprintf((yyval.node).type, "void");
                    }
#line 1730 "y.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 166 "parser.y"
                          {
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));                       
                    }
#line 1740 "y.tab.c"
    break;

  case 12: /* param_list: param $@3 COMMA param_list  */
#line 171 "parser.y"
                                     {
                        (yyval.node).nParams = (yyvsp[0].node).nParams + 1;
                    }
#line 1748 "y.tab.c"
    break;

  case 13: /* param_list: param  */
#line 174 "parser.y"
                            {
                        (yyval.node).nParams = 1;
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));
                    }
#line 1759 "y.tab.c"
    break;

  case 14: /* param_list: %empty  */
#line 180 "parser.y"
                      {
                        (yyval.node).nParams = 0;
                    }
#line 1767 "y.tab.c"
    break;

  case 15: /* param: data_type ID  */
#line 185 "parser.y"
                                 {
                        (yyval.node).nParams = 1;
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);                    }
#line 1776 "y.tab.c"
    break;

  case 25: /* stmt: BREAK SCOL  */
#line 202 "parser.y"
                                 {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
#line 1786 "y.tab.c"
    break;

  case 26: /* stmt: CONTINUE SCOL  */
#line 207 "parser.y"
                                    {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }
#line 1796 "y.tab.c"
    break;

  case 28: /* stmt: INPUT OC ID CC SCOL  */
#line 213 "parser.y"
                                           {
                        check_declaration((yyvsp[-2].node).lexeme);
                        tac.push_back("input " + string((yyvsp[-2].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)].data_type);
                        check_scope(string((yyvsp[-2].node).lexeme));
                    }
#line 1806 "y.tab.c"
    break;

  case 29: /* stmt: OUTPUT OC expr CC SCOL  */
#line 218 "parser.y"
                                             {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-2].node).type));
                    }
#line 1814 "y.tab.c"
    break;

  case 30: /* stmt: OUTPUT OC STR CC SCOL  */
#line 221 "parser.y"
                                            {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " STR");
                    }
#line 1822 "y.tab.c"
    break;

  case 31: /* declaration: data_type ID SCOL  */
#line 227 "parser.y"
                                      { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        multiple_declaration(string((yyvsp[-1].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)] = { string((yyvsp[-2].node).type), scope_counter, 0, 0, countn+1 };
                    }
#line 1833 "y.tab.c"
    break;

  case 32: /* declaration: STRING ID ASSIGN STR SCOL  */
#line 233 "parser.y"
                                                {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        tac.push_back("- STR " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " STR");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { "STR", string((yyvsp[-1].node).lexeme).length(), 0, countn+1 };
                    }
#line 1845 "y.tab.c"
    break;

  case 33: /* declaration: data_type ID ASSIGN expr SCOL  */
#line 240 "parser.y"
                                                    {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        check_type(string((yyvsp[-4].node).type), string((yyvsp[-1].node).type));
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[-4].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), scope_counter, 0, 0, countn+1 };
                    }
#line 1858 "y.tab.c"
    break;

  case 34: /* declaration: data_type ID OS INT_NUM CS SCOL  */
#line 248 "parser.y"
                                                      {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                    }
#line 1869 "y.tab.c"
    break;

  case 35: /* $@4: %empty  */
#line 254 "parser.y"
                                                        {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                        curr_array = string((yyvsp[-4].node).lexeme);
                    }
#line 1881 "y.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 263 "parser.y"
                          {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]’");
                        }
                    }
#line 1893 "y.tab.c"
    break;

  case 39: /* arr_values: const  */
#line 271 "parser.y"
                            {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]’");
                        }
                        arr_index=0;
                    }
#line 1906 "y.tab.c"
    break;

  case 40: /* return_stmt: RETURN expr  */
#line 281 "parser.y"
                                {
                        check_type(func_table[curr_func_name].return_type, string((yyvsp[0].node).type));
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].return_type);
                    }
#line 1915 "y.tab.c"
    break;

  case 41: /* data_type: INT  */
#line 287 "parser.y"
                        {
                        strcpy((yyval.node).type, "INT");
                    }
#line 1923 "y.tab.c"
    break;

  case 42: /* data_type: FLOAT  */
#line 290 "parser.y"
                            {
                        strcpy((yyval.node).type, "FLOAT");
                    }
#line 1931 "y.tab.c"
    break;

  case 43: /* data_type: CHAR  */
#line 293 "parser.y"
                           {
                        strcpy((yyval.node).type, "CHAR");
                    }
#line 1939 "y.tab.c"
    break;

  case 44: /* expr: expr ADD expr  */
#line 300 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 1948 "y.tab.c"
    break;

  case 45: /* expr: expr SUBTRACT expr  */
#line 304 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 1957 "y.tab.c"
    break;

  case 46: /* expr: expr MULTIPLY expr  */
#line 308 "parser.y"
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
#line 1984 "y.tab.c"
    break;

  case 47: /* expr: expr DIVIDE expr  */
#line 330 "parser.y"
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
#line 2011 "y.tab.c"
    break;

  case 48: /* expr: expr LE expr  */
#line 352 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = "@t" + to_string(++variable_count);
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " > " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ~ " + temp + " " + string((yyval.node).type)); 
                    }
#line 2022 "y.tab.c"
    break;

  case 49: /* expr: expr GE expr  */
#line 358 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = "@t" + to_string(++variable_count);
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " < " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ~ " + temp + " " + string((yyval.node).type)); 
                    }
#line 2033 "y.tab.c"
    break;

  case 50: /* expr: expr LT expr  */
#line 364 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2042 "y.tab.c"
    break;

  case 51: /* expr: expr GT expr  */
#line 368 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2051 "y.tab.c"
    break;

  case 52: /* expr: expr EQ expr  */
#line 372 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2060 "y.tab.c"
    break;

  case 53: /* expr: expr NE expr  */
#line 376 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = "@t" + to_string(++variable_count);
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " == " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ~ " + temp + " " + string((yyval.node).type)); 
                    }
#line 2071 "y.tab.c"
    break;

  case 54: /* expr: expr AND expr  */
#line 382 "parser.y"
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
#line 2094 "y.tab.c"
    break;

  case 55: /* expr: expr OR expr  */
#line 400 "parser.y"
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
#line 2117 "y.tab.c"
    break;

  case 56: /* expr: expr MODULO expr  */
#line 418 "parser.y"
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
#line 2144 "y.tab.c"
    break;

  case 57: /* expr: expr BITAND expr  */
#line 440 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2153 "y.tab.c"
    break;

  case 58: /* expr: expr BITOR expr  */
#line 444 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                    }
#line 2162 "y.tab.c"
    break;

  case 59: /* expr: expr XOR expr  */
#line 448 "parser.y"
                                    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string b_= "@t" + to_string(++variable_count);
                        string c = string((yyvsp[0].node).lexeme);
                        string c_= "@t" + to_string(++variable_count);

                        tac.push_back(b_ + " = ~ " + b + " " + string((yyvsp[-2].node).type));
                        tac.push_back(c_ + " = ~ " + c + " " + string((yyvsp[0].node).type));
                        tac.push_back("@t" + to_string(++variable_count) + " = " + b + " & " + c_ + " " + string((yyval.node).type));
                        tac.push_back("@t" + to_string(++variable_count) + " = " + b_ + " & " + c + " " + string((yyval.node).type));
                        tac.push_back(a + " = " + "@t" + to_string(variable_count-1) + " | " + "@t" + to_string(variable_count) + " " + string((yyval.node).type));
                    }
#line 2181 "y.tab.c"
    break;

  case 60: /* expr: expr LEFTSHIFT expr  */
#line 462 "parser.y"
                                          {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2189 "y.tab.c"
    break;

  case 61: /* expr: expr RIGHTSHIFT expr  */
#line 465 "parser.y"
                                           {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                    }
#line 2197 "y.tab.c"
    break;

  case 62: /* expr: unary_expr  */
#line 468 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2207 "y.tab.c"
    break;

  case 63: /* expr: primary_expr  */
#line 473 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2217 "y.tab.c"
    break;

  case 64: /* expr: postfix_expr  */
#line 478 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2226 "y.tab.c"
    break;

  case 65: /* postfix_expr: func_call  */
#line 483 "parser.y"
                              {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2235 "y.tab.c"
    break;

  case 66: /* postfix_expr: ID OS expr CS  */
#line 488 "parser.y"
                                  {
                        if(check_declaration(string((yyvsp[-3].node).lexeme)) && func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Variable is not an array"); 
                        }
                        check_scope(string((yyvsp[-3].node).lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].data_type.c_str());
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-3].node).lexeme) + " [ " + string((yyvsp[-1].node).lexeme) + " ] " + string((yyval.node).type));
                    }
#line 2249 "y.tab.c"
    break;

  case 67: /* unary_expr: unary_op primary_expr  */
#line 499 "parser.y"
                                          {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "@t%d", variable_count++);
                        if(string((yyvsp[-1].node).lexeme) == "~" || string((yyvsp[-1].node).lexeme) == "-"){
                            tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        }
                        else if(string((yyvsp[-1].node).lexeme) == "+"){
                            tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyval.node).type));
                        }
                        else{
                            tac.push_back(string((yyval.node).lexeme) + " = ~ " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        }
                    }
#line 2267 "y.tab.c"
    break;

  case 68: /* primary_expr: ID  */
#line 514 "parser.y"
                       {
                        check_declaration(string((yyvsp[0].node).lexeme));
                        check_scope(string((yyvsp[0].node).lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type.c_str());
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2278 "y.tab.c"
    break;

  case 69: /* primary_expr: const  */
#line 520 "parser.y"
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
#line 2295 "y.tab.c"
    break;

  case 70: /* primary_expr: OC expr CC  */
#line 532 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[-1].node).lexeme);
                    }
#line 2304 "y.tab.c"
    break;

  case 75: /* const: INT_NUM  */
#line 544 "parser.y"
                            {
                        strcpy((yyval.node).type, "INT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2313 "y.tab.c"
    break;

  case 76: /* const: FLOAT_NUM  */
#line 548 "parser.y"
                                {
                        strcpy((yyval.node).type, "FLOAT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2322 "y.tab.c"
    break;

  case 77: /* const: CHARACTER  */
#line 552 "parser.y"
                                {
                        strcpy((yyval.node).type, "CHAR");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2331 "y.tab.c"
    break;

  case 78: /* assign: ID ASSIGN expr  */
#line 558 "parser.y"
                                   {
                        check_type(func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type, string((yyvsp[0].node).type));
                        check_declaration(string((yyvsp[-2].node).lexeme));
                        check_scope(string((yyvsp[-2].node).lexeme));
                        tac.push_back(string((yyvsp[-2].node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type);
                    }
#line 2342 "y.tab.c"
    break;

  case 79: /* assign: ID OS expr CS ASSIGN expr  */
#line 565 "parser.y"
                                              {
                        check_type(func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type, string((yyvsp[0].node).type));
                        if(check_declaration(string((yyvsp[-5].node).lexeme)) && func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Line no " + to_string(countn+1) + " : Variable is not an array"); 
                        }
                        check_scope(string((yyvsp[-5].node).lexeme));
                        tac.push_back(string((yyvsp[-5].node).lexeme) + " [ " + string((yyvsp[-3].node).lexeme) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                    }
#line 2355 "y.tab.c"
    break;

  case 80: /* $@6: %empty  */
#line 574 "parser.y"
                        {
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2363 "y.tab.c"
    break;

  case 81: /* $@7: %empty  */
#line 577 "parser.y"
                               { 
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2374 "y.tab.c"
    break;

  case 82: /* $@8: %empty  */
#line 584 "parser.y"
                    {
                      scope_history.push(++scope_counter);  
                    }
#line 2382 "y.tab.c"
    break;

  case 83: /* $@9: %empty  */
#line 586 "parser.y"
                                   {  
                        scope_history.pop(); 
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2392 "y.tab.c"
    break;

  case 84: /* if_stmt: IF $@6 OC expr CC $@7 OF $@8 stmt_list CF $@9 elif_stmt else_stmt  */
#line 591 "parser.y"
                                         {   
                        tac.push_back(string((yyvsp[-12].node).parentNext) + ":");
                    }
#line 2400 "y.tab.c"
    break;

  case 85: /* $@10: %empty  */
#line 596 "parser.y"
                         {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf((yyvsp[0].node).parentNext, "%s", hold);
                    }
#line 2410 "y.tab.c"
    break;

  case 86: /* $@11: %empty  */
#line 601 "parser.y"
                               {
                        // sprintf(icg[ic_idx++], "\nif (%s != 0) GOTO L%d else GOTO L%d\n", $4.token, label, label+1);
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");
                    }
#line 2422 "y.tab.c"
    break;

  case 87: /* $@12: %empty  */
#line 609 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 2430 "y.tab.c"
    break;

  case 88: /* $@13: %empty  */
#line 612 "parser.y"
                                 {
                        scope_history.pop();
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2440 "y.tab.c"
    break;

  case 91: /* $@14: %empty  */
#line 621 "parser.y"
                            {scope_history.push(++scope_counter);}
#line 2446 "y.tab.c"
    break;

  case 92: /* else_stmt: ELSE OF $@14 stmt_list CF  */
#line 621 "parser.y"
                                                                               {scope_history.pop();}
#line 2452 "y.tab.c"
    break;

  case 94: /* $@15: %empty  */
#line 625 "parser.y"
                           {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2462 "y.tab.c"
    break;

  case 95: /* $@16: %empty  */
#line 630 "parser.y"
                          {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme));
                    }
#line 2471 "y.tab.c"
    break;

  case 96: /* $@17: %empty  */
#line 634 "parser.y"
                                         {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
#line 2480 "y.tab.c"
    break;

  case 97: /* switch_stmt: SWITCH $@15 OC ID $@16 CC OF case_stmt_list $@17 default_stmt CF  */
#line 638 "parser.y"
                                    {
                        tac.push_back("Label " + string((yyvsp[-10].node).parentNext));
                        loop_break.pop();
                    }
#line 2489 "y.tab.c"
    break;

  case 98: /* case_stmt_list: case_stmt case_stmt_list  */
#line 644 "parser.y"
                                             {
                        strcpy((yyvsp[-1].node).id, (yyval.node).id);
                        strcpy((yyvsp[-1].node).parentNext, (yyval.node).parentNext);
                    }
#line 2498 "y.tab.c"
    break;

  case 100: /* $@18: %empty  */
#line 651 "parser.y"
                         {
                        // tac.push_back(string($4.if_body) + ":");
                    }
#line 2506 "y.tab.c"
    break;

  case 101: /* $@19: %empty  */
#line 654 "parser.y"
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
#line 2521 "y.tab.c"
    break;

  case 102: /* case_stmt: CASE $@18 OC const $@19 CC COLON stmt_list  */
#line 664 "parser.y"
                                       {
                        // tac.push_back("Label " + string($4.parentNext) + ":");
                        tac.push_back("Label " + string((yyvsp[-4].node).parentNext) + ":");
                    }
#line 2530 "y.tab.c"
    break;

  case 105: /* $@20: %empty  */
#line 673 "parser.y"
                          {
                        sprintf((yyvsp[0].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[0].node).loop_body) + ":");
                    }
#line 2540 "y.tab.c"
    break;

  case 106: /* $@21: %empty  */
#line 679 "parser.y"
                    {
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));
                        tac.push_back("\n" + string((yyvsp[-1].node).if_body) + ":");
                        
                    }
#line 2555 "y.tab.c"
    break;

  case 107: /* $@22: %empty  */
#line 689 "parser.y"
                      {
                        scope_history.push(++scope_counter);
                    }
#line 2563 "y.tab.c"
    break;

  case 108: /* while_loop_stmt: WHILE $@20 OC expr CC $@21 OF $@22 stmt_list CF  */
#line 692 "parser.y"
                    {
                        scope_history.pop();
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-6].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2575 "y.tab.c"
    break;

  case 109: /* $@23: %empty  */
#line 700 "parser.y"
                                       {
                        sprintf((yyvsp[-3].node).loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string((yyvsp[-3].node).loop_body) + ":");
                    }
#line 2584 "y.tab.c"
    break;

  case 110: /* $@24: %empty  */
#line 704 "parser.y"
                              {  
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));

                        sprintf((yyvsp[-1].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[-1].node).loop_body) + ":");
                    }
#line 2601 "y.tab.c"
    break;

  case 111: /* $@25: %empty  */
#line 716 "parser.y"
                              {
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-4].node).if_body) + ":");
                    }
#line 2610 "y.tab.c"
    break;

  case 112: /* $@26: %empty  */
#line 721 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 2618 "y.tab.c"
    break;

  case 113: /* for_loop_stmt: FOR OC assign SCOL $@23 expr SCOL $@24 assign CC $@25 OF $@26 stmt_list CF  */
#line 724 "parser.y"
                                 {
                        scope_history.pop();
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-9].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2630 "y.tab.c"
    break;

  case 114: /* $@27: %empty  */
#line 732 "parser.y"
                       {
                        func_call_id.push({string((yyvsp[0].node).lexeme), func_table[string((yyvsp[0].node).lexeme)].param_types});
                        }
#line 2638 "y.tab.c"
    break;

  case 115: /* func_call: ID $@27 OC arg_list CC  */
#line 735 "parser.y"
                                        {
                        strcpy((yyval.node).type, func_table[string((yyvsp[-4].node).lexeme)].return_type.c_str());
                        func_call_id.pop();
                        sprintf((yyval.node).lexeme, "@t%d", variable_count);
                        variable_count++;

                        // checking if function is declared
                        

                        tac.push_back(string((yyval.node).lexeme) + " = @call " + string((yyvsp[-4].node).lexeme) + " " + func_table[string((yyvsp[-4].node).lexeme)].return_type + " " + to_string(func_table[string((yyvsp[-4].node).lexeme)].num_params));
                    }
#line 2654 "y.tab.c"
    break;

  case 116: /* arg_list: arg COMMA arg_list  */
#line 748 "parser.y"
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
#line 2671 "y.tab.c"
    break;

  case 117: /* arg_list: arg  */
#line 760 "parser.y"
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
#line 2687 "y.tab.c"
    break;

  case 119: /* arg: expr  */
#line 774 "parser.y"
                         {
                        tac.push_back("param " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                    }
#line 2695 "y.tab.c"
    break;


#line 2699 "y.tab.c"

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

#line 779 "parser.y"


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

