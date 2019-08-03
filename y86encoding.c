#include<stdio.h>

// Y86 -> 기계어 변환기


/*

halt 00
nop  10

rrmovl 20
cmovle 21
cmovl 2 2
cmove 2 3
cmovne 2 4
cmovge 2 5
cmovg 2 6

irmovl 30
rmmovl 40
mrmovl 50


addl 6 0
subl 6 1
andl 6 2
xorl 6 3

jmp 70
jle 71
jl 7 2
je 7 3
jne 7 4
jge 7 5
jg 7 6

call 80
ret 90
pushl A0
popl B0

0 %eax
1 %ecx
2 %edx
3 %ebx
4 %esp
5 %ebp
6 %esi
7 %edi
F No register

*/

enum Instruction
{
	halt = 0,
	nop,
	//20

	rrmovl,
	cmovle,
	cmovl,
	cmove,
	cmovne,
	cmovge,
	cmovg,


	irmovl, 
	rmmovl,
	mrmovl,


	//60
	addl,
	subl,
	andl, 
	xorl,

	//70
	jmp ,
	jle ,
	jl ,
	je ,
	jne ,
	jge ,
	jg ,


	//80
	call,
	ret,
	pushl,
	popl

};

const char* instruction[] =
{
	"halt",
	"nop",

	"rrmovl",
	"cmovle",
	"cmovl",
	"cmove",
	"cmovne",
	"cmovge",
	"cmovg",

	"irmovl",
	"rmmovl",
	"mrmovl",


	"addl",
	"subl",
	"andl",
	"xorl",

	"jmp" ,
	"jle" ,
	"jl" ,
	"je" ,
	"jne" ,
	"jge" ,
	"jg" ,

	"call",
	"ret",
	"pushl",
	"popl"
};

const int Instruction_Encoding[]
{
	0x00,
	0x10,
	0x20,
	0x21,
	0x22,
	0x23,
	0x24,
	0x25,
	0x26,

	0x30,
	0x40,
	0x50,
	
	0x60,
	0x61,
	0x62,
	0x63,

	0x70,
	0x71,
	0x72,
	0x73,
	0x74,
	0x75,
	0x76,

	0x80,
	0x90,
	0xA0,
	0xB0,
};

char* Label[20][20];

int main()
{





}