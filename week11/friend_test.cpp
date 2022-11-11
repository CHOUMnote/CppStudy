#include <iostream>
#include <string>

using namespace std;

/*
������ �Լ�?
Ŭ������ ��� �Լ��� �ƴ� �ܺ� �Լ� - ��� x

1. �ܺ�(����) �Լ� �Ǵ� �ٸ� Ŭ������ ����Լ��鿡 ����
Ŭ������ ��� ��� ���� ���� �ο� - private ��... ���� ����
������ ���� ���� ���� x
2. Ŭ���� ����δ� �����ϱ� ������ ������ ����
ex) ������ �ߺ� (���� ����)
*/

//���� ���� ���� �� ����
class Main;

class Manager
{ // RectManager Ŭ���� ����
public:
    bool equals(Main, Main);
    void print(Main, Main);
};

class Main
{ // Rect Ŭ���� ����
    int a, b;

public:
    Main(int i, int j)
    {
        this->a = i;
        this->b = j;
    }
    friend bool equals(Main, Main);          //�ܺ��Լ� ������ ����
    friend bool Manager::equals(Main, Main); //�ٸ� Ŭ������ ��� �Լ� ������ ����
    friend Manager;                          //�ٸ� Ŭ���� ��ü�� ������ ����
};

// �ݵ�� ��� ���� ���� ����!
// incomplete ���� ����!
void Manager::print(Main r, Main s)
{
    cout << r.a << " " << r.b << endl;
    cout << s.a << " " << s.b << endl;
};
bool Manager::equals(Main r, Main s)
{
    if (r.a == s.a && r.b == s.b)
        return true;
    else
        return false;
};

bool equals(Main x, Main y) //�ܺ��Լ�
{
    if (x.a == y.a && x.b == y.b) //������� ���� ���ϸ� ���� ���� ����
        return true;
    else
        return false;
}

int main()
{
    Main a(3, 4), b(3, 4);
    cout << "===�ܺ��Լ� ������ ����===\n";
    if (equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    cout << "===Ŭ���� �Լ� ������ ����===\n";
    Manager m{};
    if (m.equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    cout << "===Ŭ���� ��ü ������ ����===\n";
    m.print(a,b);

    return 0;
}