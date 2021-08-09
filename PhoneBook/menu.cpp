#include "menu.h"
#include "ui_menu.h"
#include "dialog.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);


}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_add_pushButton_clicked()
{
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
}


void Menu::on_remove_pushButton_clicked()
{

}


void Menu::on_moreInfo_pushButton_clicked()
{

}


void Menu::on_singOut_pushButton_clicked()
{
    exit(true);
}


void Menu::getData(QString person)
{
    ui->listWidget->addItem(person);
}
