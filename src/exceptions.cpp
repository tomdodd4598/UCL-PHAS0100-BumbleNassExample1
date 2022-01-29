#include "exceptions.hpp"

#include "fraction.hpp"

#include <iostream>

namespace exceptions {

    fraction::Fraction get_input_fraction() {
        using namespace fraction;
        using namespace std;

        bool valid = false;
        do {
            long num, den;

            cout << "Enter numerator: ";
            cin >> num;
            cout << "Enter denominator: ";
            cin >> den;

            try {
                Fraction f = Fraction(num, den);
                return f;
            }
            catch (invalid_argument& e) {
                std::cout << "Error: " << e.what() << '\n';
            }
        }
        while (true);
    }

    void test_func() {
        using namespace std;

        auto f = get_input_fraction();
        cout << f.to_string() << '\n';
    }
}
