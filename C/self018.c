#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.22
버전    :1.0.0.0
factorial
*/
int f(int n)
{
    if (n == 0) return 1;
    else return f(n-1)*n;
}
int main ()
{
    printf ("1! = %d \r\n", f(1));
    printf ("2! = %d \r\n", f(2));
    printf ("3! = %d \r\n", f(3));
    return 0;
}