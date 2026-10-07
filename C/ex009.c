#include <stdio.h>
/*
작성자  :Rov
작성일  :261007
버전    :1.0.0.0
비트연산자
*/
int main ()
{
    int value1 =4; //00000100
    int value2 =3; //00000011
    int result1 = value1>>1; //00000010
    int result2 = value2<<1; //00000110
    int result3 = value1>>3; //00000000
    int result4 = value2>>2; //00000000
    printf ("%d\n%d\n%d\n%d\r\n", result1,result2,result3,result4);
    return 0;
}