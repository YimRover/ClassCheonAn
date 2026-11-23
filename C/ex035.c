#include <stdio.h>
/*

*/
int main ()
{
    int num1=10, num2=20, num3=30;
    int * arr[3] = {&num1, &num2,&num3};

    printf ("%d \r\n", *arr[0]);
    printf ("%d \r\n", *arr[1]);
    printf ("%d \r\n", *arr[2]);
    printf ("\r\n");
    int num[3] = {10,20,30};
    int * arr1 = &num[0];
    
    printf ("%d \r\n", arr1[0]);
    printf ("%d \r\n", arr1[1]);
    printf ("%d \r\n", arr1[2]);
    return 0;
}