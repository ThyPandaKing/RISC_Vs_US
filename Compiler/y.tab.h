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
    VOID = 261,
    RETURN = 262,
    INT_NUM = 263,
    FLOAT_NUM = 264,
    ID = 265,
    LEFTSHIFT = 266,
    RIGHTSHIFT = 267,
    LE = 268,
    GE = 269,
    EQ = 270,
    NE = 271,
    GT = 272,
    LT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    ADD = 277,
    SUBTRACT = 278,
    DIVIDE = 279,
    MULTIPLY = 280,
    MODULO = 281,
    BITAND = 282,
    BITOR = 283,
    NEGATION = 284,
    XOR = 285,
    STR = 286,
    CHARACTER = 287,
    CC = 288,
    OC = 289,
    CS = 290,
    OS = 291,
    CF = 292,
    OF = 293,
    COMMA = 294,
    COLON = 295,
    SCOL = 296,
    OUTPUT = 297,
    INPUT = 298,
    SWITCH = 299,
    CASE = 300,
    BREAK = 301,
    DEFAULT = 302,
    IF = 303,
    ELIF = 304,
    ELSE = 305,
    WHILE = 306,
    FOR = 307,
    CONTINUE = 308,
    ASSIGN = 309
  };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define FLOAT 260
#define VOID 261
#define RETURN 262
#define INT_NUM 263
#define FLOAT_NUM 264
#define ID 265
#define LEFTSHIFT 266
#define RIGHTSHIFT 267
#define LE 268
#define GE 269
#define EQ 270
#define NE 271
#define GT 272
#define LT 273
#define AND 274
#define OR 275
#define NOT 276
#define ADD 277
#define SUBTRACT 278
#define DIVIDE 279
#define MULTIPLY 280
#define MODULO 281
#define BITAND 282
#define BITOR 283
#define NEGATION 284
#define XOR 285
#define STR 286
#define CHARACTER 287
#define CC 288
#define OC 289
#define CS 290
#define OS 291
#define CF 292
#define OF 293
#define COMMA 294
#define COLON 295
#define SCOL 296
#define OUTPUT 297
#define INPUT 298
#define SWITCH 299
#define CASE 300
#define BREAK 301
#define DEFAULT 302
#define IF 303
#define ELIF 304
#define ELSE 305
#define WHILE 306
#define FOR 307
#define CONTINUE 308
#define ASSIGN 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 76 "parser.y" /* yacc.c:1909  */

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

#line 179 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
