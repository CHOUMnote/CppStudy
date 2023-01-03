#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "randint.h"

RandInt::RandInt(int a, int b, string c):
    low{a}, high{b}, objname{c}{
    mt19937 gen(time(nullptr)); //mt19937 gen(clock()); //�ð��� �̿��� ���� ���� ���� �ʱ�ȭ
    uniform_int_distribution<int> int_rd(low, high); //low~high ������ ���� ���� ����(int)
    rannum = int_rd(gen);
}

void RandInt::print() const{
    cout<<"Random number between " << low << " and " << high << " : " << rannum << endl; //���� ������ �����Ͽ� ���� �� ������ ���� ���
}

RandInt::~RandInt(){
    cout << objname << "��ü �Ҹ�\n";
}