#pragma once
#include <iostream>
#include <string>
#include "../Libraries/InterfaceCommunication.h"

class clsPerson : public InterfaceCommunication {
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

    // Using abstract classes and interfaces enforces a structured implementation, ensuring
    // consistency and maintainability while allowing flexibility in how specific functionality is
    // defined.

    void SendEmail(std::string Title, std::string Body) override {
        std::cout << "Sending Email: " << Title << " to " << _Email << std::endl;
        std::cout << Body << std::endl;
    }

    void SendFax(std::string Title, std::string Body) override {
        std::cout << "Sending Fax: " << Title << " to " << _Phone << std::endl;
        std::cout << Body << std::endl;
    }

    void SendSMS(std::string Title, std::string Body) override {
        std::cout << "Sending SMS: " << Title << " to " << _Phone << std::endl;
        std::cout << Body << std::endl;
    }

    // just dummy functions to understand how it works
};