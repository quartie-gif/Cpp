#pragma once

#include <QDialog>
#include <PersonData.h>
#include <QLocale>
#include <vector>
#include <fstream>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QSqlQuery>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
     void updateFile() const;

     void getData(QSqlDatabase data);


private slots:
     void on_Add_pushButton_clicked();

private:
    Ui::Dialog *ui;
    std::vector<Person> m_persons;
    QSqlDatabase db;

};

