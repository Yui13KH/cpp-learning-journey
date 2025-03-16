#pragma once

#include <iostream>
#include "../Ui/clsScreen.h"
#include "../Bank/clsBankClient.h"
#include "../Core/clsInputValidate.h"

class clsTransferScreen : protected clsScreen {
   private:
    static void _PrintClient(clsBankClient Client) {
        std::cout << "\nClient Card:";
        std::cout << "\n___________________\n";
        std::cout << "\nFull Name   : " << Client.FullName();
        std::cout << "\nAcc. Number : " << Client.AccountNumber();
        std::cout << "\nBalance     : " << Client.GetAccountBalance();
        std::cout << "\n___________________\n";
    }

    static string _ReadAccountNumber() {
        string AccountNumber;
        std::cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            std::cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient) {
        float Amount;

        std::cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.GetAccountBalance()) {
            std::cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

   public:
    static void ShowTransferScreen() {
        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);

        std::cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            if (SourceClient.Transfer(DestinationClient, Amount)) {
                std::cout << "\nTransfer done successfully\n";
            } else {
                std::cout << "\nTransfer Faild \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }
};