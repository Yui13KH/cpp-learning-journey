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

bool isPalindrome(int number) {
    int flippedNumber = 0;
    int initialNumber = number;
    int remainder = 0;
    while (number > 0) {
        remainder = number % 10;
        number /= 10;
        flippedNumber = flippedNumber * 10 + remainder;
    }
    return flippedNumber == initialNumber;
}

void printResult(int number) {
    cout << "The number " << number << " is "
         << (isPalindrome(number) ? "a palindrome" : "not a palindrome") << "." << endl; // similar to a if else statement with 2 possibilities "ternanry operator"
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    printResult(num);
    return 0;
}