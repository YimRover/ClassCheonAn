#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.22
버전    :1.0.0.0
*/
int main ()
{
    char str [100];
    int idx =0;
    
    printf ("문자열 입력 : ");
    scanf (" ", str);
    printf ("입력 받은 문자는 : %s \r\n", str);

    printf ("문자 단위 출력 : ");
    while (str [idx] != '\0')
    {
        printf ("%c", str[idx]);
        ++idx;
    }
    printf ("\r\n");
    return 0;
}