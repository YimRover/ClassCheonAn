#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
별그리기 마름모 형태 만들기
*/기
int main()
{
    for (int num1 =1; num1 < 7; ++num1)
    {
        for (int num2 = 0 ; num2 < num1; ++num2)
            {
                printf (" ");
                printf ("*");
            }
        printf ("\r\n");
    }
    for (int num3 =1; num3 < 7; ++num3)
    {
        for (int num4 = 7 ; num4 > num3; --num4)
            {
                printf (" ");
                printf ("*");
            }
        printf ("\r\n");
    }
    for (int num5 = 1; num5 < 7; --num5)
        {
            for (int num6 = 1; )
            {
                printf (" ");
                printf ("*");
            }
        }
            printf ("\r\n");
    {
        for (int num6 = 1; num6 <7; ++num6)
        {
            printf (" ");
            printf ("*");
        }
        printf ("\r\n");
    }
    return 0;
}