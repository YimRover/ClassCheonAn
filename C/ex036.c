#include <stdio.h>
/*

*/
void simpleFunc (const int _array[])
{
    printf ("%d %d %d\r\n", _array[0],_array[1],_array[2]);
}
int main ()
{
    int array[3] = {10, 20, 30};
    simpleFunc(array);
    return 0;
}