#pragma once

#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>

class clsClientListScreen : protected clsScreen {
   private:
    static void PrintClientRecordLine(clsBankClient& Client) {
        std::cout << "| " << std::left << std::setw(6) << Client.AccountNumber() << " | "
                  << std::setw(20) << Client.FullName() << " | " << std::setw(35) << Client.Email()
                  << " | " << std::setw(20) << Client.Phone() << " | " << std::setw(10)
                  << Client.GetPinCode() << " | " << std::setw(12) << std::fixed
                  << std::setprecision(3) << Client.GetAccountBalance() << " |\n";
    }

    static void PrintTableHeader() {
        std::cout << "\n\t\t\t\t\tClient List\n";
        std::cout << std::setw(8) << "" << clsUtility::RepeatChar('-', 124) << "\n";
        std::cout << std::setw(8) << "" << "| " << std::left << std::setw(6) << "Acc #"
                  << " | " << std::setw(20) << "Client Name"
                  << " | " << std::setw(35) << "Email"
                  << " | " << std::setw(20) << "Phone"
                  << " | " << std::setw(10) << "Pin Code"
                  << " | " << std::setw(12) << "Balance"
                  << " |\n";
        std::cout << std::setw(8) << "" << clsUtility::RepeatChar('-', 124) << "\n";
    }

   public:
    static void ShowClientsList() {
        std::vector<clsBankClient> vClients = clsBankClient::GetClientList();

        std::string Title = "\t  Client List Screen";
        std::string SubTitle = "\t    (" + std::to_string(vClients.size()) + " Clients)";

        _DrawScreenHeader(Title, SubTitle);

        PrintTableHeader();

        if (vClients.empty()) {
            std::cout << std::setw(8) << "" << "\t\t\tNo Clients Available In the System!\n";
        } else {
            for (clsBankClient& Client : vClients) {
                std::cout << std::setw(8) << "";
                PrintClientRecordLine(Client);
            }
        }

        std::cout << std::setw(8) << "" << clsUtility::RepeatChar('-', 124) << "\n";
    }
};