#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStringList>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT

    QLineEdit *line;

public:
    Widget(QWidget *parent = 0);
    ~Widget();

signals:
    void numberAdded(QString);

private slots:
    void moveRight();
    void moveLeft();
    void clear();

};

#endif // WIDGET_H
