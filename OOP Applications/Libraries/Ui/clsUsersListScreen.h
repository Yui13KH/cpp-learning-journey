#pragma once

#include <iostream>
#include "clsScreen.h"
#include "../Users/clsUser.h"
#include <iomanip>

class clsListUsersScreen : protected clsScreen {
   private:
    static void _PrintUserRecordLine(clsUser User) {
        std::cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName();
        std::cout << "| " << setw(25) << left << User.FullName();
        std::cout << "| " << setw(12) << left << User.Phone();
        std::cout << "| " << setw(20) << left << User.Email();
        std::cout << "| " << setw(10) << left << User.GetPassword();
        std::cout << "| " << setw(12) << left << User.GetPermissions();
    }

   public:
    static void ShowUsersList() {
        std::vector<clsUser> vUsers = clsUser::GetUsersList();

        std::string Title = "\t  User List Screen";
        std::string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        std::cout << setw(8) << left << ""
             << "\n\t_______________________________________________________";
        std::cout << "______________________________________________\n" << endl;

        std::cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        std::cout << "| " << left << setw(25) << "Full Name";
        std::cout << "| " << left << setw(12) << "Phone";
        std::cout << "| " << left << setw(20) << "Email";
        std::cout << "| " << left << setw(10) << "Password";
        std::cout << "| " << left << setw(12) << "Permissions";
        std::cout << setw(8) << left << ""
             << "\n\t_______________________________________________________";
        std::cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            std::cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : vUsers) {
                _PrintUserRecordLine(User);
                std::cout << endl;
            }

        std::cout << setw(8) << left << ""
             << "\n\t_______________________________________________________";
        std::cout << "______________________________________________\n" << endl;
    }
};