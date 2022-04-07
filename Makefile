all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -w
		./glf < exemplo.SDDSEAD

commit:
		git init
		git add .
		git commit -m "Segunda Etapa - Iniciada"
		git branch -M 1.8
		git push -u origin 1.8
