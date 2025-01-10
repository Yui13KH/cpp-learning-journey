#include <iostream>
#include <cmath>  // for sqrt to make optimization

using namespace std;

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg << " ";
        cin >> number;
    } while (number <= 0);
    return number;
}

bool checkPerfectNumber(int number) {
    if (number <= 1) return false;  // Perfect numbers are greater than 1
    int sum = 1;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            sum += i;
            if (i != number / i) {
                sum += number / i;
            }
        }
    }
    return number == sum;
}

void printPerfectNumbersToN(int number) {
    // loop use checkPerfectNumber function , returns true print , else dont
    for (int i = 1; i <= number; i++) {
        if (checkPerfectNumber(i)) {
            cout << i << endl;
        }
    }
}

int main() {
    printPerfectNumbersToN(readInput("enter upper limit for perfect numbers"));

    return 0;
}
/*
 checkPerfectNumber Function Explanation:

basically you only need to check up to sqrt(number) and then find the other divisors from the
numbers you found cause divisors come in pairs for example 28

1 28
2 14
4 7

see how the left side of small numbers are only about up to sqrt of 28 which is ~5
then i can find 14 and 7 by just dividing 28 by 2 and 4

so you only cheecking for sqrt(n) instead from 1 to n which is a huge optimization

just for refernce i ran the normal one with 1,000,000 and it took unknown time :D took too long for
me to wait like 41 minutes still no result

optimized one took 10 seconds :D
*/
