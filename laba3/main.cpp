#include <iostream>
#include "laba3.h"
using namespace std;

int main()
{
    Tree tree1;
    tree1.ShowTree();

    tree1.InsertEl(20);
    tree1.InsertEl(11);
    tree1.InsertEl(8);
    tree1.InsertEl(14);
    tree1.InsertEl(6);
    tree1.InsertEl(12);
    tree1.InsertEl(18);
    tree1.ShowTree();

    tree1.DeleteEl(20);
    cout << "After deleting the element of the tree: ";
    tree1.ShowTree();

    Tree tree2;

    tree2.InsertEl(20);
    tree2.InsertEl(10);
    tree2.InsertEl(9);
    tree2.InsertEl(15);
    tree2.InsertEl(6);
    tree2.InsertEl(16);
    tree2.InsertEl(13);
    tree2.ShowTree();

    Node *root1 = tree1.getRoot();
    Node *root2 = tree2.getRoot();

    Tree tree3 = tree2;
    cout << endl << "The crossing trees: ";
    tree3.Cross(root1, root2);
    tree3.ShowTree();
    cout << endl;

    Tree tree4 = tree2;
    cout << endl << "The union trees: ";
    tree4.Union(root1, root2);
    tree4.ShowTree();
    cout << endl;

    Tree tree5 = tree2;
    cout << endl << "The substract trees: ";
    tree5.Sub(root1, root2);
    tree5.ShowTree();
    cout << endl;


    return 0;
}
