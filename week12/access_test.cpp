#include <iostream>
#include <string>

using namespace std;
//���� ������ : �ٸ� ���� �Ȱ���.
/*
��ӽ� ���� �������� ��� Ư����
1. public -> �⺻ Ŭ������ ���� ���� ������ ����
2. protected -> public protected�� protected�� ���
3. private -> ��� ����� private�� ���
�⺻ ���� ������ : private
*/

class A
{
private:
    int a = 0;

protected:
    int b = 1;

public:
    int c = 2;
};

class T1 : A// private
{ 
    // int t1=a;
public:
    int t2 = b;
    int t3 = c;
};
class T2 : protected A
{
    // int t1=a;
public:
    int t2 = b;
    int t3 = c;
};
class T3 : public A
{
    // int t1=a;
public:
    int t2 = b;
    int t3 = c;
};
class TT0 : private T1{
    int tt0 = t2;
    //int tt1 = a; A�� private�� ������ �Ұ���
    //int tt2 = c; T1�� privte�� ����߱� ������ c�� private��
};
class TT1 : private T3{
    int tt0 = t2;
    //int tt1 = a; A�� private�� ������ �Ұ���
    int tt2 = c; //T3�� public�̶� ��� ��
};
int main(){
    T1 t1;
    T2 t2;
    T3 t3;

    //1. ��� private�� ���
    // cout << t1.a;
    // cout << t1.b;
    // cout << t1.c;

    //2. ��� protected�� private�� ��� -> �ܺ� �Լ� ���� x
    // cout << t2.a;
    // cout << t2.b;
    // cout << t2.c;
    
    //3. ��� �״�� ���
    // cout << t3.a;    private
    // cout << t3.b;    protected
    cout << t3.c;   //public
}