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
}	TIPO_SIMBOLO;

typedef struct
{
	string tipoVariavel; 
	string labelVariavel;
}	TIPO_TEMP;


vector<TIPO_SIMBOLO> tabelaSimbolos;
vector<TIPO_TEMP> tabelaTemp;
string atribuicaoVariavel;

int yylex(void);
void yyerror(string);
string gentempcode();
void verificarVariavelRepetida(string variavel);
void verificarVariavelExistente(string nomeVariavel);
TIPO_SIMBOLO getSimbolo(string variavel);
void addSimbolo(string variavel, string tipo, string label);
void addTemp(string label, string tipo);
%}

%token TK_NUM TK_REAL TK_CHAR
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOLEAN TK_TRUE TK_FALSE
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
				verificarVariavelRepetida($2.label);
				addSimbolo($2.label, "int", gentempcode());
				$$.traducao = "";
				$$.label = "";
			}			
			| TK_TIPO_FLOAT TK_ID ';'
			{
				verificarVariavelRepetida($2.label);
				addSimbolo($2.label, "float", gentempcode());
				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_CHAR TK_ID ';'
			{
				verificarVariavelRepetida($2.label);
				addSimbolo($2.label, "char", gentempcode());
				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_BOOLEAN TK_ID ';'
			{
				verificarVariavelRepetida($2.label);
				addSimbolo($2.label, "boolean", gentempcode());
				$$.traducao = "";
				$$.label = "";
			}
			;

E 			: E '+' E
			{	
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					tipoAux = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " + " + $3.label + ";\n";
					addTemp($$.label, tipoAux);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " + " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " + " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
			| E '-' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					tipoAux = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " - " + $3.label + ";\n";
					addTemp($$.label, tipoAux);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " - " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " - " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
			| E '*' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					tipoAux = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " * " + $3.label + ";\n";
					addTemp($$.label, tipoAux);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " * " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " * " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
			| E '/' E
			{
				$$.label = gentempcode();
	
				string tipoAux;
				string labelAux;
	

				if($1.tipo == $3.tipo){
					tipoAux = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " / " + $3.label + ";\n";
					addTemp($$.label, tipoAux);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " / " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " / " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
			| E '%' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " % " + $3.label + ";\n";
			}
			| E '>' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " > " + $3.label + ";\n";
			}
			| E '<' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " < " + $3.label + ";\n";
			}
			| E '>''=' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " >= " + $3.label + ";\n";
			}
			| E '<''=' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " <= " + $3.label + ";\n";
			}
			| TK_ID '=''=' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " == " + $3.label + ";\n";
			}
			| TK_ID '!''=' E
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " != " + $3.label + ";\n";
			}
			| TK_ID '=' E
			{
				verificarVariavelExistente($1.label);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.tipo = "int";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_REAL
			{
				$$.tipo = "float";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_CHAR
			{
				$$.tipo = "char";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_ID
			{
				bool encontrei = false;
				TIPO_SIMBOLO variavel = getSimbolo($1.label);
				for(int i = 0; i < tabelaSimbolos.size(); i++){
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
			}
			 // conversao explicita:
			|TK_TIPO_FLOAT '('TK_ID')'
			{ 
				TIPO_SIMBOLO variavel = getSimbolo($1.label);
				TIPO_SIMBOLO variavel2 = getSimbolo($3.label);


				if (variavel.tipoVariavel == "float" && variavel2.tipoVariavel == "int")
				{
						$$.label = gentempcode();
						$$.traducao =  "\t" + $$.label + " = " + "(float) " + $3.label + ";\n";  
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
			|TK_TIPO_FLOAT '('E')'
			{		
				$$.label = gentempcode();
				$$.tipo  = "float";
				$3.traducao = "\t" + $1.label + "=" + $3.label + ";\n";

				addTemp($$.label, $$.tipo);
				
				if($3.tipo == "int")
					{	
						$$.traducao = "\t" + $$.label + " = " + "(float) " + $3.label + ";\n";  
					}else
						{
							yyerror("operacao invalida");
						}

			
			}
			|TK_TIPO_INT '('E')'
			{	
				$$.label = gentempcode();
				$$.tipo  = "int";
				addTemp($$.label, $$.tipo);
			

				if($3.tipo == "float")
					{
						$$.traducao = "\t" + $$.label + " = " + "(int) " + $3.label + ";\n";  
					}else
						{
							yyerror("operacao invalida");
						}

			
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

void verificarVariavelExistente(string nomeVariavel){
	bool result = false;
	for (int i = 0; i < tabelaSimbolos.size(); i++){
		if(tabelaSimbolos[i].nomeVariavel == nomeVariavel){
			result = true;
		}
	}
	
	if(!result)	{
		yyerror("erro: a variavel '" + nomeVariavel + "' não foi instanciada");
	}
}

TIPO_SIMBOLO getSimbolo(string variavel){
	for (int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
			return tabelaSimbolos[i];					
	}
}

void addSimbolo(string variavel, string tipo, string label){
	TIPO_SIMBOLO valor;
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;
	tabelaSimbolos.push_back(valor);
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void addTemp(string label, string tipo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = tipo;
	tabelaTemp.push_back(valor);
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
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