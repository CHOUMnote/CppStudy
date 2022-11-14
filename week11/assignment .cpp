#include <iostream>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

/*
���� ������ - operator=
*/
class Person
{
    char *name;
    int id;

public:
    Person(int id, const char *name);
    Person(const Person&) = default;
    ~Person() { delete[] name; };
    void show() { cout << id << ',' << name << endl; }
    Person &operator=(const Person &person);    //���� ������ �Լ�
    Person &operator=(const Person &&person); //�̵� ���� ������
    friend void swap_person(Person &, Person &) noexcept;
};
Person::Person(int id, const char *name)
{
    this->id = id;
    int len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}
// Person &Person::operator=(const Person &rhs) //������ ���ܰ� �߻��� ������ �����!
// {
//     if (this == &rhs) //�ڱ� �ڽ��� ����
//         return *this;
//     delete name; //���� �޸� ����
//     name = nullptr;
//     //�޸� ���� �Ҵ�
//     int len = strlen(rhs.name);
//     name = new char[len + 1];
//     //������ ����
//     id = rhs.id;
//     strcpy(name, rhs.name);
//     return *this;
// }

Person &Person::operator=(const Person &person)
{
    if (this == &person) //�ڱ� �ڽ��� ����
        return *this;
    cout << "���� ������ ����\n";
    Person temp{person};      //�ӽ� ��ü ����
    swap_person(*this, temp); //���� ��ü�� ������ �ӽ� ���纻���� ��ü
    //�ӽ� ��ü�� �����ϰ� ����
    return *this;
}
Person &Person::operator=(const Person &&person)
{
    cout << "�̵� ���� ������ ����\n";
    Person temp(person);
    swap_person(*this, temp);
    return *this;
}

// utility ���̺귯������ �����ϴ� swap() �Լ� �̿����� ����,�����ϰ� ����
//���� ������ swap_person()�� �����ϸ� ��
void swap_person(Person &first, Person &second) noexcept
{
    swap(first.id, second.id);
    swap(first.name, second.name);
}

Person createObject() {
    return Person(10, "HHH"); //rvalue(��) ��ȯ
}

int main()
{
    Person father(1, "Kitae");
    Person daughter(2, "Grace");
    father = daughter; //���� ������ �Լ� ȣ��
    father.show();
    daughter.show();

    Person p1(1, "software");
    p1 = createObject(); //�̵� ���� ������ ȣ��
    //p1.operator=(createObject());
    p1.show();
    return 0;
}
