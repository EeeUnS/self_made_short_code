/*
 * sr: status regiter for SimpleCore. 
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: sr.v
 * Date: 2001/8/23
 */

module sr (
	clk,
	nreset,
	condFlag,
	wbData,
	wbSel,
	srOEn,
	srWbEn,
	zFlag,
	rdData
);
input		clk;
input		nreset;
input	[ 3:0]	condFlag;
input	[ 3:0]	wbData;
input		wbSel;
input		srOEn;
input		srWbEn;
output		zFlag;
output	[ 3:0]	rdData;

reg	[3:0]	srData;

always@(posedge clk)
begin
	if(~nreset)
		srData <= 4'b0;
	else if(srWbEn == 1'b1)
		if(wbSel)
			srData <= condFlag;
		else
			srData <= wbData;
end

assign	zFlag = srData[2];
assign	rdData = srOEn ? srData : 4'bz;

endmodule
