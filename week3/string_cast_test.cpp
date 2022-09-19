#include <iostream>
#include <string>
#include <locale>
#include <typeinfo>
int main(){
    float i = 0.2f;
    std::string str = "10";
    char c = 'a';

    std::cout << "대문자 변환 : " << static_cast<char>(std::toupper(c)) << std::endl;
    std::cout << "소문자 변환 : " << static_cast<char>(std::tolower('A')) << std::endl;
    
    std::cout << std::isdigit('2') << std::endl;  //숫자 변환 가능한 char -> 1(true) 아니면 0
    std::cout << std::isdigit(str.at(1)) << std::endl;
    std::cout << std::isdigit(c) << std::endl;
    std::cout << std::isalpha('a') << " " << std::isalpha('A') << std::endl << std::endl;  //대문자 1 소문자 2
    
    std::cout << "문자를 숫자로 : " << std::stoi("123a") << std::endl;  //a123 -> 에러
    std::cout << "문자를 숫자로 : " << std::stol("123") << std::endl;
    std::cout << "문자를 숫자로 : " << std::stoi("12.3") << std::endl;
    std::cout << "문자를 숫자로 : " << std::stod("123") << std::endl;

    std::cout << "숫자를 문자로 : " << std::to_string(i) << std::endl;

    

    

}