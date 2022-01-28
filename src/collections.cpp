#include "collections.hpp"

#include <array>
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
        cout << arr[0] << endl;

        cout << endl;

        vector<string> vec{"Red", "Green", "Blue", "Pink"};
        vec[1] = "Yellow";
        vec.push_back("Pink");
        //vec.pop_back();
        for (auto a : vec) {
            cout << a << endl;
        }

        cout << endl;

        map<string, unsigned int> m;
        for (auto a : vec) {
            if (m.count(a) == 0) {
                m[a] = 1;
            }
            else {
                ++m[a];
            }
        }

        cout << m["Pink"] << endl;

        cout << endl;

        default_random_engine gen;
        uniform_real_distribution<double> dist(0.0, 1.0);
        for (int i = 0; i < 5; ++i) cout << dist(gen) << endl;

        cout << endl;

        auto rand_gen = bind(dist, gen);
        for (int i = 0; i < 5; ++i) cout << rand_gen() << endl;
    }
}
