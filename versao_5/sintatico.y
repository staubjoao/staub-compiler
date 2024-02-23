%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"util.h"
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
    int search(const char *, int, int);
	void insert_type();
	void print_inorder(struct node *);
    void check_declaration(const char *);
    void check_class_declaration(const char *);
    void check_declaration_previously(const char *);
    void check_atribute(const char *, const char *);
    void check_method(const char *, const char *, int, struct param_types *head);
	void function_check_return(const char *);
	void check_types(const char *, const char *);
	void check_types_atributes(const char *, const char *);
	char *get_type(const char *);
	char *get_type_function(const char *, int scope);
	struct node* mknode(struct node *left, struct node *right, const char *token);
    void insert_l_class(struct tree_class_l *head_l, struct node *head);

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

    struct node *class_aux = NULL;
    struct tree_class_l *head_class_l = NULL;
    struct tree_class_l *head_class_l_aux = NULL;

    int count_file_name;
    char file_name_current[2][MAX_FILE_NAME_LEN];
    char *class_name_current;
    int count=0;
    int q;
	char type[10];
    char *function_return;
    extern int countn[2];
	struct node *head;
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
%token <nd_obj> TK_PRINTF TK_SCANF TK_TYPE_INT TK_TYPE_FLOAT TK_TYPE_CHAR TK_TYPE_STRING TK_RETURN TK_FOR TK_IF TK_ELSE TK_CLASS_DEFINITION TK_CLASS_DEFINITION_MAIN TK_INCLUDE TK_INCLUDE_CLASS TK_TRUE TK_FALSE TK_NUMBER TK_NUMBER_FLOAT TK_ID TK_CLASS_NAME TK_UNARY TK_LE TK_GE TK_EQ TK_NE TK_GT TK_LT TK_AND TK_OR TK_STRING TK_CHARACTER
%type <nd_obj> program class_defination class_atributes class_body class_body_main class method_signature statement_atributes 
%type <nd_obj> datatype else body body_statement statement_class statement condition return relop atributs_method parament_method class_call params_const param_const
%type <nd_obj2> init value expression
%left <nd_obj> TK_MULTIPLY TK_DIVIDE
%left <nd_obj> TK_ADD TK_SUBTRACT
%%

program: TK_CLASS_DEFINITION_MAIN { class_scope_count++; add('Z'); } '{' class_body_main '}'  { 
    $$.nd = mknode($1.nd, $4.nd, "program"); 
    princial_bool = 1;
    head = $$.nd; 
} 
| class {
    class_aux = $1.nd;
    if(head_class_l_aux == NULL) {
        head_class_l_aux = head_class_l;
    } else {
        head_class_l_aux = head_class_l_aux->next;
    } 
    head_class_l_aux->head = class_aux;
}
;

/* headers: include headers { 
    // $$.nd = mknode($1.nd, $3.nd, "headers");
} 
| {
    $$.nd = NULL;
}
;

include: TK_INCLUDE TK_INCLUDE_CLASS {
    printf("%s %s\n", $1.name, $2.name);
}
; */

class: class_defination '{' class_body '}' program {
    $$.nd = mknode($1.nd, $3.nd, "class");
}
;

class_defination: TK_CLASS_DEFINITION TK_CLASS_NAME { class_scope_count++; add('Z'); } { 
    $$.nd = mknode($1.nd, $2.nd, "class"); 
    class_name_current = strdup($2.name);
}
;

class_body: class_atributes class_body { 
    $$.nd = mknode($1.nd, $2.nd, "class_body"); 
}
|  method_signature '(' atributs_method ')' {
    symbol_table[method_current].num_param = param_count;
    param_count = 0;
} '{' body return '}' class_body {
    struct node *aux_class = mknode($7.nd, $10.nd, "class_body");
    $$.nd = mknode(aux_class, $8.nd, "method");
}
| { 
    $$.nd = NULL; 
}
;

class_body_main: method_signature '(' atributs_method ')' '{' body return '}' class_body {
    $$.nd = mknode($6.nd, $7.nd, "method2");
}
| { 
    $$.nd = NULL; 
}
;


method_signature: datatype TK_ID { scope_count++; add('F'); } {
    $$.nd = mknode(NULL, NULL, $2.name);
    method_current = count-1;
}
;


atributs_method: parament_method atributs_method {
    $$.nd = mknode($1.nd, NULL, "parameter");
    param_count++;

}
| ',' parament_method {
    $$.nd = mknode($2.nd, NULL, "parameter");
    param_count++;
}
| {
    $$.nd = NULL;
}
;

parament_method: datatype TK_ID { add('P'); } {
    $2.nd = mknode(NULL, NULL, $2.name); 
    $$.nd = mknode($1.nd, $2.nd, "parameter");  
}
;

class_atributes: statement_atributes ';' {
    $$.nd = $1.nd;
}
;

datatype: TK_TYPE_INT { insert_type(); }
| TK_TYPE_FLOAT { insert_type(); }
| TK_TYPE_CHAR { insert_type(); }
| TK_TYPE_STRING { insert_type(); }
| TK_VOID { insert_type(); }
;

body: body_statement body { 
    $$.nd = mknode($1.nd, $2.nd, "statement_body"); 
}
| {
    $$.nd = NULL;
}
;

body_statement: TK_FOR { add('K'); } '(' condition ')' '{' body '}' {
    $$.nd = mknode($4.nd, $7.nd, $1.name);
}
| TK_IF { add('K'); } '(' condition ')' '{' body '}' else {
    struct node *iff = mknode($4.nd, $7.nd, $1.name);
    $$.nd = mknode(iff, $9.nd, "if-else");
}
| statement_class ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
}
| statement ';' {
    $$.nd = $1.nd;
}
| TK_PRINTF { add('K'); } '(' TK_STRING ')' ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
}
| TK_SCANF { add('K'); } '(' TK_STRING ',' '&' TK_ID ')' ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
}
;

else: TK_ELSE { add('K'); } '{' body '}' {
    $$.nd = mknode(NULL, $4.nd, $1.name);
}
| { 
    $$.nd = NULL;
}
;

statement_class: TK_CLASS_NAME { check_class_declaration($1.name); insert_type(); } TK_ID { add('O'); }
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

statement_atributes: datatype TK_ID { add('A'); } init  {
    $2.nd = mknode(NULL, NULL, $2.name); 
    $$.nd = mknode($2.nd, $4.nd, "atribute");  
}
;

statement: datatype TK_ID { check_declaration_previously($2.name); add('V'); } init {
    $2.nd = mknode(NULL, NULL, $2.name); 
    check_types($1.name, $4.type);  
    $$.nd = mknode($2.nd, $4.nd, "declaration");  
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
| class_call { check_atribute($1.nd->left->token, $1.nd->right->token); } init {
    check_types_atributes($1.nd->right->token, $3.type);  
    $$.nd = mknode($1.nd, $3.nd, ".");
}
| class_call '(' params_const ')' { 
    check_method($1.nd->left->token, $1.nd->right->token, param_count, head_params_l); 
    free_l_param(&head_params_l);
} {
    $$.nd = mknode($1.nd, $3.nd, "call_method");
    param_count = 0;
}
;

params_const: param_const params_const {
    param_count++;

}
| ',' param_const {
    param_count++;
}
| {
    $$.nd = NULL;
}
;

param_const: value {
    insert_at_end_l_param(&head_params_l, $1.type);
}
;

class_call: TK_ID { check_declaration($1.name); } '.' TK_ID {
    struct node *aux_left = mknode($1.nd, NULL, $1.name); 
    struct node *aux_right = mknode($4.nd, NULL, $4.name); 
    $$.nd = mknode(aux_left, aux_right, "call"); 
}
;

init: '=' expression { 
    $$.nd = $2.nd; 
    sprintf($$.type, "%s", $2.type);
    strcpy($$.name, $2.name);
}
| { 
    sprintf($$.type, "null"); 
    $$.nd = mknode(NULL, NULL, "NULL"); 
    strcpy($$.name, "NULL"); 
}
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
    $$.nd = mknode(NULL, NULL, $1.name); 
    // add('C'); 
}
| TK_NUMBER_FLOAT { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", "decimal");
    $$.nd = mknode(NULL, NULL, $1.name); 
    // add('C'); 
}
| TK_CHARACTER { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", "caracter");
    $$.nd = mknode(NULL, NULL, $1.name); 
    // add('C'); 
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
| TK_STRING {
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", "palavra");
    $$.nd = mknode(NULL, NULL, $1.name); 
    // add('C'); 
}
;

return: TK_RETURN { add('R'); } value ';' { 
    function_check_return($3.type); 
    $1.nd = mknode(NULL, NULL, "return"); 
    $$.nd = mknode($1.nd, $3.nd, "RETURN"); 
}
| { 
    $$.nd = NULL; 
    function_return = NULL;
    function_check_return("NULL");
}
;

%%

int main(int argc, char **argv)
{
    int i;

    count_file_name = 0;
    if(argc >= 3) {
        printf("Utilize: ./glf <arquivo_principal>.jsc");
        return 1;
    }
    strcpy(file_name_current[count_file_name], argv[1]);
    FILE *fp = fopen(argv[1], "r");
    countn[count_file_name] = 1;
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    yyin = fp;

    yyparse();

    fclose(fp);

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
            if(aux->head != NULL) {
                printf("\nArquivo: %s\n", aux->file_name);
                printtree(aux->head);
            }
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

    return 0;
}

void print_symbol_table()
{
    printf("\n\nTABELA DE SIMBOLOS:\n\n");
    printf("%-25s |%-25s |%-15s |%-15s |%-7s | %s|  %s |%-20s\n", "IDENTIFICADOR", "TIPO DE DADO", "TIPO", "CLASSE", "LINHA", "C_S", "S", "ARQUIVO");
    char aux_line[10];
    for (int i = 0; i < count; i++)
    {
        sprintf(aux_line, "%5d", symbol_table[i].line_no);
        printf("%-25s |%-25s |%-15s |%-15s |%-7s |%3d |%3d |%-20s \n", symbol_table[i].id_name, symbol_table[i].data_type,
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
	char *function_datatype = get_type_function(symbol_table[count-1].data_type, symbol_table[count-1].class_scope);
    char *return_datatype = get_type(value);
    if(strcmp(value, function_datatype)) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo de retorno\n", countn[count_file_name], file_name_current[count_file_name]);
    }
}

void check_types(const char *type1, const char *type2){
	if(!strcmp(type1, type2) || !strcmp(type2, "null"))
		return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo na atribuição\n", countn[count_file_name], file_name_current[count_file_name]);
}

void check_types_atributes(const char *token, const char *type2){
    int i;
    char *type1;
	for(i = count-1; i >= 0; i--) {
        if(!strcmp(symbol_table[i].id_name, token)) {
            type1=strdup(symbol_table[i].data_type);            
            break;
        }
    }
    if(!strcmp(type1, type2) || !strcmp(type2, "null"))
		return;

    printf("%s %s\n", type1, type2);

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo na atribuição\n", countn[count_file_name], file_name_current[count_file_name]);
}

void check_declaration(const char *c) {    
    q = search(c, class_scope_count, scope_count);
    if(!q) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: \"%s\" não foi declarada!\n", countn[count_file_name], file_name_current[count_file_name], c);  
    }
}

void check_class_declaration(const char *c) {
    int i, q = 0;
    for(i = count-1; i >= 0; i--) {
        if(!strcmp(symbol_table[i].id_name, c)) {
            q = 1;
            break;
        }
    }
    if(!q) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: A classe \"%s\" não foi declarada!\n", countn[count_file_name], file_name_current[count_file_name], c);  
    }
}

void check_declaration_previously(const char *c) {    
    q = search(c, class_scope_count, scope_count);
    if(!q) return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: \"%s\" já foi declarada anteriormente!\n", countn[count_file_name], file_name_current[count_file_name], c);  
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
    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O atributo %s não existe na classe %s\n", countn[count_file_name], file_name_current[count_file_name], atribute, class_name_target);
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
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s espera %d parametros e recebeu %d\n", countn[count_file_name], file_name_current[count_file_name], method, symbol_table[i].num_param, num_param_call);
            }
            int count_paran_index = 1;
            struct param_types *temp = head;
            for(j = i+1; j <= i+num_param_call; j++) {
                if (temp != NULL) {
                    if((strcmp(symbol_table[j].data_type, temp->type) != 0)) {
                        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O parametro de número %d, não é do tipo esperado\n", countn[count_file_name], file_name_current[count_file_name], count_paran_index);
                    }
                    temp = temp->next;
                    count_paran_index++;
                }
            }
            return;
        }
    }
    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s não existe na classe %s\n", countn[count_file_name], file_name_current[count_file_name], method, class_name_target);
}

char *get_type(const char *var){
	for(int i = 0; i < count; i++) {
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}

char *get_type_function(const char *var, int scope){
	for(int i = 0; i < count; i++) {
		if(!strcmp(symbol_table[i].id_name, var) && scope == symbol_table[i].class_scope) {
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
            symbol_table[count].line_no=countn[count_file_name];    
            symbol_table[count].type=strdup("Header");
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  
        else if(c == 'K') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Keyword");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if(c == 'V') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Variable");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if(c == 'C') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("CONST");
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Constant");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if(c == 'F') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            function_return=strdup(yylval.nd_obj.name);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Function");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'Z') {
            class_name_current = strdup(yylval.nd_obj.name);
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(yylval.nd_obj.name);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Class");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'O') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Object");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'A') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Attribute");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'X') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Vector");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'P') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Parameter");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if(c == 'R') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(function_return);
            function_return = NULL;
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Return");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
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
    fprintf(stderr, "Erro sintático na linha %d, arquivo %s: %s   %s\n", countn[count_file_name], file_name_current[count_file_name], msg, yytext);
}