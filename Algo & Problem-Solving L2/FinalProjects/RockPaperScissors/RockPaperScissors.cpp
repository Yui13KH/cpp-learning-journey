#include <iostream>
#include <cstdlib>

const std::string COLOR_GREEN = "\033[1;32m";
const std::string COLOR_RED = "\033[1;31m";
const std::string COLOR_YELLOW = "\033[1;33m";
const std::string COLOR_RESET = "\033[0m";

enum Choice { ROCK = 1, PAPER, SCISSORS };

// Function to read a valid positive number
int ReadValidPositiveNumber(std::string message) {
    int number = 0;
    bool validInput;
    do {
        std::cout << message;
        std::cin >> number;

        validInput = !std::cin.fail() && number > 0;
        if (!validInput) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a positive number.\n";
        } else {
            std::cin.ignore(1000, '\n');
        }
    } while (!validInput);
    return number;
}

// Function to read a choice within the valid range
int ReadValidPositiveNumberInRange(std::string message) {
    int number = 0;
    bool validInput;
    do {
        std::cout << message;
        std::cin >> number;

        validInput = !std::cin.fail() && number > 0 && number < 4;
        if (!validInput) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
        } else {
            std::cin.ignore(1000, '\n');
        }
    } while (!validInput);
    return number;
}

// Function to generate a random number in a range
int RandomNumberInRange(int min, int max) { return rand() % (max - min + 1) + min; }

// Function to convert choice enum to string
std::string getChoiceName(int choice) {
    switch (choice) {
        case ROCK:
            return "Rock";
        case PAPER:
            return "Paper";
        case SCISSORS:
            return "Scissors";
        default:
            return "Invalid";
    }
}

// Function to play a round
void PlayRound(int roundNumber, int &playerWins, int &computerWins) {
    std::cout << "Round [" << roundNumber << "] begins\n";
    int playerChoice =
        ReadValidPositiveNumberInRange("Enter your choice : [1]:stone [2]:paper [3]:scissors : ");
    int computerChoice = RandomNumberInRange(1, 3);

    int winner = (playerChoice - computerChoice + 3) % 3;

    // Display choices and results
    std::cout << "-----------Round [" << roundNumber << "]---------\n";
    std::cout << "Player choice     : " << getChoiceName(playerChoice) << "\n";
    std::cout << "Computer choice   : " << getChoiceName(computerChoice) << "\n";

    if (winner == 0) {
        std::cout << COLOR_YELLOW << "Round winner      : It's a tie!\n";
    } else if (winner == 1) {
        std::cout << COLOR_GREEN << "Round winner      : Player wins!\n";
        playerWins++;
    } else if (winner == 2) {
        std::cout << COLOR_RED << "Round winner      : Computer wins!\n";
        computerWins++;
    }
    std::cout << COLOR_RESET << "----------------------------------\n";
}

void PlayGame() {
    srand((unsigned)time(NULL));  // Seed random number generator

    bool playAgain;
    do {
        int rounds = ReadValidPositiveNumber("Enter the number of rounds you want to play: ");

        int playerWins = 0;
        int computerWins = 0;

        // Play all rounds
        for (int i = 0; i < rounds; i++) {
            PlayRound(i + 1, playerWins, computerWins);
        }

        // Show final score
        std::cout << "\nFinal Score:\n";
        std::cout << "Player Wins: " << playerWins << "\n";
        std::cout << "Computer Wins: " << computerWins << "\n";

        if (playerWins > computerWins) {
            std::cout << COLOR_GREEN << "You are the overall winner!\n";
        } else if (computerWins > playerWins) {
            std::cout << COLOR_RED << "The computer is the overall winner!\n";
        } else {
            std::cout << COLOR_YELLOW << "It's a tie overall!\n";
        }
        std::cout << COLOR_RESET;
        // Ask to play again
        char choice;
        std::cout << "\nDo you want to play again? (y/n): ";
        std::cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');

    } while (playAgain);

    std::cout << "Thanks for playing! Goodbye!\n";
}

int main() {
    PlayGame();
    return 0;
}

/* Main ideas for writing clean and maintainable code:

 1. Break logic into the simplest functions for clarity and modularity.
 2. Use structs/classes to group related information for better organization.
 3. Use enums for fixed choices/constants to improve readability and safety.
 4. Design reusable functions that allow easy addition of features without breaking existing code.
*/
