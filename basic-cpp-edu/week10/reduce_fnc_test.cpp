#include <string>
#include <iostream>

using namespace std;

class Circle
{
public:
    int radius;
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    //위 두개를 간소화 함수로 줄일 수 있다!
    //Circle(int r = 1) { radius = r; } -> 기본 매개변수와 중복 함수는 동시 사용 불가능

    //생성자 함수 간소화
    Circle(int a = 100){
        radius = a;
    }
};
int main()
{
    
    return 0;
}