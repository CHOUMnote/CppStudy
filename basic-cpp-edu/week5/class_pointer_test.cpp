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
    //??? ?????? ????
    Circle a{};
    Circle* pa = &a;
    cout << pa->a << endl;
    cout << sizeof(a) << " " << sizeof(pa) << endl;
    //???? 8

    //??? ?עק
    Circle b[2]; //?? ????? ????? ?????? ???
//    Circle c[3] = {1,2};//????? ?????? ???
    Circle c[3] = {Circle{1},Circle{2}};//????? ?????? ???

    cout << "b??? \n";
    for(Circle i : b) cout << i.a << endl;
    cout << "c??? \n";
    for(Circle i : c) cout << i.a << endl;
    cout << endl << endl;

    //n???? ?עק

    Circle d[3][3]; // ?????? {{{1,2,3},
                    //          {4,5,6}}
}