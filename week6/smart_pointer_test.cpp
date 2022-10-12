#include <iostream>
#include <memory> //필요!

//스마트 포인터는 포인터처럼 동작하는 클래스 템플릿
//사용이 끝나면 자동으로 메모리 해제 ->use_count == 0 이면
/*
1. unique_ptr : 하나의 스마트 포인터만 소유, 소유권 개념, 해당 포인터가 영역을 벗어나거나 리셋시 메모리 해제
소유권? 이전은 가능하지만 복사 대입 공유와 같은 연산 불가능
2. shared_ptr : 하나의 객체를 참조하는 포인터의 개수를 참조! (한마디로 해당 객체를 포인팅 + 그 포인터 개수를 카운팅)
use_count() -> 참조 카운트 반환, 이게 0이면 해당 포인터 메모리 해제
3. weak_ptr : shared_ptr이 가리키는거 참조 가능 하지만 참조 카운터는 늘어나지 않음! (순환 참조 제거)
순환 참조? shared_ptr이 서로를 참조 -> 참조 카운트가 0이 절대 되지 않음! 따라서 메모리 해제가 안된다!
*/

using namespace std;

class Person{
    public:
        int a = 0;
        Person(){
            cout << "디폴트\n";
        }
        Person(int a, int b, int c){
            cout<<"메모리 할당!\n";
            this->a = a;
        }
        ~Person(){
            cout<< a <<" 메모리 헤제!\n";
        }
};


int main(){
    //1.
    //int* p = new int{n};
    std::unique_ptr<int> p{new int {}};
    *p = 10;
    cout << *p << endl;

    //2.
    std::unique_ptr<int> pp = std::move(p);
    cout << *pp << endl;
    //std::unique_ptr<int> pp = p; 에러!
    
    //3.
    //double *dp = new double(3.14);
    std::unique_ptr<double> dp = std::make_unique<double>(3.14);
    cout << *dp << endl;

    //4.
    unique_ptr<int[]> arr = std::make_unique<int[]>(5);
    for(int i=0;i<5;i++){
        arr[i] = i;
        cout<<arr[i]<< " ";
    }
    cout << endl;

    auto p1 = make_unique<Person>(1,2,3);
    auto p2 = make_unique<Person>();
    
    return 0;
}