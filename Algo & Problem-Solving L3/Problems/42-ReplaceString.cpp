#include "Utility.h"


std::string replaceSubstring(std::string input, const std::string& target, const std::string& replace) {
    size_t startIndex = 0;

    while ((startIndex = input.find(target, startIndex)) != std::string::npos) {
        input.erase(startIndex, target.length());
        input.insert(startIndex, replace);
        startIndex += replace.length();
    }

    return input;
}

int main() {
    std::string input = utility::getValidString("Enter the Input: ");
    std::string target = utility::getValidString("Enter the targeted word (case sensetive): ");
    std::string replace = utility::getValidString("Enter the replacement word: ");

    std::string result = replaceSubstring(input, target, replace);
    std::cout << "Edited text: " << result << std::endl;  // Output: "I love Python and Python is awesome!"

    return 0;
}

//compile: g++ 42-ReplaceString.cpp Utility.cpp -o name