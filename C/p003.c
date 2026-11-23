#include <stdio.h>
/*
10진수 정수를 2진수로 변환하기
*/
int change (int num)
{
    int binary[10];
    int i = 0;
    if (num == 0)
    {
        printf ("0000");
    }
    while (num > 0)
    {
        binary[i] = num%2;
        num = num/2;
        ++i;
    }
    while (i > 0)
    {
        --i;
        printf ("%d", binary[i]);
    }
    
    printf ("\r\n");
}

int main ()
{
    int number;
    scanf("%d", &number);
    change (number);
    return 0;
}