#include <iostream>
#include <memory> //�ʿ�!

//����Ʈ �����ʹ� ������ó�� �����ϴ� Ŭ���� ���ø�
//����� ������ �ڵ����� �޸� ���� ->use_count == 0 �̸�
/*
1. unique_ptr : �ϳ��� ����Ʈ �����͸� ����, ������ ����, �ش� �����Ͱ� ������ ����ų� ���½� �޸� ����
������? ������ ���������� ���� ���� ������ ���� ���� �Ұ���
2. shared_ptr : �ϳ��� ��ü�� �����ϴ� �������� ������ ����! (�Ѹ���� �ش� ��ü�� ������ + �� ������ ������ ī����)
use_count() -> ���� ī��Ʈ ��ȯ, �̰� 0�̸� �ش� ������ �޸� ����
3. weak_ptr : shared_ptr�� ����Ű�°� ���� ���� ������ ���� ī���ʹ� �þ�� ����! (��ȯ ���� ����)
��ȯ ����? shared_ptr�� ���θ� ���� -> ���� ī��Ʈ�� 0�� ���� ���� ����! ���� �޸� ������ �ȵȴ�!
*/

using namespace std;

class Person{
    public:
        int a = 0;
        Person(){
            cout << "����Ʈ\n";
        }
        Person(int a, int b, int c){
            cout<<"�޸� �Ҵ�!\n";
            this->a = a;
        }
        ~Person(){
            cout<< a <<" �޸� ����!\n";
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
    //std::unique_ptr<int> pp = p; ����!
    
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