#include <iostream>
#include "SmartPointer.h"
#include "tree.h"

using namespace std;

int main()
{
    typedef Tree<int> IntTree;
    IntTree tree1;

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

    try
    {
        tree1.DeleteEl(57);
    }
    catch(const exception& e)
    {
        cout<<e.what()<<endl;
    }

    for (IntTree::Iterator it = tree1.begin(); it != tree1.end(); ++it)
        cout << *it << " ";
    cout << endl;

/*
    Tree <SmartPointer<int> > tree2;

    tree2.ShowTree();
*/
    return 0;
}
