#include <string>
#include <iostream>

using namespace std;

class Circle{
    double dummy1 = 10;
    double dummy2 = 10;
    double dummy3 = 10;
    public:
        int a = 10;  
        Circle();
        Circle(int);
};
Circle::Circle():Circle(100){};
Circle::Circle(int b):a{b}{};

int main(){
    //��ü ������ ����
    Circle a{};
    Circle* pa = &a;
    cout << pa->a << endl;
    cout << sizeof(a) << " " << sizeof(pa) << endl;
    //�ּҴ� 8

    //��ü �迭
    Circle b[2]; //�� ���Ҵ� ����Ʈ ������ ȣ��
//    Circle c[3] = {1,2};//���ϴ� ������ ȣ��
    Circle c[3] = {Circle{1},Circle{2}};//���ϴ� ������ ȣ��

    cout << "bȣ�� \n";
    for(Circle i : b) cout << i.a << endl;
    cout << "cȣ�� \n";
    for(Circle i : c) cout << i.a << endl;
    cout << endl << endl;

    //n���� �迭

    Circle d[3][3]; // �ʱ�ȭ�� {{{1,2,3},
                    //          {4,5,6}}
}