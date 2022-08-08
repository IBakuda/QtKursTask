#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("SELECT last_name as \"Фамилия\",first_name as \"Имя\", middle_name as \"Отчество\", price as \"Оплатил\", CASE price WHEN (SELECT max(price) FROM poselenie INNER JOIN oplata ON poselenie.id_poselenie = oplata.id_oplata) THEN 'Самый дорогой' WHEN (SELECT min(price) FROM poselenie INNER JOIN oplata ON poselenie.id_poselenie = oplata.id_oplata) THEN 'Самый дешевый' Else 'Средняя цена' END Соотношение_цен FROM oplata INNER JOIN poselenie ON oplata.id_oplata = poselenie.id_poselenie"));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("SELECT * FROM View_poselenie"));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("SELECT r.room AS \"Номер комнаты\", (SELECT last_name from poselenie po where po.id_poselenie = r.id_rasmeshenie) AS \"Фамилия\", (SELECT first_name from poselenie po where po.id_poselenie = r.id_rasmeshenie) AS \"Имя\", (SELECT middle_name from poselenie po where po.id_poselenie = r.id_rasmeshenie) AS \"Отчество\", o.price as \"Сколько заплатил клиент\" FROM (SELECT * FROM rasmeshenie )r, oplata o WHERE o.price IN (SELECT price  FROM oplata WHERE payment_method ='bank card' ) AND(r.id_rasmeshenie = o.id_oplata)"));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("select po.last_name as \"Фамилия\", po.first_name as \"Имя\", po.middle_name as \"Отчество\", Max(op.price) as \"Цена\", r.storey as \"Этаж\", r.room as \"Номер\" from poselenie po, oplata op, rasmeshenie r where po.id_poselenie = op.id_oplata Group by po.last_name, po.first_name, po.middle_name, op.price, r.storey, r.room, r.id_rasmeshenie, op.id_oplata Having Max(op.price) > '2000' and r.id_rasmeshenie = op.id_oplata"));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("Select r.storey as \"Этаж\", r.room as \"Номер\", r.stoimost as \"Цена\" from rasmeshenie r where r.stoimost = any(Select stoimost from rasmeshenie where stoimost  <= '2000')"));
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("SELECT vstorey('3') as\"Номера\""));
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("Select sroom('31') as \"Цена 31-го номера\""));
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery ID = DBConnect.Query(QString("Select id_poselenie from poselenie where last_name = '%1'").arg(ui->comboBox->currentText()));
    ID.next();
    DBConnect.Query(QString("call delete_lines(%1)").arg(ID.value(0).toString()));
    on_pushButton_11_clicked();
}

void MainWindow::on_pushButton_9_clicked()
{
    Edit.show();
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->tableView->setModel(DBConnect.SetQuery("Select event_mess as \"Событие\" from trigger_list as \"Тригер лист\""));
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->comboBox->clear();
    ui->comboBox->setModel(DBConnect.SetQuery("Select last_name, first_name, middle_name from poselenie"));
}



