#include <stdio.h>
/*

*/
int main ()
{
    sizeof (int);
    sizeof (double);
    sizeof (char);
    int value1 = 100;
    printf ("%d\r\n", value1); // 초기 value1에 대한 값을 출력
    int * ptr1 = &value1; // 포인터 주소 값 설정
    * ptr1 = 1000; // 포인터를 이용한 주소에 대한 값을 역참조를 통한 간접 변경
    printf ("%d\r\n", value1); // 포인터에 의해 바뀐 value1에 대한 값을 출력
    printf ("%ld\r\n", sizeof ptr1 );
    double * ptr2 = NULL;
    double value2 = 1000.0;
    ptr2 = &value2;
    printf ("%lf\r\n", ptr2);
    * ptr2 = 100.0;
    printf ("%lf\r\n", value2);
    printf ("%ld\r\n", sizeof ptr2 );
    char * ptr3 = NULL;
    printf ("%ld\r\n", sizeof ptr3 );
    
    ptr1 = NULL; // 포인터 방어 코드
    ptr2 = NULL;
    ptr3 = NULL;
    return 0;
}