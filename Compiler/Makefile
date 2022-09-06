run: parser
	./parser < input.txt

parser: y.tab.c lex.yy.c y.tab.h
	g++ -w y.tab.c lex.yy.c -lfl -o parser
	
lex: lexical_analyser.l
	lex lexical_analyser.l

yacc: parser.y
	yacc -v -d -t parser.y
	
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output 