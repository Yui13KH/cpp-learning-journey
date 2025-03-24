#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../Core/clsInputValidate.h"
#include "../Core/clsUtility.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include <iomanip>

class clsManageUsersScreen : protected clsScreen {
   private:
    enum enManageUsersMenueOptions {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenue = 6
    };

    static short ReadManageUsersMenueOption() {
        std::cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice =
            clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue() {
        std::cout << "\n\nPress any key to go back to Manage Users Menue...";
        clsUtility::pauseExecution();
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen() { clsListUsersScreen::ShowUsersList(); }

    static void _ShowAddNewUserScreen() { clsAddNewUserScreen::ShowAddNewUserScreen(); }

    static void _ShowDeleteUserScreen() { clsDeleteUserScreen::ShowDeleteUserScreen(); }

    static void _ShowUpdateUserScreen() { clsUpdateUserScreen::ShowUpdateUserScreen(); }

    static void _ShowFindUserScreen() { clsFindUserScreen::ShowFindUserScreen(); }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption) {
        switch (ManageUsersMenueOption) {
            case enManageUsersMenueOptions::eListUsers: {
                clsUtility::clearScreen();
                _ShowListUsersScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersMenueOptions::eAddNewUser: {
                clsUtility::clearScreen();
                _ShowAddNewUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersMenueOptions::eDeleteUser: {
                clsUtility::clearScreen();
                _ShowDeleteUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersMenueOptions::eUpdateUser: {
                clsUtility::clearScreen();
                _ShowUpdateUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersMenueOptions::eFindUser: {
                clsUtility::clearScreen();

                _ShowFindUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }

            case enManageUsersMenueOptions::eMainMenue: {
                // do nothing here the main screen will handle it :-) ;
            }
        }
    }

   public:
    static void ShowManageUsersMenue() {

        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
            return;
        }


        clsUtility::clearScreen();
        _DrawScreenHeader("\t Manage Users Screen");

        std::cout << setw(37) << left << "" << "===========================================\n";
        std::cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        std::cout << setw(37) << left << "" << "===========================================\n";
        std::cout << setw(37) << left << "" << "\t[1] List Users.\n";
        std::cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        std::cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        std::cout << setw(37) << left << "" << "\t[4] Update User.\n";
        std::cout << setw(37) << left << "" << "\t[5] Find User.\n";
        std::cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        std::cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
    }
};
