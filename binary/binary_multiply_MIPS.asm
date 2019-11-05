# #include<stdio.h>

# int main()
# {
# 	char a = 10, b = 10; // a*b =c
# 	char c = 0;
# 	char n = 0;
# 	printf("%d \n%d\n", a, b);
# 	while (b != 0)
# 	{
# 		n = b & 1;
# 		b = b >> 1;
# 		if (n)
# 		{
# 			c += a;
# 		}
# 		a = a << 1;
# 	}
# 	printf("%d", c);
# 	return 0;
# }

#MIPS
.text # 프로그램시작
.align 2 # 1word를 2bytes로 셋팅
.globl main # main함수 선언
main:
    li		$t0,  	10	# a $t0  = 10
    li		$t1, 	10	# b $t1 = 10
    li		$t2,    0	# c $t2 =  0
    # 	printf("%d \n%d\n", a, b);
Loop:
    # 		n = b & 1;
    and     $t4, $1 ,1  # n = b & 1;
    #       b = b >> 1;
    srl     $t1, $t1, 1 
    # 		if (n)
    bne     $t4 ,0, Else
    # 			c += a;
    add		$t2, $t2, $t0		# $t2 = $t2 + t0
    # 		}
Else:
    # 		a = a << 1;
    sll     $t0, $t0, 1
    bne		$t1, 0, Loop	# if $t0 != $t1  then Exit
    # 	printf("%d", c);

    # 	return 0;
    # }
