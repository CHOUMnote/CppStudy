#include <iostream>
#include <string>

using namespace std;

class Power
{
    int kick, punch;

public:
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show(string obj);
    Power &operator++();   //���� ++ ������ �Լ� ����
    Power operator++(int); //���� ++ ������ �Լ� ����
    bool operator!();      // ! ������ �Լ� ����
};
void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
}
//���� ++ ������ ��� �Լ� ����
Power &Power::operator++()
{
    kick++;
    punch++;
    return *this; //����� ��ü �ڽ�(��ü a)�� ���� ����
}

//���� ++ ������ ��� �Լ� ����
Power Power::operator++(int)
{                      //������ ���� -> ���� ������
    Power tmp = *this; //���� ���� ��ü ���¸� ����
    kick++;
    punch++;
    return tmp; //���� ���� ��ü ���� ����
}

//! ������ ��� �Լ� ����
bool Power::operator!()
{
    if (kick == 0 && punch == 0)
        return true;
    else
        return false;
}

int main()
{
    Power a{1, 2};
    Power b{};
    a.show("a");
    b.show("b");

    cout << "\n";

    b = ++a;
    a.show("a");
    b.show("b");

    cout << "\n";

    b = a.operator++(0);
    a.show("a");
    b.show("b");

    cout << "\n";
    if (!a)
        cout << "a�� �Ŀ��� 0�̴�." << endl;
    else
        cout << "a�� �Ŀ��� 0�� �ƴϴ�." << endl;
}