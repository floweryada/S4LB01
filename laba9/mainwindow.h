#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QLabel>
#include <QTextEdit>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTextEdit *textEdit;
    Ui::MainWindow *ui;

private slots:
    void shiftUp();
    void shiftDown();
    void openFile();

};

#endif // MAINWINDOW_H
