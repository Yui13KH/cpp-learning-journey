#include <iostream>

using namespace std;

/*
int readInput(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;
    } while (number <= 0);
    return number;
}
stop working after the integer limit of 10 digits so i'll use a string operations instead
*/

string readNumber(string msg) {
    string strNumber;
    bool isValid;

    do {
        cout << msg;
        cin >> strNumber;
        isValid = true;

        // Validate that the input contains only digits
        for (char c : strNumber) {
            if (!isdigit(c)) {
                isValid = false;
                cout << "Invalid input. Please enter a number containing only digits." << endl;
                break;
            }
        }

    } while (!isValid);

    return strNumber;
}

char readSingleDigit(string msg) {
    string input;
    char digit;

    do {
        input = readNumber(msg);  // reusing the function
        if (input.length() == 1) {
            digit = input[0];  // only if its 1 digit it accepts and assigns it
        } else {
            cout << "Invalid input. Please enter a single digit." << endl;
            input = "";  // else doesnt accept , clears input to repeat
        }
    } while (input.empty());

    return digit;
}

int calculateFrequency(const string& number, char digit) {
    int counter = 0;

    for (char c : number) {
        if (c == digit) { // for of loop , goes over the number digits and compare with the inputted digit
            counter++;
        }
    }

    return counter;
}

void displayFrequency(const string& number, char digit, int frequency) {
    cout << "The frequency of " << digit << " in " << number << " is " << frequency << "." << endl;
}

int main() {
    string number = readNumber("Enter a number: ");
    char digit = readSingleDigit("Enter the digit to find its frequency: ");
    int frequency = calculateFrequency(number, digit); // pre compute the frequency
    displayFrequency(number, digit, frequency); // just prints 

    return 0;
}