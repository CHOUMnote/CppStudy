#include <iostream>
#include <string>

using namespace std;

/*
오버라이딩 메소드 원형 뒤 작성
override : 이 함수가 부모 클래스에서 virtual이 아니라면 에러
fianl : 파생 클래스에서 오버라이딩 금지
-> 클래스 뒤에 사용하면 상속 금지
*/

class A final{};
// class B : public A{}; 에러
class B
{
public:
    void print()
    {
        f();
    }
    virtual void f()
    {
        cout << "B 클래스\n";
    }
    virtual void finalmethod() final
    {
        cout << "상속 금지 메소드\n";
    }
    virtual int Get(){
        cout << "부모 클래스\n";
        return 10;
    }
};

class C : public B
{   
    int Get() override{
        cout << "오버라이딩\n";
        return 1;
    }
    int Get(int){   //오버로딩
        cout << "오버로딩\n";
        return 9;
    }
public:
    //void print() override; 에러
    void f()    //동적 바인딩
    {
        cout << "C클래스\n";
        cout << Get() << endl;
    }
    //virtual void finalmethod(); 에러
};

int main(){
    C c;
    B *p = &c;
    p->print();
    p->finalmethod();
};