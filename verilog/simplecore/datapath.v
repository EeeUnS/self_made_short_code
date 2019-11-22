/*
 * datapath: datapath of SimpleCore
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: datapath.v
 * Date: 2001/8/23
 */

module	datapath (
	clk,
	nreset,
	imm,
	cmpFlag,
	srOEn,
	srWbEn,
	aluCtl,
	shiftCtl,
	aluOEn,
	shiftOEn,
	mulOEn,
	opAIdx,
	opBIdx,
	rdAOEn,
	rdBOEn,
	immOEn,
	wbIdx,
	wbEn,
	iAregCtl,
	dAregCtl,
	dInCtl,
	dOutCtl,
	dIn,

	zFlag,
	iAddr,
	dAddr,
	dOut
);

input		clk;
input		nreset;

input	[15:0]	imm;		// immediate data
input		cmpFlag;	// compare flag
input		srOEn, srWbEn;	// status register read/write enable
input	[ 2:0]	aluCtl;		// alu control
input		aluOEn;		// alu output enable
input	[ 2:0]	shiftCtl;	// shifter control
input		shiftOEn;	// shifter output enable
input		mulOEn;		// multiplier output enable
input	[ 3:0]	opAIdx;		// operand A index
input	[ 3:0]	opBIdx;		// operand B index
input		rdAOEn;		// read A output enable
input		rdBOEn;		// read B output enable
input	[ 3:0]	wbIdx;		// writeback index
input		wbEn;		// write enable
input		immOEn;		// immediate output enable
input		iAregCtl;	// instruction address register control
input		dAregCtl;	// data address register control
input		dInCtl;		// data input control
input		dOutCtl;	// data output control
input	[15:0]	dIn;

output		zFlag;    // zero flag
output	[15:0]	iAddr;    // instruction address
output	[15:0]	dAddr;    // data address
output	[15:0]	dOut;

wire	[15:0]	busA, busB, busW;
wire	[15:0]	aluOut;   // alu output
wire	[ 3:0]	condFlag; // condition flags
wire	[15:0]	shiftOut; // shifter output
wire	[15:0]	mulOut;   // multiplier output
wire	[15:0]	incrOut;  // address increment

// register file
regFile	IregFile (
	.clk		(clk		),
	.rdAIdx		(opAIdx		),
	.rdBIdx		(opBIdx		),
	.rdAOEn		(rdAOEn		),
	.rdBOEn		(rdBOEn		),
	.wbIdx		(wbIdx		),
	.wbData		(busW		),
	.wbEn		(wbEn		),
	.pc		(iAddr		),
	.rdAData	(busA		),
	.rdBData	(busB		)
);

assign	busB = immOEn ? imm : 16'bz;

sr Isr(
	.clk		(clk		),
	.nreset		(nreset		),
	.condFlag	(condFlag	),
	.wbData		(busW[15:12]	),
	.wbSel		(cmpFlag	),
	.srOEn		(srOEn		),
	.srWbEn		(srWbEn		),
	.zFlag		(zFlag		),
	.rdData		(busA[15:12]	)
);

// alu
alu	Ialu(
	.aluAIn		(busA		),
	.aluBIn		(busB		),
	.aluCtl		(aluCtl		),
	.aluOut		(aluOut		),
	.condFlag	(condFlag	)
);

assign	busW = aluOEn ? aluOut : 16'hz;

// shifter
shifter	Ishifter(
	.shiftIn	(busA		),
	.shiftAmt	(busB[3:0]	), 
	.shiftCtl	(shiftCtl	),
	.shiftOut	(shiftOut	)
);

assign	busW = shiftOEn ? shiftOut : 16'hz;

mul	Imul(
	.mulAIn		(busA		),
	.mulBIn		(busB		),
	.mulOut		(mulOut		)
);

assign	busW = mulOEn ? mulOut : 16'hz;

// address increment
incr	Iincr (
	.iAddr		(iAddr		),
	.incrOut	(incrOut	)
);

// instruction address
iAreg	IiAreg (
	.clk		(clk		),
	.nreset		(nreset		),
	.incrOut	(incrOut	),
	.aluOut		(aluOut		),
	.iAregCtl	(iAregCtl	),
	.iAddr		(iAddr		)
);

// data address
dAreg	IdAreg (
	.clk		(clk		),
	.aluOut		(aluOut		),
	.dAregCtl	(dAregCtl	),
	.dAddr		(dAddr		)
);

// data out
dOutreg	IdOutreg (
	.clk		(clk		),
	.busB		(busB		),
	.dOutCtl	(dOutCtl	),
	.dOut		(dOut		)
);	

// data in
assign	busW = (dInCtl == 1'b1) ? dIn : 16'bz;

endmodule
