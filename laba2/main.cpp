#include <iostream>
#include "laba2.h"

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter the size of vectors:";
    cin >> n;
    Vector a(n);
    Vector b(n);
    cin >> a;
    cin >> b;
    cout << a << endl;
    cout << b << endl;
    cout << "Modul a: ";
    cout << a.Module() << endl;
    cout << "Modul b: ";
    cout << b.Module() << endl;
    cout << "The scalar product of the vectors: ";
    cout << Vector::Product(a, b);
    cout << endl;
    cout << "Sum of the vectors:";
    cout << a + b << endl;
    cout << "Substraction of the vectors: ";
    cout << a - b << endl;
    double k;
    cout << "Enter the number: ";
    cin >> k;
    cout << "Multiplication on the scalar: ";
    cout << a*k << "   " << b*k << endl;
    Vector::CollVec(a, b);
    cout << endl;
    Vector::OrtVec(a, b);
    cout << endl;

    return 0;
}
