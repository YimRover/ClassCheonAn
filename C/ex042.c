#include <stdio.h>
#include <stdlib.h> // malloc(),free() 를 쓸 수 있게 하는 헤더
/*
*/
int main ()
{
    int* ptr_heap = (int*)malloc(5 * sizeof(int));
    double* ptr_heap1 = (double*)malloc(sizeof(double));
    int i, sum;
    * ptr_heap1 = 0;
    * ptr_heap = 0;
    if (ptr_heap ==NULL)
    {
        printf ("%s\r\n", "메모리가 없습니다.");
        return 1;
    }
    printf ("다섯 명의 나이를 입력하세요. : ");
    for (int i=0; i< 5; ++i)
    {
        scanf (" %d", &ptr_heap[i]);
        sum += ptr_heap[i];
    }
    printf ("다섯 명의 평균 나이 : %.1lf\r\n", (sum / 5.0));

    free(ptr_heap);
    free(ptr_heap1);
    ptr_heap = NULL;
    ptr_heap1 = NULL;
    return 0;
}