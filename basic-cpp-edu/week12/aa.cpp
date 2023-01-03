#include <iostream>
#include <string>

using namespace std;

/*
1.상속 관계시 생성자 소멸자 -> 다른 언어와 같이 자식 생성자 호출 전 부모 생성자 호출
-자식 초기화 시 부모 인스턴스가 없다는건 말이 안됨
2.소멸자는 생성 호출과 반대로 삭제 -> 자식이 먼저 삭제
-자식은 부모를 포함하는데 부모가 먼저 삭제 된다는 것은 말이 안됨

컴파일 시 묵시적 기본 클래스 생성자 호출
ex)T():Base(){}; Base()->묵시적 선언
*/

class A
{
public:
    A() { cout << "생성자 A" << endl; }
    ~A() { cout << "소멸자 A"
                << endl; }
};
class B : public A
{
public:
    B() { cout << "생성자 B" << endl; }
    ~B() { cout << "소멸자 B"
                << endl; }
};
class C : public B
{
public:
    C(int) { cout << "생성자 C" << endl; }
    ~C() { cout << "소멸자 C" << endl; }
};
class D : public C
{
public:
    //D() { cout << "생성자 C" << endl; } -> C의 기본 생성자가 없기 때문에 에러
    D() : C(1) { cout << "생성자 C" << endl; }  //명시적 생성자 선언
    ~D() { cout << "소멸자 C" << endl; }
};
int main()
{
    C c{1};      // c 생성
    return 0; // c 소멸
}