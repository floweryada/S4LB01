#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include <iostream>

using namespace std;

template <typename T>
class SmartPointer
{
private:
    T* ptr;
    int *quan;

public:
    SmartPointer() { }

    SmartPointer(T* ptr): ptr(ptr)
    {
        quan = new int();
        (*quan)++;
    }

    SmartPointer(const SmartPointer &sp):
        ptr(sp.ptr),
        quan(sp.quan)
    {
        (*quan)++;
    }

    SmartPointer<T>& operator= (const SmartPointer<T> &sp)
    {
        if(&sp != this)
        {
            --(*quan);
            this -> ptr = sp.ptr;
            this -> quan = sp.quan;
            ++(*quan);
        }
        return *this;
    }
    ~SmartPointer()
    {
        if (quan)
        {
            (*quan)--;
            if (*quan == 0)
            {
                delete ptr;
                delete quan;
            }
        }
    }

    T* operator-> () const
    {
        return ptr;
    }

    T operator*() const
    {
        return *(ptr);
    }

    bool operator== (const SmartPointer &sp) const
    {
        return this->ptr == sp.ptr;
    }

    bool operator< (const SmartPointer &sp) const
    {
        return (*ptr)<(*sp.ptr);
    }

    bool operator> (const SmartPointer &sp) const
    {
        return (*ptr)>(*sp.ptr);
    }

    friend ostream& operator<<(ostream& out,const SmartPointer &sp)
    {
        out<<(*sp);
        return out;
    }

};

#endif // SMARTPOINTER_H
