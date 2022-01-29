#include "fraction.hpp"

#include <string>

namespace fraction {

    InvalidDenominator::InvalidDenominator(const std::string& what) : std::invalid_argument(what) {}

    std::string Fraction::to_string() {
        return std::to_string(num) + " / " + std::to_string(den);
    }
}
