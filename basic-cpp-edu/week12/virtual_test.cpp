#include <iostream>
#include <string>

using namespace std;

/*
c++�� ���߻���� �����Ѵ�.
���ϰ� ��� �߰� ����
������ ���̽� Ŭ������ ���ٸ� ���� ���̽� Ŭ������ �ߺ� ���
�̸� �ذ��ϱ� ���� virtual Ű���� ���(���� ���)
�Ļ� Ŭ������ ���� �� �� ���� �ѹ��� ����
-�⺻ Ŭ���� ����� �ߺ� ���� ����
*/

class BaseIO
{
public:
    int mode = 10;
    BaseIO() {cout << "�⺻ ������\n";};
};
class A : public BaseIO
{
};
class B : public BaseIO
{
};
class C : public A, public B
{
}; //�⺻ Ŭ���� ��� �ߺ� ���
class In : virtual public BaseIO
{
public:
};
class Out : virtual public BaseIO
{
public:
};
class InOut : public In, public Out
{ // In���� ���̽� Ŭ���� ������ ���� ȣ�� �� Out������ ��� ���� ����
    int t = 1;
};

int main()
{
    //\C t0{};
    InOut t1{};
    // t0.mode = 1; �ߺ� ������� ��ȣ�� ����
    t1.mode = 100; // virtual ������� �ߺ� ��� ����
    cout << t1.mode << endl;
}