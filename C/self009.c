#include <stdio.h>
/*
작성자  :Rov
작성일  :261008
버전    :1.0.0.0
do~while문 연습 / 숫자 덧셈 총합 계산기 만들기
*/
int main ()
{
    int total = 0;
    int num = 0;
    do // do~while문 시작을 위한 do
    { // {}안에 내용을 반복할 것
        printf ("정수 입력 (0 to out) : ");
        scanf ("%d", &num); // 숫자입력을 위한 scanf
        total += num ; //total에 입력한 숫자를 저장
    } while (num != 0); //0을 입력시 반복문 종료
    printf ("총 더해진 값은 : %d\r\n", total);
    return 0;
}