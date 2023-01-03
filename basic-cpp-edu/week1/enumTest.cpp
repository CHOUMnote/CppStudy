#include <iostream>
using namespace std;

//enum class와 명시적 형변환 테스트
//1. 형변환시 의도치 않은 오류에 주의 해야한다.
//2. enum class를 사용하면 c에 enum과 달리 다른 스페이스를 사용해서 비교 등 예상치 못한 에러를 피할 수 있다. 
//기존 c enum에 비해 강력한 에러체크 -> 형식, 범위
//class를 붙이지만 class는 아니다. 단순 집합
int main(){
    enum class Color {Blue=1, Red, Green, other=100};

    Color color = Color::Blue;
    cout << "enum class 정수 변환 : " << static_cast<int>(color) << endl;
    cout << static_cast<int>(Color::Blue) << endl;
    cout << static_cast<int>(Color::Red) << endl;
    cout << static_cast<int>(Color::Green) << endl;
    cout << static_cast<char>(Color::other) << endl;

    return 0;
}
