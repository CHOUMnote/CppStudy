#include <iostream>
#include <array>    //정적배열
#include <vector>   //동적배열

int main(){
    //array 1.stack영역 정적 할당 2.컴파일시 할당 3.빠른 할당
    std::array<int,10> array = {9};
    // == int array[10] = {0}

    //vector 1.heap영역 동적 할당 2.런타임시 할당 3.느린할당?? -> 더 큰 메모리 확장시 복제 필요 (reserve()로 매우 큰 메모리 미리 지정으로 해결)
    std::vector<int> vector1(3);
    std::vector<int> vector2{1,2,34,5,5,2,41,421};

    std::cout<<"array테스트\n";
    for(int i=0; i<array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    std::cout<<"vector1테스트\n";
    for(int i=0; i<vector1.size(); i++)
        std::cout << vector1[i] << " ";
    std::cout << std::endl;

    std::cout<<"vector2테스트\n";
    for(int i=0; i<vector2.size(); i++)
        std::cout << vector2[i] << " ";
    std::cout << std::endl;

    std::cout<<"vector1 데이터 추가 테스트\n";
    vector1.emplace_back(99999);
    for(int a:vector1)
        std::cout << a << " ";
    std::cout << std::endl;    

    std::cout<<"vector2 데이터 삭제 테스트\n";    
    vector2.pop_back();
    for(int a:vector2)
        std::cout << a << " ";
    std::cout << std::endl;    

    return 0;
}