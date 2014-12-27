#ifndef EXEPTION_H
#define EXEPTION_H
#include <exception>


class DelNotExist : public std::exception
{
    virtual const char* what() const noexcept
    {
        return "You can't delete this element fron the tree, because it's not exist.";
    }
};

class CharNotInt:public std::exception
{

    virtual const char* what()const throw()
    {
        return "You can't use 'char' type.";
    }

};

#endif // EXEPTION_H
