/*
객체 치환 경우를 알아보자
치환 가능한 객체는 모든 데이터가 비트단위로 복사 -> 독립 공간 할당
1. 원시 자료형 : 값 복사    -> 깊은 복사
2. 클래스 자료형 : 주소 복사 -> 얕은 복사
3. 위 차이 때문에 의도치 않은 오류 발생
*/

#include <iostream>
#include <string>

using namespace std;
class T1
{
public:
    string name;
    int i;
    T1()
    {
        name = "AAA";
        i = 777;
    };
    void print()
    {
        cout << name << "  " << i << '\n';
    }
};

//얕은 복사 테스트 케이스
class T2
{
public:
    string name;
    int *i; //동적 메모리 복사 -> 주소 복사:메모리 공유(기본 복사 생성자)
    T2()
    {   
        //원시 자료형은 독립
        //포인터 자료형은 주소 값을 공유 -> 같은 메모리를 참조
        cout << "일반생성자 \n";
        name = "AAA";
        i = new int{100};
    }
    void print()
    {
        cout << name << "  " << *i << '\n';
    }
    T2(const T2 &t){ //기본 복사 생성자 원형
        cout<<"복사 생성자\n";
        this->name=t.name;
        this->i=t.i;
    }
    ~T2(){
        delete i; //두번 소멸자 호출 -> nullptr 참조기 때문에 비정상적 종료!
    }
};

int main()
{
    T1 a1{};
    T1 a2 = a1;

    //원시 자료형 -> 깊은 복사(string::= 연산자 또한 깊은 복사
    a1.i = 0;
    a1.name = "BBB";
    cout << "a1 객체 출력 : ";
    a1.print();
    cout << "a2 객체 출력 : ";
    a2.print();
    cout << endl;

    //포인터 자료형은 메모리를 공유!
    T2 b1{};
    T2 b2{b1};  //복사 생성자 호출

    *b1.i = 999;
    b1.name="BBB";
    cout << "b1 객체 출력 : ";
    b1.print();
    cout << "b2 객체 출력 : ";
    b2.print();
    cout << endl;
};