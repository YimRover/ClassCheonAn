#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
0-100 이하 짝수 총합을 구하는 코드를 작성해보세요.
*/
int main ()
{
    int total = 0;
    int num = 0;
    do
    {
        total += num;
        num = num+2;

    } while (num <= 100);
    printf ("%s %d\n", "0-100까지 총 합은:",total);
    return 0;
}