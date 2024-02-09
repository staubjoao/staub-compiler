#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_FILENAME_LEN 30

struct dataType
{
    char *id_name;
    char *data_type;
    char *type;
    int line_no;
    char filename[MAX_FILENAME_LEN];
} symbol_table[MAX_SYMBOLS];

int symbol_count = 0;
int count_lines = 1;

void add(char c)
{
    if (symbol_count < MAX_SYMBOLS)
    {
        if (c == 'H')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("teste");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Header");
            symbol_count++;
        }
        else if (c == 'K')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("N/A");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Keyword\t");
            symbol_count++;
        }
        else if (c == 'V')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("teste");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Variable");
            symbol_count++;
        }
        else if (c == 'C')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("CONST");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Constant");
            symbol_count++;
        }
        else if (c == 'F')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("teste");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Function");
            symbol_count++;
        }
        else if (c == 'Z')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("teste");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Class");
            symbol_count++;
        }
        else if (c == 'O')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("teste");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Object");
            symbol_count++;
        }
        else if (c == 'A')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("teste");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Attribute");
            symbol_count++;
        }
        else if (c == 'X')
        {
            symbol_table[symbol_count].id_name = strdup("teste");
            symbol_table[symbol_count].data_type = strdup("teste");
            symbol_table[symbol_count].line_no = count_lines;
            symbol_table[symbol_count].type = strdup("Vector");
            symbol_count++;
        }
    }
    else
    {
        printf("Symbol table full. Cannot insert symbol\n");
    }
}

void print_symbol_table()
{
    printf("Symbol Table:\n");
    printf("%-15s %-15s %-15s %-10s %-10s\n", "Identifier", "Data Type", "Type", "Line No", "Filename");
    for (int i = 0; i < symbol_count; i++)
    {
        printf("%-15s %-15s %-15s %-10d %-10s\n", symbol_table[i].id_name, symbol_table[i].data_type,
               symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].filename);
    }
}

int main()
{
    // Example: Insert symbols from different files
    add('A');
    add('X');
    add('O');
    add('F');
    add('K');
    add('F');
    add('A');

    // Print symbol table
    print_symbol_table();

    return 0;
}