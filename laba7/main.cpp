#include <iostream>
#include <list>
#include <algorithm>


using namespace std;


class MyFunctor
{
public:
    MyFunctor () = default;
    MyFunctor (const MyFunctor &orig) = default;
    MyFunctor &operator=(const MyFunctor &rhs) = default;
    ~MyFunctor() = default;

    int operator()(int i)
    {
        if (i % 2)
            i = i*2;
        else i = i/2;
        return i;
    }

};

int main()
{
    list<int> l;
    int i;

    for (i = 5; i < 20; i++)
        l.push_back(i);

    cout << "The basic list: ";
    list<int>::iterator it = l.begin();
    while (it != l.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl << endl;


    it = transform(l.begin(), l.end(), l.begin(), MyFunctor());

    cout << "The transformed list: ";
    it = l.begin();
    while (it != l.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    return 0;
}
