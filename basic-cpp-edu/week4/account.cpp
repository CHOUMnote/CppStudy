#include "account.h"
#include <string>
#include <iostream>

using namespace Bank;

Account::Account(std::string str, int n):
        name{str}, balance{n}{}
Account::~Account(){
        std::cout << this->getOwner() << " : °´Ã¼ ¼Ò¸ê \n";
}
int Account::deposit(int n){
        this->balance +=n;
        return n;
}
int Account::withdraw(int n){
        this->balance -= n;
        return n;
}
int Account::check() const{
    return this->balance;
}
std::string Account::getOwner() const{
    return this->name;
}