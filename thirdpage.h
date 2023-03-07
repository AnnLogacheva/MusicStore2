#ifndef THIRDPAGE_H
#define THIRDPAGE_H

#include <QDialog>

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
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::ThirdPage *ui;
};

#endif // THIRDPAGE_H
