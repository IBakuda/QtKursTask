#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}



client::~client()
{
    delete ui;
}



//Кнопка доступа к окну администратора с проверкой на СуперПользователя
void client::on_pushButton_Admin_clicked()
{
    ui->tableView_Model->setModel(DBConnect.SetQuery("SET lc_monetary TO \"en_US.UTF-8\""));
    QSqlQuery query = DBConnect.Query("SELECT rolsuper FROM pg_roles WHERE rolname = CURRENT_USER");
    query.next();
    if(query.value(0) == true)
    {
        this->close();
        Main.show();
    }
    else
        QMessageBox::information(this,"Ошибка","Недостаточно прав, обратитесь к администратору");

}

void client::on_pushButton_clicked()
{
    ui->tableView_Model->setModel(DBConnect.SetQuery("Select last_name as \"Фамилия\", first_name as \"Имя\", middle_name as \"Отчество\" from poselenie"));
}

void client::on_pushButton_2_clicked()
{
    ui->tableView_Model->setModel(DBConnect.SetQuery("select storey as \"Этаж\", room as \"Номер\", stoimost as \"Стоимость\" from rasmeshenie"));
}

void client::on_pushButton_3_clicked()
{
    ui->tableView_Model->setModel(DBConnect.SetQuery("Select number_of_persons as \"Количество людей\", contact_number as \"Контактный телефон\", id_p as \"номер заказа\" from vipiska"));
}

void client::on_pushButton_4_clicked()
{
    ui->tableView_Model->setModel(DBConnect.SetQuery("select  price as \"Оплачено\", data_opl as \"Дата оплаты\", data_los as \"Дата истечения оплаты\", payment_method as \"Способ оплаты\" from oplata"));
}
