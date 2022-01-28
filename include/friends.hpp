#ifndef FRIENDS_H
#define FRIENDS_H

#include <memory>
#include <string>

namespace pointers {

    template<typename T>
    class Person {
    protected:
        Person(std::string name);
    
    public:
        virtual ~Person() = 0;

        T best_friend;
    
    private:
        std::string name;
    };

    class TroublesomePerson : public Person<std::shared_ptr<TroublesomePerson>> {
    public:
        TroublesomePerson(std::string name);
    };

    class SensiblePerson : public Person<std::weak_ptr<SensiblePerson>> {
    public:
        SensiblePerson(std::string name);
    };
}

#endif
