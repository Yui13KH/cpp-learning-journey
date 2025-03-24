#pragma once

#include <iostream>
#include "../core/clsScreen.h"
#include "../../Core/clsPerson.h"
#include "../../Bank/clsBankClient.h"
#include "../../Core/clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen {
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
    static void ShowDeleteClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
            return;
        }


        _DrawScreenHeader("\tDelete Client Screen");

        std::string AccountNumber = "";

        std::cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            std::cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        std::cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        std::cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (Client1.Delete()) {
                std::cout << "\nClient Deleted Successfully :-)\n";
                _PrintClient(Client1);
            } else {
                std::cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};