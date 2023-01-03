#include <iostream>
#include <string>

using namespace std;

//템플릿 static 변수
template <typename T> class staticTest{
public:
    inline static T a;
    static T b;
    static void print(T);
};
template<typename T> T staticTest<T>::b = 100; //inline 사용x 초기화
template<typename T> void staticTest<T>::print (T name){
    cout << name << " : " << a << ", " << b << "\n";
}

//템플릿 클래스 특수화
template<> class staticTest<char>{  //자료형 명시
public:
    inline static char a = 'f';
    void print(){
        cout << "난 좀 달라" << a << '\n';
    }
};

int main(){
    staticTest<int> t1{};
    t1.print(999999);

    staticTest<char> t2;
    t2.print();
}