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
    const char * str = "ABCDEFG\0"; // \이 들어가야 그 뒤를 안 읽음
    printf ("아스키문자변화 숫자 : %d\r\n", ch1);
    printf ("아스키문자변화 문자 : %c\r\n", ch1);
    printf ("아스키문자변화 숫자 : %d\r\n", ch2);
    printf ("아스키문자변화 문자 : %c\r\n", ch2);
    printf ("%s\r\n", str);
    return 0;
}