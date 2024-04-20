#include <iostream>
#include <bitset>

template<typename B>
class ones_compl_int {
private:
    B data;

public:
    static constexpr int BITS = sizeof(B) * 8;
    static constexpr B SIGN_BIT = B(1) << (BITS - 1);

    ones_compl_int(B value = 0) : data(value) {}

    ones_compl_int<B> ones_complement() const {
        return ones_compl_int<B>(~data);
    }

    ones_compl_int<B> twos_complement() const {
        return ones_compl_int<B>(~data + 1);
    }

    ones_compl_int<B> operator+(const ones_compl_int<B>& other) const {
        return ones_compl_int<B>(data + other.data);
    }

    ones_compl_int<B> operator-(const ones_compl_int<B>& other) const {
        return *this + other.twos_complement();
    }

    ones_compl_int<B> operator*(const ones_compl_int<B>& other) const {
        B result = 0;
        B multiplicand = data;
        B multiplier = other.data;

        for (int i = 0; i < BITS; ++i) {
            if (multiplier & B(1)) {
                result += multiplicand;
            }
            multiplicand <<= 1;
            multiplier >>= 1;
        }

        return ones_compl_int<B>(result);
    }

    ones_compl_int<B> operator/(const ones_compl_int<B>& other) const {
        B dividend = data;
        B divisor = other.data;


        bool dividend_sign = (dividend >> (BITS - 1)) & 1;
        bool divisor_sign = (divisor >> (BITS - 1)) & 1;

        dividend = ones_compl_int<B>(dividend).twos_complement().data;
        divisor = ones_compl_int<B>(divisor).twos_complement().data;

        B quotient = 0;
        B remainder = 0;

        for (int i = 0; i < BITS; ++i) {
            remainder <<= 1;
            remainder |= (dividend >> (BITS - 1)) & 1;
            dividend <<= 1;

            if (remainder >= divisor) {
                remainder -= divisor;
                quotient |= 1;
            }

            quotient <<= 1;
        }

        quotient >>= 1;


        if (dividend_sign != divisor_sign) {
            quotient = ones_compl_int<B>(quotient).twos_complement().data;
        }

        return ones_compl_int<B>(quotient);
    }

    friend std::ostream& operator<<(std::ostream& os, const ones_compl_int<B>& obj) {
        return os << std::bitset<BITS>(obj.data);
    }
};

int main() {

    int num1, num2;

    std::cout << "first integer: ";
    std::cin >> num1;
    std::cout << "second integer: ";
    std::cin >> num2;

    ones_compl_int<uint32_t> a(num1);
    ones_compl_int<uint32_t> b(num2);

    std::cout << "first integer: " << a << std::endl;
    std::cout << "second integer: " << b << std::endl;

    ones_compl_int<uint32_t> sum = a + b;
    std::cout << "Sum: " << sum << std::endl;

    ones_compl_int<uint32_t> difference = a - b;
    std::cout << "Difference: " << difference << std::endl;

    ones_compl_int<uint32_t> product = a * b;
    std::cout << "Product: " << product << std::endl;

    ones_compl_int<uint32_t> quotient = a / b;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}
