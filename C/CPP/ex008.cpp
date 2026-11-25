#include <iostream>

int main()
{
    int * ptr = { nullptr };//raw pointer /  nullptr = NULL C++에서 포인터를 쓸 때 비워두는 것, NULL은 C에서 사용
    int value {10};
    ptr = &value;
    std::cout << *ptr << "\n"; // 역참조를 통해 value의 값을 출력
    ptr = nullptr; // 다사용한 포인터의 초기화
    return 0;
}