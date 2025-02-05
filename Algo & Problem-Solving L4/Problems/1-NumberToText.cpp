#include "Utility.h"
#include <vector>

std::vector<std::string> units = {"zero",    "one",     "two",       "three",    "four",
                                  "five",    "six",     "seven",     "eight",    "nine",
                                  "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                                  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

std::vector<std::string> tens = {"",      "",      "twenty",  "thirty", "forty",
                                 "fifty", "sixty", "seventy", "eighty", "ninety"};

std::vector<std::string> powers = {"",         "thousand",    "million",    "billion",
                                   "trillion", "quadrillion", "quintillion"};

// yes the empty ""  are intentional , for easier access [2] = "twenty" see it makes more sense

std::string convertThreeDigits(int number) {
    std::string result = "";

    int hundred = number / 100;
    int remainder = number % 100;

    if (hundred) {
        result += units[hundred] +
                  " hundred";  // simple : ex 200 / 100 = 2 -> unit[2] = " two" + "hundred"
        if (remainder)
            result += " ";  // for additional stuff , continue on upper example 219 the upper part
                            // is done this adds a space
    }

    if (remainder < 20) {
        result +=
            units[remainder];  // the upper result if 210 its simple really no need for explination
    } else {
        result += tens[remainder / 10];  // if perfect number like 240 , 40 / 10 = 4 which is
                                         // "forty" which is added to the upper
        if (remainder % 10) result += "-" + units[remainder % 10];  // for not perfect like 245
    }

    return result;
}  // handles 100's up to 999

std::string numberToWords(long long number) {  //  max is ~9 quintilion anyway
    if (number == 0) return "zero";            // :3

    std::string result = "";
    int chunkIndex = 0;  // checks the size "thousand" , "million"

    while (number > 0) {
        int chunk =
            number %
            1000;  // gets last 3 digits of any number bigger then 1000 , ex:123456789 % 1000 = 789
        if (chunk) {
            std::string chunkStr = convertThreeDigits(chunk);
            if (!result.empty()) {
                result = chunkStr + " " + powers[chunkIndex] + " " + result;
            } else {
                result = chunkStr + " " + powers[chunkIndex];
            }
        }
        number /= 1000;  // this removes the ones that the upper modulo gives back
        chunkIndex++;    // +1 to the size
    }

    return result;
}

int main() {
    long long number = Utility::getValidPositiveInt("Enter a number: ");
    std::cout << numberToWords(number) << std::endl;
    return 0;
}

// yeah yeah you could use a string-based solution for huge stuff bigger then quintilion , but thats a hassle :D , and it'll be the same logic but you'd need to split the chunks from the string to numbers


