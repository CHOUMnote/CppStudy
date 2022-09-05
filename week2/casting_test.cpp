// 형변환을 알아봅시다. 1. static_cast<?>() 2. const_cast<?*>()
#include <iostream>

//2.
void test(const int * n){
    // *n=1000; error
    auto a = const_cast<int*>(n);
    *a = 1000;
    std::cout << "*n의 값" << *n << std::endl;
    std::cout << "*a의 값" << *a << std::endl;
}
int main(){
    int x = 12345;
    test(&x);
    std::cout << "x의 값" << x << std::endl;
}

