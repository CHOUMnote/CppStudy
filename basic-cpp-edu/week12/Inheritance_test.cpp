#include <iostream>
#include <string>

using namespace std;
/*
상속
자식 : drived,sub class
부모 : base, super class
부모 클래스의 속성과 기능을 물려받는다.
추가로 자신만의 기능을 추가한다.

1. c++은 다중상속이 허용된다.
2. 선언은 : (접근제한자) (클래스 명)
*/
class Point
{
    int x, y; //한 점 (x,y) 좌표값
public:
    Point(int a=0, int b=0):x{a},y{b}{};
    void set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void showPoint()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class ColorPoint : public Point // Point를 상속
{
    string color; // 점의 색 표현
public:
    ColorPoint():Point{}{
        this->color="white";
    }
    void setColor(string color) { this->color = color; }
    void showColorPoint();
};
void ColorPoint::showColorPoint()
{
    cout << color << ":";
    showPoint(); //부모의 메소드 호출
    //cp.x;   //상속이여도 다른 언어처럼 private 접근 못함
}

int main()
{
    Point p;             // 부모
    ColorPoint cp;       // 자식
    p.showPoint();       // 부모 객체
    cp.showColorPoint(); // 자식 객체

    cout << "======\n";

    cp.set(3, 4);        // 부모 객체
    cp.setColor("Red");  // 자식 객체
    p.showPoint();       // 부모 객체
    cp.showColorPoint(); // 자식 객체

}
