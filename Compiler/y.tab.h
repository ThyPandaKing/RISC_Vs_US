/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 78 "parser.y"

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

#line 194 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
