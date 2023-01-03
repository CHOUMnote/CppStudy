#include <iostream>
//����� �Լ�!
//��� ������ ���� �б� ���ٸ� ����! ���� �Ұ���!
//����� �Լ��� ����� �Լ��� ȣ�� ����! -> �Ϲ� �Լ��� ������ ���� ������ �ƶ��� ��ġ���� ����!
//(�Լ� ����) + const
//��� ���� ���� ���� �ɼ� �߰� 
//1. mutabla : ex)mutabla int a;  
//2. const_cast<>() : ���� �Ǵ� �����Ϳ� ���\

//����� ���ÿ� ������ �ζ��� �Լ�!
//�����ڸ� ���� ��� �Լ��� �ζ��� ����!
class TestClass{
    public: 
        mutable int a;
        int b;
        TestClass() = default;
        void TestFnc() const{   //����� �Լ�
            a = 10;
            //b = 10; ����!
            std::cout << a << std::endl;//���� ���� ����!
        }
};
void Test(const int& a){
    int &temp = const_cast<int&>(a);
    temp = 999;
}
//�ζ��� �Լ�
//����ð� ������.(�Լ� ȣ�� ������� ����)
//ª�� �ڵ忡 ���� �����
//���α׷� ������ ����
inline int odd(int x){  //�ζ��� �Լ� ����
    return x%2;
}
int main(){
    int t = 100;
    std::cout << "const_cast ��� �׽�Ʈ" << std::endl;
    std::cout << t << std::endl;
    Test(t);
    std::cout << t << std::endl;

    TestClass test{1,2};
    test.TestFnc();

    if(odd(t)){ // equal - if(t%2)
        std::cout << "t�� Ȧ�� �Դϴ�." << std::endl;
    }
}