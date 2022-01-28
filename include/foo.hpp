#ifndef FOO_H
#define FOO_H

#include <memory>

namespace pointers {

    class Foo {
    public:
        Foo();
        ~Foo();
    };

    std::unique_ptr<Foo> unique_foo();
}

#endif
