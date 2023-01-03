#include <iostream>
#include <string>

using namespace std;

//���ø� static ����
template <typename T> class staticTest{
public:
    inline static T a;
    static T b;
    static void print(T);
};
template<typename T> T staticTest<T>::b = 100; //inline ���x �ʱ�ȭ
template<typename T> void staticTest<T>::print (T name){
    cout << name << " : " << a << ", " << b << "\n";
}

//���ø� Ŭ���� Ư��ȭ
template<> class staticTest<char>{  //�ڷ��� ���
public:
    inline static char a = 'f';
    void print(){
        cout << "�� �� �޶�" << a << '\n';
    }
};

int main(){
    staticTest<int> t1{};
    t1.print(999999);

    staticTest<char> t2;
    t2.print();
}