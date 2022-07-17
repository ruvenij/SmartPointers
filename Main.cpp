#include "UniquePointer.h"
#include "Person.h"
#include <iostream>

int main()
{
    UniquePointer<Person> jack(new Person("Jack", 25));
    std::cout << "First person : " << *jack << ", Ptr address : " << &jack << std::endl;

    UniquePointer<Person> jill(new Person("Jill", 23));
    std::cout << "Second person : " << *jill << ", Ptr address : " << &jill << std::endl;

    return 0;
}