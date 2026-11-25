#include <iostream>
int main ()
{
    int number {int(0)}; // single object
    number = 10;
    std::cout << number << "\n";

    const int code = 66; //
    constexpr int code1 = 66; // const 보다 좀 더 좁은 개념 컴파일 시 작동 C++ 17부터 지원
    char c1 = {25}; // char c1{25} 랑 같은 말
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    float tree = 3.0f;
    int guess = 3.9832;
    int debt = 7.2E12;
    std::cout << tree <<"\n";
    std::cout << guess << "\n";
    std::cout << debt << "\n";

    return 0;
}