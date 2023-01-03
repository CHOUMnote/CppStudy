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
Circle::Circle() : Circle("디폴트"){};
Circle::Circle(string b) : a{b} {};

int main()
{
    //동적 배열 생성
    int *a = new int[10]{1, 2, 3, 4};
    cout << "a의 포인팅 : " << *a << endl;
    cout << endl;

    //객체배열 동적 생성
    Circle *b = new Circle[4]{{}, Circle{"가"}, Circle{"A"}}; //유티폼 초기화 가능
    for (int i = 0; i < 4; i++)
        cout << b[i].a << endl;
    cout << endl;
    ;

    //포인터 배열
    Circle *c[3] = {new Circle, new Circle, new Circle{"동적생성!"}};
    int size = sizeof(c) / sizeof(c[0]);
    cout << "배열의 사이즈 : " << size << endl;
    for (int i = 0; i < size; i++)
        cout << (*(*(c+i))).a << endl;
        //(*(c+i))->a
    cout << endl;
    ;
}