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
    TK_VOID = 258,                 /* TK_VOID  */
    TK_PRINTF = 259,               /* TK_PRINTF  */
    TK_SCANF = 260,                /* TK_SCANF  */
    TK_TYPE_INT = 261,             /* TK_TYPE_INT  */
    TK_TYPE_FLOAT = 262,           /* TK_TYPE_FLOAT  */
    TK_TYPE_CHAR = 263,            /* TK_TYPE_CHAR  */
    TK_RETURN = 264,               /* TK_RETURN  */
    TK_FOR = 265,                  /* TK_FOR  */
    TK_IF = 266,                   /* TK_IF  */
    TK_ELSE = 267,                 /* TK_ELSE  */
    TK_CLASS_DEFINITION = 268,     /* TK_CLASS_DEFINITION  */
    TK_CLASS_DEFINITION_MAIN = 269, /* TK_CLASS_DEFINITION_MAIN  */
    TK_INCLUDE = 270,              /* TK_INCLUDE  */
    TK_TRUE = 271,                 /* TK_TRUE  */
    TK_FALSE = 272,                /* TK_FALSE  */
    TK_NUMBER = 273,               /* TK_NUMBER  */
    TK_NUMBER_FLOAT = 274,         /* TK_NUMBER_FLOAT  */
    TK_ID = 275,                   /* TK_ID  */
    TK_CLASS_NAME = 276,           /* TK_CLASS_NAME  */
    TK_UNARY = 277,                /* TK_UNARY  */
    TK_LE = 278,                   /* TK_LE  */
    TK_GE = 279,                   /* TK_GE  */
    TK_EQ = 280,                   /* TK_EQ  */
    TK_NE = 281,                   /* TK_NE  */
    TK_GT = 282,                   /* TK_GT  */
    TK_LT = 283,                   /* TK_LT  */
    TK_AND = 284,                  /* TK_AND  */
    TK_OR = 285,                   /* TK_OR  */
    TK_ADD = 286,                  /* TK_ADD  */
    TK_SUBTRACT = 287,             /* TK_SUBTRACT  */
    TK_DIVIDE = 288,               /* TK_DIVIDE  */
    TK_MULTIPLY = 289,             /* TK_MULTIPLY  */
    TK_STRING = 290,               /* TK_STRING  */
    TK_CHARACTER = 291             /* TK_CHARACTER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_VOID 258
#define TK_PRINTF 259
#define TK_SCANF 260
#define TK_TYPE_INT 261
#define TK_TYPE_FLOAT 262
#define TK_TYPE_CHAR 263
#define TK_RETURN 264
#define TK_FOR 265
#define TK_IF 266
#define TK_ELSE 267
#define TK_CLASS_DEFINITION 268
#define TK_CLASS_DEFINITION_MAIN 269
#define TK_INCLUDE 270
#define TK_TRUE 271
#define TK_FALSE 272
#define TK_NUMBER 273
#define TK_NUMBER_FLOAT 274
#define TK_ID 275
#define TK_CLASS_NAME 276
#define TK_UNARY 277
#define TK_LE 278
#define TK_GE 279
#define TK_EQ 280
#define TK_NE 281
#define TK_GT 282
#define TK_LT 283
#define TK_AND 284
#define TK_OR 285
#define TK_ADD 286
#define TK_SUBTRACT 287
#define TK_DIVIDE 288
#define TK_MULTIPLY 289
#define TK_STRING 290
#define TK_CHARACTER 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "sintatico_part1.y"
 struct var_name { 
			char name[100]; 
			struct node* nd;
		} nd_obj;

#line 145 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
