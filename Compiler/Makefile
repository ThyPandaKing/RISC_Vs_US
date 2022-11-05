run: parser vm
	@echo "Filename: "; \
	read FILENAME; \
	./parser < "test-cases/"$${FILENAME} > tac.txt;\
	./tac-vm > vm.vm

# dummy: parser
# 	./parser < test-cases/input1.txt > tac.txt

vm: tac.txt
	g++ tac-vm.cpp -o tac-vm

parser: y.tab.c lex.yy.c y.tab.h
	g++ -w y.tab.c lex.yy.c -lfl -o parser

y.tab.c: parser.y
	yacc -v -d -t -Wno-other parser.y

lex.yy.c: lexical_analyser.l
	lex lexical_analyser.l

optimal:  
	./Optimization/a.out > tac_optimized.txt
	
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output a.out tac-vm 
