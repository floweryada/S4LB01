#ifndef LABA4_H
#define LABA4_H

#include <iostream>

using namespace std;

class Tree
{
    public:
        Tree();
		~Tree();
		Tree(const Tree&);
		Tree& operator=(const Tree&);

		bool FindEl(int);//поиск элемента в дереве
		void InsertEl(int);//вставка элемента
		void DeleteEl(int);//удаление элемента
		void DelAllTree();

        Tree Union(Tree*);
        Tree Cross(Tree*);
        Tree Sub(Tree*);
        Tree DynSub(Tree*);

    private:
        class Impl *pimpl;

};

#endif
