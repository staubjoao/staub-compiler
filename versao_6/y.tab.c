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


#line 225 "y.tab.c"

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
  YYSYMBOL_body = 67,                      /* body  */
  YYSYMBOL_body_statement = 68,            /* body_statement  */
  YYSYMBOL_69_7 = 69,                      /* $@7  */
  YYSYMBOL_70_8 = 70,                      /* $@8  */
  YYSYMBOL_71_9 = 71,                      /* $@9  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_else = 73,                      /* else  */
  YYSYMBOL_74_11 = 74,                     /* $@11  */
  YYSYMBOL_init_vector = 75,               /* init_vector  */
  YYSYMBOL_init_vector_value = 76,         /* init_vector_value  */
  YYSYMBOL_init_vector_value_aux = 77,     /* init_vector_value_aux  */
  YYSYMBOL_statement_class = 78,           /* statement_class  */
  YYSYMBOL_79_12 = 79,                     /* $@12  */
  YYSYMBOL_condition = 80,                 /* condition  */
  YYSYMBOL_statement_atributes = 81,       /* statement_atributes  */
  YYSYMBOL_82_13 = 82,                     /* $@13  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_84_14 = 84,                     /* $@14  */
  YYSYMBOL_85_15 = 85,                     /* $@15  */
  YYSYMBOL_86_16 = 86,                     /* $@16  */
  YYSYMBOL_87_17 = 87,                     /* $@17  */
  YYSYMBOL_88_18 = 88,                     /* $@18  */
  YYSYMBOL_89_19 = 89,                     /* $@19  */
  YYSYMBOL_90_20 = 90,                     /* $@20  */
  YYSYMBOL_class_call = 91,                /* class_call  */
  YYSYMBOL_92_21 = 92,                     /* $@21  */
  YYSYMBOL_params_const = 93,              /* params_const  */
  YYSYMBOL_param_const = 94,               /* param_const  */
  YYSYMBOL_class_call_aux = 95,            /* class_call_aux  */
  YYSYMBOL_96_22 = 96,                     /* $@22  */
  YYSYMBOL_init = 97,                      /* init  */
  YYSYMBOL_expression = 98,                /* expression  */
  YYSYMBOL_relop = 99,                     /* relop  */
  YYSYMBOL_value = 100,                    /* value  */
  YYSYMBOL_return = 101,                   /* return  */
  YYSYMBOL_102_23 = 102                    /* $@23  */
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
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       0,    34,    34,    34,    39,    50,    55,    55,    61,    64,
      64,    71,    76,    76,    79,    85,    85,    92,    96,   100,
     105,   105,   111,   116,   117,   118,   119,   120,   123,   126,
     131,   131,   134,   134,   138,   141,   144,   144,   147,   147,
     152,   152,   155,   160,   166,   171,   175,   179,   185,   190,
     190,   193,   196,   197,   198,   203,   203,   210,   210,   215,
     215,   222,   222,   226,   226,   231,   232,   232,   232,   236,
     236,   242,   242,   246,   254,   257,   260,   265,   270,   270,
     277,   282,   289,   310,   335,   356,   377,   382,   403,   404,
     405,   406,   407,   408,   411,   416,   421,   426,   437,   444,
     444,   449
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
  "class_atributes", "datatype", "body", "body_statement", "$@7", "$@8",
  "$@9", "$@10", "else", "$@11", "init_vector", "init_vector_value",
  "init_vector_value_aux", "statement_class", "$@12", "condition",
  "statement_atributes", "$@13", "statement", "$@14", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "class_call", "$@21", "params_const",
  "param_const", "class_call_aux", "$@22", "init", "expression", "relop",
  "value", "return", "$@23", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,    -8,  -130,    13,     0,  -130,    -9,    -5,  -130,  -130,
      79,    20,  -130,  -130,  -130,  -130,  -130,  -130,    10,    15,
      79,    36,    17,  -130,    24,    28,    12,  -130,    25,  -130,
      31,  -130,  -130,    79,    23,    12,    57,  -130,    37,    43,
      12,  -130,  -130,  -130,    85,  -130,    53,  -130,    54,  -130,
    -130,  -130,    50,  -130,  -130,    70,   108,  -130,    68,    68,
      63,    19,    85,    85,    85,    85,  -130,  -130,  -130,  -130,
     -20,  -130,    91,    74,    68,    72,    73,  -130,    86,   109,
     104,  -130,   101,    90,    19,  -130,     5,     5,  -130,  -130,
      87,   106,   107,   110,   103,   112,   126,   105,   131,   111,
    -130,  -130,  -130,  -130,    19,    37,  -130,   114,  -130,  -130,
    -130,  -130,   122,   123,    76,    76,    85,  -130,  -130,  -130,
    -130,  -130,  -130,    85,  -130,   137,  -130,    37,   113,   117,
    -130,   101,    79,   119,   120,  -130,  -130,   124,   112,   125,
     108,   108,   116,  -130,   142,  -130,   121,  -130,   127,   128,
     129,   101,   130,   132,   133,  -130,  -130,   148,    68,  -130,
      68,    85,  -130,   134,   135,   139,   108,   136,   140,  -130,
     158,   138,  -130,  -130,  -130,  -130,    26,   141,   101,   143,
      26,  -130,    68,    26,  -130,  -130,   145,  -130,  -130
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     2,     0,     0,     4,     0,     0,     1,     6,
      11,    14,     7,    27,    23,    24,    25,    26,     0,     0,
      11,     0,     0,    12,     0,     0,    19,     8,    55,    22,
       0,     3,     5,     0,     0,    19,     0,    16,    81,     0,
      19,     9,    17,    20,     0,    56,     0,    18,     0,    21,
      94,    95,    97,    98,    96,     0,    80,    86,    29,    29,
       0,    76,     0,     0,     0,     0,    36,    38,    30,    32,
      61,    49,     0,     0,    29,     0,     0,    65,    71,   101,
       0,    97,     0,     0,    76,    77,    82,    83,    85,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      13,    28,    34,    35,    76,    81,    99,     0,    79,    75,
      87,    74,     0,     0,    54,    54,     0,    90,    91,    92,
      93,    89,    88,     0,    64,     0,    50,    81,     0,     0,
      72,     0,    11,     0,     0,    52,    53,     0,     0,     0,
      60,    62,     0,    58,     0,    73,     0,    10,     0,     0,
       0,     0,     0,     0,     0,   100,    37,     0,    29,    51,
      29,     0,    67,     0,     0,     0,    70,    44,     0,    31,
      42,     0,    68,    39,    40,    33,    47,     0,     0,     0,
      47,    48,    29,    47,    43,    45,     0,    46,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,   149,  -130,  -130,  -130,  -130,   -17,  -130,  -130,  -130,
    -130,  -130,     9,   153,  -130,  -130,    -2,   -57,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -129,    11,  -130,  -130,
      75,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,   -79,   115,   -58,  -130,   -99,   -53,    49,
     -47,  -130,  -130
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     7,     5,     6,    12,    18,    48,    24,    30,
      19,    37,    34,    35,    49,    20,    72,    73,    74,    92,
      93,    90,    91,   175,   177,   172,   179,   180,    75,    98,
     137,    22,    38,    76,   127,    94,    95,    96,   128,   167,
      97,    77,   105,    83,    84,    55,    60,    45,    56,   123,
      57,   107,   131
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    78,    79,    27,   -63,   111,   130,     4,    21,    86,
      87,    88,    89,     8,    85,    13,    78,   101,    21,    14,
      15,    16,    17,     9,    36,   129,   -59,   -69,   143,   -78,
      10,    36,     1,    36,    11,    85,    23,    85,    36,    50,
      51,    81,    64,    65,    42,     2,    50,    51,    81,    47,
      25,   185,    53,    54,   187,    33,    26,    85,    28,    53,
      54,    29,    82,   140,    31,    41,   -15,   138,   138,   178,
     141,    13,    39,    66,    67,    14,    15,    16,    17,    43,
      68,    69,    13,    44,   146,    46,    14,    15,    16,    17,
      70,    71,    58,    59,   135,   136,    50,    51,    81,   -78,
      78,   164,    78,   165,   159,    50,    51,    52,   166,    53,
      54,    61,    80,    99,   100,   147,   102,   103,    53,    54,
     106,    50,    51,    81,    78,   186,   108,   104,   112,   181,
      21,   181,   110,   181,    53,    54,   181,   117,   118,   119,
     120,   121,   122,    62,    63,    64,    65,   113,   114,   116,
     124,   115,   125,   126,   132,   133,   134,   142,   -66,   145,
     144,   148,   154,   149,   153,   155,   150,   152,   158,   160,
     163,   156,   174,   157,    32,   169,   168,   176,   161,   170,
     182,   162,   171,   184,   173,   188,    40,   151,     0,   183,
     139,     0,     0,     0,     0,     0,     0,   109
};

static const yytype_int16 yycheck[] =
{
      58,    59,    59,    20,    24,    84,   105,    15,    10,    62,
      63,    64,    65,     0,    61,     3,    74,    74,    20,     7,
       8,     9,    10,    23,    26,   104,    46,    47,   127,    49,
      39,    33,     4,    35,    39,    82,    16,    84,    40,    20,
      21,    22,    37,    38,    35,    17,    20,    21,    22,    40,
      40,   180,    33,    34,   183,    43,    41,   104,    22,    33,
      34,    44,    43,   116,    40,    42,    41,   114,   115,    43,
     123,     3,    41,     5,     6,     7,     8,     9,    10,    22,
      12,    13,     3,    46,   131,    42,     7,     8,     9,    10,
      22,    23,    39,    39,    18,    19,    20,    21,    22,    49,
     158,   158,   160,   160,   151,    20,    21,    22,   161,    33,
      34,    41,    49,    22,    40,   132,    44,    44,    33,    34,
      11,    20,    21,    22,   182,   182,    22,    41,    41,   176,
     132,   178,    42,   180,    33,    34,   183,    25,    26,    27,
      28,    29,    30,    35,    36,    37,    38,    41,    41,    46,
      24,    41,    47,    22,    40,    33,    33,    20,    47,    42,
      47,    42,    20,    43,    48,    44,    42,    42,    39,    39,
      22,    44,    14,    45,    25,    40,    42,    39,    46,    40,
      39,    48,    46,    40,    44,    40,    33,   138,    -1,   178,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    17,    51,    15,    53,    54,    52,     0,    23,
      39,    39,    55,     3,     7,     8,     9,    10,    56,    60,
      65,    66,    81,    16,    58,    40,    41,    56,    22,    44,
      59,    40,    51,    43,    62,    63,    66,    61,    82,    41,
      63,    42,    62,    22,    46,    97,    42,    62,    57,    64,
      20,    21,    22,    33,    34,    95,    98,   100,    39,    39,
      96,    41,    35,    36,    37,    38,     5,     6,    12,    13,
      22,    23,    66,    67,    68,    78,    83,    91,    95,    67,
      49,    22,    43,    93,    94,   100,    98,    98,    98,    98,
      71,    72,    69,    70,    85,    86,    87,    90,    79,    22,
      40,    67,    44,    44,    41,    92,    11,   101,    22,    94,
      42,    93,    41,    41,    41,    41,    46,    25,    26,    27,
      28,    29,    30,    99,    24,    47,    22,    84,    88,    93,
      97,   102,    40,    33,    33,    18,    19,    80,   100,    80,
      98,    98,    20,    97,    47,    42,   100,    56,    42,    43,
      42,    99,    42,    48,    20,    44,    44,    45,    39,   100,
      39,    46,    48,    22,    67,    67,    98,    89,    42,    40,
      40,    46,    75,    44,    14,    73,    39,    74,    43,    76,
      77,   100,    39,    77,    40,    76,    67,    76,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    51,    51,    53,    55,    54,    56,    57,
      56,    56,    59,    58,    58,    61,    60,    62,    62,    62,
      64,    63,    65,    66,    66,    66,    66,    66,    67,    67,
      69,    68,    70,    68,    68,    68,    71,    68,    72,    68,
      74,    73,    73,    75,    75,    76,    76,    76,    77,    79,
      78,    80,    80,    80,    80,    82,    81,    84,    83,    85,
      83,    86,    83,    87,    83,    83,    88,    89,    83,    90,
      83,    92,    91,    91,    93,    93,    93,    94,    96,    95,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,    99,    99,   100,   100,   100,   100,   100,   102,
     101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     2,     5,     0,     3,     2,     0,
      10,     0,     0,     7,     0,     0,     3,     2,     3,     0,
       0,     3,     2,     1,     1,     1,     1,     1,     2,     0,
       0,     8,     0,     9,     2,     2,     0,     6,     0,     9,
       0,     5,     0,     4,     0,     2,     3,     0,     1,     0,
       3,     3,     1,     1,     0,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     3,     1,     0,     0,     8,     0,
       7,     0,     3,     4,     2,     2,     0,     1,     0,     4,
       2,     0,     3,     3,     3,     3,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0
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
#line 34 "parser.y"
                                  { class_scope_count++; add('Z'); }
#line 1445 "y.tab.c"
    break;

  case 3: /* program: TK_CLASS_DEFINITION_MAIN $@1 '{' class_body_main '}'  */
#line 34 "parser.y"
                                                                                              { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).nd, "program"); 
    princial_bool = 1;
    head = (yyval.nd_obj).nd; 
}
#line 1455 "y.tab.c"
    break;

  case 4: /* program: TK_INCLUDE class  */
#line 39 "parser.y"
                   {
    class_aux = (yyvsp[-1].nd_obj).nd;
    if (head_class_l_aux == NULL) {
        head_class_l_aux = head_class_l;
    } else {
        head_class_l_aux = head_class_l_aux->next;
    } 
    head_class_l_aux->head = class_aux;
}
#line 1469 "y.tab.c"
    break;

  case 5: /* class: class_defination '{' class_body '}' program  */
#line 50 "parser.y"
                                                   {
    (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "class");
}
#line 1477 "y.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 55 "parser.y"
                                                    { class_scope_count++; add('Z'); }
#line 1483 "y.tab.c"
    break;

  case 7: /* class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME $@2  */
#line 55 "parser.y"
                                                                                       { 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "class"); 
    class_name_current = strdup((yyvsp[-1].nd_obj).name);
}
#line 1492 "y.tab.c"
    break;

  case 8: /* class_body: class_atributes class_body  */
#line 61 "parser.y"
                                       { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "class_body"); 
}
#line 1500 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 64 "parser.y"
                                            {
    symbol_table[method_current].num_param = count_param_vector;
    count_param_vector = 0;
}
#line 1509 "y.tab.c"
    break;

  case 10: /* class_body: method_signature '(' atributs_method ')' $@3 '{' body return '}' class_body  */
#line 67 "parser.y"
                                 {
    struct node *aux_class = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj).nd, "class_body");
    (yyval.nd_obj).nd = mknode(aux_class, (yyvsp[-2].nd_obj).nd, "method");
}
#line 1518 "y.tab.c"
    break;

  case 11: /* class_body: %empty  */
#line 71 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL; 
}
#line 1526 "y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 76 "parser.y"
                                         { scope_count++; }
#line 1532 "y.tab.c"
    break;

  case 13: /* class_body_main: TK_FUNC_DEFINITION_MAIN $@4 '(' ')' '{' body '}'  */
#line 76 "parser.y"
                                                                                 {
    (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, "main");
}
#line 1540 "y.tab.c"
    break;

  case 14: /* class_body_main: %empty  */
#line 79 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL; 
}
#line 1548 "y.tab.c"
    break;

  case 15: /* $@5: %empty  */
#line 85 "parser.y"
                                 { scope_count++; add('F'); }
#line 1554 "y.tab.c"
    break;

  case 16: /* method_signature: datatype TK_ID $@5  */
#line 85 "parser.y"
                                                              {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
    method_current = count-1;
}
#line 1563 "y.tab.c"
    break;

  case 17: /* atributs_method: parament_method atributs_method  */
#line 92 "parser.y"
                                                 {
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "parameter");
    count_param_vector++;
}
#line 1572 "y.tab.c"
    break;

  case 18: /* atributs_method: ',' parament_method atributs_method  */
#line 96 "parser.y"
                                     {
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "parameter");
    count_param_vector++;
}
#line 1581 "y.tab.c"
    break;

  case 19: /* atributs_method: %empty  */
#line 100 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1589 "y.tab.c"
    break;

  case 20: /* $@6: %empty  */
#line 105 "parser.y"
                                { add('P'); }
#line 1595 "y.tab.c"
    break;

  case 21: /* parament_method: datatype TK_ID $@6  */
#line 105 "parser.y"
                                              {
    (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "parameter");  
}
#line 1604 "y.tab.c"
    break;

  case 22: /* class_atributes: statement_atributes ';'  */
#line 111 "parser.y"
                                         {
    (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
}
#line 1612 "y.tab.c"
    break;

  case 23: /* datatype: TK_TYPE_INT  */
#line 116 "parser.y"
                      { insert_type(); }
#line 1618 "y.tab.c"
    break;

  case 24: /* datatype: TK_TYPE_FLOAT  */
#line 117 "parser.y"
                { insert_type(); }
#line 1624 "y.tab.c"
    break;

  case 25: /* datatype: TK_TYPE_CHAR  */
#line 118 "parser.y"
               { insert_type(); }
#line 1630 "y.tab.c"
    break;

  case 26: /* datatype: TK_TYPE_STRING  */
#line 119 "parser.y"
                 { insert_type(); }
#line 1636 "y.tab.c"
    break;

  case 27: /* datatype: TK_VOID  */
#line 120 "parser.y"
          { insert_type(); }
#line 1642 "y.tab.c"
    break;

  case 28: /* body: body_statement body  */
#line 123 "parser.y"
                          { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement_body"); 
}
#line 1650 "y.tab.c"
    break;

  case 29: /* body: %empty  */
#line 126 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1658 "y.tab.c"
    break;

  case 30: /* $@7: %empty  */
#line 131 "parser.y"
                       { add('K'); }
#line 1664 "y.tab.c"
    break;

  case 31: /* body_statement: TK_FOR $@7 '(' condition ')' '{' body '}'  */
#line 131 "parser.y"
                                                                    {
    (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-7].nd_obj).name);
}
#line 1672 "y.tab.c"
    break;

  case 32: /* $@8: %empty  */
#line 134 "parser.y"
        { add('K'); }
#line 1678 "y.tab.c"
    break;

  case 33: /* body_statement: TK_IF $@8 '(' condition ')' '{' body '}' else  */
#line 134 "parser.y"
                                                          {
    struct node *iff = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-8].nd_obj).name);
    (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else");
}
#line 1687 "y.tab.c"
    break;

  case 34: /* body_statement: statement_class ';'  */
#line 138 "parser.y"
                      {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
}
#line 1695 "y.tab.c"
    break;

  case 35: /* body_statement: statement ';'  */
#line 141 "parser.y"
                {
    (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
}
#line 1703 "y.tab.c"
    break;

  case 36: /* $@9: %empty  */
#line 144 "parser.y"
            { add('K'); }
#line 1709 "y.tab.c"
    break;

  case 37: /* body_statement: TK_PRINTF $@9 '(' TK_STRING ')' ';'  */
#line 144 "parser.y"
                                                {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
}
#line 1717 "y.tab.c"
    break;

  case 38: /* $@10: %empty  */
#line 147 "parser.y"
           { add('K'); }
#line 1723 "y.tab.c"
    break;

  case 39: /* body_statement: TK_SCANF $@10 '(' TK_STRING ',' '&' TK_ID ')' ';'  */
#line 147 "parser.y"
                                                             {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj).name);
}
#line 1731 "y.tab.c"
    break;

  case 40: /* $@11: %empty  */
#line 152 "parser.y"
              { add('K'); }
#line 1737 "y.tab.c"
    break;

  case 41: /* else: TK_ELSE $@11 '{' body '}'  */
#line 152 "parser.y"
                                         {
    (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).name);
}
#line 1745 "y.tab.c"
    break;

  case 42: /* else: %empty  */
#line 155 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL;
}
#line 1753 "y.tab.c"
    break;

  case 43: /* init_vector: '=' '{' init_vector_value '}'  */
#line 160 "parser.y"
                                           {
    check_vector_init(head_params_l); 
    count_param_vector = 0;
    free_l_param(&head_params_l);
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "init_vector");
}
#line 1764 "y.tab.c"
    break;

  case 44: /* init_vector: %empty  */
#line 166 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1772 "y.tab.c"
    break;

  case 45: /* init_vector_value: init_vector_value_aux init_vector_value  */
#line 171 "parser.y"
                                                           {
    count_param_vector++;
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "");
}
#line 1781 "y.tab.c"
    break;

  case 46: /* init_vector_value: ',' init_vector_value_aux init_vector_value  */
#line 175 "parser.y"
                                              {
    count_param_vector++;
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "");
}
#line 1790 "y.tab.c"
    break;

  case 47: /* init_vector_value: %empty  */
#line 179 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
    vector_name_aux = NULL;
}
#line 1799 "y.tab.c"
    break;

  case 48: /* init_vector_value_aux: value  */
#line 185 "parser.y"
                             {
    insert_at_end_l_param(&head_params_l, (yyvsp[0].nd_obj2).type);
}
#line 1807 "y.tab.c"
    break;

  case 49: /* $@12: %empty  */
#line 190 "parser.y"
                               { check_class_declaration((yyvsp[0].nd_obj).name); insert_type(); }
#line 1813 "y.tab.c"
    break;

  case 50: /* statement_class: TK_CLASS_NAME $@12 TK_ID  */
#line 190 "parser.y"
                                                                                          { add('O'); }
#line 1819 "y.tab.c"
    break;

  case 51: /* condition: value relop value  */
#line 193 "parser.y"
                             {
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
}
#line 1827 "y.tab.c"
    break;

  case 52: /* condition: TK_TRUE  */
#line 196 "parser.y"
          { add('K'); (yyval.nd_obj).nd = NULL; }
#line 1833 "y.tab.c"
    break;

  case 53: /* condition: TK_FALSE  */
#line 197 "parser.y"
           { add('K'); (yyval.nd_obj).nd = NULL; }
#line 1839 "y.tab.c"
    break;

  case 54: /* condition: %empty  */
#line 198 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1847 "y.tab.c"
    break;

  case 55: /* $@13: %empty  */
#line 203 "parser.y"
                                    { add('A'); }
#line 1853 "y.tab.c"
    break;

  case 56: /* statement_atributes: datatype TK_ID $@13 init  */
#line 203 "parser.y"
                                                        {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).type);  
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "atribute");  
}
#line 1863 "y.tab.c"
    break;

  case 57: /* $@14: %empty  */
#line 210 "parser.y"
                          { check_declaration_previously((yyvsp[0].nd_obj).name); add('V'); }
#line 1869 "y.tab.c"
    break;

  case 58: /* statement: datatype TK_ID $@14 init  */
#line 210 "parser.y"
                                                                                    {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).type);  
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "declaration");  
}
#line 1879 "y.tab.c"
    break;

  case 59: /* $@15: %empty  */
#line 215 "parser.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 1885 "y.tab.c"
    break;

  case 60: /* statement: TK_ID $@15 '=' expression  */
#line 215 "parser.y"
                                                        {
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name); 
    char *id_type = get_type((yyvsp[-3].nd_obj).name); 
    if (id_type != NULL) {
        check_types(id_type, (yyvsp[0].nd_obj2).type);  
    }
}
#line 1897 "y.tab.c"
    break;

  case 61: /* $@16: %empty  */
#line 222 "parser.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 1903 "y.tab.c"
    break;

  case 62: /* statement: TK_ID $@16 relop expression  */
#line 222 "parser.y"
                                                         {
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
}
#line 1912 "y.tab.c"
    break;

  case 63: /* $@17: %empty  */
#line 226 "parser.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 1918 "y.tab.c"
    break;

  case 64: /* statement: TK_ID $@17 TK_UNARY  */
#line 226 "parser.y"
                                                 {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "iterator");
}
#line 1928 "y.tab.c"
    break;

  case 66: /* $@18: %empty  */
#line 232 "parser.y"
                 { vector_name_aux=strdup((yyvsp[0].nd_obj).name); check_declaration_previously((yyvsp[0].nd_obj).name); add('J'); }
#line 1934 "y.tab.c"
    break;

  case 67: /* $@19: %empty  */
#line 232 "parser.y"
                                                                                                                         { symbol_table[count-1].num_param = atoi((yyvsp[-1].nd_obj).name); }
#line 1940 "y.tab.c"
    break;

  case 68: /* statement: datatype TK_ID $@18 '[' TK_NUMBER ']' $@19 init_vector  */
#line 232 "parser.y"
                                                                                                                                                                                          {
    (yyvsp[-6].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[0].nd_obj).nd, "declaration_vector");  
}
#line 1949 "y.tab.c"
    break;

  case 69: /* $@20: %empty  */
#line 236 "parser.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 1955 "y.tab.c"
    break;

  case 70: /* statement: TK_ID $@20 '[' TK_NUMBER ']' '=' expression  */
#line 236 "parser.y"
                                                                         {
    check_vector_atribt((yyvsp[-6].nd_obj).name, (yyvsp[0].nd_obj2).type, atoi((yyvsp[-3].nd_obj).name));
    (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "=");  
}
#line 1964 "y.tab.c"
    break;

  case 71: /* $@21: %empty  */
#line 242 "parser.y"
                           { check_atribute((yyvsp[0].nd_obj).nd->left->token, (yyvsp[0].nd_obj).nd->right->token); }
#line 1970 "y.tab.c"
    break;

  case 72: /* class_call: class_call_aux $@21 init  */
#line 242 "parser.y"
                                                                                             {
    check_types_atributes((yyvsp[-2].nd_obj).nd->right->token, (yyvsp[0].nd_obj2).type);  
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, ".");
}
#line 1979 "y.tab.c"
    break;

  case 73: /* class_call: class_call_aux '(' params_const ')'  */
#line 246 "parser.y"
                                      { 
    check_method((yyvsp[-3].nd_obj).nd->left->token, (yyvsp[-3].nd_obj).nd->right->token, head_params_l); 
    free_l_param(&head_params_l);
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "call_method");
    count_param_vector = 0;
}
#line 1990 "y.tab.c"
    break;

  case 74: /* params_const: param_const params_const  */
#line 254 "parser.y"
                                       {
    count_param_vector++;
}
#line 1998 "y.tab.c"
    break;

  case 75: /* params_const: ',' param_const  */
#line 257 "parser.y"
                  {
    count_param_vector++;
}
#line 2006 "y.tab.c"
    break;

  case 76: /* params_const: %empty  */
#line 260 "parser.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 2014 "y.tab.c"
    break;

  case 77: /* param_const: value  */
#line 265 "parser.y"
                   {
    insert_at_end_l_param(&head_params_l, (yyvsp[0].nd_obj2).type);
}
#line 2022 "y.tab.c"
    break;

  case 78: /* $@22: %empty  */
#line 270 "parser.y"
                      { check_declaration((yyvsp[0].nd_obj).name); }
#line 2028 "y.tab.c"
    break;

  case 79: /* class_call_aux: TK_ID $@22 '.' TK_ID  */
#line 270 "parser.y"
                                                                {
    struct node *aux_left = mknode((yyvsp[-3].nd_obj).nd, NULL, (yyvsp[-3].nd_obj).name); 
    struct node *aux_right = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[0].nd_obj).name); 
    (yyval.nd_obj).nd = mknode(aux_left, aux_right, "call"); 
}
#line 2038 "y.tab.c"
    break;

  case 80: /* init: '=' expression  */
#line 277 "parser.y"
                     { 
    (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; 
    sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name);   
}
#line 2048 "y.tab.c"
    break;

  case 81: /* init: %empty  */
#line 282 "parser.y"
  { 
    sprintf((yyval.nd_obj2).type, "NULL"); 
    (yyval.nd_obj2).nd = mknode(NULL, NULL, ""); 
    strcpy((yyval.nd_obj2).name, "NULL"); 
}
#line 2058 "y.tab.c"
    break;

  case 82: /* expression: expression TK_MULTIPLY expression  */
#line 289 "parser.y"
                                              { 
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
		}
	}
}
#line 2084 "y.tab.c"
    break;

  case 83: /* expression: expression TK_DIVIDE expression  */
#line 310 "parser.y"
                                  {
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
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
            }
        } 
    } else {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Divisão por zero\n", countn[count_file_name], file_name_current[count_file_name]);
    }
}
#line 2114 "y.tab.c"
    break;

  case 84: /* expression: expression TK_SUBTRACT expression  */
#line 335 "parser.y"
                                    {
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
		}
	} 
}
#line 2140 "y.tab.c"
    break;

  case 85: /* expression: expression TK_ADD expression  */
#line 356 "parser.y"
                               {
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
		}
	} 
}
#line 2166 "y.tab.c"
    break;

  case 86: /* expression: value  */
#line 377 "parser.y"
        { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name); 
    sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; 
}
#line 2176 "y.tab.c"
    break;

  case 87: /* expression: class_call_aux '(' params_const ')'  */
#line 382 "parser.y"
                                      { 
    check_method((yyvsp[-3].nd_obj).nd->left->token, (yyvsp[-3].nd_obj).nd->right->token, head_params_l); 
    free_l_param(&head_params_l);
    (yyval.nd_obj2).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "call_method");
    count_param_vector = 0;
    char *type_function;
    int i, find_bool = 0;
    for(i = count-1; i >= 0; i--) {
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
#line 2200 "y.tab.c"
    break;

  case 94: /* value: TK_NUMBER  */
#line 411 "parser.y"
                 { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "inteiro");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2210 "y.tab.c"
    break;

  case 95: /* value: TK_NUMBER_FLOAT  */
#line 416 "parser.y"
                  { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "decimal");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2220 "y.tab.c"
    break;

  case 96: /* value: TK_CHARACTER  */
#line 421 "parser.y"
               { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "caracter");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2230 "y.tab.c"
    break;

  case 97: /* value: TK_ID  */
#line 426 "parser.y"
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
#line 2246 "y.tab.c"
    break;

  case 98: /* value: TK_STRING  */
#line 437 "parser.y"
            {
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "palavra");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2256 "y.tab.c"
    break;

  case 99: /* $@23: %empty  */
#line 444 "parser.y"
                  { add('R'); }
#line 2262 "y.tab.c"
    break;

  case 100: /* return: TK_RETURN $@23 value ';'  */
#line 444 "parser.y"
                                          { 
    check_function_return((yyvsp[-1].nd_obj2).type); 
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return"); 
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj2).nd, "RETURN"); 
}
#line 2272 "y.tab.c"
    break;

  case 101: /* return: %empty  */
#line 449 "parser.y"
  { 
    (yyval.nd_obj).nd = NULL; 
    function_return = NULL;
    check_function_return("NULL");
}
#line 2282 "y.tab.c"
    break;


#line 2286 "y.tab.c"

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

#line 456 "parser.y"


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
    if (sem_errors>0) {
    printf("Análise semântica concluída com %d erros\n", sem_errors);
    for(int i = 0; i < sem_errors; i++){
        printf("%s", errors[i]);
    }
    } else {
        printf("Análise semântica concluída sem erros");
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

void check_function_return(const char *value) {
	char *function_datatype = get_type_function(symbol_table[count-1].data_type, symbol_table[count-1].class_scope);
    char *return_datatype = get_type(value);
    if (strcmp(value, function_datatype)) {
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
	for(i = count-1; i >= 0; i--) {
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
    for(i = count-1; i >= 0; i--) {
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
    for(i = count-1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, object) == 0) {   
            class_name_target = strdup(symbol_table[i].data_type);
            break;
        }
    }
    for(i = count-1; i >= 0; i--) {
        if ((strcmp(symbol_table[i].class_name, class_name_target) == 0) && (strcmp(symbol_table[i].id_name, atribute) == 0)) {   
            return;
        }
    }
    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O atributo %s não existe na classe %s\n", countn[count_file_name], file_name_current[count_file_name], atribute, class_name_target);
}

void check_method(const char *object, const char *method, struct param_types *head) {
    int i, j; 
    char *class_name_target;
    for(i = count-1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, object) == 0) {   
            class_name_target = strdup(symbol_table[i].data_type);
            break;
        }
    }
    if (strcmp(symbol_table[i].type, "Object")) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O %s não é um objeto\n", countn[count_file_name], file_name_current[count_file_name], object);
        return;
    }
    for(i = count-1; i >= 0; i--) {
        if ((strcmp(symbol_table[i].class_name, class_name_target) == 0) && (strcmp(symbol_table[i].id_name, method) == 0)) {   
            if (symbol_table[i].num_param != count_param_vector) {
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s espera %d parametros e recebeu %d\n", countn[count_file_name], file_name_current[count_file_name], method, symbol_table[i].num_param, count_param_vector);
            }
            int count_paran_index = 1;
            struct param_types *temp = head;
            for(j = i+1; j <= i+count_param_vector; j++) {
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
    for(i = count-1; i >= 0; i--) {
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
	for(int i = 0; i < count; i++) {
		if (!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}

char *get_type_function(const char *var, int scope){
	for(int i = 0; i < count; i++) {
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
    for(i = count-1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, type) == 0 && symbol_table[i].class_scope == cl_scope && strcmp(symbol_table[i].type, "Attribute") == 0) {
            aux_return = 1;
            break;
        }
    }
    if (!aux_return) {
        for(i = count-1; i >= 0; i--) {
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
