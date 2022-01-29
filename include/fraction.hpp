#ifndef FRACTION_H
#define FRACTION_H

#include "factors.hpp"

#include <stdint.h>
#include <string>
#include <utility>

namespace fraction {

    class InvalidDenominator : public std::invalid_argument {
    public:
        InvalidDenominator(const std::string& what);
    };

    struct Fraction {

        long num, den;

        template <typename T>
        Fraction(T&& numerator, T&& denominator) : num{ std::forward<T>(numerator) }, den{ std::forward<T>(denominator) } {
            if (den == 0) {
                throw InvalidDenominator("Fraction denominator can not be zero!");
            }
            factors::factorize(num, den);
        }

        template <typename T>
        Fraction(T&& num) : Fraction(std::forward<T>(num), 1) {}

        std::string to_string();
    };
}

#endif
