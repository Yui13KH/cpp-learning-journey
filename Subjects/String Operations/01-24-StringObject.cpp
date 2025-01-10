#include <iostream>
#include <string>

#include <iostream>
#include <string>

int main() {
    // Demonstration of common string object functions
    std::string str = "Hello World!";

    // Output the length of the string
    std::cout << "Length of string: " << str.length() << std::endl;

    // Extract a substring starting from index 6
    std::cout << "Substring from index 6: " << str.substr(6) << std::endl;

    // Access a character at a specific index
    std::cout << "Character at index 0: " << str.at(0) << std::endl;

    // Find the position of a substring ("World")
    size_t position = str.find("World");
    if (position != std::string::npos) {
        std::cout << "Position of 'World': " << position << std::endl;
    } else {
        std::cout << "'World' not found in the string." << std::endl;
    }

    // Compare the string with another string
    std::cout << "Comparison with 'Hello Universe!': " << str.compare("Hello Universe!")
              << " (0: equal, non-0: different)" << std::endl;

    // Replace a substring ("World") with another string ("Universe")
    std::cout << "Replace 'World' with 'Universe': " << str.replace(position, 5, "Universe")
              << std::endl;

    // Insert a substring ("Beautiful ") at the beginning
    std::cout << "Insert 'Beautiful ' at the beginning: " << str.insert(0, "Beautiful ")
              << std::endl;

    // Erase a portion of the string (from index 7, remove 4 characters)
    std::cout << "Erase 4 characters from index 7: " << str.erase(7, 4) << std::endl;

    // Check if a substring exists after modifications
    if (str.find("World") == std::string::npos) {
        std::cout << "Substring 'World' not found after modifications." << std::endl;
    }

    return 0;
}
