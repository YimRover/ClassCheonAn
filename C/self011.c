#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
짝수만 더할 수 있는 계산기
*/
int main ()
{
    int num1 = 0;
    int total = 0;
    do
    {
        printf ("%s %d\t %s","현재값은 : ",total,  "홀수입력 : ");
        scanf ("%d", &num1);
        (num1 %2 != 0)&&(total += num1);

    } while (num1 %2 != 0);
    printf ("%s \t %s : %d\r\n", "짝수를 입력하여 계산 종료 ","총 값은", total);
    return 0;
}