#include <iostream>
using namespace std;

int refTest(const int &a, const int &b){
    return a+b;
}
int main(){
    //참조형 변수는 선언시 초기화
    //대상의 메모리 공간을 공유한다. 따라서 상수에 레퍼런스는 불가능
    //const var 참조는 const &ref 사용

    int a = 1000;
    int &refa = a;
    //int &refa = 1000; 컴파일 에러!
    const int aa = 1;
    const int &refaa = aa;
/////////////////////////////////////////////////////////
    //포인터변수 참조
    // num <- ptr, num <- pref
    int num = 12;
    int *ptr = &num;
    int &ref = num;
    int*(&pref) = ptr;
    int &vref = *pref;

    cout << num << " " << *ptr << " " << *pref << " " << vref << endl;
    vref += 1;
    cout << num << " " << *ptr << " " << *pref << " " << vref << endl;

    cout << "매개변수로는 상수를 받을 수 있다!!!" << refTest(1000,num);
}