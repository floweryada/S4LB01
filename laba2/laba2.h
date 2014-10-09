#include "iostream"
#ifndef LABA2_H
#define LABA2_H

using namespace std;

class Vector
{
    int n;
    double *coord;

public:

    //Конструкторы
    Vector();
    Vector(int n);
    //Конструктор копирования
    Vector(const Vector&original);
    //Деструктор
    ~Vector();

    //Функции для вводы/вывода векторов (перегрузка)
    friend std::ostream& operator<<(std::ostream &myOut,const Vector &Vec);
    friend std::istream& operator>>(std::istream &myIn, Vector &Vec);

    //Функции для извлечения размера, координаты и, соответственно, записи координаты
    int getSize() const;
    int getCoord(int i) const;
    void takeCoord(int i,int coordinate);

    //Функции для нахождения модуля вуктора, скалярного произведения
    double Module() const;
    static double Product(const Vector Vec1, const Vector Vec2);

    //Функции, для определения коллинеарности и ортогональности векторов
    static void CollVec (const Vector Vec1, const Vector Vec2);
    static void OrtVec (const Vector Vec1, const Vector Vec2);

    //Перегрузки
    Vector operator+(const Vector & Vec);
    Vector operator-(const Vector & Vec);
    double & operator[](int i) const;
    Vector operator*(double scalar) const;
    Vector & operator++();
    Vector & operator--();
    Vector & operator=(const Vector & Vec);
};

#endif // LABA2_H
