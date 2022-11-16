# Assembler

Table of contents
-----------------

* [Introduction](#introduction)
* [Assembler Architecture](#assembler-architecture)
* [Installation and Usage](#installation-and-usage)

* [Known issues and limitations](#known-issues-and-limitations)

## Introduction
1. Translates RISC-V assembly code to machine language.
2. Creates a symbol table for variable and labels and converts them to appropriate format either memory address or line numbers.
3. The address space will be defined by the processor and can be modified easily.

##Assembler Architecture

TWO PASS ASSEMBLER

All the labels and variables are extracted and appropriate values are assigned to the symbol table. 
Validity check of the same is also done using regular expressions.

## Installation and Usage
1. Clone the repository from (https://github.com/PandaKing9660/RISC_Vs_US.git).
2. To run the code, go to linux terminal under /{USER_PATH}/RISC_Vs_US/Compiler and type ```make```.
3. Then enter filename. As of now all test cases are in test-cases folder. So one such filepath (or) filename can be ```test-cases/final1```. Also you can give multiple files at the same time ```test-cases/final1 test-cases/final2``` by just separating file names with spaces.
4. The generated three address code will be stored in ```tac.txt``` file.
5. Output to given to the Virtual machine team(vm-code) will be stores in ```vm.vm``` file.






