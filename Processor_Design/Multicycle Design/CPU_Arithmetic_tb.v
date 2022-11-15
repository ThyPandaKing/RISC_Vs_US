//  A testbench for CPU_Arithmetic_tb
`timescale 1us/1ns

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
      patterns[0] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[1] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[2] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[3] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[4] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[5] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[6] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[7] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[8] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[9] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[10] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[11] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[12] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[13] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[14] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[15] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[16] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[17] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[18] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[19] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[20] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[21] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[22] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[23] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[24] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[25] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[26] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[27] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[28] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[29] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[30] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[31] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[32] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[33] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[34] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[35] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[36] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[37] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[38] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[39] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[40] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[41] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[42] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[43] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[44] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[45] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[46] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[47] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[48] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[49] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[50] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[51] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[52] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[53] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[54] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[55] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[56] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[57] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[58] = 201'b0_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
      patterns[59] = 201'b1_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;

      for (i = 0; i < 60; i = i + 1)
      begin
        Clock = patterns[i][200];
        #10;
        if (patterns[i][199:168] !== 32'hx)
        begin
          if (PC_val !== patterns[i][199:168])
          begin
            $display("%d:PC_val: (assertion error). Expected %h, found %h", i, patterns[i][199:168], PC_val);
            $finish;
          end
        end
        if (patterns[i][167:164] !== 4'hx)
        begin
          if (State_out !== patterns[i][167:164])
          begin
            $display("%d:State_out: (assertion error). Expected %h, found %h", i, patterns[i][167:164], State_out);
            $finish;
          end
        end
        if (patterns[i][163:132] !== 32'hx)
        begin
          if (I_out !== patterns[i][163:132])
          begin
            $display("%d:I_out: (assertion error). Expected %h, found %h", i, patterns[i][163:132], I_out);
            $finish;
          end
        end
        if (patterns[i][131:100] !== 32'hx)
        begin
          if (op_1 !== patterns[i][131:100])
          begin
            $display("%d:op_1: (assertion error). Expected %h, found %h", i, patterns[i][131:100], op_1);
            $finish;
          end
        end
        if (patterns[i][99:68] !== 32'hx)
        begin
          if (op_2 !== patterns[i][99:68])
          begin
            $display("%d:op_2: (assertion error). Expected %h, found %h", i, patterns[i][99:68], op_2);
            $finish;
          end
        end
        if (patterns[i][67:64] !== 4'hx)
        begin
          if (ALU_in !== patterns[i][67:64])
          begin
            $display("%d:ALU_in: (assertion error). Expected %h, found %h", i, patterns[i][67:64], ALU_in);
            $finish;
          end
        end
        if (patterns[i][63:32] !== 32'hx)
        begin
          if (Al_out !== patterns[i][63:32])
          begin
            $display("%d:Al_out: (assertion error). Expected %h, found %h", i, patterns[i][63:32], Al_out);
            $finish;
          end
        end
        if (patterns[i][31:0] !== 32'hx)
        begin
          if (MemDataRegOut !== patterns[i][31:0])
          begin
            $display("%d:MemDataRegOut: (assertion error). Expected %h, found %h", i, patterns[i][31:0], MemDataRegOut);
            $finish;
          end
        end
      end

      $display("All tests passed.");
    end
    endmodule
