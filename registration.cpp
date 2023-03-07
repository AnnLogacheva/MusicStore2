#include "registration.h"
#include "ui_registration.h"
#include "secondpage.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}



void Registration::on_pushButton_clicked()
{
    hide();
    SecondPage window2;
    window2.setModal(true);
    window2.exec();
}

