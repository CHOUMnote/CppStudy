#include <string>
#include <iostream>
#include <cstring>

using namespace std;

/*
특수화?
string,int,double... 비교 및 논리연산 가능
cstirng 논리 연산 불가능
템플릿 특수화로 특정 자료형에 대한 에러 체크
단. 자료형 선언 및 원본 템플릿이 참조 가능해야한다.
*/

template <typename T>
T minf(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

//원본을 참조함 -> 인자가 & * const 등 다 맞춰야함
//다른건 오직 T의 자료형
template <>
const char *minf<const char *>(const char *a, const char *b)
{
    if (strcmp(a, b) < 0)
    {
        return a;
    }
    return b;
}

template <typename T>
T smaller(T first, T second)
{
    if (first < second)
    {
        return first;
    }
    return second;
}
//원본 템플릿을 반드시 참조할 수 있어야 한다 - 함수 템플릿 특수화
template <>
const char *smaller<const char *>(const char *first, const char *second)
{
    if (strcmp(first, second) < 0)
    {
        return first;
    }
    return second;
}

int main()
{
    string s1{"hell"};
    string s2{"world"};
    const char *a = "hello";
    const char *b = "world";

    cout << minf(a, b) << endl;
    cout << minf(s1, s2) << endl;
}