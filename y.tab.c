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
#line 1 "sintatico_part1.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    void insert_type();
    int search(char *);
	void insert_type();
	void print_tree(struct node*);
	void print_inorder(struct node *);
    void check_declaration(char *);
	void check_return_type(char *);
	int check_types(char *, char *);
	char *get_type(char *);
	struct node* mknode(struct node *left, struct node *right, char *token);

	struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
	} symbol_table[40];

    int count=0;
    int q;
	char type[10];
    extern int countn;
	struct node *head;
	int sem_errors=0;
	int ic_idx=0;
	int temp_var=0;
	int label=0;
	int is_for=0;
	char buff[100];
	char errors[10][100];
    char reserved[12][10] = {"inteiro", "decimal", "caracter", "palavra", "vazio", "se", "senao", "enquanto", "principal", "retorne", "include", "forma"};
	char icg[50][100];

    struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};

#line 122 "y.tab.c"

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
    TK_PRINTF = 259,               /* TK_PRINTF  */
    TK_SCANF = 260,                /* TK_SCANF  */
    TK_TYPE_INT = 261,             /* TK_TYPE_INT  */
    TK_TYPE_FLOAT = 262,           /* TK_TYPE_FLOAT  */
    TK_TYPE_CHAR = 263,            /* TK_TYPE_CHAR  */
    TK_TYPE_STRING = 264,          /* TK_TYPE_STRING  */
    TK_RETURN = 265,               /* TK_RETURN  */
    TK_FOR = 266,                  /* TK_FOR  */
    TK_IF = 267,                   /* TK_IF  */
    TK_ELSE = 268,                 /* TK_ELSE  */
    TK_CLASS_DEFINITION = 269,     /* TK_CLASS_DEFINITION  */
    TK_CLASS_DEFINITION_MAIN = 270, /* TK_CLASS_DEFINITION_MAIN  */
    TK_INCLUDE = 271,              /* TK_INCLUDE  */
    TK_INCLUDE_CLASS = 272,        /* TK_INCLUDE_CLASS  */
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
    TK_ADD = 288,                  /* TK_ADD  */
    TK_SUBTRACT = 289,             /* TK_SUBTRACT  */
    TK_DIVIDE = 290,               /* TK_DIVIDE  */
    TK_MULTIPLY = 291,             /* TK_MULTIPLY  */
    TK_STRING = 292,               /* TK_STRING  */
    TK_CHARACTER = 293             /* TK_CHARACTER  */
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
#define TK_TYPE_STRING 264
#define TK_RETURN 265
#define TK_FOR 266
#define TK_IF 267
#define TK_ELSE 268
#define TK_CLASS_DEFINITION 269
#define TK_CLASS_DEFINITION_MAIN 270
#define TK_INCLUDE 271
#define TK_INCLUDE_CLASS 272
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
#define TK_ADD 288
#define TK_SUBTRACT 289
#define TK_DIVIDE 290
#define TK_MULTIPLY 291
#define TK_STRING 292
#define TK_CHARACTER 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "sintatico_part1.y"
     

struct var_name { 
	char name[100]; 
	struct node* nd;
} nd_obj;


#line 260 "y.tab.c"

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
  YYSYMBOL_TK_PRINTF = 4,                  /* TK_PRINTF  */
  YYSYMBOL_TK_SCANF = 5,                   /* TK_SCANF  */
  YYSYMBOL_TK_TYPE_INT = 6,                /* TK_TYPE_INT  */
  YYSYMBOL_TK_TYPE_FLOAT = 7,              /* TK_TYPE_FLOAT  */
  YYSYMBOL_TK_TYPE_CHAR = 8,               /* TK_TYPE_CHAR  */
  YYSYMBOL_TK_TYPE_STRING = 9,             /* TK_TYPE_STRING  */
  YYSYMBOL_TK_RETURN = 10,                 /* TK_RETURN  */
  YYSYMBOL_TK_FOR = 11,                    /* TK_FOR  */
  YYSYMBOL_TK_IF = 12,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 13,                   /* TK_ELSE  */
  YYSYMBOL_TK_CLASS_DEFINITION = 14,       /* TK_CLASS_DEFINITION  */
  YYSYMBOL_TK_CLASS_DEFINITION_MAIN = 15,  /* TK_CLASS_DEFINITION_MAIN  */
  YYSYMBOL_TK_INCLUDE = 16,                /* TK_INCLUDE  */
  YYSYMBOL_TK_INCLUDE_CLASS = 17,          /* TK_INCLUDE_CLASS  */
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
  YYSYMBOL_TK_ADD = 33,                    /* TK_ADD  */
  YYSYMBOL_TK_SUBTRACT = 34,               /* TK_SUBTRACT  */
  YYSYMBOL_TK_DIVIDE = 35,                 /* TK_DIVIDE  */
  YYSYMBOL_TK_MULTIPLY = 36,               /* TK_MULTIPLY  */
  YYSYMBOL_TK_STRING = 37,                 /* TK_STRING  */
  YYSYMBOL_TK_CHARACTER = 38,              /* TK_CHARACTER  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_class = 52,                     /* class  */
  YYSYMBOL_class_body = 53,                /* class_body  */
  YYSYMBOL_method_signature = 54,          /* method_signature  */
  YYSYMBOL_atributs_method = 55,           /* atributs_method  */
  YYSYMBOL_class_atributes = 56,           /* class_atributes  */
  YYSYMBOL_class_defination = 57,          /* class_defination  */
  YYSYMBOL_headers = 58,                   /* headers  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_datatype = 60,                  /* datatype  */
  YYSYMBOL_body = 61,                      /* body  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_63_3 = 63,                      /* $@3  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_65_5 = 65,                      /* $@5  */
  YYSYMBOL_66_6 = 66,                      /* $@6  */
  YYSYMBOL_body_tail = 67,                 /* body_tail  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_69_8 = 69,                      /* $@8  */
  YYSYMBOL_70_9 = 70,                      /* $@9  */
  YYSYMBOL_statement_class = 71,           /* statement_class  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_73_11 = 73,                     /* $@11  */
  YYSYMBOL_else = 74,                      /* else  */
  YYSYMBOL_75_12 = 75,                     /* $@12  */
  YYSYMBOL_condition = 76,                 /* condition  */
  YYSYMBOL_statement_atributes = 77,       /* statement_atributes  */
  YYSYMBOL_78_13 = 78,                     /* $@13  */
  YYSYMBOL_statement = 79,                 /* statement  */
  YYSYMBOL_init = 80,                      /* init  */
  YYSYMBOL_expression = 81,                /* expression  */
  YYSYMBOL_arithmetic = 82,                /* arithmetic  */
  YYSYMBOL_relop = 83,                     /* relop  */
  YYSYMBOL_value = 84,                     /* value  */
  YYSYMBOL_return = 85,                    /* return  */
  YYSYMBOL_86_14 = 86                      /* $@14  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

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
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
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
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    66,    67,    70,    71,    74,    75,    76,
      79,    83,    84,    85,    88,    91,    94,    94,    97,    98,
      99,   100,   101,   104,   104,   105,   105,   106,   107,   108,
     108,   109,   110,   110,   111,   111,   114,   115,   116,   116,
     117,   117,   118,   118,   119,   122,   122,   122,   125,   125,
     126,   129,   130,   131,   134,   134,   137,   138,   139,   140,
     141,   142,   143,   146,   147,   148,   151,   152,   153,   156,
     157,   158,   159,   162,   163,   164,   165,   166,   167,   170,
     171,   172,   173,   176,   176,   177
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_VOID", "TK_PRINTF",
  "TK_SCANF", "TK_TYPE_INT", "TK_TYPE_FLOAT", "TK_TYPE_CHAR",
  "TK_TYPE_STRING", "TK_RETURN", "TK_FOR", "TK_IF", "TK_ELSE",
  "TK_CLASS_DEFINITION", "TK_CLASS_DEFINITION_MAIN", "TK_INCLUDE",
  "TK_INCLUDE_CLASS", "TK_TRUE", "TK_FALSE", "TK_NUMBER",
  "TK_NUMBER_FLOAT", "TK_ID", "TK_CLASS_NAME", "TK_UNARY", "TK_LE",
  "TK_GE", "TK_EQ", "TK_NE", "TK_GT", "TK_LT", "TK_AND", "TK_OR", "TK_ADD",
  "TK_SUBTRACT", "TK_DIVIDE", "TK_MULTIPLY", "TK_STRING", "TK_CHARACTER",
  "'{'", "'}'", "'('", "')'", "','", "';'", "'&'", "'['", "']'", "'='",
  "'.'", "$accept", "program", "class", "class_body", "method_signature",
  "atributs_method", "class_atributes", "class_defination", "headers",
  "$@1", "datatype", "body", "$@2", "$@3", "$@4", "$@5", "$@6",
  "body_tail", "$@7", "$@8", "$@9", "statement_class", "$@10", "$@11",
  "else", "$@12", "condition", "statement_atributes", "$@13", "statement",
  "init", "expression", "arithmetic", "relop", "value", "return", "$@14", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,     1,  -137,    10,    12,   -24,    12,     4,  -137,    36,
    -137,  -137,   112,  -137,   112,     3,  -137,  -137,  -137,  -137,
    -137,    15,    20,   112,    46,    26,    31,  -137,  -137,   112,
    -137,    33,  -137,  -137,    43,    65,    55,    83,    61,    -1,
    -137,   124,   112,  -137,  -137,  -137,  -137,    -1,    56,    -9,
    -137,  -137,  -137,  -137,    53,  -137,    95,   -15,   102,    90,
     100,  -137,    30,  -137,  -137,  -137,  -137,  -137,    -1,   104,
     108,   118,   119,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
      -1,   139,    -1,   140,  -137,    55,   116,  -137,   124,   126,
    -137,  -137,  -137,    56,   127,   128,    51,    78,    56,    55,
      56,  -137,  -137,   145,    29,   112,   129,   130,   146,   131,
    -137,  -137,   132,   125,  -137,   121,  -137,   133,  -137,   135,
     136,    78,   137,    29,   147,   138,  -137,  -137,   150,   141,
     134,  -137,   142,  -137,   144,    51,  -137,  -137,   -14,   148,
     143,   149,   152,   151,   154,   156,   157,   153,   165,   134,
     134,  -137,  -137,   160,   155,   164,   158,  -137,  -137,  -137,
    -137,   134,   161,   159,  -137,   166,   167,   162,   163,   168,
     134,  -137,   134,   169,   134,   170,  -137,   171,  -137,  -137,
     172,   134,  -137
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,    16,     0,     4,     0,     4,     0,    15,     0,
       1,     3,     9,     2,     9,     0,    22,    18,    19,    20,
      21,     0,     0,     9,     0,     0,     0,    17,     5,    13,
       7,    54,    14,     6,     0,     0,    65,     0,    12,     0,
      55,     0,    13,    79,    80,    82,    81,     0,    64,    68,
      29,    32,    23,    25,     0,    45,     0,     0,    85,     0,
       0,    11,     0,    68,    69,    70,    72,    71,     0,     0,
       0,     0,     0,    60,    75,    76,    77,    78,    74,    73,
       0,     0,     0,     0,    61,    56,     0,    83,    31,     0,
      28,    27,    67,    66,     0,     0,     0,     0,    58,    65,
      59,    46,    57,     0,     0,     9,     0,     0,     0,     0,
      52,    53,     0,     0,    62,     0,    34,     0,     8,     0,
       0,     0,     0,     0,     0,     0,    84,    30,     0,     0,
      44,    51,     0,    35,     0,     0,    38,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    44,
      44,    47,    33,     0,     0,     0,     0,    48,    26,    37,
      36,    44,     0,     0,    42,     0,     0,     0,     0,     0,
      44,    24,    44,     0,    44,     0,    39,     0,    43,    49,
       0,    44,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,    38,  -137,   -11,  -137,   173,  -137,  -137,  -137,  -137,
     -12,   176,  -137,  -137,  -137,  -137,  -137,  -136,  -137,  -137,
    -137,   -36,  -137,  -137,  -137,  -137,    63,  -137,  -137,   -40,
     -76,   -41,  -137,    76,   -35,  -137,  -137
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    21,    22,    34,    23,     5,     6,     9,
     138,    88,    71,    72,    69,    70,   125,   139,   145,   146,
     169,   140,    83,   115,   158,   165,   112,    25,    36,   141,
      40,    48,    68,    82,    63,    89,   104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    60,    24,    26,    49,    59,    62,    85,    85,   102,
      10,    24,    30,   159,   160,    12,     7,    35,    60,    43,
      44,    45,    59,   114,     8,   166,     1,    93,     2,    57,
      35,    86,   147,   -63,   175,   -63,   176,    46,   178,    98,
      47,   100,    11,    14,    13,   182,    57,    27,    60,    43,
      44,    45,    59,    15,    16,    28,   109,    17,    18,    19,
      20,    29,   113,    64,    65,    66,    67,    46,    31,   117,
      32,    33,    92,    54,   -10,    56,    57,    73,    74,    75,
      76,    77,    78,    79,   108,    37,   113,    38,   131,    64,
      65,    66,    67,    24,   118,   144,   110,   111,    43,    44,
      45,    80,    81,    39,    42,    16,    50,    51,    17,    18,
      19,    20,    87,    52,    53,    16,    46,    84,    17,    18,
      19,    20,    41,   108,    54,    55,    56,    16,    50,    51,
      17,    18,    19,    20,    90,    52,    53,    16,   136,   137,
      17,    18,    19,    20,    91,    94,    54,    55,    56,    95,
      74,    75,    76,    77,    78,    79,    54,    55,    56,    96,
      97,    99,   101,   103,   106,   107,   105,   116,    85,   124,
     132,   119,   134,   120,   122,   121,   130,   126,   157,   127,
     164,   128,   133,   142,   129,   135,   143,   149,   148,   123,
       0,   177,   162,   150,   151,   152,   153,   154,   155,   161,
     156,   163,   168,   167,     0,   170,   172,   171,   173,     0,
     179,     0,   174,   180,     0,    61,   181,    58
};

static const yytype_int16 yycheck[] =
{
      12,    41,    14,    14,    39,    41,    47,    22,    22,    85,
       0,    23,    23,   149,   150,    39,    15,    29,    58,    20,
      21,    22,    58,    99,    23,   161,    14,    68,    16,    41,
      42,    46,    46,    42,   170,    44,   172,    38,   174,    80,
      41,    82,     4,    39,     6,   181,    58,    44,    88,    20,
      21,    22,    88,    17,     3,    40,    96,     6,     7,     8,
       9,    41,    97,    33,    34,    35,    36,    38,    22,   104,
      44,    40,    42,    22,    41,    24,    88,    24,    25,    26,
      27,    28,    29,    30,    96,    42,   121,    22,   123,    33,
      34,    35,    36,   105,   105,   135,    18,    19,    20,    21,
      22,    48,    49,    48,    43,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     3,    38,    22,     6,     7,
       8,     9,    39,   135,    22,    23,    24,     3,     4,     5,
       6,     7,     8,     9,    44,    11,    12,     3,     4,     5,
       6,     7,     8,     9,    44,    41,    22,    23,    24,    41,
      25,    26,    27,    28,    29,    30,    22,    23,    24,    41,
      41,    22,    22,    47,    37,    37,    40,    22,    22,    48,
      23,    42,    22,    43,    42,    44,    39,    44,    13,    44,
      22,    45,    44,    41,   121,    44,    42,    44,    40,   113,
      -1,    22,    37,    44,    42,    44,    42,    41,    41,    39,
      47,    37,    43,    42,    -1,    39,    44,    40,    45,    -1,
      40,    -1,    44,    42,    -1,    42,    44,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    16,    51,    52,    57,    58,    15,    23,    59,
       0,    51,    39,    51,    39,    17,     3,     6,     7,     8,
       9,    53,    54,    56,    60,    77,    53,    44,    40,    41,
      53,    22,    44,    40,    55,    60,    78,    42,    22,    48,
      80,    39,    43,    20,    21,    22,    38,    41,    81,    84,
       4,     5,    11,    12,    22,    23,    24,    60,    61,    71,
      79,    55,    81,    84,    33,    34,    35,    36,    82,    64,
      65,    62,    63,    24,    25,    26,    27,    28,    29,    30,
      48,    49,    83,    72,    22,    22,    46,    10,    61,    85,
      44,    44,    42,    81,    41,    41,    41,    41,    81,    22,
      81,    22,    80,    47,    86,    40,    37,    37,    60,    79,
      18,    19,    76,    84,    80,    73,    22,    84,    53,    42,
      43,    44,    42,    83,    48,    66,    44,    44,    45,    76,
      39,    84,    23,    44,    22,    44,     4,     5,    60,    67,
      71,    79,    41,    42,    79,    68,    69,    46,    40,    44,
      44,    42,    44,    42,    41,    41,    47,    13,    74,    67,
      67,    39,    37,    37,    22,    75,    67,    42,    43,    70,
      39,    40,    44,    45,    44,    67,    67,    22,    67,    40,
      42,    44,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    52,    53,    53,    53,
      54,    55,    55,    55,    56,    57,    59,    58,    60,    60,
      60,    60,    60,    62,    61,    63,    61,    61,    61,    64,
      61,    61,    65,    61,    66,    61,    67,    67,    68,    67,
      69,    67,    70,    67,    67,    72,    73,    71,    75,    74,
      74,    76,    76,    76,    78,    77,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    86,    85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     4,     5,     2,     9,     0,
       2,     4,     2,     0,     2,     2,     0,     4,     1,     1,
       1,     1,     1,     0,    12,     0,     9,     2,     2,     0,
       6,     2,     0,     9,     0,     6,     3,     3,     0,     7,
       0,    10,     0,     7,     0,     0,     0,     8,     0,     5,
       0,     3,     1,     1,     0,     4,     2,     3,     3,     3,
       2,     2,     4,     2,     2,     0,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0
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
  case 10: /* method_signature: datatype TK_ID  */
#line 79 "sintatico_part1.y"
                                 { add('F'); }
#line 1454 "y.tab.c"
    break;

  case 15: /* class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME  */
#line 91 "sintatico_part1.y"
                                                    { add('Z'); }
#line 1460 "y.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 94 "sintatico_part1.y"
                    { add('H'); }
#line 1466 "y.tab.c"
    break;

  case 18: /* datatype: TK_TYPE_INT  */
#line 97 "sintatico_part1.y"
                      { insert_type(); }
#line 1472 "y.tab.c"
    break;

  case 19: /* datatype: TK_TYPE_FLOAT  */
#line 98 "sintatico_part1.y"
                { insert_type(); }
#line 1478 "y.tab.c"
    break;

  case 20: /* datatype: TK_TYPE_CHAR  */
#line 99 "sintatico_part1.y"
               { insert_type(); }
#line 1484 "y.tab.c"
    break;

  case 21: /* datatype: TK_TYPE_STRING  */
#line 100 "sintatico_part1.y"
                 { insert_type(); }
#line 1490 "y.tab.c"
    break;

  case 22: /* datatype: TK_VOID  */
#line 101 "sintatico_part1.y"
          { insert_type(); }
#line 1496 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 104 "sintatico_part1.y"
             { add('K'); }
#line 1502 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 105 "sintatico_part1.y"
        { add('K'); }
#line 1508 "y.tab.c"
    break;

  case 29: /* $@4: %empty  */
#line 108 "sintatico_part1.y"
            { add('K'); }
#line 1514 "y.tab.c"
    break;

  case 32: /* $@5: %empty  */
#line 110 "sintatico_part1.y"
           { add('K'); }
#line 1520 "y.tab.c"
    break;

  case 34: /* $@6: %empty  */
#line 111 "sintatico_part1.y"
                         { add('X'); }
#line 1526 "y.tab.c"
    break;

  case 38: /* $@7: %empty  */
#line 116 "sintatico_part1.y"
            { add('K'); }
#line 1532 "y.tab.c"
    break;

  case 40: /* $@8: %empty  */
#line 117 "sintatico_part1.y"
           { add('K'); }
#line 1538 "y.tab.c"
    break;

  case 42: /* $@9: %empty  */
#line 118 "sintatico_part1.y"
                         { add('X'); }
#line 1544 "y.tab.c"
    break;

  case 45: /* $@10: %empty  */
#line 122 "sintatico_part1.y"
                               { insert_type(); }
#line 1550 "y.tab.c"
    break;

  case 46: /* $@11: %empty  */
#line 122 "sintatico_part1.y"
                                                        { add('O'); }
#line 1556 "y.tab.c"
    break;

  case 48: /* $@12: %empty  */
#line 125 "sintatico_part1.y"
              { add('K'); }
#line 1562 "y.tab.c"
    break;

  case 54: /* $@13: %empty  */
#line 134 "sintatico_part1.y"
                                    { add('A'); }
#line 1568 "y.tab.c"
    break;

  case 79: /* value: TK_NUMBER  */
#line 170 "sintatico_part1.y"
                 { add('C'); }
#line 1574 "y.tab.c"
    break;

  case 80: /* value: TK_NUMBER_FLOAT  */
#line 171 "sintatico_part1.y"
                  { add('C'); }
#line 1580 "y.tab.c"
    break;

  case 81: /* value: TK_CHARACTER  */
#line 172 "sintatico_part1.y"
               { add('C'); }
#line 1586 "y.tab.c"
    break;

  case 83: /* $@14: %empty  */
#line 176 "sintatico_part1.y"
                  { add('K'); }
#line 1592 "y.tab.c"
    break;


#line 1596 "y.tab.c"

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

#line 180 "sintatico_part1.y"


struct node* mknode(struct node *left, struct node *right, char *token) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    char *newstr = (char*) malloc(strlen(token)+1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}

void insert_type() {
    strcpy(type, yytext);
}

void add(char c) {
    if(c == 'V'){
		for(int i=0; i<10; i++){
			if(!strcmp(reserved[i], strdup(yytext))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn+1, yytext);
				sem_errors++;
				return;
			}
		}
	}
    q=search(yytext);
    if(!q) {
        if(c == 'H') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);        
            symbol_table[count].data_type=strdup(type);     
            symbol_table[count].line_no=countn;    
            symbol_table[count].type=strdup("Header");
            count++;  
        }  
        else if(c == 'K') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Keyword\t");   
            count++;  
        }  else if(c == 'V') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Variable");   
            count++;  
        }  else if(c == 'C') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("CONST");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Constant");   
            count++;  
        }  else if(c == 'F') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Function");   
            count++;  
        }else if(c == 'Z') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Class");   
            count++;  
        }else if(c == 'O') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Object");   
            count++;  
        }else if(c == 'A') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Attribute");   
            count++;  
        }else if(c == 'X') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Vector");   
            count++;  
        }

    }
}

int search(char *type) { 
    int i; 
    for(i=count-1; i>=0; i--) {
        if(strcmp(symbol_table[i].id_name, type)==0) {   
            return -1;
            break;  
        }
    } 
    return 0;
}

int main(int argc, char **argv)
{
    int i;
    for (i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("Error: could not open file %s\n", argv[i]);
            return 1;
        }

        yyin = fp;

        yyparse();

        fclose(fp);
    }
    printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
    for (i = 0; i < count; i++) {
        printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
    }

    for (i = 0; i < count; i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }

    return 0;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
