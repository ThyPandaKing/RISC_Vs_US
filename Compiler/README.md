# Compiler Design

Table of contents
-----------------

* [Introduction](#introduction)
* [Installation](#installation)
* [Usage](#usage)
* [Known issues and limitations](#known-issues-and-limitations)


## Installation
1. Clone the repository from (https://github.com/cs19b001iittp/RISC_Vs_US.git) [Link will be updated for final presentation, as of now we will be cloning from compiler-dev branch].
2. To run the code, go to linux terminal under /{USER_PATH}/RISC_Vs_US/Compiler and type ```make```.
3. Then enter filename. As of now all test cases are in test-cases folder. So one such filepath (or) filename can be ```test-cases/input1.txt```.
4. The generated three address code will be stored in ```tac.txt``` file.



## Folder Structure

    .
    ├── Optimization                    # optimize tac
    │   ├── a.out                       # output file for layer1.cpp
    │   ├── layer1.cpp                  # mention ehat optimizations are done here...
    ├── test-cases                      # Test files
    │   ├── input1.txt                  # write what is tested in this file...
    │   ├── input2.txt                  # write what is tested in this file...
    │   └── ...                         # Some other test case files
    ├── Makefile                        # makefile
    ├── lex.yy.c                        
    ├── lexical-analyser.l              # Lexical code
    ├── parser                          # Parser code
    ├── parser.y                        
    ├── tac.txt                         # Final three address code stored here.
    ├── y.output                       
    ├── y.tab.c                         
    ├── y.tab.h                         
    └── 

