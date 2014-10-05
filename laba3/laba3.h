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
            Node *parent; //??? ���� ��? � �������� ����� �����)))

};

class Tree
{
    public:
            Tree();
            Tree(const Tree&); //??? ����� �� �����?
            ~Tree();

            void InsertEl(int); //������� ��������
            void DeleteEl(int); //�������� ��������
            bool FindEl(int); //����� �������� � ������ (����� - ������ ���� ��� ���



    private:
            Node *root;
            Node* InsertEl(Node*, int);
            Node* DeleteEl(Node*, int);
            Node* FindEl(Node*, int);
            void DeleteAllTree(Node*);





};

#endif // LABA3_H
