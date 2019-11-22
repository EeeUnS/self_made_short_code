/*
 * fetch: fetch unit for SimpleCore
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: fetch.v
 * Date: 2001/8/23
 */

module	fetch (
	clk,
	dIn,
	fInst
	);

input		clk;	// main clock
input	[15:0]	dIn;	// instruction data
output	[15:0]	fInst;	// fetch data

reg	[15:0]	fInst;

always@(posedge clk)
begin
	fInst = dIn;
end

endmodule
