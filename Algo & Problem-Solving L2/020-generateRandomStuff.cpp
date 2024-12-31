#include <iostream>
#include <cstdlib>

using namespace std;

enum charType { CAPITAL_LETTER, SMALL_LETTER, DIGIT, SYMBOL };

int randomNumber(int from, int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}

char GenerateCapitalLetter() { return char(randomNumber(65, 90)); }

char GenerateSmallLetter() { return char(randomNumber(97, 122)); }

int GenerateDigit() {
    int digit = randomNumber(0, 9);
    return digit;
}

char GenerateSymbol() {
    int ranges[4][2] = {
        {33, 47}, {58, 64}, {91, 96}, {123, 126}};  // ranges of ascii symbols check them out
    int rangeIndex = randomNumber(0, 3);            // gets one of the ranges randomly
    return char(randomNumber(ranges[rangeIndex][0], ranges[rangeIndex][1]));
}

char generateCharacter(charType type) {
    switch (type) {
        case CAPITAL_LETTER:
            return GenerateCapitalLetter();
        case SMALL_LETTER:
            return GenerateSmallLetter();
        case DIGIT:
            return char(GenerateDigit() + '0');  // Convert digit to character
        case SYMBOL:
            return GenerateSymbol();
        default:
            throw std::invalid_argument("Invalid character type");
    }
}

void printCharacter(charType type) {
    char c = generateCharacter(type);
    string typeName;
    switch (type) {
        case CAPITAL_LETTER:
            typeName = "capital letter";
            break;
        case SMALL_LETTER:
            typeName = "small letter";
            break;
        case DIGIT:
            typeName = "digit";
            break;
        case SYMBOL:
            typeName = "symbol";
            break;
        default:
            throw std::invalid_argument(
                "\033[31mInvalid character type\033[0m");  // uses ansi escape code to make it red 
    }
    cout << "\033[32mRandom " << typeName << ": " << c << "\033[0m" << endl; // uses ansi to make it green
}

int main() {
    srand((unsigned)time(NULL));

    printCharacter(CAPITAL_LETTER);
    printCharacter(SMALL_LETTER);
    printCharacter(DIGIT);
    printCharacter(SYMBOL);

    return 0;
}