#include "Utility.h"

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance;
};

void parseToStruct(std::string& input, strClient& client, std::string delimiter = " ") {
    size_t position = 0;

    // Extract accountNumber
    if ((position = input.find(delimiter)) != std::string::npos) {
        client.accountNumber = input.substr(0, position);
        input.erase(0, position + delimiter.length());
    }

    // Extract pinCode
    if ((position = input.find(delimiter)) != std::string::npos) {
        client.pinCode = input.substr(0, position);
        input.erase(0, position + delimiter.length());
    }

    // Extract fullName
    if ((position = input.find(delimiter)) != std::string::npos) {
        client.fullName = input.substr(0, position);
        input.erase(0, position + delimiter.length());
    }

    // Extract phoneNumber
    if ((position = input.find(delimiter)) != std::string::npos) {
        client.phoneNumber = input.substr(0, position);
        input.erase(0, position + delimiter.length());
    }

    // The remaining part is the accountBalance
    if (!input.empty()) {
        client.accountBalance = std::stoi(input);  // Convert string to int
    }

    // yeah i know its kinda a meh way to do it , but u cant itterate over a struct like arryas or objects
}

void printClientInfo(const strClient& client) {
    const int width = 15; // Column width for alignment

    // Print upper border
    std::cout << std::string(65, '=') << "\n";

    // Print header
    std::cout << std::setw(width) << std::left << "Field"
              << " | " << std::setw(width * 2) << "Value" << "\n";

    // Print separator line
    std::cout << std::string(65, '-') << "\n";

    // Print each field with aligned columns
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

    // Print lower border
    std::cout << std::string(65, '=') << "\n";
}

int main() {
    strClient client;

    std::string clientInfo = utility::getValidString("Enter User Bank Info: ");
    std::string delimiter = utility::getValidString("Enter delimiter: ");

    parseToStruct(clientInfo, client, delimiter);
    printClientInfo(client);

    return 0;
}

// compile: g++ 46-LineToRecord.cpp Utility.cpp -o 46-LineToRecord