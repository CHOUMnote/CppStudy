#include <iostream>
#include <memory>

using namespace std;

class Person{
public:
    int a;
    Person(int a){
        this->a = a;
    }
    ~Person(){
        cout<<"�޸� ����\n";    
    }
    weak_ptr<Person> per;//<-shared_ptr�� ��ȯ ������ �޸� ����! weak_ptr�� ����!
};
void show (shared_ptr<Person> ptr){
    cout <<"show : "<< ptr.use_count()<<endl;
}

int main(){
    auto sp1 = make_shared<Person>(99);
    show(sp1);
    cout << "sp1.use_count : " <<sp1.use_count()<<endl;

    sp1->per = sp1;
    show(sp1);
    cout << "sp1.use_count : " <<sp1.use_count()<<endl;      
}