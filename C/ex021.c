#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
별 그리기 2번
*/
int main ()
{
    for (int num1 =1; num1 < 6; ++num1)
    {
        for (int num2 =1; num2 <= 5-num1; ++num2)
            {
            printf (" ");
            }
        for (int num2 =1; num2 <= num1; ++num2 )
            {
            printf ("*");
            }
            printf ("\r\n");
    }
    return 0;
}