#include <iostream>
#include "laba4.h"
#include "console.h"
#include "prconsole.h"

using namespace std;

int main()
{
    Console tree1;

    tree1.InsertEl(20);
    tree1.InsertEl(11);
    tree1.InsertEl(8);
    tree1.InsertEl(14);
    tree1.InsertEl(6);
    tree1.InsertEl(4);
    tree1.InsertEl(12);
    tree1.InsertEl(17);
    tree1.InsertEl(25);
    tree1.InsertEl(18);
    tree1.ShowTree();

    tree1.DeleteEl(11);
    cout << "After deleting the element of the tree: " << endl;
    tree1.ShowTree();
    cout << endl;

    return 0;
}
