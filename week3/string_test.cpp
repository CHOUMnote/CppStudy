#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo>

using namespace std;

int main(){
    //1.cin 과 get line
    /*
    char a[30];
    std::string str;

    std::cin >> a;
    getline(std::cin, str); //(입력 스트림, 받은 주소, [특정 문자에서 입력 중지])
    //>>> 만약 abc de f 입력시 cin에서 abc 이후 입력 스트림에 \n이 존재 따라서 " de f"자동 입력

    for(char i:a)
        std::cout << i;
    std::cout << std::endl;
    std::cout << str << "\n";
    */

    //2.string 정의 방법
    string a = "i am string";
    string b("string!");
    auto c{"ABC!"s};
    auto d{"ABC!"};

    cout<< a << endl;
    cout<< b << endl;
    cout<< c << endl;
    cout<< d << endl;
    cout<< b[1] << endl;
    cout<< boolalpha << (a==b) <<endl;
    cout<< boolalpha << (c==d) <<endl<<endl;

    cout << "c의 타입 : " << typeid(c).name()<< endl;
    cout << "d의 타입 : " << typeid(d).name()<< endl;

    cout << "지금까지 " + b + "을 알아봤습니다!";
    return 0;
}