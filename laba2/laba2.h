#include "iostream"
#ifndef LABA2_H
#define LABA2_H

using namespace std;

class Vector
{
    int n;
    double *coord;

public:

    //������������
    Vector();
    Vector(int n);
    //����������� �����������
    Vector(const Vector&original);
    //����������
    ~Vector();

    //������� ��� �����/������ �������� (����������)
    friend std::ostream& operator<<(std::ostream &myOut,const Vector &Vec);
    friend std::istream& operator>>(std::istream &myIn, Vector &Vec);

    //������� ��� ���������� �������, ���������� �, ��������������, ������ ����������
    int getSize() const;
    int getCoord(int i) const;
    void takeCoord(int i,int coordinate);

    //������� ��� ���������� ������ �������, ���������� ������������
    double Module() const;
    static double Product(const Vector Vec1, const Vector Vec2);

    //�������, ��� ����������� �������������� � ��������������� ��������
    static void CollVec (const Vector Vec1, const Vector Vec2);
    static void OrtVec (const Vector Vec1, const Vector Vec2);

    //����������
    Vector operator+(const Vector & Vec);
    Vector operator-(const Vector & Vec);
    double & operator[](int i) const;
    Vector operator*(double scalar) const;
    Vector & operator++();
    Vector & operator--();
    Vector & operator=(const Vector & Vec);
};

#endif // LABA2_H
