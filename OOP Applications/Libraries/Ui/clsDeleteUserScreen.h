#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../Core/clsPerson.h"
#include "../Users/clsUser.h"
#include "../Core/clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen {
   private:
    static void _PrintUser(clsUser User) {
        std::cout << "\nUser Card:";
        std::cout << "\n___________________";
        std::cout << "\nFirstName   : " << User.FirstName();
        std::cout << "\nLastName    : " << User.LastName();
        std::cout << "\nFull Name   : " << User.FullName();
        std::cout << "\nEmail       : " << User.Email();
        std::cout << "\nPhone       : " << User.Phone();
        std::cout << "\nUser Name   : " << User.GetUserName();
        std::cout << "\nPassword    : " << User.GetPassword();
        std::cout << "\nPermissions : " << User.GetPermissions();
        std::cout << "\n___________________\n";
    }

   public:
    static void ShowDeleteUserScreen() {
        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        std::cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            std::cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        std::cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        std::cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (User1.Delete()) {
                std::cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            } else {
                std::cout << "\nError User Was not Deleted\n";
            }
        }
    }
};
