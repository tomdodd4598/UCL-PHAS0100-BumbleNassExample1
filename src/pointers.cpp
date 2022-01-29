#include "foo.hpp"
#include "friends.hpp"
#include "pointers.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <utility>

namespace pointers {

    void test_func() {
        using namespace std;

        {
            auto foo = unique_foo();
            auto other = move(foo);

            cout << foo.get() << '\n';
            cout << other.get() << '\n';
        }

        cout << '\n';

        auto jonathan = make_shared<TroublesomePerson>("Jonathan");
        {
            auto ricky = make_shared<TroublesomePerson>("Ricky");

            jonathan->best_friend = ricky;
            ricky->best_friend = jonathan;

            ricky->print_friend();
        }
        jonathan->print_friend();

        cout << '\n';

        auto steve = make_shared<SensiblePerson>("Steve");
        {
            auto karl = make_shared<SensiblePerson>("Karl");

            steve->best_friend = karl;
            karl->best_friend = steve;

            karl->print_friend();
        }
        steve->print_friend();
    }
}
