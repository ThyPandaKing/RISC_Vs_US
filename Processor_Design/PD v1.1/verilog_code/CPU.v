/*
 * Generated by Digital. Don't modify this file!
 * Any changes will be lost if this file is regenerated.
 */
module DIG_RegisterFile
#(
    parameter Bits = 8,
    parameter AddrBits = 4
)
(
    input [(Bits-1):0] Din,
    input we,
    input [(AddrBits-1):0] Rw,
    input C,
    input [(AddrBits-1):0] Ra,
    input [(AddrBits-1):0] Rb,
    output [(Bits-1):0] Da,
    output [(Bits-1):0] Db
);

    reg [(Bits-1):0] memory[0:((1 << AddrBits)-1)];

    assign Da = memory[Ra];
    assign Db = memory[Rb];

    always @ (posedge C) begin
        if (we)
            memory[Rw] <= Din;
    end
endmodule


module RegFile32Bit (
  input [31:0] DataToWrite,
  input writeEnable,
  input [4:0] writeReg,
  input [4:0] Read1,
  input [4:0] Read2,
  input CPU_clock,
  output [31:0] Register1,
  output [31:0] Register2
);
  // RegFile
  DIG_RegisterFile #(
    .Bits(32),
    .AddrBits(5)
  )
  DIG_RegisterFile_i0 (
    .Din( DataToWrite ),
    .we( writeEnable ),
    .Rw( writeReg ),
    .C( CPU_clock ),
    .Ra( Read1 ),
    .Rb( Read2 ),
    .Da( Register1 ),
    .Db( Register2 )
  );
endmodule

module DIG_Register_BUS #(
    parameter Bits = 1
)
(
    input C,
    input en,
    input [(Bits - 1):0]D,
    output [(Bits - 1):0]Q
);

    reg [(Bits - 1):0] state = 'h0;

    assign Q = state;

    always @ (posedge C) begin
        if (en)
            state <= D;
   end
endmodule
module DIG_Add
#(
    parameter Bits = 1
)
(
    input [(Bits-1):0] a,
    input [(Bits-1):0] b,
    input c_i,
    output [(Bits - 1):0] s,
    output c_o
);
   wire [Bits:0] temp;

   assign temp = a + b + c_i;
   assign s = temp [(Bits-1):0];
   assign c_o = temp[Bits];
endmodule



module Adder32Bit (
  input [31:0] B,
  input [31:0] A,
  input C_in,
  output [31:0] sum,
  output c_out
);
  // Adder
  DIG_Add #(
    .Bits(32)
  )
  DIG_Add_i0 (
    .a( A ),
    .b( B ),
    .c_i( C_in ),
    .s( sum ),
    .c_o( c_out )
  );
endmodule

module Mux_2x1_NBits #(
    parameter Bits = 2
)
(
    input [0:0] sel,
    input [(Bits - 1):0] in_0,
    input [(Bits - 1):0] in_1,
    output reg [(Bits - 1):0] out
);
    always @ (*) begin
        case (sel)
            1'h0: out = in_0;
            1'h1: out = in_1;
            default:
                out = 'h0;
        endcase
    end
endmodule

module DIG_BitExtender #(
    parameter inputBits = 2,
    parameter outputBits = 4
)
(
    input [(inputBits-1):0] in,
    output [(outputBits - 1):0] out
);
    assign out = {{(outputBits - inputBits){in[inputBits - 1]}}, in};
endmodule




module Mux_8x1
(
    input [2:0] sel,
    input in_0,
    input in_1,
    input in_2,
    input in_3,
    input in_4,
    input in_5,
    input in_6,
    input in_7,
    output reg out
);
    always @ (*) begin
        case (sel)
            3'h0: out = in_0;
            3'h1: out = in_1;
            3'h2: out = in_2;
            3'h3: out = in_3;
            3'h4: out = in_4;
            3'h5: out = in_5;
            3'h6: out = in_6;
            3'h7: out = in_7;
            default:
                out = 'h0;
        endcase
    end
endmodule


module ALU1Bit (
  input a,
  input b,
  input [3:0] Oper,
  input C_in,
  output c_out,
  output res,
  output zero
);
  wire s0;
  wire s1;
  wire s2;
  wire [2:0] s3;
  wire s4;
  wire res_temp;
  assign s0 = (b ^ Oper[0]);
  assign s3 = Oper[3:1];
  assign s1 = (a & s0);
  assign s2 = (a | s0);
  DIG_Add #(
    .Bits(1)
  )
  DIG_Add_i0 (
    .a( a ),
    .b( s0 ),
    .c_i( C_in ),
    .s( s4 ),
    .c_o( c_out )
  );
  Mux_8x1 Mux_8x1_i1 (
    .sel( s3 ),
    .in_0( s1 ),
    .in_1( s2 ),
    .in_2( s4 ),
    .in_3( 1'b0 ),
    .in_4( 1'b0 ),
    .in_5( 1'b0 ),
    .in_6( 1'b0 ),
    .in_7( 1'b0 ),
    .out( res_temp )
  );
  assign zero = ~ res_temp;
  assign res = res_temp;
endmodule

module ALU32Bit (
  input [3:0] Operation,
  input [31:0] a,
  input [31:0] b,
  output c_out,
  output [31:0] ALU_out,
  output zero
);
  wire s0;
  wire s1;
  wire s2;
  wire s3;
  wire s4;
  wire s5;
  wire s6;
  wire s7;
  wire s8;
  wire s9;
  wire s10;
  wire s11;
  wire s12;
  wire s13;
  wire s14;
  wire s15;
  wire s16;
  wire s17;
  wire s18;
  wire s19;
  wire s20;
  wire s21;
  wire s22;
  wire s23;
  wire s24;
  wire s25;
  wire s26;
  wire s27;
  wire s28;
  wire s29;
  wire s30;
  wire s31;
  wire s32;
  wire s33;
  wire s34;
  wire s35;
  wire s36;
  wire s37;
  wire s38;
  wire s39;
  wire s40;
  wire s41;
  wire s42;
  wire s43;
  wire s44;
  wire s45;
  wire s46;
  wire s47;
  wire s48;
  wire s49;
  wire s50;
  wire s51;
  wire s52;
  wire s53;
  wire s54;
  wire s55;
  wire s56;
  wire s57;
  wire s58;
  wire s59;
  wire s60;
  wire s61;
  wire s62;
  wire s63;
  wire s64;
  wire s65;
  wire s66;
  wire s67;
  wire s68;
  wire s69;
  wire s70;
  wire s71;
  wire s72;
  wire s73;
  wire s74;
  wire s75;
  wire s76;
  wire s77;
  wire s78;
  wire s79;
  wire s80;
  wire s81;
  wire s82;
  wire s83;
  wire s84;
  wire s85;
  wire s86;
  wire s87;
  wire s88;
  wire s89;
  wire s90;
  wire s91;
  wire s92;
  wire s93;
  wire s94;
  wire s95;
  wire s96;
  wire s97;
  wire s98;
  wire s99;
  wire s100;
  wire s101;
  wire s102;
  wire s103;
  wire s104;
  wire s105;
  wire s106;
  wire s107;
  wire s108;
  wire s109;
  wire s110;
  wire s111;
  wire s112;
  wire s113;
  wire s114;
  wire s115;
  wire s116;
  wire s117;
  wire s118;
  wire s119;
  wire s120;
  wire s121;
  wire s122;
  wire s123;
  wire s124;
  wire s125;
  wire s126;
  wire s127;
  wire s128;
  wire s129;
  wire s130;
  wire s131;
  wire s132;
  wire s133;
  wire s134;
  wire s135;
  wire s136;
  wire s137;
  wire s138;
  wire s139;
  wire s140;
  wire s141;
  wire s142;
  wire s143;
  wire s144;
  wire s145;
  wire s146;
  wire s147;
  wire s148;
  wire s149;
  wire s150;
  wire s151;
  wire s152;
  wire s153;
  wire s154;
  wire s155;
  wire s156;
  wire s157;
  wire s158;
  assign s0 = a[0];
  assign s6 = a[1];
  assign s11 = a[2];
  assign s16 = a[3];
  assign s21 = a[4];
  assign s26 = a[5];
  assign s31 = a[6];
  assign s36 = a[7];
  assign s41 = a[8];
  assign s46 = a[9];
  assign s51 = a[10];
  assign s56 = a[11];
  assign s61 = a[12];
  assign s65 = a[13];
  assign s70 = a[14];
  assign s75 = a[15];
  assign s80 = a[16];
  assign s85 = a[17];
  assign s90 = a[18];
  assign s155 = a[19];
  assign s95 = a[20];
  assign s101 = a[21];
  assign s106 = a[22];
  assign s111 = a[23];
  assign s116 = a[24];
  assign s121 = a[25];
  assign s126 = a[26];
  assign s131 = a[27];
  assign s136 = a[28];
  assign s141 = a[29];
  assign s146 = a[30];
  assign s151 = a[31];
  assign s1 = b[0];
  assign s7 = b[1];
  assign s12 = b[2];
  assign s17 = b[3];
  assign s22 = b[4];
  assign s27 = b[5];
  assign s32 = b[6];
  assign s37 = b[7];
  assign s42 = b[8];
  assign s47 = b[9];
  assign s52 = b[10];
  assign s57 = b[11];
  assign s62 = b[12];
  assign s66 = b[13];
  assign s71 = b[14];
  assign s76 = b[15];
  assign s81 = b[16];
  assign s86 = b[17];
  assign s91 = b[18];
  assign s156 = b[19];
  assign s96 = b[20];
  assign s102 = b[21];
  assign s107 = b[22];
  assign s112 = b[23];
  assign s117 = b[24];
  assign s122 = b[25];
  assign s127 = b[26];
  assign s132 = b[27];
  assign s137 = b[28];
  assign s142 = b[29];
  assign s147 = b[30];
  assign s152 = b[31];
  assign s2 = Operation[0];
  ALU1Bit ALU1Bit_i0 (
    .a( s0 ),
    .b( s1 ),
    .Oper( Operation ),
    .C_in( s2 ),
    .c_out( s3 ),
    .res( s4 ),
    .zero( s5 )
  );
  ALU1Bit ALU1Bit_i1 (
    .a( s6 ),
    .b( s7 ),
    .Oper( Operation ),
    .C_in( s3 ),
    .c_out( s8 ),
    .res( s9 ),
    .zero( s10 )
  );
  ALU1Bit ALU1Bit_i2 (
    .a( s11 ),
    .b( s12 ),
    .Oper( Operation ),
    .C_in( s8 ),
    .c_out( s13 ),
    .res( s14 ),
    .zero( s15 )
  );
  ALU1Bit ALU1Bit_i3 (
    .a( s16 ),
    .b( s17 ),
    .Oper( Operation ),
    .C_in( s13 ),
    .c_out( s18 ),
    .res( s19 ),
    .zero( s20 )
  );
  ALU1Bit ALU1Bit_i4 (
    .a( s21 ),
    .b( s22 ),
    .Oper( Operation ),
    .C_in( s18 ),
    .c_out( s23 ),
    .res( s24 ),
    .zero( s25 )
  );
  ALU1Bit ALU1Bit_i5 (
    .a( s26 ),
    .b( s27 ),
    .Oper( Operation ),
    .C_in( s23 ),
    .c_out( s28 ),
    .res( s29 ),
    .zero( s30 )
  );
  ALU1Bit ALU1Bit_i6 (
    .a( s31 ),
    .b( s32 ),
    .Oper( Operation ),
    .C_in( s28 ),
    .c_out( s33 ),
    .res( s34 ),
    .zero( s35 )
  );
  ALU1Bit ALU1Bit_i7 (
    .a( s36 ),
    .b( s37 ),
    .Oper( Operation ),
    .C_in( s33 ),
    .c_out( s38 ),
    .res( s39 ),
    .zero( s40 )
  );
  ALU1Bit ALU1Bit_i8 (
    .a( s41 ),
    .b( s42 ),
    .Oper( Operation ),
    .C_in( s38 ),
    .c_out( s43 ),
    .res( s44 ),
    .zero( s45 )
  );
  ALU1Bit ALU1Bit_i9 (
    .a( s46 ),
    .b( s47 ),
    .Oper( Operation ),
    .C_in( s43 ),
    .c_out( s48 ),
    .res( s49 ),
    .zero( s50 )
  );
  ALU1Bit ALU1Bit_i10 (
    .a( s51 ),
    .b( s52 ),
    .Oper( Operation ),
    .C_in( s48 ),
    .c_out( s53 ),
    .res( s54 ),
    .zero( s55 )
  );
  ALU1Bit ALU1Bit_i11 (
    .a( s56 ),
    .b( s57 ),
    .Oper( Operation ),
    .C_in( s53 ),
    .c_out( s58 ),
    .res( s59 ),
    .zero( s60 )
  );
  ALU1Bit ALU1Bit_i12 (
    .a( s61 ),
    .b( s62 ),
    .Oper( Operation ),
    .C_in( s58 ),
    .c_out( s63 ),
    .res( s64 )
  );
  ALU1Bit ALU1Bit_i13 (
    .a( s65 ),
    .b( s66 ),
    .Oper( Operation ),
    .C_in( s63 ),
    .c_out( s67 ),
    .res( s68 ),
    .zero( s69 )
  );
  ALU1Bit ALU1Bit_i14 (
    .a( s70 ),
    .b( s71 ),
    .Oper( Operation ),
    .C_in( s67 ),
    .c_out( s72 ),
    .res( s73 ),
    .zero( s74 )
  );
  ALU1Bit ALU1Bit_i15 (
    .a( s75 ),
    .b( s76 ),
    .Oper( Operation ),
    .C_in( s72 ),
    .c_out( s77 ),
    .res( s78 ),
    .zero( s79 )
  );
  ALU1Bit ALU1Bit_i16 (
    .a( s80 ),
    .b( s81 ),
    .Oper( Operation ),
    .C_in( s77 ),
    .c_out( s82 ),
    .res( s83 ),
    .zero( s84 )
  );
  ALU1Bit ALU1Bit_i17 (
    .a( s85 ),
    .b( s86 ),
    .Oper( Operation ),
    .C_in( s82 ),
    .c_out( s87 ),
    .res( s88 ),
    .zero( s89 )
  );
  ALU1Bit ALU1Bit_i18 (
    .a( s90 ),
    .b( s91 ),
    .Oper( Operation ),
    .C_in( s87 ),
    .c_out( s92 ),
    .res( s93 ),
    .zero( s94 )
  );
  ALU1Bit ALU1Bit_i19 (
    .a( s155 ),
    .b( s156 ),
    .Oper( Operation ),
    .C_in( s92 ),
    .c_out( s97 ),
    .res( s157 ),
    .zero( s158 )
  );
  ALU1Bit ALU1Bit_i20 (
    .a( s95 ),
    .b( s96 ),
    .Oper( Operation ),
    .C_in( s97 ),
    .c_out( s98 ),
    .res( s99 ),
    .zero( s100 )
  );
  ALU1Bit ALU1Bit_i21 (
    .a( s101 ),
    .b( s102 ),
    .Oper( Operation ),
    .C_in( s98 ),
    .c_out( s103 ),
    .res( s104 ),
    .zero( s105 )
  );
  ALU1Bit ALU1Bit_i22 (
    .a( s106 ),
    .b( s107 ),
    .Oper( Operation ),
    .C_in( s103 ),
    .c_out( s108 ),
    .res( s109 ),
    .zero( s110 )
  );
  ALU1Bit ALU1Bit_i23 (
    .a( s111 ),
    .b( s112 ),
    .Oper( Operation ),
    .C_in( s108 ),
    .c_out( s113 ),
    .res( s114 ),
    .zero( s115 )
  );
  ALU1Bit ALU1Bit_i24 (
    .a( s116 ),
    .b( s117 ),
    .Oper( Operation ),
    .C_in( s113 ),
    .c_out( s118 ),
    .res( s119 ),
    .zero( s120 )
  );
  ALU1Bit ALU1Bit_i25 (
    .a( s121 ),
    .b( s122 ),
    .Oper( Operation ),
    .C_in( s118 ),
    .c_out( s123 ),
    .res( s124 ),
    .zero( s125 )
  );
  ALU1Bit ALU1Bit_i26 (
    .a( s126 ),
    .b( s127 ),
    .Oper( Operation ),
    .C_in( s123 ),
    .c_out( s128 ),
    .res( s129 ),
    .zero( s130 )
  );
  ALU1Bit ALU1Bit_i27 (
    .a( s131 ),
    .b( s132 ),
    .Oper( Operation ),
    .C_in( s128 ),
    .c_out( s133 ),
    .res( s134 ),
    .zero( s135 )
  );
  ALU1Bit ALU1Bit_i28 (
    .a( s136 ),
    .b( s137 ),
    .Oper( Operation ),
    .C_in( s133 ),
    .c_out( s138 ),
    .res( s139 ),
    .zero( s140 )
  );
  ALU1Bit ALU1Bit_i29 (
    .a( s141 ),
    .b( s142 ),
    .Oper( Operation ),
    .C_in( s138 ),
    .c_out( s143 ),
    .res( s144 ),
    .zero( s145 )
  );
  ALU1Bit ALU1Bit_i30 (
    .a( s146 ),
    .b( s147 ),
    .Oper( Operation ),
    .C_in( s143 ),
    .c_out( s148 ),
    .res( s149 ),
    .zero( s150 )
  );
  ALU1Bit ALU1Bit_i31 (
    .a( s151 ),
    .b( s152 ),
    .Oper( Operation ),
    .C_in( s148 ),
    .c_out( c_out ),
    .res( s153 ),
    .zero( s154 )
  );
  assign ALU_out[0] = s4;
  assign ALU_out[1] = s9;
  assign ALU_out[2] = s14;
  assign ALU_out[3] = s19;
  assign ALU_out[4] = s24;
  assign ALU_out[5] = s29;
  assign ALU_out[6] = s34;
  assign ALU_out[7] = s39;
  assign ALU_out[8] = s44;
  assign ALU_out[9] = s49;
  assign ALU_out[10] = s54;
  assign ALU_out[11] = s59;
  assign ALU_out[12] = s64;
  assign ALU_out[13] = s68;
  assign ALU_out[14] = s73;
  assign ALU_out[15] = s78;
  assign ALU_out[16] = s83;
  assign ALU_out[17] = s88;
  assign ALU_out[18] = s93;
  assign ALU_out[19] = s157;
  assign ALU_out[20] = s99;
  assign ALU_out[21] = s104;
  assign ALU_out[22] = s109;
  assign ALU_out[23] = s114;
  assign ALU_out[24] = s119;
  assign ALU_out[25] = s124;
  assign ALU_out[26] = s129;
  assign ALU_out[27] = s134;
  assign ALU_out[28] = s139;
  assign ALU_out[29] = s144;
  assign ALU_out[30] = s149;
  assign ALU_out[31] = s153;
  assign zero = (s5 & s10 & s15 & s20 & s25 & s30 & s35 & s40 & s45 & s50 & s55 & s60 & s69 & s74 & s79 & s84 & s89 & s94 & s92 & s158 & s100 & s105 & s110 & s115 & s120 & s125 & s130 & s135 & s140 & s145 & s150 & s154);
endmodule
module DIG_BlockRAMDualPort
#(
    parameter Bits = 8,
    parameter AddrBits = 4
)
(
  input [(AddrBits-1):0] A,
  input [(Bits-1):0] Din,
  input str,
  input C,
  output [(Bits-1):0] D
);
  reg [(Bits-1):0] memory[0:((1 << AddrBits) - 1)];
  reg [(Bits-1):0] wData;

  assign D = wData;

  always @ (posedge C) begin
    wData <= memory[A];
    if (str)
      memory[A] <= Din;
  end
endmodule


module InstructionMemory (
  input Clk,
  input [31:0] Loc_addr,
  input [31:0] Data_in,
  input WriteToMem,
  output [31:0] Data_out
);
  // Memory
  DIG_BlockRAMDualPort #(
    .Bits(32),
    .AddrBits(24)
  )
  DIG_BlockRAMDualPort_i0 (
    .A( Loc_addr ),
    .Din( Data_in ),
    .str( WriteToMem ),
    .C( Clk ),
    .D( Data_out )
  );
endmodule

module And7Bit (
  input I0,
  input I1,
  input I2,
  input I3,
  input I4,
  input I5,
  input I6,
  output O
);
  assign O = (((I0 & I1) & (I2 & I3)) & ((I4 & I5) & (I6 & 1'b1)));
endmodule

module OPCodeControlUnit (
  input I0,
  input I1,
  input I2,
  input I3,
  input I4,
  input I5,
  input I6,
  output ALU_src,
  output MemtoReg,
  output RegWrite,
  output MemRead,
  output MemWrite,
  output Branch,
  output ALUop1,
  output ALUop0
);
  wire s0;
  wire s1;
  wire s2;
  wire ALUop1_temp;
  wire s3;
  wire s4;
  wire s5;
  wire s6;
  wire s7;
  wire MemRead_temp;
  wire s8;
  wire s9;
  wire s10;
  wire s11;
  wire MemWrite_temp;
  wire s12;
  wire s13;
  wire s14;
  wire ALUop0_temp;
  assign s2 = ~ I6;
  assign s1 = ~ I3;
  assign s0 = ~ I2;
  assign s7 = ~ I6;
  assign s6 = ~ I5;
  assign s5 = ~ I4;
  assign s4 = ~ I3;
  assign s3 = ~ I2;
  assign s11 = ~ I6;
  assign s10 = ~ I4;
  assign s9 = ~ I3;
  assign s8 = ~ I2;
  assign s14 = ~ I4;
  assign s13 = ~ I3;
  assign s12 = ~ I2;
  // R-Front
  And7Bit And7Bit_i0 (
    .I0( I0 ),
    .I1( I1 ),
    .I2( s0 ),
    .I3( s1 ),
    .I4( I4 ),
    .I5( I5 ),
    .I6( s2 ),
    .O( ALUop1_temp )
  );
  // lw
  And7Bit And7Bit_i1 (
    .I0( I0 ),
    .I1( I1 ),
    .I2( s3 ),
    .I3( s4 ),
    .I4( s5 ),
    .I5( s6 ),
    .I6( s7 ),
    .O( MemRead_temp )
  );
  // sw
  And7Bit And7Bit_i2 (
    .I0( I0 ),
    .I1( I1 ),
    .I2( s8 ),
    .I3( s9 ),
    .I4( s10 ),
    .I5( I5 ),
    .I6( s11 ),
    .O( MemWrite_temp )
  );
  // beq
  And7Bit And7Bit_i3 (
    .I0( I0 ),
    .I1( I1 ),
    .I2( s12 ),
    .I3( s13 ),
    .I4( s14 ),
    .I5( I5 ),
    .I6( I6 ),
    .O( ALUop0_temp )
  );
  assign ALU_src = (MemRead_temp | MemWrite_temp);
  assign RegWrite = (ALUop1_temp | MemRead_temp);
  assign MemtoReg = MemRead_temp;
  assign MemRead = MemRead_temp;
  assign MemWrite = MemWrite_temp;
  assign Branch = ALUop0_temp;
  assign ALUop1 = ALUop1_temp;
  assign ALUop0 = ALUop0_temp;
endmodule

module And3bit (
  input a0,
  input a1,
  input a2,
  output out
);
  assign out = ((a0 & a1) & a2);
endmodule

module And6bit (
  input a0,
  input a1,
  input a2,
  input a3,
  input a4,
  input a5,
  output out
);
  wire s0;
  wire s1;
  And3bit And3bit_i0 (
    .a0( a0 ),
    .a1( a1 ),
    .a2( a2 ),
    .out( s0 )
  );
  And3bit And3bit_i1 (
    .a0( a3 ),
    .a1( a4 ),
    .a2( a5 ),
    .out( s1 )
  );
  assign out = (s0 & s1);
endmodule

module alu_control_unit (
  input ALUin1,
  input ALUin0,
  input [3:0] F,
  output [3:0] Operation
);
  wire s0;
  wire s1;
  wire s2;
  wire s3;
  wire s4;
  wire s5;
  wire s6;
  wire s7;
  wire s8;
  wire s9;
  wire s10;
  wire s11;
  wire s12;
  assign s9 = ~ ALUin0;
  assign s4 = F[0];
  assign s5 = F[1];
  assign s6 = F[2];
  assign s8 = F[3];
  assign s2 = ~ s4;
  assign s1 = ~ s5;
  assign s0 = ~ s6;
  assign s10 = ~ s8;
  assign s11 = ~ s4;
  And3bit And3bit_i0 (
    .a0( s0 ),
    .a1( s1 ),
    .a2( s2 ),
    .out( s3 )
  );
  And6bit And6bit_i1 (
    .a0( ALUin1 ),
    .a1( s9 ),
    .a2( s10 ),
    .a3( s6 ),
    .a4( s5 ),
    .a5( s11 ),
    .out( s12 )
  );
  assign s7 = (s3 & (ALUin1 & ~ ALUin0));
  assign Operation[0] = s12;
  assign Operation[1] = (s7 | ~ ALUin1);
  assign Operation[2] = ((~ ALUin1 & ALUin0) | (s8 & s7));
  assign Operation[3] = 1'b0;
endmodule

module And4bit (
  input a0,
  input a1,
  input a2,
  input a3,
  output out
);
  assign out = ((a0 & a1) & (a2 & a3));
endmodule

module Or6bit (
  input a0,
  input a1,
  input a2,
  input a3,
  input a4,
  input a5,
  output out
);
  assign out = (((a0 | a1) | (a2 | a3)) | (a4 | a5));
endmodule

module branch_control_unit (
  input zr,
  input ng,
  input Branch,
  input [2:0] funct3,
  output CBranch
);
  wire s0;
  wire s1;
  wire s2;
  wire s3;
  wire s4;
  wire s5;
  wire s6;
  wire s7;
  wire s8;
  wire s9;
  wire s10;
  wire s11;
  wire s12;
  wire s13;
  wire s14;
  wire s15;
  wire s16;
  wire s17;
  wire s18;
  wire s19;
  wire s20;
  assign s7 = ~ zr;
  assign s15 = (zr | ~ ng);
  assign s6 = funct3[0];
  assign s13 = funct3[1];
  assign s9 = funct3[2];
  assign s0 = ~ s9;
  assign s1 = ~ s13;
  assign s2 = ~ s6;
  assign s4 = ~ s9;
  assign s5 = ~ s13;
  assign s10 = ~ s13;
  assign s11 = ~ s6;
  // BGEU
  And4bit And4bit_i0 (
    .a0( s9 ),
    .a1( s13 ),
    .a2( s6 ),
    .a3( 1'b0 ),
    .out( s19 )
  );
  assign s14 = ~ s13;
  assign s17 = ~ s6;
  // BEQ
  And4bit And4bit_i1 (
    .a0( s0 ),
    .a1( s1 ),
    .a2( s2 ),
    .a3( zr ),
    .out( s3 )
  );
  // BNE
  And4bit And4bit_i2 (
    .a0( s4 ),
    .a1( s5 ),
    .a2( s6 ),
    .a3( s7 ),
    .out( s8 )
  );
  // BLT
  And4bit And4bit_i3 (
    .a0( s9 ),
    .a1( s10 ),
    .a2( s11 ),
    .a3( ng ),
    .out( s12 )
  );
  // BGE
  And4bit And4bit_i4 (
    .a0( s9 ),
    .a1( s14 ),
    .a2( s6 ),
    .a3( s15 ),
    .out( s16 )
  );
  // BLTU
  And4bit And4bit_i5 (
    .a0( s9 ),
    .a1( s13 ),
    .a2( s17 ),
    .a3( 1'b0 ),
    .out( s18 )
  );
  Or6bit Or6bit_i6 (
    .a0( s3 ),
    .a1( s8 ),
    .a2( s12 ),
    .a3( s16 ),
    .a4( s18 ),
    .a5( s19 ),
    .out( s20 )
  );
  assign CBranch = (s20 & Branch);
endmodule

module CPU (
  input Clock,
  output MemRead
);
  wire [31:0] s0;
  wire s1;
  wire [4:0] s2;
  wire [4:0] s3;
  wire [4:0] s4;
  wire [31:0] s5;
  wire [31:0] s6;
  wire [31:0] s7;
  wire [31:0] s8;
  wire [31:0] s9;
  wire [31:0] s10;
  wire [31:0] s11;
  wire s12;
  wire s13;
  wire [31:0] s14;
  wire [31:0] s15;
  wire s16;
  wire [31:0] s17;
  wire [11:0] s18;
  wire [31:0] s19;
  wire [6:0] s20;
  wire [2:0] s21;
  wire [3:0] s22;
  wire s23;
  wire s24;
  wire s25;
  wire s26;
  wire s27;
  wire s28;
  wire s29;
  wire s30;
  wire [23:0] s31;
  wire s32;
  wire [23:0] s33;
  wire [3:0] s34;
  wire s35;
  wire s36;
  wire s37;
  wire s38;
  RegFile32Bit RegFile32Bit_i0 (
    .DataToWrite( s0 ),
    .writeEnable( s1 ),
    .writeReg( s2 ),
    .Read1( s3 ),
    .Read2( s4 ),
    .CPU_clock( Clock ),
    .Register1( s5 ),
    .Register2( s6 )
  );
  // PC
  DIG_Register_BUS #(
    .Bits(32)
  )
  DIG_Register_BUS_i1 (
    .D( s7 ),
    .C( Clock ),
    .en( 1'b1 ),
    .Q( s8 )
  );
  Adder32Bit Adder32Bit_i2 (
    .B( s8 ),
    .A( 32'b100 ),
    .C_in( 1'b0 ),
    .sum( s9 )
  );
  Adder32Bit Adder32Bit_i3 (
    .B( s10 ),
    .A( s8 ),
    .C_in( 1'b0 ),
    .sum( s11 )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i4 (
    .sel( s12 ),
    .in_0( s9 ),
    .in_1( s11 ),
    .out( s7 )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i5 (
    .sel( s13 ),
    .in_0( s14 ),
    .in_1( s15 ),
    .out( s0 )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i6 (
    .sel( s16 ),
    .in_0( s6 ),
    .in_1( s10 ),
    .out( s17 )
  );
  // ImmGen
  DIG_BitExtender #(
    .inputBits(12),
    .outputBits(32)
  )
  DIG_BitExtender_i7 (
    .in( s18 ),
    .out( s10 )
  );
  ALU32Bit ALU32Bit_i8 (
    .Operation( s22 ),
    .a( s5 ),
    .b( s17 ),
    .ALU_out( s14 ),
    .zero( s23 )
  );
  InstructionMemory InstructionMemory_i9 (
    .Clk( Clock ),
    .Loc_addr( s31 ),
    .Data_in( s6 ),
    .WriteToMem( s32 ),
    .Data_out( s15 )
  );
  InstructionMemory InstructionMemory_i10 (
    .Clk( Clock ),
    .Loc_addr( s33 ),
    .Data_in( 32'b0 ),
    .WriteToMem( 1'b0 ),
    .Data_out( s19 )
  );
  assign s34[0] = s19[30];
  assign s34[3:1] = s21;
  OPCodeControlUnit OPCodeControlUnit_i11 (
    .I0( s30 ),
    .I1( s29 ),
    .I2( s28 ),
    .I3( s27 ),
    .I4( s26 ),
    .I5( s25 ),
    .I6( s24 ),
    .ALU_src( s16 ),
    .MemtoReg( s13 ),
    .RegWrite( s1 ),
    .MemRead( MemRead ),
    .MemWrite( s32 ),
    .Branch( s35 ),
    .ALUop1( s36 ),
    .ALUop0( s37 )
  );
  alu_control_unit alu_control_unit_i12 (
    .ALUin1( s37 ),
    .ALUin0( s36 ),
    .F( s34 ),
    .Operation( s22 )
  );
  branch_control_unit branch_control_unit_i13 (
    .zr( s23 ),
    .ng( s38 ),
    .Branch( s35 ),
    .funct3( s21 ),
    .CBranch( s12 )
  );
  assign s20 = s19[6:0];
  assign s2 = s19[11:7];
  assign s21 = s19[14:12];
  assign s3 = s19[19:15];
  assign s4 = s19[24:20];
  assign s24 = s20[0];
  assign s25 = s20[1];
  assign s26 = s20[2];
  assign s27 = s20[3];
  assign s28 = s20[4];
  assign s29 = s20[5];
  assign s30 = s20[6];
  assign s18 = s19[11:0];
  assign s31 = s14[23:0];
  assign s33 = s8[23:0];
  assign s38 = s14[31];
endmodule