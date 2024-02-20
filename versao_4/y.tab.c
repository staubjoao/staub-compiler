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
#line 1 "sintatico.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"

    #define MAX_SYMBOLS 100
    #define MAX_FILE_NAME_LEN 30
    #define MAX_TOKEN_LEN 20

    struct param_types {
        char * type;
        struct param_types * next;
    };

    void insert_at_end_l_param(struct param_types **head, char *type);
    void free_l_param(struct param_types **head);
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    void print_symbol_table();
    void insert_type();
    void printtree(struct node *);
    void printInorder(struct node *);
    int search(const char *, int, int);
	void insert_type();
	void print_tree(struct node*);
	void print_inorder(struct node *);
    void check_declaration(const char *);
    void check_declaration_previously(const char *);
    void check_atribute(const char *, const char *);
    void check_method(const char *, const char *, int, struct param_types *head);
	void function_check_return(const char *);
	int check_types(const char *, const char *);
	char *get_type(const char *);
	struct node* mknode(struct node *left, struct node *right, const char *token);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        char * file_name;
        char * class_name;
        int num_param;
        int class_scope;
        int scope;
        int line_no;
    } symbol_table[MAX_SYMBOLS];

    struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};

    struct tree_class_l* create_tree_class_l(char *file_name);
    void free_tree_class_l(struct tree_class_l *tree);

    struct tree_class_l {
        struct node *head;
        char * file_name;
        struct tree_class_l *next;
    };

    char file_name_current[MAX_FILE_NAME_LEN];
    char *class_name_current;
    int count=0;
    int count_lines;
    int q;
	char type[10];
    char *function_return;
    extern int countn;
	struct node *head;
	struct node *class_aux;
    struct tree_class_l *head_class_l = NULL;
    int princial_bool = 0;
	int sem_errors=0;
	int ic_idx=0;
	int temp_var=0;
	int label=0;
	int is_for=0;
    int param_count=0;
    int class_scope_count=0;
    int scope_count=0;
    struct param_types *head_params_l = NULL;
    int method_current;
	char buff[100];
	char errors[100][100];
	char icg[50][100];

    YY_BUFFER_STATE prev_buffer = NULL;

    #define MAX_INCLUDE_DEPTH 10
    char included_files[MAX_INCLUDE_DEPTH][256]; // Tamanho máximo do nome do arquivo é 255 caracteres
    int include_depth = 0;

    /* Função para incluir um arquivo */
    void include_file(const char* filename) {
        if (include_depth >= MAX_INCLUDE_DEPTH) {
            fprintf(stderr, "Exceeded maximum include depth\n");
            exit(EXIT_FAILURE);
        }
        strcpy(included_files[include_depth], filename);
        include_depth++;
    }

    /* Função para desfazer a inclusão de um arquivo */
    void undo_include() {
        if (include_depth > 0) {
            include_depth--;
        }
    }

    /* Função para obter o nome do arquivo atual */
    const char* current_file() {
        if (include_depth > 0) {
            return included_files[include_depth - 1];
        }
        return NULL;
    }

#line 196 "y.tab.c"

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
#line 126 "sintatico.y"


struct var_name { 
	char name[100]; 
	struct node* nd;
} nd_obj;

struct var_name2 { 
	char name[100]; 
	struct node* nd;
	char type[10];
} nd_obj2; 


#line 340 "y.tab.c"

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
  YYSYMBOL_TK_STRING = 33,                 /* TK_STRING  */
  YYSYMBOL_TK_CHARACTER = 34,              /* TK_CHARACTER  */
  YYSYMBOL_TK_MULTIPLY = 35,               /* TK_MULTIPLY  */
  YYSYMBOL_TK_DIVIDE = 36,                 /* TK_DIVIDE  */
  YYSYMBOL_TK_ADD = 37,                    /* TK_ADD  */
  YYSYMBOL_TK_SUBTRACT = 38,               /* TK_SUBTRACT  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_headers = 51,                   /* headers  */
  YYSYMBOL_include = 52,                   /* include  */
  YYSYMBOL_class = 53,                     /* class  */
  YYSYMBOL_class_defination = 54,          /* class_defination  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_class_body = 56,                /* class_body  */
  YYSYMBOL_57_3 = 57,                      /* $@3  */
  YYSYMBOL_class_body_main = 58,           /* class_body_main  */
  YYSYMBOL_method_signature = 59,          /* method_signature  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_atributs_method = 61,           /* atributs_method  */
  YYSYMBOL_parament_method = 62,           /* parament_method  */
  YYSYMBOL_63_5 = 63,                      /* $@5  */
  YYSYMBOL_class_atributes = 64,           /* class_atributes  */
  YYSYMBOL_datatype = 65,                  /* datatype  */
  YYSYMBOL_body = 66,                      /* body  */
  YYSYMBOL_body_statement = 67,            /* body_statement  */
  YYSYMBOL_68_6 = 68,                      /* $@6  */
  YYSYMBOL_69_7 = 69,                      /* $@7  */
  YYSYMBOL_70_8 = 70,                      /* $@8  */
  YYSYMBOL_71_9 = 71,                      /* $@9  */
  YYSYMBOL_else = 72,                      /* else  */
  YYSYMBOL_73_10 = 73,                     /* $@10  */
  YYSYMBOL_statement_class = 74,           /* statement_class  */
  YYSYMBOL_75_11 = 75,                     /* $@11  */
  YYSYMBOL_condition = 76,                 /* condition  */
  YYSYMBOL_statement_atributes = 77,       /* statement_atributes  */
  YYSYMBOL_78_12 = 78,                     /* $@12  */
  YYSYMBOL_statement = 79,                 /* statement  */
  YYSYMBOL_80_13 = 80,                     /* $@13  */
  YYSYMBOL_81_14 = 81,                     /* $@14  */
  YYSYMBOL_82_15 = 82,                     /* $@15  */
  YYSYMBOL_83_16 = 83,                     /* $@16  */
  YYSYMBOL_84_17 = 84,                     /* $@17  */
  YYSYMBOL_85_18 = 85,                     /* $@18  */
  YYSYMBOL_params_const = 86,              /* params_const  */
  YYSYMBOL_param_const = 87,               /* param_const  */
  YYSYMBOL_class_call = 88,                /* class_call  */
  YYSYMBOL_89_19 = 89,                     /* $@19  */
  YYSYMBOL_init = 90,                      /* init  */
  YYSYMBOL_expression = 91,                /* expression  */
  YYSYMBOL_relop = 92,                     /* relop  */
  YYSYMBOL_value = 93,                     /* value  */
  YYSYMBOL_return = 94,                    /* return  */
  YYSYMBOL_95_20 = 95                      /* $@20  */
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
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

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
      42,    43,     2,     2,    44,     2,    47,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,   149,   149,   152,   152,   160,   163,   168,   204,   209,
     209,   215,   218,   218,   225,   230,   233,   239,   239,   246,
     251,   255,   260,   260,   266,   271,   272,   273,   274,   275,
     278,   281,   286,   286,   289,   289,   293,   296,   299,   299,
     302,   302,   307,   307,   310,   315,   315,   318,   321,   322,
     323,   328,   328,   334,   334,   367,   367,   410,   410,   414,
     414,   419,   419,   422,   422,   431,   435,   438,   443,   448,
     448,   455,   460,   467,   505,   543,   581,   619,   626,   627,
     628,   629,   630,   631,   634,   640,   646,   652,   665,   665,
     670
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
  "TK_GE", "TK_EQ", "TK_NE", "TK_GT", "TK_LT", "TK_AND", "TK_OR",
  "TK_STRING", "TK_CHARACTER", "TK_MULTIPLY", "TK_DIVIDE", "TK_ADD",
  "TK_SUBTRACT", "'{'", "'}'", "';'", "'('", "')'", "','", "'&'", "'='",
  "'.'", "$accept", "program", "$@1", "headers", "include", "class",
  "class_defination", "$@2", "class_body", "$@3", "class_body_main",
  "method_signature", "$@4", "atributs_method", "parament_method", "$@5",
  "class_atributes", "datatype", "body", "body_statement", "$@6", "$@7",
  "$@8", "$@9", "else", "$@10", "statement_class", "$@11", "condition",
  "statement_atributes", "$@12", "statement", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "params_const", "param_const", "class_call",
  "$@19", "init", "expression", "relop", "value", "return", "$@20", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,   -20,    -8,    21,    11,    -9,   -99,    -3,   -99,   -99,
     -99,   -99,    34,    75,   -99,    18,   -99,   -99,   -99,   -99,
     -99,   -99,    27,    35,    75,    54,    44,    75,   -99,    31,
     -99,    45,   -99,    48,    47,    69,    75,    50,    31,    72,
     -99,    49,   -99,    31,   -99,   -99,   -99,   -99,   -99,    24,
     -99,    55,    58,   -99,   -99,   -99,   -99,   -99,    17,   -99,
      60,    57,    24,    24,    24,    24,    57,   -99,   -99,   -99,
     -99,    -4,   -99,    78,    91,    57,    63,    64,    65,    10,
      10,   -99,   -99,    91,    66,    67,    68,    77,    74,    88,
      87,    76,    99,   -99,   -99,    82,   -99,   -99,   -99,     7,
      49,    84,    92,    93,    52,    52,    24,   -99,   -99,   -99,
     -99,   -99,   -99,    24,   -99,   105,   -99,    49,    24,    75,
      24,    85,     7,   -99,   -99,    75,    86,    89,   -99,   -99,
      94,    88,    95,    17,    17,   -99,   -99,    90,   -99,   -99,
     -99,   -99,   -99,    98,    96,    97,    24,   101,   -99,   -99,
     -99,   108,    57,   -99,    57,   100,   102,   104,   106,   -99,
     119,   -99,   -99,   -99,   107,    57,   109,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     0,     0,     0,     2,     0,     9,     7,
       1,     3,     6,    14,    10,     0,     5,    29,    25,    26,
      27,    28,     0,     0,    14,     0,     0,    16,     8,    21,
      11,    51,    24,     0,     0,     0,     0,     0,    21,     0,
      18,    72,     4,    21,    17,    20,    12,    19,    22,     0,
      52,     0,     0,    23,    84,    85,    87,    86,    71,    77,
       0,    31,     0,     0,     0,     0,    31,    38,    40,    32,
      34,    57,    45,     0,    90,    31,     0,     0,    61,    73,
      74,    76,    75,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    88,     0,    30,    36,    37,    67,
      72,     0,     0,     0,    50,    50,     0,    80,    81,    82,
      83,    79,    78,     0,    60,     0,    46,    72,     0,    14,
       0,     0,    67,    68,    62,    14,     0,     0,    48,    49,
       0,     0,     0,    56,    58,    70,    54,     0,    13,    66,
      63,    65,    15,     0,     0,     0,     0,     0,    89,    64,
      39,     0,    31,    47,    31,     0,     0,     0,     0,    33,
      44,    41,    42,    35,     0,    31,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -99,   122,   -99,   -99,   -99,   -99,   -23,   -99,
     -99,   118,   -99,   -28,   112,   -99,   -99,   -13,   -62,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    30,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    28,    32,
     -99,   -99,   -98,   -57,    20,   -87,    70,   -99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    15,     4,     5,     6,     7,    14,    22,    52,
      33,    23,    40,    37,    38,    53,    24,    73,    74,    75,
      86,    87,    84,    85,   163,   164,    76,    92,   130,    26,
      41,    77,   117,    88,    89,    90,   100,   149,   121,   122,
      78,    91,    50,    58,   113,    59,    95,   118
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    30,   124,     8,    83,    79,    80,    81,    82,     9,
      47,    25,   123,    96,    35,    51,    39,   131,   131,   136,
     -59,    10,     1,    39,     2,    39,    11,    54,    55,    56,
      39,   137,    12,   123,    17,   123,    13,    18,    19,    20,
      21,    57,   -55,   -69,    54,    55,    56,    64,    65,   133,
       2,   120,    62,    63,    64,    65,   134,    27,    57,   153,
      17,    67,    68,    18,    19,    20,    21,    28,    69,    70,
     128,   129,    54,    55,    56,    36,    31,    29,    17,    71,
      72,    18,    19,    20,    21,    32,    57,   -17,    42,    43,
     156,    44,   157,    46,    48,    49,   138,    61,    60,    66,
      93,    94,   142,   166,    97,    98,    25,    99,   102,   103,
     104,   114,    25,   107,   108,   109,   110,   111,   112,   105,
     106,   116,   119,   115,   125,   126,   127,   135,   140,   143,
     155,   148,   162,   144,    16,   132,   152,   145,   147,   150,
     154,   151,   159,   158,   160,    34,   165,   161,    45,   167,
     141,   146,   139,   101
};

static const yytype_uint8 yycheck[] =
{
      13,    24,   100,    23,    66,    62,    63,    64,    65,    17,
      38,    24,    99,    75,    27,    43,    29,   104,   105,   117,
      24,     0,    14,    36,    16,    38,    15,    20,    21,    22,
      43,   118,    41,   120,     3,   122,    39,     6,     7,     8,
       9,    34,    46,    47,    20,    21,    22,    37,    38,   106,
      16,    44,    35,    36,    37,    38,   113,    39,    34,   146,
       3,     4,     5,     6,     7,     8,     9,    40,    11,    12,
      18,    19,    20,    21,    22,    44,    22,    42,     3,    22,
      23,     6,     7,     8,     9,    41,    34,    42,    40,    42,
     152,    22,   154,    43,    22,    46,   119,    39,    43,    39,
      22,    10,   125,   165,    41,    41,   119,    42,    42,    42,
      42,    24,   125,    25,    26,    27,    28,    29,    30,    42,
      46,    22,    40,    47,    40,    33,    33,    22,    43,    43,
      22,    41,    13,    44,    12,   105,    39,    43,    43,    41,
      39,    45,    40,    43,    40,    27,    39,    41,    36,    40,
     122,   131,   120,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    16,    49,    51,    52,    53,    54,    23,    17,
       0,    15,    41,    39,    55,    50,    51,     3,     6,     7,
       8,     9,    56,    59,    64,    65,    77,    39,    40,    42,
      56,    22,    41,    58,    59,    65,    44,    61,    62,    65,
      60,    78,    40,    42,    22,    62,    43,    61,    22,    46,
      90,    61,    57,    63,    20,    21,    22,    34,    91,    93,
      43,    39,    35,    36,    37,    38,    39,     4,     5,    11,
      12,    22,    23,    65,    66,    67,    74,    79,    88,    91,
      91,    91,    91,    66,    70,    71,    68,    69,    81,    82,
      83,    89,    75,    22,    10,    94,    66,    41,    41,    42,
      84,    94,    42,    42,    42,    42,    46,    25,    26,    27,
      28,    29,    30,    92,    24,    47,    22,    80,    95,    40,
      44,    86,    87,    93,    90,    40,    33,    33,    18,    19,
      76,    93,    76,    91,    91,    22,    90,    93,    56,    87,
      43,    86,    56,    43,    44,    43,    92,    43,    41,    85,
      41,    45,    39,    93,    39,    22,    66,    66,    43,    40,
      40,    41,    13,    72,    73,    39,    66,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    49,    51,    51,    52,    53,    55,
      54,    56,    57,    56,    56,    58,    58,    60,    59,    61,
      61,    61,    63,    62,    64,    65,    65,    65,    65,    65,
      66,    66,    68,    67,    69,    67,    67,    67,    70,    67,
      71,    67,    73,    72,    72,    75,    74,    76,    76,    76,
      76,    78,    77,    80,    79,    81,    79,    82,    79,    83,
      79,    84,    79,    85,    79,    86,    86,    86,    87,    89,
      88,    90,    90,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    95,    94,
      94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     6,     3,     0,     2,     4,     0,
       3,     2,     0,    10,     0,     9,     0,     0,     3,     2,
       2,     0,     0,     3,     2,     1,     1,     1,     1,     1,
       2,     0,     0,     8,     0,     9,     2,     2,     0,     6,
       0,     9,     0,     5,     0,     0,     3,     3,     1,     1,
       0,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       3,     0,     3,     0,     5,     2,     2,     0,     1,     0,
       4,     2,     0,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       0
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
  case 2: /* program: class  */
#line 149 "sintatico.y"
               {
    class_aux = (yyvsp[0].nd_obj).nd;
}
#line 1534 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 152 "sintatico.y"
                                   { class_scope_count++; add('Z'); }
#line 1540 "y.tab.c"
    break;

  case 4: /* program: headers TK_CLASS_DEFINITION_MAIN $@1 '{' class_body_main '}'  */
#line 152 "sintatico.y"
                                                                                               { 
    (yyvsp[-4].nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "main_class"); 
    (yyval.nd_obj).nd = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-4].nd_obj).nd, "program"); 
    princial_bool = 1;
    head = (yyval.nd_obj).nd; 
}
#line 1551 "y.tab.c"
    break;

  case 5: /* headers: include ';' headers  */
#line 160 "sintatico.y"
                             { 
    // $$.nd = mknode($1.nd, $3.nd, "headers");
}
#line 1559 "y.tab.c"
    break;

  case 6: /* headers: %empty  */
#line 163 "sintatico.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1567 "y.tab.c"
    break;

  case 7: /* include: TK_INCLUDE TK_INCLUDE_CLASS  */
#line 168 "sintatico.y"
                                     {
    FILE *fp = fopen((yyvsp[0].nd_obj).name, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", (yyvsp[0].nd_obj).name);
        exit(EXIT_FAILURE);
    }

    /* Inclui o arquivo e atualiza o rastreador de arquivos incluídos */
    include_file((yyvsp[0].nd_obj).name);

    /* Lógica de processamento do arquivo incluído */
    yyin = fp;
    strcpy(file_name_current, (yyvsp[0].nd_obj).name);
    count_lines = 1;
    countn = 1;

    struct tree_class_l *class_act = create_tree_class_l(file_name_current);
    class_act->head = class_aux;
    if (head_class_l == NULL) {
        head_class_l = class_act;
    } else {
        class_act->next = head_class_l;
        head_class_l = class_act;
    }
    class_aux = NULL;

    yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));
    printf("%s\n", (yyvsp[0].nd_obj).name);
    yyparse();

    /* Desfaz a inclusão do arquivo e restaura o rastreador de arquivos incluídos */
    undo_include();
    fclose(fp);
}
#line 1606 "y.tab.c"
    break;

  case 8: /* class: class_defination '{' class_body '}'  */
#line 204 "sintatico.y"
                                           {
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "class");
}
#line 1614 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 209 "sintatico.y"
                                                    { class_scope_count++; add('Z'); }
#line 1620 "y.tab.c"
    break;

  case 10: /* class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME $@2  */
#line 209 "sintatico.y"
                                                                                       { 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "class"); 
    class_name_current = strdup((yyvsp[-1].nd_obj).name);
}
#line 1629 "y.tab.c"
    break;

  case 11: /* class_body: class_atributes class_body  */
#line 215 "sintatico.y"
                                       { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "class_body"); 
}
#line 1637 "y.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 218 "sintatico.y"
                                            {
    symbol_table[method_current].num_param = param_count;
    param_count = 0;
}
#line 1646 "y.tab.c"
    break;

  case 13: /* class_body: method_signature '(' atributs_method ')' $@3 '{' body return '}' class_body  */
#line 221 "sintatico.y"
                                 {
    struct node *aux_class = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj).nd, "class_body");
    (yyval.nd_obj).nd = mknode(aux_class, (yyvsp[-2].nd_obj).nd, "method");
}
#line 1655 "y.tab.c"
    break;

  case 14: /* class_body: %empty  */
#line 225 "sintatico.y"
  { 
    (yyval.nd_obj).nd = NULL; 
}
#line 1663 "y.tab.c"
    break;

  case 15: /* class_body_main: method_signature '(' atributs_method ')' '{' body return '}' class_body  */
#line 230 "sintatico.y"
                                                                                         {
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "method2");
}
#line 1671 "y.tab.c"
    break;

  case 16: /* class_body_main: %empty  */
#line 233 "sintatico.y"
  { 
    (yyval.nd_obj).nd = NULL; 
}
#line 1679 "y.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 239 "sintatico.y"
                                 { scope_count++; add('F'); }
#line 1685 "y.tab.c"
    break;

  case 18: /* method_signature: datatype TK_ID $@4  */
#line 239 "sintatico.y"
                                                              {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
    method_current = count-1;
}
#line 1694 "y.tab.c"
    break;

  case 19: /* atributs_method: parament_method atributs_method  */
#line 246 "sintatico.y"
                                                 {
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "parameter");
    param_count++;

}
#line 1704 "y.tab.c"
    break;

  case 20: /* atributs_method: ',' parament_method  */
#line 251 "sintatico.y"
                      {
    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "parameter");
    param_count++;
}
#line 1713 "y.tab.c"
    break;

  case 21: /* atributs_method: %empty  */
#line 255 "sintatico.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1721 "y.tab.c"
    break;

  case 22: /* $@5: %empty  */
#line 260 "sintatico.y"
                                { add('P'); }
#line 1727 "y.tab.c"
    break;

  case 23: /* parament_method: datatype TK_ID $@5  */
#line 260 "sintatico.y"
                                              {
    (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "parameter");  
}
#line 1736 "y.tab.c"
    break;

  case 24: /* class_atributes: statement_atributes ';'  */
#line 266 "sintatico.y"
                                         {
    (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
}
#line 1744 "y.tab.c"
    break;

  case 25: /* datatype: TK_TYPE_INT  */
#line 271 "sintatico.y"
                      { insert_type(); }
#line 1750 "y.tab.c"
    break;

  case 26: /* datatype: TK_TYPE_FLOAT  */
#line 272 "sintatico.y"
                { insert_type(); }
#line 1756 "y.tab.c"
    break;

  case 27: /* datatype: TK_TYPE_CHAR  */
#line 273 "sintatico.y"
               { insert_type(); }
#line 1762 "y.tab.c"
    break;

  case 28: /* datatype: TK_TYPE_STRING  */
#line 274 "sintatico.y"
                 { insert_type(); }
#line 1768 "y.tab.c"
    break;

  case 29: /* datatype: TK_VOID  */
#line 275 "sintatico.y"
          { insert_type(); }
#line 1774 "y.tab.c"
    break;

  case 30: /* body: body_statement body  */
#line 278 "sintatico.y"
                          { 
    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement_body"); 
}
#line 1782 "y.tab.c"
    break;

  case 31: /* body: %empty  */
#line 281 "sintatico.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1790 "y.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 286 "sintatico.y"
                       { add('K'); }
#line 1796 "y.tab.c"
    break;

  case 33: /* body_statement: TK_FOR $@6 '(' condition ')' '{' body '}'  */
#line 286 "sintatico.y"
                                                                    {
    (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-7].nd_obj).name);
}
#line 1804 "y.tab.c"
    break;

  case 34: /* $@7: %empty  */
#line 289 "sintatico.y"
        { add('K'); }
#line 1810 "y.tab.c"
    break;

  case 35: /* body_statement: TK_IF $@7 '(' condition ')' '{' body '}' else  */
#line 289 "sintatico.y"
                                                          {
    struct node *iff = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-8].nd_obj).name);
    (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else");
}
#line 1819 "y.tab.c"
    break;

  case 36: /* body_statement: statement_class ';'  */
#line 293 "sintatico.y"
                      {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
}
#line 1827 "y.tab.c"
    break;

  case 37: /* body_statement: statement ';'  */
#line 296 "sintatico.y"
                {
    (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
}
#line 1835 "y.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 299 "sintatico.y"
            { add('K'); }
#line 1841 "y.tab.c"
    break;

  case 39: /* body_statement: TK_PRINTF $@8 '(' TK_STRING ')' ';'  */
#line 299 "sintatico.y"
                                                {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
}
#line 1849 "y.tab.c"
    break;

  case 40: /* $@9: %empty  */
#line 302 "sintatico.y"
           { add('K'); }
#line 1855 "y.tab.c"
    break;

  case 41: /* body_statement: TK_SCANF $@9 '(' TK_STRING ',' '&' TK_ID ')' ';'  */
#line 302 "sintatico.y"
                                                             {
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj).name);
}
#line 1863 "y.tab.c"
    break;

  case 42: /* $@10: %empty  */
#line 307 "sintatico.y"
              { add('K'); }
#line 1869 "y.tab.c"
    break;

  case 43: /* else: TK_ELSE $@10 '{' body '}'  */
#line 307 "sintatico.y"
                                         {
    (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).name);
}
#line 1877 "y.tab.c"
    break;

  case 44: /* else: %empty  */
#line 310 "sintatico.y"
  { 
    (yyval.nd_obj).nd = NULL;
}
#line 1885 "y.tab.c"
    break;

  case 45: /* $@11: %empty  */
#line 315 "sintatico.y"
                               { insert_type(); }
#line 1891 "y.tab.c"
    break;

  case 46: /* statement_class: TK_CLASS_NAME $@11 TK_ID  */
#line 315 "sintatico.y"
                                                        { add('O'); }
#line 1897 "y.tab.c"
    break;

  case 47: /* condition: value relop value  */
#line 318 "sintatico.y"
                             {
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
}
#line 1905 "y.tab.c"
    break;

  case 48: /* condition: TK_TRUE  */
#line 321 "sintatico.y"
          { add('K'); (yyval.nd_obj).nd = NULL; }
#line 1911 "y.tab.c"
    break;

  case 49: /* condition: TK_FALSE  */
#line 322 "sintatico.y"
           { add('K'); (yyval.nd_obj).nd = NULL; }
#line 1917 "y.tab.c"
    break;

  case 50: /* condition: %empty  */
#line 323 "sintatico.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 1925 "y.tab.c"
    break;

  case 51: /* $@12: %empty  */
#line 328 "sintatico.y"
                                    { add('A'); }
#line 1931 "y.tab.c"
    break;

  case 52: /* statement_atributes: datatype TK_ID $@12 init  */
#line 328 "sintatico.y"
                                                        {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "atribute");  
}
#line 1940 "y.tab.c"
    break;

  case 53: /* $@13: %empty  */
#line 334 "sintatico.y"
                          { check_declaration_previously((yyvsp[0].nd_obj).name); add('V'); }
#line 1946 "y.tab.c"
    break;

  case 54: /* statement: datatype TK_ID $@13 init  */
#line 334 "sintatico.y"
                                                                                    {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    int t = check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).type);  
    if(t > 0) {
        if(t == 1) {    
            struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "decimal_para_inteiro");
            (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration");   
        }   
        else if(t == 2) {
            struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
            (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration");   
        }   
        else if(t == 3) {    
            struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_inteiro");
            (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration");   
        }   
        else if(t == 4) {    
            struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_caracter");
            (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration");   
        }   
        else if(t == 5) {    
            struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_decimal");
            (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration");   
        }   
        else {   
            struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "decimal_para_caracter");
            (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration");   
        }
    }
    else {   
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "declaration");  
    } 
}
#line 1984 "y.tab.c"
    break;

  case 55: /* $@14: %empty  */
#line 367 "sintatico.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 1990 "y.tab.c"
    break;

  case 56: /* statement: TK_ID $@14 '=' expression  */
#line 367 "sintatico.y"
                                                        {
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name); 
    char *id_type = get_type((yyvsp[-3].nd_obj).name); 
    if (id_type != NULL) {
        if(strcmp(id_type, (yyvsp[0].nd_obj2).type)) {
            if(!strcmp(id_type, "inteiro")) {
                if(!strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
                    struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "decimal_para_inteiro");
                    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
                }
                else {
                    struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_inteiro");
                    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
                }
                
            }
            else if(!strcmp(id_type, "decimal")) {
                if(!strcmp((yyvsp[0].nd_obj2).type, "inteiro")){
                    struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
                    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
                }
                else{
                    struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_decimal");
                    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
                }
                
            }
            else {
                if(!strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
                    struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_caracter");
                    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
                }
                else {
                    struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "decimal_para_caracter");
                    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
                }
            }
        }
        else {
            (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "="); 
        }
	}
}
#line 2038 "y.tab.c"
    break;

  case 57: /* $@15: %empty  */
#line 410 "sintatico.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 2044 "y.tab.c"
    break;

  case 58: /* statement: TK_ID $@15 relop expression  */
#line 410 "sintatico.y"
                                                         {
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
}
#line 2053 "y.tab.c"
    break;

  case 59: /* $@16: %empty  */
#line 414 "sintatico.y"
        { check_declaration((yyvsp[0].nd_obj).name); }
#line 2059 "y.tab.c"
    break;

  case 60: /* statement: TK_ID $@16 TK_UNARY  */
#line 414 "sintatico.y"
                                                 {
    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
    (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "iterator");
}
#line 2069 "y.tab.c"
    break;

  case 61: /* $@17: %empty  */
#line 419 "sintatico.y"
             { check_atribute((yyvsp[0].nd_obj).nd->left->token, (yyvsp[0].nd_obj).nd->right->token); }
#line 2075 "y.tab.c"
    break;

  case 62: /* statement: class_call $@17 init  */
#line 419 "sintatico.y"
                                                                               {
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, ".");
}
#line 2083 "y.tab.c"
    break;

  case 63: /* $@18: %empty  */
#line 422 "sintatico.y"
                                  { 
    check_method((yyvsp[-3].nd_obj).nd->left->token, (yyvsp[-3].nd_obj).nd->right->token, param_count, head_params_l); 
    free_l_param(&head_params_l);
}
#line 2092 "y.tab.c"
    break;

  case 64: /* statement: class_call '(' params_const ')' $@18  */
#line 425 "sintatico.y"
  {
    (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "call_method");
    param_count = 0;
}
#line 2101 "y.tab.c"
    break;

  case 65: /* params_const: param_const params_const  */
#line 431 "sintatico.y"
                                       {
    param_count++;

}
#line 2110 "y.tab.c"
    break;

  case 66: /* params_const: ',' param_const  */
#line 435 "sintatico.y"
                  {
    param_count++;
}
#line 2118 "y.tab.c"
    break;

  case 67: /* params_const: %empty  */
#line 438 "sintatico.y"
  {
    (yyval.nd_obj).nd = NULL;
}
#line 2126 "y.tab.c"
    break;

  case 68: /* param_const: value  */
#line 443 "sintatico.y"
                   {
    insert_at_end_l_param(&head_params_l, (yyvsp[0].nd_obj2).type);
}
#line 2134 "y.tab.c"
    break;

  case 69: /* $@19: %empty  */
#line 448 "sintatico.y"
                  { check_declaration((yyvsp[0].nd_obj).name); }
#line 2140 "y.tab.c"
    break;

  case 70: /* class_call: TK_ID $@19 '.' TK_ID  */
#line 448 "sintatico.y"
                                                            {
    struct node *aux_left = mknode((yyvsp[-3].nd_obj).nd, NULL, (yyvsp[-3].nd_obj).name); 
    struct node *aux_right = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[0].nd_obj).name); 
    (yyval.nd_obj).nd = mknode(aux_left, aux_right, "call"); 
}
#line 2150 "y.tab.c"
    break;

  case 71: /* init: '=' expression  */
#line 455 "sintatico.y"
                     { 
    (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; 
    sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name);
}
#line 2160 "y.tab.c"
    break;

  case 72: /* init: %empty  */
#line 460 "sintatico.y"
  { 
    sprintf((yyval.nd_obj2).type, "null"); 
    (yyval.nd_obj2).nd = mknode(NULL, NULL, "NULL"); 
    strcpy((yyval.nd_obj2).name, "NULL"); 
}
#line 2170 "y.tab.c"
    break;

  case 73: /* expression: expression TK_MULTIPLY expression  */
#line 467 "sintatico.y"
                                              { 
    if(!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
        sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	}
	else {
		if(!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "caracter")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_inteiro");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "caracter") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "caracter_para_inteiro");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "caracter")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_decimal");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "caracter_para_decimal");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
	}
}
#line 2213 "y.tab.c"
    break;

  case 74: /* expression: expression TK_DIVIDE expression  */
#line 505 "sintatico.y"
                                  {
    if(!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
        sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	}
	else {
		if(!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "caracter")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_inteiro");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "caracter") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "caracter_para_inteiro");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "caracter")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_decimal");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "caracter_para_decimal");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
	} 
}
#line 2256 "y.tab.c"
    break;

  case 75: /* expression: expression TK_SUBTRACT expression  */
#line 543 "sintatico.y"
                                    {
    if(!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
        sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	}
	else {
		if(!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "caracter")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_inteiro");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "caracter") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "caracter_para_inteiro");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "caracter")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_decimal");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "caracter_para_decimal");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
	} 
}
#line 2299 "y.tab.c"
    break;

  case 76: /* expression: expression TK_ADD expression  */
#line 581 "sintatico.y"
                               {
    if(!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
        sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	}
	else {
		if(!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "decimal")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inteiro_para_decimal");
            sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "inteiro") && !strcmp((yyvsp[0].nd_obj2).type, "caracter")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_inteiro");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "caracter") && !strcmp((yyvsp[0].nd_obj2).type, "inteiro")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "caracter_para_inteiro");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "decimal") && !strcmp((yyvsp[0].nd_obj2).type, "caracter")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "caracter_para_decimal");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "caracter_para_decimal");
			sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
	} 
}
#line 2342 "y.tab.c"
    break;

  case 77: /* expression: value  */
#line 619 "sintatico.y"
        { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name); 
    sprintf((yyval.nd_obj2).type, "%s", (yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; 
}
#line 2352 "y.tab.c"
    break;

  case 84: /* value: TK_NUMBER  */
#line 634 "sintatico.y"
                 { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "inteiro");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
    add('C'); 
}
#line 2363 "y.tab.c"
    break;

  case 85: /* value: TK_NUMBER_FLOAT  */
#line 640 "sintatico.y"
                  { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "decimal");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
    add('C'); 
}
#line 2374 "y.tab.c"
    break;

  case 86: /* value: TK_CHARACTER  */
#line 646 "sintatico.y"
               { 
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    sprintf((yyval.nd_obj2).type, "%s", "caracter");
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
    add('C'); 
}
#line 2385 "y.tab.c"
    break;

  case 87: /* value: TK_ID  */
#line 652 "sintatico.y"
        {
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); 
    char *id_type = get_type((yyvsp[0].nd_obj).name); 
    if(id_type == NULL) {
        sprintf((yyval.nd_obj2).type, "%s", "NULL"); 
    } else {
        sprintf((yyval.nd_obj2).type, "%s", id_type); 
    }
    check_declaration((yyvsp[0].nd_obj).name); 
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
}
#line 2401 "y.tab.c"
    break;

  case 88: /* $@20: %empty  */
#line 665 "sintatico.y"
                  { add('R'); }
#line 2407 "y.tab.c"
    break;

  case 89: /* return: TK_RETURN $@20 value ';'  */
#line 665 "sintatico.y"
                                          { 
    function_check_return((yyvsp[-1].nd_obj2).name); 
    (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return"); 
    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj2).nd, "RETURN"); 
}
#line 2417 "y.tab.c"
    break;

  case 90: /* return: %empty  */
#line 670 "sintatico.y"
  { 
    (yyval.nd_obj).nd = NULL; 
    function_return = NULL;
    function_check_return("NULL");
}
#line 2427 "y.tab.c"
    break;


#line 2431 "y.tab.c"

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

#line 677 "sintatico.y"


int main(int argc, char **argv)
{
    int i;

    if(argc >= 2) {
        for (i = 1; i < argc; i++) {
            strcpy(file_name_current, argv[i]);
            FILE *fp = fopen(argv[i], "r");
            count_lines = 1;
            countn = 1;
            if (fp == NULL) {
                printf("Error: could not open file %s\n", argv[i]);
                return 1;
            }

            yyin = fp;

            yyparse();

            fclose(fp);
            if(!princial_bool) {
                struct tree_class_l *class_act = create_tree_class_l(argv[i]);
                class_act->head = class_aux;
                if(head_class_l == NULL) {
                    head_class_l = class_act;
                }else {
                    class_act->next = head_class_l;
                    head_class_l = class_act;
                }
                class_aux = NULL;
            }
        }
        print_symbol_table();

        for (i = 0; i < count; i++) {
            free(symbol_table[i].id_name);
            free(symbol_table[i].type);
        }

        struct tree_class_l *aux;

        printf("\n\n");
        printf("FASE 2: ANALISE SINTATICA\n\n");
        aux = head_class_l;
        if(aux != NULL) {
            while(aux != NULL) {
                printf("\nArquivo: %s\n", aux->file_name);
                printtree(aux->head);
                aux = aux->next;
            }
        }
        if(head != NULL) {
            printtree(head);
        }
        
        printf("\n\n");
        printf("FASE 3: ANALISE SEMANTICA \n\n");
        if(sem_errors>0) {
            printf("Análise semântica concluída com %d erros\n", sem_errors);
            for(int i = 0; i < sem_errors; i++){
                printf("%s", errors[i]);
            }
        } else {
            printf("Análise semântica concluída sem erros");
        }
        printf("\n\n");
    }

    return 0;
}

void print_symbol_table()
{
    printf("\n\nTABELA DE SIMBOLOS:\n\n");
    printf("%-25s |%-20s |%-15s |%-15s |%-7s | %s|  %s |%-20s\n", "IDENTIFICADOR", "TIPO DE DADO", "TIPO", "CLASSE", "LINHA", "C_S", "S", "ARQUIVO");
    char aux_line[10];
    for (int i = 0; i < count; i++)
    {
        sprintf(aux_line, "%5d", symbol_table[i].line_no);
        printf("%-25s |%-20s |%-15s |%-15s |%-7s |%3d |%3d |%-20s \n", symbol_table[i].id_name, symbol_table[i].data_type,
               symbol_table[i].type, symbol_table[i].class_name, aux_line, symbol_table[i].class_scope, symbol_table[i].scope, symbol_table[i].file_name);
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
    if(strlen(tree->token) > 0) {
    	printf("%s, ", tree->token);
    }
	if (tree->right) {
		printInorder(tree->right);
	}
}

void insert_type() {
    strcpy(type, yytext);
}

void function_check_return(const char *value) {
	char *function_datatype = get_type(symbol_table[count-1].data_type);
    if(!strcmp(value, "NULL")) {
        printf("\n\nTESTE: %s\n\n", value);
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Falta um retorno\n", countn, file_name_current);
        return;
    }
    char *return_datatype = get_type(value);

    if(function_datatype != NULL && return_datatype != NULL) {

        if (return_datatype == NULL || (!strcmp(function_datatype, "inteiro") && !strcmp(return_datatype, "CONST")) || !strcmp(function_datatype, return_datatype)) {
            return;
        }

        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo de retorno\n", countn, file_name_current);
    }
}

int check_types(const char *type1, const char *type2){
	if(!strcmp(type2, "null"))
		return -1;

	if(!strcmp(type1, type2))
		return 0;

	if(!strcmp(type1, "inteiro") && !strcmp(type2, "decimal"))
		return 1;
	if(!strcmp(type1, "decimal") && !strcmp(type2, "inteiro"))
		return 2;
	if(!strcmp(type1, "inteiro") && !strcmp(type2, "caracter"))
		return 3;
	if(!strcmp(type1, "caracter") && !strcmp(type2, "inteiro"))
		return 4;
	if(!strcmp(type1, "decimal") && !strcmp(type2, "caracter"))
		return 5;
	if(!strcmp(type1, "caracter") && !strcmp(type2, "decimal"))
		return 6;
    return -1;
}

struct tree_class_l* create_tree_class_l(char *file_name) {
    struct tree_class_l *new_tree = (struct tree_class_l*)malloc(sizeof(struct tree_class_l));
    if (new_tree == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a estrutura tree_class_l\n");
        exit(EXIT_FAILURE);
    }

    new_tree->head = NULL;
    new_tree->file_name = strdup(file_name);
    if (new_tree->file_name == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nome do arquivo\n");
        free(new_tree);
        exit(EXIT_FAILURE);
    }

    new_tree->next = NULL;

    return new_tree;
}

void free_tree_class_l(struct tree_class_l *tree) {
    if (tree != NULL) {
        free(tree->file_name);
        free(tree);
    }
}

void check_declaration(const char *c) {    
    q = search(c, class_scope_count, scope_count);
    if(!q) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: \"%s\" não foi declarada!\n", countn, file_name_current, c);  
    }
}

void check_declaration_previously(const char *c) {    
    q = search(c, class_scope_count, scope_count);
    if(!q) return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: \"%s\" já foi declarada anteriormente!\n", countn, file_name_current, c);  
}

void check_atribute(const char *object, const char *atribute) {

    int i; 
    char *class_name_target;
    for(i = count-1; i >= 0; i--) {
        if(strcmp(symbol_table[i].id_name, object) == 0) {   
            class_name_target = strdup(symbol_table[i].data_type);
            break;
        }
    }
    for(i = count-1; i >= 0; i--) {
        if((strcmp(symbol_table[i].class_name, class_name_target) == 0) && (strcmp(symbol_table[i].id_name, atribute) == 0)) {   
            return;
        }
    }
    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O atributo %s não existe na classe %s\n", countn, file_name_current, atribute, class_name_target);
}

void check_method(const char *object, const char *method, int num_param_call, struct param_types *head) {
    int i, j; 
    char *class_name_target;
    for(i = count-1; i >= 0; i--) {
        if(strcmp(symbol_table[i].id_name, object) == 0) {   
            class_name_target = strdup(symbol_table[i].data_type);
            break;
        }
    }
    for(i = count-1; i >= 0; i--) {
        if((strcmp(symbol_table[i].class_name, class_name_target) == 0) && (strcmp(symbol_table[i].id_name, method) == 0)) {   
            if (symbol_table[i].num_param != num_param_call) {
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s espera %d parametros e recebeu %d\n", countn, file_name_current, method, symbol_table[i].num_param, num_param_call);
            }
            int count_paran_index = 1;
            struct param_types *temp = head;
            for(j = i+1; j <= i+num_param_call; j++) {
                if (temp != NULL) {
                    if((strcmp(symbol_table[j].data_type, temp->type) != 0)) {
                        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O parametro de número %d, não é do tipo esperado\n", countn, file_name_current, count_paran_index);
                    }
                    temp = temp->next;
                    count_paran_index++;
                }
            }
            return;
        }
    }
    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s não existe na classe %s\n", countn, file_name_current, method, class_name_target);
}

char *get_type(const char *var){
	for(int i = 0; i < count; i++) {
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}

void add(char c) {
    q = search(yytext, class_scope_count, scope_count);
    if(!q) {
        if(c == 'H') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);    
            symbol_table[count].data_type=strdup(yylval.nd_obj.name);     
            symbol_table[count].line_no=countn;    
            symbol_table[count].type=strdup("Header");
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  
        else if(c == 'K') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Keyword");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if(c == 'V') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Variable");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if(c == 'C') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("CONST");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Constant");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if(c == 'F') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            function_return=strdup(yylval.nd_obj.name);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Function");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'Z') {
            class_name_current = strdup(yylval.nd_obj.name);
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(yylval.nd_obj.name);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Class");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'O') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Object");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'A') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Attribute");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'X') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Vector");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'P') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Parameter");   
            symbol_table[count].file_name=strdup(file_name_current);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'R') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(function_return);
            function_return = NULL;
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Return");   
            symbol_table[count].file_name=strdup(file_name_current);
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
        if(strcmp(symbol_table[i].id_name, type) == 0 && symbol_table[i].class_scope == cl_scope && strcmp(symbol_table[i].type, "Attribute") == 0) {
            aux_return = 1;
            break;
        }
    }
    if(!aux_return) {
        for(i = count-1; i >= 0; i--) {
            if(strcmp(symbol_table[i].id_name, type) == 0 && symbol_table[i].scope == f_scope) {
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
    fprintf(stderr, "Erro sintático na linha %d, arquivo %s: %s   %s\n", countn, file_name_current, msg, yytext);
}
