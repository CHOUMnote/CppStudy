#include <iostream>
#include <string>

using namespace std;
//접근 지정자 : 다른 언어와 똑같다.
/*
상속시 접근 지정자의 경우 특별함
1. public -> 기본 클래스의 접근 지정 형식을 따름
2. protected -> public protected를 protected로 계승
3. private -> 모든 멤버를 private로 계승
기본 접근 지정자 : private
*/

class A
{
private:
    int a = 0;

protected:
    int b = 1;

public:
    int c = 2;
};

class T1 : A// private
{ 
    // int t1=a;
public:
    int t2 = b;
    int t3 = c;
};
class T2 : protected A
{
    // int t1=a;
public:
    int t2 = b;
    int t3 = c;
};
class T3 : public A
{
    // int t1=a;
public:
    int t2 = b;
    int t3 = c;
};
class TT0 : private T1{
    int tt0 = t2;
    //int tt1 = a; A가 private기 때문에 불가능
    //int tt2 = c; T1이 privte로 계승했기 때문에 c도 private임
};
class TT1 : private T3{
    int tt0 = t2;
    //int tt1 = a; A가 private기 때문에 불가능
    int tt2 = c; //T3이 public이라 계승 됨
};
int main(){
    T1 t1;
    T2 t2;
    T3 t3;

    //1. 모두 private로 계승
    // cout << t1.a;
    // cout << t1.b;
    // cout << t1.c;

    //2. 모두 protected와 private로 계승 -> 외부 함수 접근 x
    // cout << t2.a;
    // cout << t2.b;
    // cout << t2.c;
    
    //3. 모두 그대로 계승
    // cout << t3.a;    private
    // cout << t3.b;    protected
    cout << t3.c;   //public
}