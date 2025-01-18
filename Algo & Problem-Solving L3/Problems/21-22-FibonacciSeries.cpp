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

/*
void printFibonacciSeriesRecursion(int size, int a = 0, int b = 1) {
    if (size == 0) {
        return;
    }

    std::cout << a << " ";
    int next = a + b;
    printFibonacciSeriesRecursion(size - 1, b, next);
}
recursive version
*/


int main() {
    int fibonacciSize = utility::getValidPositiveInt("Enter the size of the Fibonacci series: ");

    printFibonacciSeries(fibonacciSize);
    return 0;
}

// command to compiler : g++ 21-FibonacciSeries.cpp Utility.cpp -o name