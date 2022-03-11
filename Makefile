all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -w
		./glf < exemplo.SDDSEAD

commit:
		git init
		git add .
		git commit -m "Primeira Etapa"
		git branch -M Development
		git push -u Development

