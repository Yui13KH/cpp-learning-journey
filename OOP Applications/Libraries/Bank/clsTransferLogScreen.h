#pragma once

#include <iostream>
#include "../Ui/clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen {
   private:
    static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord) {
        std::cout << setw(8) << left << "" << "| " << setw(23) << left
                  << TransferLogRecord.DateTime;
        std::cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        std::cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
        std::cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        std::cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
        std::cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter;
        std::cout << "| " << setw(8) << left << TransferLogRecord.UserName;
    }

   public:
    static void ShowTransferLogScreen() {
        vector<clsBankClient::stTrnsferLogRecord> vTransferLogRecord =
            clsBankClient::GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        std::cout << setw(8) << left << ""
                  << "\n\t_______________________________________________________";
        std::cout << "_________________________________________\n" << endl;

        std::cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        std::cout << "| " << left << setw(8) << "s.Acct";
        std::cout << "| " << left << setw(8) << "d.Acct";
        std::cout << "| " << left << setw(8) << "Amount";
        std::cout << "| " << left << setw(10) << "s.Balance";
        std::cout << "| " << left << setw(10) << "d.Balance";
        std::cout << "| " << left << setw(8) << "User";

        std::cout << setw(8) << left << ""
                  << "\n\t_______________________________________________________";
        std::cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            std::cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTrnsferLogRecord Record : vTransferLogRecord) {
                PrintTransferLogRecordLine(Record);
                std::cout << endl;
            }

        std::cout << setw(8) << left << ""
                  << "\n\t_______________________________________________________";
        std::cout << "_________________________________________\n" << endl;
    }
};
