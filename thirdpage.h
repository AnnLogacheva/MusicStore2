#ifndef THIRDPAGE_H
#define THIRDPAGE_H

#include <QDialog>
#include "secondpage.h"

namespace Ui {
class ThirdPage;
}

class ThirdPage : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdPage(QWidget *parent = nullptr);
    ~ThirdPage();

private slots:

    void on_pushButton_clicked();

private:
    Ui::ThirdPage *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // THIRDPAGE_H
