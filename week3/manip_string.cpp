#include <string>
#include <iostream>
#include <locale>

int main(){
    char* c = "C++ programming";
    std::string s1{c};
    std::string s2 = "LOVE";
    
    //��Ʈ�� Ŭ���� �ٷ��!
    //strin ���� �Լ����� ���ϰ��� ����!

    std::cout << s1 + " " + s2 +"\n";

    std::cout << "���ڿ� ���� : ";
    s1.insert(2, s2);//2��°���� ����
    std::cout << s1 << std::endl;

    std::cout << "���ڿ� ��ġ : " << s1.replace(2,4,"AAAA") << std::endl;   //2��° ���� 4���� �ٲ�
    //std::cout << "���ڿ� ��ġ : " << s1.replace(2,3,"AAAA") << std::endl;   //C+AAAAE+ programming

    std::cout << "���ڿ� ���� : " << s1.length() << std::endl;  //equal std::string.size()

    std::cout << "���ڿ� �κ� ���� : " << s1.erase(1,6) << std::endl;//1���� 6�� ����

    std::string deepCpy = s1;   //���� ����
    s1.clear(); // equal std::sring.erase(); but time complexity : clear(good) > erase(bad)!
    std::cout << "���ڿ� ���� : "+s1+"\n"; 
    std::cout << "���� ���� string : "+deepCpy+"\n";

    return 0;
}