all: Map.cpp Map.h
	g++ Map.cpp -o assemble.o

run:
	assemble.o

clean: asmout.asm assemble.o
	rm -rf asmout.asm
	rm -rf assemble.o