#include <iostream>
#include "account.h"
using namespace std;
using Bank::Account;
using Bank::MENU;
int main() {
    cout << "20195141 ����ȣ \n";

    Account a("C++", 0); //�����ָ� string name; �ܾ� int balance;
    int menu, money;
    do {
        cout << "--------------------------------------------" << endl;
        cout << "menu : 1. �Ա�, 2. ��� 3. ��ȸ 4. ���� >> ";
        cin >> menu;
        if(menu == static_cast<int>(MENU::QUIT))
            break;
        switch (menu) {
            case (static_cast<int>(MENU::DEPOSIT)):
                cout << "�Աݾ� >> ";
                cin >> money;
                a.deposit(money);
                cout << a.getOwner() << "�� �Ա� ���� " << money << endl;
                cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl; //�� �Լ� ��� const �Լ�
                break;
            case (static_cast<int>(MENU::WITHDRAW)):
                cout << "��ݾ� >> ";
                cin >> money;
                cout << a.getOwner() << "�� ��� ���� " << a.withdraw(money) << endl;
                cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl;
                break;
            case (static_cast<int>(MENU::CHECK)):
                cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl;
        }
    } while (true);
    return 0;
}