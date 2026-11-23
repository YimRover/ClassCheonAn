#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.22
버전    :1.0.0.0
*/
int main ()
{
    char str [] = "GOOD Morning!";
    printf ("배열 str의 크기 : %d\r\n", sizeof(str));
    printf ("널 문자 문자형 출력 : %c \r\n", str[13]);
    printf ("널 문자 정수형 출력 : %d \r\n", str[13]);

    str[12]= '?'; // 배열 str에 저장된 문자열 데이터 변경 가능
    printf ("문자열 출력 : %s \r\n", str);
    
    return 0;
}