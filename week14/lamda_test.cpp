#include <iostream>
#include <string>

using namespace std;

//c++ ���ٽ�(�͸��Լ�)
//[]()->{}
//ĸ�ĸ���Ʈ, �Ű�����, ����Ÿ��(void�� ��������), �ڵ屸��
int main(){
    string alpha = "TEST"; 
    [](int a, int b)->int{return a+b;}; //���ٽ� ����
    [alpha](int a){cout << alpha << " : " << a << endl;}(7777); //���� �Լ� ���� �� ��� ����

    auto lamb = [](string a, string b){cout << a << " " << b << endl;}; //���ٽ� ������ �����Ϸ��� �˰��ֱ� ������ �����ڴ� �� �� ����. -> auto
    lamb("Hello"s, "world"s); //�Լ� ȣ��

    int val = 999;
    int *p = &val;
    auto changeP = [p](){*p = 1267;};
    changeP();
    cout << "�����͸� ���� ���ٽ� : " << *p << endl;
    auto changeRef = [&val](int i){val+=i;};
    changeRef(3);
    cout << "������ ���� ���ٽ�" << val << endl;
}