all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -w
		./glf < exemplo.SDDSEAD

commit:
		git init
		git add .
		git commit -m "Primeira Etapa - Iniciando Conversões"
		git branch -M 1.3
		git push -u 1.3
