#include <iostream>
#include <cmath>  // for ceil and sqrt
using namespace std;

// ok so logically speaking in order
// take input from the user to what N is , go through a loop checking i for being a prime or not ,
// if i is prime , print it , if not continue
/* You only need to check divisibility up to sqrt(n). If n is not prime, it must have factors x and
 y such that x * y = n. If both x and y were greater than sqrt(n), their product would exceed n.*/

int readInput(string msg) {
    int number;
    do {
        cout << msg << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

bool checkPrime(int number) {
    if (number < 2) return false;
    if (number == 2) return true;       // 2 is the only even prime
    if (number % 2 == 0) return false;  // Eliminate even numbers

    int limit = sqrt(number);              // Calculate square root once
    for (int i = 3; i <= limit; i += 2) {  // Check only odd numbers
        if (number % i == 0) return false;
    }
    return true;
}
// the instructor used an enum which makes sense IF you're going to add more possibilities but for a only check prime i dont get why you would use an enum

void printPrimes(int number) {
    for (int i = 0; i < number; i++) {
        if (checkPrime(i)) {
            cout << i << endl;
        }
    }
}

int main() {
    int limit = readInput("Enter the maximum number to check for primes: ");
    printPrimes(limit);
}