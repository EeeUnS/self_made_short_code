/*
 * mem: external memory module description
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young Don(donny@duo.kaist.ac.kr)
 * Source: mem.v
 * Date: 2001/8/23
 */

/* memory control */
`define DATA_READ  1'b0
`define DATA_WRITE 1'b0

/* 32k entry * 4 bytes SRAM */
module	sram1k16 (
	nCS,
	addr,
	data,
	nOE,
	nWE,
	nLB,
	nUB
	);

input	[ 9:0]	addr;
inout	[15:0]	data;
input		nCS, nOE, nWE;
input		nLB, nUB;

parameter	maxindex = 'h1ffff;
parameter	accesstime = 3; 

reg    [15:0]	outline;
reg    [15:0]	ram[0:'h3ff];
wire   [15:0]	read_tmp;
reg    [15:0]	write_tmp;

assign data[15: 8] = (~nCS && nOE == `DATA_READ && ~nUB) ? outline[15: 8] : 16'hz;
assign data[ 7: 0] = (~nCS && nOE == `DATA_READ && ~nLB) ? outline[ 7: 0] : 16'hz;

assign read_tmp = ram[addr];

always @(addr or nCS or nOE or nLB or nUB or nWE or data)
begin
	#accesstime 
	if (~nCS && addr <= maxindex)
	begin
		if (nOE == `DATA_READ)
		begin
			outline = ram[addr];
		end
		else 
		begin
			write_tmp[ 7: 0] = (~nLB & ~nWE) ? data[ 7: 0] : read_tmp[ 7: 0];
			write_tmp[15: 8] = (~nUB & ~nWE) ? data[15: 8] : read_tmp[15: 8];
			ram[addr] = write_tmp;
		end
	end
end

endmodule
