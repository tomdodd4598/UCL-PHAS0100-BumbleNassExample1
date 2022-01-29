#include "bowler.hpp"
#include "lambdas.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

namespace lambdas {

    void test_func() {
        using namespace std;

        vector<int> vec{1, 1, 2, 3, 5, 8, 13, 21};

        auto all_count_if = [](auto& collection, auto&& condition) -> int {
            return count_if(collection.begin(), collection.end(), condition);
        };

        auto count_evens = [&all_count_if](auto& collection) -> int {
            return all_count_if(collection, [](int i) { return (i & 1) == 0; });
        };

        cout << count_evens(vec) << '\n';

        cout << '\n';

        vector<Bowler> bowlers{
            Bowler("Briggsy", 2859, 5325, 109),
            Bowler("Marcus", 325, 656, 17),
            Bowler("Maxwise", 234, 384, 13),
            Bowler("Lansdell", 4219, 7932, 156),
            Bowler("Thane", 9483, 15532, 434),
        };

        auto all_map = [](auto& collection, auto& target, auto&& mapping) {
            transform(collection.begin(), collection.end(), target.begin(), mapping);
        };

        auto bowler_strings = vector<string>(bowlers.size());

        auto all_map_strings = [&all_map](auto& collection, auto& target) {
            all_map(collection, target, [](Bowler x) { return x.to_string(); });
        };

        all_map_strings(bowlers, bowler_strings);

        auto all_print = [](auto& collection) {
            for (auto& x : collection) {
                cout << x << '\n';
            }
        };

        all_print(bowler_strings);
        cout << '\n';

        auto all_sort = [](auto& collection, auto&& compare) {
            sort(collection.begin(), collection.end(), compare);
        };

        auto all_sort_print = [&](auto& collection, auto& strings, auto&& compare) {
            all_sort(collection, compare);
            all_map_strings(bowlers, bowler_strings);
            all_print(strings);
            cout << '\n';
        };

        all_sort_print(bowlers, bowler_strings, [](Bowler x, Bowler y) { return x.wickets > y.wickets; });
        all_sort_print(bowlers, bowler_strings, [](Bowler x, Bowler y) { return x.get_average() < y.get_average(); });
    }
}
