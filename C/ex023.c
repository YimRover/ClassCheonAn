#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0.
IF 구문 활용
*/
int main()
{
    int num1 = 0;
    int num2 = 2;
    printf ("정수 입력 : ");
    scanf ("%d", &num1);
    if (num1 % num2 == 0) 
    {
        printf ("%s\r\n", "짝수");
    }
    if (num1 % num2 != 0)
    {
        printf ("%s\r\n", "홀수");
    }

    return 0;
}