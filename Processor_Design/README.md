# Processor Design

## Introduction
This folder contains the RISC V implementation of the processor for the Computer System Design course project. The processor supports the following instructions:
<!-- Table of instructions -->
| Instruction | Description | Usage |
| ----------- | ----------- | ------ |
| ADD | Add two registers | ADD rd, rs1, rs2 |
| SUB | Subtract two registers | SUB rd, rs1, rs2 |
| AND | Bitwise AND of two registers | AND rd, rs1, rs2 |
| OR | Bitwise OR of two registers | OR rd, rs1, rs2 |
| ADDI | Add a register and an immediate | ADDI rd, rs1, imm |
| SUBI | Subtract a register and an immediate | SUBI rd, rs1, imm |
| LW | Load a word from memory | LW rd, imm(rs1) |
| SW | Store a word in memory | SW rs2, imm(rs1) |
| LUI | Load upper immediate | LUI rd, imm |
| BEQ | Branch if equal | BEQ rs1, rs2, imm |
| BNE | Branch if not equal | BNE rs1, rs2, imm |
| BLT | Branch if less than | BLT rs1, rs2, imm |
| BGE | Branch if greater than or equal to | BGE rs1, rs2, imm |
| BLTU | Branch if less than unsigned | BLTU rs1, rs2, imm |
| BGEU | Branch if greater than or equal to unsigned | BGEU rs1, rs2, imm |
| JAL | Jump and link | JAL rd, imm |
| JALR | Jump and link register | JALR rd, rs1, imm |


## Installation
The processor is implemented in Verilog and can be simulated using any Verilog simulator. AMD Xilinx is used for simulation. A simpler tool for simulation is Digital, which provides a GUI for simulation. The processor can be simulated in Digital using the following steps:
- Download the Digital tool from [here](https://github.com/hneemann/Digital)
- Open the CPU.dig file in Digial
- Use spacebar to run the simulation
- Tests can be written in the test module inside CPU.dig. Further details can be found by clicking the help button.
- Any manual testing can be done by modifying the assembly code in Assembler/vmout.asm and running the `make` command inside the Assembler folder to generate the machine code, along with the program directive to initialize the memory in Digital.

## Version Info
The latest version of the implementation can be found in Multicycle branch.

## References
1. [RISC-V Instruction Set Manual](https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf)
2. [Computer Organization and Design: The Hardware/Software Interface](https://www.elsevier.com/books/computer-organization-and-design-risc-v-edition/patterson/978-0-12-820331-6)
3. [The Elements of Computing Systems](https://www.nand2tetris.org/book)