/*
 * incr: address incrementor
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: incr.v
 * Date: 2001/8/23
 */

module	incr (
	iAddr,
	incrOut,
);

input	[15:0]	iAddr;
output	[15:0]	incrOut;

assign	incrOut = iAddr + 2;

endmodule
