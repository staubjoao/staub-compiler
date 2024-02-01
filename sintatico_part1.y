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
%}

%union {

struct var_name { 
	char name[100]; 
	struct node* nd;
} nd_obj;

}
%token TK_VOID
%token <nd_obj> TK_PRINTF TK_SCANF TK_TYPE_INT TK_TYPE_FLOAT TK_TYPE_CHAR TK_TYPE_STRING TK_RETURN TK_FOR TK_IF TK_ELSE TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN TK_INCLUDE TK_INCLUDE_CLASS TK_TRUE TK_FALSE TK_NUMBER TK_NUMBER_FLOAT TK_ID TK_CLASS_NAME TK_UNARY TK_LE TK_GE TK_EQ TK_NE TK_GT TK_LT TK_AND TK_OR TK_STRING TK_CHARACTER
%type <nd_obj> statement_class statement datatype body_statement
%left TK_MULTIPLY TK_DIVIDE
%left TK_ADD TK_SUBTRACT
%%

program: headers program
| class program 
|
;

headers: TK_INCLUDE { add('H'); } TK_INCLUDE_CLASS ';'
;

class: class_defination '{' class_body '}'
| TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN '{' class_body '}'
;

class_body: class_atributes class_body
|  method_signature '(' atributs_method ')' '{' body return '}' class_body
|
;

method_signature: datatype TK_ID { add('F'); }
;


atributs_method: datatype TK_ID ',' atributs_method
| datatype TK_ID
|
;

class_atributes: statement_atributes ';' 
;

class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME { add('Z'); } 
;

datatype: TK_TYPE_INT { insert_type(); }
| TK_TYPE_FLOAT { insert_type(); }
| TK_TYPE_CHAR { insert_type(); }
| TK_TYPE_STRING { insert_type(); }
| TK_VOID { insert_type(); }
;

body: body_statement body
|
;

body_statement: TK_PRINTF { add('K'); } '(' TK_STRING ')' ';'
| TK_SCANF { add('K'); } '(' TK_STRING ',' '&' TK_ID ')' ';'
| statement_class ';'
| statement ';' 
| TK_IF { add('K'); } '(' condition ')' '{' body '}' else
| TK_FOR { add('K'); } '(' condition ')' '{' body '}'
;

else: TK_ELSE { add('K'); } '{' body '}'
|
;

statement_class: TK_CLASS_NAME { insert_type(); } TK_ID { add('O'); } '=' TK_CLASS_NAME '(' ')'
;

condition: value relop value 
| TK_TRUE 
| TK_FALSE
;

statement_atributes: datatype TK_ID { add('A'); } init 
| datatype TK_ID { add('A'); }
;

statement: datatype TK_ID init  
| datatype TK_ID
| TK_ID '=' expression 
| TK_ID relop expression
| TK_ID TK_UNARY
| TK_UNARY TK_ID
| TK_ID '.' TK_ID init
;

init: '=' expression
;

expression: expression TK_MULTIPLY expression 
| expression TK_DIVIDE expression 
| expression TK_SUBTRACT expression 
| expression TK_ADD expression 
| '(' expression ')'
| value
;

relop: TK_LT
| TK_GT
| TK_LE
| TK_GE
| TK_EQ
| TK_NE
;

value: TK_NUMBER { add('C'); }
| TK_NUMBER_FLOAT { add('C'); }
| TK_CHARACTER { add('C'); }
| TK_ID
;

return: TK_RETURN { add('K'); } value ';' 
|
;

%%

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