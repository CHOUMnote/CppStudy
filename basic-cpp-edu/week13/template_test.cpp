#include <string>
#include <iostream>

using namespace std;

/*
���ø�? �Ϲ�ȭ ���α׷���(c#, �ڹ��� ���׸��ϰ� �Ȱ���)
STL -> ���ø� Ŭ������ ���� (�ڷᱸ�� ����!)

templateŰ����� ���� �� ����
template <class T>, <typename T>�� ����
n���� ���׸� ��� : template <typename T1, typename T2...>
*/

class Test{
    string s;
public:
    Test(string a):s{a}{};
    void print(){
        cout << s << endl;
    }
};
//���׸� �Լ�
namespace my{
    template <typename Name>
    void print(Name n){ //T&, T*�� �ڷ��� �߰� ���� (����, ������)
        cout << "�̸��� " << n << endl;
    }
    template <typename T>
    void swap(T&a, T&b){ //T&, T*�� �ڷ��� �߰� ���� (����, ������)
        T t = a;
        a = b;
        b = t;
    }
}

int main(){
    //���׸� �Լ� ȣ��
    my::print("kimjiho");
    my::print(123);
    my::print(123.12314);
    string a,b = "����ȣ";
    a = "����ȣ";
    my::swap(a,b);
    cout << a << " : " << b << endl << endl;

    Test s1{"������"};
    Test s2{"123"};
    my::swap(s1,s2);
    s1.print();
    s2.print();
    cout << endl;

    //����� �ڷ��� ����
    my::print<int>(1);
    my::print<int>(1.2f);   //������ ����ȯ -> int n=1.2
    
}