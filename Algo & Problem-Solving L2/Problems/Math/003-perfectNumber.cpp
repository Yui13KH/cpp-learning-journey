#include <iostream>
using namespace std;

int readInput(string msg) {
    int number;
    do {
        cout << msg;
        cin >> number;
    } while (number <= 0);
    return number;
}

bool checkPerfectNumber(int number) {
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) sum += i;
    }
    return sum == number;
}

void printResult(int number) {
    cout << number << " is "
         << (checkPerfectNumber(number) ? "a perfect number" : "not a perfect number"); // ternary operator i just know it from js easier then if else
}

int main() { printResult(readInput("Enter a number to check if it's a perfect number: ")); }