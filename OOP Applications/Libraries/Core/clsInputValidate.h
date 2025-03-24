#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate {
public:
    // Generic template for IsNumberBetween
    template <typename T>
    static bool IsNumberBetween(T Number, T From, T To) {
        return (Number >= From && Number <= To);
    }

    // Generic template for reading a number safely
    template <typename T>
    static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        T Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    // Generic template for reading a number within a range
    template <typename T>
    static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n") {
        T Number = ReadNumber<T>();

        while (!IsNumberBetween(Number, From, To)) {
            cout << ErrorMessage;
            Number = ReadNumber<T>();
        }
        return Number;
    }

    // Date validation remains the same
    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
        return ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
                (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))) ||

               ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
                (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)));
    }

    static bool IsValideDate(clsDate Date) { return clsDate::IsValidDate(Date); }

    static std::string ReadString() {
        std::string Text = "";
        getline(std::cin >> std::ws, Text);
        return Text;
    }
};
