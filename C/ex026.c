#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0.
방정식 만들어보기
개와 닭은 18마리 / 둘의 다리수 합은 52개 일 때 개와 닭의 마리수를 구하라
*/
int main ()
{
    int x, y ;
    for (x = 1; x <= 17; ++x)
    {
        for  (y = 1; y <=17; ++y)
        {
            if ( x+y == 18 )
            {
                if (4*x + 2*y == 52)
                {
                    printf ("%s %d %s %d\r\n","개는 : ", x, "닭은 :", y );  
                    break;
                }
            }
은
        }
    }
    for (x = 1; x<=17; ++x)
    {
        for (y=1; y<=17; ++y)
        {
            if(x+y == 18 && 4*x+2*y ==52)
            {
                printf ("개는? %d 닭은? %d\r\n", x,y);
            }
        }
    }
    
    return 0;
}
