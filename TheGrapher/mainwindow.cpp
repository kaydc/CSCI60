#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <grapher.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    double v = arg1.toDouble();
    ui->widget->setA(v);
    ui->widget->update();
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    double v = arg1.toDouble();
    ui->widget->setB(v);
    ui->widget->update();

}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    double v = arg1.toDouble();
    ui->widget->setC(v);
    ui->widget->update();

}





void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    double v = arg1.toDouble();
    ui->widget->setxmax(v);
    ui->widget->update();

}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    double v = arg1.toDouble();
    ui->widget->setxmin(v);
    ui->widget->update();
}


void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    double v = arg1.toDouble();
    ui->widget->setymax(v);
    ui->widget->update();
}



void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    double v = arg1.toDouble();
    ui->widget->setymin(v);
    ui->widget->update();
}

void MainWindow::on_actionSave_triggered()
{
     std::ofstream ofs("plot.dat");
    if (ofs.fail())
    {
      std::  cout<<"cant open fail"<<std::endl;
      exit(1);
    }

     ofs<<a<< b<<c<<std::endl;
}

void MainWindow::on_actionLoad_triggered()
{
     std::ifstream ins("plot.dat");
            if(ins.fail())
            {
                std::cout<<"cannot open this fail"<<std::endl;
                exit(1);
            }
      ins>>a>>b>>c>>xmax>>xmin>>ymax>>ymin;
}

void MainWindow::on_actionQuit_triggered()
{
      exit(2);
}

