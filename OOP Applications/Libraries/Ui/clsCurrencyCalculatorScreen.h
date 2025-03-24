#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../Bank/clsCurrency.h"
#include "../Core/clsInputValidate.h"
#include "../Core/clsUtility.h"

class clsCurrencyCalculatorScreen : protected clsScreen {
   private:
    static float _ReadAmount() {
        std::cout << "\nEnter Amound To Convert: ";
        float Amount = 0;
        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static clsCurrency _GetCurrency(std::string Message) {
        std::string CurrencyCode;
        std::cout << Message << std::endl;

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
            std::cout << CurrencyCode << " is not a valid currency code." << std::endl;
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static void _PrintCurrencyCard(clsCurrency Currency, std::string Title = "Currency Card:") {
        std::cout << "\n" << Title << "\n";
        std::cout << "_____________________________\n";
        std::cout << "\nCountry    : " << Currency.getCountry();
        std::cout << "\nCode       : " << Currency.getCurrencyCode();
        std::cout << "\nName       : " << Currency.getCurrencyName();
        std::cout << "\nRate(1$) = : " << Currency.getExchangeRate();

        std::cout << "\n_____________________________\n";
    }

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1,
                                          clsCurrency Currency2)

    {
        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        std::cout << Amount << " " << Currency1.getCurrencyCode() << " = " << AmountInUSD
                  << " USD\n";

        if (Currency2.getCurrencyCode() == "USD") {
            return;
        }

        std::cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        std::cout << Amount << " " << Currency1.getCurrencyCode() << " = " << AmountInCurrency2
                  << " " << Currency2.getCurrencyCode();
    }

   public:
    static void ShowCurrencyCalculatorScreen() {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y') {
            clsUtility::clearScreen();

            _DrawScreenHeader("\tUpdate Currency Screen");

            clsCurrency CurrencyFrom = _GetCurrency("Enter Currency Code To Convert From:");

            clsCurrency CurrencyTo = _GetCurrency("Enter Currency Code To Convert To:");

            float Amount = _ReadAmount();

            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            std::cout << "\n\nDo you want to perform another calculation? y/n ? ";
            std::cin >> Continue;
        }
    }
};