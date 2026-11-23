#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
구구단 만들어보기
*/
int main()
{
    int num = 0;
    int dan = 0;
    printf ("몇 단을 계산할까요?\n");
    scanf ("%d", &dan);

    while (num <= 10)
    {
        printf ("%dx%d=%d\r\n", dan, num, num*dan);
        ++num ;
    }
    return 0;
}