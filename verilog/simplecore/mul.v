/*
 * mul: 16-bit multiplier for SimpleCore.
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: mul.v
 * Date: 2001/8/23
 */

module	mul(
	mulAIn,
	mulBIn,
	mulOut
);

input	[15:0]	mulAIn; // multiplier input A
input	[15:0]	mulBIn; // multiplier input B
output	[15:0]	mulOut; // multiplier output

assign	mulOut = mulAIn * mulBIn;

endmodule
/*
module mul_test;

reg	[15:0]	mulAIn; // multiplier input A
reg	[15:0]	mulBIn; // multiplier input B
wire	[15:0]	mulOut; // multiplier output

mul	mul(
	mulAIn,
	mulBIn,
	mulOut
);

initial
begin
	$monitor("%b %b %b", mulAIn, mulBIn, mulOut);
	mulAIn = 16'hffff;
	mulBIn = 16'b0;
#10
	mulAIn = 16'hffff;
	mulBIn = 16'b1;
#10
	$finish;
end

endmodule
*/
