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

%union { struct var_name { 
			char name[100]; 
			struct node* nd;
		} nd_obj;
}
%token TK_VOID
%token <nd_obj> TK_PRINTF TK_SCANF TK_TYPE_INT TK_TYPE_FLOAT TK_TYPE_CHAR TK_RETURN TK_FOR TK_IF TK_ELSE TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN TK_INCLUDE TK_TRUE TK_FALSE TK_NUMBER TK_NUMBER_FLOAT TK_ID TK_CLASS_NAME TK_UNARY TK_LE TK_GE TK_EQ TK_NE TK_GT TK_LT TK_AND TK_OR TK_ADD TK_SUBTRACT TK_DIVIDE TK_MULTIPLY TK_STRING TK_CHARACTER

%%

class: headers TK_CLASS_DEFINITION TK_CLASS_NAME '{'  '}'
| headers TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN program
;

program: main '(' ')' '{' body return '}'
;

headers: headers headers
| TK_INCLUDE
;

main: datatype TK_ID
;

datatype: TK_TYPE_INT 
| TK_TYPE_FLOAT 
| TK_TYPE_CHAR
| TK_VOID
;

body: TK_FOR '(' statement ';' condition ';' statement ')' '{' body '}'
| TK_IF '(' condition ')' '{' body '}' else
| statement ';' 
| body body
| TK_PRINTF '(' TK_STRING ')' ';'
| TK_SCANF '(' TK_STRING ',' '&' TK_ID ')' ';'
;

else: TK_ELSE '{' body '}'
|
;

condition: value relop value 
| TK_TRUE 
| TK_FALSE
;

statement: datatype TK_ID init 
| TK_ID '=' expression 
| TK_ID relop expression
| TK_ID TK_UNARY 
| TK_UNARY TK_ID
;

init: '=' value 
|
;

expression: expression arithmetic expression
| value
;

arithmetic: TK_ADD 
| TK_SUBTRACT 
| TK_MULTIPLY
| TK_DIVIDE
;

relop: TK_LT
| TK_GT
| TK_LE
| TK_GE
| TK_EQ
| TK_NE
;

value: TK_NUMBER
| TK_NUMBER_FLOAT
| TK_CHARACTER
| TK_ID
;

return: TK_RETURN value ';' 
|
;

%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}