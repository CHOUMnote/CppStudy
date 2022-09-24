#include <iostream>

//cpp class는 선언과 구현을 따로 구분지어 사용한다
//선언과 동시에 구현,초기화도 가능하다.
class Circle{
    //선언부
    public :     
        int radius;
        //함수는 원형만 표기! -> 컴파일시 이것만 필요!
        double GetArea();   //함수 원형 선언!

        //생성자
        Circle();               //디폴트 생성자
        Circle(int);            //매개변수 있는 생선자
        Circle(const Circle&);  //복사생성자
};//<-';' 붙음!

Circle::Circle() : Circle(9){} //위임 생성자
Circle::Circle(int r):radius{r}{
    //constructor initialization 사용 초기화
    //radius = r or radius(r)
    //이는 나열한 순서대로 초기화가 아닌 클래스 정의에 의한 순서로 초기화!
}
Circle::Circle(const Circle& cr){
    radius = cr.radius;
}

class Number{
    public:
        int a;
        int b;
        Number() = default; //구형 안해도 됨
        Number(int,int);
};

//구현부
double Circle::GetArea(){       //동일 함수이름 중복 방지!
    return 3.14 * radius * radius;
}

Number::Number(int x, int y) : a{x},b{y}{} 

int main(){
    Circle a{}; //기본생성자

    std::cout << a.radius << std::endl;
    std::cout << a.GetArea() << std::endl;

    Number b{10,20};   //기본생성자 호출!
    std::cout<<b.a << std::endl;
}