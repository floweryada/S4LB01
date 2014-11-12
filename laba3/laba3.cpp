#include "laba3.h"
#include <iostream>

using namespace std;

Tree::Tree()
{
    root=NULL;
}

Tree::~Tree()
{
    DelAllTree(root);
}

Tree::Tree(const Tree& a)
{
    if(root)
    {
        root = new Node;
        root -> data = a.root -> data;
        root -> left = root -> right = 0;
        makeCopy(root,a.root);
    }
}

void Tree::makeCopy(Node*&root1,Node*root2)
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

Tree& Tree::operator=(const Tree& root1)
{
	if(this != &root1)
	{
		DelAllTree(root);
		root = new Node;
		 root -> data = root1.root -> data;
		root -> left = 0;
        root -> right = 0;
		makeCopy(root, root1.root);

	}
	return *this;
}


void Tree::ShowTree(Node* root)
{
    if(root)
    {
        ShowTree(root -> left);
        cout<< root -> data << "  ";
        ShowTree(root -> right);
    }

}

void Tree::ShowTree()
{
    cout << "The Tree: ";
    ShowTree(root);
    cout << endl;
}


Node* Tree::FindEl(Node *root, int k)
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

bool Tree::FindEl(int k)
{
	return (FindEl(root, k) != NULL);
}


void Tree::InsertEl(Node*& root, int k)
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

void Tree::InsertEl(int k)
{
    InsertEl(root, k);
}


void Tree::DeleteEl(Node*& root,int k)
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

void Tree::DeleteEl(int k)
{
    DeleteEl(root, k);
}


void Tree::DelAllTree(Node *root)
{
 if(root -> left)
     DelAllTree(root -> left);

 if(root -> right)
     DelAllTree(root -> right);

 delete root;
}


Node* Tree::getRoot()
{
    return root;
}


void Tree::Union(Node* root1, Node* root2)
{
    if (root1 -> left != NULL)
        {
            if(FindEl((root1 -> left) -> data) == NULL) // FindEl имеет тип bool, сравнение с NULL не нужно (и даже вредно!), сие справедливо и далее
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


void Tree::Cross(Node* root1, Node* root2) //работает немного не так: выкидывает все элементы, которые содержаться в пересечении. Грубо говоря, это динамич разность
{
     if (root1 -> left != NULL)
        {
            if(FindEl((root1 -> left) -> data) == NULL)
                DeleteEl((root1 -> left) -> data);
            Cross(root1 -> left, root2);
        }
    if (root1 -> right !=NULL)
        {
            if(FindEl((root1 -> right) -> data) == NULL)
                DeleteEl((root1 -> right) -> data);
            Cross(root1 -> right, root2);
        }

}


void Tree::Sub(Node* root1, Node* root2)
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
