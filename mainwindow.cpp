#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondpage.h"
#include "registration.h"
#include "thirdpage.h"
#include<stdio.h>
#include<conio.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    QString login =ui->lineEdit->text();
    QString pass =ui->lineEdit_2->text();
    if (login=="Anna"&& pass=="1234")
    {
        hide();
        SecondPage window1;
        window1.setModal(true);
        window1.exec();
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Registration window2;
    window2.setModal(true);
    window2.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    hide();
    ThirdPage window2;
    window2.setModal(true);
    window2.exec();
}

