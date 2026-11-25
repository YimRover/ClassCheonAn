#include <iostream>
#include <string>
// #include <cstring> //old C style 


int main()
{
    double earnings[4] {1.2,1.6e4,1.1e-2,1.7}; // 배열 선언 및 초기화
    float balances[100] {}; 
    char str[] = "Hello world"; // old style
    std::string str2 = "Hello world"; // C++ style 
    std::cout << str << "\n" ; 
    std::cout << str2 << "\n";
    auto it = str2.begin();
    
    return 0;
}