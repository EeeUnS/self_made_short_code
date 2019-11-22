/*
 * iAreg: instruction address register
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: iAreg.v
 * Date: 2001/8/23
 */

module	iAreg (
	clk,
	nreset,
	incrOut,
	aluOut,
	iAregCtl,
	iAddr
);
input		clk;
input		nreset;
input	[15:0]	incrOut;
input	[15:0]	aluOut;
input		iAregCtl;
output	[15:0]	iAddr;

reg	[15:0]	iAddr;

always@(posedge clk)
begin
	if(~nreset)
		iAddr = 16'b0;
	else
		if(iAregCtl)
			iAddr = aluOut;
		else
			iAddr = incrOut;
end

endmodule
