#include <iostream>
#include <vector>

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

std::vector<int> fillVector() {
    std::vector<int> vNumbers;
    bool isDone = false;
    do {
        vNumbers.push_back(readValidNumber("Enter a number: "));
        std::cout << "Do you want to enter another number? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'n' || choice == 'N') {
            isDone = true;
        } else if (choice == 'y' || choice == 'Y') {
            isDone = false;
        } else {
            std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }

    } while (!isDone);
    return vNumbers;
}

void printVector(std::vector<int> &vNumbers) {
    for (int &number : vNumbers) {
        std::cout << number << " ";
    }
}

int main() {
    // exercise to let user input as many numbers they want in a vector and then print them out

    std::vector<int> vNumbers = fillVector();
    printVector(vNumbers);
}