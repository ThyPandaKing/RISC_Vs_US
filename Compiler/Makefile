run: parser vm bundle
	./bundle > bundle.txt
	./parser < bundle.txt > tac.txt;\
	./tac-vm > vm.vm

# run: parser vm bundle
# 	./parser < bundle.txt > tac.txt;\
# 	./tac-vm > vm.vm
# dummy: parser
# 	./parser < test-cases/input1.txt > tac.txt

bundle: bundle.cpp
	g++ bundle.cpp -o bundle

vm: tac-vm.cpp
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
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output a.out tac-vm tac.txt vm.vm bundle bundle.txt