#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
for구문의 이해 : 구구단 만들기
*/
int main()
{
    for (int dan = 2; dan < 10; ++dan)
    {
        for (int num =1; num <10; ++num)
        {
            printf ("%dx%d=%d \t", dan, num, dan*num);
        }
        printf ("%s%d \r\n", "현재 단수", dan);
    }
    return 0;
}