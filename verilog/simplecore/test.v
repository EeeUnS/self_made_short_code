/*
 * test: test module of SimpleCore. 
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: test.v
 * Date: 2001/8/23
 */

module	test;

reg		clk;
reg		nreset;
wire	[15:0]	iAddr;
wire	[15:0]	dAddr;
wire	[15:0]	iData;
wire	[15:0]	dData;
wire		nRW;

simplecore Isimplecore (
	.clk		(clk		),
	.nreset		(nreset		),
	.iAddr		(iAddr		),
	.iData		(iData		),
	.dAddr		(dAddr		),
	.dData		(dData		),
	.nRW		(nRW		)
);

sram1k16 imem (
	.nCS		(1'b0		),
	.addr		(iAddr[10:1]	),
	.data		(iData		),
	.nOE		(1'b0		),
	.nWE		(1'b1		),
	.nLB		(1'b0		),
	.nUB		(1'b0		)
	);

sram1k16 dmem (
	.nCS		(1'b0		),
	.addr		(dAddr[10:1]	),
	.data		(dData		),
	.nOE		(nRW		),
	.nWE		(~nRW		),
	.nLB		(1'b0		),
	.nUB		(1'b0		)
	);

always#10	clk = ~clk;

/* end of simulation */
always@(posedge clk)
	if(Isimplecore.Icontrol.exitFlag)
		$finish;

initial	
begin
	clk = 0;
	nreset = 0;
#15
	nreset = 1;
end

initial
begin
	$dumpvars;
	$readmemh("imem.hex", imem.ram, 0);
	$readmemh("dmem.hex", dmem.ram, 0);
end

endmodule
