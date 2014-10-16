#include "console.h"
#include "laba4.h"
#include "impl.h"
#include <iostream>


virtual void Console::ShowTree()
{
    int *elem;
    int number;
    pimpl -> GetData(&elem, &number);
    for (int i = 0; i < number; i++)
        cout << elem[i] << " ";
}

void Console::ShowAll()
{
    cout << "The Tree: ";
    ShowTree();
    cout << endl;
}

