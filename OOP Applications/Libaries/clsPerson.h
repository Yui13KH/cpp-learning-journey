#pragma once
#include <iostream>
#include <string>

class clsPerson {
   private:
    std::string _FirstName;
    std::string _LastName;
    std::string _Email;
    std::string _Phone;

   public:
    clsPerson(std::string FirstName, std::string LastName, std::string Email, std::string Phone) {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // getters
    std::string FirstName() { return _FirstName; }
    std::string LastName() { return _LastName; }
    std::string FullName() { return (_FirstName + " " + _LastName); }
    std::string Email() { return _Email; }
    std::string Phone() { return _Phone; }

    // setters
    void SetFirstName(const std::string& FirstName) { _FirstName = FirstName; }
    void SetLastName(const std::string& LastName) { _LastName = LastName; }
    void SetEmail(const std::string& Email) { _Email = Email; }
    void SetPhone(const std::string& Phone) { _Phone = Phone; }
};