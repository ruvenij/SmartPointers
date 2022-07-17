#include "UniquePointer.h"
#include "SharedPointer.h"
#include "Person.h"
#include <iostream>

int main()
{
    UniquePointer<Person> jack(new Person("Jack", 25));
    std::cout << "First person : " << *jack << ", Ptr address : " << &jack << std::endl;

    UniquePointer<Person> jill(new Person("Jill", 23));
    std::cout << "Second person : " << *jill << ", Ptr address : " << &jill << std::endl;

    std::cout << "/////////////////////////////////" << std::endl;
    SharedPointer<Person> peter(new Person("Peter", 15));
    std::cout << "Ref count : " << peter.getRefCount() << std::endl;
    SharedPointer<Person> peterPan(peter);
    std::cout << "Ref count : " << peterPan.getRefCount() << std::endl;
    SharedPointer<Person> peterPanChild;
    peterPanChild = peterPan;
    std::cout << "Ref count : " << peterPanChild.getRefCount() << std::endl;
    SharedPointer<Person> peterChild;
    peterChild = std::move(peterPanChild);
    std::cout << "Ref count : " << peterChild.getRefCount() << std::endl;

    return 0;
}