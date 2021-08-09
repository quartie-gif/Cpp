#pragma once

#include <QMainWindow>
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

    void on_login_pushButton_clicked();

private:
    Ui::GUI *ui;
};
