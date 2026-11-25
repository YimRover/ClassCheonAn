#include <iostream>

int main()
{
    int value0 = (int)19.99; // 구식 C스타일
    int value1 = int(19.99) + int(11.99); // 신식 C++ 스타일
    int value2 = static_cast<int>(19.99); // 권장
    auto value3 = 10ul; // 오른쪽을 보고 자동으로 변환해줌

    return 0;
}