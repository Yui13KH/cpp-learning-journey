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

    static std::string _ConverClientObjectToLine(clsBankClient Client,
                                                 std::string Seperator = "#//#") {
        string stClientRecord = "";
        stClientRecord += Client.FirstName() + Seperator;
        stClientRecord += Client.LastName() + Seperator;
        stClientRecord += Client.Email() + Seperator;
        stClientRecord += Client.Phone() + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    static std::vector<clsBankClient> _LoadClientsDataFromFile() {
        std::vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("../Clients.txt", ios::in);  // read Mode

        if (MyFile.is_open()) {
            std::string Line;

            while (getline(MyFile, Line)) {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    static void _SaveCleintsDataToFile(std::vector<clsBankClient> vClients) {
        fstream MyFile;
        MyFile.open("../Clients.txt", ios::out);  // overwrite

        string DataLine;

        if (MyFile.is_open()) {
            for (clsBankClient C : vClients) {
                DataLine = _ConverClientObjectToLine(C);
                MyFile << DataLine << endl;
            }

            MyFile.close();
        }
    }

    void _Update() {
        std::vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients) {
            if (C.AccountNumber() == AccountNumber()) {
                C = *this;
                break;
            }
        }

        _SaveCleintsDataToFile(_vClients);
    }

    void _AddDataLineToFile(std::string stDataLine) {
        fstream MyFile;
        MyFile.open("../Clients.txt", ios::out | ios::app);

        if (MyFile.is_open()) {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
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

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedUnknownMode = 2 };

    enSaveResults Save() {
        switch (_Mode) {
            case enMode::EmptyMode: {
                return enSaveResults::svFaildEmptyObject;
            }

            case enMode::UpdateMode: {
                _Update();

                return enSaveResults::svSucceeded;

                break;
            }
        }
        return enSaveResults::svFailedUnknownMode;
    }

    static bool IsClientExist(std::string AccountNumber) {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }
};