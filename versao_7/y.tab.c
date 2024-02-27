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

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"util.h"
    #include"lex.yy.c"

#line 80 "y.tab.c"

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
    TK_INCLUDE = 259,              /* TK_INCLUDE  */
    TK_PRINTF = 260,               /* TK_PRINTF  */
    TK_SCANF = 261,                /* TK_SCANF  */
    TK_TYPE_INT = 262,             /* TK_TYPE_INT  */
    TK_TYPE_FLOAT = 263,           /* TK_TYPE_FLOAT  */
    TK_TYPE_CHAR = 264,            /* TK_TYPE_CHAR  */
    TK_TYPE_STRING = 265,          /* TK_TYPE_STRING  */
    TK_RETURN = 266,               /* TK_RETURN  */
    TK_FOR = 267,                  /* TK_FOR  */
    TK_IF = 268,                   /* TK_IF  */
    TK_ELSE = 269,                 /* TK_ELSE  */
    TK_CLASS_DEFINITION = 270,     /* TK_CLASS_DEFINITION  */
    TK_FUNC_DEFINITION_MAIN = 271, /* TK_FUNC_DEFINITION_MAIN  */
    TK_CLASS_DEFINITION_MAIN = 272, /* TK_CLASS_DEFINITION_MAIN  */
    TK_TRUE = 273,                 /* TK_TRUE  */
    TK_FALSE = 274,                /* TK_FALSE  */
    TK_NUMBER = 275,               /* TK_NUMBER  */
    TK_NUMBER_FLOAT = 276,         /* TK_NUMBER_FLOAT  */
    TK_ID = 277,                   /* TK_ID  */
    TK_CLASS_NAME = 278,           /* TK_CLASS_NAME  */
    TK_UNARY = 279,                /* TK_UNARY  */
    TK_LE = 280,                   /* TK_LE  */
    TK_GE = 281,                   /* TK_GE  */
    TK_EQ = 282,                   /* TK_EQ  */
    TK_NE = 283,                   /* TK_NE  */
    TK_GT = 284,                   /* TK_GT  */
    TK_LT = 285,                   /* TK_LT  */
    TK_AND = 286,                  /* TK_AND  */
    TK_OR = 287,                   /* TK_OR  */
    TK_STRING = 288,               /* TK_STRING  */
    TK_CHARACTER = 289,            /* TK_CHARACTER  */
    TK_MULTIPLY = 290,             /* TK_MULTIPLY  */
    TK_DIVIDE = 291,               /* TK_DIVIDE  */
    TK_ADD = 292,                  /* TK_ADD  */
    TK_SUBTRACT = 293              /* TK_SUBTRACT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_VOID 258
#define TK_INCLUDE 259
#define TK_PRINTF 260
#define TK_SCANF 261
#define TK_TYPE_INT 262
#define TK_TYPE_FLOAT 263
#define TK_TYPE_CHAR 264
#define TK_TYPE_STRING 265
#define TK_RETURN 266
#define TK_FOR 267
#define TK_IF 268
#define TK_ELSE 269
#define TK_CLASS_DEFINITION 270
#define TK_FUNC_DEFINITION_MAIN 271
#define TK_CLASS_DEFINITION_MAIN 272
#define TK_TRUE 273
#define TK_FALSE 274
#define TK_NUMBER 275
#define TK_NUMBER_FLOAT 276
#define TK_ID 277
#define TK_CLASS_NAME 278
#define TK_UNARY 279
#define TK_LE 280
#define TK_GE 281
#define TK_EQ 282
#define TK_NE 283
#define TK_GT 284
#define TK_LT 285
#define TK_AND 286
#define TK_OR 287
#define TK_STRING 288
#define TK_CHARACTER 289
#define TK_MULTIPLY 290
#define TK_DIVIDE 291
#define TK_ADD 292
#define TK_SUBTRACT 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "parser.y"

struct var_name 
{ 
	char name[100]; 
	struct node* nd;
} nd_obj;

struct var_name2 
{ 
	char name[100]; 
	struct node* nd;
	char type[10];
} nd_obj2; 

struct var_name3 {
	char name[100];
	struct node* nd;
	char if_body[5];
	char else_body[5];
} nd_obj3;

#line 231 "y.tab.c"

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
  YYSYMBOL_TK_VOID = 3,                    /* TK_VOID  */
  YYSYMBOL_TK_INCLUDE = 4,                 /* TK_INCLUDE  */
  YYSYMBOL_TK_PRINTF = 5,                  /* TK_PRINTF  */
  YYSYMBOL_TK_SCANF = 6,                   /* TK_SCANF  */
  YYSYMBOL_TK_TYPE_INT = 7,                /* TK_TYPE_INT  */
  YYSYMBOL_TK_TYPE_FLOAT = 8,              /* TK_TYPE_FLOAT  */
  YYSYMBOL_TK_TYPE_CHAR = 9,               /* TK_TYPE_CHAR  */
  YYSYMBOL_TK_TYPE_STRING = 10,            /* TK_TYPE_STRING  */
  YYSYMBOL_TK_RETURN = 11,                 /* TK_RETURN  */
  YYSYMBOL_TK_FOR = 12,                    /* TK_FOR  */
  YYSYMBOL_TK_IF = 13,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 14,                   /* TK_ELSE  */
  YYSYMBOL_TK_CLASS_DEFINITION = 15,       /* TK_CLASS_DEFINITION  */
  YYSYMBOL_TK_FUNC_DEFINITION_MAIN = 16,   /* TK_FUNC_DEFINITION_MAIN  */
  YYSYMBOL_TK_CLASS_DEFINITION_MAIN = 17,  /* TK_CLASS_DEFINITION_MAIN  */
  YYSYMBOL_TK_TRUE = 18,                   /* TK_TRUE  */
  YYSYMBOL_TK_FALSE = 19,                  /* TK_FALSE  */
  YYSYMBOL_TK_NUMBER = 20,                 /* TK_NUMBER  */
  YYSYMBOL_TK_NUMBER_FLOAT = 21,           /* TK_NUMBER_FLOAT  */
  YYSYMBOL_TK_ID = 22,                     /* TK_ID  */
  YYSYMBOL_TK_CLASS_NAME = 23,             /* TK_CLASS_NAME  */
  YYSYMBOL_TK_UNARY = 24,                  /* TK_UNARY  */
  YYSYMBOL_TK_LE = 25,                     /* TK_LE  */
  YYSYMBOL_TK_GE = 26,                     /* TK_GE  */
  YYSYMBOL_TK_EQ = 27,                     /* TK_EQ  */
  YYSYMBOL_TK_NE = 28,                     /* TK_NE  */
  YYSYMBOL_TK_GT = 29,                     /* TK_GT  */
  YYSYMBOL_TK_LT = 30,                     /* TK_LT  */
  YYSYMBOL_TK_AND = 31,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 32,                     /* TK_OR  */
  YYSYMBOL_TK_STRING = 33,                 /* TK_STRING  */
  YYSYMBOL_TK_CHARACTER = 34,              /* TK_CHARACTER  */
  YYSYMBOL_TK_MULTIPLY = 35,               /* TK_MULTIPLY  */
  YYSYMBOL_TK_DIVIDE = 36,                 /* TK_DIVIDE  */
  YYSYMBOL_TK_ADD = 37,                    /* TK_ADD  */
  YYSYMBOL_TK_SUBTRACT = 38,               /* TK_SUBTRACT  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_49_ = 49,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_class = 53,                     /* class  */
  YYSYMBOL_class_defination = 54,          /* class_defination  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_class_body = 56,                /* class_body  */
  YYSYMBOL_57_3 = 57,                      /* $@3  */
  YYSYMBOL_class_body_main = 58,           /* class_body_main  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_method_signature = 60,          /* method_signature  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_atributs_method = 62,           /* atributs_method  */
  YYSYMBOL_parament_method = 63,           /* parament_method  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_class_atributes = 65,           /* class_atributes  */
  YYSYMBOL_datatype = 66,                  /* datatype  */
  YYSYMBOL_body_main = 67,                 /* body_main  */
  YYSYMBOL_body_main_statement = 68,       /* body_main_statement  */
  YYSYMBOL_69_7 = 69,                      /* $@7  */
  YYSYMBOL_70_8 = 70,                      /* $@8  */
  YYSYMBOL_71_9 = 71,                      /* $@9  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_73_11 = 73,                     /* $@11  */
  YYSYMBOL_74_12 = 74,                     /* $@12  */
  YYSYMBOL_else_main = 75,                 /* else_main  */
  YYSYMBOL_76_13 = 76,                     /* $@13  */
  YYSYMBOL_body = 77,                      /* body  */
  YYSYMBOL_body_statement = 78,            /* body_statement  */
  YYSYMBOL_79_14 = 79,                     /* $@14  */
  YYSYMBOL_80_15 = 80,                     /* $@15  */
  YYSYMBOL_81_16 = 81,                     /* $@16  */
  YYSYMBOL_82_17 = 82,                     /* $@17  */
  YYSYMBOL_else = 83,                      /* else  */
  YYSYMBOL_84_18 = 84,                     /* $@18  */
  YYSYMBOL_init_vector = 85,               /* init_vector  */
  YYSYMBOL_init_vector_value = 86,         /* init_vector_value  */
  YYSYMBOL_init_vector_value_aux = 87,     /* init_vector_value_aux  */
  YYSYMBOL_statement_class = 88,           /* statement_class  */
  YYSYMBOL_89_19 = 89,                     /* $@19  */
  YYSYMBOL_condition = 90,                 /* condition  */
  YYSYMBOL_statement_atributes = 91,       /* statement_atributes  */
  YYSYMBOL_92_20 = 92,                     /* $@20  */
  YYSYMBOL_statement = 93,                 /* statement  */
  YYSYMBOL_94_21 = 94,                     /* $@21  */
  YYSYMBOL_95_22 = 95,                     /* $@22  */
  YYSYMBOL_96_23 = 96,                     /* $@23  */
  YYSYMBOL_97_24 = 97,                     /* $@24  */
  YYSYMBOL_98_25 = 98,                     /* $@25  */
  YYSYMBOL_99_26 = 99,                     /* $@26  */
  YYSYMBOL_100_27 = 100,                   /* $@27  */
  YYSYMBOL_class_call = 101,               /* class_call  */
  YYSYMBOL_102_28 = 102,                   /* $@28  */
  YYSYMBOL_params_const = 103,             /* params_const  */
  YYSYMBOL_param_const = 104,              /* param_const  */
  YYSYMBOL_class_call_aux = 105,           /* class_call_aux  */
  YYSYMBOL_106_29 = 106,                   /* $@29  */
  YYSYMBOL_init = 107,                     /* init  */
  YYSYMBOL_expression = 108,               /* expression  */
  YYSYMBOL_relop = 109,                    /* relop  */
  YYSYMBOL_value = 110,                    /* value  */
  YYSYMBOL_return = 111,                   /* return  */
  YYSYMBOL_112_30 = 112                    /* $@30  */
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      41,    42,     2,     2,    43,     2,    49,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    41,    46,    57,    62,    62,    68,    71,
      71,    78,    83,    83,    86,    92,    92,    99,   103,   107,
     112,   112,   118,   123,   124,   125,   126,   127,   130,   133,
     138,   138,   144,   144,   144,   144,   149,   152,   155,   155,
     159,   159,   164,   164,   167,   172,   175,   180,   180,   183,
     183,   187,   190,   190,   193,   193,   198,   198,   201,   206,
     212,   217,   221,   225,   231,   236,   236,   239,   252,   253,
     254,   259,   259,   266,   266,   272,   272,   280,   280,   284,
     284,   294,   295,   295,   295,   299,   299,   305,   305,   309,
     317,   320,   323,   328,   333,   333,   340,   345,   352,   378,
     409,   435,   461,   466,   487,   488,   489,   490,   491,   492,
     495,   500,   505,   510,   521,   528,   528,   533
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_VOID",
  "TK_INCLUDE", "TK_PRINTF", "TK_SCANF", "TK_TYPE_INT", "TK_TYPE_FLOAT",
  "TK_TYPE_CHAR", "TK_TYPE_STRING", "TK_RETURN", "TK_FOR", "TK_IF",
  "TK_ELSE", "TK_CLASS_DEFINITION", "TK_FUNC_DEFINITION_MAIN",
  "TK_CLASS_DEFINITION_MAIN", "TK_TRUE", "TK_FALSE", "TK_NUMBER",
  "TK_NUMBER_FLOAT", "TK_ID", "TK_CLASS_NAME", "TK_UNARY", "TK_LE",
  "TK_GE", "TK_EQ", "TK_NE", "TK_GT", "TK_LT", "TK_AND", "TK_OR",
  "TK_STRING", "TK_CHARACTER", "TK_MULTIPLY", "TK_DIVIDE", "TK_ADD",
  "TK_SUBTRACT", "'{'", "'}'", "'('", "')'", "','", "';'", "'&'", "'='",
  "'['", "']'", "'.'", "$accept", "program", "$@1", "class",
  "class_defination", "$@2", "class_body", "$@3", "class_body_main", "$@4",
  "method_signature", "$@5", "atributs_method", "parament_method", "$@6",
  "class_atributes", "datatype", "body_main", "body_main_statement", "$@7",
  "$@8", "$@9", "$@10", "$@11", "$@12", "else_main", "$@13", "body",
  "body_statement", "$@14", "$@15", "$@16", "$@17", "else", "$@18",
  "init_vector", "init_vector_value", "init_vector_value_aux",
  "statement_class", "$@19", "condition", "statement_atributes", "$@20",
  "statement", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27",
  "class_call", "$@28", "params_const", "param_const", "class_call_aux",
  "$@29", "init", "expression", "relop", "value", "return", "$@30", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-95)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -12,  -173,    24,     3,  -173,     8,    15,  -173,  -173,
     138,    42,  -173,  -173,  -173,  -173,  -173,  -173,    22,    38,
     138,    58,    37,  -173,    48,     4,    10,  -173,    65,  -173,
      72,  -173,  -173,   138,    47,    10,    69,  -173,    68,    74,
      10,  -173,  -173,  -173,    43,  -173,    88,  -173,    89,  -173,
    -173,  -173,    77,  -173,  -173,    99,    66,  -173,    87,   112,
      80,    18,    43,    43,    43,    43,  -173,  -173,  -173,  -173,
      -1,  -173,   121,   113,    87,   108,   115,  -173,   116,  -173,
    -173,  -173,  -173,   149,   112,   118,   142,  -173,    50,   130,
      18,  -173,    36,    36,  -173,  -173,   122,   132,   133,   134,
     131,   141,   152,   135,   156,   136,  -173,  -173,  -173,  -173,
      18,    68,   139,   140,   143,   144,  -173,   146,  -173,  -173,
    -173,  -173,  -173,  -173,   154,   155,   117,   117,    43,  -173,
    -173,  -173,  -173,  -173,  -173,    43,  -173,   159,  -173,    68,
     145,   147,  -173,   157,   158,   117,   117,    50,   138,   151,
     153,  -173,  -173,   160,   141,   161,    66,    66,   150,  -173,
     174,  -173,   162,   163,   165,   166,   167,  -173,   168,   164,
     171,    50,  -173,   169,   170,   172,   175,   178,   180,  -173,
    -173,   173,    87,  -173,   182,    43,  -173,  -173,   177,   112,
     112,   181,   184,    87,    66,   176,   183,   186,   187,   185,
    -173,   188,   191,  -173,   189,  -173,   199,  -173,  -173,    35,
    -173,  -173,  -173,   200,    50,   192,    35,  -173,   195,  -173,
    -173,    35,  -173,  -173,   112,   196,  -173,   197,    87,  -173,
     198,  -173
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     2,     0,     0,     4,     0,     0,     1,     6,
      11,    14,     7,    27,    23,    24,    25,    26,     0,     0,
      11,     0,     0,    12,     0,     0,    19,     8,    71,    22,
       0,     3,     5,     0,     0,    19,     0,    16,    97,     0,
      19,     9,    17,    20,     0,    72,     0,    18,     0,    21,
     110,   111,   113,   114,   112,     0,    96,   102,    29,    46,
       0,    92,     0,     0,     0,     0,    38,    40,    30,    32,
      77,    65,     0,     0,    29,     0,     0,    81,    87,    52,
      54,    47,    49,   117,    46,     0,     0,   113,     0,     0,
      92,    93,    98,    99,   101,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    13,    28,    36,    37,
      92,    97,     0,     0,     0,     0,   115,     0,    45,    51,
      95,    91,   103,    90,     0,     0,    70,    70,     0,   106,
     107,   108,   109,   105,   104,     0,    80,     0,    66,    97,
       0,     0,    88,     0,     0,    70,    70,     0,    11,     0,
       0,    68,    69,     0,     0,     0,    76,    78,     0,    74,
       0,    89,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,   116,
      39,     0,    29,    67,     0,     0,    83,    53,     0,    46,
      46,     0,     0,    29,    86,    60,     0,     0,     0,     0,
      31,     0,     0,    84,     0,    48,    58,    41,    34,    63,
      55,    56,    50,    44,     0,     0,    63,    64,     0,    42,
      35,    63,    59,    61,    46,     0,    62,     0,    29,    57,
       0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,   206,  -173,  -173,  -173,  -173,   -15,  -173,  -173,  -173,
    -173,  -173,     2,   203,  -173,  -173,    -4,   -70,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,   -82,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -172,   -17,  -173,  -173,
     -86,  -173,  -173,   -59,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,   -83,   179,   -30,  -173,   -96,   -53,    46,
     -60,  -173,  -173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     7,     5,     6,    12,    18,    48,    24,    30,
      19,    37,    34,    35,    49,    20,    72,    73,    74,    98,
      99,   184,   213,    96,    97,   220,   225,    83,    84,   114,
     115,   112,   113,   212,   218,   203,   215,   216,    75,   104,
     153,    22,    38,    76,   139,   100,   101,   102,   140,   195,
     103,    77,   111,    89,    90,    78,    60,    45,    56,   135,
      57,   117,   147
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,    91,   118,     4,   107,    27,    21,   123,     1,    92,
      93,    94,    95,    13,    55,   142,    21,    14,    15,    16,
      17,     2,    36,   -79,     8,    85,     9,   141,    91,    36,
      91,    36,    55,    55,    55,    55,    36,    42,    50,    51,
      87,   155,    47,   159,   223,   -75,   -85,    10,   -94,   226,
      91,    53,    54,    33,    11,    50,    51,    87,    23,   164,
     165,    88,    25,    50,    51,    52,   154,   154,    53,    54,
      50,    51,    87,    64,    65,   156,    53,    54,   214,    26,
      28,    29,   157,    53,    54,   154,   154,   166,    31,    41,
      13,    43,    66,    67,    14,    15,    16,    17,    55,    68,
      69,    62,    63,    64,    65,    55,   -15,   197,   198,    70,
      71,   183,   192,    39,    44,    13,    46,    79,    80,    14,
      15,    16,    17,   201,    81,    82,   -94,    58,    59,    86,
      85,    85,   194,   167,    70,   151,   152,    50,    51,    87,
      61,    13,   227,   105,    21,    14,    15,    16,    17,   217,
      53,    54,   108,   106,   217,    55,   217,   110,   230,   109,
     116,   217,   119,   124,   120,    85,   129,   130,   131,   132,
     133,   134,   122,   125,   126,   127,   136,   128,   138,   158,
     143,   144,   137,   -82,   145,   146,   148,   149,   150,   161,
     162,   163,   160,   168,   174,   191,   169,   221,   173,   196,
     171,     0,   170,   172,   175,     0,   176,   177,   178,   181,
     182,   179,   180,   211,   219,   185,   187,   189,   186,   190,
     188,   193,   202,   199,   200,   204,   205,   206,   208,   207,
     209,    32,   222,   210,   224,   228,    40,   229,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121
};

static const yytype_int16 yycheck[] =
{
      59,    61,    84,    15,    74,    20,    10,    90,     4,    62,
      63,    64,    65,     3,    44,   111,    20,     7,     8,     9,
      10,    17,    26,    24,     0,    84,    23,   110,    88,    33,
      90,    35,    62,    63,    64,    65,    40,    35,    20,    21,
      22,   127,    40,   139,   216,    46,    47,    39,    49,   221,
     110,    33,    34,    43,    39,    20,    21,    22,    16,   145,
     146,    43,    40,    20,    21,    22,   126,   127,    33,    34,
      20,    21,    22,    37,    38,   128,    33,    34,    43,    41,
      22,    44,   135,    33,    34,   145,   146,   147,    40,    42,
       3,    22,     5,     6,     7,     8,     9,    10,   128,    12,
      13,    35,    36,    37,    38,   135,    41,   189,   190,    22,
      23,   171,   182,    41,    46,     3,    42,     5,     6,     7,
       8,     9,    10,   193,    12,    13,    49,    39,    39,    49,
     189,   190,   185,   148,    22,    18,    19,    20,    21,    22,
      41,     3,   224,    22,   148,     7,     8,     9,    10,   209,
      33,    34,    44,    40,   214,   185,   216,    41,   228,    44,
      11,   221,    44,    41,    22,   224,    25,    26,    27,    28,
      29,    30,    42,    41,    41,    41,    24,    46,    22,    20,
      41,    41,    47,    47,    41,    41,    40,    33,    33,    42,
      33,    33,    47,    42,    20,    22,    43,   214,    48,    22,
     154,    -1,    42,    42,    42,    -1,    43,    42,    42,    45,
      39,    44,    44,    14,    14,    46,    44,    39,    48,    39,
      45,    39,    46,    42,    40,    42,    40,    40,    40,    44,
      39,    25,    40,    44,    39,    39,    33,    40,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    17,    51,    15,    53,    54,    52,     0,    23,
      39,    39,    55,     3,     7,     8,     9,    10,    56,    60,
      65,    66,    91,    16,    58,    40,    41,    56,    22,    44,
      59,    40,    51,    43,    62,    63,    66,    61,    92,    41,
      63,    42,    62,    22,    46,   107,    42,    62,    57,    64,
      20,    21,    22,    33,    34,   105,   108,   110,    39,    39,
     106,    41,    35,    36,    37,    38,     5,     6,    12,    13,
      22,    23,    66,    67,    68,    88,    93,   101,   105,     5,
       6,    12,    13,    77,    78,    93,    49,    22,    43,   103,
     104,   110,   108,   108,   108,   108,    73,    74,    69,    70,
      95,    96,    97,   100,    89,    22,    40,    67,    44,    44,
      41,   102,    81,    82,    79,    80,    11,   111,    77,    44,
      22,   104,    42,   103,    41,    41,    41,    41,    46,    25,
      26,    27,    28,    29,    30,   109,    24,    47,    22,    94,
      98,   103,   107,    41,    41,    41,    41,   112,    40,    33,
      33,    18,    19,    90,   110,    90,   108,   108,    20,   107,
      47,    42,    33,    33,    90,    90,   110,    56,    42,    43,
      42,   109,    42,    48,    20,    42,    43,    42,    42,    44,
      44,    45,    39,   110,    71,    46,    48,    44,    45,    39,
      39,    22,    67,    39,   108,    99,    22,    77,    77,    42,
      40,    67,    46,    85,    42,    40,    40,    44,    40,    39,
      44,    14,    83,    72,    43,    86,    87,   110,    84,    14,
      75,    87,    40,    86,    39,    76,    86,    77,    39,    40,
      67,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    51,    51,    53,    55,    54,    56,    57,
      56,    56,    59,    58,    58,    61,    60,    62,    62,    62,
      64,    63,    65,    66,    66,    66,    66,    66,    67,    67,
      69,    68,    70,    71,    72,    68,    68,    68,    73,    68,
      74,    68,    76,    75,    75,    77,    77,    79,    78,    80,
      78,    78,    81,    78,    82,    78,    84,    83,    83,    85,
      85,    86,    86,    86,    87,    89,    88,    90,    90,    90,
      90,    92,    91,    94,    93,    95,    93,    96,    93,    97,
      93,    93,    98,    99,    93,   100,    93,   102,   101,   101,
     103,   103,   103,   104,   106,   105,   107,   107,   108,   108,
     108,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   112,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     2,     5,     0,     3,     2,     0,
      10,     0,     0,     7,     0,     0,     3,     2,     3,     0,
       0,     3,     2,     1,     1,     1,     1,     1,     2,     0,
       0,     8,     0,     0,     0,    11,     2,     2,     0,     6,
       0,     9,     0,     5,     0,     2,     0,     0,     8,     0,
       9,     2,     0,     6,     0,     9,     0,     5,     0,     4,
       0,     2,     3,     0,     1,     0,     3,     3,     1,     1,
       0,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       3,     1,     0,     0,     8,     0,     7,     0,     3,     4,
       2,     2,     0,     1,     0,     4,     2,     0,     3,     3,
       3,     3,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     0
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
  case 2: /* $@1: %empty  */
#line 41 "parser.y"
                                  { class_scope_count++; add('Z'); }
#line 1496 "y.tab.c"
    break;

  case 3: /* program: TK_CLASS_DEFINITION_MAIN $@1 '{' class_body_main '}'  */
#line 41 "parser.y"
                                                                                              { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).nd, "program"); 
    princial_bool = 1;
    head = (yyval.nd_obj).nd; 
}
#line 1506 "y.tab.c"
    break;

  case 4: /* program: TK_INCLUDE class  */
#line 46 "parser.y"
                   {
    class_aux = (yyvsp[0].nd_obj).nd;
    if (head_class_l_aux == NULL) {
        head_class_l_aux = head_class_l;
    } else {
        head_class_l_aux = head_class_l_aux->next;
    } 
    head_class_l_aux->head = class_aux;
}
#line 1520 "y.tab.c"
    break;

  case 5: /* class: class_defination '{' class_body '}' program  */
#line 57 "parser.y"
                                                   {
    (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "class");
}
#line 1528 "y.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 62 "parser.y"
                                                    { class_scope_count++; add('Z'); }
#line 1534 "y.tab.c"
    break;

  case 7: /* class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME $@2  */
#line 62 "parser.y"
                                                                                       { 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "class"); 
    class_name_current = strdup((yyvsp[-1].nd_obj).name);
}
#line 1543 "y.tab.c"
    break;

  case 8: /* class_body: class_atributes class_body  */
#line 68 "parser.y"
                                       { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "class_body"); 
}
#line 1551 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 71 "parser.y"
                                            {
    symbol_table[method_current].num_param = count_param_vector;
    count_param_vector = 0;
}
#line 1560 "y.tab.c"
    break;

  case 10: /* class_body: method_signature '(' atributs_method ')' $@3 '{' body return '}' class_body  */
#line 74 "parser.y"
                                 {
    struct node *aux_class = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj).nd, "class_body");
    (yyval.nd_obj).nd = mknode(aux_class, (yyvsp[-2].nd_obj).nd, "method");
}
#line 1569 "y.tab.c"
    break;

  case 11: /* class_body: %empty  */
#line 78 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL; 
}
#line 1577 "y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 83 "parser.y"
                                         { scope_count++; }
#line 1583 "y.tab.c"
    break;

  case 13: /* class_body_main: TK_FUNC_DEFINITION_MAIN $@4 '(' ')' '{' body_main '}'  */
#line 83 "parser.y"
                                                                                      {
    (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, "main");
}
#line 1591 "y.tab.c"
    break;

  case 14: /* class_body_main: %empty  */
#line 86 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL; 
}
#line 1599 "y.tab.c"
    break;

  case 15: /* $@5: %empty  */
#line 92 "parser.y"
                                 { check_method_declaration_previously((yyvsp[0].nd_obj).name); scope_count++; add('F'); }
#line 1605 "y.tab.c"
    break;

  case 16: /* method_signature: datatype TK_ID $@5  */
#line 92 "parser.y"
                                                                                                            {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
    method_current = count-1;
}
#line 1614 "y.tab.c"
    break;

  case 17: /* atributs_method: parament_method atributs_method  */
#line 99 "parser.y"
                                                 {
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "parameter");
    count_param_vector++;
}
#line 1623 "y.tab.c"
    break;

  case 18: /* atributs_method: ',' parament_method atributs_method  */
#line 103 "parser.y"
                                     {
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "parameter");
    count_param_vector++;
}
#line 1632 "y.tab.c"
    break;

  case 19: /* atributs_method: %empty  */
#line 107 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1640 "y.tab.c"
    break;

  case 20: /* $@6: %empty  */
#line 112 "parser.y"
                                { add('P'); }
#line 1646 "y.tab.c"
    break;

  case 21: /* parament_method: datatype TK_ID $@6  */
#line 112 "parser.y"
                                              {
    (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "parameter");  
}
#line 1655 "y.tab.c"
    break;

  case 22: /* class_atributes: statement_atributes ';'  */
#line 118 "parser.y"
                                         {
    (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
}
#line 1663 "y.tab.c"
    break;

  case 23: /* datatype: TK_TYPE_INT  */
#line 123 "parser.y"
                      { insert_type(); }
#line 1669 "y.tab.c"
    break;

  case 24: /* datatype: TK_TYPE_FLOAT  */
#line 124 "parser.y"
                { insert_type(); }
#line 1675 "y.tab.c"
    break;

  case 25: /* datatype: TK_TYPE_CHAR  */
#line 125 "parser.y"
               { insert_type(); }
#line 1681 "y.tab.c"
    break;

  case 26: /* datatype: TK_TYPE_STRING  */
#line 126 "parser.y"
                 { insert_type(); }
#line 1687 "y.tab.c"
    break;

  case 27: /* datatype: TK_VOID  */
#line 127 "parser.y"
          { insert_type(); }
#line 1693 "y.tab.c"
    break;

  case 28: /* body_main: body_main_statement body_main  */
#line 130 "parser.y"
                                         { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, ""); 
}
#line 1701 "y.tab.c"
    break;

  case 29: /* body_main: %empty  */
#line 133 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1709 "y.tab.c"
    break;

  case 30: /* $@7: %empty  */
#line 138 "parser.y"
                            { add('K'); }
#line 1715 "y.tab.c"
    break;

  case 31: /* body_main_statement: TK_FOR $@7 '(' condition ')' '{' body_main '}'  */
#line 138 "parser.y"
                                                                              {
    (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj3).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-7].nd_obj).name);
    strcpy(icg[ic_idx++], buff);
	sprintf(icg[ic_idx++], "JUMP to %s\n", (yyvsp[-4].nd_obj3).if_body);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-4].nd_obj3).else_body);
}
#line 1726 "y.tab.c"
    break;

  case 32: /* $@8: %empty  */
#line 144 "parser.y"
        { add('K'); }
#line 1732 "y.tab.c"
    break;

  case 33: /* $@9: %empty  */
#line 144 "parser.y"
                                        { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-1].nd_obj3).if_body); }
#line 1738 "y.tab.c"
    break;

  case 34: /* $@10: %empty  */
#line 144 "parser.y"
                                                                                                                   { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-5].nd_obj3).else_body); }
#line 1744 "y.tab.c"
    break;

  case 35: /* body_main_statement: TK_IF $@8 '(' condition ')' $@9 '{' body_main '}' $@10 else_main  */
#line 144 "parser.y"
                                                                                                                                                                                        {
    struct node *iff = mknode((yyvsp[-7].nd_obj3).nd, (yyvsp[-3].nd_obj).nd, (yyvsp[-10].nd_obj).name);
    (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else");
    printf(icg[ic_idx++], "GOTO next\n");
}
#line 1754 "y.tab.c"
    break;

  case 36: /* body_main_statement: statement_class ';'  */
#line 149 "parser.y"
                      {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
}
#line 1762 "y.tab.c"
    break;

  case 37: /* body_main_statement: statement ';'  */
#line 152 "parser.y"
                {
    (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
}
#line 1770 "y.tab.c"
    break;

  case 38: /* $@11: %empty  */
#line 155 "parser.y"
            { add('K'); }
#line 1776 "y.tab.c"
    break;

  case 39: /* body_main_statement: TK_PRINTF $@11 '(' TK_STRING ')' ';'  */
#line 155 "parser.y"
                                                {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
	sprintf(icg[ic_idx++], "PRINT %s\n", (yyvsp[-2].nd_obj).name);
}
#line 1785 "y.tab.c"
    break;

  case 40: /* $@12: %empty  */
#line 159 "parser.y"
           { add('K'); }
#line 1791 "y.tab.c"
    break;

  case 41: /* body_main_statement: TK_SCANF $@12 '(' TK_STRING ',' '&' TK_ID ')' ';'  */
#line 159 "parser.y"
                                                             {
    (yyval.nd_obj).nd = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-8].nd_obj).name);
}
#line 1799 "y.tab.c"
    break;

  case 42: /* $@13: %empty  */
#line 164 "parser.y"
                   { add('K'); }
#line 1805 "y.tab.c"
    break;

  case 43: /* else_main: TK_ELSE $@13 '{' body_main '}'  */
#line 164 "parser.y"
                                                   {
    (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).name);
}
#line 1813 "y.tab.c"
    break;

  case 44: /* else_main: %empty  */
#line 167 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL;
}
#line 1821 "y.tab.c"
    break;

  case 45: /* body: body_statement body  */
#line 172 "parser.y"
                          { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, ""); 
}
#line 1829 "y.tab.c"
    break;

  case 46: /* body: %empty  */
#line 175 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1837 "y.tab.c"
    break;

  case 47: /* $@14: %empty  */
#line 180 "parser.y"
                       { add('K'); is_for = 1; }
#line 1843 "y.tab.c"
    break;

  case 48: /* body_statement: TK_FOR $@14 '(' condition ')' '{' body '}'  */
#line 180 "parser.y"
                                                                                {
    (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj3).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-7].nd_obj).name);
}
#line 1851 "y.tab.c"
    break;

  case 49: /* $@15: %empty  */
#line 183 "parser.y"
        { add('K'); is_for = 0; }
#line 1857 "y.tab.c"
    break;

  case 50: /* body_statement: TK_IF $@15 '(' condition ')' '{' body '}' else  */
#line 183 "parser.y"
                                                                      {
    struct node *iff = mknode((yyvsp[-5].nd_obj3).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-8].nd_obj).name);
    (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else");
}
#line 1866 "y.tab.c"
    break;

  case 51: /* body_statement: statement ';'  */
#line 187 "parser.y"
                {
    (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
}
#line 1874 "y.tab.c"
    break;

  case 52: /* $@16: %empty  */
#line 190 "parser.y"
            { add('K'); }
#line 1880 "y.tab.c"
    break;

  case 53: /* body_statement: TK_PRINTF $@16 '(' TK_STRING ')' ';'  */
#line 190 "parser.y"
                                                {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
}
#line 1888 "y.tab.c"
    break;

  case 54: /* $@17: %empty  */
#line 193 "parser.y"
           { add('K'); }
#line 1894 "y.tab.c"
    break;

  case 55: /* body_statement: TK_SCANF $@17 '(' TK_STRING ',' '&' TK_ID ')' ';'  */
#line 193 "parser.y"
                                                             {
    (yyval.nd_obj).nd = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-8].nd_obj).name);
}
#line 1902 "y.tab.c"
    break;

  case 56: /* $@18: %empty  */
#line 198 "parser.y"
              { add('K'); }
#line 1908 "y.tab.c"
    break;

  case 57: /* else: TK_ELSE $@18 '{' body '}'  */
#line 198 "parser.y"
                                         {
    (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).name);
}
#line 1916 "y.tab.c"
    break;

  case 58: /* else: %empty  */
#line 201 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL;
}
#line 1924 "y.tab.c"
    break;

  case 59: /* init_vector: '=' '{' init_vector_value '}'  */
#line 206 "parser.y"
                                           {
    check_vector_init(head_params_l); 
    count_param_vector = 0;
    free_l_param(&head_params_l);
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "init_vector");
}
#line 1935 "y.tab.c"
    break;

  case 60: /* init_vector: %empty  */
#line 212 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1943 "y.tab.c"
    break;

  case 61: /* init_vector_value: init_vector_value_aux init_vector_value  */
#line 217 "parser.y"
                                                           {
    count_param_vector++;
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "");
}
#line 1952 "y.tab.c"
    break;

  case 62: /* init_vector_value: ',' init_vector_value_aux init_vector_value  */
#line 221 "parser.y"
                                              {
    count_param_vector++;
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "");
}
#line 1961 "y.tab.c"
    break;

  case 63: /* init_vector_value: %empty  */
#line 225 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
    vector_name_aux = NULL;
}
#line 1970 "y.tab.c"
    break;

  case 64: /* init_vector_value_aux: value  */
#line 231 "parser.y"
                             {
    insert_at_end_l_param(&head_params_l, (yyvsp[0].nd_obj2).type);
}
#line 1978 "y.tab.c"
    break;

  case 65: /* $@19: %empty  */
#line 236 "parser.y"
                               { check_class_declaration((yyvsp[0].nd_obj).name); insert_type(); }
#line 1984 "y.tab.c"
    break;

  case 66: /* statement_class: TK_CLASS_NAME $@19 TK_ID  */
#line 236 "parser.y"
                                                                                          { add('O'); }
#line 1990 "y.tab.c"
    break;

  case 67: /* condition: value relop value  */
#line 239 "parser.y"
                             {
    (yyval.nd_obj3).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	if (is_for) {
		sprintf((yyval.nd_obj3).if_body, "L%d", label++);
		sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
		sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name, label);
		sprintf((yyval.nd_obj3).else_body, "L%d", label++);
	} else {
		sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name, label, label+1);
		sprintf((yyval.nd_obj3).if_body, "L%d", label++);
		sprintf((yyval.nd_obj3).else_body, "L%d", label++);
	}
}
#line 2008 "y.tab.c"
    break;

  case 68: /* condition: TK_TRUE  */
#line 252 "parser.y"
          { add('K'); (yyval.nd_obj3).nd = NULL; }
#line 2014 "y.tab.c"
    break;

  case 69: /* condition: TK_FALSE  */
#line 253 "parser.y"
           { add('K'); (yyval.nd_obj3).nd = NULL; }
#line 2020 "y.tab.c"
    break;

  case 70: /* condition: %empty  */
#line 254 "parser.y"
  {
    (yyval.nd_obj3).nd = NULL;
}
#line 2028 "y.tab.c"
    break;

  case 71: /* $@20: %empty  */
#line 259 "parser.y"
                                    { add('A'); }
#line 2034 "y.tab.c"
    break;

  case 72: /* statement_atributes: datatype TK_ID $@20 init  */
#line 259 "parser.y"
                                                        {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).type);  
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "atribute");  
}
#line 2044 "y.tab.c"
    break;

  case 73: /* $@21: %empty  */
#line 266 "parser.y"
                          { check_declaration_previously((yyvsp[0].nd_obj).name); add('V'); }
#line 2050 "y.tab.c"
    break;

  case 74: /* statement: datatype TK_ID $@21 init  */
#line 266 "parser.y"
                                                                                    {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).type);  
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "declaration");  
    sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-2].nd_obj).name, (yyvsp[0].nd_obj2).name);
}
#line 2061 "y.tab.c"
    break;

  case 75: /* $@22: %empty  */
#line 272 "parser.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 2067 "y.tab.c"
    break;

  case 76: /* statement: TK_ID $@22 '=' expression  */
#line 272 "parser.y"
                                                        {
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name); 
    char *id_type = get_type((yyvsp[-3].nd_obj).name); 
    if (id_type != NULL) {
        check_types(id_type, (yyvsp[0].nd_obj2).type);  
    }
    sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).name);
}
#line 2080 "y.tab.c"
    break;

  case 77: /* $@23: %empty  */
#line 280 "parser.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 2086 "y.tab.c"
    break;

  case 78: /* statement: TK_ID $@23 relop expression  */
#line 280 "parser.y"
                                                         {
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
}
#line 2095 "y.tab.c"
    break;

  case 79: /* $@24: %empty  */
#line 284 "parser.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 2101 "y.tab.c"
    break;

  case 80: /* statement: TK_ID $@24 TK_UNARY  */
#line 284 "parser.y"
                                                 {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
    if (!strcmp((yyvsp[0].nd_obj).name, "++")) {
        sprintf(icg[ic_idx++], "%s = %s + 1\n", (yyvsp[-2].nd_obj).name, (yyvsp[-2].nd_obj).name);
    } else if (!strcmp((yyvsp[0].nd_obj).name, "--")) {
        sprintf(icg[ic_idx++], "%s = %s - 1\n", (yyvsp[-2].nd_obj).name, (yyvsp[-2].nd_obj).name);
    }
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "iterator");
}
#line 2116 "y.tab.c"
    break;

  case 82: /* $@25: %empty  */
#line 295 "parser.y"
                 { vector_name_aux=strdup((yyvsp[0].nd_obj).name); check_declaration_previously((yyvsp[0].nd_obj).name); add('J'); }
#line 2122 "y.tab.c"
    break;

  case 83: /* $@26: %empty  */
#line 295 "parser.y"
                                                                                                                         { symbol_table[count-1].num_param = atoi((yyvsp[-1].nd_obj).name); }
#line 2128 "y.tab.c"
    break;

  case 84: /* statement: datatype TK_ID $@25 '[' TK_NUMBER ']' $@26 init_vector  */
#line 295 "parser.y"
                                                                                                                                                                                          {
    (yyvsp[-6].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[0].nd_obj).nd, "declaration_vector");  
}
#line 2137 "y.tab.c"
    break;

  case 85: /* $@27: %empty  */
#line 299 "parser.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 2143 "y.tab.c"
    break;

  case 86: /* statement: TK_ID $@27 '[' TK_NUMBER ']' '=' expression  */
#line 299 "parser.y"
                                                                         {
    check_vector_atribt((yyvsp[-6].nd_obj).name, (yyvsp[0].nd_obj2).type, atoi((yyvsp[-3].nd_obj).name));
    (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "=");  
}
#line 2152 "y.tab.c"
    break;

  case 87: /* $@28: %empty  */
#line 305 "parser.y"
                           { check_atribute((yyvsp[0].nd_obj).nd->left->token, (yyvsp[0].nd_obj).nd->right->token); }
#line 2158 "y.tab.c"
    break;

  case 88: /* class_call: class_call_aux $@28 init  */
#line 305 "parser.y"
                                                                                             {
    check_types_atributes((yyvsp[-2].nd_obj).nd->right->token, (yyvsp[0].nd_obj2).type);  
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, ".");
}
#line 2167 "y.tab.c"
    break;

  case 89: /* class_call: class_call_aux '(' params_const ')'  */
#line 309 "parser.y"
                                      { 
    check_method((yyvsp[-3].nd_obj).nd->left->token, (yyvsp[-3].nd_obj).nd->right->token, head_params_l); 
    free_l_param(&head_params_l);
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "call_method");
    count_param_vector = 0;
}
#line 2178 "y.tab.c"
    break;

  case 90: /* params_const: param_const params_const  */
#line 317 "parser.y"
                                       {
    count_param_vector++;
}
#line 2186 "y.tab.c"
    break;

  case 91: /* params_const: ',' param_const  */
#line 320 "parser.y"
                  {
    count_param_vector++;
}
#line 2194 "y.tab.c"
    break;

  case 92: /* params_const: %empty  */
#line 323 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 2202 "y.tab.c"
    break;

  case 93: /* param_const: value  */
#line 328 "parser.y"
                   {
    insert_at_end_l_param(&head_params_l, (yyvsp[0].nd_obj2).type);
}
#line 2210 "y.tab.c"
    break;

  case 94: /* $@29: %empty  */
#line 333 "parser.y"
                      { check_declaration((yyvsp[0].nd_obj).name); }
#line 2216 "y.tab.c"
    break;

  case 95: /* class_call_aux: TK_ID $@29 '.' TK_ID  */
#line 333 "parser.y"
                                                                {
    struct node *aux_left = mknode((yyvsp[-3].nd_obj).nd, NULL, (yyvsp[-3].nd_obj).name); 
    struct node *aux_right = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[0].nd_obj).name); 
    (yyval.nd_obj).nd = mknode(aux_left, aux_right, "call"); 
}
#line 2226 "y.tab.c"
    break;

  case 96: /* init: '=' expression  */
#line 340 "parser.y"
                     { 
    (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; 
    sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name);   
}
#line 2236 "y.tab.c"
    break;

  case 97: /* init: %empty  */
#line 345 "parser.y"
  { 
    sprintf((yyval.nd_obj2).type, "NULL"); 
    (yyval.nd_obj2).nd = mknode(NULL, NULL, ""); 
    strcpy((yyval.nd_obj2).name, "NULL"); 
}
#line 2246 "y.tab.c"
    break;

  case 98: /* expression: expression TK_MULTIPLY expression  */
#line 352 "parser.y"
                                              { 
    error_local = 0;
    if (!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
        sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	}
	else {
		if (!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if (!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else {
            error_local = 1;
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
		}
	}
    if (!error_local) {
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
    }
}
#line 2277 "y.tab.c"
    break;

  case 99: /* expression: expression TK_DIVIDE expression  */
#line 378 "parser.y"
                                  {
    error_local = 0;
    if (atoi((yyvsp[-1].nd_obj).name) != 0) {
        if (!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
            (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
        }
        else {
            if (!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
                struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inteiro_para_decimal");
                sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
                (yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
            }
            else if (!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
                struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
                sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
                (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
            }
            else {
                error_local = 1;
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
            }
        } 
    } else {
        error_local = 1;
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Divisão por zero\n", countn[count_file_name], file_name_current[count_file_name]);
    }
    if (!error_local) {
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
    }
}
#line 2313 "y.tab.c"
    break;

  case 100: /* expression: expression TK_SUBTRACT expression  */
#line 409 "parser.y"
                                    {
    error_local = 0;
    if (!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
        sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	}
	else {
		if (!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if (!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else {
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
            error_local = 1;
		}
	}
    if (!error_local) {
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
    } 
}
#line 2344 "y.tab.c"
    break;

  case 101: /* expression: expression TK_ADD expression  */
#line 435 "parser.y"
                               {
    error_local = 0;
    if (!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
        sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	}
	else {
		if (!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if (!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else {
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
            error_local = 1;
		}
	} 
    if (!error_local) {
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
    }
}
#line 2375 "y.tab.c"
    break;

  case 102: /* expression: value  */
#line 461 "parser.y"
        { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name); 
    sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; 
}
#line 2385 "y.tab.c"
    break;

  case 103: /* expression: class_call_aux '(' params_const ')'  */
#line 466 "parser.y"
                                      { 
    check_method((yyvsp[-3].nd_obj).nd->left->token, (yyvsp[-3].nd_obj).nd->right->token, head_params_l); 
    free_l_param(&head_params_l);
    (yyval.nd_obj2).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "call_method");
    count_param_vector = 0;
    char *type_function;
    int i, find_bool = 0;
    for (i = count-1; i >= 0; i--)  {
        if (!strcmp(symbol_table[i].id_name, (yyvsp[-3].nd_obj).nd->right->token)) {
            find_bool = 1;
            break;
        }
    }
    if (find_bool) {
        sprintf((yyval.nd_obj2).type, "%s", symbol_table[i].data_type);
    } else {
        sprintf((yyval.nd_obj2).type, "%s", "NULL");
    }
}
#line 2409 "y.tab.c"
    break;

  case 110: /* value: TK_NUMBER  */
#line 495 "parser.y"
                 { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "inteiro");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2419 "y.tab.c"
    break;

  case 111: /* value: TK_NUMBER_FLOAT  */
#line 500 "parser.y"
                  { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "decimal");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2429 "y.tab.c"
    break;

  case 112: /* value: TK_CHARACTER  */
#line 505 "parser.y"
               { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "caracter");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2439 "y.tab.c"
    break;

  case 113: /* value: TK_ID  */
#line 510 "parser.y"
        {
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    char *id_type = get_type((yyvsp[0].nd_obj).name); 
    if (id_type == NULL) {
        sprintf((yyval.nd_obj2).type, "%s", "NULL"); 
    } else {
        sprintf((yyval.nd_obj2).type, "%s", id_type); 
    }
    check_declaration((yyvsp[0].nd_obj).name); 
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2455 "y.tab.c"
    break;

  case 114: /* value: TK_STRING  */
#line 521 "parser.y"
            {
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "palavra");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2465 "y.tab.c"
    break;

  case 115: /* $@30: %empty  */
#line 528 "parser.y"
                  { add('R'); }
#line 2471 "y.tab.c"
    break;

  case 116: /* return: TK_RETURN $@30 value ';'  */
#line 528 "parser.y"
                                          { 
    check_function_return((yyvsp[-1].nd_obj2).name); 
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return"); 
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj2).nd, "RETURN"); 
}
#line 2481 "y.tab.c"
    break;

  case 117: /* return: %empty  */
#line 533 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL; 
    function_return = NULL;
    check_function_return("NULL");
}
#line 2491 "y.tab.c"
    break;


#line 2495 "y.tab.c"

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

#line 540 "parser.y"


int main(int argc, char **argv)
{
    int i;
    count_file_name = 0;
    if (argc >= 3) {
        printf("Utilize: ./glf <arquivo_principal>.jsc");
        return 1;
    }
    strcpy(file_name_current[count_file_name], argv[1]);
    FILE *fp = fopen(argv[1], "r");
    countn[count_file_name] = 1;
    yyin = fp;
    if (yyin == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }


    yyparse();

    fclose(fp);

    print_symbol_table();

    for (i = 0; i < count; i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }

    struct tree_class_l *aux;

    printf("\n\n");
    printf("FASE 2: ANALISE SINTATICA\n\n");
    aux = head_class_l;
    if (aux != NULL) {
        while(aux != NULL) {
            if (aux->head != NULL) {
                printf("\nArquivo: %s\n", aux->file_name);
                printtree(aux->head);
            }
            aux = aux->next;
        }
    }
    if (head != NULL) {
        printtree(head);
    }
        
    printf("\n\n");
    printf("FASE 3: ANALISE SEMANTICA \n\n");
    if (sem_errors > 0) {
    printf("Análise semântica concluída com %d erros\n", sem_errors);
        for (i = 0; i < sem_errors; i++) {
            printf("%s", errors[i]);
        }
    } else {
        printf("Análise semântica concluída sem erros");
        printf("\n\n");
        printf("FASE 4: Geraçao de código \n\n");
        for (i = 0; i < ic_idx; i++) {
            printf("%s", icg[i]);
        }
    }
	printf("\n\n");

    return 0;
}

void print_symbol_table()
{
    printf("\n\nTABELA DE SIMBOLOS:\n\n");
    printf("%-25s |%-25s |%-15s |%-15s |%-7s | %s|  %s |%-20s\n", "IDENTIFICADOR", "TIPO DE DADO", "TIPO", "CLASSE", "LINHA", "C_S", "S", "ARQUIVO");
    char aux_line[10];
    for (int i = 0; i < count; i++)
    {
        sprintf(aux_line, "%5d", symbol_table[i].line_no);
        printf("%-25s |%-25s |%-15s |%-15s |%-7s |%3d |%3d |%-20s | %d\n", symbol_table[i].id_name, symbol_table[i].data_type,
               symbol_table[i].type, symbol_table[i].class_name, aux_line, symbol_table[i].class_scope, symbol_table[i].scope, symbol_table[i].file_name, symbol_table[i].num_param);
    }
}

struct node* mknode(struct node *left, struct node *right, const char *token) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    char *newstr = (char*) malloc(strlen(token)+1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}
    

void printtree(struct node* tree) {
	printf("\nÁrvore impresa inorder (Parse Tree): \n\n");
	printInorder(tree);
	printf("\n\n");
}

void printInorder(struct node *tree) {
	int i;
	if (tree->left) {
		printInorder(tree->left);
	}
    if (strlen(tree->token) > 0) {
    	printf("%s, ", tree->token);
    }
	if (tree->right) {
		printInorder(tree->right);
	}
}

void insert_type() {
    strcpy(type, yytext);
}

void check_function_return(const char *name) {
	char *function_datatype = get_type_function(symbol_table[count-1].data_type, symbol_table[count-1].class_scope);
    char *return_datatype = get_type(name);
    if (strcmp(return_datatype, function_datatype)) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo de retorno\n", countn[count_file_name], file_name_current[count_file_name]);
    }
}

void check_types(const char *type1, const char *type2){
	if (!strcmp(type1, type2) || !strcmp(type2, "NULL"))
		return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo na atribuição\n", countn[count_file_name], file_name_current[count_file_name]);
}

void check_types_atributes(const char *token, const char *type2){
    int i;
    char *type1;
	for (i = count-1; i >= 0; i--)  {
        if (!strcmp(symbol_table[i].id_name, token)) {
            type1=strdup(symbol_table[i].data_type);            
            break;
        }
    }
    if (type1 == NULL) {
        return;
    }
    if (!strcmp(type1, type2) || !strcmp(type2, "NULL"))
		return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo na atribuição\n", countn[count_file_name], file_name_current[count_file_name]);
}

void check_declaration(const char *c) {    
    q = search(c, class_scope_count, scope_count);
    if (!q) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: \"%s\" não foi declarada!\n", countn[count_file_name], file_name_current[count_file_name], c);  
    }
}

void check_class_declaration(const char *c) {
    int i, q = 0;
    for (i = count-1; i >= 0; i--)  {
        if (!strcmp(symbol_table[i].id_name, c)) {
            q = 1;
            break;
        }
    }
    if (!q) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: A classe \"%s\" não foi declarada!\n", countn[count_file_name], file_name_current[count_file_name], c);  
    }
}

void check_declaration_previously(const char *c) {    
    q = search(c, class_scope_count, scope_count);
    if (!q) return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: \"%s\" já foi declarada anteriormente!\n", countn[count_file_name], file_name_current[count_file_name], c);  
}

void check_atribute(const char *object, const char *atribute) {

    int i; 
    char *class_name_target;
    for (i = count-1; i >= 0; i--)  {
        if (strcmp(symbol_table[i].id_name, object) == 0) {   
            class_name_target = strdup(symbol_table[i].data_type);
            break;
        }
    }
    for (i = count-1; i >= 0; i--)  {
        if ((strcmp(symbol_table[i].class_name, class_name_target) == 0) && (strcmp(symbol_table[i].id_name, atribute) == 0)) {   
            return;
        }
    }
    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O atributo %s não existe na classe %s\n", countn[count_file_name], file_name_current[count_file_name], atribute, class_name_target);
}

void check_method(const char *object, const char *method, struct param_types *head) {
    int i, j; 
    char *class_name_target;
    for (i = count-1; i >= 0; i--)  {
        if (strcmp(symbol_table[i].id_name, object) == 0) {   
            class_name_target = strdup(symbol_table[i].data_type);
            break;
        }
    }
    if (strcmp(symbol_table[i].type, "Object")) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O %s não é um objeto\n", countn[count_file_name], file_name_current[count_file_name], object);
        return;
    }
    for (i = count-1; i >= 0; i--)  {
        if ((strcmp(symbol_table[i].class_name, class_name_target) == 0) && (strcmp(symbol_table[i].id_name, method) == 0)) {   
            if (symbol_table[i].num_param != count_param_vector) {
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s espera %d parametros e recebeu %d\n", countn[count_file_name], file_name_current[count_file_name], method, symbol_table[i].num_param, count_param_vector);
            }
            int count_paran_index = 1;
            struct param_types *temp = head;
            for (j = i+1; j <= i+count_param_vector; j++)  {
                if (temp != NULL) {
                    if ((strcmp(symbol_table[j].data_type, temp->type) != 0)) {
                        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O parametro de número %d, não é do tipo esperado\n", countn[count_file_name], file_name_current[count_file_name], count_paran_index);
                    }
                    temp = temp->next;
                    count_paran_index++;
                }
            }
            return;
        }
    }
    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s não existe na classe %s\n", countn[count_file_name], file_name_current[count_file_name], method, class_name_target);
}

void check_method_declaration_previously(const char *name) {
    int i; 
    for (i = count-1; i >= 0; i--)  {
        if (symbol_table[i].class_scope != class_scope_count) {
            break;
        }
        if (!strcmp(symbol_table[i].id_name, name) && symbol_table[i].class_scope == class_scope_count) {   
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s já foi declarado anteriormente\n", countn[count_file_name], file_name_current[count_file_name], name);
            break;
        }
    }
}

void check_vector_init(struct param_types *head) {
    if (symbol_table[count-1].num_param < count_param_vector) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O vetor %s, está recebendo mais valores do que o esperado\n", countn[count_file_name], file_name_current[count_file_name], symbol_table[count-1].id_name);
        return;
    }else if (symbol_table[count-1].num_param > count_param_vector) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O vetor %s, está recebendo menos valores do que o esperado\n", countn[count_file_name], file_name_current[count_file_name], symbol_table[count-1].id_name);
        return;
    }

    struct param_types *temp = head;

    while(temp != NULL) {
        if (strcmp(temp->type, symbol_table[count-1].data_type)) {
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O vetor está recebendo um tipo não esperado\n", countn[count_file_name], file_name_current[count_file_name]);
        }
        temp = temp->next;
    }
}

void check_vector_atribt(const char *vector_name, const char *type, int position) {
    int i;
    for (i = count-1; i >= 0; i--)  {
        if (!strcmp(symbol_table[i].id_name, vector_name)) {
            if (position >= symbol_table[i].num_param || position < 0) {
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Posição invalida na atribuição do vetor %s\n", countn[count_file_name], file_name_current[count_file_name], vector_name);
            }
            if (strcmp(symbol_table[i].data_type, type)) {
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Atibuição do vetor %s invalida, tipos diferentes\n", countn[count_file_name], file_name_current[count_file_name], vector_name);
            }
            break;
        }
    }
}

char *get_type(const char *var){
	for (int i = count-1; i >= 0; i--)  {
		if (!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}

char *get_type_function(const char *var, int scope){
	for (int i = 0; i < count; i++)  {
		if (!strcmp(symbol_table[i].id_name, var) && scope == symbol_table[i].class_scope) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}



void add(char c) {
    q = search(yytext, class_scope_count, scope_count);
    if (!q) {
        if (c == 'H') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);    
            symbol_table[count].data_type=strdup(yylval.nd_obj.name);     
            symbol_table[count].line_no=countn[count_file_name];    
            symbol_table[count].type=strdup("Header");
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  
        else if (c == 'K') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Keyword");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if (c == 'V') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Variable");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if (c == 'F') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            function_return=strdup(yylval.nd_obj.name);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Function");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'Z') {
            class_name_current = strdup(yylval.nd_obj.name);
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(yylval.nd_obj.name);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Class");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'O') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Object");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'A') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Attribute");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'X') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Vector");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'P') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Parameter");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'R') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(function_return);
            function_return = NULL;
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Return");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        } else if (c == 'J') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Vector");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++; 
        }
    }
}

int search(const char *type, int cl_scope, int f_scope) { 
    int i, aux_return = 0;
    for (i = count-1; i >= 0; i--)  {
        if (strcmp(symbol_table[i].id_name, type) == 0 && symbol_table[i].class_scope == cl_scope && strcmp(symbol_table[i].type, "Attribute") == 0) {
            aux_return = 1;
            break;
        }
    }
    if (!aux_return) {
        for (i = count-1; i >= 0; i--)  {
            if (strcmp(symbol_table[i].id_name, type) == 0 && symbol_table[i].scope == f_scope) {
                aux_return = 2;
                break;
            }
        } 
    }
    return aux_return;
}

void insert_at_end_l_param(struct param_types **head, char *type) {
    struct param_types *newNode = (struct param_types *)malloc(sizeof(struct param_types));
    if (newNode == NULL) {
        printf("Erro ao alocar memória do, função %s\n", "insert_at_end_l_param");
        exit(1);
    }

    newNode->type=strdup(type);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct param_types *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void free_l_param(struct param_types **head) {
    struct param_types *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp->type);
        free(temp);
    }
}

void yyerror(const char* msg) {
    fprintf(stderr, "Erro sintático na linha %d, arquivo %s: %s   %s\n", countn[count_file_name], file_name_current[count_file_name], msg, yytext);
}
