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

string error = "";
string warning = "";

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string valor;
	int contexto;
	int linha;
};

typedef struct
{
	string nomeVariavel;
	string tipoVariavel; 
	string labelVariavel;
	int contexto;
}	TIPO_SIMBOLO;

typedef struct
{
	string tipoVariavel; 
	string labelVariavel;
	string valor;
}	TIPO_TEMP;

vector<TIPO_SIMBOLO> tabelaSimbolos;
int contextoGlobal;
vector<TIPO_TEMP> tabelaTemp;
string atribuicaoVariavel;

int yylex(void);
void yyerror(string);
string gentempcode();
string genLacecode();
string genCondcode();
void verificarVariavelRepetida(string variavel, int contexto);
void verificarVariavelExistente(string nomeVariavel, int contexto);
TIPO_SIMBOLO getSimbolo(string variavel, int contexto);
void addSimbolo(string variavel, string tipo, string label, int contexto);
void addString(string variavel, string tipo, string label, int contexto);
void addTempString(string label, string tipo);
int getSize(string str);
void addTemp(string label, string tipo);
void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2);
void atualizarContexto(int num);
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
				"IF(" + $$.label + ") goto "+ cond + "\n" + 
				$5.traducao + "\t" + cond + "\n" + $7.traducao;
			}
			| TK_IF '(' E ')' E ';' TK_ELSE E ';' COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"IF(" + $$.label + ") goto ELSE" + "\n" + 
				$5.traducao + "\tgoto " + cond + "\n" + "\tELSE\n" + $8.traducao
				+ "\t" + cond +"\n" + $10.traducao;
			}
			| TK_IF '(' E ')' E ';' TK_ELSE BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"IF(" + $$.label + ") goto ELSE\n" + $5.traducao
				+ "\tgoto "+cond+"\n" + "\tELSE\n" + $8.traducao + "\t"+cond+"\n" +
				$9.traducao;
			}
			| TK_IF '(' E ')' BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"IF(" + $$.label + ") goto " + cond + "\n"
				+ $5.traducao + "\t" + cond + "\n" + $6.traducao;
			}
			| TK_IF '(' E ')' BLOCO TK_ELSE E ';' COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"IF(" + $$.label + ") goto ELSE\n" + $5.traducao +
				"\tgoto " + cond + "\n" + "\tELSE\n" + $7.traducao
				+ "\t" + cond +"\n" + $9.traducao ;
			}
			| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"IF(" + $$.label + ") goto ELSE\n" + $5.traducao +
				"\tgoto " + cond + "\n" + "\tELSE\n" + $7.traducao + "\t"+cond+"\n" + $8.traducao;
			}
			| TK_WHILE '(' RELACIONAL ')' BLOCO COMANDOS
			{
				$$.label = gentempcode();
				addTemp($$.label, $3.tipo);
				string lace = genLacecode();
				string cond = genCondcode();

				$$.traducao = lace + $3.traducao + "\t" + $$.label + " = !" +
				$3.label + ";\n" + "\tIF(" + $$.label + ") goto " + cond + "\n" +
				$5.traducao + "\tgoto " + lace + "\n\t" + cond + "\n" + $6.traducao;
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
				" = !" + $5.label + ";\n\t" + "IF(" + $$.label + ") goto "+ cond + "\n" + 
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
			;

DECLARACAO  : TK_TIPO_INT TK_ID ';'
			{
				verificarVariavelRepetida($2.label, $2.contexto);
				addSimbolo($2.label, "int", gentempcode(), $2.contexto);
				$$.traducao = "";
				$$.label = "";
			}			
			| TK_TIPO_FLOAT TK_ID ';'
			{
				verificarVariavelRepetida($2.label, $2.contexto);
				addSimbolo($2.label, "float", gentempcode(), $2.contexto);
				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_CHAR TK_ID ';'
			{
				verificarVariavelRepetida($2.label, $2.contexto);
				addSimbolo($2.label, "char", gentempcode(), $2.contexto);
				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_STRING TK_ID ';'
			{
				verificarVariavelRepetida($2.label, $2.contexto);
				string label = gentempcode();
				addString($2.label, "string", label, $2.contexto);
				$$.traducao = "";
				$$.label = "\tstrcpy(" + label + ", " + "\0" + ");\n";
			}
			| TK_TIPO_BOOLEAN TK_ID ';'
			{
				verificarVariavelRepetida($2.label, $2.contexto);
				addSimbolo($2.label, "boolean", gentempcode(), $2.contexto);
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
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string($3.linha) +  ":\033[0m\033[1;39m Operandos com tipos inválidos.");
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
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string($3.linha) +  ":\033[0m\033[1;39m Operandos com tipos inválidos.");
				}
			}
			| TK_ID TK_MAIS_MAIS
			{
				verificarVariavelExistente($1.label, $1.contexto);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label, $2.contexto );
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}
			| TK_ID TK_MENOS_MENOS
			{
				verificarVariavelExistente($1.label, $1.contexto);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label, $2.contexto);
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
				verificarVariavelExistente($1.label, $1.contexto);
				TIPO_SIMBOLO variavel = getSimbolo($1.label, $2.contexto);

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
					yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string($3.linha) +"  Contexto: " + std::to_string($3.contexto) +  ": Atribuição inválida, tipos diferentes.");
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
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string($3.linha) +  ":\033[0m\033[1;39m Operandos com tipos inválidos.");
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
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string($3.linha) +  ":\033[0m\033[1;39m Operandos com tipos inválidos.");
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
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string($3.linha) +  ":\033[0m\033[1;39m Operação inválida, divisão por 0.");
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
					yyerror("\n\033[1;31mError\033[0m - \033[1;36mLinha " + std::to_string($3.linha) +  ":\033[0m\033[1;39m Operandos inválidos para %, ( ou presença de float).");
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
				TIPO_SIMBOLO variavel = getSimbolo($1.label, $1.contexto);
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == $1.label && tabelaSimbolos[i].contexto == $1.contexto)
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
				$$.contexto = variavel.contexto;
			}
			| TK_PRINT '(' E ')'
			{
				$$.traducao = $3.traducao + "\t" + "cout >> " + $3.label + ";\n";
			}
			| TK_SCAN '(' TK_ID ')'
			{
				verificarVariavelExistente($3.label, $3.contexto);
				TIPO_SIMBOLO variavel = getSimbolo($3.label, $2.contexto);

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
	return "_L" + std::to_string(var_lace_qnt);	
}

string genCondcode(){
	var_cond_qnt++;
	return "FIM_IF(" + std::to_string(var_cond_qnt) + ")";	
}

void verificarVariavelRepetida(string variavel, int contexto){

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel && tabelaSimbolos[i].contexto == contexto)
		{
			yyerror("Variável ja existente");
		}
	}
}

void verificarVariavelExistente(string nomeVariavel, int contexto){
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

TIPO_SIMBOLO getSimbolo(string variavel, int contexto){

	int aux = contexto;

	for (int i = tabelaSimbolos.size(); i >= 0; i--)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
		{
			if(tabelaSimbolos[i].contexto == contexto){
				return tabelaSimbolos[i];
			} else {
				
				while(contexto >= 0){
					contexto--;
					if(tabelaSimbolos[i].contexto == contexto){
						return tabelaSimbolos[i];
					}
				}
				contexto = aux;
			}
		}					
	}
}

void addSimbolo(string variavel, string tipo, string label, int num){
	TIPO_SIMBOLO valor;
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;
	valor.contexto = num;
	tabelaSimbolos.push_back(valor);

	if(valor.tipoVariavel == "boolean"){
		valor.tipoVariavel = "int";
	}

	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void addString(string variavel, string tipo, string label, int num){
	TIPO_SIMBOLO valor;
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;
	valor.contexto = num;
	tabelaSimbolos.push_back(valor);
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
	if(tipo_1.tipo == "char" || tipo_2.tipo == "char" || tipo_1.tipo == "string" || tipo_2.tipo == "string")
	{
		yyerror("\n\033[1;31mError\033[0m - Linha " + std::to_string(tipo_1.linha) +  ": Operação relacional inválida.");
	}
}

int main(int argc, char* argv[]){
	var_temp_qnt = 0;
	contextoGlobal = 0;
	yyparse();

	for(int i = tabelaSimbolos.size(); i >= 0; i--){
		
	}
	return 0;
}

void atualizarContexto(int num){
	if(num == 1){
		contextoGlobal++;
	} else{
		contextoGlobal--;
	}

	cout << contextoGlobal;
}

void yyerror(string MSG){
	cout << MSG << endl;
	exit (0);
}