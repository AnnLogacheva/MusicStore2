#include "secondpage.h"
#include "ui_secondpage.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QString>
#include <QList>
#include <iostream>
#include <QModelIndex>


SecondPage::SecondPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondPage)
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
    //query->exec("CREATE TABLE artist5(name TEXT, band TEXT, songs TEXT);");
    model = new QSqlTableModel(this,db);
    model->setTable("artist5");
    model->select();
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(model);
    QTableView *table = new QTableView();
    table->horizontalHeader()->setStretchLastSection(true);
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->name->hide();
    ui->band->hide();
    ui->song->hide();
    ui->pushButton_3->hide();
    ui->pushButton_7->hide();
}

SecondPage::~SecondPage()
{
    delete ui;
}
//exit
void SecondPage::on_pushButton_clicked()
{
    close();
}
//Add
void SecondPage::on_pushButton_4_clicked()
{
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->name->show();
    ui->band->show();
    ui->song->show();
    ui->pushButton_3->show();
    ui->pushButton_7->show();
}



void SecondPage::on_pushButton_3_clicked()
{
    QString log = ui->name->text();
    QString pass = ui->band->text();
    QString word =ui->song->text();

    if(word=="" || word==" "||log=="" || log==" "||pass=="" || pass==" " ){
        QMessageBox::information(this,tr("Ошибка"),tr("Пустая строка"));
        return;
    }
    query->prepare("INSERT INTO artist5(name, band, songs) "
              "VALUES (:site, :log, :password);");
    query->bindValue(":site", log);
    query->bindValue(":log", pass);
    query->bindValue(":password", word);
    query->exec();
    ui->name->clear();
    ui->band->clear();
    ui->song->clear();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->name->hide();
    ui->band->hide();
    ui->song->hide();
    ui->pushButton_3->hide();
    ui->pushButton_7->hide();
    model->select();
}


void SecondPage::on_pushButton_7_clicked()
{
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->name->hide();
    ui->band->hide();
    ui->song->hide();
    ui->pushButton_3->hide();
    ui->pushButton_7->hide();
}


