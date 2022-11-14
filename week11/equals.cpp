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
    bool operator==(const Power&); //더하기 연산 재정의
};
void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
};
bool Power::operator==(const Power& p)
{   
    //멤버 변수를 비교 후 리턴
    return (kick == p.kick) && (punch == p.punch); //임시객체 리턴
};

int main()
{
    Power a(3, 5), b(3, 5); // 2개의 동일한 파워 객체 생성
    a.show("a");
    b.show("b");

    if (a==b) //a.operator==(b)
        cout << "두 파워가 같다." << endl;
    else
        cout << "두 파워가 같지 않다." << endl;
}