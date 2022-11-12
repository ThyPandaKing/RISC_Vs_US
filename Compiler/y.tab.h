/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 104 "parser.y" /* yacc.c:1909  */

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

#line 181 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
