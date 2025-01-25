#include "Utility.h"
#include <fstream>

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance;
};

// Function to parse a single line into a strClient struct
void parseToStruct(std::string& input, strClient& client, std::string delimiter = "/##/") {
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
}

// Function to read the file and print the client data in a table
void PrintClients(const std::string& filename) {
    std::ifstream file(filename);  // Open the file
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    
    // Print the table header
    std::cout << std::left  // Left-align the columns
              << "| " << std::setw(15) << "Account Number"
              << "| " << std::setw(15) << "Pin Code"
              << "| " << std::setw(25) << "Full Name"
              << "| " << std::setw(20) << "Phone Number"
              << "| " << std::setw(15) << "Account Balance"
              << " |" << std::endl;

    std::cout << std::setfill('-')  // Use '-' to create a separator line
              << "| " << std::setw(15) << ""
              << "| " << std::setw(15) << ""
              << "| " << std::setw(25) << ""
              << "| " << std::setw(20) << ""
              << "| " << std::setw(15) << ""
              << " |" << std::endl;
    std::cout << std::setfill(' ');  // Reset the fill character to space

    // Read the file line by line and parse each line
    while (std::getline(file, line)) {
        strClient client;  // Create a temporary client struct
        parseToStruct(line, client);  // Parse the line into the struct

        // Print the client data in the table
        std::cout << "| " << std::setw(15) << std::left << client.accountNumber
                  << "| " << std::setw(15) << std::left << client.pinCode
                  << "| " << std::setw(25) << std::left << client.fullName
                  << "| " << std::setw(20) << std::left << client.phoneNumber
                  << "| " << std::setw(15) << std::left << client.accountBalance
                  << " |" << std::endl;
    }

    file.close();
}

int main() {

    std::string filename = utility::getValidString("Enter file name: ");
    PrintClients(filename);

    return 0;
}

// compile: g++ 48-ShowClients.cpp Utility.cpp -o 48-ShowClients