#include <stdio.h>
/*
작성자  :Rov
작성일  :261007
버전    :1.0.0.0

*/
int main ()
{
    char ch1 = 'A';
    char ch2 = 65;
    const char * str = "ABCD\0EFG"; // \0이 들어가면 출력이 끊기는 현상 발생
    printf ("아스키문자변화 숫자 : %d\r\n", ch1);
    printf ("아스키문자변화 문자 : %c\r\n", ch1);
    printf ("아스키문자변화 숫자 : %d\r\n", ch2);
    printf ("아스키문자변화 문자 : %c\r\n", ch2);
    printf ("%s\r\n", str);
    return 0;
}