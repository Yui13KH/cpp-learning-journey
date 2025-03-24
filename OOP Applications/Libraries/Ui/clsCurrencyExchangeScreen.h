#include "../Bank/clsCurrency.h"
#include "clsScreen.h"
#include "../Core/clsUtility.h"
#include "../Core/clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>
#include <iostream>

class clsCurrencyExhcnageScreen : protected clsScreen {
   private:
    enum enCurrenciesMainMenuOptions {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4,
        eMainMenu = 5
    };

    static short ReadCurrenciesMainMenuOptions() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice =
            clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrenciesMenue() {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        clsUtility::pauseExecution();
        ShowCurrenciesMenu();
    }

    static void _ShowCurrenciesListScreen() { clsCurrenciesListScreen::ShowCurrenciesListScreen(); }

    static void _ShowFindCurrencyScreen() { clsCurrencyFindScreen::ShowFindCurrencyScreen(); }

    static void _ShowUpdateCurrencyRateScreen() {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrenciesMainMenueOptions(
        enCurrenciesMainMenuOptions CurrenciesMainMenueOptions) {
        switch (CurrenciesMainMenueOptions) {
            case enCurrenciesMainMenuOptions::eListCurrencies: {
                clsUtility::clearScreen();
                _ShowCurrenciesListScreen();
                _GoBackToCurrenciesMenue();
                break;
            }

            case enCurrenciesMainMenuOptions::eFindCurrency: {
                clsUtility::clearScreen();
                _ShowFindCurrencyScreen();
                _GoBackToCurrenciesMenue();
                break;
            }

            case enCurrenciesMainMenuOptions::eUpdateCurrencyRate: {
                clsUtility::clearScreen();
                _ShowUpdateCurrencyRateScreen();
                _GoBackToCurrenciesMenue();
                break;
            }

            case enCurrenciesMainMenuOptions::eCurrencyCalculator: {
                clsUtility::clearScreen();
                _ShowCurrencyCalculatorScreen();
                _GoBackToCurrenciesMenue();
                break;
            }

            case enCurrenciesMainMenuOptions::eMainMenu: {
                // do nothing here the main screen will handle it :-) ;
            }
        }
    }

   public:
    static void ShowCurrenciesMenu() {
        clsUtility::clearScreen();
        _DrawScreenHeader("    Currancy Exhange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrenciesMainMenueOptions(
            (enCurrenciesMainMenuOptions)ReadCurrenciesMainMenuOptions());
    }
};
