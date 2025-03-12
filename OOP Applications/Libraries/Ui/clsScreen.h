#pragma once
#include <iostream>
#include "../Core/Global.h"

class clsScreen {
   protected:
    static void _DrawScreenHeader(std::string Title, std::string SubTitle = "") {
        std::cout << "\t\t\t\t\t______________________________________";
        std::cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "") {
            std::cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        std::cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission) {
        if (!CurrentUser.CheckAccessPermission(Permission)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        } else {
            return true;
        }
    }
};