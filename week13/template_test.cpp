#include <string>
#include <iostream>

using namespace std;

/*
템플릿? 일반화 프로그래밍(c#, 자바의 제네릭하고 똑같음)
STL -> 템플릿 클래스들 모음 (자료구조 포함!)

template키워드로 선언 및 구현
template <class T>, <typename T>로 선언
n개의 제네릭 사용 : template <typename T1, typename T2...>
*/

class Test{
    string s;
public:
    Test(string a):s{a}{};
    void print(){
        cout << s << endl;
    }
};
//제네릭 함수
namespace my{
    template <typename Name>
    void print(Name n){ //T&, T*등 자료형 추가 가능 (참조, 포인터)
        cout << "이름은 " << n << endl;
    }
    template <typename T>
    void swap(T&a, T&b){ //T&, T*등 자료형 추가 가능 (참조, 포인터)
        T t = a;
        a = b;
        b = t;
    }
}

int main(){
    //제네릭 함수 호출
    my::print("kimjiho");
    my::print(123);
    my::print(123.12314);
    string a,b = "김지호";
    a = "김준호";
    my::swap(a,b);
    cout << a << " : " << b << endl << endl;

    Test s1{"가나다"};
    Test s2{"123"};
    my::swap(s1,s2);
    s1.print();
    s2.print();
    cout << endl;

    //명시적 자료형 결정
    my::print<int>(1);
    my::print<int>(1.2f);   //묵시적 형변환 -> int n=1.2
    
}