#include "laba2.h"
#include <iostream>
#include <math.h>

using namespace std;

//Конструкторы и деструктор
Vector::Vector():n(n)
{
    coord = new double[n];
    for(int i = 0; i < n; i++)
        coord[i] = 0;
}

Vector::Vector(int n):n(n)
{
    coord = new double[n];
    for(int i = 0; i < n; i++)
        coord[i] = 0;
}

Vector::Vector(const Vector &original)
{
    n = original.n;
    coord = new double[n];

    for (int i = 0; i < n; i++)
    {
        coord[i] = original[i];
    }
}

Vector::~Vector()
{
    n = 0;
    delete [] coord;
    coord = nullptr;
}

//Перегрузка ввода/вывода
ostream& operator<<(ostream& myOut,const Vector &Vec)
{
    for(int i = 0; i < Vec.getSize(); i++)
    {
        myOut << Vec.getCoord(i) << "  ";
    }
    return myOut;
}

istream& operator>>(istream& myIn, Vector& Vec)
{
    int coordinate;
    cout << "Enter the coordinates of vector: " << endl;
    for(int i = 0; i < Vec.getSize(); i++)
    {
        cout << "[" << i+1 << "] Coordinate: ";
        myIn >> coordinate;
        Vec.takeCoord(i,coordinate);
    }
    return myIn;
}

//Получение и запись необходимых элементов
int Vector::getCoord(int i) const
{
    return coord[i];
}

int Vector::getSize() const
{
    return n;
}

void Vector::takeCoord(int i,int coordinate)
{
    coord[i] = coordinate;
}

//Вычислялки
double Vector::Module() const
{
    double module = 0;

    for (int i = 0; i < n; ++i)
    {
        module += coord[i]*coord[i];
    }
    module = sqrt(module);
    return module;
}

double Vector::Product(const Vector Vec1, const Vector Vec2)
{
    int product = 0;
    for(int i = 0; i < Vec1.getSize(); i++)
    {
        product += Vec1[i]*Vec2[i];
    }
    return product;
}

void Vector::CollVec (const Vector Vec1, const Vector Vec2)
{
    double cos = (Vector::Product(Vec1, Vec2))/(Vec1.Module()*Vec2.Module());
    if (cos == 1 || cos == -1)
        cout << "Vectors are complanar";
    else cout << "Vectors aren't complanar";
}

void Vector::OrtVec (const Vector Vec1, const Vector Vec2)
{
    if (Vector::Product(Vec1, Vec2) == 0)
        cout << "Vectors are ortogonal";
    else cout << "Vectors aren't ortogonal";
}

//Перешрузки
Vector Vector::operator+(const Vector & Vec)
{
    Vector sum(n);
    for(int i = 0; i < n; i++)
    {
        sum.coord[i] = coord[i] + Vec.coord[i];
    }
    return sum;
}

Vector Vector::operator-(const Vector & Vec)
{
    Vector sub(n);
    for(int i = 0; i < n; i++)
    {
        sub.coord[i] = coord[i] - Vec.coord[i];
    }
    return sub;
}

double &Vector::operator[](int i) const
{
    return coord[i];
}

Vector Vector::operator*(double scalar) const
{
    Vector mult(n);

    for (int i = 0; i < n; ++i)
    {
        mult[i] = coord[i] * scalar;
    }

    return mult;
}

Vector& Vector::operator++()
{
    for (int i = 0; i < n; i++)
    {
        coord[i]++;
    }
    return *this;
}

Vector& Vector::operator--()
{
    for (int i = 0; i < n; i++)
    {
        coord[i]--;
    }
    return *this;
}

Vector & Vector::operator=(const Vector & Vec)
{
    if(this != &Vec)
    {
        delete [] coord;
        n = Vec.n;
        coord = new double[n];
        for (int i = 0; i < n; i++)
        {
            coord[i] = Vec[i];
        }
    }
    return *this;
}

