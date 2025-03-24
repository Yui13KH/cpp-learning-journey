#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}  // template function

template <class T>
class Calculator {
   private:
    T number1, number2;

   public:
    Calculator(T n1, T n2) {
        number1 = n1;
        number2 = n2;
    }

    void PrintResults() {
        std::cout << number1 << " + " << number2 << " = " << add() << std::endl;
        std::cout << number1 << " - " << number2 << " = " << subtract() << std::endl;
        std::cout << number1 << " * " << number2 << " = " << multiply() << std::endl;
        std::cout << number1 << " / " << number2 << " = " << divide() << std::endl;
    }

    T add() const { return number1 + number2; }

    T subtract() const { return number1 - number2; }

    T multiply() const { return number1 * number2; }

    T divide() const {
        if (number2 == 0 || number1 == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return number1 / number2;
    }
};

int main() {
    std::cout << add<int>(2, 3) << std::endl;
    std::cout << add<double>(2.3, 3.4) << std::endl;
    std::cout << add<std::string>("Hello ", "World") << std::endl;
    // important Note whatever ur doing with the template , has to actually work with the types that
    // are passed in for example a multiplication function wont work with strings

    Calculator<int> intCalculator(10, 5);
    intCalculator.PrintResults();

    Calculator<double> doubleCalculator(10.5, 5.5);
    doubleCalculator.PrintResults();
}
