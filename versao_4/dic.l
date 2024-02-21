%x INCLUDE_FILE
%{
    #define MAX_FILE_NAME_LEN 30

    #include "y.tab.h"
    int countn[2];
    int count_file_name;
    char file_name_current[2][MAX_FILE_NAME_LEN];
%}

%option yylineno

alphaMax [A-Z]
alphaMin [a-z]
alpha [a-zA-Z]
alphanum {alpha}|{digit}
digit [0-9]
unary "++"|"--"

%%

\/\/.*                          { ; }

importa                         BEGIN(INCLUDE_FILE);
<INCLUDE_FILE>[ \t]*
<INCLUDE_FILE>[^ \t\n]+.jsc     { 
                                  yyin = fopen(yytext, "r");
                                  if(yyin == NULL) {
                                    printf("Erro ao abrir o arquivo %s\n", yytext);
                                    exit(1);
                                  }
                                  count_file_name++;
                                  strcpy(file_name_current[count_file_name], yytext);
                                  countn[count_file_name] = 1;
                                  yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));
                                  BEGIN(INITIAL);
                                  printf("TESTE %s\n", yytext);
                                }
<INCLUDE_FILE>[^ \t\n]+         {
                                  printf("O arquivo %s não possui a extensão .jsc\n", yytext);
                                  exit(1);
                                }


"imprime"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_PRINTF; }
"leia"                          { strcpy(yylval.nd_obj.name,(yytext)); return TK_SCANF; }
"inteiro"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_INT; }
"decimal"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_FLOAT; }
"caracter"                      { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_CHAR; }
"palavra"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_STRING; }
"vazio"                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_VOID; }
"retorno"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_RETURN; }
"enquanto"	                    { strcpy(yylval.nd_obj.name,(yytext)); return TK_FOR; }
"se"	                          { strcpy(yylval.nd_obj.name,(yytext)); return TK_IF; }
"senao"	                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_ELSE; }
"forma"                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_CLASS_DEFINITION; }
"Principal"                     { strcpy(yylval.nd_obj.name,(yytext)); return TK_CLASS_DEFINITION_MAIN; }
"verdadeiro"                    { strcpy(yylval.nd_obj.name,(yytext)); return TK_TRUE; }
"falso"                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_FALSE; }

[-]?{digit}+                    { strcpy(yylval.nd_obj.name,(yytext)); return TK_NUMBER; }
[-]?{digit}+\.{digit}{1,6}      { strcpy(yylval.nd_obj.name,(yytext)); return TK_NUMBER_FLOAT; }
{alphaMax}{alpha}+              { strcpy(yylval.nd_obj.name,(yytext)); return TK_CLASS_NAME; }
{alphaMin}{alphanum}*           { strcpy(yylval.nd_obj.name,(yytext)); return TK_ID; }

{unary}                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_UNARY; }
"<="                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_LE; }
">="                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_GE; }
"=="                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_EQ; }
"!="                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_NE; }
">"	                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_GT; }
"<"	                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_LT; }
"&&"	                          { strcpy(yylval.nd_obj.name,(yytext)); return TK_AND; }
"||"	                          { strcpy(yylval.nd_obj.name,(yytext)); return TK_OR; }
"+"                             { strcpy(yylval.nd_obj.name,(yytext)); return TK_ADD; }
"-"                             { strcpy(yylval.nd_obj.name,(yytext)); return TK_SUBTRACT; }
"/"                             { strcpy(yylval.nd_obj.name,(yytext)); return TK_DIVIDE; }
"*"                             { strcpy(yylval.nd_obj.name,(yytext)); return TK_MULTIPLY; }
\/\*(.*\n)*.*\*\/               { ; } 
[ \t]*                          { ; }
[\n]                            { countn[count_file_name]++; }
.	                              { return *yytext; }
["].*["]                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_STRING; }
['].[']                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_CHARACTER; }
<<EOF>>                         { yypop_buffer_state(); count_file_name--; if(!YY_CURRENT_BUFFER) { yyterminate(); } }

%%

int yywrap() {
    return 1;
}
