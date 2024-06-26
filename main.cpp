#include <iostream>

template<typename B>
class ones_compl_int {
private:
    B data;

public:
    ones_compl_int(B value = 0) : data(value) {}

    ones_compl_int twos_complement() const {
        return ones_compl_int(~data + 1);
    }

    ones_compl_int operator+(const ones_compl_int& other) const {
        return ones_compl_int(data + other.data);
    }

    ones_compl_int operator-(const ones_compl_int& other) const {
        return *this + other.twos_complement();
    }

    ones_compl_int operator*(const ones_compl_int& other) const {
        B result = 0;
        B multiplicand = data;
        B multiplier = other.data;

        for (int i = 0; i < sizeof(B) * 8; ++i) {
            if (multiplier & 0x01) {
                result += multiplicand;
            }
            multiplicand <<= 1;
            multiplier >>= 1;
        }

        return ones_compl_int(result);
    }

    ones_compl_int operator/(const ones_compl_int& other) const {
        B dividend = data;
        B divisor = other.data;

        B quotient = 0;
        B remainder = 0;

        bool dividend_sign = (dividend >> (sizeof(B) * 8 - 1)) & 0x01;
        bool divisor_sign = (divisor >> (sizeof(B) * 8 - 1)) & 0x01;
        bool result_sign = dividend_sign ^ divisor_sign;

        dividend = ones_compl_int(dividend).twos_complement().data;
        divisor = ones_compl_int(divisor).twos_complement().data;

        for (int i = 0; i < sizeof(B) * 8; ++i) {
            remainder <<= 1;
            remainder |= (dividend >> (sizeof(B) * 8 - 1)) & 0x01;
            dividend <<= 1;

            if (remainder >= divisor) {
                remainder -= divisor;
                quotient |= 0x01;
            }

            quotient <<= 1;
        }

        quotient >>= 1;

        return ones_compl_int(result_sign ? quotient : ones_compl_int(quotient).twos_complement().data);
    }

    friend std::ostream& operator<<(std::ostream& os, const ones_compl_int& obj) {
        B temp_data = obj.data;
        B mask = static_cast<B>(1) << (sizeof(B) * 8 - 1);
        for (int i = 0; i < sizeof(B) * 8; ++i) {
            os << ((temp_data & mask) ? '1' : '0');
            temp_data <<= 1;
        }
        return os;
    }
};

int main() {

    ones_compl_int<int32_t> a(5);
    ones_compl_int<int32_t> b(-5);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    ones_compl_int<int32_t> sum = a + b;
    std::cout << "Sum: " << sum << std::endl;

    ones_compl_int<int32_t> difference = a - b;
    std::cout << "Difference: " << difference << std::endl;

    ones_compl_int<int32_t> product = a * b;
    std::cout << "Product: " << product << std::endl;

    ones_compl_int<int32_t> quotient = a / b;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}