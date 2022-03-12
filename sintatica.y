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
};

typedef struct
{ 
	string nomeVariavel;
	string tipoVariavel;


}SYMBOL_TYPE;

vector<SYMBOL_TYPE> tabelaSimbolos;

int yylex(void);
void yyerror(string);
string gentempcode();
%}

%token TK_NUM
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOLEAN
%token TK_FIM TK_ERROR

%start S

%left '+'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "\n/*Compilador SDDSEAD*/\n\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
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
			|TK_TIPO_INT TK_ID ';'
			{
				SYMBOL_TYPE batata;
				batata.nomeVariavel = $2.label;
				batata.tipoVariavel = "int";
				tabelaSimbolos.push_back(batata);

				$$.traducao = "";
				$$.label = "";

			}
			;

E 			: E '+' E
			{
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " + " + $3.label + ";\n";
			}
			| E '-' E
			{
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " - " + $3.label + ";\n";
			}
			| E '*' E
			{
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " * " + $3.label + ";\n";
			}
			| E '/' E
			{
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " / " + $3.label + ";\n";
			}
			| TK_ID '=' E
			{
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.label = gentempcode();
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_ID
			{
				$$.label = gentempcode();
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
<<<<<<< Updated upstream
=======
			| TK_ID
			{
				bool encontrei = false;
				TIPO_SIMBOLO variavel = getSimbolo($1.label);
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{

					if(tabelaSimbolos[i].nomeVariavel == $1.label)
					{
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}	
				}

				if(!encontrei)
				{
					yyerror("erro: a variavel '" + $1.label + "' não foi instanciada");
				}

				$$.tipo = variavel.tipoVariavel;
				$$.label = variavel.labelVariavel;
				$$.traducao = "";
			} // conversao explicita:
			|TK_TIPO_FLOAT '('TK_ID')'
			{ 
				TIPO_SIMBOLO variavel = getSimbolo($1.label);
				TIPO_SIMBOLO variavel2 = getSimbolo($3.label);

				if (variavel.tipoVariavel == "float" && variavel2.tipoVariavel == "int")
				{
						$$.label = gentempcode();
						$$.traducao = "\t" + $$.label + " = " + "(float) " + $3.label + ";\n";  
				}
					else
					{
								yyerror("operacao invalida ");
					}  

			}
			|TK_TIPO_INT '('TK_ID')'
			{ 
				TIPO_SIMBOLO variavel = getSimbolo($1.label);
				TIPO_SIMBOLO variavel2 = getSimbolo($3.label);

					if (variavel.tipoVariavel == "int" && variavel2.tipoVariavel == "float")
				{
					$$.label = gentempcode();
					$$.traducao = "\t" + $$.label + " = " + "(int) " + $3.label + ";\n";  
				}
					else
					{
						yyerror("operacao invalida");
					}

			}
			
			
			
			
			
>>>>>>> Stashed changes
			;

%%

#include "lex.yy.c"

int yyparse();

string gentempcode()
{
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);	
}

int main(int argc, char* argv[])
{
	


	var_temp_qnt = 0;
	yyparse();
	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}