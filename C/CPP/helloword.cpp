#include <iostream> //<iostream.h> 이 경우 좀 오래된 스타일
 // #include <cstdio> // 이 경우는 c파일 형태 위 보단 가벼운 형태

int main ()
{
    std::cout << "Hello world\n";  // << std::endl; 출력 버퍼를 강제로 비운다
    int number = 0;
    std::cin >> number; // scanf와 같은 역활의 cin
    std::cout << number << "\n"; // 이후 cin으로 받은 값을 cout 을 출력하는 것
    std::cout.put(number);

    return 0;
}