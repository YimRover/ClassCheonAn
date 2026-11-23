#include <stdio.h>
/*

*/
int main ()
{
    int arr[3] = {15,25,35};
    int * ptrArr= &arr[0];
    
    printf ("%d\r\n", ptrArr[0]);
    printf ("%d\r\n", ptrArr[1]);
    printf ("%d\r\n", ptrArr[2]);
    printf ("\r\n");
    printf ("%d\r\n", *(ptrArr + 0));
    printf ("%d\r\n", *(ptrArr + 1));
    printf ("%d\r\n", *(ptrArr + 2));
    return 0;
}