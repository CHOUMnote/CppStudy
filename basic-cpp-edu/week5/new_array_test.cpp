#include <string>
#include <iostream>

using namespace std;

class Circle
{
public:
    string a;
    Circle();
    Circle(string);
};
Circle::Circle() : Circle("����Ʈ"){};
Circle::Circle(string b) : a{b} {};

int main()
{
    //���� �迭 ����
    int *a = new int[10]{1, 2, 3, 4};
    cout << "a�� ������ : " << *a << endl;
    cout << endl;

    //��ü�迭 ���� ����
    Circle *b = new Circle[4]{{}, Circle{"��"}, Circle{"A"}}; //��Ƽ�� �ʱ�ȭ ����
    for (int i = 0; i < 4; i++)
        cout << b[i].a << endl;
    cout << endl;
    ;

    //������ �迭
    Circle *c[3] = {new Circle, new Circle, new Circle{"��������!"}};
    int size = sizeof(c) / sizeof(c[0]);
    cout << "�迭�� ������ : " << size << endl;
    for (int i = 0; i < size; i++)
        cout << (*(*(c+i))).a << endl;
        //(*(c+i))->a
    cout << endl;
    ;
}