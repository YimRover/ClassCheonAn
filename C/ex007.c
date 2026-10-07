#include <stdio.h>
/*
만든이  :Rov
작성일  :261006
버전    :1.0.0.0
scanf_s();//scanf();
*/
int main()
{
    int input_number1=0;
    int input_number2=0;
    printf ("%s\r\n","첫번째 숫자");
    scanf("%d", &input_number1);
    printf ("%s\r\n","두번째 숫자");
    scanf("%d", &input_number2);
    printf ("%s\r\n","---------------------");
    printf("입력한 숫자합은 :%d\r\n", input_number1+input_number2);
    printf("입력한 숫자차이는 :%d\r\n", input_number1-input_number2);
    printf("입력한 숫자곱은 :%d\r\n", input_number1*input_number2);
    printf("입력한 숫자나눔은 :%d\r\n", input_number1/input_number2);
    return 0; //EXit_SUCCESSss
}