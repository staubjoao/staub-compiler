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
    void printtree(struct node*);
    void printInorder(struct node *);
    int search(char *);
	void insert_type();
	void print_tree(struct node*);
	void print_inorder(struct node *);
    void check_declaration(const char *);
	void check_return_type(const char *);
	int check_types(const char *, const char *);
	char *get_type(const char *);
	struct node* mknode(struct node *left, struct node *right, const char *token);

	struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
	} symbol_table[40];

    struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};

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


#line 125 "y.tab.c"

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
    TK_TRUE = 272,                 /* TK_TRUE  */
    TK_FALSE = 273,                /* TK_FALSE  */
    TK_NUMBER = 274,               /* TK_NUMBER  */
    TK_NUMBER_FLOAT = 275,         /* TK_NUMBER_FLOAT  */
    TK_ID = 276,                   /* TK_ID  */
    TK_CLASS_NAME = 277,           /* TK_CLASS_NAME  */
    TK_UNARY = 278,                /* TK_UNARY  */
    TK_LE = 279,                   /* TK_LE  */
    TK_GE = 280,                   /* TK_GE  */
    TK_EQ = 281,                   /* TK_EQ  */
    TK_NE = 282,                   /* TK_NE  */
    TK_GT = 283,                   /* TK_GT  */
    TK_LT = 284,                   /* TK_LT  */
    TK_AND = 285,                  /* TK_AND  */
    TK_OR = 286,                   /* TK_OR  */
    TK_STRING = 287,               /* TK_STRING  */
    TK_CHARACTER = 288,            /* TK_CHARACTER  */
    TK_MULTIPLY = 289,             /* TK_MULTIPLY  */
    TK_DIVIDE = 290,               /* TK_DIVIDE  */
    TK_ADD = 291,                  /* TK_ADD  */
    TK_SUBTRACT = 292              /* TK_SUBTRACT  */
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
#define TK_TRUE 272
#define TK_FALSE 273
#define TK_NUMBER 274
#define TK_NUMBER_FLOAT 275
#define TK_ID 276
#define TK_CLASS_NAME 277
#define TK_UNARY 278
#define TK_LE 279
#define TK_GE 280
#define TK_EQ 281
#define TK_NE 282
#define TK_GT 283
#define TK_LT 284
#define TK_AND 285
#define TK_OR 286
#define TK_STRING 287
#define TK_CHARACTER 288
#define TK_MULTIPLY 289
#define TK_DIVIDE 290
#define TK_ADD 291
#define TK_SUBTRACT 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "sintatico_part1.y"


struct var_name { 
	char name[100]; 
	struct node* nd;
} nd_obj;

struct var_name2 { 
	char name[100]; 
	struct node* nd;
	char type[5];
} nd_obj2; 


#line 267 "y.tab.c"

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
  YYSYMBOL_TK_TRUE = 17,                   /* TK_TRUE  */
  YYSYMBOL_TK_FALSE = 18,                  /* TK_FALSE  */
  YYSYMBOL_TK_NUMBER = 19,                 /* TK_NUMBER  */
  YYSYMBOL_TK_NUMBER_FLOAT = 20,           /* TK_NUMBER_FLOAT  */
  YYSYMBOL_TK_ID = 21,                     /* TK_ID  */
  YYSYMBOL_TK_CLASS_NAME = 22,             /* TK_CLASS_NAME  */
  YYSYMBOL_TK_UNARY = 23,                  /* TK_UNARY  */
  YYSYMBOL_TK_LE = 24,                     /* TK_LE  */
  YYSYMBOL_TK_GE = 25,                     /* TK_GE  */
  YYSYMBOL_TK_EQ = 26,                     /* TK_EQ  */
  YYSYMBOL_TK_NE = 27,                     /* TK_NE  */
  YYSYMBOL_TK_GT = 28,                     /* TK_GT  */
  YYSYMBOL_TK_LT = 29,                     /* TK_LT  */
  YYSYMBOL_TK_AND = 30,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 31,                     /* TK_OR  */
  YYSYMBOL_TK_STRING = 32,                 /* TK_STRING  */
  YYSYMBOL_TK_CHARACTER = 33,              /* TK_CHARACTER  */
  YYSYMBOL_TK_MULTIPLY = 34,               /* TK_MULTIPLY  */
  YYSYMBOL_TK_DIVIDE = 35,                 /* TK_DIVIDE  */
  YYSYMBOL_TK_ADD = 36,                    /* TK_ADD  */
  YYSYMBOL_TK_SUBTRACT = 37,               /* TK_SUBTRACT  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '&'  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_headers = 49,                   /* headers  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_class = 51,                     /* class  */
  YYSYMBOL_class_defination_main = 52,     /* class_defination_main  */
  YYSYMBOL_class_body = 53,                /* class_body  */
  YYSYMBOL_method_signature = 54,          /* method_signature  */
  YYSYMBOL_atributs_method = 55,           /* atributs_method  */
  YYSYMBOL_class_atributes = 56,           /* class_atributes  */
  YYSYMBOL_class_defination = 57,          /* class_defination  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_datatype = 59,                  /* datatype  */
  YYSYMBOL_body = 60,                      /* body  */
  YYSYMBOL_body_statement = 61,            /* body_statement  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_64_5 = 64,                      /* $@5  */
  YYSYMBOL_65_6 = 65,                      /* $@6  */
  YYSYMBOL_else = 66,                      /* else  */
  YYSYMBOL_67_7 = 67,                      /* $@7  */
  YYSYMBOL_statement_class = 68,           /* statement_class  */
  YYSYMBOL_69_8 = 69,                      /* $@8  */
  YYSYMBOL_70_9 = 70,                      /* $@9  */
  YYSYMBOL_condition = 71,                 /* condition  */
  YYSYMBOL_statement_atributes = 72,       /* statement_atributes  */
  YYSYMBOL_73_10 = 73,                     /* $@10  */
  YYSYMBOL_statement = 74,                 /* statement  */
  YYSYMBOL_init = 75,                      /* init  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_relop = 77,                     /* relop  */
  YYSYMBOL_value = 78,                     /* value  */
  YYSYMBOL_return = 79,                    /* return  */
  YYSYMBOL_80_11 = 80                      /* $@11  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,     2,     2,     2,     2,     2,    44,     2,
      41,    42,     2,     2,    43,     2,    46,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    78,    78,    83,    86,    87,    87,    90,    95,    98,
     101,   104,   109,   113,   114,   115,   118,   121,   121,   124,
     125,   126,   127,   128,   131,   132,   135,   135,   138,   138,
     141,   144,   147,   147,   151,   151,   156,   156,   157,   160,
     160,   160,   163,   164,   165,   168,   168,   169,   172,   173,
     174,   175,   176,   177,   178,   181,   184,   185,   186,   187,
     188,   189,   192,   193,   194,   195,   196,   197,   200,   201,
     202,   203,   206,   206,   210
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
  "TK_TRUE", "TK_FALSE", "TK_NUMBER", "TK_NUMBER_FLOAT", "TK_ID",
  "TK_CLASS_NAME", "TK_UNARY", "TK_LE", "TK_GE", "TK_EQ", "TK_NE", "TK_GT",
  "TK_LT", "TK_AND", "TK_OR", "TK_STRING", "TK_CHARACTER", "TK_MULTIPLY",
  "TK_DIVIDE", "TK_ADD", "TK_SUBTRACT", "'{'", "'}'", "';'", "'('", "')'",
  "','", "'&'", "'='", "'.'", "$accept", "program", "headers", "$@1",
  "class", "class_defination_main", "class_body", "method_signature",
  "atributs_method", "class_atributes", "class_defination", "$@2",
  "datatype", "body", "body_statement", "$@3", "$@4", "$@5", "$@6", "else",
  "$@7", "statement_class", "$@8", "$@9", "condition",
  "statement_atributes", "$@10", "statement", "init", "expression",
  "relop", "value", "return", "$@11", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      11,   -11,   -93,    26,    52,   -93,    14,   -93,    19,   -93,
      40,    46,    29,    88,   -93,   -93,   -93,    88,   -93,   -93,
     -93,   -93,   -93,    38,    41,    88,    62,    47,    45,   -93,
      88,   -93,   -35,   -93,   -93,    50,    68,    59,    67,    63,
      -5,   -93,    42,    88,   -93,   -93,   -93,   -93,    -5,    -3,
     -93,   -93,   -93,   -93,   -93,    15,   -93,    86,    87,    99,
      42,    70,    71,   -93,    44,    -5,    -5,    -5,    -5,    72,
      73,    75,    76,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
      -5,    91,    -5,    94,   -93,    59,   -93,    79,   -93,   -93,
     -93,   -93,   -18,   -18,   -93,   -93,    89,    90,    55,    55,
      -3,    59,    -3,   -93,   -93,    37,    88,    77,    80,   -93,
     -93,    78,    74,    82,   -93,    81,    85,   -93,    92,    83,
      93,    37,    95,   106,   -93,   -93,   108,    42,   -93,    42,
      96,    97,   101,   102,   100,    98,   -93,   117,   -93,   -93,
     -93,   -93,   105,    42,   107,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     5,     0,     0,     3,     0,    17,     0,     1,
       0,     4,     0,    11,    18,     6,     8,    11,    23,    19,
      20,    21,    22,     0,     0,    11,     0,     0,     0,     7,
      15,     9,    12,    16,     2,     0,     0,     0,     0,    14,
       0,    46,    25,    15,    68,    69,    71,    70,     0,    55,
      61,    26,    28,    34,    32,     0,    39,     0,     0,    74,
      25,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    64,    65,    66,    67,    63,    62,
       0,     0,     0,     0,    53,    49,    72,     0,    24,    30,
      31,    60,    56,    57,    59,    58,     0,     0,     0,     0,
      50,     0,    51,    40,    48,     0,    11,     0,     0,    43,
      44,     0,     0,     0,    54,     0,     0,    10,     0,     0,
       0,     0,     0,     0,    73,    27,     0,    25,    42,    25,
       0,     0,     0,     0,     0,     0,    35,    38,    41,    29,
      36,    33,     0,    25,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   134,   -93,   -93,   -93,   -16,   -93,   104,   -93,
     -93,   -93,   -13,   -58,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,    36,   -93,   -93,   -93,   -77,   -45,
      24,   -92,   -93,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    11,     8,     5,    12,    23,    24,    35,    25,
       6,    14,    58,    59,    60,    69,    70,    72,    71,   141,
     142,    61,    83,   115,   111,    27,    37,    62,    41,    49,
      82,    50,    87,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    28,    88,    64,    26,   -47,   112,   112,   104,    31,
     -45,     7,    26,   116,    44,    45,    46,    36,    67,    68,
      92,    93,    94,    95,   114,     1,     9,     2,    47,   128,
      36,    65,    66,    67,    68,   100,    48,   102,    73,    74,
      75,    76,    77,    78,    79,    18,    51,    52,    19,    20,
      21,    22,    13,    53,    54,    16,    44,    45,    46,    15,
      80,    81,     2,    55,    56,    57,    10,    17,     2,   132,
      47,   133,   109,   110,    44,    45,    46,    29,    65,    66,
      67,    68,    30,    32,    34,   144,    91,    33,    47,    39,
     117,    18,    38,    26,    19,    20,    21,    22,    74,    75,
      76,    77,    78,    79,    40,    42,    43,    84,    85,    86,
      89,    90,   101,    96,    97,   103,    98,    99,   106,   118,
     120,   107,   108,   119,   122,   124,   123,   126,   130,   131,
     140,   127,   125,   129,     4,   113,   121,   134,   139,   135,
     136,   137,   138,   143,     0,     0,   145,    63
};

static const yytype_int16 yycheck[] =
{
      13,    17,    60,    48,    17,    40,    98,    99,    85,    25,
      45,    22,    25,   105,    19,    20,    21,    30,    36,    37,
      65,    66,    67,    68,   101,    14,     0,    16,    33,   121,
      43,    34,    35,    36,    37,    80,    41,    82,    23,    24,
      25,    26,    27,    28,    29,     3,     4,     5,     6,     7,
       8,     9,    38,    11,    12,    15,    19,    20,    21,    40,
      45,    46,    16,    21,    22,    23,    14,    38,    16,   127,
      33,   129,    17,    18,    19,    20,    21,    39,    34,    35,
      36,    37,    41,    21,    39,   143,    42,    40,    33,    21,
     106,     3,    42,   106,     6,     7,     8,     9,    24,    25,
      26,    27,    28,    29,    45,    38,    43,    21,    21,    10,
      40,    40,    21,    41,    41,    21,    41,    41,    39,    42,
      42,    32,    32,    43,    42,    40,    45,    44,    22,    21,
      13,    38,    40,    38,     0,    99,   112,    41,    40,    42,
      39,    39,    42,    38,    -1,    -1,    39,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    16,    48,    49,    51,    57,    22,    50,     0,
      14,    49,    52,    38,    58,    40,    15,    38,     3,     6,
       7,     8,     9,    53,    54,    56,    59,    72,    53,    39,
      41,    53,    21,    40,    39,    55,    59,    73,    42,    21,
      45,    75,    38,    43,    19,    20,    21,    33,    41,    76,
      78,     4,     5,    11,    12,    21,    22,    23,    59,    60,
      61,    68,    74,    55,    76,    34,    35,    36,    37,    62,
      63,    65,    64,    23,    24,    25,    26,    27,    28,    29,
      45,    46,    77,    69,    21,    21,    10,    79,    60,    40,
      40,    42,    76,    76,    76,    76,    41,    41,    41,    41,
      76,    21,    76,    21,    75,    80,    39,    32,    32,    17,
      18,    71,    78,    71,    75,    70,    78,    53,    42,    43,
      42,    77,    42,    45,    40,    40,    44,    38,    78,    38,
      22,    21,    60,    60,    41,    42,    39,    39,    42,    40,
      13,    66,    67,    38,    60,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    50,    49,    51,    52,    53,
      53,    53,    54,    55,    55,    55,    56,    58,    57,    59,
      59,    59,    59,    59,    60,    60,    62,    61,    63,    61,
      61,    61,    64,    61,    65,    61,    67,    66,    66,    69,
      70,    68,    71,    71,    71,    73,    72,    72,    74,    74,
      74,    74,    74,    74,    74,    75,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    80,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     2,     0,     3,     4,     2,     2,
       9,     0,     2,     4,     2,     0,     2,     0,     3,     1,
       1,     1,     1,     1,     2,     0,     0,     6,     0,     9,
       2,     2,     0,     9,     0,     8,     0,     5,     0,     0,
       0,     8,     3,     1,     1,     0,     4,     2,     3,     2,
       3,     3,     2,     2,     4,     2,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0
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
  case 2: /* program: headers class_defination_main '{' class_body '}'  */
#line 78 "sintatico_part1.y"
                                                          { 
    (yyvsp[-3].nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "main_class"); 
    (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-3].nd_obj).nd, "program"); 
    head = (yyval.nd_obj).nd; 
}
#line 1430 "y.tab.c"
    break;

  case 4: /* headers: headers headers  */
#line 86 "sintatico_part1.y"
                         { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "headers"); }
#line 1436 "y.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 87 "sintatico_part1.y"
             { add('H'); }
#line 1442 "y.tab.c"
    break;

  case 6: /* headers: TK_INCLUDE $@1 ';'  */
#line 87 "sintatico_part1.y"
                               { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); }
#line 1448 "y.tab.c"
    break;

  case 7: /* class: class_defination '{' class_body '}'  */
#line 90 "sintatico_part1.y"
                                           {
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "class");
}
#line 1456 "y.tab.c"
    break;

  case 8: /* class_defination_main: TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN  */
#line 95 "sintatico_part1.y"
                                                                    { add('Z'); }
#line 1462 "y.tab.c"
    break;

  case 9: /* class_body: class_atributes class_body  */
#line 98 "sintatico_part1.y"
                                       { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "class_body"); 
}
#line 1470 "y.tab.c"
    break;

  case 10: /* class_body: method_signature '(' atributs_method ')' '{' body return '}' class_body  */
#line 101 "sintatico_part1.y"
                                                                           {
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "method");
}
#line 1478 "y.tab.c"
    break;

  case 11: /* class_body: %empty  */
#line 104 "sintatico_part1.y"
  { 
    (yyval.nd_obj).nd = NULL;
}
#line 1486 "y.tab.c"
    break;

  case 12: /* method_signature: datatype TK_ID  */
#line 109 "sintatico_part1.y"
                                 { add('F'); }
#line 1492 "y.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 121 "sintatico_part1.y"
                                                    { add('Z'); }
#line 1498 "y.tab.c"
    break;

  case 18: /* class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME $@2  */
#line 121 "sintatico_part1.y"
                                                                  { (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "class"); }
#line 1504 "y.tab.c"
    break;

  case 19: /* datatype: TK_TYPE_INT  */
#line 124 "sintatico_part1.y"
                      { insert_type(); }
#line 1510 "y.tab.c"
    break;

  case 20: /* datatype: TK_TYPE_FLOAT  */
#line 125 "sintatico_part1.y"
                { insert_type(); }
#line 1516 "y.tab.c"
    break;

  case 21: /* datatype: TK_TYPE_CHAR  */
#line 126 "sintatico_part1.y"
               { insert_type(); }
#line 1522 "y.tab.c"
    break;

  case 22: /* datatype: TK_TYPE_STRING  */
#line 127 "sintatico_part1.y"
                 { insert_type(); }
#line 1528 "y.tab.c"
    break;

  case 23: /* datatype: TK_VOID  */
#line 128 "sintatico_part1.y"
          { insert_type(); }
#line 1534 "y.tab.c"
    break;

  case 24: /* body: body_statement body  */
#line 131 "sintatico_part1.y"
                          { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement_body"); }
#line 1540 "y.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 135 "sintatico_part1.y"
                          { add('K'); }
#line 1546 "y.tab.c"
    break;

  case 27: /* body_statement: TK_PRINTF $@3 '(' TK_STRING ')' ';'  */
#line 135 "sintatico_part1.y"
                                                              {
    (yyval.nd_obj).nd = mknode(NULL, NULL, "print");
}
#line 1554 "y.tab.c"
    break;

  case 28: /* $@4: %empty  */
#line 138 "sintatico_part1.y"
           { add('K'); }
#line 1560 "y.tab.c"
    break;

  case 29: /* body_statement: TK_SCANF $@4 '(' TK_STRING ',' '&' TK_ID ')' ';'  */
#line 138 "sintatico_part1.y"
                                                             {

}
#line 1568 "y.tab.c"
    break;

  case 30: /* body_statement: statement_class ';'  */
#line 141 "sintatico_part1.y"
                      {

}
#line 1576 "y.tab.c"
    break;

  case 31: /* body_statement: statement ';'  */
#line 144 "sintatico_part1.y"
                {

}
#line 1584 "y.tab.c"
    break;

  case 32: /* $@5: %empty  */
#line 147 "sintatico_part1.y"
        { add('K'); }
#line 1590 "y.tab.c"
    break;

  case 33: /* body_statement: TK_IF $@5 '(' condition ')' '{' body '}' else  */
#line 147 "sintatico_part1.y"
                                                          {
    struct node *iff = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-8].nd_obj).name);
    (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else");
}
#line 1599 "y.tab.c"
    break;

  case 34: /* $@6: %empty  */
#line 151 "sintatico_part1.y"
         { add('K'); }
#line 1605 "y.tab.c"
    break;

  case 35: /* body_statement: TK_FOR $@6 '(' condition ')' '{' body '}'  */
#line 151 "sintatico_part1.y"
                                                      {

}
#line 1613 "y.tab.c"
    break;

  case 36: /* $@7: %empty  */
#line 156 "sintatico_part1.y"
              { add('K'); }
#line 1619 "y.tab.c"
    break;

  case 38: /* else: %empty  */
#line 157 "sintatico_part1.y"
  { (yyval.nd_obj).nd = NULL; }
#line 1625 "y.tab.c"
    break;

  case 39: /* $@8: %empty  */
#line 160 "sintatico_part1.y"
                               { insert_type(); }
#line 1631 "y.tab.c"
    break;

  case 40: /* $@9: %empty  */
#line 160 "sintatico_part1.y"
                                                        { add('O'); }
#line 1637 "y.tab.c"
    break;

  case 45: /* $@10: %empty  */
#line 168 "sintatico_part1.y"
                                    { add('A'); }
#line 1643 "y.tab.c"
    break;

  case 47: /* statement_atributes: datatype TK_ID  */
#line 169 "sintatico_part1.y"
                 { add('A'); }
#line 1649 "y.tab.c"
    break;

  case 68: /* value: TK_NUMBER  */
#line 200 "sintatico_part1.y"
                 { add('C'); }
#line 1655 "y.tab.c"
    break;

  case 69: /* value: TK_NUMBER_FLOAT  */
#line 201 "sintatico_part1.y"
                  { add('C'); }
#line 1661 "y.tab.c"
    break;

  case 70: /* value: TK_CHARACTER  */
#line 202 "sintatico_part1.y"
               { add('C'); }
#line 1667 "y.tab.c"
    break;

  case 72: /* $@11: %empty  */
#line 206 "sintatico_part1.y"
                  { add('K'); }
#line 1673 "y.tab.c"
    break;

  case 73: /* return: TK_RETURN $@11 value ';'  */
#line 206 "sintatico_part1.y"
                                          { 
    check_return_type((yyvsp[-1].nd_obj2).name); (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return"); 
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj2).nd, "RETURN"); 
}
#line 1682 "y.tab.c"
    break;

  case 74: /* return: %empty  */
#line 210 "sintatico_part1.y"
  { 
    (yyval.nd_obj).nd = NULL; 
}
#line 1690 "y.tab.c"
    break;


#line 1694 "y.tab.c"

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

#line 215 "sintatico_part1.y"


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

    printf("\n\n");
	printf("\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	printtree(head);
    printf("\n\n");

    return 0;
}


struct node* mknode(struct node *left, struct node *right, const char *token) {
    printf("%s\n", token);
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    char *newstr = (char*) malloc(strlen(token)+1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}

void printtree(struct node* tree) {
	printf("\n\n Inorder traversal of the Parse Tree: \n\n");
	printInorder(tree);
	printf("\n\n");
}

void printInorder(struct node *tree) {
	int i;
	if (tree->left) {
		printInorder(tree->left);
	}
	printf("%s, ", tree->token);
	if (tree->right) {
		printInorder(tree->right);
	}
}

void insert_type() {
    strcpy(type, yytext);
}

void check_return_type(const char *value) {
	char *main_datatype = get_type("main");
	char *return_datatype = get_type(value);
	if((!strcmp(main_datatype, "int") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
		return ;
	}
	else {
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
		sem_errors++;
	}
}

int check_types(const char *type1, const char *type2){
	// declaration with no init
	if(!strcmp(type2, "null"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))
		return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))
		return 6;
    return -1;
}

char *get_type(const char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
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

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
