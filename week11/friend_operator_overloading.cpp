#include <iostream>
#include <string>

using namespace std;

//�ܺ� �Լ� �����带 �̿��� ������ �����ε�
// fnc(T1, T2) -> T1�� ����, T2�� ������ �����ڸ� ����
// fnc(T1, [int]) -> ���� ����, int�� ���� ����� ���� ���� ���н� ���

class Power
{
    int kick, punch;

public:
    Power(int a=0, int b=0){
        kick=a;
        punch=b;
    }
    void show(string obj);
    // ������ ����
    friend Power operator+(const Power &op1, const Power &op2);
    friend Power &operator++(Power &op);       //���� ����
    friend Power operator++(Power &op, int); //���� ����
};
void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(const Power &op1, const Power &op2)
{
    Power tmp;                         //�ӽ� ��ü ����
    tmp.kick = op1.kick + op2.kick;    // kick ���ϱ�
    tmp.punch = op1.punch + op2.punch; // punch ���ϱ�
    return tmp;                        //�ӽ� ��ü ����
}

Power &operator++(Power &op) //���� ����
{
    op.kick++;
    op.punch++;
    return op; //���� ��� ����
}
Power operator++(Power &op, int) //���� ����
{
    Power tmp = op; //�����ϱ� ���� op ���� ����
    op.kick++;
    op.punch++;
    return tmp; //���� ������ op ����
}

int main()
{
    Power a(3, 5), b;
    b = operator++(a); //���� ++ ������
    b = operator++(a,0); //���� ++ ������
    a.show("a");
    b.show("b");
}