#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

class clsUser : public clsPerson {
   private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    std::string _UserName;
    std::string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;

    static clsUser _ConvertLinetoUserObject(std::string Line, std::string Seperator = "#//#") {
        std::vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3],
                       vUserData[4], vUserData[5], stoi(vUserData[6]));
    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#") {
        string UserRecord = "";
        UserRecord += User.FirstName() + Seperator;
        UserRecord += User.LastName() + Seperator;
        UserRecord += User.Email() + Seperator;
        UserRecord += User.Phone() + Seperator;
        UserRecord += User.GetUserName() + Seperator;
        UserRecord += User.GetPassword() + Seperator;
        UserRecord += to_string(User.GetPermissions());

        return UserRecord;
    }

    static vector<clsUser> _LoadUsersDataFromFile() {
        std::vector<clsUser> vUsers;

        fstream MyFile;
        MyFile.open("../Users.txt", std::ios::in);  // read Mode

        if (MyFile.is_open()) {
            std::string Line;

            while (getline(MyFile, Line)) {
                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();
        }

        return vUsers;
    }

    static void _SaveUsersDataToFile(vector<clsUser> vUsers) {
        fstream MyFile;
        MyFile.open("../Users.txt", ios::out);  // overwrite

        std::string DataLine;

        if (MyFile.is_open()) {
            for (clsUser U : vUsers) {
                if (U.MarkedForDeleted() == false) {
                    // we only write records that are not marked for delete.
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update() {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers) {
            if (U.GetUserName() == _UserName) {
                U = *this;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);
    }

    void _AddNew() { _AddDataLineToFile(_ConverUserObjectToLine(*this)); }

    void _AddDataLineToFile(std::string stDataLine) {
        fstream MyFile;
        MyFile.open("../Users.txt", std::ios::out | std::ios::app);

        if (MyFile.is_open()) {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static clsUser _GetEmptyUserObject() {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

   public:
    clsUser(enMode Mode, std::string FirstName, std::string LastName, std::string Email,
            std::string Phone, std::string UserName, std::string Password, int Permissions)
        : clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

    bool MarkedForDeleted() { return _MarkedForDelete; }

    string GetUserName() { return _UserName; }

    void SetUserName(string UserName) { _UserName = UserName; }

    void SetPassword(string Password) { _Password = Password; }

    string GetPassword() { return _Password; }

    void SetPermissions(int Permissions) { _Permissions = Permissions; }

    int GetPermissions() { return _Permissions; }

    static clsUser Find(std::string UserName) {
        fstream MyFile;
        MyFile.open("../Users.txt", ios::in);  // read Mode

        if (MyFile.is_open()) {
            std::string Line;
            while (getline(MyFile, Line)) {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName) {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(std::string UserName, std::string Password) {
        fstream MyFile;
        MyFile.open("Users.txt", std::ios::in);  // read Mode

        if (MyFile.is_open()) {
            std::string Line;
            while (getline(MyFile, Line)) {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName && User.GetPassword() == Password) {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save() {
        switch (_Mode) {
            case enMode::EmptyMode: {
                if (IsEmpty()) {
                    return enSaveResults::svFaildEmptyObject;
                }
            }

            case enMode::UpdateMode: {
                _Update();
                return enSaveResults::svSucceeded;

                break;
            }

            case enMode::AddNewMode: {
                // This will add new record to file or database
                if (clsUser::IsUserExist(_UserName)) {
                    return enSaveResults::svFaildUserExists;
                } else {
                    _AddNew();
                    // We need to set the mode to update after add new
                    _Mode = enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                }

                break;
            }
        }
    }

    static bool IsUserExist(std::string UserName) {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete() {
        std::vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers) {
            if (U.GetUserName() == _UserName) {
                U._MarkedForDelete = true;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

    static clsUser GetAddNewUserObject(std::string UserName) {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static std::vector<clsUser> GetUsersList() { return _LoadUsersDataFromFile(); }
};
