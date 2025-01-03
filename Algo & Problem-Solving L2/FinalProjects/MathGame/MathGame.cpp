#include <iostream>
#include <cstdlib>
#include <string>

// Enums
enum Difficulty { EASY = 1, MEDIUM, HARD, EXTREME };
enum Operator { ADDITION = 1, SUBTRACTION, MULTIPLICATION, DIVISION, MIXED };

// Structs
struct Results {
    int questionCount = 0;
    int percentageOfSuccess = 0;
    char letterGrade;
    Difficulty difficulty;
    Operator operatorType;
};

// Helper Functions
int RandomNumberInRange(int min, int max) { return rand() % (max - min + 1) + min; }

std::string difficultyToString(Difficulty difficulty) {
    switch (difficulty) {
        case EASY:
            return "EASY";
        case MEDIUM:
            return "MEDIUM";
        case HARD:
            return "HARD";
        case EXTREME:
            return "EXTREME";
        default:
            return "UNKNOWN";
    }
}

std::string operatorToString(Operator op) {
    switch (op) {
        case ADDITION:
            return "+";
        case SUBTRACTION:
            return "-";
        case MULTIPLICATION:
            return "*";
        case DIVISION:
            return "/";
        case MIXED:
            return "MIXED";
    }
    return "UNKNOWN";
}

char decideLetterGrade(int percentage) {
    if (percentage > 90)
        return 'A';
    else if (percentage > 80)
        return 'B';
    else if (percentage > 70)
        return 'C';
    else if (percentage > 60)
        return 'D';
    else
        return 'F';
}

int readValidNumberInRange(const std::string &message, int min, int max) {
    int number;
    while (true) {
        std::cout << message;
        std::cin >> number;
        if (!std::cin.fail() && number >= min && number <= max) break;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max
                  << ".\n";
    }
    std::cin.ignore(1000, '\n');
    return number;
}

void printResults(const Results &results) {
    std::cout << "\nResults:\n";
    std::cout << "Question Count: " << results.questionCount << "\n";
    std::cout << "Percentage of Success: " << results.percentageOfSuccess << "%\n";
    std::cout << "Letter Grade: " << results.letterGrade << "\n";
    std::cout << "Difficulty: " << difficultyToString(results.difficulty) << "\n";
    std::cout << "Operator: " << operatorToString(results.operatorType) << "\n";
}

// Difficulty-Specific Functions
int getQuestionCountForDifficulty(Difficulty difficulty) {
    switch (difficulty) {
        case EASY:
            return 5;
        case MEDIUM:
            return 10;
        case HARD:
            return 15;
        case EXTREME:
            return 20;
        default:
            return 5;
    }
}

void getRangeForDifficulty(Difficulty difficulty, int &min, int &max) {
    switch (difficulty) {
        case EASY:
            min = 1;
            max = 10;
            break;
        case MEDIUM:
            min = 10;
            max = 100;
            break;
        case HARD:
            min = 100;
            max = 1000;
            break;
        case EXTREME:
            min = 1000;
            max = 10000;
            break;
        default:
            min = 1;
            max = 10;
            break;
    }
}

// Core Functions
int calculateAnswer(int num1, int num2, Operator op) {
    switch (op) {
        case ADDITION:
            return num1 + num2;
        case SUBTRACTION:
            return num1 - num2;
        case MULTIPLICATION:
            return num1 * num2;
        case DIVISION:
            return num2 != 0 ? num1 / num2 : 0;  // Handle division by zero
        default:
            return 0;
    }
}

bool askQuestion(Difficulty difficulty, Operator operatorType) {
    int min, max;
    getRangeForDifficulty(difficulty, min, max);

    int num1 = RandomNumberInRange(min, max);
    int num2 = RandomNumberInRange(min, max);

    Operator currentOperator = operatorType;
    if (operatorType == MIXED) {
        currentOperator = (Operator)(RandomNumberInRange(1, 4));
    }

    int correctAnswer = calculateAnswer(num1, num2, currentOperator);
    std::string operatorSymbol = operatorToString(currentOperator);

    std::cout << num1 << " " << operatorSymbol << " " << num2 << " = ";
    int userAnswer;
    std::cin >> userAnswer;

    return userAnswer == correctAnswer;
}

void conductQuiz(Difficulty difficulty, Operator operatorType, Results &results) {
    results.questionCount = getQuestionCountForDifficulty(difficulty);
    int correctAnswers = 0;

    for (int i = 0; i < results.questionCount; i++) {
        if (askQuestion(difficulty, operatorType)) {
            correctAnswers++;
        }
    }

    results.percentageOfSuccess = (correctAnswers * 100) / results.questionCount;
    results.letterGrade = decideLetterGrade(results.percentageOfSuccess);
    results.difficulty = difficulty;
    results.operatorType = operatorType;
}

// Main Function
int main() {
    srand(unsigned(time(NULL)));

    Difficulty difficulty = (Difficulty)readValidNumberInRange(
        "Select Difficulty: [1] Easy, [2] Medium, [3] Hard, [4] Extreme: ", 1, 4);

    Operator operatorType = (Operator)readValidNumberInRange(
        "Select Operator: [1] Addition, [2] Subtraction, [3] "
        "Multiplication, [4] Division, [5] Mixed :",
        1, 5);

    Results results;
    conductQuiz(difficulty, operatorType, results);
    printResults(results);

    return 0;
}
