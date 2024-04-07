#include "binary_operations.h"
#include <bitset>

// Function to convert decimal number to binary
std::string decimalToBinary(int decimal) {
    return std::bitset<16>(decimal).to_string(); // Assuming numbers are not greater than 8 bits
}

// Function to perform addition on binary numbers
std::string binaryAddition(std::string binary1, std::string binary2) {
    int decimal1 = std::stoi(binary1, nullptr, 2);
    int decimal2 = std::stoi(binary2, nullptr, 2);
    int result = decimal1 + decimal2;
    return decimalToBinary(result);
}

// Function to perform subtraction on binary numbers
std::string binarySubtraction(std::string binary1, std::string binary2) {
    int decimal1 = std::stoi(binary1, nullptr, 2);
    int decimal2 = std::stoi(binary2, nullptr, 2);
    int result = decimal1 - decimal2;
    return decimalToBinary(result);
}

// Function to perform multiplication on binary numbers
std::string binaryMultiplication(std::string binary1, std::string binary2) {
    int decimal1 = std::stoi(binary1, nullptr, 2);
    int decimal2 = std::stoi(binary2, nullptr, 2);
    int result = decimal1 * decimal2;
    return decimalToBinary(result);
}

// Function to perform division on binary numbers
std::string binaryDivision(std::string binary1, std::string binary2) {
    int decimal1 = std::stoi(binary1, nullptr, 2);
    int decimal2 = std::stoi(binary2, nullptr, 2);
    int result = decimal1 / decimal2;
    return decimalToBinary(result);
}
