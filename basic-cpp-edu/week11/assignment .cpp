#include <iostream>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

/*
대입 연산자 - operator=
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
    Person &operator=(const Person &person);    //대입 연산자 함수
    Person &operator=(const Person &&person); //이동 대입 연산자
    friend void swap_person(Person &, Person &) noexcept;
};
Person::Person(int id, const char *name)
{
    this->id = id;
    int len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}
// Person &Person::operator=(const Person &rhs) //복사중 예외가 발생시 문제가 생긴다!
// {
//     if (this == &rhs) //자기 자신을 대입
//         return *this;
//     delete name; //기존 메모리 해제
//     name = nullptr;
//     //메모리 새로 할당
//     int len = strlen(rhs.name);
//     name = new char[len + 1];
//     //데이터 복사
//     id = rhs.id;
//     strcpy(name, rhs.name);
//     return *this;
// }

Person &Person::operator=(const Person &person)
{
    if (this == &person) //자기 자신을 대입
        return *this;
    cout << "대입 연산자 실행\n";
    Person temp{person};      //임시 객체 생성
    swap_person(*this, temp); //현재 객체를 생성된 임시 복사본으로 교체
    //임시 객체로 안전하게 스왑
    return *this;
}
Person &Person::operator=(const Person &&person)
{
    cout << "이동 대입 연산자 실행\n";
    Person temp(person);
    swap_person(*this, temp);
    return *this;
}

// utility 라이브러리에서 제공하는 swap() 함수 이용으로 간단,안전하게 대입
//추후 관리시 swap_person()만 수정하면 됨
void swap_person(Person &first, Person &second) noexcept
{
    swap(first.id, second.id);
    swap(first.name, second.name);
}

Person createObject() {
    return Person(10, "HHH"); //rvalue(값) 반환
}

int main()
{
    Person father(1, "Kitae");
    Person daughter(2, "Grace");
    father = daughter; //대입 연산자 함수 호출
    father.show();
    daughter.show();

    Person p1(1, "software");
    p1 = createObject(); //이동 대입 연산자 호출
    //p1.operator=(createObject());
    p1.show();
    return 0;
}
