#include <iostream>
#include <string>
#include <iomanip>

class clsEmployee {
   private:
    int _id;
    std::string _firstName;
    std::string _lastName;
    std::string _title;
    std::string _email;
    std::string _phone;
    double _salary;
    std::string _department;

   public:
    clsEmployee(int id, std::string firstName, std::string lastName, std::string title,
                std::string email, std::string phone, double salary, std::string department) {
        _id = id;
        _firstName = firstName;
        _lastName = lastName;
        _title = title;
        _email = email;
        _phone = phone;
        _salary = salary;
        _department = department;
    }

    int getId() const { return _id; }
    std::string getFullName() const { return _firstName + " " + _lastName; }
    std::string getTitle() const { return _title; }
    std::string getEmail() const { return _email; }
    std::string getPhone() const { return _phone; }
    double getSalary() const { return _salary; }
    std::string getDepartment() const { return _department; }

    void SendEmail(std::string body, std::string subject) const {
        std::cout << "\n========================================\n";
        std::cout << "Sending Email to: " << _email << std::endl;
        std::cout << "Subject: " << subject << std::endl;
        std::cout << "Body:\n" << body << std::endl;
        std::cout << "Email sent successfully." << std::endl;
        std::cout << "========================================\n";
    }

    void SendSMS(std::string message) const {
        std::cout << "\n========================================\n";
        std::cout << "Sending SMS to: " << _phone << std::endl;
        std::cout << "Message:\n" << message << std::endl;
        std::cout << "SMS sent successfully." << std::endl;
        std::cout << "========================================\n";
    }

    void Print() const {
        std::cout << "\n========================================\n";
        std::cout << std::setw(20) << std::left << "Info" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << std::setw(20) << std::left << "Full Name" << getFullName() << std::endl;
        std::cout << std::setw(20) << std::left << "Title" << _title << std::endl;
        std::cout << std::setw(20) << std::left << "Email" << _email << std::endl;
        std::cout << std::setw(20) << std::left << "Phone" << _phone << std::endl;
        std::cout << std::setw(20) << std::left << "Salary" << _salary << std::endl;
        std::cout << std::setw(20) << std::left << "Department" << _department << std::endl;
        std::cout << "========================================\n";
    }
};

int main() {
    clsEmployee Employee1(10, "Kato", "Hirasawa", "Software Engineer", "katoEmail@gmail.com", "+963933333333", 50000, "IT");

    Employee1.Print();
    Employee1.SendEmail("Hello, this is a test email.", "Test Email");
    Employee1.SendSMS("Hello, this is a test SMS.");

    return 0;
}
