#include "registration.h"
#include "ui_registration.h"
#include "secondpage.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");
    if(db.open()){
        qDebug("open");
    }
    else {
        qDebug("no open");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE user(name TEXT, log TEXT, pass TEXT, email TEXT, phone INT);");
}

Registration::~Registration()
{
    delete ui;
}



void Registration::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString log = ui->login->text();
    QString pass = ui->pass->text();
    QString mail = ui->email->text();
    QString phone = ui->phone->text();
    query->prepare("INSERT INTO user(name, log, pass,email,phone) "
              "VALUES (:name, :log, :pass, :email, :phone)");
    query->bindValue(":name", name);
    query->bindValue(":log",log);
    query->bindValue(":pass",pass);
    query->bindValue(":email",mail);
    query->bindValue(":phone",phone);
    query->exec();

    close();
    SecondPage window2;
    window2.setModal(true);
    window2.exec();
}

