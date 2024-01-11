%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
%}

%union {
    int intval;
    char* strval;
}

%token TK_MAIN TK_PRINTF
%token TK_SCANFF
%token TK_TYPE_INT
%token TK_TYPE_FLOAT
%token TK_TYPE_CHAR
%token TK_TYPE_STRING
%token TK_VOID
%token TK_RETURN
%token TK_WHILE
%token TK_IF
%token TK_ELSE
%token TK_CLASS
%token TK_INCLUDE
%token <intval> TK_NUMBER
%token TK_FLOAT_NUM
%token TK_ID
%token TK_CLASS_NAME
%token TK_METHOD_NAME
%token TK_UNARY
%token TK_LE
%token TK_GE
%token TK_EQ
%token TK_NE
%token TK_GT
%token TK_LT
%token TK_AND
%token TK_OR
%token TK_ADD
%token TK_SUBTRACT
%token TK_DIVIDE
%token TK_MULTIPLY
%token TK_STRING
%token TK_CHAR

%type <intval> line expr term type_decl_int

/* 

%type <strval> assignment 

*/

%% 

program: line
| program line
;

line: type_decl_int
| TK_PRINTF expr ';' { printf("%d\n", $2); }
| TK_PRINTF TK_NUMBER ';' { printf("%d\n", $2); }
/* | assignment ';' { ; }
| TK_PRINTF expr ';' { printf("%d\n", $2); }
| line TK_PRINTF expr ';' { printf("%d\n", $3); }
| term ';' { ; }  */
;


type_decl_int: 
TK_TYPE_INT TK_ID '=' TK_NUMBER ';' { printf("declarou com valor\n"); }
| TK_TYPE_INT TK_ID ';' { printf("declarou sem valor\n"); }
;

expr: term
| expr TK_ADD term { $$ = $1 + $3; { printf("%d\n", $1); } }
| expr TK_SUBTRACT term { $$ = $1 - $3; } 
| expr TK_MULTIPLY term { $$ = $1 * $3; } 
;

term: TK_NUMBER { $$ = $1; }
/* | TK_ID { printf("[Parser] indentifier: %s\n", $1);}  */
;

/* assignment: TK_ID '=' expr
;

 */

%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}