#include <iostream>
#include <string>
#include <vector>
#include <sstream> 

// Function to reverse the words in a string
std::string reverseWords(const std::string& input) {
    std::vector<std::string> words;
    std::string word;

    // Use a stringstream to split the input by spaces
    std::stringstream ss(input);
    while (ss >> word) {
        words.push_back(word);
    }

    std::string reversed;
    for (int i = words.size() - 1; i >= 0; --i) {
        reversed += words[i];
        if (i > 0) {
            reversed += " ";
        }
    }

    return reversed;
}

int main() {
    std::string input = "hello world this is a test";
    std::string result = reverseWords(input);

    std::cout << "Original: " << input << std::endl;
    std::cout << "Reversed: " << result << std::endl;

    return 0;
}
