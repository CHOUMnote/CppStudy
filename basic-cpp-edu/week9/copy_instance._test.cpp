/*
��ü ġȯ ��츦 �˾ƺ���
ġȯ ������ ��ü�� ��� �����Ͱ� ��Ʈ������ ���� -> ���� ���� �Ҵ�
1. ���� �ڷ��� : �� ����    -> ���� ����
2. Ŭ���� �ڷ��� : �ּ� ���� -> ���� ����
3. �� ���� ������ �ǵ�ġ ���� ���� �߻�
*/

#include <iostream>
#include <string>

using namespace std;
class T1
{
public:
    string name;
    int i;
    T1()
    {
        name = "AAA";
        i = 777;
    };
    void print()
    {
        cout << name << "  " << i << '\n';
    }
};

//���� ���� �׽�Ʈ ���̽�
class T2
{
public:
    string name;
    int *i; //���� �޸� ���� -> �ּ� ����:�޸� ����(�⺻ ���� ������)
    T2()
    {   
        //���� �ڷ����� ����
        //������ �ڷ����� �ּ� ���� ���� -> ���� �޸𸮸� ����
        cout << "�Ϲݻ����� \n";
        name = "AAA";
        i = new int{100};
    }
    void print()
    {
        cout << name << "  " << *i << '\n';
    }
    T2(const T2 &t){ //�⺻ ���� ������ ����
        cout<<"���� ������\n";
        this->name=t.name;
        this->i=t.i;
    }
    ~T2(){
        delete i; //�ι� �Ҹ��� ȣ�� -> nullptr ������ ������ �������� ����!
    }
};

int main()
{
    T1 a1{};
    T1 a2 = a1;

    //���� �ڷ��� -> ���� ����(string::= ������ ���� ���� ����
    a1.i = 0;
    a1.name = "BBB";
    cout << "a1 ��ü ��� : ";
    a1.print();
    cout << "a2 ��ü ��� : ";
    a2.print();
    cout << endl;

    //������ �ڷ����� �޸𸮸� ����!
    T2 b1{};
    T2 b2{b1};  //���� ������ ȣ��

    *b1.i = 999;
    b1.name="BBB";
    cout << "b1 ��ü ��� : ";
    b1.print();
    cout << "b2 ��ü ��� : ";
    b2.print();
    cout << endl;
};