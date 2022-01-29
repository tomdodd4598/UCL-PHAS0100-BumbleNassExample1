#ifndef FRIENDS_H
#define FRIENDS_H

#include <functional>
#include <memory>
#include <string>

namespace pointers {

    template<typename Ptr, typename Sptr, const char* str>
    class Person {
    protected:
        template <typename Univ>
        Person(Univ&& name);
    
    public:
        ~Person();

        virtual std::function<Sptr()> get_friend_shared_ptr_lambda() = 0;

        virtual void print_friend();
    
    protected:
        const std::string _name;
    
    public:
        Ptr best_friend;
    };

    extern const char TROUBLESOME[];

    class TroublesomePerson : public Person<std::shared_ptr<TroublesomePerson>, std::shared_ptr<TroublesomePerson>, TROUBLESOME> {
    public:
        TroublesomePerson(std::string&& name);

        ~TroublesomePerson();

        virtual std::function<std::shared_ptr<TroublesomePerson>()> get_friend_shared_ptr_lambda();
    };

    extern const char SENSIBLE[];

    class SensiblePerson : public Person<std::weak_ptr<SensiblePerson>, std::shared_ptr<SensiblePerson>, SENSIBLE> {
    public:
        SensiblePerson(std::string&& name);

        ~SensiblePerson();

        virtual std::function<std::shared_ptr<SensiblePerson>()> get_friend_shared_ptr_lambda();
    };
}

#endif
