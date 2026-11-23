#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
1-9단 표기
*/
int main()
{   
    printf ("%s\r\n", "구구단을 외워봅시다."); // 제일 먼저 표기
    int dan1 = 0; //계산을 위한 변수 설정
    int dan2 = 0; //단수 표기를 위한 변수 설정
    while (dan1, dan2 < 10) // 반복문의 설정
    {
        int dan3 = 1; // 반복문의 반복문의 설정
        while (dan3 < 10)// 반복문에서 탈출을 위한 초기 설정값
        {
            printf ("%dx%d=%d\t", dan1, dan3, dan3*dan1); // 단수 계산 및 표기
            ++dan3; // 탈출문 설정
        }
        printf ("%s %d%s\r\n","--",dan2,"단"); // 단수 표기
        ++dan1, ++dan2; // 탈출문 설정
    }
    return 0;
}