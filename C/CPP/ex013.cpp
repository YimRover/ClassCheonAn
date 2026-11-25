#include <iostream>
/*
E.O.F (End Of File)
*/


int main ()
{
    char ch;
    int count =0;
    std::cin.get(ch); // 문자를 하나씩 읽어온다.
    while (std::cin.fail() == false) // EOF인지 검사
    {
        std::cout << ch << " "; // 읽어온 문자들을 출력
        ++count; // 문자마다 카운팅
        std::cin.get(ch); // 다시 문자를 읽어오겠다를 반복
    }
    std::cout << count << "문자를 읽었습니다. \n"; // 마지막에 여지껏 읽은 문자 갯수를 출력
    return 0;
}