#ifndef CONSOLE_H
#define CONSOLE_H
#include "laba4.h"

class Console:

    public Tree
    {
    public:
        Console();
        ~Console();
        Console(const Console&);
        Console &operator=(const Console&);
        void ShowTree();

    private:
        virtual void ShowTree(int *, int);


    };

#endif // CONSOLE_H


