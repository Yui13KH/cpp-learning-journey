#include <iostream>
#include <string>

class Person {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _profession;
    int _age;

public:
    // Setters
    void setFirstName(const std::string& firstName) { _firstName = firstName; }
    void setLastName(const std::string& lastName) { _lastName = lastName; }
    void setProfession(const std::string& profession) { _profession = profession; }
    void setAge(int age) { _age = age; }

    // Getters
    std::string getFirstName() const { return _firstName; }
    std::string getLastName() const { return _lastName; }
    std::string getProfession() const { return _profession; }
    int getAge() const { return _age; }

    // Print Information
    void printInfo() const {
        std::cout << "Name: " << _firstName << " " << _lastName << std::endl;
        std::cout << "Profession: " << _profession << std::endl;
        std::cout << "Age: " << _age << std::endl;
    }
};

int main() {
    Person person;
    person.setFirstName("John");
    person.setLastName("Doe");
    person.setProfession("Software Engineer");
    person.setAge(30);

    person.printInfo(); // Display person information

    return 0;
}

