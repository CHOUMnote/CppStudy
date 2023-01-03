#include <string>
#include <iostream>

using namespace std;

template <typename T, int size>
decltype(auto) add(const T (&data)[size])   //&data T타입 배열의 대한 참조
{                 //T타입 배열에 대한 참조
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    return sum; //컴파일러가 함수의 리턴 타입을 자동으로 추론
}

template <typename T, int size = 10> //기본 매개변수 정의
decltype(auto) print(T a)
{
    for (int i = 0; i < size; i++)
        cout << i;
}

//템플릿 함수 반환 타입
//1. auto : 복사 후 반환 -> const & 없음
//2. decltype(auto) : const, & 반환
template<typename T>
decltype(auto) add(T a, T b){
    cout << "1번 템플릿 함수 : ";
    return a+b;
}
template <typename T>
decltype(auto) add(T a, T b, T c){
    cout << "2번 템플릿 함수 : ";
    return a+b+c;
}
int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    double d[6] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
    // 함수 템플릿을 호출할 때 컴파일러는 T의 구체적인 값 뿐만 아니라 size 값 추론
    cout << "sum of x[] = " << add(x) << endl; //또는 add<int>(x);
    cout << "sum of d[] = " << add(d) << endl;
    
    print<int>(1);
    cout << endl;
    print<int,5>(1);

    cout << endl;
    cout << add(1,2) << endl;
    cout << add(1,2,3) << endl;
}