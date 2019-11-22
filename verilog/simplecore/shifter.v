/*
 * shifter: 16-bit barrel shifter for SimpleCore. 
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: shifter.v
 * Date: 2001/8/23
 */

module	shifter(
	shiftIn,
	shiftAmt, 
	shiftCtl,
	shiftOut
);

input	[15:0]	shiftIn;  // shifter input
input	[ 3:0]	shiftAmt; // shift amount
input	[ 2:0]	shiftCtl; // control input {left/right, arith/logic, rotate}
output	[15:0]	shiftOut; // shifter output

reg	[15:0]	shiftOut;

always @ (shiftIn or shiftAmt or shiftCtl)
begin
	casex(shiftCtl)
		3'b0?? : // LSL (logical shift left)
			shiftOut = shiftIn << shiftAmt; 
		3'b100 : // LSR (logical shift right)
			shiftOut = shiftIn >> shiftAmt; 
		3'b101 : // ASR (arithmetic shift right)
			shiftOut = ({16{shiftIn[15]}}<<(16-shiftAmt)) | (shiftIn >> shiftAmt); 
		3'b11? : // ROR (rotate right)
			shiftOut = (shiftIn >> shiftAmt) | (shiftIn << (16-shiftAmt)); 
	endcase
end

endmodule
/*
module shifter_test;

reg	[15:0]	shiftIn;
reg	[ 3:0]	shiftAmt;
reg	[ 2:0]	shiftCtl; // {left/right, arith/logic, ror}
wire	[15:0]	shiftOut;

shifter shifter(
	shiftIn,
	shiftAmt, 
	shiftCtl,
	shiftOut
);

initial
begin
	$monitor("%b %b %b %b", shiftIn, shiftAmt, shiftCtl, shiftOut);
	shiftIn = 16'hffff;
	shiftAmt = 0;
	shiftCtl = 3'b0;
#10
	shiftIn = 16'h3c3c;
	shiftAmt = 3;
	shiftCtl = 3'b001;
#10
	$finish;
end

endmodule
*/
