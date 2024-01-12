%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"

    struct node* mknode(struct node *left, struct node *right, char *token);

    
    void yyerror(const char *s);
    int yylex();
    int yywrap();

    char reserved[10][10] = {"inteiro", "decimal", "caracter", "vazio", "se", "senao", "forma", "principal", "retorne", "include"};

    struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};
%}

%union { struct var_name { 
			char name[100]; 
			struct node* nd;
		} nd_obj;

		struct var_name2 { 
			char name[100]; 
			struct node* nd;
			char type[5];
		} nd_obj2; 

		struct var_name3 {
			char name[100];
			struct node* nd;
			char if_body[5];
			char else_body[5];
		} nd_obj3;
    } 
%token TK_VOID
%token <nd_obj> TK_MAIN TK_PRINTF TK_SCANFF TK_TYPE_INT TK_TYPE_FLOAT TK_TYPE_CHAR TK_TYPE_STRING TK_RETURN TK_WHILE TK_IF TK_ELSE TK_CLASS TK_INCLUDE TK_NUMBER TK_FLOAT_NUM TK_ID TK_CLASS_NAME TK_METHOD_NAME TK_UNARY TK_LE TK_GE TK_EQ TK_NE TK_GT TK_LT TK_AND TK_OR TK_ADD TK_SUBTRACT TK_DIVIDE TK_MULTIPLY TK_STRING TK_CHAR
%token <nd_obj2> headers main body return datatype statement arithmetic relop program else
%token <nd_obj3> condition

%% 

program: headers main '(' ')' '{' body return '}' { $2.nd = mknode($6.nd, $7.nd, "main"); $$.nd = mknode($1.nd, $2.nd, "program"); 
	head = $$.nd;
} 
; 

headers: headers headers { $$.nd = mknode($1.nd, $2.nd, "headers"); }
| TK_INCLUDE { add('H'); } { $$.nd = mknode(NULL, NULL, $1.name); }
;

main: datatype TK_ID { add('F'); }
;


/* 
program: line
| program line
;

line: type_decl_int
| TK_PRINTF expr ';' { printf("%d\n", $2); }
| TK_PRINTF TK_NUMBER ';' { printf("%d\n", $2); }
;


type_decl_int: 
TK_TYPE_INT TK_ID '=' TK_NUMBER ';' { printf("declarou com valor\n"); }
| TK_TYPE_INT TK_ID ';' { printf("declarou sem valor\n"); }
;

expr: term
| expr TK_ADD term { $$ = $1 + $3; }
| expr TK_SUBTRACT term { $$ = $1 - $3; } 
| expr TK_MULTIPLY term { $$ = $1 * $3; } 
;

term: TK_NUMBER { $$ = $1; }
;


*/

%%

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}