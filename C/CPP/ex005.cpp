#include <iostream>
#include <string>

struct Inflatable
{
    //char name [20];
    std::string name;
    float volume;
    double price;
};
typedef struct
{
    std::string name;
    float volume;
    double price;
}Inflat;

int main()
{
    Inflatable flat {"", 0.0f, 0.0}; // C에선 여기서 앞에 struct라는 표현을 해야되었지만, C++에선 그냥 가져다 쓸 수 있다.
    flat.name = "hehehe" ;
    flat.price = 100.0;
    flat.volume = 10.0f;
    Inflat flat1 {"", 0.0f, 0.0};
    // Inflat flat1 = Inflatable flat; 성립할 수 없는 관계 Inflat flat1은 자료형구조체, Inflatable flat은 구조
    Inflatable flat2[2]
    {
        {"Duck", 100.3f, 200.0},
        {"DOG", 200.4f, 400.0}
    };

    std::cout << flat.name << "\n";
    std::cout << "price : " << flat.price << "\n";
    std::cout << "volume : " << flat.volume << "\n";
    std::cout << "Inflat : " << flat1.name << ", " << flat1.price << ", " << flat1.volume << "\n";
    std::cout << flat2[0].name << "\n";

    std::cout << "=========" << "\n";

    for (int i = 0; i < 2; ++i )
    {
        std::cout << flat2[i].name << ", " << flat2[i].price << ", " << flat2[i].volume << "\n";
    }
    return 0;
}