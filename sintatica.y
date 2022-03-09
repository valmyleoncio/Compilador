%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};

typedef struct
{
	string nomeVariavel;
	string tipoVariavel;
	string labelVariavel;
	string atribuicao;
}	TIPO_SIMBOLO;

vector<TIPO_SIMBOLO> tabelaSimbolos;
string atribuicaoVariavel = "";

int yylex(void);
void yyerror(string);
string gentempcode();
string cast(TIPO_SIMBOLO var1, TIPO_SIMBOLO var2);
void verificarVariavelRepetida(string variavel);
TIPO_SIMBOLO getSimbolo(string variavel);
%}

%token TK_NUM TK_REAL TK_CHAR
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOLEAN
%token TK_FIM TK_ERROR

%start S

%left '+'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "\n/*Compilador SDDSEAD*/\n\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << atribuicaoVariavel + "\n" + $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			| TK_TIPO_INT TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				verificarVariavelRepetida(valor.nomeVariavel);
				valor.tipoVariavel = "int";
				valor.labelVariavel = gentempcode();

				atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";

				$$.traducao = "";
				$$.label = "";

				tabelaSimbolos.push_back(valor);
			}			
			| TK_TIPO_FLOAT TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				verificarVariavelRepetida(valor.nomeVariavel);
				valor.tipoVariavel = "float";
				valor.labelVariavel = gentempcode();

				atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";

				$$.traducao = "";
				$$.label = "";

				tabelaSimbolos.push_back(valor);
			}
			| TK_TIPO_CHAR TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				verificarVariavelRepetida(valor.nomeVariavel);
				valor.tipoVariavel = "char";
				tabelaSimbolos.push_back(valor);

				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_BOOLEAN TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				verificarVariavelRepetida(valor.nomeVariavel);
				valor.tipoVariavel = "boolean";
				tabelaSimbolos.push_back(valor);

				$$.traducao = "";
				$$.label = "";
			}
			;

E 			: E '+' E
			{	
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " + " + $3.label + ";\n";
			}
			| E '-' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " - " + $3.label + ";\n";
			}
			| E '*' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " * " + $3.label + ";\n";
			}
			| E '/' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " / " + $3.label + ";\n";
			}
			| TK_ID '=' E
			{
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.tipo = "int";
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + $$.tipo + " " + $$.label + ";\n";
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_REAL
			{
				$$.tipo = "float";
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + $$.tipo + " " + $$.label + ";\n";
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_CHAR
			{
				$$.tipo = "char";
				$$.label = gentempcode();
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_ID
			{
				bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == $1.label)
					{
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}	
				}

				if(!encontrei)
				{
					yyerror("Não foi declarado a variavel " + $1.label);
				}

				$$.tipo = variavel.tipoVariavel;
				$$.label = variavel.labelVariavel;
				$$.traducao = "";
			}
			;

%%

#include "lex.yy.c"

int yyparse();

string gentempcode(){
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);	
}

void verificarVariavelRepetida(string variavel){

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
		{
			yyerror("Variável ja existente");
		}
	}
}

TIPO_SIMBOLO getSimbolo(string variavel){
	for (int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
			return tabelaSimbolos[i];					
	}
}

int main(int argc, char* argv[]){
	var_temp_qnt = 0;
	yyparse();
	//string a = "\033[1;31mError\033[0m\n";
	//string b = ": só por teste mesmo\n|\n|\n|\n";
	return 0;
}

void yyerror(string MSG){
	cout << MSG << endl;
	exit (0);
}