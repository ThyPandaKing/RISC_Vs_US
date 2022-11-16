//  A testbench for CPU_Arithmetic_tb
`timescale 1ps/1ps

module CPU_Arithmetic_tb;
    reg Clock;
    wire [31:0] PC_val;
    wire [3:0] State_out;
    wire [31:0] A_reg;
    wire [31:0] B_reg;
    wire [31:0] Imm;
    wire [31:0] Al_out;
    wire ALU_a;
    wire [1:0] ALU_b;
    wire [3:0] ALU_in;
    wire [31:0] MemDataRegOut;
    wire [31:0] op_1;
    wire [31:0] op_2;
    wire [31:0] I_out;

  CPU CPU0 (
    .Clock(Clock),
    .PC_val(PC_val),
    .State_out(State_out),
    .A_reg(A_reg),
    .B_reg(B_reg),
    .Imm(Imm),
    .Al_out(Al_out),
    .ALU_a(ALU_a),
    .ALU_b(ALU_b),
    .ALU_in(ALU_in),
    .MemDataRegOut(MemDataRegOut),
    .op_1(op_1),
    .op_2(op_2),
    .I_out(I_out)
  );

    
    reg [200:0] patterns[0:59];
    integer i;

    
    initial begin
     Clock = 1'b1;
    

      for (i = 0; i < 10000; i = i + 1)
      begin
        //Clock = patterns[i][200];
        Clock = ~Clock;
        #10;

      end

      $display("All tests passed.");
    end
    endmodule
    
