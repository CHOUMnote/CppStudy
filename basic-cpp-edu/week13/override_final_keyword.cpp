#include <iostream>
#include <string>

using namespace std;

/*
�������̵� �޼ҵ� ���� �� �ۼ�
override : �� �Լ��� �θ� Ŭ�������� virtual�� �ƴ϶�� ����
fianl : �Ļ� Ŭ�������� �������̵� ����
-> Ŭ���� �ڿ� ����ϸ� ��� ����
*/

class A final{};
// class B : public A{}; ����
class B
{
public:
    void print()
    {
        f();
    }
    virtual void f()
    {
        cout << "B Ŭ����\n";
    }
    virtual void finalmethod() final
    {
        cout << "��� ���� �޼ҵ�\n";
    }
    virtual int Get(){
        cout << "�θ� Ŭ����\n";
        return 10;
    }
};

class C : public B
{   
    int Get() override{
        cout << "�������̵�\n";
        return 1;
    }
    int Get(int){   //�����ε�
        cout << "�����ε�\n";
        return 9;
    }
public:
    //void print() override; ����
    void f()    //���� ���ε�
    {
        cout << "CŬ����\n";
        cout << Get() << endl;
    }
    //virtual void finalmethod(); ����
};

int main(){
    C c;
    B *p = &c;
    p->print();
    p->finalmethod();
};