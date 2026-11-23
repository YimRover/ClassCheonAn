#include <stdio.h>
/*
작성자  :Rov
작성일  :261007
버전    :1.0.0.0
2번째 문제
*/
int main()
{
    int hour, min, sec ;
    const double time = 3.76 ; //변하지 않을 거니깐 const 사용으로 고정
    hour = (int)time ; //총 시간 값에서 시간에 해당하는 값을 정수화를 통해 빼내기
    min = (int)((time - hour) *60); //총 시간 값에서 정수화시간값을 빼고 x60한 후 정수화
    sec = (int)((time *60*60)-(hour*60*60)-(min*60)); // 시간 = 3600초를 치환해서 계산 후 빼서 계산하기
    printf ("3.76시간은 : %d %s %d %s %d %s\r\n", hour,"시간", min,"분", sec,"초 입니다.");
    return 0;
}