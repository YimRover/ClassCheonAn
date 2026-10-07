#include <stdio.h>
/*
작업자  :Rov
작업일  :261006
버전    :1.0.0.0
복합계산기 만들어보기
*/
int main()
{
    int num1 =0;
    int num2 =0;
    char op;
    printf ("첫번째 숫자를 입력하세요.");
    scanf ("%d",&num1);
    printf ("연산자를 입력하세요.");
    scanf (" %c",&op);
    printf ("두번째 숫자를 입력하세요.");
    scanf ("%d",&num2);
    printf ("%d%c%d\r\n",num1,op,num2);
    switch (op)
    {
        case '+':
            printf ("%d+%d=%d\n",num1,num2,num1+num2);break;
        case '-':
            printf ("%d-%d=%d\n",num1,num2,num1-num2);break;
        case '*':
            printf ("%d*%d=%d\n",num1,num2,num1*num2);break;
        case '/':
            printf ("%d/%d=%d\n",num1,num2,num1/num2);break;
        case '%':
            printf ("%d%%%d=%d\n",num1,num2,num1%num2);break;
    }

    return 0;
}