#ifndef LABA3_H
#define LABA3_H

#include <iostream>

using namespace std;    // раскрытие пространства имён в заголовочнике является плохим тоном

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

        // методы, не изменяющие состояние класса, необходимо помечать модификатором const
        // хорошим тоном также является передача в методы вывода ostream& с организацией вывода в этот поток
		void ShowTree(); //вывод дерева на экран
		bool FindEl(int);//поиск элемента в дереве
		void InsertEl(int);//вставка элемента
		void DeleteEl(int);//удаление элемента

        void ShowTree(Node*); // можно было сделать эти 4 функции в private
        Node*FindEl(Node*,int);
        void InsertEl(Node*&, int);
        void DeleteEl(Node*&, int);

        void DelAllTree(Node*);
        void makeCopy(Node*&, Node*);

        Node* getRoot();
        // можно было сделать эти 4 функции в private, а здесь сделать аналогичные с аргументами-деревьями
        void Union(Node*, Node*);
        void Cross(Node*, Node*);
        void Sub(Node*, Node*);
        void DynSub(Node*, Node*);


    private:

        Node *root;

};

#endif
