#pragma once

#include "../Core/clsUtility.h"
#include "../Core/clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "../Bank/clsShowTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include <iostream>
#include <iomanip>

class clsMainScreen : protected clsScreen {
   private:
    enum enMainMenueOptions {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eExit = 8
    };

    static short _ReadMainMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice =
            clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static void _GoBackToMainMenue() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        clsUtility::pauseExecution();
        ShowMainMenu();
    }

    // placeholders for now

    static void _ShowAllClientsScreen() { clsClientListScreen::ShowClientsList(); }

    static void _ShowAddNewClientsScreen() { clsAddNewClientScreen::ShowAddNewClientScreen(); }

    static void _ShowDeleteClientScreen() { clsDeleteClientScreen::ShowDeleteClientScreen(); }

    static void _ShowUpdateClientScreen() { clsUpdateClientScreen::ShowUpdateClientScreen(); }

    static void _ShowFindClientScreen() { clsFindClientScreen::ShowFindClientScreen(); }

    static void _ShowTransactionsMenue() { clsTransactionsScreen::ShowTransactionsMenue(); }

    static void _ShowManageUsersMenue() { clsManageUsersScreen::ShowManageUsersMenue(); }

    static void _ShowEndScreen() { cout << "\nEnd Screen Will be here...\n"; }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption) {
        switch (MainMenueOption) {
            case enMainMenueOptions::eListClients: {
                clsUtility::clearScreen();
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::eAddNewClient:
                clsUtility::clearScreen();
                _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eDeleteClient:
                clsUtility::clearScreen();
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eUpdateClient:
                clsUtility::clearScreen();
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eFindClient:
                clsUtility::clearScreen();
                _ShowFindClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eShowTransactionsMenue:
                clsUtility::clearScreen();
                _ShowTransactionsMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eManageUsers:
                clsUtility::clearScreen();
                _ShowManageUsersMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eExit:
                clsUtility::clearScreen();
                _ShowEndScreen();
                // Login();

                break;
        }
    }

   public:
    static void ShowMainMenu() {
        clsUtility::clearScreen();
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};
