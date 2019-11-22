/*
 * busCtl: I/O bus control
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: busCtl.v
 * Date: 2001/8/23
 */

module	busCtl(
	nRW,
	dataOut,
	dataIn,
	data
	);
input		nRW;
input	[15:0]	dataOut;

output	[15:0]	dataIn;

inout	[15:0]	data;

assign	dataIn = data;
assign	data = (nRW) ? dataOut : 16'hzz;

endmodule
