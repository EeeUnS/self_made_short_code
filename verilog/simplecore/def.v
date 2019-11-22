/*
 * def: macros for SimpleCore
 *
 * Copyright (c) 2001. Integrated Computer Systems Lab., KAIST
 * All rights reserved.
 *
 * Author: Bae Young-Don(donny@ics.kaist.ac.kr)
 * Source: def.v
 * Date: 2001/8/23
 */

`define INST_ALUI	3'd0	// ALU immediate operand
`define INST_ALUR	3'd1	// ALU register operand
`define INST_SHRO	3'd2	// shift and rotate
`define INST_LOAD	3'd3	// load
`define INST_STORE	3'd4	// store
`define INST_BRANCH	3'd5	// branch
`define INST_MUL	3'd6	// multiply

`define COND_EQ		2'd0	// equal
`define COND_NE		2'd1	// not equal
`define COND_AL		2'd2	// always
`define COND_NV		2'd3	// never

`define	OP_MOV		3'd0
`define	OP_ADD		3'd1
`define	OP_SUB		3'd2
`define	OP_AND		3'd3
`define	OP_OR		3'd4
`define	OP_CMP		3'd5
`define	OP_MSR		3'd6
`define	OP_MRS		3'd7

`define	SH_LSL		2'd0	// logical shift left
`define	SH_LSR		2'd1	// logical shift right
`define	SH_ASR		2'd2	// arithmetic shift right
`define	SH_ROR		2'd3	// rotate
