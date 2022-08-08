#ifndef CLIENT_H
#define CLIENT_H
#include "mainwindow.h"
#include "database.h"
#include <QWidget>

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    void ShowTables();
private slots:

    void on_pushButton_Admin_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::client *ui;
    MainWindow Main;
};

#endif
