/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    INT = 258,
    CHAR = 259,
    FLOAT = 260,
    RETURN = 261,
    INT_NUM = 262,
    ID = 263,
    LEFTSHIFT = 264,
    RIGHTSHIFT = 265,
    LE = 266,
    GE = 267,
    EQ = 268,
    NE = 269,
    GT = 270,
    LT = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    ADD = 275,
    SUBTRACT = 276,
    DIVIDE = 277,
    MULTIPLY = 278,
    MODULO = 279,
    BITAND = 280,
    BITOR = 281,
    NEGATION = 282,
    XOR = 283,
    STR = 284,
    CHARACTER = 285,
    CC = 286,
    OC = 287,
    CS = 288,
    OS = 289,
    CF = 290,
    OF = 291,
    COMMA = 292,
    COLON = 293,
    SCOL = 294,
    PRINT = 295,
    SCAN = 296,
    ASSIGN = 297
  };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define FLOAT 260
#define RETURN 261
#define INT_NUM 262
#define ID 263
#define LEFTSHIFT 264
#define RIGHTSHIFT 265
#define LE 266
#define GE 267
#define EQ 268
#define NE 269
#define GT 270
#define LT 271
#define AND 272
#define OR 273
#define NOT 274
#define ADD 275
#define SUBTRACT 276
#define DIVIDE 277
#define MULTIPLY 278
#define MODULO 279
#define BITAND 280
#define BITOR 281
#define NEGATION 282
#define XOR 283
#define STR 284
#define CHARACTER 285
#define CC 286
#define OC 287
#define CS 288
#define OS 289
#define CF 290
#define OF 291
#define COMMA 292
#define COLON 293
#define SCOL 294
#define PRINT 295
#define SCAN 296
#define ASSIGN 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    struct node { 
        char lexeme[100];
        int line_number;
        char type[100];
    } node;

#line 149 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
