#include <iostream>
#include <string>

class Person
{
    public:
        Person(const std::string& name, int age)
        {
            this->name = name;
            this->age = age;
        };

        const std::string& getName() const { return this->name; };
        int getAge() const { return this->age; };

        friend std::ostream& operator<<(std::ostream& os, const Person& person)
        {
            os << "My name is " << person.getName() << " and I am " << 
                person.getAge() << " years old";
            return os;
        }

    private:
        std::string name;
        int age;

};