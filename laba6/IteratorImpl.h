#ifndef ITERATORIMPL_H
#define ITERATORIMPL_H

template <typename Tree, typename T, typename Node>
class IteratorImpl
{
    friend Tree;

    Tree* par; //��������� �� ������ (������)
    Node cur; //������� ������� (���� ������)

public:
    IteratorImpl():par(0), cur(0) { }
    IteratorImpl(Tree* par, Node cur): par(par), cur(cur) { }
    IteratorImpl(const IteratorImpl &it): par(it.par), cur(it.cur) { }
    IteratorImpl& operator=(const IteratorImpl &it)
    {
        par = it.par;
        cur = it.cur;
        return *this;
    }

    ~IteratorImpl() { }

    T operator*()
    {
        return cur -> data;
    }

    bool operator== (IteratorImpl const &it)
    {
        return (cur == it.cur) && (par == it.par);
    }

    bool operator!= (IteratorImpl const &it)
    {
        return !(*this == it);
    }

    void operator++()
    {
        if (cur -> right)//�������� 1 ��� ������, �� ����� �����
            {
                cur = cur -> right;
                while (cur -> left)
                    cur = cur -> left;
            return;
            }

    }

        IteratorImpl operator++(int)
        {
            IteratorImpl it(*this);
            ++(*this);
            return it;
        }

};

#endif // ITERATORIMPL_H
