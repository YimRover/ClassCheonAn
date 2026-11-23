#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
로또 번호 생성기
1~45까지의 숫자 6개 랜덤으로 추첨 / 숫자가 겹쳐서는 안됨

*/
int lottonum(void)
{
    int num;
    num = rand() %45+1;
    return num;
}
int main()
{
    int lotto[6];
    int i, j, k;
    int duplicate ;
    int num ;
    srand ((unsigned int) time (NULL));
    for (k =0; k<6; ++k)

    {
        for (i = 0; i <=5; ++i)
        {
            num = lottonum();
            duplicate = 0;

            for (j = 0; j<i; ++j)
            {
                if (lotto[j] == num)
                {
                    duplicate = 1;
                    break;
                }
            
            }
            if (duplicate != 0 )
                {
                    --i;
                    continue;
                }
                lotto[i] = num;
        }
        for (i = 0; i < 6; ++i)
        {
            printf ("%d \t", lotto[i]);
        }
        printf ("\r\n");
}
    return 0;
}