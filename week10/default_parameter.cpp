#include <string>
#include <iostream>

using namespace std;

//����Ʈ �Ű� - Ư�� �Լ��� �Ű������� �Ѿ���� ������ ������� ������ �Ű������� ���Ե�
//���̽�� ���� ��Ģ ����

void print(int a, string name="hokimji"){
    cout << a << " : " << name << endl;
}

//����Ʈ �Ű����� - �����ʺ��� ä�� ������. �ƴϸ� ����
//void error(int a, int b=1, int c) { }; ������ ����!
//void error(int a=0, int b, int c) { }; ������ ����!
void error(int a=0, int b=1, int c=2) { }; //������ ����!
int main(){
    print(10); //print(10,"hokimji")�� ����.
    print(20, "Hello"); //����Ʈ �Ű����� ��� Hello�� ���Ե�
    //print(); ���� - int a �Ű������� ä������
    //print("AAA"); ���� - ù��° �Ű������� �����ʴ� Ÿ�� 
    return 0;
}