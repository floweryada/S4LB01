#include "laba3.h"

using namespace std;


Node::Node(int k): data(k),left(NULL),right(NULL)
{
}

Node* Node::getRight()
{
    return right;
}

Node* Node::getLeft()
{
    return left;
}

Node* Node::getParent()
{
    return parent;
}

int Node::getData()
{
    return data;
}



void pushRight(Node* right)
{
    this -> right = right;
}

void pushLeft(Node* left)
{
    this -> left = left;
}

void pushData(int k)
{
    data = k;
}




Tree::Tree()
{
    root = NULL;
}

Tree::~Tree()
{
    DeleteAllTree(root);
}

Tree::Tree(const Tree& a)
{

}

void Tree::InsertEl(int k)
{
    root = InsertEl(root, k);
}

Node* Tree::InsertEl(Node* root, int k) //root - корень поддерева, к - вставляемый элемент
{
    if(root != NULL)
    {
        if(k < root -> getData())
        {
            root -> pushLeft(Insert(root -> getLeft(),k));
        }
        else
        {
            if(k > root-> getData())
            {
                root -> pushRight(Insert(root -> getRight(),k));
            }
        }
    }
    else
        root = new Node(k);

	return root;
}

void DeleteEl(int k)
{
    root = DeleteEl(root, k);
}

Node* Tree::DeleteEl(Node* root, int k)
{

}

bool Tree::FindEl(int)
{
    return (FindEl(root, k) != NULL);
}

Node* Tree::FindEl (Node* root, int k)
{
    if(root != NULL)
        {
            if(k < root -> getData())
                return FindEl(root -> getLeft(),k);
            else
                {
                    if(k > root -> getData())
                        return FindEl(root -> getRight(),k);
                    else
                        return root;
                }
        }
    else
        return NULL;
}

void Tree::DeleteAllTree(Node* root)
{
    if(root -> getLeft())
        {
            DeleteAllTree(root->getLeft());
        }
    if(root->getRight())
        {
            DeleteAlTree(root -> getRight());
        }

 delete root;
}

