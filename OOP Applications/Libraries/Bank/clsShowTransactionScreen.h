#pragma once
#include <iostream>
#include <iomanip>
#include "../Ui/core/clsScreen.h"
#include "../Core/clsInputValidate.h"
#include "../Core/clsUtility.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen {
   private:
    enum enTransactionsMenueOptions {
        eDeposit = 1,
        eWithdraw = 2,
        eShowTotalBalance = 3,
        eTransfer = 4,
        eTransferLogs = 5,
        eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption() {
        std::cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice =
            clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen() { clsDepositScreen::ShowDepositScreen(); }

    static void _ShowWithdrawScreen() { clsWithdrawScreen::ShowWithdrawScreen(); }

    static void _ShowTotalBalancesScreen() { clsTotalBalancesScreen::ShowTotalBalances(); }

    static void _ShowTransferScreen() { clsTransferScreen::ShowTransferScreen(); }

    static void _ShowTransferLogScreen() { clsTransferLogScreen::ShowTransferLogScreen(); }

    static void _GoBackToTransactionsMenue() {
        std::cout << "\n\nPress any key to go back to Transactions Menue...";

        clsUtility::pauseExecution();
        ShowTransactionsMenue();
    }

    static void _PerformTransactionsMenueOption(
        enTransactionsMenueOptions TransactionsMenueOption) {
        switch (TransactionsMenueOption) {
            case enTransactionsMenueOptions::eDeposit: {
                clsUtility::clearScreen();
                _ShowDepositScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::eWithdraw: {
                clsUtility::clearScreen();
                _ShowWithdrawScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::eShowTotalBalance: {
                clsUtility::clearScreen();
                _ShowTotalBalancesScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::eTransfer: {
                clsUtility::clearScreen();
                _ShowTransferScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::eTransferLogs: {
                clsUtility::clearScreen();
                _ShowTransferLogScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::eShowMainMenue: {
                // do nothing here the main screen will handle it :-) ;
            }
        }
    }

   public:
    static void ShowTransactionsMenue() {
        clsUtility::clearScreen();
        _DrawScreenHeader("\t  Transactions Screen");

        std::cout << setw(37) << left << "" << "===========================================\n";
        std::cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        std::cout << setw(37) << left << "" << "===========================================\n";
        std::cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        std::cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        std::cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        std::cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        std::cout << setw(37) << left << "" << "\t[5] Transfer Logs. \n";
        std::cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        std::cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }
};
