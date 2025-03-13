#include <iostream>
#include "../Libraries/Ui/clsLoginScreen.h"
#include "../Libraries/Core/clsUtility.h"

int main() {
    while (true) {
        if(!clsLoginScreen::ShowLoginScreen()){
            break;
        }
        
    }

    return 0;
}