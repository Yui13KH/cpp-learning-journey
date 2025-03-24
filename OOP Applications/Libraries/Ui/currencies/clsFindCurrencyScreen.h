#pragma once
#include <iostream>
#include "../core/clsScreen.h"
#include "../../Bank/clsCurrency.h"
#include "../../Core/clsInputValidate.h"

class clsCurrencyFindScreen : protected clsScreen {
   private:
    static void _PrintCurrency(clsCurrency Currency) {
        std::cout << "\nCurrency Card:\n";
        std::cout << "_____________________________\n";
        std::cout << "\nCountry    : " << Currency.getCountry();
        std::cout << "\nCode       : " << Currency.getCurrencyCode();
        std::cout << "\nName       : " << Currency.getCurrencyName();
        std::cout << "\nRate(1$) = : " << Currency.getExchangeRate();

        std::cout << "\n_____________________________\n";
    }

    static void _displayResult(clsCurrency currency) {
        if (!currency.IsEmpty()) {
            std::cout << "\nCurrency Found";
            _PrintCurrency(currency);
        } else {
            std::cout << "\nCurrency Was not found";
        }
    }

    public:

        static void ShowFindCurrencyScreen()
        {
            _DrawScreenHeader("\t Find Currency Screen");

            std::cout << "\nFind By: [1] Code, [2] Country ? ";
            short Answer = 1;

            cin >> Answer;
            if(Answer == 1)
            {
                std::string CurrencyCode;
                std::cout << "\nEnter Currency Code: ";
                CurrencyCode = clsInputValidate::ReadString();
                clsCurrency currency = clsCurrency::FindByCode(CurrencyCode);
                _displayResult(currency);
            } else 
            {
                std::string Country;
                std::cout << "\nEnter Country: ";
                Country = clsInputValidate::ReadString();
                clsCurrency currency = clsCurrency::FindByCountry(Country);
                _displayResult(currency);
            }
        }
};