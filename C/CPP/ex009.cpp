#include <iostream>

int main()
{
    int nights{1001};
    int *pt { new int }; // HEAP(freestore)를 사용하겠다. / C에선 에멀록과 같은 효과
    *pt = nights;
    std::cout << "night의 값 = ";
    std::cout << nights << ": 메모리 위치 " << &nights << std::endl;
    std::cout << "int 형";
    std::cout << "값 = " << *pt << ": 메모리 위치 " << pt << std::endl;
    
    double *pd {new double};
    *pd = 10000001.0;
    
    std::cout << "double 형";
    std::cout << "값 = " << *pd << ": 메모리 위치" << pd << std::endl;
    std::cout << "포인터 pd의 메모리위치 : " << &pd << std::endl;
    std::cout << "pt의 크기 = " << sizeof(pt);
    std::cout << ": *pt의 크기 = " << sizeof(*pt) << std::endl;
    std::cout << "pd의 크기 = " << sizeof(pd);
    std::cout << ": *pd의 크기 = " << sizeof(*pd) << std::endl; 

    delete pt; // HEAP(freestore)의 사용을 해제하겠다. / C에선 free랑 같은 효과
    pt = nullptr; // 이후 값을 초기화
    delete pd;
    pd = nullptr;

    int inputArray = 0;
    std::cin >> inputArray;
    int *ptrArray = new int[inputArray];
    delete[] ptrArray; // 동적 배열을 사용했으면 delete에서도 배열의 형태를 같이 표시를 해줘야 한다.
    ptrArray = nullptr; // 동적 배열을 사용한 후 값을 초기화까지 진행
    return 0;
}