#include <iostream>
#include <string>

using namespace std;

class Power
{              //�������� ǥ���ϴ� �Ŀ� Ŭ����
    int kick;  //�߷� ���� ��
    int punch; //�ָ����� ġ�� ��
public:
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show(string obj);
    bool operator==(const Power&); //���ϱ� ���� ������
};
void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
};
bool Power::operator==(const Power& p)
{   
    //��� ������ �� �� ����
    return (kick == p.kick) && (punch == p.punch); //�ӽð�ü ����
};

int main()
{
    Power a(3, 5), b(3, 5); // 2���� ������ �Ŀ� ��ü ����
    a.show("a");
    b.show("b");

    if (a==b) //a.operator==(b)
        cout << "�� �Ŀ��� ����." << endl;
    else
        cout << "�� �Ŀ��� ���� �ʴ�." << endl;
}