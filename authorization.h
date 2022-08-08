#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "mainwindow.h"
#include "client.h"
#include "database.h"
#include <QWidget>

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Authorization *ui;
    MainWindow Main;
    client client;
};

#endif
