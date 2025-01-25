#include "Utility.h"
#include <fstream>

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance = 0;
};

std::string findLineByAccount(const std::string& filename, const std::string& accountNumber,
                              const std::string& delimiter) {
    std::ifstream file(filename);
    if (!file.is_open()) return "";

    std::string line;
    while (std::getline(file, line)) { // reads the file line by line
        if (line.find(accountNumber + delimiter) == 0) { 
            return line;
        }
    }

    return "";
}

void parseToStruct(std::string& input, strClient& client, const std::string& delimiter = "/##/") {
    size_t position = 0;

    if ((position = input.find(delimiter)) != std::string::npos) {
        client.accountNumber = input.substr(0, position);
        input.erase(0, position + delimiter.length());
    }

    if ((position = input.find(delimiter)) != std::string::npos) {
        client.pinCode = input.substr(0, position);
        input.erase(0, position + delimiter.length());
    }

    if ((position = input.find(delimiter)) != std::string::npos) {
        client.fullName = input.substr(0, position);
        input.erase(0, position + delimiter.length());
    }

    if ((position = input.find(delimiter)) != std::string::npos) {
        client.phoneNumber = input.substr(0, position);
        input.erase(0, position + delimiter.length());
    }

    if (!input.empty()) {
        client.accountBalance = std::stoi(input);
    }
}

void printClientInfo(const strClient& client) {
    const int width = 15;
    std::cout << std::string(65, '=') << "\n";
    std::cout << std::setw(width) << std::left << "Field"
              << " | " << std::setw(width * 2) << "Value" << "\n";
    std::cout << std::string(65, '-') << "\n";
    std::cout << std::setw(width) << std::left << "Account Number"
              << " | " << std::setw(width * 2) << client.accountNumber << "\n";
    std::cout << std::setw(width) << std::left << "PIN Code"
              << " | " << std::setw(width * 2) << client.pinCode << "\n";
    std::cout << std::setw(width) << std::left << "Full Name"
              << " | " << std::setw(width * 2) << client.fullName << "\n";
    std::cout << std::setw(width) << std::left << "Phone Number"
              << " | " << std::setw(width * 2) << client.phoneNumber << "\n";
    std::cout << std::setw(width) << std::left << "Account Balance"
              << " | " << std::setw(width * 2) << client.accountBalance << "\n";
    std::cout << std::string(65, '=') << "\n";
}

void handleFoundLine(std::string& line) {
    if (!line.empty()) {
        strClient client;
        parseToStruct(line, client);
        printClientInfo(client);
    } else {
        std::cout << "Account number not found!" << std::endl;
    }
}

int main() {
    std::string filename = utility::getValidString("Enter file name: ");
    std::string accountNumber = utility::getValidString("Enter account number");

    std::string line = findLineByAccount(filename, accountNumber, "/##/");

    handleFoundLine(line);

    return 0;
}

// compile: g++ 49-ClientByAccountNumber.cpp Utility.cpp -o 49-ClientByAccountNumber