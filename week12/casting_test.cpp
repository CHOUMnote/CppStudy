#include <iostream>
#include <string>

using namespace std;
/*
�ڽ� - �θ� ���� ����ȯ - Ŭ���� �����Ϳ� ����
1. �� ĳ���� : �ڽ�->�θ�� ��ȯ
2. �ٿ� ĳ���� : �θ�->�ڽ� ��ȯ �� ������� ����
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
    Point *bp = ap; //�ڽ�->�θ� ��ĳ����
    //ap�� a�� ��� public ���� ����
    //bp�� �θ� Ŭ������ public ������ ���� ����

    cout << "===��ĳ����===\n";
    ap->set(3,4);
    bp->showPoint();
    ap->setColor("Red");
    ap->showColorPoint();
    //bp->showColorPoint(); -> �ڽ� Ŭ������ ���

    cout << "\n";

    cout << "===�ٿ�ĳ����===\n";
    bp->set(10,23);
    bp->showPoint();
    ap = (ColorPoint*)bp;   //�ٿ� ĳ����;
    ap->setColor("Blue");
    ap->showColorPoint();
    //bp�� �ٿ� ĳ���� ���� �̹� ��ĳ������ ���־��⿡ �����ϴ�.

    cout << "\n";

    cout << "===�߸��� �ٿ�ĳ����===\n";
    ColorPoint t;
    ColorPoint *tp = &t;
    Point b;
    Point *tp2 = tp;    //�� ĳ����
    tp2=&b;
    ColorPoint *p = (ColorPoint*)tp2; //�ٿ� ĳ����

    p->set(1,2);
    p->showPoint();
    //Ÿ���� ColorPoint���� �� �� ���� �޼ҵ� ����
    p->setColor("Black");
    p->showColorPoint(); //tp2�� �θ� Ŭ���� ��� �ȵȴ�. ���� �ڽ��� ��ĳ���� �� �ڽ� ��ü�����Ѵ�.

    cout << "������ ����" << endl;
    return 0;
}