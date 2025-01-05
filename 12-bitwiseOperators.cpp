#include <iostream>

int main() {
    // Bitwise AND
    int a = 5;   // 0101 in binary
    int b = 3;   // 0011 in binary
    int andResult = a & b; // 0001 in binary
    std::cout << "Bitwise AND: " << andResult << std::endl; // Outputs 1

    // Use case: Checking if a number is even
    int number = 10;
    if ((number & 1) == 0) {
        std::cout << "Number is even" << std::endl;
    }

    // Bitwise OR
    int orResult = a | b; // 0111 in binary
    std::cout << "Bitwise OR: " << orResult << std::endl; // Outputs 7

    // Use case: Setting specific bits in a number. Can be used to simulate checkboxes.
    // One byte can have 8 different checkboxes, so 8 different options can be set using bitwise OR.
    int flags = 0;
    int option1 = 1 << 0; // 0001
    int option2 = 1 << 1; // 0010
    flags |= option1 | option2; // Set option1 and option2 bits
    std::cout << "Flags with options set: " << flags << std::endl; // Outputs 3

    // Bitwise XOR
    int xorResult = a ^ b; // 0110 in binary
    std::cout << "Bitwise XOR: " << xorResult << std::endl; // Outputs 6

    // Use case: Swapping two numbers without a temporary variable
    // hard to explain in text but its just binary math or logical math , u can write it it make sense
    int x = 7, y = 9;
    x ^= y;
    y ^= x;
    x ^= y;
    std::cout << "Swapped x: " << x << ", y: " << y << std::endl; // Outputs x: 9, y: 7

    // Bitwise NOT
    int notResult = ~a; // 1010 in binary (two's complement representation)
    std::cout << "Bitwise NOT: " << notResult << std::endl; // Outputs -6

    // Use case: Inverting bits for creating masks or toggles

    // Left shift
    int leftShiftResult = a << 1; // 1010 in binary
    std::cout << "Left Shift: " << leftShiftResult << std::endl; // Outputs 10

    // Use case: Multiplying by powers of two
    int multiplier = 3;
    int result = multiplier << 2; // 3 * 2^2 = 12
    std::cout << "Multiplied by 4 using shift: " << result << std::endl; // Outputs 12

    // Right shift
    int rightShiftResult = a >> 1; // 0010 in binary
    std::cout << "Right Shift: " << rightShiftResult << std::endl; // Outputs 2

    // Use case: Dividing by powers of two
    int divisor = 8;
    int divisionResult = divisor >> 1; // 8 / 2 = 4
    std::cout << "Divided by 2 using shift: " << divisionResult << std::endl; // Outputs 4

    return 0;
}

