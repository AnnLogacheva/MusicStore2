#include "thirdpage.h"
#include "ui_thirdpage.h"

ThirdPage::ThirdPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdPage)
{
    ui->setupUi(this);
}

ThirdPage::~ThirdPage()
{
    delete ui;
}

void ThirdPage::on_pushButton_5_clicked()
{

    static Qt::SortOrder order = Qt::AscendingOrder;
     ui->list->sortItems(order);
     if (order == Qt::AscendingOrder) order = Qt::DescendingOrder;
     else order = Qt::AscendingOrder;
}


void ThirdPage::on_pushButton_clicked()
{
    hide();
}

