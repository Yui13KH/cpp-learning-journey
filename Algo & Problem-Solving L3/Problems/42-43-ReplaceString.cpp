#include "Utility.h"

bool caseInsensitiveCompare(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) return false;
    for (size_t i = 0; i < str1.length(); ++i) {
        if (std::tolower(str1[i]) != std::tolower(str2[i])) {
            return false;
        }
    }
    return true;
}

std::string replaceSubstring(std::string input, const std::string& target,
                             const std::string& replace, bool caseSensitive = true) {
    size_t startIndex = 0;

    while (true) {
        if (caseSensitive) {
            startIndex = input.find(target, startIndex);  // Case-sensitive search
        } else {
            // Case-insensitive search
            startIndex = std::string::npos;
            for (size_t i = 0; i + target.length() <= input.length(); ++i) {
                if (caseInsensitiveCompare(input.substr(i, target.length()), target)) {
                    startIndex = i;
                    break;
                }
            }
        }

        if (startIndex == std::string::npos) break;

        // Replace the target substring
        input.erase(startIndex, target.length());
        input.insert(startIndex, replace);

        // Move the startIndex forward
        startIndex += replace.length();
    }

    return input;
}

int main() {
    // std::string input = utility::getValidString("Enter the Input: ");
    // std::string target = utility::getValidString("Enter the targeted word (case sensetive): ");
    // std::string replace = utility::getValidString("Enter the replacement word: ");
    // to allow user input but nah

    std::string input = "I love C++ and c++ is awesome!";
    std::string target = "C++";
    std::string replace = "Python";

    std::string result1 = replaceSubstring(input, target, replace, true);
    std::cout << "case sensetive: " << result1 << std::endl;

    std::string result2 = replaceSubstring(input, target, replace, false);
    std::cout << "case insensetive: " << result2 << std::endl;

    return 0;
}

// compile: g++ 42-43-ReplaceString.cpp Utility.cpp -o name