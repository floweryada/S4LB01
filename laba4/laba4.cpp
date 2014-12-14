#include "laba4.h"
#include "impl.h"
#include <iostream>

using namespace std;

Tree::Tree():pimpl(NULL)
{
    pimpl = new Impl;
}

Tree::~Tree()
{
    delete pimpl;
    pimpl = NULL;
}

Tree::Tree(const Tree& a):pimpl(NULL)
{
    pimpl = new Impl(*(a.pimpl));
}



Tree& Tree::operator=(const Tree& root1)
{
	if(this -> pimpl = root1.pimpl)
            return *this;
}


bool Tree::FindEl(int k)
{
	return pimpl -> FindEl(k);
}


void Tree::InsertEl(int k)
{
    pimpl -> InsertEl(k);
}


void Tree::DeleteEl(int k)
{
    pimpl -> DeleteEl(k);
}


void Tree::DelAllTree()
{
    pimpl -> DelAllTree();
}

void Tree::GetElem(int *&array, int &size)
{
    pimpl -> GetElem(array, size);
}


Tree Tree::Union(Tree *t)
{
    Tree *result = new Tree();
    result -> pimpl-> GoodUnion(pimpl);
    result -> pimpl-> GoodUnion(t -> pimpl);
    return *result;

}


Tree Tree::Cross(Tree *t)
{
    Tree *result = new Tree();
    result -> pimpl-> GoodCross(pimpl);
    result -> pimpl-> GoodCross(t -> pimpl);
    return *result;
}


Tree Tree::Sub(Tree *t)
{
    Tree *result = new Tree();
    result -> pimpl-> GoodSub(pimpl);
    result -> pimpl-> GoodSub(t -> pimpl);
    return *result;
}

Tree Tree::DynSub(Tree *t)
{
    Tree *result = new Tree();
    result -> pimpl-> GoodDynSub(pimpl);
    result -> pimpl-> GoodDynSub(t -> pimpl);
    return *result;
}
