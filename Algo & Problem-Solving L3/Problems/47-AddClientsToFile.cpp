#include "Utility.h"
#include <fstream>

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance;
};

void ReadClient(strClient &client) {
    std::cout << "\nClient Information" << std::endl;
    client.accountNumber = utility::getValidString("Enter Account Number: ");
    client.pinCode = utility::getValidString("Enter PIN Code: ");
    client.fullName = utility::getValidString("Enter Full Name: ");
    client.phoneNumber = utility::getValidString("Enter Phone Number: ");
    client.accountBalance = utility::getValidPositiveInt("Enter Account Balance: ");
}

std::string JoinString(const std::vector<std::string> &input, const std::string &delimiter) {
    std::string joinedString;
    for (size_t i = 0; i < input.size(); i++) {
        joinedString += input[i];
        if (i != input.size() - 1) {
            joinedString += delimiter;
        }
    }
    return joinedString;
}

std::string JoinClientData(const strClient &client, const std::string &delimiter) {
    std::vector<std::string> clientData = {client.accountNumber, client.pinCode, client.fullName,
                                           client.phoneNumber,
                                           std::to_string(client.accountBalance)};

    return JoinString(clientData, delimiter);
}

void createFile(const std::string &filename) {
    // Check if the file can be opened (it exists)
    std::ifstream checkFile(filename);
    if (checkFile.is_open()) {
        std::cout << "File already exists: " << filename << std::endl;
        checkFile.close();
        return;
    }

    // If the file doesn't exist, create it
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error creating file: " << filename << std::endl;
    } else {
        std::cout << "File created successfully: " << filename << std::endl;
        outputFile.close();
    }
}

void fillFile(std::string fileName, std::string cliendData) {
    std::ofstream file(fileName, std::ios::app);

    if (file.is_open()) {
        file << cliendData << "\n";
        file.close();
        std::cout << "Client added secussefuly" << std::endl;
    } else {
        std::cerr << "Error coud not open file " << fileName << std::endl;
    }
}

void AddClientToFile(strClient client, std::string fileName) {
    char UserInput = '0';
    do {
        ReadClient(client);
        std::string clientInfo = JoinClientData(client, "/##/");
        fillFile(fileName, clientInfo);
        std::cout << "Do you want to add another client? (Y/N): ";
        std::cin >> UserInput;
    } while (UserInput == 'Y' || UserInput == 'y');
}

int main() {
    strClient client;

    std::string fileName = utility::getValidString("Enter file name: ");
    createFile(fileName);
    AddClientToFile(client, fileName);

    return 0;
}

// compile: g++ 47-AddClientsToFile.cpp Utility.cpp -o 47-AddingClientsToFile