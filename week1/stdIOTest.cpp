#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    int a;
    bool b;
    // cout << "여러 진법으로 정수 출력하기"<<endl;
    // cout << "10진수 입력 : ";
    // cin >> a;
    
    // cout << "8진수 : " << oct << a << endl;
    // cout << "16진수 : " << hex << a << endl;

    // cout << "불 자료형 출력" << endl;
    // cout << "불 자료형 입력 : ";
    // cin >> boolalpha >> b;
    // cout  << b << boolalpha << b;

    cout << "고정 소수점 출력" << endl;
    cout << fixed << setprecision(3) <<1237.3417 << endl;
    return 0;
}