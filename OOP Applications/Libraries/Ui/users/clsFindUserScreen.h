#pragma once
#include <iostream>
#include "../core/clsScreen.h"
#include "../../Core/clsPerson.h"
#include "../../Users/clsUser.h"
#include "../../Core/clsInputValidate.h"

class clsFindUserScreen : protected clsScreen {
   private:
    static void _PrintUser(clsUser User) {
        std::cout << "\nUser Card:";
        std::cout << "\n___________________";
        std::cout << "\nFirstName   : " << User.FirstName();
        std::cout << "\nLastName    : " << User.LastName();
        std::cout << "\nFull Name   : " << User.FullName();
        std::cout << "\nEmail       : " << User.Email();
        std::cout << "\nPhone       : " << User.Phone();
        std::cout << "\nUserName    : " << User.GetUserName();
        std::cout << "\nPassword    : " << User.GetPassword();
        std::cout << "\nPermissions : " << User.GetPermissions();
        std::cout << "\n___________________\n";
    }

   public:
    static void ShowFindUserScreen() {
        _DrawScreenHeader("\t  Find User Screen");

        string UserName;
        std::cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            std::cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty()) {
            std::cout << "\nUser Found :-)\n";
        } else {
            std::cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);
    }
};
