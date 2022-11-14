# Compiler Design

Table of contents
-----------------

* [Introduction](#introduction)
* [Installation and Usage](#installation-and-usage)
* [Folder Structure](#folder-structure)
* [Known issues and limitations](#known-issues-and-limitations)

## Introduction
1. In this project you can find a compiler for the programming language developed by <mark style="background-color: lightblue">RISC_Vs_US</mark> team.
2. You may refer to the language manual here (https://docs.google.com/document/d/1IAW91fNMeh6gcIINUFF5NAg-Zl-5EekPPTUq8fAZZ5Q/edit?usp=sharing).
3. One can also refer to the examples given in the test case folder(for more clarity refer to Folder Structure(#folder-structure)).


## Installation and Usage
1. Clone the repository from (https://github.com/PandaKing9660/RISC_Vs_US.git).
2. To run the code, go to linux terminal under /{USER_PATH}/RISC_Vs_US/Compiler and type ```make```.
3. Then enter filename. As of now all test cases are in test-cases folder. So one such filepath (or) filename can be ```test-cases/final1```. Also you can give multiple files at the same time ```test-cases/final1 test-cases/final2``` by just separating file names with spaces.
4. The generated three address code will be stored in ```tac.txt``` file.
5. Output to given to the Virtual machine team(vm-code) will be stores in ```vm.vm``` file.



## Folder Structure

    .
    ├── Optimization                    # optimize tac
    │   ├── a.out                       # output file for layer1.cpp
    │   ├── layer1.cpp                  # mention ehat optimizations are done here...
    ├── test-cases                      # Test files
    │   ├── final1                      # write what is tested in this file...
    │   ├── final2                      # write what is tested in this file...
    │   └── ...                         # Some other test case files
    ├── bundle                          # executable file to merge all code files
    ├── bundle.cpp                      # Program to merge multiple user program files                        
    ├── bundle.txt                      # Complete program dump file
    ├── Makefile                        # makefile
    ├── lex.yy.c                        
    ├── lexical-analyser.l              # Lexical code
    ├── parser                          # Parser code
    ├── parser.y  
    ├── tac-vm                          # Executable to convert tac to vm
    ├── tac-vm.cpp                      # Program to convert tac to vm
    ├── tac.txt                         # Three address code stored here.
    ├── vm.vm                           # Final vmcode stored here.
    ├── y.output                       
    ├── y.tab.c                         
    ├── y.tab.h                         
    └── 
    
 ## Known issues and limitations
1. Pointers and structures are not introduced to the programming language yet.
2. Line numbers in error messages in case of giving multiple files is not dealt with.
