%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alphaMax [A-Z]
alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

%%

"imprime"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_PRINTF; }
"leia"                          { strcpy(yylval.nd_obj.name,(yytext)); return TK_SCANF; }
"inteiro"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_INT; }
"decimal"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_FLOAT; }
"caracter"                      { strcpy(yylval.nd_obj.name,(yytext)); return TK_CHAR; }
"vazio"                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_VOID; }
"return"                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_RETURN; }
"enquanto"	                    { strcpy(yylval.nd_obj.name,(yytext)); return TK_FOR; }
"se"	                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_IF; }
"senao"	                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_ELSE; }
"forma"                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_CLASS_DEFINITION; }
^"#include"[ ]*<.+\.h>          { strcpy(yylval.nd_obj.name,(yytext)); return TK_INCLUDE; }
"true"                          { strcpy(yylval.nd_obj.name,(yytext)); return TK_TRUE; }
"false"                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_FALSE; }
[-]?{digit}+                    { strcpy(yylval.nd_obj.name,(yytext)); return TK_NUMBER; }
[-]?{digit}+\.{digit}{1,6}      { strcpy(yylval.nd_obj.name,(yytext)); return TK_NUMBER_FLOAT; }
{alpha}({alpha}|{digit})*       { strcpy(yylval.nd_obj.name,(yytext)); return TK_ID; }
{alphaMax}({alpha}|{digit})*    { strcpy(yylval.nd_obj.name,(yytext)); return TK_CLASS_NAME; }
{unary}                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_UNARY; }
"<="                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_LE; }
">="                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_GE; }
"=="                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_EQ; }
"!="                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_NE; }
">"	                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_GT; }
"<"	                            { strcpy(yylval.nd_obj.name,(yytext)); return TK_LT; }
"&&"	                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_AND; }
"||"	                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_OR; }
"+"                             { strcpy(yylval.nd_obj.name,(yytext)); return TK_ADD; }
"-"                             { strcpy(yylval.nd_obj.name,(yytext)); return TK_SUBTRACT; }
"/"                             { strcpy(yylval.nd_obj.name,(yytext)); return TK_DIVIDE; }
"*"                             { strcpy(yylval.nd_obj.name,(yytext)); return TK_MULTIPLY; }
\/\/.*                          { ; }
\/\*(.*\n)*.*\*\/               { ; } 
[ \t]*                          { ; }
[\n]                            { countn++; }
.	                            { return *yytext; }
["].*["]                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_STRING; }
['].[']                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_CHARACTER; }

%%

int yywrap() {
    return 1;
}
