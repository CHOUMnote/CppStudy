#include <iostream>
#include <string>

using namespace std;
/*
연산자 오버로딩?
피연사자에 따른 서로 다른 연산을 하도록 연산자를 중복 작성 하는것
1. 연산자 중복 정의 -> 가독성 높아짐
2. c++에 본래부터 있던 연산자에 새로운 의미 부여
3. 클래스를 기본타입처럼 다룰 수 있다.
4. 프로그램을 세밀히 제어 가능하다
*/

/*
연산자 오버로딩 방법
1. c++에 기존 연산자만 가능하다.
이중에서도 .(닷) .*(전체) ::(범위지정) ?:(3항) 이 넷은 오버로딩 불가능
연산자 우선순위는 고정
2. 연산자는 함수 형태로 구현 - 연산자 함수
클래스 멤버 함수 또는 외부함수
디폴트 매개변수 불가능,
*/

/*
예시
Color a(BLUE), b(RED), c;
c = a + b; - 객체끼리 더할 수 있나?
-> 연산자 함수 필요!
*/

//이번 주차 테스트를 위한 클래스!
class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show(string obj);
    Power operator+(const Power&); //더하기 연산 재정의
};
void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
};
Power Power::operator+(const Power& p)
{
    // Power temp{p};//복사 후 리턴! 상황에 따라서 깊은 복사 필요!
    return Power{this->kick + p.kick, this->punch + p.punch}; //임시객체 리턴
};

int main()
{
    Power a(3, 5), b(4, 6), c;
    // 객체 a의 operator+() 멤버 함수 호출
    c = a + b; //파워 객체 + 연산
    //c=a.operator+(b); 이와 같은 형태로 자동으로 컴파일!
    a.show("a");
    b.show("b");
    c.show("C");
}