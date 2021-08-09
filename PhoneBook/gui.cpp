#include "gui.h"
#include "ui_gui.h"
#include "menu.h"
#include <QDebug>
#include <QMessageBox>


GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);
}

GUI::~GUI()
{
    delete ui;
}


void GUI::on_login_pushButton_clicked()
{
    QString username = ui->username_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    if (username == QString("test")  && password == QString("test"))
    {
        QMessageBox::information(this, "Login", "Username and password is correct!");
        Menu menu;
        menu.setModal(true);
        menu.exec();
    }
    else
    {
        QMessageBox::information(this, "Login", "Username and password is incorrect!");
    }
}



