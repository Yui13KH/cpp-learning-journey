#pragma once

#include <iostream>
#include <iomanip>
#include "../../Bank/clsCurrency.h"
#include "../core/clsScreen.h"

class clsCurrenciesListScreen : protected clsScreen {
   private:
    static void PrintCurrencyRecordLine(clsCurrency Currency) {
        std::cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.getCountry();
        std::cout << "| " << setw(8) << left << Currency.getCurrencyCode();
        std::cout << "| " << setw(8) << left << Currency.getCurrencyName();
        std::cout << "| " << setw(8) << left << Currency.getExchangeRate();
    }

   public:
    static void ShowCurrenciesListScreen() {
        std::vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        std::string Title = "Currency List Screen";
        std::string Subtitle = "( " + std::to_string(vCurrencies.size()) + " Currencies )";

        _DrawScreenHeader(Title, Subtitle);

        std::cout << setw(8) << left << ""
                  << "\n\t_______________________________________________________";
        std::cout << "_______________________________________________\n" << endl;

        std::cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        std::cout << "| " << left << setw(8) << "Code";
        std::cout << "| " << left << setw(45) << "Name";
        std::cout << "| " << left << setw(10) << "Rate/(1$)";
        std::cout << setw(8) << left << ""
                  << "\n\t_______________________________________________________";
        std::cout << "_______________________________________________\n" << endl;

        if (vCurrencies.size() == 0) {
            std::cout << "\t\t\t\tNo Currencies Avilable In the System!";
        } else {
            for (clsCurrency Currency : vCurrencies) {
                PrintCurrencyRecordLine(Currency);
                std::cout << std::endl;
            }

            cout << setw(8) << left << ""
                 << "\n\t_______________________________________________________";
            cout << "_______________________________________________\n" << endl;
        }
    }
};