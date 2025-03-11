#pragma once

#include <iostream>
#include "clsScreen.h"
#include "../Users/clsUser.h"
#include "../Core/clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen {
   private:
    static void _ReadUserInfo(clsUser& User) {
        std::cout << "\nEnter FirstName: ";
        User.SetFirstName(clsInputValidate::ReadString());

        std::cout << "\nEnter LastName: ";
        User.SetLastName(clsInputValidate::ReadString());

        std::cout << "\nEnter Email: ";
        User.SetEmail(clsInputValidate::ReadString());

        std::cout << "\nEnter Phone: ";
        User.SetPhone(clsInputValidate::ReadString());

        std::cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());

        std::cout << "\nEnter Permission: ";
        User.SetPermissions(_ReadPermissionsToSet());
    }

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

    static int _ReadPermissionsToSet() {
        int Permissions = 0;
        char Answer = 'n';

        std::cout << "\nDo you want to give full access? y/n? ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            return -1;
        }

        std::cout << "\nDo you want to give access to : \n ";

        std::cout << "\nShow Client List? y/n? ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pListClients;
        }

        std::cout << "\nAdd New Client? y/n? ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        std::cout << "\nDelete Client? y/n? ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        std::cout << "\nUpdate Client? y/n? ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        std::cout << "\nFind Client? y/n? ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        std::cout << "\nTransactions? y/n? ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        std::cout << "\nManage Users? y/n? ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;
    }

   public:
    static void ShowAddNewUserScreen() {
        _DrawScreenHeader("\t  Add New User Screen");

        std::string UserName = "";

        std::cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName)) {
            std::cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult) {
            case clsUser::enSaveResults::svSucceeded: {
                std::cout << "\nUser Addeded Successfully :-)\n";
                _PrintUser(NewUser);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject: {
                std::cout << "\nError User was not saved because it's Empty";
                break;
            }
            case clsUser::enSaveResults::svFaildUserExists: {
                std::cout << "\nError User was not saved because UserName is used!\n";
                break;
            }
        }
    }
};
