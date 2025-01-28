#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

// Define a namespace for the banking system
namespace BankUtils {

// Define a delimiter for file operations
const std::string DELIMITER = "#//#";

// Client structure to store client details
struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance = 0;
};

// Function Declarations

// Utility Functions
std::string getValidString(const std::string& prompt);
int getValidPositiveInt(const std::string& prompt);
std::vector<std::string> SplitString(std::string input, std::string delimiter = DELIMITER);

// File Operations
strClient ConvertLineToRecord(std::string line, std::string delimiter = DELIMITER);
std::vector<strClient> LoadClientsDataFromFile(std::string FileName);
void SaveClientsDataToFile(std::string FileName, const std::vector<strClient>& vClients);

// Client Operations
void PrintClientCard(const strClient& Client);
void PrintClients(const std::string& filename);
void ReadClient(strClient& client);

}  // namespace BankUtils