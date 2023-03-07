#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QDialog>

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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::SecondPage *ui;
};

#endif // SECONDPAGE_H
