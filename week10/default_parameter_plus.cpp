#include <string>
#include <iostream>

using namespace std;

//기본 매개변수가 있는 함수 원형 선언과 구현

void msg1(int=5); //디폴트 매개변수 선언
//void msg1(int, string="");오류 오버로딩 실패 -> 모호한 선언
//ex) msg(10) -> 뭘 호출하는지 모름
void msg2(int, string="msg"); //디폴트 매개변수 선언
void msg1(int a) {
    for(int i=0; i<a; i++)
        cout << '*';
    cout << endl;
}
void msg2(int id, string text) {
    cout << id << ' ' << text << endl;
}

int main(){
    msg1(); //msg(5)
    msg1(10);

    msg2(10); //msg(10, "")
    msg2(10, "Hello");

    return 0;
}