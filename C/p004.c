#include <stdio.h>
/*
길이가 10인 배열에 10개의 정수를 입력 받는데, 홀수면 배열의 앞에서부터 짝수면 뒤에서부터 채워나가자.
*/
int main ()
{
    int num1[10] = {0, };
    int num2[10] = {0, };
    int i, j ;
    for (i =0; i < 10; ++i)
    {
        scanf ("%d", &num1[i]);

    }
    if (num1[i] / 2 == 0)
    {
        for (int i = 10; i > 0; --i)
        {
           num1[i] = num2[i];
        }
    }
    else
    {
        for (int i = 0; i < 10; ++i);
        {
            num1[i] = num2[i];
        } 
    }
    for (i = 0; i < 10; ++i)
    {
        printf ("%d \t", num2[i]);
    }
    printf ("\r\n");
    printf ("\r\n");
    return 0;
}