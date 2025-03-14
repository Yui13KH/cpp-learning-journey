#pragma once

#include "../Users/clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "../Core/Global.h"
#include "../Core/clsDate.h"
#include <fstream>

class clsLoginScreen : protected clsScreen {
   private:
    static bool _Login() {
        bool LoginFailed = false;
        short LoginCountTries = 2;

        std::string Username, Password;
        do {
            if (LoginFailed) {
                std::cout << "\nInvalid Username or Password please try again\n";
                LoginCountTries--;
                std::cout << std::to_string(LoginCountTries + 1) << ": Tries Left";
            }

            std::cout << "\nPlease Enter Username: ";
            Username = clsInputValidate::ReadString();

            std::cout << "Please Enter Password: ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();

            if (LoginCountTries < 1) {
                std::cout << "\nToo Many failed attempts , Locked out of the system \n";
                return false;
            };
        } while (LoginFailed);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenu();
        return true;
    }

   public:
    static bool ShowLoginScreen() {
        clsUtility::clearScreen();
        _DrawScreenHeader("\t Login Screen");
        return _Login();
    }
};