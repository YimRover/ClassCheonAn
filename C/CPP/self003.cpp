#include <iostream>

struct Inflatable
{
    char name[20];
    float volume;
    double price;
};

typedef struct
{
    char name[20];
    char size[30];
    double price;
}Cloth;


int main ()
{
    Inflatable *ps = new Inflatable;
    std::cout << "모형 건물의 이름을 입력하십시오 : ";
    std::cin.get(ps->name, 20);
    std::cout << "방의 넓이를 세제곱 피트 단위로 입력하십시오 : ";
    std::cin >> (*ps).volume;
    std::cout << "가격을 달러 단위로 입력하십시오 : $";
    std::cin >> ps->price;
    std::cout << "이름 : " << ps->name << std::endl;
    std::cout << "크기 : " << ps->volume << std::endl;
    std::cout << "가격 : " << ps->price << std::endl;
    std::cout << "\r\n";

    std::cin.get();

    Cloth *pp = new Cloth;
    std::cout << "옷의 이름을 입력하세요 : ";
    std::cin.get(pp->name, 20);

    std::cin.get();
    
    std::cout << "옷의 사이즈를 입력하세요 : ";
    std::cin.get(pp->size, 30);
    std::cout << "옷의 가격을 입력하세요 : ";
    std::cin >> pp->price;
    std::cout << "옷의 이름은 : " << pp->name << std::endl;
    std::cout << "옷의 사이즈는 : " << pp->size << std::endl;
    std::cout << "옷의 가격은 : " << pp->price << std::endl;

    delete ps;
    ps = nullptr;
    delete pp;
    pp = nullptr;


    return 0;
}