#ifndef LABA6_H
#define LABA6_H

using namespace std;

class IteratorImpl;

template <class T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    Node *parent;
};

template <class T>
class Tree
{
    private:
        Node<T> *root;

    public:
        typedef IteratorImpl<T>Iterator;
        friend IteratorImpl<T>;

        Tree();
		~Tree();
		Tree(const Tree<T>&);
		Tree& operator=(const Tree<T>&);

		void ShowTree();
		bool FindEl(int);
		void InsertEl(int);
		void DeleteEl(int);
		void DelAllTree();

        void ShowTree(Node<T>*);
        Node<T>*FindEl(Node<T>*,int);
        void InsertEl(Node<T>*&, int);
        void DeleteEl(Node<T>*&, int);

        void DelAllTree(Node<T>*);
        void makeCopy(Node<T>*&, Node<T>*);

        Node<T>* getRoot();
        void Union(Node<T>*, Node<T>*);
        void Cross(Node<T>*, Node<T>*);
        void Sub(Node<T>*, Node<T>*);
        void DynSub(Node<T>*, Node<T>*);




};

template <class T>
class IteratorImpl
{
public:
    friend Tree<T>;

private:

};




#endif // LABA6_H
