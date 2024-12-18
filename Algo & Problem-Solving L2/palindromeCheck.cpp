#include <iostream>

using namespace std;

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;
    } while (number < 0);
    return number;
}

int reverseNumber(int number) {
    int flippedNumber = 0;
    int remainder = 0;
    while (number > 0) {
        remainder = number % 10;
        number /= 10;
        flippedNumber = flippedNumber * 10 + remainder;
    }
    return flippedNumber;
}

bool isPalindrome(int number) { return number == reverseNumber(number); }

// Function to print the result
void printResult(int number) {
    cout << "The number " << number << " is "
         << (isPalindrome(number) ? "a palindrome" : "not a palindrome") << "." << endl;
}

int main() {
    printResult(readInput("Input a number: "));
    return 0;
}

// okay the instructor seperated the logic of palindrome check , and reversing which make sense
// noted okay make it more modular and seperate logic
// this is more easy to modify