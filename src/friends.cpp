#include "friends.hpp"

#include <iostream>

namespace pointers {
    
    template<typename T>
    Person<T>::Person(std::string name) : name{name} {

    }

    template<typename T>
    Person<T>::~Person() {

    }

    TroublesomePerson::TroublesomePerson(std::string name) : Person(name) {}

    SensiblePerson::SensiblePerson(std::string name) : Person(name) {}
}