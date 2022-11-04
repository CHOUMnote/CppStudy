#include <iostream>
#include <vector>
#include <string>

using namespace std;

//1. L�� : ����ó�� �̸��� �ּҸ� ���´�.(����) -> int a...
//   R�� : ���ͷ�, �ӽ� ��üó�� �� �̻� �������� �ʴ� �ӽ��� ��ü -> "~~",1 ... 
//2. L�� ���� -> &, R�� ���� &&
//   ���ʿ��� ���� �� ������带 ���δ�.
//3. �޸� ������ ��ȯ -> �޸� ���� �� Dangling Pointer ����
//   �̸� ���� �̵�����, �̵����� �����ڴ� R�� ���� ����Ѵ�. -> ���� ��ü ���� �� ����

void Value(int& a){
    cout << "���� �� : " << a << endl;
};
void Value(int&& a){
    //�̶� a�� L��
    cout << "������ �� : " << a << endl;
}
int main(){
    int num = 10;

    Value(num);
    Value(999);
    Value(move(num));   //std::move() -> �̵��� ������ �ƴ� �ܼ��� L���� R������ ���� ��ȯ
    
    return 0;
}