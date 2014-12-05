#include "laba6.h"

#include <iostream>

using namespace std;

template <class T>
Tree<T>::Tree()
{
    root=NULL;
}

template <class T>
Tree<T>::~Tree()
{
    DelAllTree(root);
}

template <class T>
Tree<T>::Tree(const Tree<T>& a)
{
    if(root)
    {
        root = new Node<T>;
        root -> data = a.root -> data;
        root -> left = root -> right = 0;
        makeCopy(root,a.root);
    }
}

template <class T>
void Tree<T>::makeCopy(Node<T>*&root1,Node<T>*root2)
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

template <class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& root1)
{
	if(this != &root1)
	{
		DelAllTree(root);
		root = new Node<T>;
		 root -> data = root1.root -> data;
		root -> left = 0;
        root -> right = 0;
		makeCopy(root, root1.root);

	}
	return *this;
}


template <class T>
void Tree<T>::ShowTree(Node<T>* root)
{
    if(root)
    {
        ShowTree(root -> left);
        cout<< root -> data << "  ";
        ShowTree(root -> right);
    }

}

template <class T>
void Tree<T>::ShowTree()
{
    cout << "The Tree: ";
    ShowTree(root);
    cout << endl;
}


template <class T>
Node<T>* Tree<T>::FindEl(Node<T> *root, int k)
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

template <class T>
bool Tree<T>::FindEl(int k)
{
	return (FindEl(root, k) != NULL);
}


template <class T>
void Tree<T>::InsertEl(Node<T>*& root, int k)
{
    if(root == NULL)
    {
        root = new Node<T>;
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

template <class T>
void Tree<T>::InsertEl(int k)
{
    InsertEl(root, k);
}


template <class T>
void Tree<T>::DeleteEl(Node<T>*& root,int k)
{
    Node<T> *helpNode;
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
                    else// случай, когда у вершины два потомка
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

template <class T>
void Tree<T>::DeleteEl(int k)
{
    DeleteEl(root, k);
}


template <class T>
void Tree<T>::DelAllTree(Node<T> *root)
{
 if(root -> left)
     DelAllTree(root -> left);

 if(root -> right)
     DelAllTree(root -> right);

 delete root;
}

template <class T>
void Tree<T>::DelAllTree()
{
    DelAllTree(root);
}

template <class T>
Node<T>* Tree<T>::getRoot()
{
    return root;
}


template <class T>
void Tree<T>::Union(Node<T>* root1, Node<T>* root2)
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


template <class T>
void Tree<T>::Cross(Node<T>* root1, Node<T>* root2)
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


template <class T>
void Tree<T>::Sub(Node<T>* root1, Node<T>* root2)
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

template <class T>
void Tree<T>::DynSub(Node<T>* root1, Node<T>* root2)
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

