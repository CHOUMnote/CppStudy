#include <iostream>
#include <string>

using namespace std;
/*
자식 - 부모 간의 형변환 - 클래스 포인터에 한정
1. 업 캐스팅 : 자식->부모로 변환
2. 다운 캐스팅 : 부모->자식 변환 단 제약사항 존재
*/
class Point
{
    int x, y;
private:
    int c=0;
public:
    Point(int a = 0, int b = 0) : x{a}, y{b} {};
    void set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void showPoint()
    {
        cout << "(" << x << "," << y << "," << c << ")" << endl;
    }
};
class ColorPoint : public Point
{
    string color;

public:
    ColorPoint() : Point{}
    {
        this->color = "white";
    }
    void setColor(string color) { this->color = color; }
    void showColorPoint();
};
void ColorPoint::showColorPoint()
{
    cout << color << ":";
    showPoint(); 
}

int main()
{
    ColorPoint a;
    ColorPoint *ap = &a;
    Point *bp = ap; //자식->부모 업캐스팅
    //ap는 a의 모든 public 접근 가능
    //bp는 부모 클래스의 public 변수만 접근 가능

    cout << "===업캐스팅===\n";
    ap->set(3,4);
    bp->showPoint();
    ap->setColor("Red");
    ap->showColorPoint();
    //bp->showColorPoint(); -> 자식 클래스의 멤버

    cout << "\n";

    cout << "===다운캐스팅===\n";
    bp->set(10,23);
    bp->showPoint();
    ap = (ColorPoint*)bp;   //다운 캐스팅;
    ap->setColor("Blue");
    ap->showColorPoint();
    //bp는 다운 캐스팅 전에 이미 업캐스팅이 돼있었기에 가능하다.

    cout << "\n";

    cout << "===잘못된 다운캐스팅===\n";
    ColorPoint t;
    ColorPoint *tp = &t;
    Point b;
    Point *tp2 = tp;    //업 캐스팅
    tp2=&b;
    ColorPoint *p = (ColorPoint*)tp2; //다운 캐스팅

    p->set(1,2);
    p->showPoint();
    //타입은 ColorPoint지만 알 수 없는 메소드 들임
    p->setColor("Black");
    p->showColorPoint(); //tp2가 부모 클래스 였어도 안된다. 현재 자신이 업캐스팅 된 자식 객체여야한다.

    cout << "비정상 종료" << endl;
    return 0;
}