#include <thread>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mem;

void sumVec(vector<int>::iterator i, vector<int>::iterator j, int idx)
{
    int sum = 0;
    while (i++ != j)
        sum += (*i);

    thread::id thread_id = this_thread::get_id();
    cout << "������ " << thread_id << "���� ���� ��� : " << sum << endl;
    mem.push_back(sum);
}

int main()
{
    vector<int> data(10000);
    for (int i = 0; i < 10000; i++)
    {
        data[i] = i;
    }

    vector<thread> cpu;
    //�������� ù �Ű������� �ݵ�� callable ����
    //�� ���� �ش� �Լ��� ���ڿ� �°� �μ����� �����Ѵ�
    for (int i = 0; i < 4; i++)
        cpu.push_back(thread(sumVec, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, i));
    for (int i = 0; i < 4; i++)
        cpu[i].join();

    int result = 0;
    for (int i = 0; i < 4; i++)
        result += mem[i];
    cout << "���� : " << result << endl;
}
