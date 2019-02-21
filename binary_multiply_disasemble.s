#include<stdio.h>

int main()
{
003F6070  push        ebp  
003F6071  mov         ebp,esp  
003F6073  sub         esp,0F0h  
003F6079  push        ebx  
003F607A  push        esi  
003F607B  push        edi  
003F607C  lea         edi,[ebp-0F0h]  
003F6082  mov         ecx,3Ch  
003F6087  mov         eax,0CCCCCCCCh  
003F608C  rep stos    dword ptr es:[edi]  
003F608E  mov         ecx,offset _F6C3F367_소스.cpp (040A042h)  
003F6093  call        @__CheckForDebuggerJustMyCode@4 (03E17D5h)  
	char  a = 10, b = 10; // a*b =c
003F6098  mov         byte ptr [a],0Ah  
003F609C  mov         byte ptr [b],0Ah  
	char c = 0;
003F60A0  mov         byte ptr [c],0  
	char n = 0;
003F60A4  mov         byte ptr [n],0  
	printf("%d \n%d", a, b);
003F60A8  movsx       eax,byte ptr [b]  
003F60AC  push        eax  
003F60AD  movsx       ecx,byte ptr [a]  
003F60B1  push        ecx  
003F60B2  push        offset string "%d \n%d" (0401A08h)  
003F60B7  call        _printf (03E10E6h)  
003F60BC  add         esp,0Ch  
	while (b != 0)
003F60BF  movsx       eax,byte ptr [b]  
003F60C3  test        eax,eax  
003F60C5  je          main+78h (03F60E8h)  
	{
		n = b & 1;
003F60C7  movsx       eax,byte ptr [b]  
003F60CB  and         eax,1  
003F60CE  mov         byte ptr [n],al  
		b >> 1;
		a << 1;
		if (n)
003F60D1  movsx       eax,byte ptr [n]  
003F60D5  test        eax,eax  
003F60D7  je          main+76h (03F60E6h)  
		{
			c += a;
003F60D9  movsx       eax,byte ptr [a]  
003F60DD  movsx       ecx,byte ptr [c]  
003F60E1  add         ecx,eax  
003F60E3  mov         byte ptr [c],cl  
		}
	}
003F60E6  jmp         main+4Fh (03F60BFh)  
	printf("%d", c);
003F60E8  movsx       eax,byte ptr [c]  
003F60EC  push        eax  
003F60ED  push        offset string "%d" (0401A10h)  
003F60F2  call        _printf (03E10E6h)  
003F60F7  add         esp,8  
	return 0;
003F60FA  xor         eax,eax  
}
