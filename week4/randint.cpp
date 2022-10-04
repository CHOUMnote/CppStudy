#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "randint.h"

RandInt::RandInt(int a, int b, string c):
    low{a}, high{b}, objname{c}{
    mt19937 gen(time(nullptr)); //mt19937 gen(clock()); //시간을 이용해 난수 생성 엔진 초기화
    uniform_int_distribution<int> int_rd(low, high); //low~high 사이의 난수 분포 정의(int)
    rannum = int_rd(gen);
}

void RandInt::print() const{
    cout<<"Random number between " << low << " and " << high << " : " << rannum << endl; //난수 엔진을 전달하여 범위 내 생성된 난수 출력
}

RandInt::~RandInt(){
    cout << objname << "객체 소멸\n";
}