#include <iostream>
#include "ReverseCode.h"

int main() {

    ReverseCode<int> num1(12);
    ReverseCode<int> num2(4);
    

    std::cout << "Number 1: ";
    num1.print();
    std::cout << "Number 2: ";
    num2.print();

    ReverseCode<int> sum = num1 + num2;
    std::cout << "Sum: ";
    sum.print();

    ReverseCode<int> difference = num1 - num2;
    std::cout << "Difference: ";
    difference.print();

    ReverseCode<int> product = num1 * num2;
    std::cout << "Product: ";
    product.print();

    ReverseCode<int> quotient = num1 / num2;
    std::cout << "Quotient: ";
    quotient.print();

    return 0;
}
