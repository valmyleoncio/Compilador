%{
#include <string>
#include <vector>
int linhas = 1;
int contextoAtual = 0;
void removerSimbolos();
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
SINAL [-]
SIMBOLO [-+*/=.":;<=>!#$£%¢&?@[\]^`{|}¹²³ 0x0020]

DELIM {ESPACO}+
NUM ({SINAL}({DIGITO}+)|{DIGITO}+)
REAL {NUM}+("."{DIGITO}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*
STRING \"({LETRA}|{NUM}|{SIMBOLO})*\"

%%

"\n"		        {linhas++;}

{DELIM} 	        {}

"main"		        { yylval.contexto = contextoAtual; return TK_MAIN;}

"int"		        { yylval.contexto = contextoAtual; return TK_TIPO_INT;}

"float"		        { yylval.contexto = contextoAtual; return TK_TIPO_FLOAT;}

"char"		        { yylval.contexto = contextoAtual; return TK_TIPO_CHAR;}

"string"		    { yylval.contexto = contextoAtual; return TK_TIPO_STRING;}

"boolean"	        { yylval.contexto = contextoAtual; return TK_TIPO_BOOLEAN;}

"true"              { yylval.linha = linhas; return TK_TRUE; }

"false"             { yylval.linha = linhas; return TK_FALSE; }

"if"                { return TK_IF; }

"else"              { return TK_ELSE; }

"while"             { return TK_WHILE; }

"for"               { return TK_FOR; }

"do"                { yylval.traducao = "DO"; return TK_DO; }

"switch"            { return TK_SWITCH; }

"case"              { yylval.contexto = contextoAtual; return TK_CASE;}

"break"             { return TK_BREAK; }

"continue"          { return TK_CONTINUE; }

"print"             { yylval.contexto = contextoAtual; return TK_PRINT; }

"scan"              { yylval.contexto = contextoAtual; return TK_SCAN; }

"{"                 { contextoAtual++; return *yytext;}

"}"                 { contextoAtual--; return *yytext;}

[()[\];,:]	        { return *yytext; }

[+\-*/%!&|<>""]		{ yylval.contexto = contextoAtual; return *yytext; }

"="		            { yylval.contexto = contextoAtual; return *yytext; }

">="		        { yylval.contexto = contextoAtual; return TK_MAIOR_IGUAL; }

"<="		        { yylval.contexto = contextoAtual; return TK_MENOR_IGUAL; }

"=="		        { yylval.contexto = contextoAtual; return TK_IGUAL_IGUAL; }

"!="		        { yylval.contexto = contextoAtual; return TK_DIFERENTE; }

"++"		        { yylval.contexto = contextoAtual; return TK_MAIS_MAIS; }

"--"		        { yylval.contexto = contextoAtual; return TK_MENOS_MENOS; }

"||"		        { yylval.contexto = contextoAtual; return TK_OU; }

"&&"		        { yylval.contexto = contextoAtual; return TK_E; }

{NUM}		{yylval.label = yytext; yylval.linha = linhas; yylval.contexto = contextoAtual; return TK_NUM;}
{REAL}		{yylval.label = yytext; yylval.linha = linhas; yylval.contexto = contextoAtual; return TK_REAL;}
{CHAR}		{yylval.label = yytext; yylval.linha = linhas; yylval.contexto = contextoAtual; return TK_CHAR;}
{STRING}	{yylval.valor = yytext; yylval.linha = linhas; yylval.contexto = contextoAtual; return TK_STRING;}
{ID}		{yylval.label = yytext; yylval.linha = linhas; yylval.contexto = contextoAtual; return TK_ID;}

.			{ *yytext; }
%%