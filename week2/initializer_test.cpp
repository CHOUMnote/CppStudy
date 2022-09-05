//initializer_list�� uniform initialization �׸��� ������ ȣ�� �ʱ�ȭ�� ��������
//�׸��� initializer�� �������� ¤�� ����!
#include <iostream>
#include <initializer_list>  //�� ����� ����!
#include <typeinfo>

//1. initializer_list ������!
class A{
    public:
        A(){
            std::cout << "call default constructor!\n";
        }
        A(int a, double b){
            std::cout << "call initializer (int a, double b)!\n";
        }
        A(std::initializer_list<int> a){
            std::cout << "call initializer_list()!\n";
        }
};

class B{
    public:
        B(){
            std::cout << "�⺻ ������!\n";
        }
        B(int a){
            std::cout << "�ι�° ������!\n";
        }
};

int main(){
    /*
    //1��! initializer_list ������!
    A a;        //�Ϲ� ��ü ����
    A b{1000};  //initializer_list ������ ȣ��
    // c{1, 3.0};//����!!! -> CPP�� �����ڿ� initializer_list�� ���ڷ� �޴� �����ڸ� �ֿ켱������ ���! 
    A d(1, 1.57); //���� �۵�!
    A e({});    //initializer_list ������ ȣ��
    A f();      //�Լ� ȣ�� -> ������ ȣ��X
    */

    /*
    //2��! uniform initialization�� �پ��� ���̽�!
    // '{}'�� �̿��Ͽ� ������ ȣ�� -> �Ͻ��� ����ȯ ���� �Ұ��� : ���� �߻�
    B w;      //���� -> ������ ȣ�� >>> Pseudo in java : B w = new B()
    // >>> �⺻������
    B x();    //B�� �����ϴ� �Լ� x() ȣ��! -> cpp�� �Լ��� ���̴� �� ��� �Լ��� ������!
    // >>> 
    B y(10);  //�Ű����� �ִ� ������ ȣ�� >>> Pseudo in java : B y = new B(10)
    // >>> �ι�° ������
    B z{};
    // >>> �⺻ ������
    B q = {100};
    // >>> �ι��� ������
    // B e = {1.2}; //����! ����ȯ�� ������� �ʴ´�!
    */

    /*
    //3��! uniform initialization ���� �ʱ�ȭ!
    int a{1}; //int a = 1; ����ȯ ��� X
    //double b{1}; //�̰� �ֵɱ�??
    //int b = {1.4}; //����!
    
    std::cout << "a�� �� : "<< typeid(a).name() <<  "��, " << a << std::endl;
    */

    //4��! cpp17 ���� auto�� std::initializer_list<T>�� ��� ����
    /*
    auto a = {n1,n2,n3} or {n1} -> auto == std::initializer_list<T>
    aubo b{n1} -> auto == int
    auto c{n1,n2} -> ����!

    +++
    auto list = {"a", "b", "c"} -> initializer_list<std::string>�� �ƴ� initializer_list<const char*>
    */
    auto a = {1};    
    auto b = {1, 2};  
    auto c{1};
    //auto d{1, 2}; //����! 
    auto arr = {"a", "b", "c"};

    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(c).name() << std::endl;
    std::cout << typeid(arr).name() << std::endl;
    // >>> St16initializer_listIPKcE
    //�ؼ� IPKc -> �迭 : const * char �� �ǹ�
}