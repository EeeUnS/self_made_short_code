/*
 * debug: debug information
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: debug.v
 * Date: 2001/8/23
 */

module	instDebug (
	instId,
	instIdText
);

input	[2 :0]	instId;
output	[47:0]	instIdText;

reg	[47:0]	instIdText;

always@(instId)
begin
	casex(instId)
		`INST_ALUI	: instIdText <= "ALUI  ";
		`INST_ALUR	: instIdText <= "ALUR  ";
		`INST_SHRO	: instIdText <= "SHRO  ";
		`INST_LOAD	: instIdText <= "LOAD  ";
		`INST_STORE	: instIdText <= "STORE ";
		`INST_BRANCH	: instIdText <= "BRANCH";
		`INST_MUL	: instIdText <= "MUL   ";
		default		: instIdText <= "UNDEF ";
	endcase
end

endmodule

module	aluDebug (
	aluCtl,
	aluText
);

input	[ 2:0]	aluCtl;
output	[31:0]	aluText;

reg	[31:0]	aluText;

always@(aluCtl)
begin
	casex(aluCtl)
		3'b000: aluText <= "MOVA";
		3'b001: aluText <= "MOVB";
		3'b010: aluText <= "AND ";
		3'b011: aluText <= "OR  ";
		3'b10?: aluText <= "ADD ";
		3'b11?: aluText <= "SUB ";
	endcase
end

endmodule
