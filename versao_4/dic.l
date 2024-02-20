%x INCLUDE_FILE
%{
    #include "y.tab.h"
    int countn;

    int push_file(char *);
%}

%option yylineno

alphaMax [A-Z]
alphaMin [a-z]
alpha [a-zA-Z]
alphanum {alpha}|{digit}
digit [0-9]
unary "++"|"--"

%%

"importa" { BEGIN INCLUDE_FILE; }

<INCLUDE_FILE>{alphaMin}*\.jsc  {
                             {
                               int c;

                               while ((c = input ()) && c != '\n') ;
                             }

                             if (!push_file(strdup(yytext)))
                             {
                               yyterminate ();
                             }

                             BEGIN INITIAL;
                           }

<INCLUDE_FILE>.|\n { fprintf (stderr, "Bad include line is found.\n"); yyterminate (); }

"imprime"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_PRINTF; }
"leia"                          { strcpy(yylval.nd_obj.name,(yytext)); return TK_SCANF; }
"inteiro"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_INT; }
"decimal"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_FLOAT; }
"caracter"                      { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_CHAR; }
"palavra"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_TYPE_STRING; }
"vazio"                         { strcpy(yylval.nd_obj.name,(yytext)); return TK_VOID; }
"retorno"                       { strcpy(yylval.nd_obj.name,(yytext)); return TK_RETURN; }
"enquanto"	                    { strcpy(yylval.nd_obj.name,(yytext)); return TK_FOR; }
"se"	                        { strcpy(yylval.nd_obj.name,(yytext)); return TK_IF; }
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
<<EOF>>                         { yypop_buffer_state(); if(!YY_CURRENT_BUFFER) { yyterminate(); } }

%%

int push_file(char *f) {
    printf("%s\n", f);
}

int yywrap() {
    return 1;
}
