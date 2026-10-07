#include <stdio.h>
/*
만든이  : Rov
작성일  : 261006
버 전   : 1.0.0.0
scanf_s(); // scanf() 서식쓰기;
*/
int main()
{
    unsigned int number1 = 0u;//양수만 받겠습니다.
    int number2 = 0;
    int number3 = 0;
    printf ("%s","정수 세 개를 입력: ");
    scanf ("%d,%d,%d",&number1,&number2,&number3); // 서식을 정함 (,)
    printf ("%d:%d:%d\r\n", number1,number2,number3); //scanf입력한 정수 세개를 출력함
    return 0;
}