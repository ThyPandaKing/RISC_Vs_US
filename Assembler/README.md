# Assembler

Table of contents
-----------------

* [Introduction](#introduction)
* [Assembler Architecture](#assembler-architecture)
* [Installation and Usage](#installation-and-usage)

## Introduction
1. Translates RISC-V assembly code to machine language.
2. Creates a symbol table for variable and labels and converts them to appropriate format either memory address or line numbers.
3. The address space will be defined by the processor and can be modified easily.

## Assembler Architecture
1. In first pass, all the labels and variables are extracted and appropriate values are assigned to the symbol table. 
2. Validity check of the same is also done using regular expressions.
3. In second pass, CPP unordered_maps was used to map operations to respective funct3, funct7 and opcode.
4. Each RISC V TAC instruction in the given format <operation><space><operator list> from the VM output was first split into operation name and operator list. 
5. Each operation was then added to the instruction (a 32 bit integer) by using bit operations. Then operator list was parsed using regex to get the respective values and stores to a operator_list vector.
6. Operator_list vector was converted to binary and added to the bit<32> output instruction using the opcode, funct3, funct7 values and symbol_table entries.
bitset<32> was used to output the integer to the .asm file

## Installation and Usage
1. Clone the repository from (https://github.com/PandaKing9660/RISC_Vs_US.git).
2. The input RISC-V code is stored as ```vmout.asm``` file.
3. Use ```make all``` to compile the code.
4. Use ```make run``` to run the code.
5. The generated machine code output will be stored in ```asmout.o``` file.






