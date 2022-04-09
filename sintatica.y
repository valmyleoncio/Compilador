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
	string valor;
	int linha;
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
void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2);
%}

%token TK_NUM TK_REAL TK_CHAR TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOLEAN
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_IGUAL_IGUAL TK_DIFERENTE TK_MAIS_MAIS TK_MENOS_MENOS TK_OU TK_E
%token TK_IF TK_ELSE TK_WHILE TK_FOR
%token TK_ERROR

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
			| BLOCO
			{
				$$.traducao = $1.traducao;
			}
			| TK_IF '(' E ')' E ';' COMANDOS
			{
				$$.traducao = $3.traducao + $5.traducao + $7.traducao;
			}
			| TK_IF '(' E ')' E ';' TK_ELSE E ';' COMANDOS
			{
				$$.traducao = $3.traducao + $5.traducao + $8.traducao + $10.traducao;
			}
			| TK_IF '(' E ')' E ';' TK_ELSE BLOCO
			{
				$$.traducao = $3.traducao + $5.traducao + $8.traducao;
			}
			| TK_IF '(' E ')' BLOCO
			{
				$$.traducao = $3.traducao + $5.traducao;
			}
			| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO
			{
				$$.traducao = $3.traducao + $5.traducao + $7.traducao;
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

E 			: E '+' M
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " + " + $3.label + ";\n";
					addTemp($$.label, $$.tipo);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					$$.tipo = $3.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " + " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					$$.tipo = $1.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " + " + labelAux + ";\n";
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +  ": Operandos com tipo inválidos.");
				}
			}
			| E '-' M
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
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +  ": Operandos com tipo inválidos.");
				}
			}
			| E '>' E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " > " + $3.label + ";\n";
			}
			| E '<' E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " < " + $3.label + ";\n";
			}
			| E TK_MAIOR_IGUAL E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " >= " + $3.label + ";\n";
			}
			| E TK_MENOR_IGUAL E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " <= " + $3.label + ";\n";
			}
			| E TK_IGUAL_IGUAL E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " == " + $3.label + ";\n";
			}
			| E TK_DIFERENTE E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " != " + $3.label + ";\n";
			}
			| E TK_OU E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " || " + $3.label + ";\n";
			}
			| E TK_E E
			{
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " && " + $3.label + ";\n";
			}
			| '!' E
			{
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $2.traducao + "\t" + 
				$$.label + " = " + "!" + $2.label + ";\n";
			}
			| TK_ID TK_MAIS_MAIS
			{
				verificarVariavelExistente($1.label);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}
			| TK_ID TK_MENOS_MENOS
			{
				verificarVariavelExistente($1.label);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " - 1" + ";\n";
			}
			| TK_TIPO_FLOAT '(' E ')'
			{		
				$$.label = gentempcode();
				$$.tipo  = "float";

				addTemp($$.label, $$.tipo);
				
				if($3.tipo == "int")
				{	
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(float) " + $3.label + ";\n";  
				} else if ($3.tipo == "float")
				{
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(float) " + $3.label + ";\n";
					cout << "\n\033[1;33mWarning\033[0m - Linha " + std::to_string($3.linha) +  ": Muleque burro, ja é o tipo certo.\n";
				}
				else
				{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +  ": Casting inválido");
				}
			}
			| TK_TIPO_INT '(' E ')'
			{	
				$$.label = gentempcode();
				$$.tipo  = "int";
				addTemp($$.label, $$.tipo);

				if($3.tipo == "float")
				{
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(int) " + $3.label + ";\n";
				} else if ($3.tipo == "int"){
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(int) " + $3.label + ";\n";
					cout << "\n\033[1;33mWarning\033[0m - Linha " + std::to_string($3.linha) +  ": Muleque burro, ja é o tipo certo.\n";
				}else{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +  ": Casting inválido");
				}
			}
			| TK_ID '=' E
			{
				verificarVariavelExistente($1.label);
				TIPO_SIMBOLO variavel = getSimbolo($1.label);

				if(variavel.tipoVariavel == $3.tipo){
					if($3.tipo == "boolean"){
						$$.traducao = $1.traducao  + $3.traducao +"\t" + 
				    	variavel.labelVariavel + " = " + $3.label + ";\n";
					} else {
						$$.traducao = $1.traducao + $3.traducao + "\t" + 
				    	variavel.labelVariavel + " = " + $3.label + ";\n";
					}
					
				}

				else if (variavel.tipoVariavel == "int" & $3.tipo == "float")
				{
					$$.label = gentempcode();
					addTemp($$.label, "int");
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (int) " + $3.label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + $$.label + ";\n";
				}
				else if (variavel.tipoVariavel == "float" & $3.tipo == "int")
				{
					$$.label = gentempcode();
					addTemp($$.label, "float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + $$.label + ";\n";
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +  ": Atribuição inválida, tipos diferentes.");
				}
			}
			| M
			{
			}
			;

M 			: M '*' P
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " * " + $3.label + ";\n";
					addTemp($$.label, $$.tipo);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					$$.tipo = $3.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " * " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					$$.tipo = $1.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " * " + labelAux + ";\n";
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +  ": Operandos com tipos inválidos.");
				}
			}
			| M '/' P
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;
				
				string aux = $3.valor;
				int cont = 0;
				int ponto = 0;

				for(int i = 0; i < aux.size(); i++)
				{
					if(aux[i] == '.')
					{
						ponto = 1;
					}
					if(aux[i] == '0')
					{
						cont++;
					}
				}

				if(cont == aux.size() || (cont + ponto) == aux.size()){
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string($3.linha) +  ":\033[0m\033[1;39m Operação inválida, divisão por 0");
				}

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
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +  ": Operandos com tipos inválidos.");
				}
			}
			| M '%' P
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == "int" & $3.tipo == "int"){
					tipoAux = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " % " + $3.label + ";\n";
					addTemp($$.label, tipoAux);
				}
				else{
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +  ": operandos inválidos para % (Presença de float).");
				}
			}
			| P
			{
			}
			;

P 			: '(' E ')'
			| TK_NUM
			{
				$$.tipo = "int";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				$$.valor = $1.label;
			}
			| TK_REAL
			{
				$$.tipo = "float";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				$$.valor = $1.label;
			}
			| TK_CHAR
			{
				$$.tipo = "char";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_TRUE
			{
				$$.tipo = "boolean";
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = "\t" + $$.label + " = " + "1" + ";\n";	
			}
			| TK_FALSE
			{
				$$.tipo = "boolean";
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = "\t" + $$.label + " = " + "0" + ";\n";		
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
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($1.linha) +  ": A variavel '" + $1.label + "' não foi instanciada.");
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

void verificarVariavelExistente(string nomeVariavel){
	bool result = false;
	for (int i = 0; i < tabelaSimbolos.size(); i++){
		if(tabelaSimbolos[i].nomeVariavel == nomeVariavel){
			result = true;
		}
	}
	
	if(!result)	{
		yyerror("\n\033[1;31mError\033[0m - Linha : A variável '" + nomeVariavel + "' não foi instanciada");

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
	if(valor.tipoVariavel == "boolean"){
		valor.tipoVariavel = "int";
	}
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void addTemp(string label, string tipo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = tipo;
	tabelaTemp.push_back(valor);
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2){
	if(tipo_1.tipo == "char" || tipo_2.tipo == "char")
	{
		yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string(tipo_1.linha) +  ": Operação relacional inválida.");
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