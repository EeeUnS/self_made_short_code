/*
 * decode: instruction decode unit for SimpleCore
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: decode.v
 * Date: 2001/8/23
 */

module	decode (
	clk,
	nreset,
	fInst,
	flush,

	refill,
	instId,
	cond,
	opcode,
	shift,
	rs1Idx,
	rs2Idx,
	rdIdx,
	imm,
	immFlag,
	cmpFlag,
	branchFlag,
	exitFlag,
	srOEn,
	srWbEn
	);

input		clk;		// main clock
input		nreset;		// reset
input	[15:0]	fInst;		// fetch data
input		flush;		// pipeline flush

output		refill;		// pipeline refill
output	[ 2:0]	instId;		// instruction ID
output	[ 1:0]	cond;		// condition
output	[ 2:0]	opcode;		// op code
output	[ 1:0]	shift;		// shift type
output	[ 3:0]	rs1Idx;		// Rb/Rs1 Index
output	[ 3:0]	rs2Idx;		// Rs2 Index
output	[ 3:0]	rdIdx;		// Rd Index
output	[15:0]	imm;		// immediate data
output		immFlag;	// immediate operand flag
output		cmpFlag;	// compare flag (update status register, no writeback)
output		branchFlag;	// branch flag
output		exitFlag;	// end of simulation flag
output		srOEn, srWbEn;	// status register read/write enable

reg	[ 2:0]	instId;
reg		refillTmp, refill;
reg	[ 1:0]	cond;

/* pipeline control (reset,flush and refill) */
always@(posedge clk)
begin
	if(~nreset)
		refillTmp <= 1'b1;
	else
	begin
		if(flush)
		begin
			refillTmp <= 1'b1;
			refill    <= 1'b1;
		end
		else
		begin
			refillTmp <= 1'b0;
			refill    <= refillTmp;
		end
	end
end

/* instruction ID */
always@(fInst)
begin
	casex(fInst[15:12])
		4'b00?? : instId <= `INST_ALUI; 	// ALU imm.
		4'b01?? : instId <= `INST_ALUR; 	// ALU reg.
		4'b100? : instId <= `INST_SHRO; 	// Shift/Rotate
		4'b1010 : instId <= `INST_LOAD; 	// Load
		4'b1011 : instId <= `INST_STORE; 	// Store
		4'b110? : instId <= `INST_BRANCH; 	// Branch
		4'b11?0 : instId <= `INST_BRANCH; 	// Branch
		4'b1111 : instId <= `INST_MUL;		// Multiply
	endcase
end

/* condition */
always@(fInst or instId or refill)
begin
	casex({instId, refill})
	{`INST_BRANCH, 1'b0} : cond <=  fInst[13:12];
	{      3'b???, 1'b0} : cond <=  `COND_AL;
	default              : cond <=  `COND_AL;
	endcase
end

/* field extraction */
assign	opcode     = fInst[13:11];
assign	shift      = fInst[12:11];
assign	rs1Idx     = fInst[ 3: 0];
assign	rs2Idx     = {1'b0, fInst[ 6: 4]};
assign	rdIdx      = fInst[10: 7];
assign	imm        = (instId == `INST_BRANCH) ? 
			{{4{fInst[11]}}, fInst[11:0]} :  // sign extension
			{9'b0, fInst[6:0]};		 // zero extension
assign	immFlag    = (instId == `INST_ALUI);
assign	cmpFlag    = (fInst[15:11] == 5'b00101);
assign	branchFlag = (instId == `INST_BRANCH); 
assign	exitFlag   = (fInst[15:11] == 5'b00111);	 // end of simulation
assign	srWbEn     = (fInst[15:11] == 5'b00110) || (fInst[15:11] == 5'b00101); // MSR or CMP
assign	srOEn      = (fInst[15:11] == 5'b00111); // MRS

endmodule
