cd Compiler
make run

cd ..
cd VM_TAC_Translator
python3 main.py  ../tac.txt
cd outputs 
cat tac.asm > ../../tac.asm

cd ..
cd ..
cd Assembler
cat ../tac.asm > vmout.asm
g++ Assembler.cpp -o assemble.o
cat assemble.o > ../assemble.o
