/*
 * execute: execute unit for SimpleCore
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: execute.v
 * Date: 2001/8/23
 */

// operand A control
`define	ARD	2'b00	// operand A : Rd
`define	ARS1	2'b01	// operand A : Rs1
`define	APC	2'b10	// operand A : PC

// operand B control
`define	BIM	2'b00	// operand B : Immediate
`define	BRS2	2'b01	// operand B : Rs2
`define	BRD	2'b10	// operand B : Rd

module	execute (
	clk,
	instId,
	cond,
	opcode,
	shift,
	rs1Idx,
	rs2Idx,
	rdIdx,
	imm,
	immFlag,
	cmpFlag,
	srOEn,
	srWbEn,
	aluCtl,
	aluOEn,
	shiftCtl,
	shiftOEn,
	mulOEn,
	opAIdx,
	opBIdx,
	rdAOEn,
	rdBOEn,
	wbIdx,
	wbEn,
	immOEn,
	iAregCtl,
	dAregCtl,
	dInCtl,
	dOutCtl
	);

input		clk;		// main clock
input	[ 2:0]	instId;		// instruction ID
input	[ 1:0]	cond;		// condition
input	[ 2:0]	opcode;		// op code
input	[ 1:0]	shift;		// shift type
input	[ 3:0]	rs1Idx;		// Rs1 index
input	[ 3:0]	rs2Idx;		// Rb/Rs2 index
input	[ 3:0]	rdIdx;		// Rd index
input	[15:0]	imm;		// immediate data
input		immFlag;	// immediate operand flag
input		cmpFlag;	// compare flag (update status register, no writeback)
input		srOEn, srWbEn;	// status register read/write enable

output	[ 2:0]	aluCtl;		// alu control
output		aluOEn;		// alu output enable
output	[ 2:0]	shiftCtl;	// shifter control
output		shiftOEn;	// shifter output enable
output		mulOEn;		// multiplier output enable
output	[ 3:0]	opAIdx;		// operand A index
output	[ 3:0]	opBIdx;		// operand B index
output		rdAOEn;		// read A output enable
output		rdBOEn;		// read B output enable
output	[ 3:0]	wbIdx;		// writeback index
output		wbEn;		// write enable
output		immOEn;		// immediate output enable
output		iAregCtl;	// instruction address register control
output		dAregCtl;	// data address register control
output		dInCtl;		// data input control
output		dOutCtl;	// data output control

reg	[16:0]	control;
reg	[ 2:0]	aluCtl;
reg	[ 2:0]	shiftCtl;
reg	[ 3:0]	opAIdx;
reg	[ 3:0]	opBIdx;

always@(instId or opcode)
begin
	casex(instId)
		// control signals      : |opcode |aluOEn|shiftOEn|mulOEn| opA | opB |wbEn|iAreg|dAreg|dInCtl|dOutCtl|
		`INST_ALUI   : control <= { opcode,  1'b1,    1'b0,  1'b0,`ARD ,`BIM ,1'b1, 1'b0, 1'b0,  1'b0,   1'b0};
		`INST_ALUR   : control <= { opcode,  1'b1,    1'b0,  1'b0,`ARS1,`BRS2,1'b1, 1'b0, 1'b0,  1'b0,   1'b0};
		`INST_SHRO   : control <= {   3'bx,  1'b0,    1'b1,  1'b0,`ARS1,`BRS2,1'b1, 1'b0, 1'b0,  1'b0,   1'b0};
		`INST_LOAD   : control <= {`OP_MOV,  1'b0,    1'b0,  1'b0,`ARS1, 2'bx,1'b1, 1'b0, 1'b1,  1'b1,   1'b0};
		`INST_STORE  : control <= {`OP_MOV,  1'b0,    1'b0,  1'b0,`ARS1,`BRD ,1'b0, 1'b0, 1'b1,  1'b0,   1'b1};
		`INST_BRANCH : control <= {`OP_ADD,  1'b1,    1'b0,  1'b0,`APC ,`BIM ,1'b0, 1'b1, 1'b0,  1'b0,   1'b0};
		`INST_MUL    : control <= {   3'bx,  1'b0,    1'b0,  1'b1,`ARS1,`BRS2,1'b1, 1'b0, 1'b0,  1'b0,   1'b0};
	endcase
end

wire	[ 2:0]	opcodeTmp;
wire	[ 1:0]	opA;
wire	[ 1:0]	opB;
wire		wbEnTmp; 

assign	{opcodeTmp, aluOEn, shiftOEn, mulOEn, opA, opB, wbEnTmp, iAregCtl, dAregCtl,dInCtl, dOutCtl} = control;

assign	rdAOEn = ~srOEn;
assign	rdBOEn = (opB != `BIM);
assign	wbEn   = (cmpFlag == 1'b0 && wbEnTmp == 1'b1);	// no writeback for compare instructions
assign	immOEn = (opB == `BIM);

// opAIdx
always@(opA or rdIdx or rs1Idx)
begin
	casex(opA)
		`ARD   : opAIdx <= rdIdx;
		`ARS1  : opAIdx <= rs1Idx;
		`APC   : opAIdx <= 4'b1111;
		default: opAIdx <= 4'bx;
	endcase
end

// opBIdx
always@(opB or rdIdx or rs2Idx)
begin
	casex(opB)
		`BIM   : opBIdx <= 4'bx;
		`BRS2  : opBIdx <= rs2Idx;
		`BRD   : opBIdx <= rdIdx;
		default: opBIdx <= 4'bx;
	endcase
end

assign	wbIdx = rdIdx;

// aluCtl
always@(opcodeTmp or immFlag)
begin
	casex({opcodeTmp, immFlag})
		{`OP_MOV,1'b0}	: aluCtl <= 3'b000;
		{`OP_MOV,1'b1}	: aluCtl <= 3'b001;
		{`OP_ADD,1'b?}	: aluCtl <= 3'b100;
		{`OP_SUB,1'b?}	: aluCtl <= 3'b11x;
		{`OP_AND,1'b?}	: aluCtl <= 3'b01x;
		{`OP_OR ,1'b?}	: aluCtl <= 3'b011;
		{`OP_CMP,1'b?}	: aluCtl <= 3'b110;
		{`OP_MSR,1'b?}	: aluCtl <= 3'b000;
		{`OP_MRS,1'b?}	: aluCtl <= 3'b000;
	endcase
end

always@(shift)
begin
	casex(shift)
		`SH_LSL	: shiftCtl <= 3'b0xx;
		`SH_LSR	: shiftCtl <= 3'b100;
		`SH_ASR	: shiftCtl <= 3'b101;
		`SH_ROR	: shiftCtl <= 3'b11x;
	endcase
end

endmodule
