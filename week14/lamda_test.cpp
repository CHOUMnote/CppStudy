#include <iostream>
#include <string>

using namespace std;

//c++ 람다식(익명함수)
//[]()->{}
//캡쳐리스트, 매개변수, 리턴타입(void는 생략가능), 코드구현
int main(){
    string alpha = "TEST"; 
    [](int a, int b)->int{return a+b;}; //람다식 선언
    [alpha](int a){cout << alpha << " : " << a << endl;}(7777); //람다 함수 선언 및 즉시 실행

    auto lamb = [](string a, string b){cout << a << " " << b << endl;}; //람다식 형식은 컴파일러가 알고있기 때문에 개발자는 알 수 없다. -> auto
    lamb("Hello"s, "world"s); //함수 호출

    int val = 999;
    int *p = &val;
    auto changeP = [p](){*p = 1267;};
    changeP();
    cout << "포인터를 갖는 람다식 : " << *p << endl;
    auto changeRef = [&val](int i){val+=i;};
    changeRef(3);
    cout << "참조를 갖는 람다식" << val << endl;
}