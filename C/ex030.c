#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0.
방정식 만들어보기
xy +yx = 99 일 때의 공 수 구하기
*/
int main ()
{
    int x, y;
    for (x=0; x<=9; ++x)
    {
        for (y=0; y<=9; ++y)
        {
            if ((10*x + y) + (10*y + x) == 99)
            {
                printf ("X : %d,Y : %d\r\n", x,y);
            } 
        }
    }
    return 0;
}