#include <stdio.h>
/*
*/
int add (int first, int second)
{
    return first + second;
}
int add2(int (*func)(int, int))
{
    return func(10,20);
}

int main ()
{
    int (* f_aptr)(int, int) = NULL;
    f_aptr = add;
    int result = f_aptr(10,20);
    printf ("%d \r\n", result);
    result = add2(add);
    printf ("%d \r\n", result);
    return 0;
};