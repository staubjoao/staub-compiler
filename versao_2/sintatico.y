%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"

    #define MAX_SYMBOLS 100
    #define MAX_FILENAME_LEN 30
    #define MAX_TOKEN_LEN 20
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    void print_symbol_table();
    void insert_type();
    void printtree(struct node*);
    void printInorder(struct node *);
    int search(const char *);
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
        char * filename;
        int line_no;
    } symbol_table[MAX_SYMBOLS];

    struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};

    char file_name_current[MAX_FILENAME_LEN];
    int count=0;
    int count_lines;
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
	char errors[100][100];
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
	char type[10];
} nd_obj2; 

}
%token TK_VOID
%token <nd_obj> TK_PRINTF TK_SCANF TK_TYPE_INT TK_TYPE_FLOAT TK_TYPE_CHAR TK_TYPE_STRING TK_RETURN TK_FOR TK_IF TK_ELSE TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN TK_INCLUDE TK_TRUE TK_FALSE TK_NUMBER TK_NUMBER_FLOAT TK_ID TK_CLASS_NAME TK_UNARY TK_LE TK_GE TK_EQ TK_NE TK_GT TK_LT TK_AND TK_OR TK_STRING TK_CHARACTER
%type <nd_obj> headers include program class_defination class_atributes class_body class_body_main class method_signature statement_atributes 
%type <nd_obj> datatype else body body_statement statement_class statement condition return relop
%type <nd_obj2> init value expression
%left <nd_obj> TK_MULTIPLY TK_DIVIDE
%left <nd_obj> TK_ADD TK_SUBTRACT
%%

program: class {

}
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

class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME { add('Z'); } { 
    $$.nd = mknode($1.nd, $2.nd, "class"); 
}
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


atributs_method: parament_method ',' atributs_method
| parament_method
|
;

parament_method: datatype TK_ID { add('P'); }
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
    int t = check_types($1.name, $4.type);  
    if(t > 0) {
        if(t == 1) {    
            struct node *temp = mknode(NULL, $4.nd, "decimal_para_inteiro");
            $$.nd = mknode($2.nd, temp, "declaration");   
        }   
        else if(t == 2) {
            struct node *temp = mknode(NULL, $4.nd, "inteiro_para_decimal");
            $$.nd = mknode($2.nd, temp, "declaration");   
        }   
        else if(t == 3) {    
            struct node *temp = mknode(NULL, $4.nd, "caracter_para_inteiro");
            $$.nd = mknode($2.nd, temp, "declaration");   
        }   
        else if(t == 4) {    
            struct node *temp = mknode(NULL, $4.nd, "inteiro_para_caracter");
            $$.nd = mknode($2.nd, temp, "declaration");   
        }   
        else if(t == 5) {    
            struct node *temp = mknode(NULL, $4.nd, "caracter_para_decimal");
            $$.nd = mknode($2.nd, temp, "declaration");   
        }   
        else {   
            struct node *temp = mknode(NULL, $4.nd, "decimal_para_caracter");
            $$.nd = mknode($2.nd, temp, "declaration");   
        }
    }
    else {   
        $$.nd = mknode($2.nd, $4.nd, "declaration");  
    } 
}
| TK_ID { check_declaration($1.name); } '=' expression  {
    $1.nd = mknode(NULL, NULL, $1.name); 
    char *id_type = get_type($1.name); 
    if (id_type != NULL) {
        if(strcmp(id_type, $4.type)) {
            if(!strcmp(id_type, "inteiro")) {
                if(!strcmp($4.type, "decimal")) {
                    struct node *temp = mknode(NULL, $4.nd, "decimal_para_inteiro");
                    $$.nd = mknode($1.nd, temp, "="); 
                }
                else {
                    struct node *temp = mknode(NULL, $4.nd, "caracter_para_inteiro");
                    $$.nd = mknode($1.nd, temp, "="); 
                }
                
            }
            else if(!strcmp(id_type, "decimal")) {
                if(!strcmp($4.type, "inteiro")){
                    struct node *temp = mknode(NULL, $4.nd, "inteiro_para_decimal");
                    $$.nd = mknode($1.nd, temp, "="); 
                }
                else{
                    struct node *temp = mknode(NULL, $4.nd, "caracter_para_decimal");
                    $$.nd = mknode($1.nd, temp, "="); 
                }
                
            }
            else {
                if(!strcmp($4.type, "inteiro")) {
                    struct node *temp = mknode(NULL, $4.nd, "inteiro_para_caracter");
                    $$.nd = mknode($1.nd, temp, "="); 
                }
                else {
                    struct node *temp = mknode(NULL, $4.nd, "decimal_para_caracter");
                    $$.nd = mknode($1.nd, temp, "="); 
                }
            }
        }
        else {
            $$.nd = mknode($1.nd, $4.nd, "="); 
        }
	}
    printf("Teste2 %s\n", id_type);
}
| TK_ID { check_declaration($1.name); } relop expression {
    $1.nd = mknode(NULL, NULL, $1.name);
    $$.nd = mknode($1.nd, $4.nd, $3.name);
}
| TK_ID { check_declaration($1.name); } TK_UNARY {
    $1.nd = mknode(NULL, NULL, $1.name); 
    $3.nd = mknode(NULL, NULL, $3.name); 
    $$.nd = mknode($1.nd, $3.nd, "iterator");
}
| TK_ID { check_declaration($1.name); } '.' TK_ID { /* ADICIONAR FUNÇÃO PARA VALIDAR O ATRIBUTO OU METODO */} init {
    $4.nd = mknode(NULL, NULL, $4.name); 
    $$.nd = mknode($4.nd, $6.nd, ".");
}
;

init: '=' expression { 
    $$.nd = $2.nd; 
    sprintf($$.type, "%s", $2.type);
    strcpy($$.name, $2.name);
}
| { sprintf($$.type, "null"); $$.nd = mknode(NULL, NULL, "NULL"); strcpy($$.name, "NULL"); }
;

expression: expression TK_MULTIPLY expression { 
    if(!strcmp($1.type, $3.type)) {
        sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name); 
	}
	else {
		if(!strcmp($1.type, "inteiro") && !strcmp($3.type, "decimal")) {
			struct node *temp = mknode(NULL, $1.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $3.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "inteiro") && !strcmp($3.type, "caracter")) {
			struct node *temp = mknode(NULL, $3.nd, "caracter_para_inteiro");
			sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "caracter") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $1.nd, "caracter_para_inteiro");
			sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "caracter")) {
			struct node *temp = mknode(NULL, $3.nd, "caracter_para_decimal");
			sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else {
			struct node *temp = mknode(NULL, $1.nd, "caracter_para_decimal");
			sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
	}
}
| expression TK_DIVIDE expression {
    if(!strcmp($1.type, $3.type)) {
        sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name); 
	}
	else {
		if(!strcmp($1.type, "inteiro") && !strcmp($3.type, "decimal")) {
			struct node *temp = mknode(NULL, $1.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $3.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "inteiro") && !strcmp($3.type, "caracter")) {
			struct node *temp = mknode(NULL, $3.nd, "caracter_para_inteiro");
			sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "caracter") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $1.nd, "caracter_para_inteiro");
			sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "caracter")) {
			struct node *temp = mknode(NULL, $3.nd, "caracter_para_decimal");
			sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else {
			struct node *temp = mknode(NULL, $1.nd, "caracter_para_decimal");
			sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
	} 
}
| expression TK_SUBTRACT expression {
    if(!strcmp($1.type, $3.type)) {
        sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name); 
	}
	else {
		if(!strcmp($1.type, "inteiro") && !strcmp($3.type, "decimal")) {
			struct node *temp = mknode(NULL, $1.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $3.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "inteiro") && !strcmp($3.type, "caracter")) {
			struct node *temp = mknode(NULL, $3.nd, "caracter_para_inteiro");
			sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "caracter") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $1.nd, "caracter_para_inteiro");
			sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "caracter")) {
			struct node *temp = mknode(NULL, $3.nd, "caracter_para_decimal");
			sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else {
			struct node *temp = mknode(NULL, $1.nd, "caracter_para_decimal");
			sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
	} 
}
| expression TK_ADD expression {
    if(!strcmp($1.type, $3.type)) {
        sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name); 
	}
	else {
		if(!strcmp($1.type, "inteiro") && !strcmp($3.type, "decimal")) {
			struct node *temp = mknode(NULL, $1.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $3.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "inteiro") && !strcmp($3.type, "caracter")) {
			struct node *temp = mknode(NULL, $3.nd, "caracter_para_inteiro");
			sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "caracter") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $1.nd, "caracter_para_inteiro");
			sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "decimal") && !strcmp($3.type, "caracter")) {
			struct node *temp = mknode(NULL, $3.nd, "caracter_para_decimal");
			sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else {
			struct node *temp = mknode(NULL, $1.nd, "caracter_para_decimal");
			sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
	} 
}
| value { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", $1.type);
    $$.nd = $1.nd; 
}
;

relop: TK_LT
| TK_GT
| TK_LE
| TK_GE
| TK_EQ
| TK_NE
;

value: TK_NUMBER { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", "inteiro");
    add('C'); $$.nd = mknode(NULL, NULL, $1.name); 
}
| TK_NUMBER_FLOAT { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", "decimal");
    add('C'); $$.nd = mknode(NULL, NULL, $1.name); 
}
| TK_CHARACTER { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", "caracter");
    add('C'); $$.nd = mknode(NULL, NULL, $1.name); 
}
| TK_ID {
    strcpy($$.name, $1.name); 
    char *id_type = get_type($1.name); 
    if(id_type == NULL) {
        sprintf($$.type, "%s", "NULL"); 
    } else {
        sprintf($$.type, "%s", id_type); 
    }
    check_declaration($1.name); 
    $$.nd = mknode(NULL, NULL, $1.name); 
}
;

return: TK_RETURN { add('K'); } value ';' { 
    check_return_type($3.name); 
    $1.nd = mknode(NULL, NULL, "return"); 
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
        strcpy(file_name_current, argv[i]);
        if(i > 1) {
            struct node *aux;
            aux = head;
        }
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
    }
    print_symbol_table();

    for (i = 0; i < count; i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }

    printf("\n\n");
	printf("FASE 2: ANALISE SINTATICA\n\n");
	printtree(head);
    
    printf("\n\n");
    printf("FASE 3: ANALISE SEMANTICA \n\n");
	if(sem_errors>0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i = 0; i < sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");

    return 0;
}

void print_symbol_table()
{
    printf("Symbol Table:\n");
    printf("%-25s |%-15s |%-15s |%-7s |%-20s|\n", "Identifier", "Data Type", "Type", "Line No", "Filename");
    char aux_line[10];
    for (int i = 0; i < count; i++)
    {
        sprintf(aux_line, "%5d", symbol_table[i].line_no);
        printf("%-25s |%-15s |%-15s |%-7s |%-20s|\n", symbol_table[i].id_name, symbol_table[i].data_type,
               symbol_table[i].type, aux_line, symbol_table[i].filename);
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

void check_return_type(const char *value) {
	char *main_datatype = get_type("principal");
	char *return_datatype = get_type(value);

    if (return_datatype == NULL || (!strcmp(main_datatype, "inteiro") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)) {
        return;
    }

    sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
    sem_errors++;

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

void check_declaration(const char *c) {    
    q = search(c);    
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);  
        sem_errors++;
    }
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
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }  
        else if(c == 'K') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Keyword");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }  else if(c == 'V') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Variable");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }  else if(c == 'C') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("CONST");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Constant");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }  else if(c == 'F') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Function");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }else if(c == 'Z') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Class");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }else if(c == 'O') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Object");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }else if(c == 'A') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Attribute");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }else if(c == 'X') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Vector");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }else if(c == 'P') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Parameter");   
            symbol_table[count].filename=strdup(file_name_current);
            count++;  
        }

    }
}

int search(const char *type) { 
    int i; 
    for(i = count-1; i >= 0; i--) {
        if(strcmp(symbol_table[i].id_name, type) == 0) {   
            return -1;
            break;
        }
    }
    return 0;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}