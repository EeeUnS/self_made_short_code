/*
 * alu: 16-bit ALU(Arithmetic Logic Unit) for SimpleCore.
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: alu.v
 * Date: 2001/8/23
 */

module	alu(
	aluAIn,
	aluBIn,
	aluCtl,
	aluOut,
	condFlag
);

input	[15:0]	aluAIn;   // alu input A
input	[15:0]	aluBIn;   // alu input B
input	[ 2:0]	aluCtl;   // alu control input
output	[15:0]	aluOut;   // alu output
output	[ 3:0]	condFlag; // condition flags

reg	[15:0]	aluOut;
reg		aluCarry;

always @ (aluAIn or aluBIn or aluCtl)
begin
	casex(aluCtl)
		3'b000: // MOVA
			{aluCarry, aluOut} = {1'b0, aluAIn};
		3'b001: // MOVB
			{aluCarry, aluOut} = {1'b0, aluBIn};
		3'b010: // AND
			{aluCarry, aluOut} = {1'b0, aluAIn & aluBIn};
		3'b011: // OR
			{aluCarry, aluOut} = {1'b0, aluAIn | aluBIn};
		3'b10?: // ADD
			{aluCarry, aluOut} = aluAIn + aluBIn;
		3'b11?: // SUB
			{aluCarry, aluOut} = aluAIn - aluBIn;
	endcase
end

wire	aluOverflow;
assign	aluOverflow = (aluAIn[15] == aluBIn[15])&&(aluAIn[15] != aluOut[15]);

assign	condFlag[3] = aluOut[15];			// negative flag
assign	condFlag[2] = ~|aluOut;				// zero flag
assign	condFlag[1] = aluCtl[2] ? aluCarry    : 1'b0;	// carry flag
assign	condFlag[0] = aluCtl[2] ? aluOverflow : 1'b0;	// overflow flag

endmodule
