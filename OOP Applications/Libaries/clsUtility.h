#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

class clsUtility {
   public:
    enum enCharType {
        SamallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    static void Srand() {
        // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To) {
        // Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType) {
        // updated this method to accept mixchars
        if (CharType == MixChars) {
            // Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType) {
            case enCharType::SamallLetter: {
                return char(RandomNumber(97, 122));
                break;
            }
            case enCharType::CapitalLetter: {
                return char(RandomNumber(65, 90));
                break;
            }
            case enCharType::SpecialCharacter: {
                return char(RandomNumber(33, 47));
                break;
            }
            case enCharType::Digit: {
                return char(RandomNumber(48, 57));
                break;
            }
            defualt: {
                return char(RandomNumber(65, 90));
                break;
            }
        }
    }

    static std::string GenerateWord(enCharType CharType, short Length)

    {
        std::string Word;

        for (int i = 1; i <= Length; i++)

        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    static std::string GenerateKey(enCharType CharType = CapitalLetter) {
        std::string Key = "";

        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType) {
        for (int i = 1; i <= NumberOfKeys; i++)

        {
            std::cout << "Key [" << i << "] : ";
            std::cout << GenerateKey(CharType) << std::endl;
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To) {
        for (int i = 0; i < arrLength; i++) arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(std::string arr[100], int arrLength, enCharType CharType,
                                         short Wordlength) {
        for (int i = 0; i < arrLength; i++) arr[i] = GenerateWord(CharType, Wordlength);
    }

    static void FillArrayWithRandomKeys(std::string arr[100], int arrLength, enCharType CharType) {
        for (int i = 0; i < arrLength; i++) arr[i] = GenerateKey(CharType);
    }

    static void Swap(int& A, int& B) {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double& A, double& B) {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool& A, bool& B) {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char& A, char& B) {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(std::string& A, std::string& B) {
        std::string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B) { clsDate::SwapDates(A, B); }

    static void ShuffleArray(int arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void ShuffleArray(std::string arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static std::string Tabs(short NumberOfTabs) {
        std::string t = "";

        for (int i = 1; i < NumberOfTabs; i++) {
            t = t + "\t";
            std::cout << t;
        }
        return t;
    }

    static std::string EncryptText(std::string Text, short EncryptionKey) {
        for (int i = 0; i <= Text.length(); i++) {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text;
    }

    static std::string DecryptText(std::string Text, short EncryptionKey) {
        for (int i = 0; i <= Text.length(); i++) {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    static std::string RepeatChar(char ch, int count) { return std::string(count, ch); }

    static string NumberToText(int Number) {
        if (Number == 0) {
            return "Zero";
        }

        // Arrays for different ranges of numbers
        const string oneToNineteen[] = {"",        "One",     "Two",       "Three",    "Four",
                                        "Five",    "Six",     "Seven",     "Eight",    "Nine",
                                        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        const string tens[] = {"",      "",      "Twenty",  "Thirty", "Forty",
                               "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const string thousands[] = {"", "Thousand", "Million", "Billion", "Trillion"};

        // Helper function to convert numbers from 1 to 999
        auto convertThreeDigits = [&](int num) {
            string result = "";
            if (num >= 100) {
                result += oneToNineteen[num / 100] + " Hundred ";
                num %= 100;
            }
            if (num >= 20) {
                result += tens[num / 10] + " ";
                num %= 10;
            }
            if (num > 0) {
                result += oneToNineteen[num] + " ";
            }
            return result;
        };

        string result = "";
        int index = 0;

        // Process each group of 3 digits (thousands, millions, etc.)
        while (Number > 0) {
            if (Number % 1000 != 0) {
                result = convertThreeDigits(Number % 1000) + thousands[index] + " " + result;
            }
            Number /= 1000;
            index++;
        }

        // Trim any extra spaces
        result = result.substr(0, result.size() - 1);  // Remove trailing space

        return result;
    }
};
