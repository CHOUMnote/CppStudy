#include <string>
#include <iostream>

using namespace std;

//디폴트 매개 - 특정 함수에 매개변수가 넘어오지 않으면 디폴드로 설정한 매개변수가 대입됨
//파이썬과 같은 규칙 적용

void print(int a, string name="hokimji"){
    cout << a << " : " << name << endl;
}

//디폴트 매개변수 - 오른쪽부터 채워 나간다. 아니면 에러
//void error(int a, int b=1, int c) { }; 컴파일 에러!
//void error(int a=0, int b, int c) { }; 컴파일 에러!
void error(int a=0, int b=1, int c=2) { }; //컴파일 성공!
int main(){
    print(10); //print(10,"hokimji")랑 같다.
    print(20, "Hello"); //디폴트 매개변수 대신 Hello가 대입됨
    //print(); 에러 - int a 매개변수를 채워야함
    //print("AAA"); 에러 - 첫번째 매개변수에 맞지않는 타입 
    return 0;
}