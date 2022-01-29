#include "collections.hpp"

#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

namespace collections {

    void test_func() {
        using namespace std;
        
        array<string, 5> arr{"Red", "Green", "Blue", "Green", "Green"};
        for (auto a : arr) {
            cout << a << '\n';
        }

        cout << '\n';

        vector<string> vec{"Red", "Green", "Blue", "Pink"};
        vec[1] = "Yellow";
        vec.push_back("Pink");
        //vec.pop_back();
        for (auto a : vec) {
            cout << a << '\n';
        }

        cout << '\n';

        map<string, unsigned int> m;
        for (auto a : vec) {
            if (m.count(a) == 0) {
                m[a] = 1;
            }
            else {
                ++m[a];
            }
        }

        for (auto a : m) {
            cout << a.first << ": " << a.second << '\n';
        }

        cout << '\n';

        default_random_engine gen;
        uniform_real_distribution<double> dist(-1.0, 1.0);
        //for (int i = 0; i < 3; ++i) cout << dist(gen) << '\n';

        //cout << '\n';

        auto rand = bind(dist, gen);
        for (int i = 0; i < 3; ++i) cout << rand() << '\n';

        size_t len;
        cout << "\nMonte Carlo sample size: ";
        cin >> len;
        cout << '\n';
        size_t hits = 0;

        for (int i = 0; i < len; ++i) {
            double x = rand(), y = rand();
            if (std::sqrt(x * x + y * y) < 1.0) {
                ++hits;
            }
        }

        double pi = 4.0 * hits / len;
        cout << pi << '\n';
    }
}
