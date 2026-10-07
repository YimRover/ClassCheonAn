#include <stdio.h>
/*
만든이  :Rov
작성일  :261006
버 전   :1.0.0.0
관계 연산자
*/
int main()
{
    int num1 = 10;
    int num2 = 12;
    int result1=(num1==num2), result2=(num1<=num2), result3=(num1>num2);
    printf ("result1:%d\r\n", result1);
    printf ("result2:%d\r\n", result2);
    printf ("result3:%d\r\n", result3);
    return 0;
}