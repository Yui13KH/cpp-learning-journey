#pragma once

#include "../Users/clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "../Core/Global.h"

class clsLoginScreen : protected clsScreen {
   private:
    static void _Login() {
        bool LoginFailed = false;

        std::string Username, Password;
        do {
            if (LoginFailed) {
                std::cout << "\nInvalid Username or Password please try again\n";
            }

            std::cout << "\nPlease Enter Username: ";
            Username = clsInputValidate::ReadString();

            std::cout << "\nPlease Enter Password: ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();
        } while (LoginFailed);

        clsMainScreen::ShowMainMenu();
    }

   public:
    static void ShowLoginScreen() {
        clsUtility::clearScreen();
        _DrawScreenHeader("\t Login Screen");
        _Login();
    }
};