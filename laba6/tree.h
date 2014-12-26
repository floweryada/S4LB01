#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cmath>
#include <windows.h>
#include "Exeption.h"
#include "IteratorImpl.h"

using namespace std;

template <typename T>

class Tree
{
    struct Node;

public:
    typedef SmartPointer<Node> SmNode;
    typedef IteratorImpl<Tree<T>, T, SmNode>Iterator;

private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        Node *parent;

    };

    Node *root;
    friend Iterator;
    T* type;
    int height, index;


public:
    Tree() { root = NULL; }

    ~Tree()
    {
        DelAllTree(root);
    }

    Tree(const Tree& a)
    {
        if(root)
        {
            root = new Node;
            root -> data = a.root -> data;
            root -> left = root -> right = 0;
            makeCopy(root,a.root);
        }
    }

    Tree& operator=(const Tree<T> &a)
    {
        if(this != &a)
        {
            DelAllTree(root);
            root = new SmNode;
            root -> data = a.root -> data;
            root -> left = 0;
            root -> right = 0;
            makeCopy(root, a.root);
        }
        return *this;
    }


    void ShowTree()
    {
        cout << "The Tree: ";
        ShowTree(root);
        cout << endl;
    }

    bool FindEl(T k)
    {
        return (FindEl(root, k) != NULL);
    }

    void InsertEl(T k)
    {
        InsertEl(root, k);
    }

    void DeleteEl(T k)
    {
        DeleteEl(root, k);
    }

    void DelAllTree()
    {
        if(root -> left)
            DelAllTree(root -> left);

        if(root -> right)
            DelAllTree(root -> right);

        delete root;
    }


    void ShowTree(Node* root)
    {
        if(root)
        {
            ShowTree(root -> left);
            cout<< root -> data << "  ";
            ShowTree(root -> right);
        }

    }

    Node* FindEl(Node *root, int k)
    {
        if(root == NULL)
            return 0;
        else
        {
            if(k < root -> data)
                return FindEl(root -> left, k);
            else
            {
                if(k > root -> data)
                    return FindEl(root -> right, k);
                else
                    return root;
            }
        }
    }

    Node* InsertEl(Node*& root, int k)
    {
        if(root == NULL)
        {
            root = new Node;
            root -> data = k;
            root -> left = 0;
            root -> right = 0;
        }
        else
        {
            if(k < root -> data)
                InsertEl(root -> left, k);
            else
            {
                if(k > root -> data)
                    InsertEl(root -> right, k);
            }
        }
    }


    void DeleteEl(Node*& root,int k)
    {
        Node *helpNode;
        if(root)
        {
            if(k < root -> data)
                DeleteEl(root -> left, k);
            else
            {
                if(k > root -> data)
                    DeleteEl(root -> right, k);
                else
                {
                    if(root -> left == NULL)
                    {
                        helpNode = root;
                        root = root -> right;
                        delete helpNode;
                    }

                    else
                    {
                        if(root -> right == NULL)
                        {
                            helpNode = root;
                            root = root -> left;
                            delete helpNode;
                        }
                        else// ������, ����� � ������� ��� �������
                        {
                            helpNode = root -> right;
                            while(helpNode -> left)
                                helpNode = helpNode -> left;

                            root -> data = helpNode -> data;
                            DeleteEl(root -> right, helpNode -> data);
                        }
                    }
                }
            }
        }
    }


    void DelAllTree(Node *root)
    {
        if(root -> left)
            DelAllTree(root -> left);

        if(root -> right)
            DelAllTree(root -> right);

        delete root;
    }

    void makeCopy(Node*&root1, Node*root2)
    {
        if(root2 -> left)
        {
            InsertEl((root2 -> left) -> data);
            makeCopy(root1, root2 -> left);
        }
        if(root2 -> right)
        {
            InsertEl((root2 -> right) -> data);
            makeCopy(root1, root2 -> right);
        }
    }

    Node* getRoot()
    {
        return root;
    }


    void Union(Node* root1, Node* root2)
    {
        if (root1 -> left != NULL)
        {
            if(FindEl((root1 -> left) -> data) == NULL)
                InsertEl((root1 -> left) -> data);
            Union(root1 -> left, root2);
        }
        if (root1 -> right != NULL)
        {
            if(FindEl((root1 -> right) -> data) == NULL)
                InsertEl((root1 -> right) -> data);
            Union(root1 -> right, root2);
        }

        root1 = NULL;
    }

    void Cross(Node* root1, Node* root2)
    {
        if (root1 -> left != NULL)
        {
            if(FindEl((root1 -> left) -> data) != NULL)
                InsertEl((root1 -> left) -> data);
            Cross(root1 -> left, root2);
        }
        if (root1 -> right !=NULL)
        {
            if(FindEl((root1 -> right) -> data) != NULL)
                InsertEl((root1 -> right) -> data);
            Cross(root1 -> right, root2);
        }
    }

    void Sub(Node* root1, Node* root2)
    {
        if (root1 -> left != NULL)
        {
            if(FindEl((root1 -> left) -> data) != NULL)
                DeleteEl((root1 -> left) -> data);
            Sub(root1 -> left, root2);
        }
        if (root1 -> right != NULL)
        {
            if(FindEl((root1 -> right) -> data) != NULL)
                DeleteEl((root1 -> right) -> data);
            Sub(root1 -> right, root2);
        }
    }

    void DynSub(Node* root1, Node* root2)
    {
        if (root1 -> left != NULL)
        {
            if(FindEl((root1 -> left) -> data) != NULL)
                DeleteEl((root1 -> left) -> data);
            else InsertEl((root1 -> left) -> data);
            DynSub(root1 -> left, root2);
        }
        if (root1 -> right != NULL)
        {
            if(FindEl((root1 -> right) -> data) != NULL)
                DeleteEl((root1 -> right) -> data);
            else InsertEl((root1 -> right) -> data);
            DynSub(root1 -> right, root2);
        }

    }

Iterator begin ()
{
    Node* lastNode;
    lastNode = root;
    while (lastNode -> left)
        lastNode = lastNode -> left;
    return Iterator(this, lastNode);
}

Iterator end()
{
    return Iterator(this, 0);
}

};

#endif // TREE_H
