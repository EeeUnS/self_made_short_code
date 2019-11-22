/*
 * control: control part of SimpleCore
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: control.v
 * Date: 2001/8/23
 */
 
 module	control (
	clk,
	nreset,
	dIn,
	zFlag,

	imm,
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
input		nreset;		// reset
input	[15:0]	dIn;		// data input
input		zFlag; 		// condition flags

output	[15:0]	imm;		// immediate data
output		cmpFlag;	// compare flag
output		srOEn, srWbEn;	// status register read/write enable
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

wire	[15:0]	fInst;

fetch	Ifetch (
	.clk		(clk		),
	.dIn		(dIn		),
	.fInst		(fInst		)
	);


wire		flush;		// pipeline flush
wire		refill;		// pipeline refill
wire	[ 2:0]	dInstId;	// instruction id
wire	[ 1:0]	dCond;		// condition
wire	[ 2:0]	opcode;		// op code
wire	[ 1:0]	shift;		// shift type
wire	[ 3:0]	rs1Idx;		// Rb/Rs1 Index
wire	[ 3:0]	rs2Idx;		// Rs2 Index
wire	[ 3:0]	rdIdx;		// Rd Index
wire	[15:0]	dImm;		// immediate data
wire		immFlag;	// immediate operand flag
wire		dCmpFlag;	// compare flag (update status register, no writeback)
wire		dBranchFlag;	// branch flag
wire		dExitFlag;	// end of simulation
wire		dSrOEn, dSrWbEn;// status register read/write enable

decode	Idecode (
	.clk		(clk		),
	.nreset		(nreset		),
	.fInst		(fInst		),
	.flush		(flush		),
	.refill		(refill		),
	.instId		(dInstId	),
	.cond		(dCond		),
	.opcode		(opcode		),
	.shift		(shift		),
	.rs1Idx		(rs1Idx		),
	.rs2Idx		(rs2Idx		),
	.rdIdx		(rdIdx		),
	.imm		(dImm		),
	.immFlag	(immFlag	),
	.cmpFlag	(dCmpFlag	),
	.branchFlag	(dBranchFlag	),
	.exitFlag	(dExitFlag	),
	.srOEn		(dSrOEn		),
	.srWbEn		(dSrWbEn	)	
	);

wire	[ 2:0]	dAluCtl;	// alu control
wire		dAluOEn;	// alu output enable
wire	[ 2:0]	dShiftCtl;	// shifter control
wire		dShiftOEn;	// shifter output enable
wire		dMulOEn;	// multiplier output enable
wire	[ 3:0]	dOpAIdx;	// operand A index
wire	[ 3:0]	dOpBIdx;	// operand B index
wire		dRdAOEn;	// read A output enable
wire		dRdBOEn;	// read B output enable
wire	[ 3:0]	dWbIdx;		// writeback index
wire		dWbEn;		// write enable
wire		dImmOEn;	// immediate output enable
wire		dIAregCtl;	// instruction address register control
wire		dDAregCtl;	// data address register control
wire		dDInCtl;	// data input control
wire		dDOutCtl;	// data output control

reg	[ 2:0]	instId;		// instruction id
reg	[ 1:0]	cond;		// execution condition
reg		cmpFlag;	// compare flag
reg		branchFlag;	// branch flag
reg		eExitFlag;
reg		srOEn, eSrWbEn;	// status register read/write enable
reg	[ 2:0]	aluCtl;		// alu control
reg		aluOEn;		// alu output enable
reg	[ 2:0]	shiftCtl;	// shifter control
reg		shiftOEn;	// shifter output enable
reg		mulOEn;		// multiplier output enable
reg	[ 3:0]	opAIdx;		// operand A index
reg	[ 3:0]	opBIdx;		// operand B index
reg		rdAOEn;		// read A output enable
reg		rdBOEn;		// read B output enable
reg	[ 3:0]	wbIdx;		// writeback index
reg		eWbEn;		// write enable
reg	[15:0]	imm;		// immediate data
reg		immOEn;		// immediate output enable
reg		eIAregCtl;	// instruction address register control
reg		dAregCtl;	// data address register control
reg		dInCtl;		// data input control
reg		eDOutCtl;	// data output control

execute	Iexecute (
	.clk		(clk		),
	.instId		(dInstId	),
	.cond		(dCond		),
	.opcode		(opcode		),
	.shift		(shift		),
	.rs1Idx		(rs1Idx		),
	.rs2Idx		(rs2Idx		),
	.rdIdx		(rdIdx		),
	.imm		(dImm		),
	.immFlag	(immFlag	),
	.cmpFlag	(dCmpFlag	),
	.srOEn		(dSrOEn		),
	.srWbEn		(dSrWbEn	),
	.aluCtl		(dAluCtl	),
	.aluOEn		(dAluOEn	),
	.shiftCtl	(dShiftCtl	),
	.shiftOEn	(dShiftOEn	),
	.mulOEn		(dMulOEn	),
	.opAIdx		(dOpAIdx	),
	.opBIdx		(dOpBIdx	),
	.rdAOEn		(dRdAOEn	),
	.rdBOEn		(dRdBOEn	),
	.wbIdx		(dWbIdx		),
	.wbEn		(dWbEn		),
	.immOEn		(dImmOEn	),
	.iAregCtl	(dIAregCtl	),
	.dAregCtl	(dDAregCtl	),
	.dInCtl		(dDInCtl	),
	.dOutCtl	(dDOutCtl	)
	);

always@(posedge clk)
begin
	if(~nreset)
	begin
		cond		<= 2'b10;
		eSrWbEn		<= 1'b0;
		eWbEn		<= 1'b0;	
		eIAregCtl	<= 1'b0;
		branchFlag	<= 1'b0;
		eExitFlag	<= 1'b0;
	end
	else
	begin
		instId		<= dInstId;
		cond		<= dCond;
		cmpFlag		<= dCmpFlag;
		branchFlag	<= dBranchFlag;
		eExitFlag	<= dExitFlag;
		srOEn  		<= dSrOEn;
		eSrWbEn		<= dSrWbEn;
		aluCtl		<= dAluCtl;
		aluOEn		<= dAluOEn;
		shiftCtl	<= dShiftCtl;
		shiftOEn	<= dShiftOEn;
		mulOEn		<= dMulOEn;
		opAIdx		<= dOpAIdx;
		opBIdx		<= dOpBIdx;
		rdAOEn		<= dRdAOEn;
		rdBOEn		<= dRdBOEn;
		wbIdx		<= dWbIdx;
		eWbEn		<= dWbEn;
		immOEn		<= dImmOEn;
		imm		<= dImm;
		eIAregCtl	<= dIAregCtl;
		dAregCtl	<= dDAregCtl;
		dInCtl		<= dDInCtl;
		eDOutCtl	<= dDOutCtl;
	end
end

/* conditional execution */
wire		execFlag;	// execute flag
assign	execFlag = (cond == `COND_AL) || (cond == `COND_EQ && zFlag) || (cond == `COND_NE && ~zFlag);
assign	flush    = branchFlag & execFlag;

assign	wbEn     = (execFlag && ~refill) ? eWbEn    : 1'b0;
assign	srWbEn   = (execFlag && ~refill) ? eSrWbEn  : 1'b0;
assign	iAregCtl = (execFlag && ~refill) ? eIAregCtl: 1'b0;
assign	dOutCtl  = (execFlag && ~refill) ? eDOutCtl : 1'b0;

/* end of simulation */
wire		exitFlag;
assign	exitFlag = (execFlag && ~refill) ? eExitFlag: 1'b0;

// debug information
wire	[47:0]	instIdText;
instDebug IinstDebug(instId, instIdText); 
wire	[31:0]	aluText;
aluDebug IaluDebug(aluCtl, aluText); 

endmodule
