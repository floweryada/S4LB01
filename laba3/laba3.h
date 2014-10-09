#ifndef LABA3_H
#define LABA3_H

#include <iostream>

using namespace std;

 struct Node
{
    int data;
    Node *left;
    Node *right;

};

class Tree
{
    public:
        Tree();
		~Tree();
		Tree(const Tree&);
		Tree& operator=(const Tree&);

		void ShowTree(); //вывод дерева на экран
		bool FindEl(int);//поиск элемента в дереве
		void InsertEl(int);//вставка элемента
		void DeleteEl(int);//удаление элемента

        void ShowTree(Node*);
        Node*FindEl(Node*,int);
        void InsertEl(Node*&, int);
        void DeleteEl(Node*&, int);

        void DelAllTree(Node*);
        void makeCopy(Node*&, Node*);

        Node* getRoot();
        void Union(Node*, Node*);
        void Cross(Node*, Node*);
        void Sub(Node*, Node*);
        void DynSub(Node*, Node*);


    private:

        Node *root;

};

#endif
