#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0.
1~100까지 3과 4의 공배수
*/
int main ()
{
    int num1 = 0;
    printf ("1~100까지의 3,4의 공배수는? ");
    for (num1 = 1; num1 <= 100; ++num1)
    {
        if (num1%3 == 0 && num1%4 == 0)
        printf ("%d \t", num1);
    }
    printf ("끝 \r\n");

    int num2 = 0;
    printf ("1~100까지의 3,4의 공배수는? ");
    for (num2 =1; num2 <=100; ++num2)
    {
        if (num2%3 != 0 || num2%4 !=0) continue;
        printf ("%d \t", num2);
    }
    printf ("끝\r\n");

    return 0;
}