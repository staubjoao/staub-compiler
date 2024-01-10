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
%token TK_NUMBER
%token TK_FLOAT_NUM
%token TK_ID
%token TK_CLASS_NAME
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

%% 

declaration: datatype TK_ID '=' value
| datatype TK_ID
;
datatype: TK_TYPE_INT
| TK_TYPE_FLOAT
| TK_TYPE_CHAR
;
value: TK_NUMBER
| TK_FLOAT_NUM
| TK_CHAR
;

%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}