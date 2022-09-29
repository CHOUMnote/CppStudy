#include <iostream>
//상수형 함수!
//멤버 변수에 대해 읽기 접근만 가능! 쓰기 불가능!
//상수형 함수는 상수형 함수만 호출 가능! -> 일반 함수로 변수에 대해 접근은 맥락상 일치하지 않음!
//(함수 선언) + const
//멤버 변수 쓰기 가능 옵션 추가 
//1. mutabla : ex)mutabla int a;  
//2. const_cast<>() : 참조 또는 포인터에 사용\

//선언과 동시에 구현은 인라인 함수!
//생성자를 포함 모든 함수는 인라인 가능!
class TestClass{
    public: 
        mutable int a;
        int b;
        TestClass() = default;
        void TestFnc() const{   //상수형 함수
            a = 10;
            //b = 10; 에러!
            std::cout << a << std::endl;//쓰기 접근 가능!
        }
};
void Test(const int& a){
    int &temp = const_cast<int&>(a);
    temp = 999;
}
//인라인 함수
//실행시간 빨라짐.(함수 호출 오버헤드 없음)
//짧은 코드에 한해 사용함
//프로그램 사이즈 증가
inline int odd(int x){  //인라인 함수 지정
    return x%2;
}
int main(){
    int t = 100;
    std::cout << "const_cast 사용 테스트" << std::endl;
    std::cout << t << std::endl;
    Test(t);
    std::cout << t << std::endl;

    TestClass test{1,2};
    test.TestFnc();

    if(odd(t)){ // equal - if(t%2)
        std::cout << "t는 홀수 입니다." << std::endl;
    }
}