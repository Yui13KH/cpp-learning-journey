#include "Utility.h"
#include <fstream>

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance;
};

strClient UpdateClientInfo(const strClient& existingClient) {
    strClient client = existingClient;  // Copy the existing client to keep the account number

    std::cout << "\nUpdating Client Information" << std::endl;
    client.pinCode = utility::getValidString("Enter PIN Code: ");
    client.fullName = utility::getValidString("Enter Full Name: ");
    client.phoneNumber = utility::getValidString("Enter Phone Number: ");
    client.accountBalance = utility::getValidPositiveInt("Enter Account Balance: ");

    return client;
}

std::vector<std::string> SplitString(std::string input, std::string delimiter) {
    std::vector<std::string> vString;
    short position = 0;
    std::string token;

    while ((position = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, position);  // store word temporarily
        if (token != "") {
            vString.push_back(token);
        }
        input.erase(0, position + delimiter.length());
    }

    if (input != "") {
        vString.push_back(input);  // last word
    }

    return vString;
}

strClient ConvertLineToRecord(std::string line, std::string delimiter = "#//#") {
    strClient Client;
    std::vector<std::string> vClientData = SplitString(line, delimiter);

    Client.accountNumber = vClientData[0];
    Client.pinCode = vClientData[1];
    Client.fullName = vClientData[2];
    Client.phoneNumber = vClientData[3];
    Client.accountBalance = std::stoi(vClientData[4]);

    return Client;
}

std::vector<strClient> LoadClientsDataFromFile(const std::string& FileName) {
    std::vector<strClient> vClients;
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::in);  // Read Mode

    if (MyFile.is_open()) {
        std::string Line;
        strClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }

    return vClients;
}

std::string JoinString(const std::vector<std::string>& input, const std::string& delimiter) {
    std::string joinedString;
    for (size_t i = 0; i < input.size(); i++) {
        joinedString += input[i];
        if (i != input.size() - 1) {
            joinedString += delimiter;
        }
    }
    return joinedString;
}

std::string JoinClientData(const strClient& client, const std::string& delimiter) {
    std::vector<std::string> clientData = {client.accountNumber, client.pinCode, client.fullName,
                                           client.phoneNumber,
                                           std::to_string(client.accountBalance)};
    return JoinString(clientData, delimiter);
}

void UpdateClientInVector(std::vector<strClient>& Clients, const std::string& targetClient) {
    bool found = false;

    for (auto& client : Clients) {
        if (client.accountNumber == targetClient) {
            client = UpdateClientInfo(client); // Pass existing client to preserve account number
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Client Doesn't Exist." << std::endl;
    }
}

void SaveClientsToFile(const std::vector<strClient>& vClients, const std::string& FileName,
                       const std::string& delimiter = "#//#") {
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::out);  // Open in write mode (overwrite)

    if (MyFile.is_open()) {
        for (const auto& client : vClients) {
            std::string line = JoinClientData(client, delimiter);
            MyFile << line << std::endl;
        }
        MyFile.close();
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
}

void updateClient(const std::string& FileName, const std::string& targetClient) {
    std::vector<strClient> AllClients = LoadClientsDataFromFile(FileName);
    UpdateClientInVector(AllClients, targetClient);
    SaveClientsToFile(AllClients, FileName);
}

int main() {
    std::string FileName = "Clients.txt";
    std::string targetAccountNumber;
    std::cout << "Enter the Account number you wish to Update: ";
    std::cin >> targetAccountNumber;
    // this is the simplified approach i wont be printing and validating
    updateClient(FileName, targetAccountNumber);

    return 0;
}

// command to compile : g++ 51-UpdateClient.cpp Utility.cpp -o 51-UpdateClient