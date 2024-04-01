#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "ReverseCode.h"

template<typename T>
class Visualization {
public:
    static void print(const ReverseCode<T>& obj) {
        obj.print();
    }
};

#endif // VISUALIZATION_H
