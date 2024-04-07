#include <iostream>
#include <string>
#include "binary_operations.h"

int main() {
    int num1, num2;
    std::cout << "Enter the first decimal number: ";
    std::cin >> num1;
    std::cout << "Enter the second decimal number: ";
    std::cin >> num2;

    std::string binary1 = decimalToBinary(num1);
    std::string binary2 = decimalToBinary(num2);

    std::cout << "First number in binary: " << binary1 << std::endl;
    std::cout << "Second number in binary: " << binary2 << std::endl;

    std::cout << "Addition: " << binaryAddition(binary1, binary2) << std::endl;
    std::cout << "Subtraction: " << binarySubtraction(binary1, binary2) << std::endl;
    std::cout << "Multiplication: " << binaryMultiplication(binary1, binary2) << std::endl;
    std::cout << "Division: " << binaryDivision(binary1, binary2) << std::endl;

    return 0;
}
