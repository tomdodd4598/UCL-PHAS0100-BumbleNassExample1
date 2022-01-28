#include "foo.hpp"

#include <iostream>
#include <memory>

namespace pointers {

    Foo::Foo() {
        std::cout << "Created!" << std::endl;
    }

    Foo::~Foo() {
        std::cout << "Destroyed!" << std::endl;
    }

    std::unique_ptr<Foo> unique_foo() {
        return std::make_unique<Foo>();
    }
}