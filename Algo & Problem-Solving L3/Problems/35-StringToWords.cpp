#include "Utility.h"
#include <iostream>
#include <string>

void splitAndPrintWords(const std::string& input) {
    std::string temp = input;
    size_t pos = 0;

    while ((pos = temp.find(' ')) != std::string::npos) {
        std::string word = temp.substr(0, pos);
        if (!word.empty()) {
            std::cout << word << '\n';
        }

        temp.erase(0, pos + 1);
    }

    if (!temp.empty()) {
        std::cout << temp << '\n';
    }
}

int main() {
    std::string input = utility::getValidString("Enter a string: ");

    splitAndPrintWords(input);

    return 0;
}

/*
Ok, so basically this finds each word before a space, prints it, 
then removes it from the string until no spaces are left. 
Finally, it prints the last word if there’s any.
faster then manually making the string and then pushing it to a vector

Command to compile: g++ 35-StringToWords.cpp Utility.cpp -o name
*/
