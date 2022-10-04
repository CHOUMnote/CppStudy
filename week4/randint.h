#ifndef RANDINT_H
#define RANDINT_H
#include <string>
using namespace std;

class RandInt {
    private:
        string objname;
        int low, high, rannum;
    public:
        RandInt(int low, int high, string cn); //작은 값(low)과 큰 값(high) 범위 내의 난수(rannum) 생성 ~RandInt(); //소멸자
        RandInt(const RandInt& random) = delete; //복사 생성자를 생성하지 않음
        void print() const; //범위, 난수 출력, 변경 작업이 필요 없으므로 const
        ~RandInt();
};
#endif