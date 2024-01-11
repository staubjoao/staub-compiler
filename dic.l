%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alphaMin [a-z]
alphaMax [A-Z]
alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

%%

"principal"                    { return TK_MAIN; }
"imprime"                      { return TK_PRINTF; }
"leia"                         { return TK_SCANFF; }
"inteiro"                      { return TK_TYPE_INT; }
"decimal"                      { return TK_TYPE_FLOAT; }
"caracter"                     { return TK_TYPE_CHAR; }
"palavra"                      { return TK_TYPE_STRING; }    
"vazio"                        { return TK_VOID; }
"retorne"                      { return TK_RETURN; }
"enquanto"	                   { return TK_WHILE; }
"se"	                       { return TK_IF; }
"senao"	                       { return TK_ELSE; }
"forma"                        { return TK_CLASS; }
^"#include"[ ]*<.+\.h>         { return TK_INCLUDE; }
[-]?{digit}+                   { return TK_NUMBER; }
[-]?{digit}+\.{digit}{1,6}     { return TK_FLOAT_NUM; }
{alphaMin}({alpha}|{digit})*   { return TK_ID; }
{alphaMax}{alpha}              { return TK_CLASS_NAME; }
{alpha}({alphaMax}|{digit})    { return TK_METHOD_NAME; }
{unary}                        { return TK_UNARY; }
"<="                           { return TK_LE; }
">="                           { return TK_GE; }
"=="                           { return TK_EQ; }
"!="                           { return TK_NE; }
">"	                           { return TK_GT; }
"<"	                           { return TK_LT; }
"&&"	                       { return TK_AND; }
"||"	                       { return TK_OR; }
"+"                            { return TK_ADD; }
"-"                            { return TK_SUBTRACT; }
"/"                            { return TK_DIVIDE; }
"*"                            { return TK_MULTIPLY; }
\/\/.*                         { ; }
\/\*(.*\n)*.*\*\/              { ; } 
[ \t]*                         { ; }
[\n]                           { countn++; }
.	                           { return *yytext;  }
["].*["]                       { return TK_STRING; }
['].[']                        { return TK_CHAR; }

%%

int yywrap() {
    return 1;
}
