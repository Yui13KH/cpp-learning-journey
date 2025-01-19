#include <iostream>
#include <string>
#include <cctype>

char invertCase(char c) {
    return std::isupper(c) ? std::tolower(c) : std::toupper(c);
    // initially used a ascii range check but this simplifies the code
}

std::string invertStringCase(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        c = invertCase(c);
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string output = invertStringCase(input);
    std::cout << "Inverted case string: " << output << std::endl;

    return 0;
}


