#include <iostream>
#include <cctype>  // For character classification functions

int main() {
    char ch = 'a';
    
    // isalpha: Checks if the character is an alphabetic letter (a-z, A-Z)
    if (std::isalpha(ch)) {
        std::cout << ch << " is an alphabetic letter." << std::endl;
    }

    // isdigit: Checks if the character is a digit (0-9)
    ch = '5';
    if (std::isdigit(ch)) {
        std::cout << ch << " is a digit." << std::endl;
    }

    // isupper: Checks if the character is uppercase
    ch = 'G';
    if (std::isupper(ch)) {
        std::cout << ch << " is uppercase." << std::endl;
    }

    // islower: Checks if the character is lowercase
    ch = 'g';
    if (std::islower(ch)) {
        std::cout << ch << " is lowercase." << std::endl;
    }

    // toupper: Converts the character to uppercase
    ch = 'b';
    std::cout << "Uppercase of " << ch << " is " << (char)std::toupper(ch) << std::endl;

    // tolower: Converts the character to lowercase
    ch = 'Y';
    std::cout << "Lowercase of " << ch << " is " << (char)std::tolower(ch) << std::endl;

    ch = '$';
    // ispunct: Checks if the character is a punctuation mark
    if (std::ispunct(ch)) {
        std::cout << ch << " is a punctuation mark." << std::endl;
    }

    return 0;
}
