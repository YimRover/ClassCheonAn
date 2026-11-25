#include <iostream>
//비트 필드 방식

struct Torgle // 10bit 즈음을 사용할 구조체 짜임새
{
    unsigned int SN: 4; // SN 값 4bit 사용
    unsigned int : 4; // 4bit 값을 사용 X // 임베디드 환경에서 레지스터의 값을 변환해서 사용을 하기 위해 비워 둘 수 있음
    // 다만 이 상태로는 사용 X 위에 SN처럼 변수값을 선언해서 포인터형식으로 사용은 가능하게 하는 방법
    bool goodIn : 1; // 1bit 사용
    bool goodTorgle : 1; // 1bit 사용
};


int main ()
{
    Torgle triger {14,true, false}; // 위에 Torgle 사용 할 것 왜 3개냐 위에 1개는 사용을 안한다고 선언을 했기 때문
    return 0;
}