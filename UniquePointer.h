#include <iostream>

template <class T>
class UniquePointer
{
    public:
        UniquePointer() : myPointer(nullptr){};
        UniquePointer(T* newPointer) : myPointer(newPointer)
        {
            std::cout << "Object created. Pointer : " << myPointer << std::endl;
        };

        //copy constructor
        UniquePointer(const UniquePointer& copyObj) = delete;

        //move constructor
        UniquePointer(UniquePointer&& moveObj)
        {
            this->myPointer = moveObj.myPointer;
            moveObj = nullptr;
        };

        ~UniquePointer()
        {
            std::cout << "Object deleted. Pointer : " << myPointer << std::endl;
            delete myPointer;
        };
        
        //copy assignment
        UniquePointer& operator=(const UniquePointer& copyObj) = delete;

        //move assignment
        void operator=(UniquePointer&& moveObj)
        {
            this->myPointer = moveObj.myPointer;
            moveObj = nullptr;
        };
        
        T* operator->() 
        {
            return this->myPointer;
        }

        T& operator*()
        {
            return *(this->myPointer);
        }

    private:
        T* myPointer = nullptr;

};