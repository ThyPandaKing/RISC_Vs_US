program: generate_test.py vmout.asm
	./assemble.o
	python generate_test.py

all: Assembler.cpp Assembler.h
	g++ Assembler.cpp -o assemble.o

run:
	./assemble.o

clean: asmout.asm assemble.o
	rm -rf asmout.asm
	rm -rf assemble.o