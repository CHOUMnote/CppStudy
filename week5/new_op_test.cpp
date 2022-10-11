#include <iostream>

//cpp 메모리 동적(heap)할당 => new 연산자   (c에서는 malloc)
//기본타입, 배열, 객체, 객체배열 할당
//할당시 생성자 호출!
//delete    (c에서는 free)
//동적 할당 메모리 반환 -> 소멸자 호출 후 반환

class Circle{

};
int main(){
    int *p = nullptr; //!=0,null
    p = new int; //동적 할당
    *p = 5;
    int n = *p;
    std::cout << "*p = " << *p << "\n";
    std::cout << "n = " << n << "\n";
    
    delete p;   //할당 메모리 제거
    std::cout << "delete p = " << *p << "\n";
    p = nullptr; //명시적 제거 -> 반환 한 메모리에 포인팅중이기 때문에 널포인터를 가르킴
    //std::cout << "*p=nullptr = " << *p << "\n";

    int *parr = new int[5];
    
    for(int i=0; i<5; i++){
        //*(parr+i) = i;
        parr[i] = i;
        std::cout<< "p[i] = " << *(parr+i) << std::endl;
    }
    delete [] p; //동적 생성 배열 삭제 


}