cd Compiler
make run

cd ..
cd VM_VMC_Translator
python3 main.py  ../Compiler/vm.vm
cd outputs 
cat asm.asm > ../../asm.asm

cd ..
cd ..
cd Assembler
cat ../asm.asm > vmout.asm
g++ Assembler.cpp -o assemble.o
cat assemble.o > ../assemble.o
