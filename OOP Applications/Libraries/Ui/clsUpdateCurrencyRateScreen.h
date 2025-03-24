#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../Bank/clsCurrency.h"
#include "../Core/clsInputValidate.h"

class clsUpdateCurrencyRateScreen : protected clsScreen {
   private:
    static float _ReadRate() {
        std::cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadNumber<float>();
        return NewRate;
    }

    static void _PrintCurrency(clsCurrency Currency) {
        std::cout << "\nCurrency Card:\n";
        std::cout << "_____________________________\n";
        std::cout << "\nCountry    : " << Currency.getCountry();
        std::cout << "\nCode       : " << Currency.getCurrencyCode();
        std::cout << "\nName       : " << Currency.getCurrencyName();
        std::cout << "\nRate(1$) = : " << Currency.getExchangeRate();

        std::cout << "\n_____________________________\n";
    }

   public:
    static void ShowUpdateCurrencyRateScreen() {
        _DrawScreenHeader("\t Update Currency Rate Screen");

        std::string CurrencyCode = "";

        std::cout << "\nEnter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
            std::cout << "\nCurrency Code Not Found, Try Again: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(currency);

        std::cout << "\n Are you sure you want to update the currency rate? (y/n) : ";
        char Answer = 'n';
        std::cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            std::cout << "\n\nUpdate Currency Rate:";
            std::cout << "\n____________________\n";

            currency.UpdateRate(_ReadRate());

            std::cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(currency);
        }
    }
};