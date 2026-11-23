#include <stdio.h>
/*

*/
void swap(int * first, int * second)
{
    int temp = 0;
    temp = * first;
    * first = * second;
    * second = temp;
    printf ("%p\t%p\r\n",first,second);
}

int main ()
{
    int value1 = 100, value2 = 900;
    printf ("%d\t%d\r\n",value1,value2);
    printf ("%p\t%p\r\n",&value1,&value2);
    swap (&value1,&value2); //call by pointer
    printf ("%d\t%d\r\n",value1,value2);
    return 0;
}