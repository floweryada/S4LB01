#include "widget.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);
    layout -> setContentsMargins(5,5,5,5);
    layout -> setSpacing(10);

    QPushButton* butL = new QPushButton ("Shift left");
    connect(butL, SIGNAL(clicked()), this, SLOT(left));
    layout -> addWidget(butL);

    QPushButton* butR = new QPushButton ("Shift right");
    connect(butR, SIGNAL(clicked()), this, SLOT(right));
    layout -> addWidget(butR);

    QLineEdit* box = new QLineEdit();
    layout -> addWidget(box);


}

Widget::~Widget()
{

}

void Widget::right()
{
//to do дописать эти две функции, которые осуществляют сдвиг при нажатии на соответствующие кнопки
}

void Widget::left()
{

}
