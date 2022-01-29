#include "args.hpp"
#include "collections.hpp"
#include "exceptions.hpp"
#include "lambdas.hpp"
#include "pointers.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <string>

int main(int argc, char** argv) {

    if (argc != 2) {
        throw std::runtime_error("Program requires one argument!");
    }

    auto to_lowercase = [](std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), [](char c){ return std::tolower(c); });
    };

    std::map<std::string, std::function<void()>> m{
        {"collections", collections::test_func},
        {"pointers", pointers::test_func},
        {"lambdas", lambdas::test_func},
        {"exceptions", exceptions::test_func},
    };

    auto arg = std::string(argv[1]);
    to_lowercase(arg);

    if (auto func = m[arg]) {
        func();
    }
    else {
        throw std::runtime_error("Function entry \"" + arg + "\" doesn't exist!");
    }

    return 0;
}
