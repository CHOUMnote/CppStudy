#include <iostream>
#include <memory>

using namespace std;

class Person
{
public:
    int a = 0;
    Person()
    {
        cout << "디폴트\n";
    }
    Person(int a, int b, int c)
    {
        cout << "메모리 할당!\n";
        this->a = a;
    }
    ~Person()
    {
        cout << a << " 메모리 헤제!\n";
    }
    void display()
    {
        cout << "No." << a << "\n";
    }
};
void show(shared_ptr<Person> p)
{
    (*p).display();
    cout << "use_count : " << p.use_count() << endl;
}

int main()
{
    int a = 177;
    auto sp1 = make_shared<Person>(a,0,0);
    show(sp1);
    cout << "use_count : " << sp1.use_count() << endl<<endl;
    
    shared_ptr<Person> sp2 = sp1;
    show(sp2);
    cout << "sp1 use_count : " << sp1.use_count() << endl;
    cout << "sp2 use_count : " << sp2.use_count() << endl;
}