#include <string>
#include <iostream>

using namespace std;
class Person
{
public:
    double money; //인스턴스 멤버
    void addMoney(int money)
    {
        this->money += money;
        this->sharedMoney += money; //non-static은 static에 접근 가능
    }
    static inline int sharedMoney; // static 멤버 변수 선언
    static void addShared(int n)
    { // static 멤버 함수 선언
        sharedMoney += n;
        //this->sharedMoney += n; static은 this사용 불가능
    }
};
//외부 선언이없으면 에러 - 인라인 선언시 생략 가능
//int Person::sharedMoney = 10; // static 멤버변수 초기화
/*
1. static 멤버함수는 non-static 멤버 접근 불가 - 객체 생성 전 접근한다는건 말이 안됨
2. static 멤버는 static 멤버만 접근, 지역 번수는 가능
3. this 사용 불가능 - 객체가 없는데 객체를 접근 한다는건 말이 안됨
4. non-static 멤버는 static에 접근 가능
*/


int main()
{
    cout << Person::sharedMoney << endl;

    cout << "===1===\n";
    //객체러 static멤버 접근
    Person lee{};
    lee.sharedMoney = 100;
    Person*p = &lee;
    p->addShared(100);
    p->addMoney(10);
    cout << lee.sharedMoney << endl;

    cout << "===2===\n";
    //클래스로 static멤버 접근
    Person::sharedMoney=300;//클래스 namespace안에 static 구역에 존재
    //Person::money = 100; static아님
    cout << Person::sharedMoney << endl;
}