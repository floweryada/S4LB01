#ifndef LABA3_H
#define LABA3_H

using namespace std;

class Node
{
    public:
            Node(int = 0);
            Node* getRight();
            Node* getLeft();
            Node* getParent();
            int getData();
            void pushRight(Node* );
            void pushLeft(Node* );
            void pushData(int );


    private:
            int data;
            Node *left;
            Node *right;
            Node *parent; //??? надо ли? с дружеств будет нужен)))

};

class Tree
{
    public:
            Tree();
            Tree(const Tree&); //??? нужен ли здесь?
            ~Tree();

            void InsertEl(int); //вставка элемента
            void DeleteEl(int); //удаление элемента
            bool FindEl(int); //поиск эелмента в дереве (вывод - просто есть или нет



    private:
            Node *root;
            Node* InsertEl(Node*, int);
            Node* DeleteEl(Node*, int);
            Node* FindEl(Node*, int);
            void DeleteAllTree(Node*);





};

#endif // LABA3_H
