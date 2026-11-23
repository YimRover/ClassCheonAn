#include <stdio.h>
/*
작성자  :Rov
작성일  :261007
버전    :1.0.0.0
1번 문제 풀기
*/
int main ()
{
    int num1 = 70, num2 = 65 ;
    double rate = (double)num2/num1;
    printf ("%20s %5d\r\n","seats : ", num1);
    printf ("%20s %5d\r\n", "audience : ", num2);
    printf ("%20s %5f\r\n", "rate : ", rate*100);
    return 0;
}