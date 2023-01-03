//함수 호출시 파라미터에 따른 차이 TEST (객체 전달시 복사 유형 차이를 알아보자)
#include <iostream>
#include <string>

using namespace std;
class T{
    public :
        int a;
        T(){
            a=10;
            cout << "생성자 호출!\n";
        };
        ~T(){
            cout << a << " : 소멸자 호출!\n";
        };
        T(T &){
            cout << "복사 생성자 호출!\n";
        };
};
//객체는 복사 -> 생성자 호출x 복사 생성자 호출!
//복사 생성자 구현x -> 생성자는 한번만 호출 소멸자는 2번 호출 -> 비대칭
void F(T t){
    t.a += 100;
}
//call by addr -> 단순 주소를 넘기기 때문에 값 복사 x
void F(T*t){
    (*t).a++;
    cout <<"주소호출!\n";
}
int main(){
    T t1{};
    F(t1);
    cout << t1.a << endl;
    cout << "\n======================\n\n";
    T t2{};
    F(&t2);
    cout << t2.a << endl;
}