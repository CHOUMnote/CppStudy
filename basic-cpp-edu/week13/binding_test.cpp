#include <iostream>
#include <string>

using namespace std;

/*
다형성 - 같은 이름을 갖는 여러 형태의 함수를 클래스별로 만드는 기능
정적 바인딩 - 상속 간 함수 재정의 : 컴파일시 다형성 구성
동적 바인딩 - 가상 함수(virtual fnc) : virtual 키워드로 선언 -> 동적 바인딩 지시
            컴파일러에게 함수에 대한 호출 바인딩을 런타임까지 미룬다.

가상함수 오버라이딩 : 파생클래스에서 기본 클래스의 virtual 함수와 동일한 이름의 함수 선언
- 기본 클래스에 있는 가상함수의 존재감을 상실 시킨다
- 파생 클래스에서 오버라이딩한 함수가 호출 되도록 한다.(동적 바인딩 - 실행시간 다형성)
- 함수 재정의 : 같은 말이지만 보통 정적 바인딩

오버라이딩? 파생 클래스에서 구현 해야하는 명세 즉, 인터페이스를 제공한다.
c++에서는 자바처럼 인터페이스는 따로 없고 순수 가상 함수가 그 역할을 한다.
순수 가상 함수 - virtual void fnc() = 0;
이를 구현 하지 않은 파생 클래스도 인터페이스로 작동

c++의 다형성 : 포인터, 호환 객체(상속), 가상 함수
*/
class Base
{
public:
virtual void ff(){cout << "Base::f() called" << endl;};
void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base
{
public: //함수 재정의
virtual void ff(){cout << "Derived::f() called" << endl; }  //가상함수 오버라이딩 - virtual생략가능
void f() { cout << "Derived::f() called" << endl; }
};

int main(){
Derived d, *pDer;
pDer = &d;
pDer->f(); //Derived::f() 호출
pDer->Base::f(); //Base::f() 호출

Base* pBase;
pBase = pDer; //업캐스팅
pBase->f(); //Base::f() 호출
pBase->Base::f();

cout << "============================\n";

pDer->ff();
pDer->Base::ff();   //부모 함수 호출

pBase->ff();    //동적 바인딩
pBase->Base::f();   //부모 호출
}