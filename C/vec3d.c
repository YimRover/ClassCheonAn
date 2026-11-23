#include <stdio.h>
/*
*/
struct Box
{
    int xpos;
    int ypos;
    int zpos;
};
struct Box result (struct Box,struct Box,struct Box,char op);
//struct Box add (struct Box,struct Box,struct Box);
struct Box minus (struct Box _x1, struct Box _x2, struct Box _x3);
//struct Box multi (struct Box _x1, struct Box _x2, struct Box _x3);

int main ()
{
    struct Box x1 = {0,0,0};
    struct Box x2 = {0,0,0};
    struct Box x3 = {0,0,0};
    char op;
    scanf ("%d %d %d", &x1.xpos, &x1.ypos, &x1.zpos);
    scanf ("%d %d %d", &x2.xpos, &x2.ypos, &x2.zpos);
    scanf ("%d %d %d", &x3.xpos, &x3.ypos, &x3.zpos);
    printf ("원하는 연산을 입력하세요 : ");
    scanf (" %c", &op);

    struct Box result1 = result(x1,x2,x3,op);
   struct Box result2 = minus(x1,x2,x3);
   {
    /* data */
   };
   
    // printf ("더한 좌표값은 : (%d,%d,%d)\r\n", result1.xpos, result1.ypos, result1.zpos);
    printf ("뺀 좌표값은 : (%d,%d,%d)\r\n", result2.xpos, result2.ypos, result2.zpos);
    // printf ("곱한 좌표값은 : (%d,%d,%d)\r\n", result3.xpos, result3.ypos, result3.zpos);
    
    return 0;
}
struct Box result (struct Box _x1, struct Box _x2, struct Box _x3, char op)
{
    switch (op)
    {
    case '+' :
        int _xpos = _x1.xpos + _x2.xpos + _x3.xpos;
        int _ypos = _x1.ypos + _x2.ypos + _x3.ypos;
        int _zpos = _x1.zpos + _x2.zpos + _x3.zpos;
        struct Box temp = {_xpos, _ypos, _zpos};
        printf ("더한 좌표값은 : (%d,%d,%d)\r\n", temp.xpos,temp.ypos,temp.zpos);
        break;
    case '*' :
        int _xpos1 = _x1.xpos * _x2.xpos * _x3.xpos;
        int _ypos1 = _x1.ypos * _x2.ypos * _x3.ypos;
        int _zpos1 = _x1.zpos * _x2.zpos * _x3.zpos;
        struct Box temp1 = {_xpos, _ypos, _zpos};  
        printf ("곱한 좌표값은 : (%d,%d,%d)\r\n", temp1.xpos,temp1.ypos,temp1.zpos);
        break;
    case '-' :
        int _xpos2 = _x1.xpos - _x2.xpos - _x3.xpos;
        int _ypos2 = _x1.ypos - _x2.ypos - _x3.ypos;
        int _zpos2 = _x1.zpos - _x2.zpos - _x3.zpos;
        struct Box temp2 = {_xpos, _ypos, _zpos};
        printf ("뺀 좌표값은 : (%d,%d,%d)\r\n", temp2.xpos,temp2.ypos,temp2.zpos);
        break;
    }
}

// struct Box add (struct Box _x1, struct Box _x2, struct Box _x3)
// {
//     int _xpos = _x1.xpos + _x2.xpos + _x3.xpos;
//     int _ypos = _x1.ypos + _x2.ypos + _x3.ypos;
//     int _zpos = _x1.zpos + _x2.zpos + _x3.zpos;
//     struct Box temp = {_xpos, _ypos, _zpos};   
//     return temp;
// }
struct Box minus (struct Box _x1, struct Box _x2, struct Box _x3)
{
    int _xpos = _x1.xpos - _x2.xpos - _x3.xpos;
    int _ypos = _x1.ypos - _x2.ypos - _x3.ypos;
    int _zpos = _x1.zpos - _x2.zpos - _x3.zpos;
    struct Box temp = {_xpos, _ypos, _zpos};   
    return temp;
}
// struct Box multi (struct Box _x1, struct Box _x2, struct Box _x3)
// {
//     int _xpos = _x1.xpos * _x2.xpos * _x3.xpos;
//     int _ypos = _x1.ypos * _x2.ypos * _x3.ypos;
//     int _zpos = _x1.zpos * _x2.zpos * _x3.zpos;
//     struct Box temp = {_xpos, _ypos, _zpos};   
//     return temp;
// }
