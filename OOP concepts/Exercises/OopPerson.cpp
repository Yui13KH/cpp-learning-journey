#include <iostream>
#include <string>
#include <iomanip>

class clsPerson {
   private:
    int _id;
    std::string _firstName;
    std::string _lastName;
    std::string _email;
    std::string _phoneNumber;

   public:
    clsPerson(int id, std::string firstName, std::string lastName, std::string email,
              std::string phoneNumber) {
        _id = id;
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phoneNumber = phoneNumber;
    }  // constructor

    int getId() const { return _id; }
    std::string getFirstName() const { return _firstName; }
    std::string getLastName() const { return _lastName; }
    std::string getEmail() const { return _email; }
    std::string getPhoneNumber() const { return _phoneNumber; }

    void setFirstName(std::string firstName) { _firstName = firstName; }
    void setLastName(std::string lastName) { _lastName = lastName; }
    void setEmail(std::string email) { _email = email; }
    void setPhoneNumber(std::string phoneNumber) { _phoneNumber = phoneNumber; }

    std::string getFullName() const { return _firstName + " " + _lastName; }

    void printInfo() {
        std::cout << std::setw(20) << std::left << "Info" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << std::setw(20) << std::left << "ID" << _id << std::endl;
        std::cout << std::setw(20) << std::left << "FullName" << getFullName() << std::endl;
        std::cout << std::setw(20) << std::left << "Email" << _email << std::endl;
        std::cout << std::setw(20) << std::left << "PhoneNumber" << _phoneNumber << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    void SendEmail(std::string body, std::string subject) {
        std::cout << "Sending email to: " << _email << std::endl;
        std::cout << "Subject: " << subject << std::endl;
        std::cout << "Body: " << body << std::endl;
        std::cout << "Email sent successfully." << std::endl;
    }

    void SendSMS(std::string message) {
        std::cout << "Sending SMS to: " << _phoneNumber << std::endl;
        std::cout << "Message: " << message << std::endl;
        std::cout << "SMS sent successfully." << std::endl;
    }
};

int main() {
    // placeholder

    clsPerson Person1(10, "kato", "hirasawa", "katoEmail.gmail.com", "+963933333333");
    Person1.printInfo();

    Person1.SendEmail("Hello, this is a test email.", "Test Email");
    Person1.SendSMS("Hello, this is a test SMS.");

    return 0;
}