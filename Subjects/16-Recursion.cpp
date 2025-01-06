#include <iostream>

int printPower(int base, int power) {
    if (power == 0) {
        return 1;
    }
    return base * printPower(base, power - 1);
}

int main() {
    int base, power;
    std::cout << "Enter the base: ";
    std::cin >> base;
    std::cout << "Enter the power: ";
    std::cin >> power;

    std::cout << "The result is: " << printPower(base, power);
    return 0;
}
