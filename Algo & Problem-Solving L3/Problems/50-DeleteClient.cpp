#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance;
};

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

std::vector<strClient> LoadCleintsDataFromFile(std::string FileName) {
    std::vector<strClient> vClients;
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::in);  // read Mode
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

void DeleteClientFromVector(std::vector<strClient>& vClients,
                            const std::string& targetAccountNumber) {
    std::vector<strClient> vUpdatedClients;

    for (const auto& client : vClients) {
        if (client.accountNumber != targetAccountNumber) {
            vUpdatedClients.push_back(client);
        }
    }

    vClients = vUpdatedClients;
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

void DeleteClient(const std::string& FileName, const std::string& targetAccountNumber) {
    std::vector<strClient> vClients = LoadCleintsDataFromFile(FileName);
    DeleteClientFromVector(vClients, targetAccountNumber);
    SaveClientsToFile(vClients, FileName);
}

int main() {
    std::string FileName = "clients.txt";
    std::string targetAccountNumber;
    std::cout << "Enter the Account number you wish to delete: ";
    std::cin >> targetAccountNumber;
    // this is the simplified approach i wont be printing and validating
    DeleteClient(FileName, targetAccountNumber);

    return 0;
}