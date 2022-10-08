# run: parser
# 	@echo "Filename: "; \
# 	read FILENAME; \
# 	echo "Filename is ", $${FILENAME};\
# 	./parser < $${FILENAME}

dummy: parser
	./parser < test-cases/arrays > tac.txt

parser: y.tab.c lex.yy.c y.tab.h
	g++ -w y.tab.c lex.yy.c -lfl -o parser

y.tab.c: parser.y
	yacc -v -d -t -Wno-other parser.y

lex.yy.c: lexical_analyser.l
	lex lexical_analyser.l
	
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output 