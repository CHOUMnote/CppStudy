#include <iostream>
#include <vector>
using namespace std;
class Person
{
    string name;
    int id;

public:
    Person(int id, string name);
    Person(const Person &p);
    Person(Person &&p) noexcept;
    ~Person();
    void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, string name) : id{id}, name{name}
{
    cout << "������ ����\n";
};
Person::Person(const Person &p) : id{p.id}, name{p.name}
{
    cout << "���� ������ ����\n";
};
Person::Person(Person &&p) noexcept : id{p.id}, name{p.name}
{
    cout << "�̵� ������ ���� " << endl;
    p.name.clear();
    p.id = 0;
}
Person::~Person(){
    cout << "�Ҹ��� ����\n";
}
void disPlay(Person &&per)
{
    per.show();
}

int main()
{
    vector<Person> vp; //
    // Person temp{0,"Rust"};
    // vp.push_back(temp);
    //push_back�� R�� ÷���� ���� ���� �̵� ����
    //emplace_back�� �ȿ��� ������ �ڿ� ���� ����
    cout << "=1==========" << endl;
    vp.push_back(Person(1, "python")); //������ �ι� ����
    cout << "=2==========" << endl;
    vp.push_back(Person(2, "java")); //�̵�
    cout << "=3==========" << endl;
    vp.emplace_back(3, "c");    //push back �ߴ��� ���� �̵�
    cout << "=4==========" << endl;
    vp.emplace_back(4, "c++");  //�ι�° ���� �ӽ� ��ü ����x
    // vector<Person*> vp; //�̵� ������ ������ ������ ���
    // vp.push_back(new Person(3, ��c��))
    for (auto &tmp : vp)
        tmp.show();
    cout << "=5==========" << endl;
    // rvalue������ �Ű������� ���� �Լ� ȣ��
    disPlay(Person(5, "web"));
    return 0;
}