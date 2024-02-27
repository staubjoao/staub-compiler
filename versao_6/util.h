#ifndef UTIL_H
#define UTIL_H

#define MAX_SYMBOLS 100
#define MAX_FILE_NAME_LEN 30
#define MAX_TOKEN_LEN 20

int princial_bool = 0;

struct node
{
    struct node *left;
    struct node *right;
    char *token;
};

struct tree_class_l
{
    struct node *head;
    char *file_name;
    struct tree_class_l *next;
};

struct param_types
{
    char *type;
    struct param_types *next;
};
struct dataType
{
    char *id_name;
    char *data_type;
    char *type;
    char *file_name;
    char *class_name;
    int num_param;
    int class_scope;
    int scope;
    int line_no;
} symbol_table[MAX_SYMBOLS];

struct node *class_aux;
struct tree_class_l *head_class_l;
void printtree(struct node *);
void printInorder(struct node *);

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
void check_method(const char *, const char *, struct param_types *head);
void check_vector_init(struct param_types *head);
void check_vector_atribt(const char *, const char *, int);
void check_function_return(const char *);
void check_types(const char *, const char *);
void check_types_atributes(const char *, const char *);
char *get_type(const char *);
char *get_type_function(const char *, int scope);
struct node *mknode(struct node *left, struct node *right, const char *token);

struct node *class_aux = NULL;
struct tree_class_l *head_class_l = NULL;
struct tree_class_l *head_class_l_aux = NULL;

int count_file_name;
char file_name_current[2][MAX_FILE_NAME_LEN];
char *class_name_current;
int count = 0;
int q;
char type[10];
char *function_return;
char *vector_name_aux;
extern int countn[2];
struct node *head = NULL;
int sem_errors = 0;
int ic_idx = 0;
int temp_var = 0;
int label = 0;
int is_for = 0;
int count_param_vector = 0;
int class_scope_count = 0;
int scope_count = 0;
struct param_types *head_params_l = NULL;
int method_current;
char buff[100];
char errors[100][200];
char *errors_msg_aux;
char icg[50][100];

#endif