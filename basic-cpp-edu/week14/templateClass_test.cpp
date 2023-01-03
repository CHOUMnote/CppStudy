#include <iostream>
#include <string>

using namespace std;
/*
템플릿 클래스
템플릿 클래스 선언, 구현 모두 템플릿 매개변수가 있어야한다.
템플릿 클래스 사용시 템플릿 매개변수에 구체적 타입 명시해야한다.
*/

template <typename T> class Stack{  //대충 스택
    T* head;
    int idx;
public:
    Stack(){
        head = new T[10];
        idx=0;
    }
    void push(const T&);
    T& pop();
    ~Stack(){ delete [] head; }
};
template <typename T> void Stack<T>:: push(const T& a){   //구현시 템플릿, 템플릿 클래스 범위 지정 필요
    head[idx]=a;
    idx = ((idx+1)%10);
}
template <typename T> T& Stack<T>::pop(){
    return head[idx-- - 1];
}

template <typename T1, typename T2> class A{    //템플릿 매개변수가 2개
public:
    T1 x;
    T2 y;
    A(T1 a,T2 b):x{a}, y{b}{}
    void print();
};
template <typename T1, typename T2> void A<T1,T2>::print(){
    cout << x << " " << y << '\n';
}

int main(){
    Stack<int> istack{}; //타입 명시
    istack.push(5);
    Stack<char> cstack{};
    cstack.push('a');
    cout << istack.pop() << " " << cstack.pop(); 
    
    cout << "\n===================\n";

    A <int,string> a{100,"imstring"s};
    a.print();
}