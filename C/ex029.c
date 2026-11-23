#include <stdio.h>
#include <termios.h>
#include <unistd.h>
/*
작성자  :Rov
작성일  :26.10.21
버전    :1.0.0.0.
방향키 반복문
*/
int getch (void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main ()
{
    while (true)
    {
        int c = getch() ;
        switch (c)
        {
            case 'a' :
            case 'A' :
            printf ("a는 왼쪽\r\n");
            break;
            case 's' :
            case 'S' :
            printf ("s는 아래\r\n");
            break;
            case 'd' :
            case 'D' :
            printf ("d는 오른쪽\r\n");
            break;
            case 'w' :
            case 'W' :
            printf ("w는 위\r\n");
            break;
            default :
            printf ("방향키가 아닌키를 입력했습니다.\r\n");
            goto END;
        }
    }
    END : 
    return 0;
}