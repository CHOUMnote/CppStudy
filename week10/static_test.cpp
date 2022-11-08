#include <string>
#include <iostream>

using namespace std;
class Person
{
public:
    double money; //�ν��Ͻ� ���
    void addMoney(int money)
    {
        this->money += money;
        this->sharedMoney += money; //non-static�� static�� ���� ����
    }
    static inline int sharedMoney; // static ��� ���� ����
    static void addShared(int n)
    { // static ��� �Լ� ����
        sharedMoney += n;
        //this->sharedMoney += n; static�� this��� �Ұ���
    }
};
//�ܺ� �����̾����� ���� - �ζ��� ����� ���� ����
//int Person::sharedMoney = 10; // static ������� �ʱ�ȭ
/*
1. static ����Լ��� non-static ��� ���� �Ұ� - ��ü ���� �� �����Ѵٴ°� ���� �ȵ�
2. static ����� static ����� ����, ���� ������ ����
3. this ��� �Ұ��� - ��ü�� ���µ� ��ü�� ���� �Ѵٴ°� ���� �ȵ�
4. non-static ����� static�� ���� ����
*/


int main()
{
    cout << Person::sharedMoney << endl;

    cout << "===1===\n";
    //��ü�� static��� ����
    Person lee{};
    lee.sharedMoney = 100;
    Person*p = &lee;
    p->addShared(100);
    p->addMoney(10);
    cout << lee.sharedMoney << endl;

    cout << "===2===\n";
    //Ŭ������ static��� ����
    Person::sharedMoney=300;//Ŭ���� namespace�ȿ� static ������ ����
    //Person::money = 100; static�ƴ�
    cout << Person::sharedMoney << endl;
}