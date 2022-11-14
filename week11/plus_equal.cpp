#include <iostream>
#include <string>

using namespace std;

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
    Power& operator+=(const Power &); //더하기 연산 재정의
};
void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
};
Power& Power::operator+=(const Power &p)
{
    this->kick += p.kick;
    this->punch += p.punch;
    return *this; //매개 변수 값들 더한 후 자신 리턴
};

int main()
{
    Power a(3, 5), b(4, 6), c;
    a.show("a");
    b.show("b");
    //a.operator+=(b)
    c = a+=b; // 파워 객체 더하기
    a.show("a");
    c.show("c");
}