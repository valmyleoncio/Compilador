all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -w
		./glf < exemplo.SDDSEAD

commit:
		git init
		git add .
		git commit -m "Contexto finalizado, pilha loop, início break"
		git branch -M 2.7
		git push -u origin 2.7