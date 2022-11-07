#include <string>
#include <iostream>

using namespace std;

//메소드 오버라이딩 - 메소드 중복
//이름 동일, 중복 함수들 내 변수 타입 또는 개수가 달라야함(생성자 함수 포함)
//리턴 타입은 함수 중복과 무관!
void F(int){
    cout << "1번 메소드 \n";
}
//int F(int){    cout << "4번 메소드 \n";} 
//리턴 타입은 함수 중복과 무관! 따라서 1번 메소드와 구분 되지 않음
//따라서 컴파일 에러
void F(double){
    cout << "2번 메소드 \n";
}

void F(float){
    cout << "3번 메소드 \n";
}

/*
int FF(int, int){};
double FF(int, int){};
이름, 인자가 같음 - 리턴 타입만 다름 
이는 중복 함수가 아니라 단순 오류
*/
int main(){
    //만약 1번 메소드 부재시 double, float중 어떤걸로 형변환 해야하는지 모호하다 -> 컴파일 에러
    F(1);

    F(1.0);
    F(1.0f);
    
    return 0;
}