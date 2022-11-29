#include <string>
#include <iostream>

using namespace std;

/*
순수 가상 함수 : 함수의 선언만 있고 구현x
추상 클래스 : 순수 가상 함수를 포함 하는 클래스
인스턴스화 불가능, 파생 클래스에서 구현 해야함 아니면 그것도 추상 클래스
T virtual F()=0 선언

+++
private 가상함수는 오버라이딩이 가능하다
선언은 부모 - 구현은 자식
왜 쓰는가?
자식 객체에서 정적 바인딩으로 부모의 함수를 부를수 있지만 그것도 허용하지 않는다!
*/

class A{    //추상클래스
    A *a;
    virtual void ff() = 0;
    virtual void fff(){};
public:
    void print(){
        f();    // 순수 가상함수도 호출 가능
    }
    virtual void f() = 0; //-> 순수 가상 함수
};

class B : A{};

class C : public B{
public:
//private 가상함수 재정의!
    void ff(){cout << "?\n";}
    void fff(){cout << "??\n";};
    
    virtual void f() override{
        cout << "순수 가상함수 구현\n";
    }
};
int main(){
    //A a; 추상 클래스는 인스턴스화 불가능
    A*a;    //이건 포인터이기 때문에 가능
    //B b;  구현 안했기 때문에 얘도 추상 클래스
    
    C c;
    c.fff();
    return 0;
}