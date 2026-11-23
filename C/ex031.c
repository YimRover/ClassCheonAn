#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0
계산형 함수를 이용한 계산기 함수
*/
int value1 =0;
int value2 =0;
void add(int value1, int value2) // 소비형의 함수를 선언
{
    printf ("덧셈 결과는? :%d\r\n", value1 + value2);
    value1 = 0;
    value2 = 0;
}
void minus(int value1, int value2)
{
    printf ("뺄셈 결과는 ? : %d\r\n", value1-value2);
    value1 = 0;
    value2 = 0;
}
void multiply(int value1, int value2)
{
    printf ("곱셈 결과는 ? : %d\r\n", value1*value2);
    value1 = 0;
    value2 = 0;
}
void divide(int value1, int value2)
{
    if (value1 ==0 || value2 ==0)
    {
        printf ("0\r\n");
    }
    printf ("나눗셈 결과는 ? : %lf\r\n", (double)value1/value2);
    value1 = 0;
    value2 = 0;
}
int main ()
{
    int num;
    printf ("1.덧셈 2.뺄셈 3.곱셈 4.나눗셈\r\n");
    printf ("숫자를 눌러 선택해주세요.\r\n");
    scanf ("%d",&num);
    if (num ==1)
    {
        printf ("두 숫자를 입력하십시오\r\n");
        scanf ("%d %d", &value1, &value2);
        add(value1, value2);
    }
    else if (num ==2)
    {
        printf ("두 숫자를 입력하십시오\r\n");
        scanf ("%d %d", &value1, &value2);
        minus(value1, value2);
    }
    else if (num ==3)
    {
        printf ("두 숫자를 입력하십시오\r\n");
        scanf ("%d %d", &value1, &value2);
        multiply(value1, value2);
    }
    else if (num ==4)
    {
        printf ("두 숫자를 입력하십시오\r\n");
        scanf ("%d %d", &value1, &value2);
        divide(value1, value2);
    }
    else
    {
        printf ("연산을 선택하지 않으셨습니다.\r\n%s\r\n","계산기를 종료합니다.");
    }
    return 0;
}