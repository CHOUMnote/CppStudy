#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo>

using namespace std;

int main(){
    //1.cin �� get line
    /*
    char a[30];
    std::string str;

    std::cin >> a;
    getline(std::cin, str); //(�Է� ��Ʈ��, ���� �ּ�, [Ư�� ���ڿ��� �Է� ����])
    //>>> ���� abc de f �Է½� cin���� abc ���� �Է� ��Ʈ���� \n�� ���� ���� " de f"�ڵ� �Է�

    for(char i:a)
        std::cout << i;
    std::cout << std::endl;
    std::cout << str << "\n";
    */

    //2.string ���� ���
    string a = "i am string";
    string b("string!");
    auto c{"ABC!"s};
    auto d{"ABC!"};

    cout<< a << endl;
    cout<< b << endl;
    cout<< c << endl;
    cout<< d << endl;
    cout<< b[1] << endl;
    cout<< boolalpha << (a==b) <<endl;
    cout<< boolalpha << (c==d) <<endl<<endl;

    cout << "c�� Ÿ�� : " << typeid(c).name()<< endl;
    cout << "d�� Ÿ�� : " << typeid(d).name()<< endl;

    cout << "���ݱ��� " + b + "�� �˾ƺý��ϴ�!";
    return 0;
}