#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0.
홀수만 보여주는 코드
*/
int main ()
{
    int num = 0;
    printf ("1~100홀수 보여주기 시작\r\n");
    
    for (num = 1; num <100; ++num )
    {
        if (num%2 == 0 )
        continue;
        printf ("%d \t",num);
    }
    printf ("끝\r\n");
    return 0;
}