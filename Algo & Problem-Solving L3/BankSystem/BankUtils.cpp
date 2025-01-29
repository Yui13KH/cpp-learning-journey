#include "BankUtils.h"
#include <functional>
struct strClient {
    std::string accountNumber;
    int pinCode = 0;
    std::string fullName;
    int phoneNumber = 0;
    int accountBalance = 0;
};

enum Choices {
    ADD_CLIENT = 1,
    DELETE_CLIENT,
    UPDATE_CLIENT,
    FIND_CLIENT,
    SHOW_ALL_CLIENTS,
    TRANSACTIONS,
    EXIT
};

namespace BankUtils {

bool FindClientByAccountNumber(std::string AccountNumber, strClient& Client,
                               const std::string& FileName);

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
        std::cin.clear();
        std::cin.ignore(1000, '\n');
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

std::vector<std::string> SplitString(std::string input, std::string delimiter = DELIMITER) {
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
    client.accountNumber = getValidString("Enter Account Number: ");
    client.pinCode = getValidPositiveInt("Enter PIN Code: ");
    client.fullName = getValidString("Enter Full Name: ");
    client.phoneNumber = getValidPositiveInt("Enter Phone Number: ");
    client.accountBalance = getValidPositiveInt("Enter Account Balance: ");

    return client;
}

strClient UpdateClientInfo(const strClient& existingClient) {
    strClient client = existingClient;  // Copy the existing client to keep the account number

    std::cout << "\nUpdating Client Information" << std::endl;
    client.pinCode = getValidPositiveInt("Enter PIN Code: ");
    client.fullName = getValidString("Enter Full Name: ");
    client.phoneNumber = getValidPositiveInt("Enter Phone Number: ");
    client.accountBalance = getValidPositiveInt("Enter Account Balance: ");

    return client;
}

strClient DepositClientInfo(const strClient& existingClient) {
    strClient client = existingClient;  // Copy the existing client to keep the account number
    std::cout << "\nDepositing Client Information" << std::endl;
    client.accountBalance += getValidPositiveInt("Enter Amount to Deposit: ");
    return client;
}

strClient WithdrawClientInfo(const strClient& existingClient) {
    strClient client = existingClient;  // Copy the existing client to keep the account number
    std::cout << "\nWithdrawing Client Information" << std::endl;
    int amount = getValidPositiveInt("Enter Amount to Withdraw: ");
    if (amount > client.accountBalance) {
        std::cerr << "Insufficient funds!" << std::endl;
    } else {
        client.accountBalance -= amount;
    }
    return client;
}

std::string ReadClientAccountNumber() {
    std::string AccountNumber = "";
    AccountNumber = getValidString("Enter Account Number: ");
    return AccountNumber;
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

void PrintClientsSummary(const std::string& filename) {
    std::ifstream file(filename);  // Open the file
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    double totalBalance = 0;  // Variable to store the total balance

    // Print the table header
    std::cout << std::left << "| " << std::setw(15) << "Account Number"
              << "| " << std::setw(25) << "Full Name"
              << "| " << std::setw(15) << "Account Balance"
              << " |" << std::endl;

    std::cout << std::setfill('-') << "| " << std::setw(15) << ""
              << "| " << std::setw(25) << ""
              << "| " << std::setw(15) << ""
              << " |" << std::endl;
    std::cout << std::setfill(' ');  // Reset the fill character to space

    // Read the file line by line and parse each line
    while (std::getline(file, line)) {
        strClient client = ConvertLineToRecord(line, DELIMITER);  // Parse the line into the struct
        totalBalance += client.accountBalance;                    // Add to total balance

        // Print the client data in the table
        std::cout << "| " << std::setw(15) << std::left << client.accountNumber << "| "
                  << std::setw(25) << std::left << client.fullName << "| " << std::setw(15)
                  << std::left << client.accountBalance << " |" << std::endl;
    }

    file.close();

    // Print total balance
    std::cout << std::setfill('-') << std::setw(60) << "-" << std::setfill(' ') << std::endl;
    std::cout << "| " << std::setw(42) << "Total Balance:"
              << "| " << std::setw(15) << totalBalance << " |" << std::endl;
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
    std::vector<std::string> clientData = {client.accountNumber, std::to_string(client.pinCode),
                                           client.fullName, std::to_string(client.phoneNumber),
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

void AddNewClient(const std::string& filename, const std::string& delimiter) {
    std::string accountNumber =
        ReadClientAccountNumber();  // Function to read only the account number

    strClient dummyClient;  // Dummy client object for FindClientByAccountNumber
    if (FindClientByAccountNumber(accountNumber, dummyClient, filename)) {
        std::cout << "\nClient with Account Number (" << accountNumber << ") Already Exists!\n";
    } else {
        strClient client = ReadClient();  // Read the rest of the client data
        AddClientLineToFile(filename, ClientLine(client, delimiter));
    }
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
            std::string line = ClientLine(client, delimiter);
            MyFile << line << std::endl;
        }
        MyFile.close();
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
}

bool FindClientByAccountNumber(std::string AccountNumber, strClient& Client,
                               const std::string& FileName) {
    std::vector<strClient> vClients = LoadCleintsDataFromFile(FileName);
    for (const strClient& C : vClients) {
        if (C.accountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;  // No match found
}

void UpdateClientInVector(std::vector<strClient>& Clients, const std::string& targetClient,
                          std::function<strClient(const strClient&)> transactionFunc) {
    bool found = false;

    for (auto& client : Clients) {
        if (client.accountNumber == targetClient) {
            client = transactionFunc(client);  // Apply the transaction function
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Client Doesn't Exist." << std::endl;
    }
}

void updateClient(const std::string& FileName, const std::string& targetClient) {
    std::vector<strClient> AllClients = LoadCleintsDataFromFile(FileName);
    UpdateClientInVector(AllClients, targetClient, UpdateClientInfo);
    SaveClientsToFile(AllClients, FileName);
}

void showTransactionsMenu() {
    std::cout << "==============================\n";
    std::cout << "      Transactions Menu       \n";
    std::cout << "==============================\n";
    std::cout << "1. Withdraw\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Total Balances\n";
    std::cout << "4. Exit\n";
    std::cout << "==============================\n";
    std::cout << "Please select an option: ";
}

// main functions

void bankManagementSystem(std::string ClientsFileName) {
    while (true) {
        system("cls");  // Clears the console screen
        std::cout << "Welcome to the Bank Management System\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Add Client\n";
        std::cout << "2. Delete Client\n";
        std::cout << "3. Update Client\n";
        std::cout << "4. Find Client\n";
        std::cout << "5. Show All Clients\n";
        std::cout << "6. Transactions\n";
        std::cout << "7. Exit\n";
        std::cout << "----------------------------------------\n";

        int choice = getValidPositiveInt("Enter your choice: ");

        switch (choice) {
            case ADD_CLIENT:
                AddClients(ClientsFileName, "#//#");
                break;
            case DELETE_CLIENT:
                DeleteClient(ClientsFileName);
                break;
            case UPDATE_CLIENT:
                handleClientUpdate(ClientsFileName);
                break;
            case FIND_CLIENT:
                FindClient(ClientsFileName);
                break;
            case SHOW_ALL_CLIENTS:
                showAllClients(ClientsFileName);
                break;
            case TRANSACTIONS:
                Transactions(ClientsFileName);
                break;
            case EXIT:
                std::cout << "Exiting the application. Goodbye!\n";
                exit(0);  // Terminate the program
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        system("pause");  // Wait for user input before clearing the screen
    }
}

void showAllClients(const std::string& filename) { PrintClients(filename); }

void AddClients(std::string filename, std::string delimiter) {
    char option = 'Y';
    do {
        std::cin.clear();
        std::cout << "Adding New Client:\n\n";
        AddNewClient(filename, delimiter);
        std::cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
        std::cin >> option;
        std::cin.ignore(1000, '\n');
    } while (toupper(option) == 'Y');
}

void DeleteClient(const std::string& FileName) {
    strClient Client;
    std::string targetAccountNumber = getValidString("Account Number To Delete: ");
    if (FindClientByAccountNumber(targetAccountNumber, Client, FileName)) {
        std::vector<strClient> vClients = LoadCleintsDataFromFile(FileName);
        DeleteClientFromVector(vClients, targetAccountNumber);
        SaveClientsToFile(vClients, FileName);
    } else {
        std::cout << "\nClient with Account Number (" << targetAccountNumber
                  << ") is Not Found! \n";
    }
}

void FindClient(std::string Filename) {
    strClient Client;
    std::string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, Client, Filename)) {
        PrintClientCard(Client);
    } else {
        std::cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found! \n";
    }
}

void handleClientUpdate(std::string FileName) {
    std::string targetClient = getValidString("Account Number to Update: ");
    updateClient(FileName, targetClient);
}

void Transactions(std::string FileName) {
    while (true) {
        showTransactionsMenu();

        int option;
        std::cin >> option;
        std::cin.ignore(1000, '\n');

        if (option == 4) return;  // Exit Transactions menu and return to bankManagementSystem

        std::vector<strClient> AllClients = LoadCleintsDataFromFile(FileName);

        if (option == 1 || option == 2) {
            std::string targetClient = getValidString("Enter Account Number to Update: ");

            if (option == 1) {
                UpdateClientInVector(AllClients, targetClient, DepositClientInfo);
            } else if (option == 2) {
                UpdateClientInVector(AllClients, targetClient, WithdrawClientInfo);
            }
        } else if (option == 3) {
            PrintClientsSummary(FileName);
        } else {
            std::cout << "Invalid option, please try again.\n";
            continue;  // Restart the loop without reloading the file
        }

        SaveClientsToFile(AllClients, FileName);
    }
}

}  // namespace BankUtils
