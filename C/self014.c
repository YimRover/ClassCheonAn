#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0
204p 예제문 3번
2이상의 정수를 입력해 2부터 입력한 수까지의 모든 소수를 출력합니다.
단 한 줄에 5개씩 5칸 간격으로 출력합니다. 
*/
int num1 =0;
int primenum()
{
    (num1%2 !=0 && num1%3 !=0) ;
    num1 = 0;
}
int main ()
{
    printf ("2이상의 정수를 입력하세요. :");
    scanf ("%d", &num1);
    if (num1<2)
    {
        printf("2이상의 정수를 입력해주세요.\r\n");
    }
    else if (num1%2 !=0 && num1%3 !=0)
    {
        printf ("%d\t", primenum);
    }
    printf ("종료\r\n");
    return 0;
}