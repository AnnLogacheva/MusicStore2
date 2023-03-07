#include "secondpage.h"
#include "ui_secondpage.h"
#include <QMessageBox>

SecondPage::SecondPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondPage)
{
    ui->setupUi(this);
}

SecondPage::~SecondPage()
{
    delete ui;
}
//exit
void SecondPage::on_pushButton_clicked()
{
    hide();
}


void SecondPage::on_pushButton_2_clicked()
{
    QString pass =ui->find->text();

}

//clear
void SecondPage::on_pushButton_3_clicked()
{
    ui->list->clear();
}

//Add
void SecondPage::on_pushButton_4_clicked()
{
    QString word =ui->find->text();
    if(word=="" or word==" "){
        QMessageBox::information(this,tr("Ошибка"),tr("Пустая строка"));
        return;
    }
    QListWidgetItem *item2 = new QListWidgetItem;
    item2->setText(word);
    ui->list->addItem(item2);

}

//sort
void SecondPage::on_pushButton_5_clicked()
{
    static Qt::SortOrder order = Qt::AscendingOrder;
     ui->list->sortItems(order);
     if (order == Qt::AscendingOrder) order = Qt::DescendingOrder;
     else order = Qt::AscendingOrder;
}

//delete
void SecondPage::on_pushButton_6_clicked()
{
    QListWidgetItem *item = ui->list->item(ui->list->currentRow());
     if (!item) {
      QMessageBox::information(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
      return;
     }
     ui->list->takeItem (ui->list->currentRow());
}

