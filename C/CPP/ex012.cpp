#include <iostream>
#include <vector>
 

int main ()
{
    std::vector<int> vec1{1,2,3,4,5};
    for (int i = 0; i < 5; ++i) // 전통적인 for 구문 사용
    {
        std::cout << vec1[i] << "\t";
    }
    std::cout << std::endl;
    
    for (auto i = vec1.cbegin(); i != vec1.cend(); ++i) // .cbegin 이랑 .cend로 시작과 끝을 활용한 for 구문
    {
        std::cout << *i << "\t";
    }
    std::cout << std::endl;
    
    for (auto i : vec1) // range기반의 for 구문사용
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}