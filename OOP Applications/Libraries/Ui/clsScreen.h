#pragma once
#include <iostream>

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
};