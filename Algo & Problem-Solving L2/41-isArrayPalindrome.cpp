#include <iostream>

bool IsPalindromeArray(int arr[100], int Length) {
    for (int i = 0; i < Length / 2; i++) {  // Only iterate up to the middle of the array
        if (arr[i] != arr[Length - i - 1]) {  // Compare front and back elements
            return false;  // Return false if a mismatch is found
        }
    }
    return true;
}

void PrintResults(int arr[100], int Length) {
    if (IsPalindromeArray(arr, Length)) {
        std::cout << "The array is a palindrome." << std::endl;
    } else {
        std::cout << "The array is not a palindrome." << std::endl;
    }
}

int main() {
    int notPalindromeArray[] = {1, 2, 3, 4, 5};
    int palindromeArray[] = {1, 2, 3, 2, 1};

    PrintResults(notPalindromeArray, 5);
    PrintResults(palindromeArray, 5);

    return 0;
}

