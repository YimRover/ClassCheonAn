#include <stdio.h>
/*
*/
struct Complex
{
    int real;
    int imaginary;
};
struct Complex add (struct  Complex, struct Complex);
int main ()
{
    struct Complex c1 = {0,0};
    struct Complex c2 = {0,0};
    scanf ("%d %d", &c1.real, &c1.imaginary);
    scanf ("%d %d", &c2.real, &c2.imaginary);
    struct Complex result = add(c1,c2);
    printf ("(%d,%d)", result.real, result.imaginary); // ("%d+%dj" 프린트하는데 같은값을 도출)
    return 0;
}
struct Complex add (struct  Complex _c1, struct Complex _c2)
{
    int _real = _c1.real + _c2.real;
    int _imaginary = _c1.imaginary + _c2.imaginary;
    struct Complex temp = {_real, _imaginary};
    return temp;
}