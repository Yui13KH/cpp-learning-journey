#include <vector>
#include <string>
#include <iostream>

std::string JoinString(std::vector<std::string> input, std::string delimiter) {
    std::string joinedString = "";

    for (int i = 0; i < input.size(); i++) {
        if (i == 0) {
            joinedString += input[i];
        } else if (i < input.size() - 1) {
            joinedString += delimiter + input[i];
        } else {
            joinedString += input[i];
        }
    }
    std::cout << "Vector joined string:" << std::endl;
    return joinedString;
}

std::string JoinString(std::string input[], int size, std::string delimiter) {
    std::string joinedString = "";

    for (int i = 0; i < size; i++) {
        joinedString += input[i];
        if (i != size - 1) {
            joinedString += delimiter;
        }
    }
    std::cout << "Array joined string:" << std::endl;
    return joinedString;
}

int main() {
    std::vector<std::string> seperatedStrings = {"hello", "world", "this", "is", "a", "test"};

    std::string seperatedStringsArray[] = {"hello", "world", "this", "is", "a", "test"};

    std::cout << JoinString(seperatedStrings, " ") << std::endl;

    std::cout << JoinString(seperatedStringsArray, 6, " ") << std::endl;

    return 0;
}

// compile: g++ 38-TrimString.cpp Utility.cpp -o name