#include "gui.h"
#include "ui_gui.h"
#include <QDebug>
#include <QLocale>


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


void GUI::on_Add_pushButton_clicked()
{

}

