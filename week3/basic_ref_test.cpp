#include <iostream>
using namespace std;

int refTest(const int &a, const int &b){
    return a+b;
}
int main(){
    //������ ������ ����� �ʱ�ȭ
    //����� �޸� ������ �����Ѵ�. ���� ����� ���۷����� �Ұ���
    //const var ������ const &ref ���

    int a = 1000;
    int &refa = a;
    //int &refa = 1000; ������ ����!
    const int aa = 1;
    const int &refaa = aa;
/////////////////////////////////////////////////////////
    //�����ͺ��� ����
    // num <- ptr, num <- pref
    int num = 12;
    int *ptr = &num;
    int &ref = num;
    int*(&pref) = ptr;
    int &vref = *pref;

    cout << num << " " << *ptr << " " << *pref << " " << vref << endl;
    vref += 1;
    cout << num << " " << *ptr << " " << *pref << " " << vref << endl;

    cout << "�Ű������δ� ����� ���� �� �ִ�!!!" << refTest(1000,num);
}