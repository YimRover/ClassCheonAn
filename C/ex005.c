#include <stdio.h>
/*
만든이  : Rov
작성일  : 261006
버 전   : 1.0.0.0
복합대입연산자
*/
int main()
{
    int num1=2, num2=4, num3=6;
    double num4=8;
    num1 += 3; // num1 = num1+3 업데이트 개념
    num2 *=4; // num2 = num2*4
    num3 %=5; // num3 = num3%5
    num4 /=6; // num4 = num4/6
    printf ("result : %d,%d,%d,%f\r\n",num1,num2,num3,num4);
    printf ("%d+%d=%d\r\n",num1,num2,num1+num2);
    num1 -= 1; // num1 = num1 -1 다시 업데이트 진행
    printf ("result : %d\r\n",num1);
    return 0;
}