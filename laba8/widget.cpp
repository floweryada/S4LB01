#include "widget.h"
#include <iostream>
#include <QLineEdit>


using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    line = new QLineEdit();
    layout -> addWidget(line);

    QPushButton* butR = new QPushButton ("Move Right");
    connect(butR, SIGNAL(clicked()), this, SLOT(moveRight()));
    layout -> addWidget(butR);

    QPushButton* butL = new QPushButton ("Move Left");
    connect(butL, SIGNAL(clicked()), this, SLOT(moveLeft()));
    layout -> addWidget(butL);

    QPushButton* butC = new QPushButton ("Clear");
    connect(butC, SIGNAL(clicked()), this, SLOT(clear()));
    layout -> addWidget(butC);

    setLayout(layout);
}

Widget::~Widget()
{

}

void Widget::moveLeft()
{
    QString arr = this -> line -> text();
    QStringList normarr = arr.split(" ");
    QStringList *newarr = new QStringList();

        for(int i = 1; i < normarr.length(); i++)
            newarr -> append(normarr[i]);

        newarr -> append(normarr[0]);
        line -> setText(newarr -> join(" "));
}

void Widget::moveRight()
{
    QString arr = this -> line -> text();
    QStringList normarr = arr.split(" ");
    QStringList *newarr = new QStringList();

    newarr -> append(normarr[normarr.length()-1]);
            for(int i = 0; i < normarr.length()-1; i++)
               newarr -> append(normarr[i]);

            line -> setText(newarr -> join(" "));
}

void Widget::clear()
{
    line->setText("");
}
