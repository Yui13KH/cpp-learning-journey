#include <iostream>
#include <string>
using namespace std;

string readInput(string msg) {
    string strNumber;
    do {
        cout << msg << endl;
        cin >> strNumber;

        // Check if the input contains only digits
        bool isValid = true;
        for (char c : strNumber) {
            if (!isdigit(c)) {  // native cpp function ¯\_(ツ)_/¯ use what u got
                isValid = false;
                break;
            }
        }

        if (isValid) {
            return strNumber;  // Valid input
        } else {
            cout << "Invalid input. Please enter a positive number." << endl;
        }

    } while (true);
}

// sum of digits but from string to allow huge numbers without using unsigned long long
int sumOfDigits(const string& strNumber) {
    int sum = 0;
    for (char digit : strNumber) {
        sum += digit - '0';  // subtracts the ASCII value of '0' from digit to get its integer value
    }
    return sum;
}

void printSum(const string& strNumber) {
    cout << "Sum of digits of " << strNumber << " is " << sumOfDigits(strNumber) << endl;
}

int main() {
    string strNumber = readInput("Enter a number: ");
    printSum(strNumber);
    return 0;
}

// i know solutoins differ from instructor but i believe my solutions solve edge cases for example in this one the instructor uses math-based way to do it which wont work if ur going to enter idk a 1000 digit number even unsigned long long wont take it but in this way you can take any size of number