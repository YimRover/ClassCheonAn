#include <stdio.h>
/*
*/
int first = 10;
int second = 20;
void swap ()
{
    int c = 0;
    c = first;
    first = second;
    second = c;
    printf ("%d\t%d\r\n", first, second);
}

int main ()
{
    swap ();
    printf ("%d\t%d\r\n",first,second);
    return 0;
}