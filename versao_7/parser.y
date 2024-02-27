%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"util.h"
    #include"lex.yy.c"
%}

%union {
struct var_name 
{ 
	char name[100]; 
	struct node* nd;
} nd_obj;

struct var_name2 
{ 
	char name[100]; 
	struct node* nd;
	char type[10];
} nd_obj2; 

struct var_name3 {
	char name[100];
	struct node* nd;
	char if_body[5];
	char else_body[5];
} nd_obj3;
}
%token TK_VOID
%token <nd_obj> TK_INCLUDE TK_PRINTF TK_SCANF TK_TYPE_INT TK_TYPE_FLOAT TK_TYPE_CHAR TK_TYPE_STRING TK_RETURN TK_FOR TK_IF TK_ELSE TK_CLASS_DEFINITION TK_FUNC_DEFINITION_MAIN TK_CLASS_DEFINITION_MAIN TK_TRUE TK_FALSE TK_NUMBER TK_NUMBER_FLOAT TK_ID TK_CLASS_NAME TK_UNARY TK_LE TK_GE TK_EQ TK_NE TK_GT TK_LT TK_AND TK_OR TK_STRING TK_CHARACTER
%type <nd_obj> program class_defination class_atributes class_body class_body_main class method_signature statement_atributes init_vector_value init_vector_value_aux body_main body_main_statement
%type <nd_obj> datatype else body body_statement statement_class statement return relop atributs_method parament_method class_call class_call_aux params_const param_const init_vector else_main
%type <nd_obj2> init value expression 
%type <nd_obj3> condition
%left <nd_obj> TK_MULTIPLY TK_DIVIDE
%left <nd_obj> TK_ADD TK_SUBTRACT
%%

program: TK_CLASS_DEFINITION_MAIN { class_scope_count++; add('Z'); } '{' class_body_main '}'  { 
    $$.nd = mknode($4.nd, $1.nd, "program"); 
    princial_bool = 1;
    head = $$.nd; 
} 
| TK_INCLUDE class {
    class_aux = $2.nd;
    if (head_class_l_aux == NULL) {
        head_class_l_aux = head_class_l;
    } else {
        head_class_l_aux = head_class_l_aux->next;
    } 
    head_class_l_aux->head = class_aux;
}
;

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
    symbol_table[method_current].num_param = count_param_vector;
    count_param_vector = 0;
} '{' body return '}' class_body {
    struct node *aux_class = mknode($7.nd, $10.nd, "class_body");
    $$.nd = mknode(aux_class, $8.nd, "method");
}
| { 
    $$.nd = NULL; 
}
;

class_body_main: TK_FUNC_DEFINITION_MAIN { scope_count++; } '(' ')' '{' body_main '}' {
    $$.nd = mknode(NULL, $6.nd, "main");
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
    count_param_vector++;
}
| ',' parament_method atributs_method{
    $$.nd = mknode($2.nd, NULL, "parameter");
    count_param_vector++;
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

body_main: body_main_statement body_main { 
    $$.nd = mknode($1.nd, $2.nd, ""); 
}
| {
    $$.nd = NULL;
}
;

body_main_statement: TK_FOR { add('K'); } '(' condition ')' '{' body_main '}' {
    $$.nd = mknode($4.nd, $7.nd, $1.name);
    strcpy(icg[ic_idx++], buff);
	sprintf(icg[ic_idx++], "JUMP to %s\n", $4.if_body);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body);
}
| TK_IF { add('K'); } '(' condition ')' { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body); } '{' body_main '}' { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body); } else_main {
    struct node *iff = mknode($4.nd, $8.nd, $1.name);
    $$.nd = mknode(iff, $11.nd, "if-else");
    printf(icg[ic_idx++], "GOTO next\n");
}
| statement_class ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
}
| statement ';' {
    $$.nd = $1.nd;
}
| TK_PRINTF { add('K'); } '(' TK_STRING ')' ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
	sprintf(icg[ic_idx++], "PRINT %s\n", $4.name);
}
| TK_SCANF { add('K'); } '(' TK_STRING ',' '&' TK_ID ')' ';' {
    $$.nd = mknode($4.nd, $7.nd, $1.name);
}
;

else_main: TK_ELSE { add('K'); } '{' body_main '}' {
    $$.nd = mknode(NULL, $4.nd, $1.name);
}
| { 
    $$.nd = NULL;
}
;

body: body_statement body { 
    $$.nd = mknode($1.nd, $2.nd, ""); 
}
| {
    $$.nd = NULL;
}
;

body_statement: TK_FOR { add('K'); is_for = 1; } '(' condition ')' '{' body '}' {
    $$.nd = mknode($4.nd, $7.nd, $1.name);
}
| TK_IF { add('K'); is_for = 0; } '(' condition ')' '{' body '}' else {
    struct node *iff = mknode($4.nd, $7.nd, $1.name);
    $$.nd = mknode(iff, $9.nd, "if-else");
}
| statement ';' {
    $$.nd = $1.nd;
}
| TK_PRINTF { add('K'); } '(' TK_STRING ')' ';' {
    $$.nd = mknode(NULL, NULL, $1.name);
}
| TK_SCANF { add('K'); } '(' TK_STRING ',' '&' TK_ID ')' ';' {
    $$.nd = mknode($4.nd, $7.nd, $1.name);
}
;

else: TK_ELSE { add('K'); } '{' body '}' {
    $$.nd = mknode(NULL, $4.nd, $1.name);
}
| { 
    $$.nd = NULL;
}
;

init_vector: '=' '{' init_vector_value '}' {
    check_vector_init(head_params_l); 
    count_param_vector = 0;
    free_l_param(&head_params_l);
    $$.nd = mknode($3.nd, NULL, "init_vector");
} 
| {
    $$.nd = NULL;
}
;

init_vector_value: init_vector_value_aux init_vector_value {
    count_param_vector++;
    $$.nd = mknode($1.nd, $2.nd, "");
}
| ',' init_vector_value_aux init_vector_value {
    count_param_vector++;
    $$.nd = mknode($2.nd, $3.nd, "");
}
| {
    $$.nd = NULL;
    vector_name_aux = NULL;
}
;

init_vector_value_aux: value {
    insert_at_end_l_param(&head_params_l, $1.type);
}
;

statement_class: TK_CLASS_NAME { check_class_declaration($1.name); insert_type(); } TK_ID { add('O'); }
;

condition: value relop value {
    $$.nd = mknode($1.nd, $3.nd, $2.name); 
	if (is_for) {
		sprintf($$.if_body, "L%d", label++);
		sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
		sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", $1.name, $2.name, $3.name, label);
		sprintf($$.else_body, "L%d", label++);
	} else {
		sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", $1.name, $2.name, $3.name, label, label+1);
		sprintf($$.if_body, "L%d", label++);
		sprintf($$.else_body, "L%d", label++);
	}
}
| TK_TRUE { add('K'); $$.nd = NULL; }
| TK_FALSE { add('K'); $$.nd = NULL; }
| {
    $$.nd = NULL;
}
;

statement_atributes: datatype TK_ID { add('A'); } init  {
    $2.nd = mknode(NULL, NULL, $2.name); 
    check_types($1.name, $4.type);  
    $$.nd = mknode($2.nd, $4.nd, "atribute");  
}
;

statement: datatype TK_ID { check_declaration_previously($2.name); add('V'); } init {
    $2.nd = mknode(NULL, NULL, $2.name); 
    check_types($1.name, $4.type);  
    $$.nd = mknode($2.nd, $4.nd, "declaration");  
    sprintf(icg[ic_idx++], "%s = %s\n", $2.name, $4.name);
}
| TK_ID { check_declaration($1.name); } '=' expression  {
    $1.nd = mknode(NULL, NULL, $1.name); 
    char *id_type = get_type($1.name); 
    if (id_type != NULL) {
        check_types(id_type, $4.type);  
    }
    sprintf(icg[ic_idx++], "%s = %s\n", $1.name, $4.name);
}
| TK_ID { check_declaration($1.name); } relop expression {
    $1.nd = mknode(NULL, NULL, $1.name);
    $$.nd = mknode($1.nd, $4.nd, $3.name);
}
| TK_ID { check_declaration($1.name); } TK_UNARY {
    $1.nd = mknode(NULL, NULL, $1.name); 
    $3.nd = mknode(NULL, NULL, $3.name); 
    if (!strcmp($3.name, "++")) {
        sprintf(icg[ic_idx++], "%s = %s + 1\n", $1.name, $1.name);
    } else if (!strcmp($3.name, "--")) {
        sprintf(icg[ic_idx++], "%s = %s - 1\n", $1.name, $1.name);
    }
    $$.nd = mknode($1.nd, $3.nd, "iterator");
}
| class_call
| datatype TK_ID { vector_name_aux=strdup($2.name); check_declaration_previously($2.name); add('J'); } '[' TK_NUMBER ']' { symbol_table[count-1].num_param = atoi($5.name); } init_vector {
    $2.nd = mknode(NULL, NULL, $2.name); 
    $$.nd = mknode($2.nd, $8.nd, "declaration_vector");  
}
| TK_ID { check_declaration($1.name); } '[' TK_NUMBER ']' '=' expression {
    check_vector_atribt($1.name, $7.type, atoi($4.name));
    $$.nd = mknode($1.nd, $7.nd, "=");  
}
;

class_call: class_call_aux { check_atribute($1.nd->left->token, $1.nd->right->token); } init {
    check_types_atributes($1.nd->right->token, $3.type);  
    $$.nd = mknode($1.nd, $3.nd, ".");
}
| class_call_aux '(' params_const ')' { 
    check_method($1.nd->left->token, $1.nd->right->token, head_params_l); 
    free_l_param(&head_params_l);
    $$.nd = mknode($1.nd, $3.nd, "call_method");
    count_param_vector = 0;
}
;

params_const: param_const params_const {
    count_param_vector++;
}
| ',' param_const {
    count_param_vector++;
}
| {
    $$.nd = NULL;
}
;

param_const: value {
    insert_at_end_l_param(&head_params_l, $1.type);
}
;

class_call_aux: TK_ID { check_declaration($1.name); } '.' TK_ID {
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
    sprintf($$.type, "NULL"); 
    $$.nd = mknode(NULL, NULL, ""); 
    strcpy($$.name, "NULL"); 
}
;

expression: expression TK_MULTIPLY expression { 
    error_local = 0;
    if (!strcmp($1.type, $3.type)) {
        sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name); 
	}
	else {
		if (!strcmp($1.type, "inteiro") && !strcmp($3.type, "decimal")) {
			struct node *temp = mknode(NULL, $1.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if (!strcmp($1.type, "decimal") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $3.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else {
            error_local = 1;
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
		}
	}
    if (!error_local) {
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    }
}
| expression TK_DIVIDE expression {
    error_local = 0;
    if (atoi($2.name) != 0) {
        if (!strcmp($1.type, $3.type)) {
            sprintf($$.type, "%s", $1.type);
            $$.nd = mknode($1.nd, $3.nd, $2.name); 
        }
        else {
            if (!strcmp($1.type, "inteiro") && !strcmp($3.type, "decimal")) {
                struct node *temp = mknode(NULL, $1.nd, "inteiro_para_decimal");
                sprintf($$.type, "%s", $3.type);
                $$.nd = mknode(temp, $3.nd, $2.name);
            }
            else if (!strcmp($1.type, "decimal") && !strcmp($3.type, "inteiro")) {
                struct node *temp = mknode(NULL, $3.nd, "inteiro_para_decimal");
                sprintf($$.type, "%s", $1.type);
                $$.nd = mknode($1.nd, temp, $2.name);
            }
            else {
                error_local = 1;
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
            }
        } 
    } else {
        error_local = 1;
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Divisão por zero\n", countn[count_file_name], file_name_current[count_file_name]);
    }
    if (!error_local) {
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    }
}
| expression TK_SUBTRACT expression {
    error_local = 0;
    if (!strcmp($1.type, $3.type)) {
        sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name); 
	}
	else {
		if (!strcmp($1.type, "inteiro") && !strcmp($3.type, "decimal")) {
			struct node *temp = mknode(NULL, $1.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if (!strcmp($1.type, "decimal") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $3.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else {
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
            error_local = 1;
		}
	}
    if (!error_local) {
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    } 
}
| expression TK_ADD expression {
    error_local = 0;
    if (!strcmp($1.type, $3.type)) {
        sprintf($$.type, "%s", $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name); 
	}
	else {
		if (!strcmp($1.type, "inteiro") && !strcmp($3.type, "decimal")) {
			struct node *temp = mknode(NULL, $1.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $3.type);
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else if (!strcmp($1.type, "decimal") && !strcmp($3.type, "inteiro")) {
			struct node *temp = mknode(NULL, $3.nd, "inteiro_para_decimal");
            sprintf($$.type, "%s", $1.type);
			$$.nd = mknode($1.nd, temp, $2.name);
		}
		else {
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Tipo não esperado na expressão\n", countn[count_file_name], file_name_current[count_file_name]);
            error_local = 1;
		}
	} 
    if (!error_local) {
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    }
}
| value { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", $1.type);
    $$.nd = $1.nd; 
}
| class_call_aux '(' params_const ')' { 
    check_method($1.nd->left->token, $1.nd->right->token, head_params_l); 
    free_l_param(&head_params_l);
    $$.nd = mknode($1.nd, $3.nd, "call_method");
    count_param_vector = 0;
    char *type_function;
    int i, find_bool = 0;
    for (i = count-1; i >= 0; i--)  {
        if (!strcmp(symbol_table[i].id_name, $1.nd->right->token)) {
            find_bool = 1;
            break;
        }
    }
    if (find_bool) {
        sprintf($$.type, "%s", symbol_table[i].data_type);
    } else {
        sprintf($$.type, "%s", "NULL");
    }
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
}
| TK_NUMBER_FLOAT { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", "decimal");
    $$.nd = mknode(NULL, NULL, $1.name); 
}
| TK_CHARACTER { 
    strcpy($$.name, $1.name); 
    sprintf($$.type, "%s", "caracter");
    $$.nd = mknode(NULL, NULL, $1.name); 
}
| TK_ID {
    strcpy($$.name, $1.name); 
    char *id_type = get_type($1.name); 
    if (id_type == NULL) {
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
}
;

return: TK_RETURN { add('R'); } value ';' { 
    check_function_return($3.type); 
    $1.nd = mknode(NULL, NULL, "return"); 
    $$.nd = mknode($1.nd, $3.nd, "RETURN"); 
}
| { 
    $$.nd = NULL; 
    function_return = NULL;
    check_function_return("NULL");
}
;

%%

int main(int argc, char **argv)
{
    int i;
    count_file_name = 0;
    if (argc >= 3) {
        printf("Utilize: ./glf <arquivo_principal>.jsc");
        return 1;
    }
    strcpy(file_name_current[count_file_name], argv[1]);
    FILE *fp = fopen(argv[1], "r");
    countn[count_file_name] = 1;
    yyin = fp;
    if (yyin == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }


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
    if (aux != NULL) {
        while(aux != NULL) {
            if (aux->head != NULL) {
                printf("\nArquivo: %s\n", aux->file_name);
                printtree(aux->head);
            }
            aux = aux->next;
        }
    }
    if (head != NULL) {
        printtree(head);
    }
        
    printf("\n\n");
    printf("FASE 3: ANALISE SEMANTICA \n\n");
    if (sem_errors > 0) {
    printf("Análise semântica concluída com %d erros\n", sem_errors);
        for (i = 0; i < sem_errors; i++) {
            printf("%s", errors[i]);
        }
    } else {
        printf("Análise semântica concluída sem erros");
        printf("\n\n");
        printf("FASE 4: Geraçao de código \n\n");
        for (i = 0; i < ic_idx; i++) {
            printf("%s", icg[i]);
        }
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
        printf("%-25s |%-25s |%-15s |%-15s |%-7s |%3d |%3d |%-20s | %d\n", symbol_table[i].id_name, symbol_table[i].data_type,
               symbol_table[i].type, symbol_table[i].class_name, aux_line, symbol_table[i].class_scope, symbol_table[i].scope, symbol_table[i].file_name, symbol_table[i].num_param);
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
    if (strlen(tree->token) > 0) {
    	printf("%s, ", tree->token);
    }
	if (tree->right) {
		printInorder(tree->right);
	}
}

void insert_type() {
    strcpy(type, yytext);
}

void check_function_return(const char *value) {
	char *function_datatype = get_type_function(symbol_table[count-1].data_type, symbol_table[count-1].class_scope);
    char *return_datatype = get_type(value);
    if (strcmp(value, function_datatype)) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo de retorno\n", countn[count_file_name], file_name_current[count_file_name]);
    }
}

void check_types(const char *type1, const char *type2){
	if (!strcmp(type1, type2) || !strcmp(type2, "NULL"))
		return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo na atribuição\n", countn[count_file_name], file_name_current[count_file_name]);
}

void check_types_atributes(const char *token, const char *type2){
    int i;
    char *type1;
	for (i = count-1; i >= 0; i--)  {
        if (!strcmp(symbol_table[i].id_name, token)) {
            type1=strdup(symbol_table[i].data_type);            
            break;
        }
    }
    if (type1 == NULL) {
        return;
    }
    if (!strcmp(type1, type2) || !strcmp(type2, "NULL"))
		return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Incompatibilidade de tipo na atribuição\n", countn[count_file_name], file_name_current[count_file_name]);
}

void check_declaration(const char *c) {    
    q = search(c, class_scope_count, scope_count);
    if (!q) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: \"%s\" não foi declarada!\n", countn[count_file_name], file_name_current[count_file_name], c);  
    }
}

void check_class_declaration(const char *c) {
    int i, q = 0;
    for (i = count-1; i >= 0; i--)  {
        if (!strcmp(symbol_table[i].id_name, c)) {
            q = 1;
            break;
        }
    }
    if (!q) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: A classe \"%s\" não foi declarada!\n", countn[count_file_name], file_name_current[count_file_name], c);  
    }
}

void check_declaration_previously(const char *c) {    
    q = search(c, class_scope_count, scope_count);
    if (!q) return;

    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: \"%s\" já foi declarada anteriormente!\n", countn[count_file_name], file_name_current[count_file_name], c);  
}

void check_atribute(const char *object, const char *atribute) {

    int i; 
    char *class_name_target;
    for (i = count-1; i >= 0; i--)  {
        if (strcmp(symbol_table[i].id_name, object) == 0) {   
            class_name_target = strdup(symbol_table[i].data_type);
            break;
        }
    }
    for (i = count-1; i >= 0; i--)  {
        if ((strcmp(symbol_table[i].class_name, class_name_target) == 0) && (strcmp(symbol_table[i].id_name, atribute) == 0)) {   
            return;
        }
    }
    sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O atributo %s não existe na classe %s\n", countn[count_file_name], file_name_current[count_file_name], atribute, class_name_target);
}

void check_method(const char *object, const char *method, struct param_types *head) {
    int i, j; 
    char *class_name_target;
    for (i = count-1; i >= 0; i--)  {
        if (strcmp(symbol_table[i].id_name, object) == 0) {   
            class_name_target = strdup(symbol_table[i].data_type);
            break;
        }
    }
    if (strcmp(symbol_table[i].type, "Object")) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O %s não é um objeto\n", countn[count_file_name], file_name_current[count_file_name], object);
        return;
    }
    for (i = count-1; i >= 0; i--)  {
        if ((strcmp(symbol_table[i].class_name, class_name_target) == 0) && (strcmp(symbol_table[i].id_name, method) == 0)) {   
            if (symbol_table[i].num_param != count_param_vector) {
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O método %s espera %d parametros e recebeu %d\n", countn[count_file_name], file_name_current[count_file_name], method, symbol_table[i].num_param, count_param_vector);
            }
            int count_paran_index = 1;
            struct param_types *temp = head;
            for (j = i+1; j <= i+count_param_vector; j++)  {
                if (temp != NULL) {
                    if ((strcmp(symbol_table[j].data_type, temp->type) != 0)) {
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

void check_vector_init(struct param_types *head) {
    if (symbol_table[count-1].num_param < count_param_vector) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O vetor %s, está recebendo mais valores do que o esperado\n", countn[count_file_name], file_name_current[count_file_name], symbol_table[count-1].id_name);
        return;
    }else if (symbol_table[count-1].num_param > count_param_vector) {
        sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O vetor %s, está recebendo menos valores do que o esperado\n", countn[count_file_name], file_name_current[count_file_name], symbol_table[count-1].id_name);
        return;
    }

    struct param_types *temp = head;

    while(temp != NULL) {
        if (strcmp(temp->type, symbol_table[count-1].data_type)) {
            sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: O vetor está recebendo um tipo não esperado\n", countn[count_file_name], file_name_current[count_file_name]);
        }
        temp = temp->next;
    }
}

void check_vector_atribt(const char *vector_name, const char *type, int position) {
    int i;
    for (i = count-1; i >= 0; i--)  {
        if (!strcmp(symbol_table[i].id_name, vector_name)) {
            if (position >= symbol_table[i].num_param || position < 0) {
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Posição invalida na atribuição do vetor %s\n", countn[count_file_name], file_name_current[count_file_name], vector_name);
            }
            if (strcmp(symbol_table[i].data_type, type)) {
                sprintf(errors[sem_errors++], "Erro semântico na linha %d, arquivo %s: Atibuição do vetor %s invalida, tipos diferentes\n", countn[count_file_name], file_name_current[count_file_name], vector_name);
            }
            break;
        }
    }
}

char *get_type(const char *var){
	for (int i = 0; i < count; i++)  {
		if (!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}

char *get_type_function(const char *var, int scope){
	for (int i = 0; i < count; i++)  {
		if (!strcmp(symbol_table[i].id_name, var) && scope == symbol_table[i].class_scope) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}



void add(char c) {
    q = search(yytext, class_scope_count, scope_count);
    if (!q) {
        if (c == 'H') {
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
        else if (c == 'K') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Keyword");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if (c == 'V') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Variable");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }  else if (c == 'F') {
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
        }else if (c == 'Z') {
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
        }else if (c == 'O') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Object");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'A') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Attribute");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'X') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Vector");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'P') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Parameter");   
            symbol_table[count].file_name=strdup(file_name_current[count_file_name]);
            symbol_table[count].class_name=strdup(class_name_current);
            symbol_table[count].class_scope=class_scope_count;
            symbol_table[count].scope=scope_count;
            count++;  
        }else if (c == 'R') {
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
        } else if (c == 'J') {
            symbol_table[count].id_name=strdup(yylval.nd_obj.name);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn[count_file_name];
            symbol_table[count].type=strdup("Vector");   
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
    for (i = count-1; i >= 0; i--)  {
        if (strcmp(symbol_table[i].id_name, type) == 0 && symbol_table[i].class_scope == cl_scope && strcmp(symbol_table[i].type, "Attribute") == 0) {
            aux_return = 1;
            break;
        }
    }
    if (!aux_return) {
        for (i = count-1; i >= 0; i--)  {
            if (strcmp(symbol_table[i].id_name, type) == 0 && symbol_table[i].scope == f_scope) {
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