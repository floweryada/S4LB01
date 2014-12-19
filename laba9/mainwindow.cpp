#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> btnShiftUp, SIGNAL(clicked()), this, SLOT(shiftUp));
    connect(ui -> btnShiftDown, SIGNAL(clicked()), this, SLOT(shiftDown));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::shiftUp()
{
//to do дописать функции сдвига
}

void MainWindow::shiftDown()
{

}
