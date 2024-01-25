%{
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
%}

%union { struct var_name { 
			char name[100]; 
			struct node* nd;
		} nd_obj;
}
%token TK_VOID
%token <nd_obj> TK_PRINTF TK_SCANF TK_TYPE_INT TK_TYPE_FLOAT TK_TYPE_CHAR TK_TYPE_STRING TK_RETURN TK_FOR TK_IF TK_ELSE TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN TK_INCLUDE TK_TRUE TK_FALSE TK_NUMBER TK_NUMBER_FLOAT TK_ID TK_CLASS_NAME TK_UNARY TK_LE TK_GE TK_EQ TK_NE TK_GT TK_LT TK_AND TK_OR TK_ADD TK_SUBTRACT TK_DIVIDE TK_MULTIPLY TK_STRING TK_CHARACTER

%%

program: headers program
| class program 
| main_class program
|
;

class: class_defination '{' class_body '}' { printf("Classe\n"); }
| headers TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN program
;

main_class: main_class_defination '{' class_body '}'
/* | headers TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN program */
;

class_body: class_atributes class_body
| class_method class_body
|
;

class_method: datatype TK_ID '(' atributs_method ')' '{' body return '}' { printf("Teste!!\n"); }
;

atributs_method: datatype TK_ID ',' atributs_method { printf("atributo1!\n"); }
| datatype TK_ID { printf("atributo2!\n"); }
/* | atributs_method */
|
;

class_atributes: statement_atributes ';' { printf("Atributo da classe!\n"); }
;

class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME { printf("Classe!\n"); }
;

main_class_defination: TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN { printf("Classe princiapl!\n"); }
;

headers: TK_INCLUDE { printf("Header!\n"); }
;

datatype: TK_TYPE_INT 
| TK_TYPE_FLOAT 
| TK_TYPE_CHAR
| TK_TYPE_STRING
| TK_VOID
;

body: TK_FOR '(' statement ';' condition ';' statement ')' '{' body '}'
| TK_IF '(' condition ')' '{' body '}' else
| statement ';' 
| statement_class ';'
| TK_PRINTF '(' TK_STRING ')' ';'
| body body
| TK_SCANF '(' TK_STRING ',' '&' TK_ID ')' ';'
;

statement_class: TK_CLASS_NAME TK_ID '=' TK_CLASS_NAME '(' ')'
;

else: TK_ELSE '{' body '}'
|
;

condition: value relop value 
| TK_TRUE 
| TK_FALSE
;

statement_atributes: datatype TK_ID init 
;

statement: datatype TK_ID 
| datatype TK_ID init 
| TK_ID '=' expression 
| TK_ID relop expression
| TK_ID TK_UNARY 
| TK_UNARY TK_ID
| TK_ID '.' TK_ID init
;

init: '=' value 
| '=' expression
|
;

expression: expression arithmetic expression
| '(' expression ')'
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

void insert_type() {
    strcpy(type, yytext);
}

void add(char c) {
    q=search(yytext);
    if(!q) {
        if(c == 'H') {
            symbol_table[count].id_name=strdup(yytext);        
            symbol_table[count].data_type=strdup(type);     
            symbol_table[count].line_no=countn;    
            symbol_table[count].type=strdup("Header");
            count++;  
        }  
        else if(c == 'K') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Keyword\t");   
            count++;  
        }  else if(c == 'V') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Variable");   
            count++;  
        }  else if(c == 'C') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup("CONST");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Constant");   
            count++;  
        }  else if(c == 'F') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Function");   
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

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}