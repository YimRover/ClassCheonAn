#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0
204p 예제문 2번
*/
int main ()
{
    int i,j;
    for (i =0; i <=4; ++i)
    {
        for (j=0; j<=4; ++j)
        {
            printf (" ");
            if (i+j==4 || i==j)
            {
                printf ("*");
            }
        }
        printf ("\r\n");
    }
    return 0;
}