#include <stdio.h>
/*
*/
int main()
{
    int num1 = 12;
    int num2 = 12;
    int num3 = 12;
    printf ("num1: %d\r\n",num1);
    printf ("num1++: %d\r\n",num1++);//후위 증가
    printf ("num1: %d\r\n",num1);
    printf ("num2: %d\r\n",num2);
    printf ("++num2: %d\r\n",++num2);//전위 증가
    printf ("num3: %d\r\n",num3);
    printf ("++num3: %d\r\n",++num3);
    printf ("++num3과num3++를 같이 사용하면:%d,%d\r\n",++num3,num3++);
    printf ("num3: %d\r\n",num3);
    return 0;
}