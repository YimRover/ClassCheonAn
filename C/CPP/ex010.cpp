#include <iostream>
#include <vector> // vector 템플릿을 사용할려면 선언해야되는 헤더
#include <array>

void ary_func(std::array<double, 4> ary)
{
    std::size_t ary_size = ary.size();
}

int main()
{
    std::vector <int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30); // HEAP에 10,20,30 배열형식으로 값을 넣는다.논리적으로 순서대로 나열
    std::cout << vec[0] <<", " << vec[1] <<", " << vec[2] <<", " << std::endl; // HEAP에 저장된 vec의 값을 순서대로 불러오는 방식
    // std::cout << vec << std::endl; 이런식이면 vec의 값을 출력못한다.
    vec.insert(vec.begin() + 1, 50);// vec의 첫 시작으로부터 +1 [1]자리에 50을 넣는것
    std::cout << vec[1] << std::endl;
    std::cout << vec[0] <<", " << vec[1] <<", " << vec[2] <<", " << vec[3] << std::endl; // 이후 앞에 연속적인 배열에 추가로 값을 넣었기 때문에 이후 순서대로 값이 유동적으로 밀림
    for (auto i : vec ) // advanced for 구문
    {
        std::cout << i << "\t";
    }
    std::cout << std:: endl;
    for (auto i = vec.cbegin(); i != vec.cend(); ++i) // iterater 방식 i 대신 iter를 넣어서 사용
    {
        std::cout << *i << "\t";
    }
    std::cout << std::endl;

    std::array <double,4> array1 {1,2,3,4};
    array1[0] = 3.14;
    array1[1] = 2.724;
    array1[2] = 1.414;
    array1[3] = 0.0;
    for (auto item : array1)
    {
        std::cout << item << "\t";
    }
    std::cout << std::endl;
    return 0;
}