#pragma once

#include <QMainWindow>
#include "PersonData.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();

private slots:
    void on_Add_pushButton_clicked();

private:
    Ui::GUI *ui;
    std::vector<Person> m_person;
};
