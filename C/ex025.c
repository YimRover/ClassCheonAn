#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0.
삼항 연산자
양수 입력시 짝수만 출력 
음수 입력시 절대값 출력
*/
int main()
{
    int num, abs;
    printf ("수 입력 :");
    scanf ("%d", num);
    
    int abs = num>0 ? num%2 ;
    printf ("%d\r\n", abs);
    return 0;
}