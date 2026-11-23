#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.22
버전    :1.0.0.0
*/
void recusive (int num1)
{
    if (num1 <=0) return;
    printf ("%s \r\n","Function Call.");
    recusive (num1 - 1);
}
int mine ()
{
    recusive(3);
    return 0;
}