// ����ȯ�� �˾ƺ��ô�. 1. static_cast<?>() 2. const_cast<?*>()
#include <iostream>

//2.
void test(const int * n){
    // *n=1000; error
    auto a = const_cast<int*>(n);
    *a = 1000;
    std::cout << "*n�� ��" << *n << std::endl;
    std::cout << "*a�� ��" << *a << std::endl;
}
int main(){
    int x = 12345;
    test(&x);
    std::cout << "x�� ��" << x << std::endl;
}

