#include <stdio.h>
/*
작성자  :Rov
작성일  :261007
버전    :1.0.0.0
명시적 형 변환
*/
int main()
{
    int num1 = 3, num2 = 4;
    double divResult1 = 0.0; //0.0 유리수 표시를 같이 해주는게 좋다.
    double divResult2 ;
    divResult1 = (double)num1 / (double)num2;
    divResult2 = (double)num2 / (double)num1;
    printf ("나눗셈 결과: %lf\r\n", divResult1); //C에선 %lf가 longfloat으로 사용
    printf ("나눗셈 결과: %lf\r\n", divResult2);
    return 0;
}