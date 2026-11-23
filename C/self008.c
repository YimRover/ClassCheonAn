#include <stdio.h>
/*
작성자  :Rov
작성일  :261007
버전    :1.0.0.0
도전 문제
*/
int main ()
{
    int weight = 0;
    double height = 0.0;
    printf ("%s\r\n", "weight, height");
    scanf (" %d %lf", &weight, &height);
    double BMI = (double)(((weight/height)*(weight/height))*100);
    ((int)20.0 <= (int)BMI && (int)BMI < (int)25.0) && printf ("표준\r\n");
    ((int)20.0 > (int)BMI) && printf ("저체중\r\n");
    ((int)25.0 < (int)BMI) && printf ("과체중\r\n");
    printf ("%d\r\n",(int)BMI);
    return 0;
}