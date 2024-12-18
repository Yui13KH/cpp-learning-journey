// Quick idea:
// 1. Count the digits of the number.
// 2. Calculate the divisor: 10^(digitCount - 1).
// 3. Integer division gives the leftmost digit.
// 4. Use remainder (number % divisor) to get the rest of the digits.
// 5. Repeat until the number becomes 0.
//
// Example (1234):
// - Divisor: 10^(4 - 1) = 1000
// - 1234 / 1000 = 1, remainder = 1234 % 1000 = 234
// - Update number to 234 and repeat:
//   - 234 / 100 = 2, remainder = 34
//   - 34 / 10 = 3, remainder = 4
//   - 4 / 1 = 4, remainder = 0
//
// check remainder till 0


#include <iostream>
#include <cmath>  // for power
using namespace std;

int numberOfDigits(int number) {
    int counter = 0;
    while (number > 0) {
        number /= 10;
        counter++;
    }
    return counter;
}

void extractAndPrintDigits(int number) {
    int digitCount = numberOfDigits(number);
    while (number > 0) {
        int divisor = pow(10, digitCount - 1);
        int leftMostDigit = number / divisor;
        cout << leftMostDigit << "\n";
        number %= divisor;
        digitCount--;
    }
}
// ok the instructor did it smartly , used a reverse number function which is easy to do , then just did the normal printing digits function 

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    extractAndPrintDigits(number);
    return 0;
}
