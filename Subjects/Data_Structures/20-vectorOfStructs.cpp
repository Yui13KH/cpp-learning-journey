#include <iostream>
#include <vector>
#include <string>

struct strUser {
    std::string firstName;
    std::string lastName;
    int age;
};

int readValidNumber(std::string msg) {
    int number = 0;
    bool isValid = false;
    do {
        std::cout << msg;
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a valid integer.\n";
        } else {
            std::cin.ignore(1000, '\n');
            isValid = true;
        }

    } while (!isValid);
    return number;
}

bool isAlphabeticOrSpace(const std::string& input) {
    for (char character : input) {
        if (!((character >= 'A' && character <= 'Z') ||
              (character >= 'a' && character <= 'z' || character == ' '))) {
            return false;
        }
    }
    return true;
}

std::string readValidString(std::string msg) {
    std::string input;
    bool isValid = false;
    do {
        std::cout << msg;
        std::cin >> input;
        isValid = isAlphabeticOrSpace(input);
        if (!isValid) {
            std::cout << "Invalid input. Please enter a valid string.\n";
        }
    } while (!isValid);
    return input;
}

void readUsers(std::vector<strUser>& user) {
    bool AddMore = true;
    do {
        strUser tempUser;
        tempUser.firstName = readValidString("Enter first name: ");
        tempUser.lastName = readValidString("Enter last name: ");
        tempUser.age = readValidNumber("Enter Age: ");
        user.push_back(tempUser);

        std::cout << "Do you want to add another user? (y/n): ";

        char choice;
        std::cin >> choice;
        if (choice == 'n' || choice == 'N') {
            AddMore = false;
        } else if (choice == 'y' || choice == 'Y') {
            AddMore = true;
        } else {
            std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
        std::cout << std::endl;
    } while (AddMore);
}

void printUsers(const std::vector<strUser>& users) {
    std::cout << "Users vector:\n\n";

    const int labelWidth = 10;  // Width for the labels

    for (const strUser& tempUser : users) {
        printf("%-*s : %s\n", labelWidth, "First name", tempUser.firstName.c_str());
        printf("%-*s : %s\n", labelWidth, "Last name", tempUser.lastName.c_str());
        printf("%-*s : %d\n", labelWidth, "Age", tempUser.age);
        std::cout << std::endl;  
    }
}

int main() {
    std::vector<strUser> user;
    readUsers(user);
    printUsers(user);

    return 0;
}