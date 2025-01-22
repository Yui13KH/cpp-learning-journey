#include <vector>
#include <string>
#include <iostream>

std::string JoinString(const std::vector<std::string> &input, const std::string &delimiter) {
    std::string joinedString;
    for (size_t i = 0; i < input.size(); i++) {
        joinedString += input[i];
        if (i != input.size() - 1) {
            joinedString += delimiter;
        }
    }
    std::cout << "vector joined: ";
    return joinedString;
}

std::string JoinString(const std::string input[], int size, const std::string &delimiter) {
    std::string joinedString;
    for (int i = 0; i < size; i++) {
        joinedString += input[i];
        if (i != size - 1) {
            joinedString += delimiter;
        }
    }
    std::cout << "String joined: ";
    return joinedString;
}

int main() {
    std::vector<std::string> seperatedStrings = {"hello", "world", "this", "is", "a", "test"};

    std::string seperatedStringsArray[] = {"hello", "world", "this", "is", "a", "test"};

    std::cout << JoinString(seperatedStrings, " ") << std::endl;

    std::cout << JoinString(seperatedStringsArray, 6, " ") << std::endl;

    return 0;
}

// compile: g++ 39-40JoinStrings.cpp Utility.cpp -o name