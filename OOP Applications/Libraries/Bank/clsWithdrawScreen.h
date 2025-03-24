#pragma once

#include <iostream>
#include "../Ui/clsScreen.h"
#include "../Bank/clsBankClient.h"
#include "../Core/clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen {
   private:
    static void _PrintClient(clsBankClient Client) {
        cout << "\nClient Card:" << endl;
        cout << "___________________" << endl;
        cout << "FirstName   : " << Client.FirstName() << endl;
        cout << "LastName    : " << Client.LastName() << endl;
        cout << "Full Name   : " << Client.FullName() << endl;
        cout << "Email       : " << Client.Email() << endl;
        cout << "Phone       : " << Client.Phone() << endl;
        cout << "Acc. Number : " << Client.AccountNumber() << endl;
        cout << "Password    : " << Client.GetPinCode() << endl;
        cout << "Balance     : " << Client.GetAccountBalance() << endl;
        cout << "___________________" << endl;
    }

    static string _ReadAccountNumber() {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

   public:
    static void ShowWithdrawScreen() {
        _DrawScreenHeader("\t   WithDraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter WithDraw amount? ";
        Amount = clsInputValidate::ReadNumber<double>();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y') {
            if (Client1.Withdraw(Amount)) {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.GetAccountBalance();
            } else {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.GetAccountBalance();
            }
        } else {
            cout << "\nOperation was cancelled.\n";
        }
    }
};
