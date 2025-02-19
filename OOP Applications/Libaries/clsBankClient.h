#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "../Libaries/clsString.h"
#include "../Libaries/clsPerson.h"

class clsBankClient : public clsPerson {
   private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    std::string _AccountNumber;
    std::string _PinCode;
    float _AccountBalance;

    static clsBankClient _ConvertLineToClientObject(std::string Line,
                                                    std::string Seperator = "#//#") {
        std::vector<std::string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
                             vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject() {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

   public:
    clsBankClient(enMode Mode, std::string FirstName, std::string LastName, std::string Email,
                  std::string Phone, std::string AccountNumber, std::string PinCode,
                  float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone) {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

    std::string AccountNumber() { return _AccountNumber; }

    void SetPinCode(std::string PinCode) { _PinCode = PinCode; }

    std::string GetPinCode() { return _PinCode; }

    void SetAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; }

    float GetAccountBalance() { return _AccountBalance; }

    void Print() {
        std::cout << "\nClient Card:";
        std::cout << "\n----------------------------------\n";

        std::cout << std::left;  // Align text to the left
        std::cout << std::setw(15) << "First Name" << " : " << FirstName() << "\n";
        std::cout << std::setw(15) << "Last Name" << " : " << LastName() << "\n";
        std::cout << std::setw(15) << "Full Name" << " : " << FullName() << "\n";
        std::cout << std::setw(15) << "Email" << " : " << Email() << "\n";
        std::cout << std::setw(15) << "Phone" << " : " << Phone() << "\n";
        std::cout << std::setw(15) << "Acc. Number" << " : " << _AccountNumber << "\n";
        std::cout << std::setw(15) << "Password" << " : " << _PinCode << "\n";
        std::cout << std::setw(15) << "Balance" << " : " << _AccountBalance << "\n";

        std::cout << "----------------------------------\n";
    }

    static clsBankClient Find(std::string AccountNumber) {
        std::vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("../Clients.txt", ios::in);

        if (MyFile.is_open()) {
            std::string Line;
            while (getline(MyFile, Line)) {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber) {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(std::string AccountNumber, std::string PinCode) {
        std::vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("../Clients.txt", ios::in);

        if (MyFile.is_open()) {
            std::string Line;
            while (getline(MyFile, Line)) {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client._PinCode == PinCode) {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static bool IsClientExist(std::string AccountNumber) {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }
};