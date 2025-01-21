#include "Utility.h"

void splitTokens(std::string& input, std::vector<std::string>& tokens, char delimiter = ' ') {
    size_t position = 0;

    while ((position = input.find(delimiter)) != std::string::npos) {
        tokens.push_back(input.substr(0, position));
        input.erase(0, position + 1);
    }

    if (!input.empty()) {
        tokens.push_back(input);
    }
}

void printTokens(const std::vector<std::string>& tokens) {
    for (size_t i = 0; i < tokens.size(); i++) {
        std::cout << tokens[i] << std::endl;
    }

    std::cout << "Total tokens: " << tokens.size() << std::endl;
}

int main() {
    std::string input = utility::getValidString("Enter a string: ");
    std::vector<std::string> tokens;

    splitTokens(input, tokens);

    printTokens(tokens);

    return 0;
}


