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
    //객체 포인터 생성
    Circle a{};
    Circle* pa = &a;
    cout << pa->a << endl;
    cout << sizeof(a) << " " << sizeof(pa) << endl;
    //주소는 8

    //객체 배열
    Circle b[2]; //각 원소는 디폴트 생성자 호출
//    Circle c[3] = {1,2};//원하는 생성자 호출
    Circle c[3] = {Circle{1},Circle{2}};//원하는 생성자 호출

    cout << "b호출 \n";
    for(Circle i : b) cout << i.a << endl;
    cout << "c호출 \n";
    for(Circle i : c) cout << i.a << endl;
    cout << endl << endl;

    //n차원 배열

    Circle d[3][3]; // 초기화는 {{{1,2,3},
                    //          {4,5,6}}
}