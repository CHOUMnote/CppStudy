#include <iostream>
#include <string>

using namespace std;

/*
c++은 다중상속을 지원한다.
편하게 기능 추가 가능
하지만 베이스 클래스가 같다면 같은 베이스 클래스를 중복 상속
이를 해결하기 위해 virtual 키워드 사용(가상 상속)
파생 클래스가 생성 될 때 오직 한번만 생성
-기본 클래스 멤버의 중복 생성 방지
*/

class BaseIO
{
public:
    int mode = 10;
    BaseIO() {cout << "기본 생성자\n";};
};
class A : public BaseIO
{
};
class B : public BaseIO
{
};
class C : public A, public B
{
}; //기본 클래스 멤버 중복 상속
class In : virtual public BaseIO
{
public:
};
class Out : virtual public BaseIO
{
public:
};
class InOut : public In, public Out
{ // In에서 베이스 클래스 생성자 먼저 호출 후 Out에서는 멤버 생성 안함
    int t = 1;
};

int main()
{
    //\C t0{};
    InOut t1{};
    // t0.mode = 1; 중복 상속으로 모호한 선언
    t1.mode = 100; // virtual 상속으로 중복 상속 방지
    cout << t1.mode << endl;
}