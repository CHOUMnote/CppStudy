#include <thread> //������ ��� 11�̻󿡼� ���յ�
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mem;

void fn1()
{
    for (int i = 0; i < 100; i++)
        mem.push_back(1);
}
void fn2()
{
    for (int i = 0; i < 100; i++)
        mem.push_back(2);
}
void fn3()
{
    for (int i = 0; i < 100; i++)
        mem.push_back(3);
}
int main()
{
    mem.clear();
    std::thread cpu1(fn1);
    thread cpu2(fn2);
    thread cpu3(fn3);

    // join�� �ش� �����尡 ����Ǹ� �ڵ����� �����ϴ� �Լ���
    // join, detach�� ���� �ʰ� ������ �����Ű�� ������ �߻���Ų��.
    // �Ѹ���� �ش� �����尡 ���� ������ sleep�մϴ�.
    // detach�� ������ ����ñ��� ��ٸ��� �ʰ� ���� ������ �����Ѵ�. �׸��� �ش� ������� ��� �۵��Ѵ�.
    cpu1.join();
    cpu2.join();
    cpu3.join();
    //cpu3.detach();

    //�ü�� �����층�� �Ź� �ٸ��� ������ȣ��� ���� ����� �޶���
    for (int i = 0; i < mem.size(); i++)
        cout << mem.at(i) << ' ';
    cout << endl;
}
