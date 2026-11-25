#include <iostream>

int main ()
{
    double *p3 = new double [3];

    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    std::cout << "p3[0]은 " << p3[0] << "입니다. \n";
    std::cout << "p3[1]은 " << p3[1] << "입니다. \n";
    std::cout << "p3[2]은 " << p3[2] << "입니다. \n";
    std::cout << "p3 = p3 +1 코드를 넣으면 \n";
    p3 = p3 +1;
    std::cout << "이제는 p3[0]이 " << p3[0] << "이고, ";
    std::cout << "p3[1]이 " << p3[1] << "입니다.\n";
    std::cout << "p3 = p3-1 을 하면 \n";
    p3 = p3 -1;
    std::cout << "이제 다시 p3[0]은 " << p3[0] << "이고, ";
    std::cout << "p3[1]은 다시 " << p3[1] << "입니다.\n";
    delete[] p3;
    p3 = nullptr;
    return 0;
}