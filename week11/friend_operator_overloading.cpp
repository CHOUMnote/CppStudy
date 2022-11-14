#include <iostream>
#include <string>

using namespace std;

//외부 함수 프랜드를 이용한 연산자 오버로딩
// fnc(T1, T2) -> T1은 왼쪽, T2는 오른쪽 연산자를 뜻함
// fnc(T1, [int]) -> 단항 연산, int는 전위 연산과 후위 연산 구분시 사용

class Power
{
    int kick, punch;

public:
    Power(int a=0, int b=0){
        kick=a;
        punch=b;
    }
    void show(string obj);
    // 프렌드 선언
    friend Power operator+(const Power &op1, const Power &op2);
    friend Power &operator++(Power &op);       //전위 연산
    friend Power operator++(Power &op, int); //후위 연산
};
void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(const Power &op1, const Power &op2)
{
    Power tmp;                         //임시 객체 생성
    tmp.kick = op1.kick + op2.kick;    // kick 더하기
    tmp.punch = op1.punch + op2.punch; // punch 더하기
    return tmp;                        //임시 객체 리턴
}

Power &operator++(Power &op) //전위 연산
{
    op.kick++;
    op.punch++;
    return op; //연산 결과 리턴
}
Power operator++(Power &op, int) //후위 연산
{
    Power tmp = op; //변경하기 전의 op 상태 저장
    op.kick++;
    op.punch++;
    return tmp; //변경 이전의 op 리턴
}

int main()
{
    Power a(3, 5), b;
    b = operator++(a); //전위 ++ 연산자
    b = operator++(a,0); //후위 ++ 연산자
    a.show("a");
    b.show("b");
}