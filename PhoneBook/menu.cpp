#include "menu.h"
#include "ui_menu.h"
#include "dialog.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("/Users/apple/Desktop/people.db");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("select * from people");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    m_db.close();

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_add_pushButton_clicked()
{
    Dialog dialog;
    dialog.getData(m_db);
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

}
