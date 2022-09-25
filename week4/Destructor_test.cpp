#include <iostream>
#include <string>

using namespace std;

class Animal{
    public:
        string name;
        Animal();
        Animal(string);
        //소멸자는 클래스 이름 앞'~'을 달아야 한다, 그리고 인수는없고, 한개만 존재해야 한다. 
        //생성자와 같이 반환값음 없다.(void 또한 아님!)
         ~Animal();
};
Animal::Animal():Animal("DOG"){}
Animal::Animal(string n) {
    name = n;
    cout << name << "생성!\n";
}
Animal::~Animal(){
    cout << name << " delete" << endl;
}

void Temp(){
    Animal x{"Dog1"};
    Animal y{"Dog2"};
}

//생성자와 소멸자의 라이프 타임
//전역 객체 : 선언시 생성, 종료할 때 소멸
//지역 객체 : 함수 호출시 생성, 함수 종료시 소멸
//선언된 순서 대로 생성
//생성된 역순으로 소멸
//new 연산자로 동적 생성시 delete 연산자로 객체 소멸
Animal a{"dog"};
Animal b{"cat"};
int main(){
    Animal a{};
    Animal b{"CAT"};

    Temp();
    return 0;
}