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
    cout << "생성자 실행\n";
};
Person::Person(const Person &p) : id{p.id}, name{p.name}
{
    cout << "복사 생성자 실행\n";
};
Person::Person(Person &&p) noexcept : id{p.id}, name{p.name}
{
    cout << "이동 생성자 실행 " << endl;
    p.name.clear();
    p.id = 0;
}
Person::~Person(){
    cout << "소멸자 실행\n";
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
    //push_back은 R값 첨가시 마다 값의 이동 존재
    //emplace_back은 안에서 생성후 뒤에 갖다 붙임
    cout << "=1==========" << endl;
    vp.push_back(Person(1, "python")); //생성자 두번 실행
    cout << "=2==========" << endl;
    vp.push_back(Person(2, "java")); //이동
    cout << "=3==========" << endl;
    vp.emplace_back(3, "c");    //push back 했던거 최초 이동
    cout << "=4==========" << endl;
    vp.emplace_back(4, "c++");  //두번째 부터 임시 객체 생성x
    // vector<Person*> vp; //이동 생성자 없으면 포인터 사용
    // vp.push_back(new Person(3, “c”))
    for (auto &tmp : vp)
        tmp.show();
    cout << "=5==========" << endl;
    // rvalue참조를 매개변수로 갖는 함수 호출
    disPlay(Person(5, "web"));
    return 0;
}