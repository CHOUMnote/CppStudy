#include <iostream>
#include <string>

using namespace std;

/*
프렌드 함수?
클래스의 멤버 함수가 아닌 외부 함수 - 상속 x

1. 외부(전역) 함수 또는 다른 클래스의 멤버함수들에 대해
클래스의 모든 멤버 접근 권한 부여 - private 등... 접근 가능
프렌드 선언 갯수 제한 x
2. 클래스 멤버로는 선언하기 무리가 있을때 선언
ex) 연산자 중복 (거의 유일)
*/

//참조 오류 방지 선 선언
class Main;

class Manager
{ // RectManager 클래스 선언
public:
    bool equals(Main, Main);
    void print(Main, Main);
};

class Main
{ // Rect 클래스 선언
    int a, b;

public:
    Main(int i, int j)
    {
        this->a = i;
        this->b = j;
    }
    friend bool equals(Main, Main);          //외부함수 프렌드 선언
    friend bool Manager::equals(Main, Main); //다른 클래스의 멤버 함수 프렌드 선언
    friend Manager;                          //다른 클래스 전체를 프렌드 선언
};

// 반드시 모두 선언 이후 구현!
// incomplete 에러 조심!
void Manager::print(Main r, Main s)
{
    cout << r.a << " " << r.b << endl;
    cout << s.a << " " << s.b << endl;
};
bool Manager::equals(Main r, Main s)
{
    if (r.a == s.a && r.b == s.b)
        return true;
    else
        return false;
};

bool equals(Main x, Main y) //외부함수
{
    if (x.a == y.a && x.b == y.b) //프렌드로 선언 안하면 접근 권한 오류
        return true;
    else
        return false;
}

int main()
{
    Main a(3, 4), b(3, 4);
    cout << "===외부함수 프렌드 선언===\n";
    if (equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    cout << "===클래스 함수 프렌드 선언===\n";
    Manager m{};
    if (m.equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    cout << "===클래스 전체 프렌드 선언===\n";
    m.print(a,b);

    return 0;
}