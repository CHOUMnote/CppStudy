#include <iostream>
#include <string>

using namespace std;

class Power
{
    int kick, punch;

public:
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show(string obj);
    Power &operator++();   //전위 ++ 연산자 함수 선언
    Power operator++(int); //후위 ++ 연산자 함수 선언
    bool operator!();      // ! 연산자 함수 선언
};
void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
}
//전위 ++ 연산자 멤버 함수 구현
Power &Power::operator++()
{
    kick++;
    punch++;
    return *this; //변경된 객체 자신(객체 a)의 참조 리턴
}

//후위 ++ 연산자 멤버 함수 구현
Power Power::operator++(int)
{                      //임의의 정수 -> 후위 연산자
    Power tmp = *this; //증가 이전 객체 상태를 저장
    kick++;
    punch++;
    return tmp; //증가 이전 객체 상태 리턴
}

//! 연산자 멤버 함수 구현
bool Power::operator!()
{
    if (kick == 0 && punch == 0)
        return true;
    else
        return false;
}

int main()
{
    Power a{1, 2};
    Power b{};
    a.show("a");
    b.show("b");

    cout << "\n";

    b = ++a;
    a.show("a");
    b.show("b");

    cout << "\n";

    b = a.operator++(0);
    a.show("a");
    b.show("b");

    cout << "\n";
    if (!a)
        cout << "a의 파워가 0이다." << endl;
    else
        cout << "a의 파워가 0이 아니다." << endl;
}