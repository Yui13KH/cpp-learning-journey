#include "Utility.h"

int findFirstAlphaPos(const std::string& input) {
    for (int i = 0; i < input.size(); ++i) {
        if (std::isalpha(input[i])) {
            return i;
        }
    }
    return -1;
}

int findLastAlphaPos(const std::string& input) {
    for (int i = input.size() - 1; i >= 0; --i) {
        if (std::isalpha(input[i])) {
            return i;
        }
    }
    return -1;
}

std::string trimString(const std::string& input) {
    int firstPos = findFirstAlphaPos(input);
    int lastPos = findLastAlphaPos(input);

    if (firstPos == -1 || lastPos == -1) {
        return "";
    }

    return input.substr(firstPos, lastPos - firstPos + 1);
}

std::string trimTrailingSpaces(const std::string& input) {
    int lastPos = findLastAlphaPos(input);
    if (lastPos == -1) {
        return "";
    }
    return input.substr(0, lastPos + 1);
}

std::string trimLeadingSpaces(const std::string& input) {
    int firstPos = findFirstAlphaPos(input);
    if (firstPos == -1) {
        return "";
    }
    return input.substr(firstPos);
}

int main() {
    std::string input = utility::getValidString("Enter a string: ");

    std::cout << "Original string: " << input << std::endl;
    std::cout << "Trimmed string: " << trimString(input) << std::endl;
    std::cout << "Trimmed trailing spaces: " << trimTrailingSpaces(input) << std::endl;
    std::cout << "Trimmed leading spaces: " << trimLeadingSpaces(input) << std::endl;

    return 0;
}

//compile: g++ 38-TrimString.cpp Utility.cpp -o name