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

%}

%union {

struct var_name { 
	char name[100]; 
	struct node* nd;
} nd_obj;

struct var_name2 { 
	char name[100]; 
	struct node* nd;
	char type[5];
} nd_obj2; 

}
%token TK_VOID
%token <nd_obj> TK_PRINTF TK_SCANF TK_TYPE_INT TK_TYPE_FLOAT TK_TYPE_CHAR TK_TYPE_STRING TK_RETURN TK_FOR TK_IF TK_ELSE TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN TK_INCLUDE TK_TRUE TK_FALSE TK_NUMBER TK_NUMBER_FLOAT TK_ID TK_CLASS_NAME TK_UNARY TK_LE TK_GE TK_EQ TK_NE TK_GT TK_LT TK_AND TK_OR TK_STRING TK_CHARACTER
%type <nd_obj> headers include program class_defination class_atributes class_body class_body_main class method_signature statement_atributes 
%type <nd_obj> datatype else body body_statement statement_class statement condition return value init expression relop
%left <nd_obj> TK_MULTIPLY TK_DIVIDE
%left <nd_obj> TK_ADD TK_SUBTRACT
%%

program: class
| headers TK_CLASS_DEFINITION_MAIN '{' class_body_main '}' { 
    $2.nd = mknode($4.nd, NULL, "main_class"); 
    $$.nd = mknode($1.nd, $2.nd, "program"); 
    head = $$.nd; 
} 
;

headers: include ';' headers { 
    $$.nd = mknode($1.nd, $3.nd, "headers");
} 
| {$$.nd = NULL;}
;

include: TK_INCLUDE { add('H'); } {
    $$.nd = mknode(NULL, NULL, $1.name); 
}
;

class: class_defination '{' class_body '}' {
    $$.nd = mknode($1.nd, $3.nd, "class");
}
;

class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME { add('Z'); } { $$.nd = mknode($1.nd, $2.nd, "class"); }
;

class_body: class_atributes class_body { 
    $$.nd = mknode($1.nd, $2.nd, "class_body"); 
}
|  method_signature '(' atributs_method ')' '{' body return '}' class_body {
    $$.nd = mknode($6.nd, $7.nd, "method");
}
| { $$.nd = NULL; }
;

class_body_main: method_signature '(' atributs_method ')' '{' body return '}' class_body {
    $$.nd = mknode($6.nd, $7.nd, "method");
}
| { $$.nd = NULL; }
;


method_signature: datatype TK_ID { add('F'); }
;


atributs_method: datatype TK_ID ',' atributs_method
| datatype TK_ID
|
;

class_atributes: statement_atributes ';' 
;

datatype: TK_TYPE_INT { insert_type(); }
| TK_TYPE_FLOAT { insert_type(); }
| TK_TYPE_CHAR { insert_type(); }
| TK_TYPE_STRING { insert_type(); }
| TK_VOID { insert_type(); }
;

body: body_statement body { $$.nd = mknode($1.nd, $2.nd, "statement_body"); }
| {
    $$.nd = NULL;
}
;

body_statement: TK_PRINTF { add('K'); } '(' TK_STRING ')' ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
}
| TK_SCANF { add('K'); } '(' TK_STRING ',' '&' TK_ID ')' ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
}
| statement_class ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
}
| statement ';' {
    $$.nd = $1.nd;
}
| TK_IF { add('K'); } '(' condition ')' '{' body '}' else {
    struct node *iff = mknode($4.nd, $7.nd, $1.name);
    $$.nd = mknode(iff, $9.nd, "if-else");
}
| TK_FOR { add('K'); } '(' condition ')' '{' body '}' {
    $$.nd = mknode($4.nd, $7.nd, $1.name);
}
;

else: TK_ELSE { add('K'); } '{' body '}' {
    $$.nd = mknode(NULL, $4.nd, $1.name);
}
| { $$.nd = NULL; }
;

statement_class: TK_CLASS_NAME { insert_type(); } TK_ID { add('O'); } '=' TK_CLASS_NAME '(' ')'
;

condition: value relop value {
    $$.nd = mknode($1.nd, $3.nd, $2.name);
}
| TK_TRUE { add('K'); $$.nd = NULL; }
| TK_FALSE { add('K'); $$.nd = NULL; }
| {
    $$.nd = NULL;
}
;

statement_atributes: datatype TK_ID { add('A'); } init 
;

statement: datatype TK_ID { add('V'); } init {
    $2.nd = mknode(NULL, NULL, $2.name); 
    $$.nd = mknode($2.nd, $4.nd, "declaration"); 
}
| TK_ID '=' expression  {
    $1.nd = mknode(NULL, NULL, $1.name); 
    $$.nd = mknode($1.nd, $3.nd, "=");
}
| TK_ID relop expression {
    $1.nd = mknode(NULL, NULL, $1.name); 
    $$.nd = mknode($1.nd, $3.nd, $2.name);
}
| TK_ID TK_UNARY {
    $1.nd = mknode(NULL, NULL, $1.name); 
    $2.nd = mknode(NULL, NULL, $2.name); 
    $$.nd = mknode($1.nd, $2.nd, "iterator");
}
| TK_ID '.' TK_ID init {
    $3.nd = mknode(NULL, NULL, $3.name); 
    $$.nd = mknode($3.nd, $4.nd, ".");
}
;

init: '=' expression { 
    $$.nd = $2.nd; 
}
| { $$.nd = mknode(NULL, NULL, "NULL"); }
;

expression: expression TK_MULTIPLY expression { 
    $$.nd = mknode($1.nd, $3.nd, $2.name); 
}
| expression TK_DIVIDE expression {
    $$.nd = mknode($1.nd, $3.nd, $2.name); 
}
| expression TK_SUBTRACT expression {
    $$.nd = mknode($1.nd, $3.nd, $2.name); 
}
| expression TK_ADD expression {
    $$.nd = mknode($1.nd, $3.nd, $2.name); 
}
| '(' expression ')' {
    struct node *aux = mknode(NULL, NULL, "(");
    struct node *aux2 = mknode(NULL, NULL, ")");
    struct node *aux3 = mknode(aux, $2.nd, "");
    $$.nd = mknode (aux3, aux2, "");
}
| value { $$.nd = $1.nd; }
;

relop: TK_LT
| TK_GT
| TK_LE
| TK_GE
| TK_EQ
| TK_NE
;

value: TK_NUMBER { add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| TK_NUMBER_FLOAT { add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| TK_CHARACTER { add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| TK_ID { $$.nd = mknode(NULL, NULL, $1.name); }
;

return: TK_RETURN { add('K'); } value ';' { 
    check_return_type($3.name); $1.nd = mknode(NULL, NULL, "return"); 
    $$.nd = mknode($1.nd, $3.nd, "RETURN"); 
}
| { 
    $$.nd = NULL; 
}
;

%%

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
    printf("\nSYMBOL\tDATATYPE\tTYPE\tLINE NUMBER\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
    }

    for (i = 0; i < count; i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }

    printf("\n\n");
	printf("FASE 2: ANALISE SINTATICA\n\n");
	printtree(head);
    printf("\n\n");

    return 0;
}


struct node* mknode(struct node *left, struct node *right, const char *token) {
    /* printf("%s\n", token); */
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

void check_return_type(const char *value) {
	char *main_datatype = get_type("principal");
	char *return_datatype = get_type(value);
	if((!strcmp(main_datatype, "inteiro") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
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

char *get_type(const char *var){
	for(int i = 0; i < count; i++) {
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