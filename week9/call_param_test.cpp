//�Լ� ȣ��� �Ķ���Ϳ� ���� ���� TEST (��ü ���޽� ���� ���� ���̸� �˾ƺ���)
#include <iostream>
#include <string>

using namespace std;
class T{
    public :
        int a;
        T(){
            a=10;
            cout << "������ ȣ��!\n";
        };
        ~T(){
            cout << a << " : �Ҹ��� ȣ��!\n";
        };
        T(T &){
            cout << "���� ������ ȣ��!\n";
        };
};
//��ü�� ���� -> ������ ȣ��x ���� ������ ȣ��!
//���� ������ ����x -> �����ڴ� �ѹ��� ȣ�� �Ҹ��ڴ� 2�� ȣ�� -> ���Ī
void F(T t){
    t.a += 100;
}
//call by addr -> �ܼ� �ּҸ� �ѱ�� ������ �� ���� x
void F(T*t){
    (*t).a++;
    cout <<"�ּ�ȣ��!\n";
}
int main(){
    T t1{};
    F(t1);
    cout << t1.a << endl;
    cout << "\n======================\n\n";
    T t2{};
    F(&t2);
    cout << t2.a << endl;
}