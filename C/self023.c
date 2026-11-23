#include <stdio.h>
/*
Hello World 를 거꾸로 출력해보기
추가로 입력되는 단어의 앞뒤를 체크 및 검사하기
*/
bool is_palindrom (const char check1[], int check1_len)
{
    for (int i = 0; i < check1_len / 2; ++i)
    {
        if (check1[i] != check1[check1_len-1-i])return false;
        else return true;
    }
}

int main ()
{
    char str [13] = "Hello World";
    int x ;
    printf ("%s\r\n", str);
    for (x = 13; x >=0; --x)
    {
        printf ("%c", str[x]);
    }
    printf ("\r\n");
    char check [50];
    int y ;
    int palindrome = 1;
    int len ;
    printf ("문자열 입력 : ");
    scanf ("%c", check);
    printf ("입력 받은 문자는 : %c \r\n", check[50]);
    while (check[len] != '\0')
    {
        len++;
    }
    for (y = 0; y <=len; ++y )
    {
        if (check[y] != check[len- 1 -y])
        {
            palindrome = 0;
            break;
        }

    }
    if (palindrome == 1)
    {
        printf ("이 문장은 회문입니다.");
    }
    else
    {
        printf ("이 문장은 회문이 아닙니다.");
    }
    printf ("\r\n");
    char strs[BUFSIZ] = {0,};
    printf ("%s", "문자열 입력 : ");
    scanf ("%[^\n]%*c",strs);
    int strs_len = 0;
    for (int z = 0; z <= BUFSIZ; ++z )
    {
        if (strs[z] == '\0')break;
        ++strs_len;
    }
    printf ("%s : %d \r\n", "문자열의 갯수는 ", strs_len);
    printf ("%s\r\n", is_palindrom(strs, strs_len) ? "회문입니다." : "회문이 아닙니다.");
    return 0;
}