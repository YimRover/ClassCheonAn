#include <iostream>

int main()
{
    int myfravoritenum = 0;
    std::cout << "내가 좋아하는 숫자는 뭐일까? *hint : 1-9사이 \n"; // do / while 구문 사용 do 에 해당하는 것은 1번 발동, while에서 참이 아닌 조건일 경우 계속해서 발동
    do {
        std::cout << "숫자 입력 : ";
        std::cin >> myfravoritenum;
    }
    while (myfravoritenum != 7 );
    std::cout << "내가 좋아하는 숫자는 7이었어.\n";
    return 0;
}