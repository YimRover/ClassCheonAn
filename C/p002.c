#include <stdio.h>
/*
0-9까지의 정수를 홀수와 짝수로 분류
*/
void checknum1(int num)
{
    if (num %2 == 0)
    {
        printf ("%d ", num);
    }
}
void checknum2(int num)
{
    if (num %2 != 0)
    {
        printf ("%d ", num);
    }
}



int main ()
{
    int i;
    int num1[10] = {1,2,3,4,5,6,7,8,9,0};
    printf ("10개의 숫자는 : " );
    for (i =0; i < 10; ++i)
    {
        printf ("%d ", num1[i]);
    }
    printf ("\r\n");
    printf ("짝수는 : \r\n");
    for (i =0; i <10; ++i)
    {
        checknum1 (num1[i]);
    }
    printf ("\r\n");
    printf ("홀수는 : \r\n");
    for (i =0; i <10; ++i)
    {
        checknum2 (num1[i]);
    }
    
    printf ("\r\n");
    return 0;
}