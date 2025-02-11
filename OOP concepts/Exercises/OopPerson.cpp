#include <iostream>
#include <string>
#include <iomanip>

class clsPerson {
   private:
    int _id;
    std::string _firstName;
    std::string _lastName;
    std::string _email;
    std::string _phone;

   public:
    clsPerson() {}  // Default Constructor so you can call inhereted classes with no parameters

    clsPerson(
        int id, std::string firstName, std::string lastName,
        std::string email,  // Perameterized Constructor , it overwrites the default constructor
        std::string phone) {
        _id = id;
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }

    int getId() const { return _id; }
    std::string getFullName() const { return _firstName + " " + _lastName; }
    std::string getEmail() const { return _email; }
    std::string getPhone() const { return _phone; }

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
        std::cout << std::setw(20) << std::left << "Email" << _email << std::endl;
        std::cout << std::setw(20) << std::left << "Phone" << _phone << std::endl;
        std::cout << "========================================\n";
    }
};

class clsEmployee : public clsPerson {
   private:
    std::string _title;
    std::string _department;
    double _salary;

   public:
    clsEmployee(int id, std::string firstName, std::string lastName, std::string email,
                std::string phone, std::string title, std::string department, double salary)
        : clsPerson(id, firstName, lastName, email, phone) {
        _title = title;
        _department = department;
        _salary = salary;
    }
    void setTitle(std::string title) { _title = title; }
    void setDepartment(std::string department) { _department = department; }
    void setSalary(double salary) { _salary = salary; }

    std::string getTitle() const { return _title; }
    std::string getDepartment() const { return _department; }
    double getSalary() const { return _salary; }

    void Print() const {
        std::cout << "\n========================================\n";
        std::cout << std::setw(20) << std::left << "Info" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << std::setw(20) << std::left << "ID" << getId() << std::endl;
        std::cout << std::setw(20) << std::left << "Full Name" << getFullName() << std::endl;
        std::cout << std::setw(20) << std::left << "Email" << getEmail() << std::endl;
        std::cout << std::setw(20) << std::left << "Phone" << getPhone() << std::endl;
        std::cout << std::setw(20) << std::left << "Title" << _title << std::endl;
        std::cout << std::setw(20) << std::left << "Department" << _department << std::endl;
        std::cout << std::setw(20) << std::left << "Salary" << _salary << std::endl;
        std::cout << "========================================\n";
    }
};

class clsDeveloper : public clsEmployee {
   private:
    std::string _mainProgrammingLanguage;

   public:
    clsDeveloper(int id, std::string firstName, std::string lastName, std::string email,
                 std::string phone, std::string title, std::string department, double salary,
                 std::string mainProgrammingLanguage)
        : clsEmployee(id, firstName, lastName, email, phone, title, department, salary) {
        _mainProgrammingLanguage = mainProgrammingLanguage;
    }

    std::string getMainProgrammingLanguage() const { return _mainProgrammingLanguage; }
    void setMainProgrammingLanguage(std::string mainProgrammingLanguage) {
        _mainProgrammingLanguage = mainProgrammingLanguage;
    }

    void Print() const {
        std::cout << "\n========================================\n";
        std::cout << std::setw(15) << std::left << "Info" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << std::setw(15) << std::left << "ID" << getId() << std::endl;
        std::cout << std::setw(15) << std::left << "Full Name" << getFullName() << std::endl;
        std::cout << std::setw(15) << std::left << "Email" << getEmail() << std::endl;
        std::cout << std::setw(15) << std::left << "Phone" << getPhone() << std::endl;
        std::cout << std::setw(15) << std::left << "Title" << getTitle() << std::endl;
        std::cout << std::setw(15) << std::left << "Department" << getDepartment() << std::endl;
        std::cout << std::setw(15) << std::left << "Salary" << getSalary() << std::endl;
        std::cout << std::setw(15) << std::left << "P Language" << getMainProgrammingLanguage()
                  << std::endl;
        std::cout << "========================================\n";
    }
};

int main() {
    // placeholder

    clsDeveloper Developer1(1, "kato", "hirasawa", "katogmail.com", "+963123456789",
                            "Software Engineer", "IT", 100000, "C++");

    Developer1.Print();

    return 0;
}