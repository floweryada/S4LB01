#include "laba4.h"
#include "impl.h"
#include <iostream>

using namespace std;

Impl::Impl()
{
    root = NULL;
}

Impl::~Impl()
{
    DelAllTree(getRoot());
}

Impl::Impl(const Impl& a)
{
    if(root)
    {
        root = new Node;
        root -> data = a.root -> data;
        root -> left = root -> right = 0;
        makeCopy(root,a.root);
    }
}

void Impl::makeCopy(Node*&root1,Node*root2)
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

Impl& Impl::operator=(const Impl& root1)
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



 Impl::Node* Impl::FindEl(Impl::Node *root, int k)
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

bool Impl::FindEl(int k)
{
	return (FindEl(getRoot(), k) != NULL);
}


void Impl::InsertEl(Node*& root, int k)
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

void Impl::InsertEl(int k)
{
    InsertEl(root, k);
}


void Impl::DeleteEl(Node*& root,int k)
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

void Impl::DeleteEl(int k)
{
    DeleteEl(root, k);
}


void Impl::DelAllTree(Node *root)
{
 if(root -> left)
     DelAllTree(root -> left);

 if(root -> right)
     DelAllTree(root -> right);

 delete root;
}

void Impl::DelAllTree()
{
    DelAllTree(root);
}

Impl::Node* Impl::getRoot()
{
    return root;
}

void Impl::findSize(Node* node, int& resSize)
{
    if (node -> left)
    {
        resSize++;
        findSize(node -> left, resSize);
    }
    if (node -> right)
    {
        resSize++;
        findSize(node -> right, resSize);
    }
}

int Impl::getSize()
{
    int resSize = 1;
    findSize(root, resSize);
    return resSize;
}

void Impl::createArray(Node* node, int *& array, int & index)
{
    if (node -> left)
    {
        index++;
        array[index]=(node -> left) -> data;
    }
    if (node -> right)
    {
        index++;
        array[index]=(node -> right) -> data;
    }
    if (node -> left)
        createArray(node -> left, array, index);
    if (node -> right)
        createArray(node -> right, array, index);
}

void Impl::GetElem(int *&array, int &size)
{
    size = getSize();
    array = nullptr;
    array = new int[size];
    int index = 0;
    array[index] = root -> data;
    createArray(root, array, index);
}

void Impl::Union(Node* root1, Node* root2)
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


Impl Impl::GoodUnion (Impl *t)
{
    Impl *result = new Impl();
    result -> Union(getRoot(), t -> getRoot());
    return *result;
}


void Impl::Cross(Node* root1, Node* root2)
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

Impl Impl::GoodCross (Impl *t)
{
    Impl *result = new Impl();
    result -> Cross(getRoot(), t -> getRoot());
    return *result;
}


void Impl::Sub(Node* root1, Node* root2)
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

Impl Impl::GoodSub (Impl *t)
{
    Impl *result = new Impl();
    result -> Sub(getRoot(), t -> getRoot());
    return *result;
}


void Impl::DynSub(Node* root1, Node* root2)
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

Impl Impl::GoodDynSub (Impl *t)
{
    Impl *result = new Impl();
    result -> DynSub(getRoot(), t -> getRoot());
    return *result;
}

int Impl::Number(Node*root)
{
	if (root -> left == NULL && root -> right == NULL)
		return 1;

	int left1, right1;
	if (root -> left)
		left1 = Number(root -> left);

	else
		left1 = 0;

	if (root -> right)
		right1 = Number(root -> right);

	else
		right1 = 0;

	return left1+right1;
}

int Impl::Number()
{
    return Number(root);
}

void Impl::ForShow(int *arr, int i,Node* root)
{
    int lnum = 0;
    if(root -> left)
    {
        ForShow(arr, i+1, root -> left);
        lnum = Number(root -> left);
    }
    if(root -> right)
    {
        ForShow(arr, i+1+lnum, root -> right);
        lnum = Number(root -> right);
    }
}

void Impl::GetData(int *&arr, int &size)
{
    size = this -> Number();
	arr = new int[size-1];

    ForShow(arr, 0, root);
}

