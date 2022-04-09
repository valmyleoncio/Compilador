%{
#include <string>
int linhas = 1;
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
SINAL [-]

DELIM {ESPACO}+
NUM ({SINAL}({DIGITO}+)|{DIGITO}+)
REAL {NUM}+("."{DIGITO}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		        {linhas++;}

{DELIM} 	        {}

"main"		        {return TK_MAIN;}

"int"		        {return TK_TIPO_INT;}

"float"		        {return TK_TIPO_FLOAT;}

"char"		        {return TK_TIPO_CHAR;}

"boolean"	        {return TK_TIPO_BOOLEAN;}

"true"              { yylval.linha = linhas; return TK_TRUE; }

"false"             { yylval.linha = linhas; return TK_FALSE; }

"if"                { return TK_IF; }

"else"              { return TK_ELSE; }

"while"             { return TK_WHILE; }

"for"               { return TK_FOR; }

"do"                { return TK_DO; }

"switch"            { return TK_SWITCH; }

"case"              { return TK_CASE; }

"break"             { return TK_BREAK; }

"continue"          { return TK_CONTINUE; }

[(){}[\];,:]	    { return *yytext; }

[+\-*/%!&|<>""]		{ return *yytext; }

"="		            { return *yytext; }

">="		        { return TK_MAIOR_IGUAL; }

"<="		        { return TK_MENOR_IGUAL; }

"=="		        { return TK_IGUAL_IGUAL; }

"!="		        { return TK_DIFERENTE; }

"++"		        { return TK_MAIS_MAIS; }

"--"		        { return TK_MENOS_MENOS; }

"||"		        { return TK_OU; }

"&&"		        { return TK_E; }

{NUM}		{ yylval.label = yytext; yylval.linha = linhas; return TK_NUM; }
{REAL}		{ yylval.label = yytext; yylval.linha = linhas; return TK_REAL; }
{CHAR}		{ yylval.label = yytext; yylval.linha = linhas; return TK_CHAR; }
{ID}		{ yylval.label = yytext; yylval.linha = linhas; return TK_ID; }

.			{ *yytext; }
%%
