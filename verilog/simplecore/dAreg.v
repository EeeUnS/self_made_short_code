/*
 * dAreg: data address register
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: dAreg.v
 * Date: 2001/8/23
 */

module	dAreg (
	clk,
	aluOut,
	dAregCtl,
	dAddr
);
input		clk;
input	[15:0]	aluOut;
input		dAregCtl;
output	[15:0]	dAddr;

reg	[15:0]	dAddr;

always@(clk or dAregCtl or aluOut)
begin
	if(dAregCtl == 1'b1 && clk == 1'b1) // transparent latch
		dAddr = aluOut;
end

endmodule
