#include <iostream>

template <class T>
class SharedPointer
{
    public:
        SharedPointer() : myPointer(nullptr){};
        SharedPointer(T* newPointer) : myPointer(newPointer)
        {
            counter++;
        };

        




    private:
        T* myPointer = nullptr;
        int counter = 0;

};