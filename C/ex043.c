#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*/
int main ()
{
    char temp[80] = {0,};
    char * str[3] = {NULL,};
    int i;
    for (int i =0; i < 3; ++i )
    {
        printf ("문자열을 입력하세요 : ");
        fgets(temp, sizeof temp, stdin); // gets만 쓰긴 위험하니, fgets로 변경해서 사용
        str[i] = (char*)malloc (strlen(temp)+1); // 워드의 경우 NULL 포함한 영역할당이 필수 
        strcpy(str[i], temp);
    }
    for (int i=0; i<3; ++i)
    {
        printf ("%s \r\n", str[i]);
    }
    for (int i =0; i < 3; ++i)
    {
        free (str[i]);
    }
    return 0;
}