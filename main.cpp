#include <iostream>
#include <bitset>
#include <type_traits>

template<typename T>
class BinaryNumber {
private:
    T decimal;
public:
    explicit BinaryNumber(T value) : decimal(value) {}

    std::bitset<sizeof(T) * 8> toBinary() const {
        return std::bitset<sizeof(T) * 8>(decimal);
    }

    BinaryNumber<T> operator+(const BinaryNumber<T>& other) const {
        return BinaryNumber<T>(decimal + other.decimal);
    }

    BinaryNumber<T> operator-(const BinaryNumber<T>& other) const {
        return BinaryNumber<T>(decimal - other.decimal);
    }

    BinaryNumber<T> operator*(const BinaryNumber<T>& other) const {
        return BinaryNumber<T>(decimal * other.decimal);
    }

    BinaryNumber<T> operator/(const BinaryNumber<T>& other) const {
        return BinaryNumber<T>(decimal / other.decimal);
    }
};

int main() {
    int a, b;

    std::cout << "Enter the first integer: ";
    std::cin >> a;
    std::cout << "Enter the second integer: ";
    std::cin >> b;

    BinaryNumber<int> num1(a);
    BinaryNumber<int> num2(b);

    std::cout << "Num1 in binary: " << num1.toBinary() << std::endl;
    std::cout << "Num2 in binary: " << num2.toBinary() << std::endl;

    BinaryNumber<int> sum = num1 + num2;
    BinaryNumber<int> difference = num1 - num2;
    BinaryNumber<int> product = num1 * num2;
    BinaryNumber<int> quotient = num1 / num2;

    std::cout << "Sum: " << sum.toBinary() << std::endl;
    std::cout << "Difference: " << difference.toBinary() << std::endl;
    std::cout << "Product: " << product.toBinary() << std::endl;
    std::cout << "Quotient: " << quotient.toBinary() << std::endl;

    return 0;
}
