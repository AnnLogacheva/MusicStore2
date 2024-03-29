#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QDialog>
#include <QModelIndex>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class SecondPage;
}

class SecondPage : public QDialog
{
    Q_OBJECT

public:
    explicit SecondPage(QWidget *parent = nullptr);
    ~SecondPage();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::SecondPage *ui;
    QSqlDatabase db;
    QSqlQuery *query;

    QSqlTableModel *model;
};

#endif // SECONDPAGE_H
