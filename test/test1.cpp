#include "arithmetic.hpp"
#include "catch.hpp"
#include "main.hpp"

#include <iostream>

#define TEST_SECTION_START std::cout << "Section start: a = " << a << ", b = " << b << "." << std::endl;

TEST_CASE("Addition functions", "[arithmetic]") {

    long a = 0, b = 0, c = 0;

    SECTION("add_integers") {
        TEST_SECTION_START

        a = 14, b = 12;
        REQUIRE(arithmetic::add_integers(a, b) == 26);

        a = 4, b = 33;
        arithmetic::add_integers(a, b, &c);
        REQUIRE(c == 37);
    }

    SECTION("add_pointers") {
        TEST_SECTION_START

        a = 16, b = 23;
        REQUIRE(arithmetic::add_pointers(&a, &b) == 39);

        a = 27, b = 17;
        arithmetic::add_pointers(&a, &b, c);
        REQUIRE(c == 44);
    }
}
