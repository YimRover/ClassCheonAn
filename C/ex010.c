#include <stdio.h>
//#define PI 3.141592
//#define SEMICOLON ;
/*

*/
int main()
{
    //const double PI = 3.141592 // 상수값을 지정할 때는 대문자로 표시
    // PI = 2.1724; 위에 const 때문에 PI값이 상수화가 되었기 때문에 안됨.
    char ch=9;
    int inum=1052;
    double dnum=3.1415;
    printf ("변수 ch의 크기: %ld\r\n", sizeof(ch));
    printf ("변수 inum의 크기: %ld\r\n", sizeof(inum));
    printf ("변수 dnum의 크기: %ld\r\n\n", sizeof(dnum));

    printf ("Char 의 크기: %ld\r\n", sizeof(char));
    printf ("int 의 크기: %ld\r\n", sizeof(int));
    printf ("double 의 크기: %ld\r\n", sizeof(double));
    return 0;
}