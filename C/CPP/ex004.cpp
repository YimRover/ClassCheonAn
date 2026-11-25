#include <iostream> // ostream + istream 

int main()
{
    std::string str1;
    std::string str2;
    std::string str4;
    // char str5[100];
    std::cin >> str1;
    std::cout << str1 << "\n";
    std::cin >> str2;
    std::string str3 = str1 + str2 ;
    std::cout << str3 << "\n";
    std::cout << str3.size() << std::endl;
    
    // std::cin >> str4;
    // str4.clear();
    // std::cin >> str4;
    std::cin.get();//밑에 getline을 제대로 받기 위한 위에서 받아놓은 버퍼값 처리
    std::getline(std::cin, str4); // getline으로 전체 문자열을 받을 수 있음 (다만 위에서 버퍼값이 존재할 경우 제대로 받질 못함)
    // std::cin.getline(str5, 100);
    std::cout <<  str3 << str4 << "\n";
    return 0;
}