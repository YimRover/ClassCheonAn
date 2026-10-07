#include <stdio.h>
/*
만든이  : Rov
작성일  : 261006
버 전   :1.0.0.0
변수의 다양한 선언 및 초기화 방법
*/
int main()
{
    int num1, num2; //변수 num1, num2의 선언
    int num3=30, num4=40; //변수 num3,num4의 선언 및 초기화
    printf ("num1:%d,num2:%d\r\n",num1,num2);
    printf ("%s\r\n","----------");
    num1=10; //변수 num1의 초기화
    num2=20; //변수 num2의 초기화
    printf ("num1:%d,num2:%d \r\n",num1,num2);
    printf ("num3:%d,num4:%d \r\n",num3,num4);
    return 0;
}