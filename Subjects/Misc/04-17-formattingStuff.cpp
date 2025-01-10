#include <cstdio>
#include <cstring>

int main() {
    // 1. Formatting Integers
    int intVal = 123;
    printf("Formatting Integers:\n");
    printf("Default: %d\n", intVal);
    printf("With Width 10: %10d\n", intVal);  // Right-align in a field of 10 characters
    printf("With Leading Zeroes: %010d\n", intVal);  // Pad with zeroes
    printf("With Left Alignment: %-10d\n", intVal);  // Left-align in a field of 10 characters
    printf("\n");

    // 2. Formatting Floats
    float floatVal = 3.14159;
    printf("Formatting Floats:\n");
    printf("Default: %f\n", floatVal);
    printf("With Precision 2: %.2f\n", floatVal);  // Limit to 2 decimal places
    printf("With Width and Precision: %10.3f\n", floatVal);  // Width of 10, 3 decimal places
    printf("\n");

    // 3. Formatting Characters
    char charVal = 'A';
    printf("Formatting Characters:\n");
    printf("Character: %c\n", charVal);
    printf("With Width 5: %5c\n", charVal);  // Right-align character in a width of 5
    printf("With Left Alignment: %-5c\n", charVal);  // Left-align character in a width of 5
    printf("\n");

    // 4. Formatting Strings (Array of Chars)
    char strVal[] = "Hello, World!";
    printf("Formatting Strings (Array of Chars):\n");
    printf("String: %s\n", strVal);
    printf("With Width 20: %20s\n", strVal);  // Right-align string in a width of 20
    printf("Left-Aligned String: %-20s\n", strVal);  // Left-align string in a width of 20
    printf("Padded with Character: %20s\n", strVal);  // Right-align, but padded with spaces (default)
    printf("Padded with Zeroes: %020s\n", strVal);  // Right-align, padded with zeroes
    printf("\n");

    return 0;
}
