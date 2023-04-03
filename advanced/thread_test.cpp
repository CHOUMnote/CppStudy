#include <thread> //쓰래드 사용 11이상에서 통합됨
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

    // join은 해당 쓰레드가 종료되면 자동으로 리턴하는 함수임
    // join, detach을 하지 않고 메인을 종료시키면 에러를 발생시킨다.
    // 한마디로 해당 쓰레드가 종료 전까지 sleep합니다.
    // detach는 쓰레드 종료시까지 기다리지 않고 다음 라인을 실행한다. 그리고 해당 쓰레드는 계속 작동한다.
    cpu1.join();
    cpu2.join();
    cpu3.join();
    //cpu3.detach();

    //운영체제 스케쥴링이 매번 다르기 때문에호출시 마다 출력이 달라짐
    for (int i = 0; i < mem.size(); i++)
        cout << mem.at(i) << ' ';
    cout << endl;
}
