#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QStringList>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT
    std::vector <int> array;
    QStringList list;

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:

private slots:
    void left();
    void right();

};

#endif // WIDGET_H
