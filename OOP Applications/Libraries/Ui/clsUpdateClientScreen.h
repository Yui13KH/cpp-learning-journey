#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../Core/clsPerson.h"
#include "../Bank/clsBankClient.h"
#include "../Core/clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen

{
   private:
    static void _PrintClient(clsBankClient& Client) {
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

    static void ReadClientInfo(clsBankClient& Client) {
        cout << "\nEnter FirstName: ";
        Client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        Client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        Client.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode: ";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
    }

   public:
    static void ShowUpdateClientScreen() {
        _DrawScreenHeader("\tUpdate Client Screen");

        std::string AccountNumber = "";

        std::cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            std::cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        std::cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        std::cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            std::cout << "\n\nUpdate Client Info:";
            std::cout << "\n____________________\n";

            ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult) {
                case clsBankClient::enSaveResults::svSucceeded: {
                    std::cout << "\nAccount Updated Successfully :-)\n";

                    _PrintClient(Client1);
                    break;
                }
                case clsBankClient::enSaveResults::svFaildEmptyObject: {
                    std::cout << "\nError account was not saved because it's Empty";
                    break;
                }
            }
        }
    }
};
