#include <iostream>

template <class T>
class SharedPointer
{
    public:
        SharedPointer() : myPointer(nullptr), counter(new int(0)) 
        {
            std::cout << "SP Default constructor" << std::endl;
        };

        SharedPointer(T* newPointer) : myPointer(newPointer), counter(new int(1))
        {
            std::cout << "SP Original object is created. Ptr : " << myPointer << ", Ref count : " << *(this->counter) << std::endl;
        };

        //copy constructor
        SharedPointer(const SharedPointer& obj)
        {
            this->myPointer = obj.myPointer;
            this->counter = obj.counter;

            if (obj.myPointer)
            {
                (*counter)++;
                std::cout << "SP Original object is copied from copy constructor. Ptr : " << this << ", Ref count : " << *counter << std::endl;
            }
        }

        //move constructor
        SharedPointer(SharedPointer&& obj)
        {
            this->myPointer = obj.myPointer;
            this->counter = obj->counter;

            if (this->myPointer)
            {
                std::cout << "SP Original object is moved from move constructor. Ptr : " << this << ", Ref count : " << *counter << std::endl;
            }

            obj.myPointer = nullptr;
        }

        //copy assignment
        void operator=(const SharedPointer& obj)
        {
            this->myPointer = obj.myPointer;
            this->counter = obj.counter;
            
            if (obj.myPointer)
            {
                (*counter)++;
                std::cout << "SP Original object is copied from copy assignment. Ptr : " << this << ", Ref count : " << *counter << std::endl;
            }
        }

        //move assignment
        void operator=(SharedPointer&& obj)
        {
            this->myPointer = obj.myPointer;
            this->counter = obj.counter;

            if (this->myPointer)
            {
                std::cout << "SP Original object is moved from move assignment. Ptr : " << this << ", Ref count : " << *counter << std::endl;
            }

            obj.myPointer = nullptr;
        }

        
        ~SharedPointer()
        {
            if (counter)
            {
                (*counter)--;

                if ((*counter) == 0)
                {
                    std::cout << "SP Original object is deleted. Ptr : " << myPointer << std::endl;
                    if (myPointer) delete myPointer;
                    delete counter;
                }
                else
                {
                    std::cout << "SP object is deleted. Ptr : " << myPointer << std::endl;
                }
            }
        };

        T* operator*() const
        {
            return myPointer;
        }

        T* operator->() const
        {
            return myPointer;
        }

        int getRefCount() const
        {
            return *counter;
        }


    private:
        T* myPointer = nullptr;
        int* counter = nullptr; //will be shared among the shared pointers

};