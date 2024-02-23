#ifndef UTIL_H
#define UTIL_H

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

struct node *class_aux;
struct tree_class_l *head_class_l;
void printtree(struct node *);
void printInorder(struct node *);

#endif