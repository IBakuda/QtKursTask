#include "authorization.h"
#include "ui_authorization.h"
#include "database.h"

Authorization::Authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
}

Authorization::~Authorization()
{
    delete ui;
}


void Authorization::on_pushButton_clicked()
{
    QString Authorization = ui->lineEdit->text();
    QString Pass = ui->lineEdit_2->text();
    DBConnect.Authorization(Authorization,Pass);
    if(DBConnect.isOk())
    {
        this->close();
        client.show();
    }
}
