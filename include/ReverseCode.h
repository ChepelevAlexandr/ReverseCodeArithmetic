#ifndef REVERSCODE_H
#define REVERSCODE_H

#include <iostream>
#include <bitset>

template<typename T>
class ReverseCode {
private:
    T value;
public:

    ReverseCode() : value(0) {}

    ReverseCode(T val) : value(val) {}


    void setValue(T val) {
        value = val;
    }

    T getValue() const {
        return value;
    }

    ReverseCode<T> toReverseCode() const {
        return ReverseCode<T>(~value + 1);
    }

    ReverseCode<T> operator+(const ReverseCode<T>& other) const {
        return ReverseCode<T>(value + other.value);
    }

    ReverseCode<T> operator-(const ReverseCode<T>& other) const {
        return ReverseCode<T>(value - other.value);
    }

    ReverseCode<T> operator*(const ReverseCode<T>& other) const {
        return ReverseCode<T>(value * other.value);
    }

    ReverseCode<T> operator/(const ReverseCode<T>& other) const {
        return ReverseCode<T>(value / other.value);
    }

    void print() const {
        std::cout << "Value: " << value << ", Binary: " << std::bitset<sizeof(T) * 8>(value) << std::endl;
    }
};

#endif // REVERSCODE_H
