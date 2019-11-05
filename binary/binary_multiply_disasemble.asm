#include<stdio.h>

int main()
{
00CD6070  push        ebp  
00CD6071  mov         ebp,esp  
00CD6073  sub         esp,0F0h  
00CD6079  push        ebx  
00CD607A  push        esi  
00CD607B  push        edi  
00CD607C  lea         edi,[ebp-0F0h]  
00CD6082  mov         ecx,3Ch  
00CD6087  mov         eax,0CCCCCCCCh  
00CD608C  rep stos    dword ptr es:[edi]  
00CD608E  mov         ecx,offset _F6C3F367_소스.cpp (0CEA042h)  
00CD6093  call        @__CheckForDebuggerJustMyCode@4 (0CC17D5h)  
	char a = 10, b = 10; // a*b =c
00CD6098  mov         byte ptr [a],0Ah  
00CD609C  mov         byte ptr [b],0Ah  
	char c = 0;
00CD60A0  mov         byte ptr [c],0  
	char n = 0;
00CD60A4  mov         byte ptr [n],0  
	printf("%d \n%d", a, b);
00CD60A8  movsx       eax,byte ptr [b]  
00CD60AC  push        eax  
00CD60AD  movsx       ecx,byte ptr [a]  
00CD60B1  push        ecx  
00CD60B2  push        offset string "%d \n%d" (0CE1A08h)  
00CD60B7  call        _printf (0CC10E6h)  
00CD60BC  add         esp,0Ch  
	while (b != 0)
00CD60BF  movsx       eax,byte ptr [b]  
00CD60C3  test        eax,eax  
00CD60C5  je          main+8Ah (0CD60FAh)  
	{
		n = b & 1;
00CD60C7  movsx       eax,byte ptr [b]  
00CD60CB  and         eax,1  
00CD60CE  mov         byte ptr [n],al  
		b = b >> 1;
00CD60D1  movsx       eax,byte ptr [b]  
00CD60D5  sar         eax,1  
00CD60D7  mov         byte ptr [b],al  
		if (n)
00CD60DA  movsx       eax,byte ptr [n]  
00CD60DE  test        eax,eax  
00CD60E0  je          main+7Fh (0CD60EFh)  
		{
			c += a;
00CD60E2  movsx       eax,byte ptr [a]  
00CD60E6  movsx       ecx,byte ptr [c]  
00CD60EA  add         ecx,eax  
00CD60EC  mov         byte ptr [c],cl  
		}
		a = a << 1;
00CD60EF  movsx       eax,byte ptr [a]  
00CD60F3  shl         eax,1  
00CD60F5  mov         byte ptr [a],al  
	}
00CD60F8  jmp         main+4Fh (0CD60BFh)  
	printf("%d", c);
00CD60FA  movsx       eax,byte ptr [c]  
00CD60FE  push        eax  
00CD60FF  push        offset string "%d" (0CE1A10h)  
00CD6104  call        _printf (0CC10E6h)  
00CD6109  add         esp,8  
	return 0;
00CD610C  xor         eax,eax  
}
00CD610E  pop         edi  
00CD610F  pop         esi  
00CD6110  pop         ebx  
00CD6111  add         esp,0F0h  
00CD6117  cmp         ebp,esp  
00CD6119  call        __RTC_CheckEsp (0CC1811h)  
00CD611E  mov         esp,ebp  
00CD6120  pop         ebp  
00CD6121  ret  
