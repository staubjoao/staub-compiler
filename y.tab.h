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
# define YYDEBUG 0
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
    TK_MAIN = 258,                 /* TK_MAIN  */
    TK_PRINTF = 259,               /* TK_PRINTF  */
    TK_SCANFF = 260,               /* TK_SCANFF  */
    TK_TYPE_INT = 261,             /* TK_TYPE_INT  */
    TK_TYPE_FLOAT = 262,           /* TK_TYPE_FLOAT  */
    TK_TYPE_CHAR = 263,            /* TK_TYPE_CHAR  */
    TK_TYPE_STRING = 264,          /* TK_TYPE_STRING  */
    TK_VOID = 265,                 /* TK_VOID  */
    TK_RETURN = 266,               /* TK_RETURN  */
    TK_WHILE = 267,                /* TK_WHILE  */
    TK_IF = 268,                   /* TK_IF  */
    TK_ELSE = 269,                 /* TK_ELSE  */
    TK_CLASS = 270,                /* TK_CLASS  */
    TK_INCLUDE = 271,              /* TK_INCLUDE  */
    TK_NUMBER = 272,               /* TK_NUMBER  */
    TK_FLOAT_NUM = 273,            /* TK_FLOAT_NUM  */
    TK_ID = 274,                   /* TK_ID  */
    TK_CLASS_NAME = 275,           /* TK_CLASS_NAME  */
    TK_UNARY = 276,                /* TK_UNARY  */
    TK_LE = 277,                   /* TK_LE  */
    TK_GE = 278,                   /* TK_GE  */
    TK_EQ = 279,                   /* TK_EQ  */
    TK_NE = 280,                   /* TK_NE  */
    TK_GT = 281,                   /* TK_GT  */
    TK_LT = 282,                   /* TK_LT  */
    TK_AND = 283,                  /* TK_AND  */
    TK_OR = 284,                   /* TK_OR  */
    TK_ADD = 285,                  /* TK_ADD  */
    TK_SUBTRACT = 286,             /* TK_SUBTRACT  */
    TK_DIVIDE = 287,               /* TK_DIVIDE  */
    TK_MULTIPLY = 288,             /* TK_MULTIPLY  */
    TK_STRING = 289,               /* TK_STRING  */
    TK_CHAR = 290                  /* TK_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_MAIN 258
#define TK_PRINTF 259
#define TK_SCANFF 260
#define TK_TYPE_INT 261
#define TK_TYPE_FLOAT 262
#define TK_TYPE_CHAR 263
#define TK_TYPE_STRING 264
#define TK_VOID 265
#define TK_RETURN 266
#define TK_WHILE 267
#define TK_IF 268
#define TK_ELSE 269
#define TK_CLASS 270
#define TK_INCLUDE 271
#define TK_NUMBER 272
#define TK_FLOAT_NUM 273
#define TK_ID 274
#define TK_CLASS_NAME 275
#define TK_UNARY 276
#define TK_LE 277
#define TK_GE 278
#define TK_EQ 279
#define TK_NE 280
#define TK_GT 281
#define TK_LT 282
#define TK_AND 283
#define TK_OR 284
#define TK_ADD 285
#define TK_SUBTRACT 286
#define TK_DIVIDE 287
#define TK_MULTIPLY 288
#define TK_STRING 289
#define TK_CHAR 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
