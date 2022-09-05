//initializer_list와 uniform initialization 그리고 생성자 호출 초기화를 공부하자
//그리고 initializer의 문제점도 짚어 보자!
#include <iostream>
#include <initializer_list>  //이 헤더에 정의!
#include <typeinfo>

//1. initializer_list 문제점!
class A{
    public:
        A(){
            std::cout << "call default constructor!\n";
        }
        A(int a, double b){
            std::cout << "call initializer (int a, double b)!\n";
        }
        A(std::initializer_list<int> a){
            std::cout << "call initializer_list()!\n";
        }
};

class B{
    public:
        B(){
            std::cout << "기본 생성자!\n";
        }
        B(int a){
            std::cout << "두번째 생성자!\n";
        }
};

int main(){
    /*
    //1번! initializer_list 문제점!
    A a;        //일반 객체 생성
    A b{1000};  //initializer_list 생성자 호출
    // c{1, 3.0};//에러!!! -> CPP는 생성자에 initializer_list를 인자로 받는 생성자를 최우선적으로 고려! 
    A d(1, 1.57); //정상 작동!
    A e({});    //initializer_list 생성자 호출
    A f();      //함수 호출 -> 생성자 호출X
    */

    /*
    //2번! uniform initialization의 다양한 케이스!
    // '{}'를 이용하여 생성자 호출 -> 암시적 형변환 절대 불가능 : 에러 발생
    B w;      //선언 -> 생성자 호출 >>> Pseudo in java : B w = new B()
    // >>> 기본생성자
    B x();    //B를 리턴하는 함수 x() 호출! -> cpp는 함수로 보이는 건 모두 함수로 컴파일!
    // >>> 
    B y(10);  //매개변수 있는 생성자 호출 >>> Pseudo in java : B y = new B(10)
    // >>> 두번째 생성자
    B z{};
    // >>> 기본 생성자
    B q = {100};
    // >>> 두번재 생성자
    // B e = {1.2}; //에러! 형변환은 허용하지 않는다!
    */

    /*
    //3번! uniform initialization 변수 초기화!
    int a{1}; //int a = 1; 형변환 허용 X
    //double b{1}; //이건 왜될까??
    //int b = {1.4}; //에러!
    
    std::cout << "a의 값 : "<< typeid(a).name() <<  "형, " << a << std::endl;
    */

    //4번! cpp17 이후 auto와 std::initializer_list<T>의 상관 관계
    /*
    auto a = {n1,n2,n3} or {n1} -> auto == std::initializer_list<T>
    aubo b{n1} -> auto == int
    auto c{n1,n2} -> 에러!

    +++
    auto list = {"a", "b", "c"} -> initializer_list<std::string>이 아닌 initializer_list<const char*>
    */
    auto a = {1};    
    auto b = {1, 2};  
    auto c{1};
    //auto d{1, 2}; //에러! 
    auto arr = {"a", "b", "c"};

    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(c).name() << std::endl;
    std::cout << typeid(arr).name() << std::endl;
    // >>> St16initializer_listIPKcE
    //해석 IPKc -> 배열 : const * char 을 의미
}