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
    cout << "쓰레드 " << thread_id << "에서 구한 결과 : " << sum << endl;
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
    //쓰레드의 첫 매개변수는 반드시 callable 인자
    //그 다음 해당 함수의 인자에 맞게 인수들을 나열한다
    for (int i = 0; i < 4; i++)
        cpu.push_back(thread(sumVec, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, i));
    for (int i = 0; i < 4; i++)
        cpu[i].join();

    int result = 0;
    for (int i = 0; i < 4; i++)
        result += mem[i];
    cout << "총합 : " << result << endl;
}
