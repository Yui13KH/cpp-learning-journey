#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class clsString {
   private:
    std::string _text;

    // abstracted functions

    static char invertCase(char c) { return std::isupper(c) ? std::tolower(c) : std::toupper(c); }

    static std::string readText() {
        std::string text;
        std::cout << "Enter text (type 'END' to stop):" << std::endl;

        std::string line;
        while (true) {
            std::getline(std::cin, line);

            if (line == "END") {
                break;
            }

            if (!text.empty()) {
                text += " ";
            }
            text += line;
        }

        return text;
    }

    static int findFirstAlphaPos(const std::string& input) {
        for (int i = 0; i < input.size(); ++i) {
            if (std::isalpha(input[i])) {
                return i;
            }
        }
        return -1;
    }

    static int findLastAlphaPos(const std::string& input) {
        for (int i = input.size() - 1; i >= 0; --i) {
            if (std::isalpha(input[i])) {
                return i;
            }
        }
        return -1;
    }

   public:
    // getter
    std::string getText() { return _text; }

    // setter

    void setText(std::string text) { _text = text; }

    // string libary functions

    static void printText(std::string text) { std::cout << text << std::endl; }

    void printText() { printText(_text); }

    static std::string invertStringCase(const std::string& input) {
        std::string result = input;
        for (char& c : result) {
            c = invertCase(c);
        }
        return result;
    }

    void invertStringCase() { _text = invertStringCase(_text); }

    static void PrintFirstLetterOfEachWord(const std::string& input) {
        bool currentIndex = true;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ' ') {
                currentIndex = true;
            } else if (currentIndex) {
                printf("%c\t", input[i]);
                currentIndex = false;
            }
        }
    }

    void PrintFirstLetterOfEachWord() { PrintFirstLetterOfEachWord(_text); }

    static void splitAndPrintWords(const std::string& input) {
        std::string temp = input;
        size_t pos = 0;

        while ((pos = temp.find(' ')) != std::string::npos) {
            std::string word = temp.substr(0, pos);
            if (!word.empty()) {
                std::cout << word << '\n';
            }

            temp.erase(0, pos + 1);
        }

        if (!temp.empty()) {
            std::cout << temp << '\n';
        }
    }

    void splitAndPrintWords() { splitAndPrintWords(_text); }

    static void countWords(const std::string& input) {
        std::string temp = input;
        size_t pos = 0;
        int wordCount = 0;

        while ((pos = temp.find(' ')) != std::string::npos || !temp.empty()) {
            if (temp[pos] == '\n') {
                temp.erase(pos, 1);
                pos = temp.find(' ');
            }

            if (pos > 0) {
                wordCount++;
            }

            temp.erase(0, pos + 1);
        }

        if (!temp.empty()) {
            wordCount++;
        }

        std::cout << wordCount << " words\n";
    }

    void countWords() { countWords(_text); }

    static std::string trimString(const std::string& input) {
        int firstPos = findFirstAlphaPos(input);
        int lastPos = findLastAlphaPos(input);

        if (firstPos == -1 || lastPos == -1) {
            return "";
        }

        return input.substr(firstPos, lastPos - firstPos + 1);
    }

    void trimString() { _text = trimString(_text); }

    static std::string trimTrailingSpaces(const std::string& input) {
        int lastPos = findLastAlphaPos(input);
        if (lastPos == -1) {
            return "";
        }
        return input.substr(0, lastPos + 1);
    }

    void trimTrailingSpaces() { _text = trimTrailingSpaces(_text); }

    static std::string trimLeadingSpaces(const std::string& input) {
        int firstPos = findFirstAlphaPos(input);
        if (firstPos == -1) {
            return "";
        }
        return input.substr(firstPos);
    }

    void trimLeadingSpaces() { _text = trimLeadingSpaces(_text); }

    static std::string reverseWords(const std::string& input) {
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

    void reverseWords() { _text = reverseWords(_text); }

    static void stringLength(const std::string& input) {
        std::cout << input.length() << " characters\n";
    }

    void stringLength() { stringLength(_text); }

    // destructor

    ~clsString() {}
    
};