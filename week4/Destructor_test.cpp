#include <iostream>
#include <string>

using namespace std;

class Animal{
    public:
        string name;
        Animal();
        Animal(string);
        //�Ҹ��ڴ� Ŭ���� �̸� ��'~'�� �޾ƾ� �Ѵ�, �׸��� �μ��¾���, �Ѱ��� �����ؾ� �Ѵ�. 
        //�����ڿ� ���� ��ȯ���� ����.(void ���� �ƴ�!)
         ~Animal();
};
Animal::Animal():Animal("DOG"){}
Animal::Animal(string n) {
    name = n;
    cout << name << "����!\n";
}
Animal::~Animal(){
    cout << name << " delete" << endl;
}

void Temp(){
    Animal x{"Dog1"};
    Animal y{"Dog2"};
}

//�����ڿ� �Ҹ����� ������ Ÿ��
//���� ��ü : ����� ����, ������ �� �Ҹ�
//���� ��ü : �Լ� ȣ��� ����, �Լ� ����� �Ҹ�
//����� ���� ��� ����
//������ �������� �Ҹ�
//new �����ڷ� ���� ������ delete �����ڷ� ��ü �Ҹ�
Animal a{"dog"};
Animal b{"cat"};
int main(){
    Animal a{};
    Animal b{"CAT"};

    Temp();
    return 0;
}