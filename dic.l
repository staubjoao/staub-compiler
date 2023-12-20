%{
    // #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alphaMin [a-z]
alphaMax [A-Z]
alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

%%

"imprime"                      { printf("PRINTFF\n"); }
"leia"                         { printf("SCANFF\n"); }
"inteiro"                      { printf("INT\n"); }
"decimal"                      { printf("FLOAT\n"); }
"caracter"                     { printf("CHAR\n"); }
"palavra"                      { printf("STRING\n"); }   
"vazio"                        { printf("VOID\n"); }
"retorne"                      { printf("RETURN\n"); }
"enquanto"	                   { printf("WHILE\n"); }
"se"	                       { printf("IF\n"); }
"senao"	                       { printf("ELSE\n"); }
"forma"                        { printf("CLASS\n"); }
^"#include"[ ]*<.+\.h>         { printf("INCLUDE\n"); }
[-]?{digit}+                   { printf("NUMBER\n"); }
[-]?{digit}+\.{digit}{1,6}     { printf("FLOAT_NUM\n"); }
{alphaMin}({alpha}|{digit})*   { printf("ID\n"); }
{alphaMax}{alpha}              { printf("CLASS_NAME\n"); }
{unary}                        { printf("UNARY\n"); }
"<="                           { printf("LE\n"); }
">="                           { printf("GE\n"); }
"=="                           { printf("EQ\n"); }
"!="                           { printf("NE\n"); }
">"	                           { printf("GT\n"); }
"<"	                           { printf("LT\n"); }
"&&"	                       { printf("AND\n"); }
"||"	                       { printf("OR\n"); }
"+"                            { printf("ADD\n"); }
"-"                            { printf("SUBTRACT\n"); }
"/"                            { printf("DIVIDE\n"); }
"*"                            { printf("MULTIPLY\n"); }
\/\/.*                         { ; }
\/\*(.*\n)*.*\*\/              { ; } 
[ \t]*                         { ; }
[\n]                           { countn++; }
.	                           { printf(" yytext\n"); }
["].*["]                       { printf("STR\n"); }
['].[']                        { printf("CHARACTER\n"); }

%%

int main(){
    yylex();
}

int yywrap() {
    printf("1\n");
}
