#include <iostream>
#include <string>
#include <locale>
#include <typeinfo>
int main(){
    float i = 0.2f;
    std::string str = "10";
    char c = 'a';

    std::cout << "�빮�� ��ȯ : " << static_cast<char>(std::toupper(c)) << std::endl;
    std::cout << "�ҹ��� ��ȯ : " << static_cast<char>(std::tolower('A')) << std::endl;
    
    std::cout << std::isdigit('2') << std::endl;  //���� ��ȯ ������ char -> 1(true) �ƴϸ� 0
    std::cout << std::isdigit(str.at(1)) << std::endl;
    std::cout << std::isdigit(c) << std::endl;
    std::cout << std::isalpha('a') << " " << std::isalpha('A') << std::endl << std::endl;  //�빮�� 1 �ҹ��� 2
    
    std::cout << "���ڸ� ���ڷ� : " << std::stoi("123a") << std::endl;  //a123 -> ����
    std::cout << "���ڸ� ���ڷ� : " << std::stol("123") << std::endl;
    std::cout << "���ڸ� ���ڷ� : " << std::stoi("12.3") << std::endl;
    std::cout << "���ڸ� ���ڷ� : " << std::stod("123") << std::endl;

    std::cout << "���ڸ� ���ڷ� : " << std::to_string(i) << std::endl;

    

    

}