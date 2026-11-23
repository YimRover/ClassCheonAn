#include <stdio.h>
/*
*/
int main ()
{
    int i, j;
    // 2차원 배열의 값을 선언하면서 초기화
    int arr1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    // 2차원 배열에 값을 넣지 않는 곳은 0의 값이 입력 (쓰레기)
    int arr2[3][3] = {
        {1},
        {4,5},
        {7,8,9}
    };
    int arr3[3][3] = {1,2,3,4,5,6,7}; // 2차원 배열이 결국 1차원으로 값이 저장이 됨
    for (i=0; i < 3; ++i)
    {
        for (j =0; j<3; ++j)
        printf ("%d ", arr1[i][j]);
        printf ("\r\n");
    }
    printf ("\r\n");
    for (i =0; i < 3; ++i)
    {
        for (j =0; j <3; ++j)
        printf ("%d ", arr2[i][j]);
        printf ("\r\n");
    }
    printf ("\r\n");
    for (i =0; i < 3; ++i)
    {
        for (j =0; j <3; ++j)
        printf ("%d ", arr3[i][j]);
        printf ("\r\n");
    }
    return 0;
}