#include "Utility.h"

std::vector<std::string> splitTokens(std::string line, std::string delimiter) {
    std::vector<std::string> vString;
    short position = 0;
    std::string word;

    while ((position = line.find(delimiter)) != std::string::npos) {
        word = line.substr(0, position);
        if (word != "") {
            vString.push_back(word);
        }

        line.erase(0, position + delimiter.length());
    }

    if (line != "") {
        vString.push_back(line);
    }

    return vString;
}

void printTokens(const std::vector<std::string>& tokens) {
    for (size_t i = 0; i < tokens.size(); i++) {
        std::cout << tokens[i] << std::endl;
    }

    std::cout << "Total tokens: " << tokens.size() << std::endl;
}

int main() {
    std::string input = utility::getValidString("Enter a string: ");
    std::string delimiter = utility::getValidString("Enter a delimiter: ");

    std::vector<std::string> tokens = splitTokens(input, delimiter);
    

    printTokens(tokens);

    return 0;
}

// compile: g++ 37-splitAndCountTokens.cpp Utility.cpp -o name
