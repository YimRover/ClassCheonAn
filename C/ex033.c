#include <stdio.h>
/*

*/
int main ()
{
    int num1 = 100, num2 = 100;
    int * ptr = NULL;
    printf ("num1:%d\tnum2:%d\r\n",num1,num2);
    ptr = &num1;
    (*ptr) += 30 ;
    printf ("%d\r\n", num1);
    ptr = &num2;
    (*ptr) -= 30;
    printf ("%d\r\n", num2);
    printf ("num1:%d\tnum2:%d\r\n",num1,num2);
    printf ("num2의 주소 : %p\r\n", &num2);
    ptr = NULL;
    printf ("ptr의 주소 : %p\r\n", ptr);
    printf("\r\n");

    int arr[3] = {0,1,2};
    printf ("배열의 이름 주소 : %p\r\n", arr);
    printf ("첫번째 요소 주소 : %p\r\n", &arr[0]);
    printf ("두번째 요소 주소 : %p\r\n", &arr[1]);
    printf ("세번째 요소 주소 : %p\r\n", &arr[2]);
    printf ("\r\n");

    int arr2[3] = {0,1,2};
    printf ("배열의 이름 주소 : %p\r\n", arr2);
    printf ("첫번째 요소 주소 : %p\r\n", &arr2[0]);
    printf ("두번째 요소 주소 : %p\r\n", &arr2[1]);
    printf ("세번째 요소 주소 : %p\r\n", &arr2[2]);
    
    return 0;
}