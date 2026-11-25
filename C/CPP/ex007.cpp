#include <iostream>
// 열거체

enum Spectrum  // enum class Spectrum 으로도 사용하기도함
{
    Red, Orange, Yellow, Green, Blue, Violet, Indigo, Ultraviolet
}; // 변수에 대한 상수화 값은 변경이 어렵다.

int main()
{
    Spectrum band;
    int input_num = 0;
    std::cin >> input_num;
    if (input_num == Spectrum::Blue)
    {
        std::cout << "블루" << "\n" << std::endl;
    }
    return 0;
}