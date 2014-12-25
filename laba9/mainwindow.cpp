#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> pushButton, SIGNAL(clicked()), this, SLOT(shiftUp()));
    connect(ui -> pushButton_2, SIGNAL(clicked()), this, SLOT(shiftDown()));
    connect(ui -> actionSave, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui -> actionClose, SIGNAL(triggered()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::shiftUp()
{
    QString temp = ui->textEdit->toPlainText();
    int n=sqrt(temp.split(",", QString::SkipEmptyParts).length());
    int x[n][n];
     QString str[n][n];
        for (int i=0;i<n;i++)
          for (int j=0;j<n;j++)
          {
            x[i][j]= temp.split(",", QString::SkipEmptyParts)[i*n+j].toInt();
          }
        for (int i=0; i<n; i++)
        {
            QString k;
            k=QString("%1").arg(x[0][i]);
            for (int j=0; j<n; j++)
                str[j][i]=QString("%1").arg(x[j+1][i]);
            str[n-1][i]=k;
        }
        for (int i=0;i<n;i++)
         {   for(int j=0;j<n;j++)
        { if((i+j)>0)
            str[0][0] += ","+str[i][j];
        }
        str[0][0]+=";";
        }

     ui->textBrowser_2->setText(str[0][0]);
}

void MainWindow::shiftDown()
{
    QString temp = ui->textEdit->toPlainText();
    int n=sqrt(temp.split(",", QString::SkipEmptyParts).length());
    int x[n][n];
     QString str[n][n];
        for (int i=0;i<n;i++)
          for (int j=0;j<n;j++)
          {
            x[i][j]= temp.split(",", QString::SkipEmptyParts)[i*n+j].toInt();
          }
        for (int i=0; i<n; i++)
        {
            QString k;
            k=QString("%1").arg(x[n-1][i]);
            for (int j=1; j<n; j++)
                str[j][i]=QString("%1").arg(x[j-1][i]);
            str[0][i]=k;
        }
        for (int i=0;i<n;i++)
         {   for(int j=0;j<n;j++)
        { if((i+j)>0)
            str[0][0] += ","+str[i][j];
        }
        str[0][0]+=";";
        }

     ui->textBrowser_2->setText(str[0][0]);
}
