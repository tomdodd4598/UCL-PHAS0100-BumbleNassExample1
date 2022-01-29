#include "friends.hpp"

#include <functional>
#include <iostream>

namespace pointers {
    
    template<typename Ptr, typename Sptr, const char* str>
    template <typename Univ>
    Person<Ptr, Sptr, str>::Person(Univ&& name) : _name{name} {
        std::cout << "The " << str << " " << name << " has joined!\n";
    }

    template<typename Ptr, typename Sptr, const char* str>
    Person<Ptr, Sptr, str>::~Person() {
        std::cout << "The " << str << " " << _name << " has left...\n";
    }

    template<typename Ptr, typename Sptr, const char* str>
    void Person<Ptr, Sptr, str>::print_friend() {
        std::cout << "The " << str << " " << _name;

        if (auto ptr = get_friend_shared_ptr_lambda()()) {
            std::cout << " is best friends with " << ptr->_name << ".\n";
        }
        else {
            std::cout << " does not have a best friend...\n";
        }
    }

    extern const char TROUBLESOME[] = "troublesome";

    TroublesomePerson::TroublesomePerson(std::string&& name) : Person(name) {}

    TroublesomePerson::~TroublesomePerson() {}

    std::function<std::shared_ptr<TroublesomePerson>()> TroublesomePerson::get_friend_shared_ptr_lambda() {
        return [this]() { return best_friend; };
    }

    extern const char SENSIBLE[] = "sensible";

    SensiblePerson::SensiblePerson(std::string&& name) : Person(name) {}

    SensiblePerson::~SensiblePerson() {}

    std::function<std::shared_ptr<SensiblePerson>()> SensiblePerson::get_friend_shared_ptr_lambda() {
        return [this]() { return best_friend.lock(); };
    }
}