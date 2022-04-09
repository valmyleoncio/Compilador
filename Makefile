all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -w
		./glf < exemplo.SDDSEAD

commit:
		git init
		git add .
		git commit -m "If's, else's, while - (sintaticos)"
		git branch -M 2.4
		git push -u origin 2.4