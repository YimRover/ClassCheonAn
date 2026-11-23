#include <stdio.h>
/*
작성자  :Rov
작성일  :261011
버전    :1.0.0.0
마름모 * 만들기
*/
int main ()
{
    for (int i = 1; i < 6; ++i) // 1~5행에 대한 정의
    {
        for (int j = 1; j <= i - 1; ++j) //
        {
            printf (" ");
        }
        for (int j = 1; j <= 6 - i; ++j)
        {
            printf ("*");
        }
        printf ("\r\n");
    }
    return 0;
}