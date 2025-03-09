#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtility.h"

class clsTotalBalancesScreen : protected clsScreen {
   private:
    static void PrintClientRecordBalanceLine(clsBankClient Client) {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetAccountBalance() << endl;
    }

   public:
    static void ShowTotalBalances() {
        vector<clsBankClient> vClients = clsBankClient::GetClientList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        // Print Header
        cout << "\n" << clsUtility::RepeatChar('-', 69) << endl;
        cout << "| Account Number  | Client Name                   | Balance         |" << endl;
        cout << clsUtility::RepeatChar('-', 69) << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        // Print Clients
        if (vClients.empty()) {
            cout << "|                 | No Clients Available in the System!            |" << endl;
        } else {
            for (clsBankClient& Client : vClients) {
                cout << "| " << left << setw(16) << Client.AccountNumber() << "| " << left
                     << setw(30) << Client.FullName() << "| " << right << setw(15) << fixed
                     << setprecision(2) << Client.GetAccountBalance() << " |" << endl;
            }
        }

        // Print Footer
        cout << clsUtility::RepeatChar('-', 69) << endl;
        cout << "| Total Balance:  |                               | " << right << setw(15) << fixed
             << setprecision(2) << TotalBalances << " |" << endl;
        cout << clsUtility::RepeatChar('-', 69) << endl;
    }
};
