#include <iostream>
#include <vector>
#include <string>

using namespace std;

//1. L값 : 변수처럼 이름과 주소를 갖는다.(지속) -> int a...
//   R값 : 리터럴, 임시 객체처럼 더 이상 존재하지 않는 임시적 객체 -> "~~",1 ... 
//2. L값 참조 -> &, R값 참조 &&
//   불필요한 복사 및 오버헤드를 줄인다.
//3. 메모리 소유권 전환 -> 메모리 누수 및 Dangling Pointer 방지
//   이를 위해 이동생성, 이동대입 연산자는 R값 참조 사용한다. -> 원본 객체 삭제 시 유용

void Value(int& a){
    cout << "왼쪽 값 : " << a << endl;
};
void Value(int&& a){
    //이때 a는 L값
    cout << "오른쪽 값 : " << a << endl;
}
int main(){
    int num = 10;

    Value(num);
    Value(999);
    Value(move(num));   //std::move() -> 이동의 개념이 아닌 단순히 L값을 R값으로 으로 변환
    
    return 0;
}