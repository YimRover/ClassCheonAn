#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.22
버전    :1.0.0.0
*/
void simpleFunc()
{
    static int num1 = 0;
    int num2 = 0;
    ++num1;
    num2++;
    printf ("%d\t%d\r\n",num1,num2);
}

int main ()
{
    simpleFunc();
    simpleFunc();
    simpleFunc();
    return 0;
}