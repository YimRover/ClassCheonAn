#include <stdio.h>
/*
*/
int main ()
{
    // 가구별 거주 인원 입력
    int villa[4][2] = {
        {1,2},
        {4,2},
        {4,4},
        {5,1}
    }; 

    int popu, i, j;
    // 가구별 거주인원 출력
    for (i = 0; i < 4; ++i )
    {
        for (j = 0; j < 2; ++j)
        {
            printf ("%d층 %d호 인구수 :  %d\r\n", i+1, j+1, villa[i][j]);
        }
    }
    // 빌라 층별 인구수 출력하기
    for (i = 0; i < 4; ++i)
    {
        popu =0;
        popu += villa[i][0];
        popu += villa[i][1];
        printf ("%d층 인구수 : %d \r\n", i+1, popu);
    }
    return 0;
}