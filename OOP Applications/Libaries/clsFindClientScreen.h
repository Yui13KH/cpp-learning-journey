#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsScreen {
   private:
    static void _PrintClient(clsBankClient Client) {
        std::cout << "\nClient Card:";
        std::cout << "\n___________________";
        std::cout << "\nFirstName   : " << Client.FirstName();
        std::cout << "\nLastName    : " << Client.LastName();
        std::cout << "\nFull Name   : " << Client.FullName();
        std::cout << "\nEmail       : " << Client.Email();
        std::cout << "\nPhone       : " << Client.Phone();
        std::cout << "\nAcc. Number : " << Client.AccountNumber();
        std::cout << "\nPassword    : " << Client.GetPinCode();
        std::cout << "\nBalance     : " << Client.GetAccountBalance();
        std::cout << "\n___________________\n";
    }

   public:
    static void ShowFindClientScreen() {
        _DrawScreenHeader("\tFind Client Screen");

        std::string AccountNumber;
        std::cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            std::cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty()) {
            std::cout << "\nClient Found :-)\n";
        } else {
            std::cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);
    }
};
