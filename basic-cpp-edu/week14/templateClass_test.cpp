#include <iostream>
#include <string>

using namespace std;
/*
���ø� Ŭ����
���ø� Ŭ���� ����, ���� ��� ���ø� �Ű������� �־���Ѵ�.
���ø� Ŭ���� ���� ���ø� �Ű������� ��ü�� Ÿ�� ����ؾ��Ѵ�.
*/

template <typename T> class Stack{  //���� ����
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
template <typename T> void Stack<T>:: push(const T& a){   //������ ���ø�, ���ø� Ŭ���� ���� ���� �ʿ�
    head[idx]=a;
    idx = ((idx+1)%10);
}
template <typename T> T& Stack<T>::pop(){
    return head[idx-- - 1];
}

template <typename T1, typename T2> class A{    //���ø� �Ű������� 2��
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
    Stack<int> istack{}; //Ÿ�� ���
    istack.push(5);
    Stack<char> cstack{};
    cstack.push('a');
    cout << istack.pop() << " " << cstack.pop(); 
    
    cout << "\n===================\n";

    A <int,string> a{100,"imstring"s};
    a.print();
}