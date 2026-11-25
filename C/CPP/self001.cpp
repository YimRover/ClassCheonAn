#include <iostream>
#include <string>

int main ()
{
    const int ArSize = 20;
    char name [ArSize];
    char dessert [ArSize];

    std::cout << "이름을 입력하십시오 : " << "\n";
    std::cin.getline(name, 20); // cin.getline 은 여기까지의 enter까지 입력을 받음
    std::cout << "좋아하는 디저트를 입력하십시오 : " << "\n";
    std::cin.getline(dessert, 20);
    std::cout << "맛있는 " << dessert;
    std::cout << "디저트를 준비하겠습니다. " << name << "님! \n";

    return 0;
}