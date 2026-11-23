#include <stdio.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0.
*/
int main()
{
    int op;
    double num1, num2;
    double result;

    printf ("연산을 선택하세요.\r\n 1.덧셈 2.뺄셈 3.곱셈 4.나눗셈\r\n");
    scanf ("%d", &op);
     
    if (op == 1)
    {
        printf ("연산할 두 수를 입력 : ");
        scanf ("%lf %lf", &num1,&num2);
        result = num1 + num2;
        printf ("연산결과 : %lf + %lf = %f\r\n", num1, num2, result);
    }
    else if (op == 2)
    {
        printf ("연산할 두 수를 입력 : ");
        scanf ("%lf %lf", &num1,&num2);
        result = num1 - num2;
        printf ("연산결과 : %lf - %lf = %f\r\n", num1, num2, result);
    }
    else if (op == 3)
    {
        printf ("연산할 두 수를 입력 : ");
        scanf ("%lf %lf", &num1,&num2);
        result = num1 * num2;
        printf ("연산결과 : %lf * %lf = %f\r\n", num1, num2, result);
    }
    else if (op == 4)
    {
        printf ("연산할 두 수를 입력 : ");
        scanf ("%lf %lf", &num1,&num2);
        result = num1 / num2;
        printf ("연산결과 : %lf / %lf = %f\r\n", num1, num2, result);
    }
    else
    {
        printf ("연산을 선택하지 않았습니다.\r\n");
    }
    return 0;
}