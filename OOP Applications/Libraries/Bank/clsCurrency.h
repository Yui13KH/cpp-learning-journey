#pragma once

#include <iostream>
#include <string>
#include "../Core/clsString.h"
#include <vector>
#include <fstream>
class clsCurrency {
   private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _ExchangeRate;

    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#") {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
                           stod(vCurrencyData[3]));
    }

    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {
        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.getCountry() + Seperator;
        stCurrencyRecord += Currency.getCurrencyCode() + Seperator;
        stCurrencyRecord += Currency.getCurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.getExchangeRate());

        return stCurrencyRecord;
    }

    static vector<clsCurrency> _LoadCurrencysDataFromFile() {
        vector<clsCurrency> vCurrencys;

        fstream MyFile;
        MyFile.open("../Currencies.txt", ios::in);  // read Mode

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

                vCurrencys.push_back(Currency);
            }

            MyFile.close();
        }

        return vCurrencys;
    }

    static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrencys) {
        fstream MyFile;
        MyFile.open("../Currencies.txt", ios::out);  // overwrite

        string DataLine;

        if (MyFile.is_open()) {
            for (clsCurrency C : vCurrencys) {
                DataLine = _ConverCurrencyObjectToLine(C);
                MyFile << DataLine << endl;
            }

            MyFile.close();
        }
    }

    void _Update() {
        vector<clsCurrency> _vCurrencys;
        _vCurrencys = _LoadCurrencysDataFromFile();

        for (clsCurrency& C : _vCurrencys) {
            if (C.getCurrencyCode() == getCurrencyCode()) {
                C = *this;
                break;
            }
        }

        _SaveCurrencyDataToFile(_vCurrencys);
    }

    static clsCurrency _GetEmptyCurrencyObject() {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

   public:
    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _ExchangeRate = Rate;
    }

    static vector<clsCurrency> GetAllUSDRates() { return _LoadCurrencysDataFromFile(); }

    bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

    string getCountry() { return _Country; }

    string getCurrencyCode() { return _CurrencyCode; }

    string getCurrencyName() { return _CurrencyName; }

    void UpdateRate(float NewRate) {
        _ExchangeRate = NewRate;
        _Update();
    }

    float getExchangeRate() { return _ExchangeRate; }

    static clsCurrency FindByCode(string CurrencyCode) {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("../Currencies.txt", ios::in);  // read Mode

        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (Currency.getCurrencyCode() == CurrencyCode) {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();
        }

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country) {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open("../Currencies.txt", ios::in);  // read Mode

        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.getCountry()) == Country) {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();
        }

        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode) {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());
    }

    static vector<clsCurrency> GetCurrenciesList() { return _LoadCurrencysDataFromFile(); }

    float ConvertToUSD(float Amount) {
        // placeoholder
        return (float)(Amount / _ExchangeRate);
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2) {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.getCurrencyCode() == "USD")
            return AmountInUSD;
        else
            return (float)(AmountInUSD * Currency2.getExchangeRate());
    }
};
