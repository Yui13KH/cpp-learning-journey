#include "BankUtils.h"

struct strClient {
    std::string accountNumber;
    int pinCode = 0;
    std::string fullName;
    int phoneNumber = 0;
    int accountBalance = 0;
};

namespace BankUtils {

// Utility Functions
std::string getValidString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) {
            return input;
        }
        std::cout << "Please enter a valid string: ";
    }
}

int getValidPositiveInt(const std::string& prompt) {
    int input;
    std::string line;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        if (iss >> input && input > 0 && iss.eof()) {
            return input;
        }

        std::cout << "Please enter a valid positive integer: ";
    }
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
        vString.push_back(token);  // last word
    }

    return vString;
}

strClient ConvertLineToRecord(std::string line, std::string delimiter = DELIMITER) {
    strClient Client;
    std::vector<std::string> vClientData;

    vClientData = SplitString(line, delimiter);

    Client.accountNumber = (vClientData[0]);
    Client.pinCode = std::stoi(vClientData[1]);
    Client.fullName = vClientData[2];
    Client.phoneNumber = std::stoi(vClientData[3]);
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
            Client = ConvertLineToRecord(Line, DELIMITER);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

// client functions

void PrintClientCard(const strClient& Client) {
    std::cout << "\nThe following are the client details:\n";
    std::cout << std::left;
    std::cout << std::setw(16) << "\nAccount Number" << ": " << Client.accountNumber;
    std::cout << std::setw(16) << "\nPin Code" << ": " << Client.pinCode;
    std::cout << std::setw(16) << "\nName" << ": " << Client.fullName;
    std::cout << std::setw(16) << "\nPhone" << ": " << Client.phoneNumber;
    std::cout << std::setw(16) << "\nAccount Balance" << ": " << Client.accountBalance << std::endl;
}

strClient ReadClient() {  // using a function of type struct better then void
    strClient client;

    std::cout << "\nClient Information" << std::endl;
    client.accountNumber = getValidPositiveInt("Enter Account Number: ");
    client.pinCode = getValidPositiveInt("Enter PIN Code: ");
    client.fullName = getValidString("Enter Full Name: ");
    client.phoneNumber = getValidPositiveInt("Enter Phone Number: ");
    client.accountBalance = getValidPositiveInt("Enter Account Balance: ");

    return client;
}

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
        strClient client = ConvertLineToRecord(line, DELIMITER);  // Parse the line into the struct

        // Print the client data in the table
        std::cout << "| " << std::setw(15) << std::left << client.accountNumber << "| "
                  << std::setw(15) << std::left << client.pinCode << "| " << std::setw(25)
                  << std::left << client.fullName << "| " << std::setw(20) << std::left
                  << client.phoneNumber << "| " << std::setw(15) << std::left
                  << client.accountBalance << " |" << std::endl;
    }

    file.close();
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

std::string ClientLine(const strClient& client, const std::string& delimiter) {
    std::vector<std::string> clientData = {client.accountNumber, std::to_string(client.pinCode), client.fullName,
                                           std::to_string(client.phoneNumber),
                                           std::to_string(client.accountBalance)};

    return JoinString(clientData, delimiter);
}

void AddClientLineToFile(std::string FileName, std::string ClientLine) {
    std::fstream ClientFile;
    ClientFile.open(FileName, std::ios::out | std::ios::app);
    if (ClientFile.is_open()) {
        ClientFile << ClientLine << std::endl;
        ClientFile.close();
    }
}  // appends the new line into the file

void AddNewClient(std::string filename, std::string delimiter) {
    strClient client;
    client = ReadClient();
    AddClientLineToFile(filename, ClientLine(client, delimiter));
}
// main functions

void showAllClients(const std::string& filename) { PrintClients(filename); }

void AddClients(std::string filename, std::string delimiter) {
    char option = 'Y';
    do {
        std::cout << "Adding New Client:\n\n";
        AddNewClient(filename, delimiter);
        std::cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
        std::cin >> option;
    } while (toupper(option) == 'Y');
}

}  // namespace BankUtils