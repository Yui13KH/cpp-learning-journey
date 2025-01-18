#include "Utility.h"

void printFibonacciSeries(int size) {
    int a = 0 , b = 1;

    for (int i = 0; i < size; i++) {
        std::cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    int fibonacciSize = utility::getValidPositiveInt("Enter the size of the Fibonacci series: ");

    printFibonacciSeries(fibonacciSize);
    return 0;
}

// command to compiler : g++ 21-FibonacciSeries.cpp Utility.cpp -o name