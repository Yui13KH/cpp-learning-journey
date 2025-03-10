#pragma once

#include "../Core/clsInputValidate.h"
#include "../Bank/clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>

class clsAddNewClientScreen : protected clsScreen {
   private:
    static void _ReadClientInfo(clsBankClient& Client) {
        std::cout << "\nEnter FirstName: ";
        Client.SetFirstName(clsInputValidate::ReadString());

        std::cout << "\nEnter LastName: ";
        Client.SetLastName(clsInputValidate::ReadString());

        std::cout << "\nEnter Email: ";
        Client.SetEmail(clsInputValidate::ReadString());

        std::cout << "\nEnter Phone: ";
        Client.SetPhone(clsInputValidate::ReadString());

        std::cout << "\nEnter PinCode: ";
        Client.SetPinCode(clsInputValidate::ReadString());

        std::cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
    }

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
    static void ShowAddNewClientScreen() {
        _DrawScreenHeader("\t  Add New Client Screen");

        std::string AccountNumber = "";

        std::cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber)) {
            std::cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult) {
            case clsBankClient::enSaveResults::svSucceeded: {
                std::cout << "\nAccount Addeded Successfully :-)\n";
                _PrintClient(NewClient);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject: {
                std::cout << "\nError account was not saved because it's Empty";
                break;
            }
            case clsBankClient::enSaveResults::svFaildAccountNumberExists: {
                std::cout << "\nError account was not saved because account number is used!\n";
                break;
            }
        }
    }
};
