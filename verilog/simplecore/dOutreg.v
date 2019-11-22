/*
 * dOutreg: data output register
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: dOutreg.v
 * Date: 2001/8/23
 */

module	dOutreg (
	clk,
	busB,
	dOutCtl,
	dOut
);
input		clk;
input	[15:0]	busB;
input		dOutCtl;
output	[15:0]	dOut;

reg	[15:0]	dOut;

always@(clk or dOutCtl or busB)
begin
	if(dOutCtl == 1'b1 && clk == 1'b0) // transparent latch
		dOut = busB;
end

endmodule
