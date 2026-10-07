#include <stdio.h>
/*
작업자  : Rov
작업일  :261006
버전    :1.0.0.0
8진수와 16진수를 이용한 데이터 표현
*/
int main()
{
    int num1 = 0xA7, num2= 0x43;//10x16+7,16x4+3 0x시작은 16진수를 의미
    int num3 = 032, num4= 024;//3x8+2,2x8+4 0시작은 8진수를 의미

    printf ("0xA7의 10진수 정수 값: %d\r\n", num1);//16진수의 숫자를 10진수로 바꿔주는 명령어%d
    printf ("0x43의 10진수 정수 값: %d\r\n", num2);
    printf ("032의 10진수 정수 값: %d\r\n", num3);//8진수의 숫자를 10진수로 바꿔주는 명령어%d
    printf ("024의 10진수 정수 값: %d\r\n", num4);

    printf ("%d-%d=%d\r\n",num1,num2,num1-num2);
    printf ("%dx%d=%d\r\n",num3,num4,num3*num4);
    return 0;
}