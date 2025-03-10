#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "../Core/clsString.h"
#include "../Core/clsPerson.h"
#include "../Core/clsUtility.h"

class clsBankClient : public clsPerson {
   private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;

    std::string _AccountNumber;
    std::string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLineToClientObject(std::string Line,
                                                    std::string Seperator = "#//#") {
        // Check if Line is empty
        if (Line.empty()) {
            std::cerr << "Error: Line is empty." << std::endl;
            // Handle error gracefully, maybe return an empty object or throw an exception
            throw std::invalid_argument("Line cannot be empty");
        }

        std::vector<std::string> vClientData = clsString::Split(Line, Seperator);

        // Check if vClientData has enough elements (7 elements)
        if (vClientData.size() < 7) {
            std::cerr << "Error: Insufficient data in Line." << std::endl;
            // Handle the error (maybe return a default object, throw an exception, etc.)
            throw std::invalid_argument("Insufficient data in Line");
        }

        // Now, we can safely convert to a clsBankClient object
        try {
            return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
                                 vClientData[3], vClientData[4], vClientData[5],
                                 stod(vClientData[6]));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid data when converting to double: " << e.what() << std::endl;
            throw;
        }
    }

    static std::string _ConvertClientObjecToLine(clsBankClient Client,
                                                 std::string Seperator = "#//#") {
        std::string stClientRecord = "";
        stClientRecord += Client.FirstName() + Seperator;
        stClientRecord += Client.LastName() + Seperator;
        stClientRecord += Client.Email() + Seperator;
        stClientRecord += Client.Phone() + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        stClientRecord += std::to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    static std::vector<clsBankClient> _LoadClientsDataFromFile() {
        std::vector<clsBankClient> vClients;

        std::fstream MyFile;
        MyFile.open("../Clients.txt", std::ios::in);  // read Mode

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
        std::fstream MyFile;
        MyFile.open("../Clients.txt", std::ios::out);  // overwrite

        std::string DataLine;

        if (MyFile.is_open()) {
            for (clsBankClient C : vClients) {
                if (C.MarkedForDeleted() == false) {
                    DataLine = _ConvertClientObjecToLine(C);
                    MyFile << DataLine << std::endl;
                }
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

    void _AddNew() { _AddDataLineToFile(_ConvertClientObjecToLine(*this)); }

    void _AddDataLineToFile(std::string stDataLine) {
        std::fstream MyFile;
        MyFile.open("../Clients.txt", std::ios::out | std::ios::app);

        if (MyFile.is_open()) {
            MyFile << stDataLine << std::endl;

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

    bool MarkedForDeleted() { return _MarkedForDelete; }

    std::string AccountNumber() { return _AccountNumber; }

    void SetPinCode(std::string PinCode) { _PinCode = PinCode; }

    std::string GetPinCode() { return _PinCode; }

    void SetAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; }

    float GetAccountBalance() { return _AccountBalance; }

    void Print() {
        std::cout << "\nClient Card:";
        std::cout << "\n" << clsUtility::RepeatChar('-', 34) << "\n";

        std::cout << std::left;  // Align text to the left
        std::cout << std::setw(15) << "First Name" << " : " << FirstName() << "\n";
        std::cout << std::setw(15) << "Last Name" << " : " << LastName() << "\n";
        std::cout << std::setw(15) << "Full Name" << " : " << FullName() << "\n";
        std::cout << std::setw(15) << "Email" << " : " << Email() << "\n";
        std::cout << std::setw(15) << "Phone" << " : " << Phone() << "\n";
        std::cout << std::setw(15) << "Acc. Number" << " : " << _AccountNumber << "\n";
        std::cout << std::setw(15) << "Password" << " : " << _PinCode << "\n";
        std::cout << std::setw(15) << "Balance" << " : " << _AccountBalance << "\n";

        std::cout << clsUtility::RepeatChar('-', 34) << "\n";
    }

    static clsBankClient Find(std::string AccountNumber) {
        std::vector<clsBankClient> vClients;

        std::fstream MyFile;
        MyFile.open("../Clients.txt", std::ios::in);

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

        std::fstream MyFile;
        MyFile.open("../Clients.txt", std::ios::in);

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

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

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
            case enMode::AddNewMode: {
                // This will add new record to file or database
                if (clsBankClient::IsClientExist(_AccountNumber)) {
                    return enSaveResults::svFaildAccountNumberExists;
                } else {
                    _AddNew();

                    // We need to set the mode to update after add new
                    _Mode = enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                }

                break;
            }
        }
        return enSaveResults::svFaildAccountNumberExists;
    }

    static bool IsClientExist(std::string AccountNumber) {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }

    bool Delete() {
        std::vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients) {
            if (C.AccountNumber() == _AccountNumber) {
                C._MarkedForDelete = true;
                break;
            }
        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;
    }

    static clsBankClient GetAddNewClientObject(std::string AccountNumber) {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static std::vector<clsBankClient> GetClientList() { return _LoadClientsDataFromFile(); }

    static double GetTotalBalances() {
        std::vector<clsBankClient> vClients = GetClientList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients) {
            TotalBalances += Client.GetAccountBalance();
        }

        return TotalBalances;
    }

    void Deposit(double Amount) {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount) {
        if (Amount > _AccountBalance) {
            return false;
        } else {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }
};