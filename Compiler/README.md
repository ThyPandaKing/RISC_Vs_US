# Compiler Design

Table of contents
-----------------

* [Introduction](#introduction)
* [Installation](#installation)
* [Usage](#usage)
* [Known issues and limitations](#known-issues-and-limitations)

## Folder Structure

    .
    ├── ...
    ├── Optimization                    # Test files (alternatively `spec` or `tests`)
    │   ├── a.out                       # Load and stress tests
    │   ├── layer1.cpp                  # End-to-end, integration tests (alternatively `e2e`)
    ├── test-cases                      # Test files (alternatively `spec` or `tests`)
    │   ├── a.out                       # Load and stress tests
    │   ├── layer1.cpp                  # End-to-end, integration tests (alternatively `e2e`)
    │   └── unit                # Unit tests
    ├── Makefile                        # Test files (alternatively `spec` or `tests`)
    ├── lex.yy.c                        # Test files (alternatively `spec` or `tests`)
    ├── lexical-analyser.l              # Test files (alternatively `spec` or `tests`)
    ├── parser                          # Test files (alternatively `spec` or `tests`)
    ├── parser.y                        # Test files (alternatively `spec` or `tests`)
    ├── tac.txt                         # Test files (alternatively `spec` or `tests`)
    ├── y.output                        # Test files (alternatively `spec` or `tests`)
    ├── y.tab.c                         # Test files (alternatively `spec` or `tests`)
    ├── y.tab.h                         # Test files (alternatively `spec` or `tests`)
    └── ...


## Installation
1. Clone the repository from (https://github.com/cs19b001iittp/RISC_Vs_US.git) [Link will be updated for final presentation, as of now we will be cloning from compiler-dev branch].
2. To run the code, go to linux terminal under /{USER_PATH}/RISC_Vs_US/Compiler and type ```make```.
3. Then enter filename. As of now all test cases are in test-cases folder. So one such filepath (or) filename can be ```test-cases/input1.txt```.
4. The generated three address code will be stored in ```tac.txt``` file.
