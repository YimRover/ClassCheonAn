#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
최종값이 홀수일 때 종료되는 계산기
*/
int main ()
{
    int total =1;
    int num =1;
    do
    {
        printf ("%s %d \t%s", "현재값 : ",total, "정수를 입력: ");
        scanf ("%d", &num);
        total += num;

    } while (total %2 ==0);
    printf ("%s \t%s %d\n","계산값이 홀수라 계산 종료","총 값은", total);
    return 0;
}