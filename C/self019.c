#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.22
버전    :1.0.0.0
*/
int main ()
{
    int arr[5]; //int 형태의 배열 arr을 5개 만드는 것을 선언
    int sum=0, i;
    
    arr[0] = 10, arr[1] = 20, arr[2] = 30, arr[3] = 40, arr[4] = 50;
    // arr[0]은 arr배열의 처음 시작되는 본인위치를 의미

    for (i=0; i<5; ++i)
    sum += arr[i];

    printf ("배열요소에 저장된 값의 합 : %d\r\n", sum);
    printf ("arr첫번째 값: %d \r\n", arr[0]);
    printf ("arr 배열의 전체 값 : %d \r\rn", arr);
    return 0;
}