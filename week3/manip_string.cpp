#include <string>
#include <iostream>
#include <locale>

int main(){
    char* c = "C++ programming";
    std::string s1{c};
    std::string s2 = "LOVE";
    
    //스트링 클래스 다루기!
    //strin 내장 함수에는 리턴값이 있음!

    std::cout << s1 + " " + s2 +"\n";

    std::cout << "문자열 삽입 : ";
    s1.insert(2, s2);//2번째부터 삽입
    std::cout << s1 << std::endl;

    std::cout << "문자열 대치 : " << s1.replace(2,4,"AAAA") << std::endl;   //2번째 부터 4개를 바꿈
    //std::cout << "문자열 대치 : " << s1.replace(2,3,"AAAA") << std::endl;   //C+AAAAE+ programming

    std::cout << "문자열 길이 : " << s1.length() << std::endl;  //equal std::string.size()

    std::cout << "문자열 부분 삭제 : " << s1.erase(1,6) << std::endl;//1부터 6개 삭제

    std::string deepCpy = s1;   //깊은 복사
    s1.clear(); // equal std::sring.erase(); but time complexity : clear(good) > erase(bad)!
    std::cout << "문자열 삭제 : "+s1+"\n"; 
    std::cout << "깊은 복사 string : "+deepCpy+"\n";

    return 0;
}