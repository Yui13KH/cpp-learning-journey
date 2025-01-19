#include "Utility.h"

std::vector<std::string> splitString(const std::string& input) {
    bool isWord = false;
    std::vector<std::string> words;
    std::string temporaryString;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            isWord = false;
            words.push_back(temporaryString);
            temporaryString.clear();
        } else {
            temporaryString.push_back(input[i]);
            isWord = true;
        }
    }

    if (!temporaryString.empty()) {
        words.push_back(temporaryString);
    }

    return words;
}

int main() {
    std::string input = utility::getValidString("Enter a string: ");

    std::vector<std::string> words = splitString(input);

    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << std::endl;
    }

    return 0;
}

// command to compiler : g++ 35-StringToWords.cpp Utility.cpp -o name

