#include <stdio.h>
/*
작업자  :Rov
작업일  :261006
버전    :1.0.0.0
0+0 = 0, 0-0=0, 0x0=0, 0/0=0, 0%0=0
*/
int main ()
{
    int num1 =0;
    int num2 =0;
    printf ("첫번째 숫자입력: \r\n");
    scanf ("%d", &num1);
    printf ("두번째 숫자입력: \r\n");
    scanf ("%d", &num2);

    printf ("%d+%d=%d\r\n",num1,num2,num1+num2);
    printf ("%d-%d=%d\r\n",num1,num2,num1-num2);
    printf ("%dx%d=%d\r\n",num1,num2,num1*num2);
    printf ("%d/%d=%d\r\n",num1,num2,num1/num2);
    printf ("%d%%%d=%d\r\n",num1,num2,num1%num2);
    return 0;
}