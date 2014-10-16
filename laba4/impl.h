#ifndef IMPL_H
#define IMPL_H


class Impl
{
   private:
       struct Node
        {
            int data;
            Node *left;
            Node *right;
        };
        Node *root;

        Node* FindEl(Node*,int);
        void InsertEl(Node*&, int);
        void DeleteEl(Node*&, int);
        void DelAllTree(Node*);

        void makeCopy(Node*&, Node*);

        Node* getRoot();
        void Union(Node*, Node*);
        void Cross(Node*, Node*);
        void Sub(Node*, Node*);
        void DynSub(Node*, Node*);

        int Number(Node*);
        void ForShow(int *, int, Node*);

   public:
        Impl();
		~Impl();
		Impl(const Impl&);
		Impl & operator=(const Impl&);

		bool FindEl(int);//поиск элемента в дереве
		void InsertEl(int);//вставка элемента
		void DeleteEl(int);//удаление элемента
		void DelAllTree();

        Impl GoodUnion (Impl *t);
        Impl GoodCross (Impl *t);
        Impl GoodSub (Impl *t);
        Impl GoodDynSub (Impl *t);

        int Number();
        void GetData(int *&arr, int &size);

};

#endif // IMPL_H
