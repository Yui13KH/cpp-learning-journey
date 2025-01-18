#include "Utility.h"

void PrintFirstLetterOfEachWord(const std::string& input) {
    bool currentIndex = true;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            currentIndex = true;
        } else if (currentIndex) {
            printf("%c\t", input[i]);  
            currentIndex = false;
        }
    }
}

int main() {
    std::string input = utility::getValidString("Enter a string: ");

    PrintFirstLetterOfEachWord(input);
    return 0;
}

// command to compiler : g++ 23-ExtractInitials.cpp Utility.cpp -o name