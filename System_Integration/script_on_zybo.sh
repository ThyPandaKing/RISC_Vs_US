dnf install bison
dnf install flex
cd Compiler
cp ../User/userCode.txt  bundle.txt 
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
./assemble.o

cd ..
scp ./Assembler/asmout.o user@10.21.130.84:/home/user/xilinx-projects/CPU/CPU.srcs/sim_1/new/ram_data.mem

