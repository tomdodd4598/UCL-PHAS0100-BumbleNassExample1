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

        //auto foo = new Foo();
        //delete foo;

        auto foo = unique_foo();
        auto other = move(foo);

        cout << foo.get() << endl;
        cout << other.get() << endl;

        cout << endl;

        auto jonathan = make_shared<TroublesomePerson>("Jonathan");
        auto ricky = make_shared<TroublesomePerson>("Ricky");

        auto steve = make_shared<SensiblePerson>("Steve");
        auto karl = make_shared<SensiblePerson>("Karl");
    }
}
