#include <iostream>
#include <string>

using namespace std;

/*
1.��� ����� ������ �Ҹ��� -> �ٸ� ���� ���� �ڽ� ������ ȣ�� �� �θ� ������ ȣ��
-�ڽ� �ʱ�ȭ �� �θ� �ν��Ͻ��� ���ٴ°� ���� �ȵ�
2.�Ҹ��ڴ� ���� ȣ��� �ݴ�� ���� -> �ڽ��� ���� ����
-�ڽ��� �θ� �����ϴµ� �θ� ���� ���� �ȴٴ� ���� ���� �ȵ�

������ �� ������ �⺻ Ŭ���� ������ ȣ��
ex)T():Base(){}; Base()->������ ����
*/

class A
{
public:
    A() { cout << "������ A" << endl; }
    ~A() { cout << "�Ҹ��� A"
                << endl; }
};
class B : public A
{
public:
    B() { cout << "������ B" << endl; }
    ~B() { cout << "�Ҹ��� B"
                << endl; }
};
class C : public B
{
public:
    C(int) { cout << "������ C" << endl; }
    ~C() { cout << "�Ҹ��� C" << endl; }
};
class D : public C
{
public:
    //D() { cout << "������ C" << endl; } -> C�� �⺻ �����ڰ� ���� ������ ����
    D() : C(1) { cout << "������ C" << endl; }  //����� ������ ����
    ~D() { cout << "�Ҹ��� C" << endl; }
};
int main()
{
    C c{1};      // c ����
    return 0; // c �Ҹ�
}