#include "lambdas.hpp"

#include <algorithm>
#include <iostream>

namespace lambdas {

    void test_func() {
        using namespace std;

        auto v = {1,2,3,4,5,6,7,8,9,10,21};

        auto count = count_if(v.begin(), v.end(), [](int i) { return i & 2 == 0; });
    }
}
