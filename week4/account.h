#ifndef ACCOUNT_H
#include <string>
#define ACCOUNT_H
namespace Bank{
    enum class MENU{
        DEPOSIT = 1,
        WITHDRAW,
        CHECK,
        QUIT
    };

    class Account{
        public : 
            std::string name;
            int balance;
            Account() = default;
            Account(std::string, int);
            int deposit(int);
            std::string getOwner() const;
            int check() const;
            int withdraw(int);
            ~Account();
    };
}
#endif