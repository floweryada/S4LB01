#include <iostream>
#include "laba4.h"
#include "console.h"
#include "prconsole.h"

using namespace std;

int main()
{
    Console tree1;
    tree1.ShowAll();

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
    tree1.ShowAll();

    tree1.DeleteEl(11);
    cout << "After deleting the element of the tree: " << endl;
    tree1.ShowAll();

    Console tree2;

    tree2.InsertEl(20);
    tree2.InsertEl(10);
    tree2.InsertEl(9);
    tree2.InsertEl(23);
    tree2.InsertEl(15);
    tree2.InsertEl(17);
    tree2.InsertEl(6);
    tree2.InsertEl(16);
    tree2.InsertEl(5);
    tree2.ShowAll();


/*
    Tree tree3 = tree2;
    cout << endl << "The crossing trees: " << endl;
    tree3.Cross(root1, root2);
    tree3.ShowTree();
    cout << endl;

    Tree tree4 = tree2;
    cout << endl << "The union trees: " << endl;
    tree4.Union(root1, root2);
    tree4.ShowTree();
    cout << endl;

    Tree tree5 = tree2;
    cout << endl << "The substract trees: " << endl;
    tree5.Sub(root1, root2);
    tree5.ShowTree();
    cout << endl;

    Tree tree6 = tree2;
    cout << endl << "The dynamic substract trees: " << endl;
    tree6.DynSub(root1, root2);
    tree6.ShowTree();
    cout << endl;

*/
    return 0;
}
