/*
 * regFile: 16-bit register file for SimpleCore.
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: regFile.v
 * Date: 2001/8/23
 */

module	gpr (
	clk,
	wbEn,
	wbData,
	rdData
);

input		clk;
input		wbEn;
input	[15:0]	wbData;
output	[15:0]	rdData;

reg	[15:0]	rdData;

always	@(posedge clk)
	if(wbEn)
		rdData= wbData;

endmodule

module	regSel (
	rdIdx,
	gpr0 , gpr1 , gpr2 , gpr3 , gpr4 , gpr5 , gpr6 , gpr7,
	gpr8 , gpr9 , gpr10, gpr11, gpr12, gpr13, gpr14, gpr15,
	rdData
);

input	[ 3:0]	rdIdx;
input	[15:0]	gpr0 , gpr1 , gpr2 , gpr3 , gpr4 , gpr5 , gpr6 , gpr7;
input	[15:0]	gpr8 , gpr9 , gpr10, gpr11, gpr12, gpr13, gpr14, gpr15;
output	[15:0]	rdData;

reg	[15:0]	rdData;

always @ (rdIdx or gpr0  or gpr1  or gpr2  or gpr3  or gpr4  or gpr5  or gpr6  or gpr7  or
	gpr8  or gpr9  or gpr10 or gpr11 or gpr12 or gpr13 or gpr14 or gpr15) 
begin
	casex(rdIdx)
		4'd0 :	rdData = gpr0 ;
		4'd1 :	rdData = gpr1 ;
		4'd2 :	rdData = gpr2 ;
		4'd3 :	rdData = gpr3 ;
		4'd4 :	rdData = gpr4 ;
		4'd5 :	rdData = gpr5 ;
		4'd6 :	rdData = gpr6 ;
		4'd7 :	rdData = gpr7 ;
		4'd8 :	rdData = gpr8 ;
		4'd9 :	rdData = gpr9 ;
		4'd10:	rdData = gpr10;
		4'd11:	rdData = gpr11;
		4'd12:	rdData = gpr12;
		4'd13:	rdData = gpr13;
		4'd14:	rdData = gpr14;
		4'd15:	rdData = gpr15;
	endcase
end

endmodule

module	regFile (
	clk,
	rdAIdx,
	rdBIdx,
	rdAOEn,
	rdBOEn,
	wbIdx,
	wbData,
	wbEn,
	pc,
	rdAData,
	rdBData
);

input		clk;
input	[ 3:0]	rdAIdx;   // read index A
input	[ 3:0]	rdBIdx;   // read index B
input		rdAOEn;   // read A output enable
input		rdBOEn;   // read A output enable
input	[ 3:0]	wbIdx;    // writeback index
input	[15:0]	wbData;   // writeback data
input		wbEn;	  // write enable
input	[15:0]	pc;
output	[15:0]	rdAData;  // read data A
output	[15:0]	rdBData;  // read data B

wire	[15:0]	gpr0 , gpr1 , gpr2 , gpr3 , gpr4 , gpr5 , gpr6 , gpr7;
wire	[15:0]	gpr8 , gpr9 , gpr10, gpr11, gpr12, gpr13, gpr14;
wire	[15:0]	rdADataTmp, rdBDataTmp;

gpr	Igpr0 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd0),  .wbData(wbData), .rdData(gpr0 ));
gpr	Igpr1 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd1),  .wbData(wbData), .rdData(gpr1 ));
gpr	Igpr2 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd2),  .wbData(wbData), .rdData(gpr2 ));
gpr	Igpr3 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd3),  .wbData(wbData), .rdData(gpr3 ));
gpr	Igpr4 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd4),  .wbData(wbData), .rdData(gpr4 ));
gpr	Igpr5 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd5),  .wbData(wbData), .rdData(gpr5 ));
gpr	Igpr6 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd6),  .wbData(wbData), .rdData(gpr6 ));
gpr	Igpr7 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd7),  .wbData(wbData), .rdData(gpr7 ));
gpr	Igpr8 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd8),  .wbData(wbData), .rdData(gpr8 ));
gpr	Igpr9 (.clk(clk), .wbEn(wbEn && wbIdx == 4'd9),  .wbData(wbData), .rdData(gpr9 ));
gpr	Igpr10(.clk(clk), .wbEn(wbEn && wbIdx == 4'd10), .wbData(wbData), .rdData(gpr10));
gpr	Igpr11(.clk(clk), .wbEn(wbEn && wbIdx == 4'd11), .wbData(wbData), .rdData(gpr11));
gpr	Igpr12(.clk(clk), .wbEn(wbEn && wbIdx == 4'd12), .wbData(wbData), .rdData(gpr12));
gpr	Igpr13(.clk(clk), .wbEn(wbEn && wbIdx == 4'd13), .wbData(wbData), .rdData(gpr13));
gpr	Igpr14(.clk(clk), .wbEn(wbEn && wbIdx == 4'd14), .wbData(wbData), .rdData(gpr14));

regSel	regASel (
	rdAIdx,
	gpr0 , gpr1 , gpr2 , gpr3 , gpr4 , gpr5 , gpr6 , gpr7,
	gpr8 , gpr9 , gpr10, gpr11, gpr12, gpr13, gpr14, pc,
	rdADataTmp
);

regSel	regBSel (
	rdBIdx,
	gpr0 , gpr1 , gpr2 , gpr3 , gpr4 , gpr5 , gpr6 , gpr7,
	gpr8 , gpr9 , gpr10, gpr11, gpr12, gpr13, gpr14, pc,
	rdBDataTmp
);

assign	rdAData = rdAOEn ? rdADataTmp : 16'hz;
assign	rdBData = rdBOEn ? rdBDataTmp : 16'hz;

endmodule
