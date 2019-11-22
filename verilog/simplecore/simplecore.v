/*
 * simplecore: top module of SimpleCore. 
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: simplecore.v
 * Date: 2001/8/23
 */

module	simplecore (
	clk,
	nreset,
	iAddr,
	iData,
	dAddr,
	dData,
	nRW
);

input		clk;
input		nreset;
output	[15:0]	iAddr;    // instruction address
input	[15:0]	iData;    // instruction data
output	[15:0]	dAddr;    // data address
inout 	[15:0]	dData;    // data bus
output		nRW;

wire	[15:0]	imm;
wire		cmpFlag;	// compare flag
wire		srOEn, srWbEn;	// status register read/write enable
wire	[ 2:0]	aluCtl;   // alu control input
wire	[ 2:0]	shiftCtl; // control input {left/right, arith/logic, rotate}
wire		aluOEn;
wire		shiftOEn;
wire		mulOEn;
wire	[ 3:0]	opAIdx;
wire	[ 3:0]	opBIdx;
wire		rdAOEn;
wire		rdBOEn;
wire	[ 3:0]	wbIdx;
wire		wbEn;
wire		immOEn;
wire		iAregCtl;
wire		dAregCtl;
wire		dInCtl;
wire		dOutCtl;
wire	[15:0]	dIn;
wire	[15:0]	dOut;
wire		zFlag;

busCtl	IbusCtl (
	.nRW		(nRW		),
	.dataOut	(dOut		),
	.dataIn		(dIn		),
	.data		(dData		)
);

control	Icontrol (
	clk,
	nreset,
	iData,
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

assign	nRW = dOutCtl;

datapath Idatapath (
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
endmodule
