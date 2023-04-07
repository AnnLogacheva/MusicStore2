#include "thirdpage.h"
#include "ui_thirdpage.h"
#include "secondpage.h"


ThirdPage::ThirdPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdPage)
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
}

ThirdPage::~ThirdPage()
{
    delete ui;
}


void ThirdPage::on_pushButton_clicked()
{
    close();
}

