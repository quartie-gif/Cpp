#pragma once

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_add_pushButton_clicked();

    void on_remove_pushButton_clicked();

    void on_moreInfo_pushButton_clicked();

    void on_singOut_pushButton_clicked();

    void getData(QString person);

private:
    Ui::Menu *ui;
};
