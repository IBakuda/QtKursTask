#include "edit.h"
#include "ui_edit.h"
#include "database.h"

Edit::Edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);

}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_pushButton_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("Select last_name as \"Фамилия\", first_name as \"Имя\", middle_name as \"Отчество\" from poselenie"));
}

void Edit::on_pushButton_2_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("select storey as \"Этаж\", room as \"Номер\", stoimost as \"Стоимость\" from rasmeshenie"));
}

void Edit::on_pushButton_3_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("Select number_of_persons as \"Количество людей\", contact_number as \"Контактный телефон\", id_p as \"номер заказа\" from vipiska"));
}

void Edit::on_pushButton_4_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("select  price as \"Оплачено\", data_opl as \"Дата оплаты\", data_los as \"Дата истечения оплаты\", payment_method as \"Способ оплаты\" from oplata"));
}

void Edit::on_pushButton_5_clicked()//добавление poselenie
{
    ui->tableView->setModel(DBConnect.SetQuery(QString("call insert_poselenie('%1','%2','%3')")
                                               .arg(ui->lineEdit->text())
                                               .arg(ui->lineEdit_2->text())
                                               .arg(ui->lineEdit_3->text())));
}

void Edit::on_pushButton_6_clicked()//добавление rasmeshenie
{
    ui->tableView->setModel(DBConnect.SetQuery(QString("call insert_rasmeshenie('%1','%2','%3')")
                                               .arg(ui->comboBox->currentText())
                                               .arg(ui->lineEdit_4->text())
                                               .arg(ui->lineEdit_6->text())));
}

void Edit::on_pushButton_8_clicked()//добавление vipiska
{
    ui->tableView->setModel(DBConnect.SetQuery(QString("call insert_vipiska('%1','%2','%3','%3','%3')")
                                               .arg(ui->lineEdit_5->text())
                                               .arg(ui->lineEdit_7->text())
                                               .arg(ui->lineEdit_8->text())));
}

void Edit::on_pushButton_7_clicked()//добавление oplata
{
    ui->tableView->setModel(DBConnect.SetQuery(QString("call insert_oplata('%1','%2','%3','%4')")
                                              .arg(ui->lineEdit_9->text())
                                              .arg(ui->lineEdit_10->text())
                                              .arg(ui->lineEdit_11->text())
                                              .arg(ui->lineEdit_12->text())));
}

void Edit::on_pushButton_13_clicked()//изменение poselenie
{
    QSqlQuery sql = DBConnect.Query(QString("Select id_poselenie from poselenie where last_name = '%1'").arg(ui->comboBox_9->currentText()));
    sql.next();
    ui->tableView->setModel(DBConnect.SetQuery(QString("call update_poselenie(%1,'%2','%3','%4')")
                                               .arg(sql.value(0).toString())
                                               .arg(ui->lineEdit_13->text())
                                               .arg(ui->lineEdit_21->text())
                                               .arg(ui->lineEdit_22->text())));
}

void Edit::on_pushButton_14_clicked()//изменение rasmeshenie
{
    QSqlQuery sql = DBConnect.Query(QString("Select id_rasmeshenie from rasmeshenie where room = '%1'").arg(ui->comboBox_2->currentText()));
    sql.next();
    ui->tableView->setModel(DBConnect.SetQuery(QString("call update_rasmeshenie(%1, '%2', '%3', '%4')")
                                               .arg(sql.value(0).toString())
                                               .arg(ui->lineEdit_17->text())
                                               .arg(ui->comboBox_2->currentText())
                                               .arg(ui->lineEdit_23->text())));
}

void Edit::on_pushButton_15_clicked()//изменение vipiska
{
    QSqlQuery sql = DBConnect.Query(QString("Select id_vipiska from vipiska where id_p = '%1'").arg(ui->comboBox_7->currentText()));
    sql.next();
    ui->tableView->setModel(DBConnect.SetQuery(QString("call update_vipiska('%1','%2','%3','%4','%4','%4')")
                                               .arg(sql.value(0).toString())
                                               .arg(ui->lineEdit_14->text())
                                               .arg(ui->lineEdit_15->text())
                                               .arg(ui->comboBox_7->currentText())));
}

void Edit::on_pushButton_16_clicked()//изменение oplata
{
    QSqlQuery sql = DBConnect.Query(QString("Select id_oplata from oplata where data_opl = '%1'").arg(ui->comboBox_8->currentText()));
    sql.next();
    ui->tableView->setModel(DBConnect.SetQuery(QString("call update_oplata(%1,'%2','%3','%4','%5')")
                                               .arg(sql.value(0).toString())
                                               .arg(ui->lineEdit_24->text())
                                               .arg(ui->comboBox_8->currentText())
                                               .arg(ui->lineEdit_16->text())
                                               .arg(ui->lineEdit_27->text())));
}

void Edit::on_pushButton_9_clicked()//удаление poselenie
{
    QSqlQuery ID = DBConnect.Query(QString("Select id_poselenie from poselenie where last_name = '%1'").arg(ui->comboBox_3->currentText()));
    ID.next();
    DBConnect.Query(QString("call delete_poselenie(%1)").arg(ID.value(0).toString()));
}

void Edit::on_pushButton_10_clicked()//удаление vipiska
{
    QSqlQuery ID = DBConnect.Query(QString("Select id_vipiska from vipiska where contact_number = '%1'").arg(ui->comboBox_4->currentText()));
    ID.next();
    DBConnect.Query(QString("call delete_vipiska(%1)").arg(ID.value(0).toString()));
}

void Edit::on_pushButton_11_clicked()//удаление rasmeshenie
{
    QSqlQuery ID = DBConnect.Query(QString("Select id_rasmeshenie from rasmeshenie where room = '%1'").arg(ui->comboBox_5->currentText()));
    ID.next();
    DBConnect.Query(QString("call delete_rasmeshenie(%1)").arg(ID.value(0).toString()));
}

void Edit::on_pushButton_12_clicked()//удаление oplata
{
    QSqlQuery ID = DBConnect.Query(QString("Select id_oplata from oplata where data_opl = '%1'").arg(ui->comboBox_6->currentText()));
    ID.next();
    DBConnect.Query(QString("call delete_oplata(%1)").arg(ID.value(0).toString()));
}

void Edit::on_pushButton_17_clicked()
{
    ui->comboBox->setModel(DBConnect.SetQuery("Select storey from rasmeshenie group by storey"));
    ui->comboBox_2->setModel(DBConnect.SetQuery("Select room from rasmeshenie"));
    ui->comboBox_9->setModel(DBConnect.SetQuery("Select last_name from poselenie"));
    ui->comboBox_7->setModel(DBConnect.SetQuery("Select id_p from vipiska"));
    ui->comboBox_8->setModel(DBConnect.SetQuery("Select data_opl from oplata"));
    ui->comboBox_3->setModel(DBConnect.SetQuery("Select last_name from poselenie"));
    ui->comboBox_5->setModel(DBConnect.SetQuery("Select room from rasmeshenie"));
    ui->comboBox_4->setModel(DBConnect.SetQuery("Select contact_number from vipiska"));
    ui->comboBox_6->setModel(DBConnect.SetQuery("Select data_opl from oplata"));
}
