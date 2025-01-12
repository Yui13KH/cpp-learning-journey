#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// Function to create a new file (overwrites if exists)
void createFile(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error creating file: " << filename << std::endl;
    } else {
        outputFile.close();
    }
}

// Function to fill the file with the content of the vector
void fillFile(const std::string& filename, const std::vector<std::string>& content) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const std::string& line : content) {
            outputFile << line << std::endl;
        }
        outputFile.close();
    } else {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
    }
}

// Function to print the content of the file to the terminal
void printFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string line;
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}

// Function to delete a specific string from the file
void deleteFromFile(const std::string& filename, const std::string& target) {
    std::ifstream inputFile(filename);
    std::vector<std::string> fileContent;
    std::string line;

    // Read the file content into a vector
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            fileContent.push_back(line);
        }
        inputFile.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Remove target line from the vector
    fileContent.erase(std::remove(fileContent.begin(), fileContent.end(), target),
                      fileContent.end());

    // Write the updated content back to the file
    fillFile(filename, fileContent);
}

// Function to change a specific string in the file
void changeInFile(const std::string& filename, const std::string& oldContent,
                  const std::string& newContent) {
    std::ifstream inputFile(filename);
    std::vector<std::string> fileContent;
    std::string line;

    // Read the file content into a vector
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            fileContent.push_back(line);
        }
        inputFile.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Change target line to the new content
    for (std::string& line : fileContent) {
        if (line == oldContent) {
            line = newContent;
        }
    }

    // Write the updated content back to the file
    fillFile(filename, fileContent);
}

// Function to clear the contents of the file
void clearFile(const std::string& filename) {
    std::ofstream outputFile(filename, std::ios::trunc);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
    } else {
        outputFile.close();  // Just close the file to clear its contents
    }
}

// Function to delete the file
void deleteFile(const std::string& filename) {
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Error deleting file: " << filename << std::endl;
    } else {
        std::cout << "File deleted: " << filename << std::endl;
    }
}

int main() {
    // a bunch of file manipulations / handeling
    std::string filename = "example.txt";

    // Create a new file
    createFile(filename);

    // Define a vector to be written to the file
    std::vector<std::string> fileContent = {"Hello", "This is a test", "Another line", "Goodbye"};

    // Fill the file with content
    fillFile(filename, fileContent);

    // Print file content to the terminal
    std::cout << "File content after fill:\n";
    printFile(filename);

    // Change a line in the file
    changeInFile(filename, "This is a test", "This line has been changed");

    // Print the updated content
    std::cout << "File content after change:\n";
    printFile(filename);

    // Delete a line from the file
    deleteFromFile(filename, "Hello");

    // Print the file after deletion
    std::cout << "File content after deletion:\n";
    printFile(filename);

    /*
        Clear the file content
        clearFile(filename);

        Print the cleared file (should be empty)
        std::cout << "File content after clearing:\n";
        printFile(filename);

        Delete the file
        deleteFile(filename);

        commented out because you'll be left with nothing it'll clear the .txt and delete it
    */
    return 0;
}
