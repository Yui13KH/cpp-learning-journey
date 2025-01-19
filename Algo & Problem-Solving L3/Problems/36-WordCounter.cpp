#include <iostream>
#include <string>

std::string readText() {
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

void countWords(const std::string& input) {
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

int main() {
    std::string text = readText();
    countWords(text);

    return 0;
}


