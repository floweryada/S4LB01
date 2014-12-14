#include "console.h"
#include <iostream>

using namespace std;

Console::Console()
{
}

Console::~Console()
{
}

Console::Console(const Console& rhs): Tree(rhs)
{
}

Console& Console::operator=(const Console &rhs)
{
}

void Console::ShowTree(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void Console::ShowTree()
{
    int *array = nullptr;
    int size = 0;
    GetElem(array, size);
    ShowTree(array, size);
    delete []array;
    array = nullptr;
}

