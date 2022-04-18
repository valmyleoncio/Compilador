%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define YYSTYPE atributos
#define SIZESTRING 256

using namespace std;

int var_temp_qnt;
int var_lace_qnt;
int var_cond_qnt;
int var_linha_qnt = 1;
int var_lace_name_qnt = 0;

string error = "";
string warning = "";
string contLinha = "";

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string valor;
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
	string valor;
}	TIPO_TEMP;

typedef struct
{
	string nomeLaco;
	string tipoLaco;
	string fimLaco;
	string contexto;
}	TIPO_LOOP;

vector<TIPO_LOOP> tabelaLoop;
vector<vector<TIPO_SIMBOLO>> mapa;
int contextoGlobal;
vector<TIPO_TEMP> tabelaTemp;
string atribuicaoVariavel;

int yylex(void);
void yyerror(string);
string gentempcode();
string genLacecode();
string genCondcode();
string genLaceNameCode();
void verificarVariavelRepetida(string variavel);
TIPO_SIMBOLO getSimbolo(string variavel);
void addSimbolo(string variavel, string tipo, string label);
void addString(string variavel, string tipo, string label);
void addTempString(string label, string tipo);
int getSize(string str);
void addTemp(string label, string tipo);
void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2);
void atualizarContexto(int num);
void contadorDeLinha();
void pushContexto();
void popContexto();
void pushLoop(string tipo);
TIPO_LOOP getLace(string nome);
TIPO_LOOP getLaceBreak();
%}

%token TK_NUM TK_REAL TK_CHAR TK_TRUE TK_FALSE TK_STRING
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOLEAN TK_TIPO_STRING
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_IGUAL_IGUAL TK_DIFERENTE TK_MAIS_MAIS TK_MENOS_MENOS TK_OU TK_E
%token TK_IF TK_ELSE TK_WHILE TK_FOR TK_DO TK_SWITCH TK_CASE TK_BREAK TK_CONTINUE TK_PRINT TK_SCAN
%token TK_ERROR 

%start S

%left '+'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				if(error == "")
					cout << "\n/*Compilador SDDSEAD*/\n\n" + warning + "\n"<< "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << atribuicaoVariavel + "\n" + $5.traducao << "\treturn 0;\n}" << endl;
				else{
					cout << "\n" + warning + "\n";
					yyerror(error);
				} 
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
			| BLOCO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			| TK_IF '(' E ')' E ';' COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto "+ cond + "\n" + 
				$5.traducao + "\t" + cond + "\n" + $7.traducao;
			}
			| TK_IF '(' E ')' E ';' TK_ELSE E ';' COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto ELSE;" + "\n" + 
				$5.traducao + "\tgoto " + cond + "\n" + "\tELSE:\n" + $8.traducao
				+ "\t" + cond +"\n" + $10.traducao;
			}
			| TK_IF '(' E ')' E ';' TK_ELSE BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto ELSE;\n" + $5.traducao
				+ "\tgoto "+cond+"\n" + "\tELSE:\n" + $8.traducao + "\t"+cond+"\n" +
				$9.traducao;
			}
			| TK_IF '(' E ')' BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto " + cond + "\n"
				+ $5.traducao + "\t" + cond + "\n" + $6.traducao;
			}
			| TK_IF '(' E ')' BLOCO TK_ELSE E ';' COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto ELSE;\n" + $5.traducao +
				"\tgoto " + cond + "\n" + "\tELSE:\n" + $7.traducao
				+ "\t" + cond +"\n" + $9.traducao ;
			}
			| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto ELSE;\n" + $5.traducao +
				"\tgoto " + cond + "\n" + "\tELSE:\n" + $7.traducao + "\t"+cond+"\n" + $8.traducao;
			}
			| TK_WHILE '(' P ')' BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string lace = genLacecode();
				TIPO_LOOP loop = getLace($1.label);

				$$.traducao = lace + $3.traducao + "\t" + $$.label + " = !" +
				$3.label + ";\n" + "\tIF(" + $$.label + ") goto " + loop.fimLaco + "\n" +
				$5.traducao + "\tgoto " + lace + "\n\t" + loop.fimLaco + "\n" + $6.traducao;
			}
			| TK_DO BLOCO TK_WHILE '(' E ')' ';' COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $5.tipo);
				string lace = genLacecode();
				string cond = genCondcode();

				$$.traducao = lace + "\t" + $1.traducao +"\n" 
				+ $2.traducao + $5.traducao + "\t" + $$.label + " = !" 
				+ $5.label + ";\n"
				+ "\tIF(" + $$.label +") goto " + cond + "\n" + "\tgoto " + lace
				+ "\n\t" + cond +" \n"+ $8.traducao;
			}
			| TK_FOR '(' ';' ';' ')' BLOCO COMANDOS
			{
				$$.traducao = $6.traducao + $7.traducao;
			}
			| TK_FOR '(' ATRIBUICAO ';' RELACIONAL ';' E ')' BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $5.tipo);
				string lace = genLacecode();
				string cond = genCondcode();

				$$.traducao = $3.traducao + lace + $5.traducao + "\t" + $$.label + 
				" = !" + $5.label + ";\n\t" + "if(" + $$.label + ") goto "+ cond + "\n" + 
				$9.traducao + $7.traducao + "\tgoto " + lace + "\n\t"+ cond +"\n" + $10.traducao;
			}
			| TK_SWITCH '(' TK_NUM ')' '{' CASES '}' COMANDOS
			{
				$$.traducao = $3.traducao + $6.traducao + $8.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

CASES       : CASE CASES
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

CASE        : TK_CASE TK_NUM ':' COMANDOS TK_BREAK ';'
			{
				$$.traducao = $2.traducao + $4.traducao;
			}
			;

COMANDO 	: E ';'
			| DECLARACAO
			{
			}
			| TK_BREAK ';'
			{
				TIPO_LOOP loop = getLaceBreak();
				$$.traducao = "\tgoto " + loop.fimLaco + "\n";
			}
			;

DECLARACAO  : TK_TIPO_INT TK_ID ';'
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
			| TK_TIPO_STRING TK_ID ';'
			{
				verificarVariavelRepetida($2.label);
				string label = gentempcode();
				addString($2.label, "string", label);
				$$.traducao = "";
				$$.label = "\tstrcpy(" + label + ", " + "\0" + ");\n";
			}
			| TK_TIPO_BOOLEAN TK_ID ';'
			{
				verificarVariavelRepetida($2.label);
				addSimbolo($2.label, "boolean", gentempcode());
				$$.traducao = "";
				$$.label = "";
			}
			;

E 			: M '+' E
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
			| M '-' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " - " + $3.label + ";\n";
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
					$$.label + " = " + labelAux + " - " + $3.label + ";\n";
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
					$$.label + " = " + $1.label + " - " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
			| TK_ID TK_MAIS_MAIS
			{
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}
			| TK_ID TK_MENOS_MENOS
			{
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
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha +  ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\n\033[1;31mError\033[0m - Linha " + contLinha +  ": Casting inválido";
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
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha +  ": as variáveis já apresentam o mesmo tipo.\n";
				}else{
					error += "\033[1;31mError\033[0m - Linha " + contLinha +  ": Casting inválido\n";
				}
			}
			| RELACIONAL
			{
			}
			| ATRIBUICAO
			{
			}
			| M
			{
				$$.traducao = $1.traducao;
			}
			;

RELACIONAL  : E '>' E
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
			;

ATRIBUICAO  : TK_ID '=' E
			{
				TIPO_SIMBOLO variavel = getSimbolo($1.label);

				if(variavel.tipoVariavel == $3.tipo){
					if($3.tipo == "string"){
						$$.traducao = $1.traducao + $3.traducao 
						+ "\tstrcpy(" + $3.label +", " + $3.valor +");\n"
						+ "\tstrcpy(" + variavel.labelVariavel +", " + $3.label +");\n";
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Atribuição inválida, tipos diferentes.\n";
				}
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
			| M '/' P
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " / " + $3.label + ";\n";
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
					$$.label + " = " + labelAux + " / " + $3.label + ";\n";
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
					$$.label + " = " + $1.label + " / " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}

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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação inválida, divisão por 0.\n";
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
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos inválidos para %, (ou presença de float).\n";
				}
			}
			| P
			{
				$$.traducao = $1.traducao;
			}
			;

P 			: '(' E ')'
			{
				$$.traducao = $2.traducao;
				$$.tipo = $2.tipo;
				$$.label = $2.label;
			}
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
			| TK_STRING
			{
				$$.tipo = "string";
				$$.label = gentempcode();
				addTempString($$.label, $$.valor);
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

				$$.tipo = variavel.tipoVariavel;
				$$.label = variavel.labelVariavel;
				$$.traducao = "";
			}
			| TK_PRINT '(' E ')'
			{
				$$.traducao = $3.traducao + "\t" + "cout << " + $3.label + ";\n";
			}
			| TK_SCAN '(' TK_ID ')'
			{
				TIPO_SIMBOLO variavel = getSimbolo($3.label);

				$$.traducao = $3.traducao + "\t" "STD::CIN >> " + variavel.labelVariavel + ";\n";
			}
			;
%%

#include "lex.yy.c"

int yyparse();

string gentempcode(){
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);	
}

string genLacecode(){
	var_lace_qnt++;
	return "_L" + std::to_string(var_lace_qnt) + ":";	
}

string genCondcode(){
	var_cond_qnt++;
	return "FIM_IF_" + std::to_string(var_cond_qnt) + ":";
}

string genLaceNameCode(){
	var_lace_name_qnt++;
	return "loop_" + std::to_string(var_lace_name_qnt);
}

void verificarVariavelRepetida(string variavel){

	int contexto = mapa.size() - 1;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	tabelaSimbolos = mapa[contexto];

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
		{
			error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m A variável '" + variavel + "' já existe.\n";
		}
	}
}

TIPO_SIMBOLO getSimbolo(string variavel){

	int contexto = mapa.size() - 1;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	tabelaSimbolos = mapa[contexto];

	while(contexto >= 0)
	{
		for (int i = tabelaSimbolos.size() - 1; i >= 0; i--)
		{
			if(tabelaSimbolos[i].nomeVariavel == variavel)
			{
				return tabelaSimbolos[i];
			}				
		}
		contexto -= 1;
		tabelaSimbolos = mapa[contexto];
	}

	error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m A variável '" + variavel + "' não foi instanciada.\n";
}

void addSimbolo(string variavel, string tipo, string label){
	
	TIPO_SIMBOLO valor;

	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;

	int contexto = mapa.size() - 1;
	mapa[contexto].push_back(valor);

	if(valor.tipoVariavel == "boolean"){
		valor.tipoVariavel = "int";
	}

	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void addString(string variavel, string tipo, string label){
	TIPO_SIMBOLO valor;
	
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;

	int contexto = mapa.size() - 1;
	mapa[contexto].push_back(valor);

	valor.tipoVariavel = "char";
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " 
	+ valor.labelVariavel + "[" + std::to_string(SIZESTRING) + "]" +";\n";
}

void addTemp(string label, string tipo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = tipo;
	tabelaTemp.push_back(valor);

	if(valor.tipoVariavel == "boolean"){
		valor.tipoVariavel = "int";
	}

	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void addTempString(string label, string conteudo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = "string";
	valor.valor = conteudo;
	tabelaTemp.push_back(valor);
	valor.tipoVariavel = "char";

	int size = getSize(conteudo) - 1;

	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + 
	valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
}

int getSize(string str){
	int i = 0;
	while (str[i] != '\0')
		i++;

	return i;
}

void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2){
	if(tipo_1.tipo == "char" || tipo_2.tipo == "char" && tipo_1.tipo == "string" || tipo_2.tipo == "string")
	{
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação relacional inválida.\n";
	}
}

int main(int argc, char* argv[]){
	var_temp_qnt = 0;
	contextoGlobal = 0;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	mapa.push_back(tabelaSimbolos);
	yyparse();
	return 0;
}

void pushContexto(){
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	mapa.push_back(tabelaSimbolos);
}

void popContexto(){
	mapa.pop_back();
}

void pushLoop(string tipo){

	TIPO_LOOP aux;
	aux.nomeLaco = "loop_" + std::to_string(var_lace_name_qnt);
	aux.tipoLaco = tipo;
	aux.fimLaco = genCondcode();
	aux.contexto = mapa.size();
	tabelaLoop.push_back(aux);
}

TIPO_LOOP getLace(string nome){

	for (int i = tabelaLoop.size() - 1; i >= 0; i--)
	{ 
		if(tabelaLoop[i].nomeLaco == nome){
			return tabelaLoop[i];
		}
	}
}

TIPO_LOOP getLaceBreak(){
	int size = tabelaLoop.size();
	return tabelaLoop[size - 1];
}


void contadorDeLinha(){
	var_linha_qnt++;
	contLinha = std::to_string(var_linha_qnt);
}

void yyerror(string MSG){
	cout << MSG << endl;
	exit (0);
}