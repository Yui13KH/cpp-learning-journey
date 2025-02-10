#include <iostream>

class clsCalculator {
   private:
    float _Number;
    float _PreviousResult;
    float _Result;
    char _Operation;
    float _LastOperand;

   public:
    void setResult(int number) { _Result = number; }

    int getResult() const { return _Result; }

    void Add(int number) {
        _PreviousResult = _Result;
        _Result += number;
        _Operation = '+';
        _LastOperand = number;
    }

    void Subtract(int number) {
        _PreviousResult = _Result;
        _Result -= number;
        _Operation = '-';
        _LastOperand = number;
    }

    void Multiply(int number) {
        _PreviousResult = _Result;
        _Result *= number;
        _Operation = '*';
        _LastOperand = number;
    }

    void Divide(int number) {
        if (number == 0) {
            std::cout << "Error: Division by zero is not allowed." << std::endl;
            number = 1;
        }
        _PreviousResult = _Result;
        _Result /= number;
        _Operation = '/';
        _LastOperand = number;
    }

    void Clear() {
        _PreviousResult = 0;
        _Result = 0;
        _Operation = '+';
        _LastOperand = 0;
    }

    void Undo() { _Result = _PreviousResult; }

    void PrintResult() const {
        std::cout << "Result after " << _PreviousResult << " " << _Operation << " " << _LastOperand
                  << " is: " << _Result << std::endl;
    }
};

int main() {
    clsCalculator calculator;

    std::cout << "Initial result: " << calculator.getResult() << std::endl;

    calculator.Add(5);
    calculator.PrintResult();
    calculator.Multiply(34);
    calculator.PrintResult();
    calculator.Subtract(10);
    calculator.PrintResult();
    calculator.Divide(2);
    calculator.PrintResult();

    std::cout << "Final result: " << calculator.getResult() << std::endl;

    calculator.Clear();
    std::cout << "After clear: " << calculator.getResult() << std::endl;

    return 0;
}