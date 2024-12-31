#include <iostream>
#include <cstdlib>

// ok after watching instructor's video he made use of enums to make the key more randomized
// even though he didnt specify , he only said capital letters

enum charType { CAPITAL_LETTER, SMALL_LETTER, DIGIT, SYMBOL };

using namespace std;

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;
    } while (number <= 0);
    return number;
}

int generateRandomNumber(int min, int max) { return rand() % (max - min + 1) + min; }

char GenerateCapitalLetter() { return char(generateRandomNumber(65, 90)); }

char GenerateSmallLetter() { return char(generateRandomNumber(97, 122)); }

int GenerateDigit() {
    int digit = generateRandomNumber(0, 9);
    return digit;
}

char GenerateSymbol() {
    int ranges[4][2] = {
        {33, 47}, {58, 64}, {91, 96}, {123, 126}};  // ranges of ascii symbols check them out
    int rangeIndex = generateRandomNumber(0, 3);            // gets one of the ranges randomly
    return char(generateRandomNumber(ranges[rangeIndex][0], ranges[rangeIndex][1]));
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

string generateWord(int length) {
    string word = "";
    for (int i = 0; i < length; i++) {
        word += generateCharacter(charType(generateRandomNumber(0, 3)));
    }
    return word;
}

string generateKey() {
    string key = "";
    for (int i = 0; i < 4; i++) {
        key += generateWord(4);

        if (i != 3) {
            key += "-";
        }
    }

    return key;
}

void printKeys(int number) {
    for (int i = 0; i < number; i++) {
        cout << "Key [" << i + 1 << "] : " << generateKey() << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    printKeys(readInput("Enter the number of keys to generate: "));

    return 0;
}