#include <QtGui>
#include "QList"
#include "pole.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Pole::Pole(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    //pre_size=0;
}

void Pole::on_pushButton_clicked()
{
    QStringList list, list_com;
  //  QModelIndexList mlist = listView->selectionModel()->selectedIndexes();
    QString list_pole,list_pole_com;
    QString tmp_n, tmp_o,tmp_d,tmp_str,tmp_str_n,
            tmp_str_o,tmp_str_u,tmp_if,tmp_if_1,tmp_if_2, sel_com,str_com;
    QSqlQueryModel *model = new QSqlQueryModel();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));
    // установка кириллицы

QModelIndexList mlist1=tableWidget->selectionModel()->selectedIndexes();

for(int i = 0;i < mlist1.count();i+=2){
//Получаем отображаемое имя
list.append(mlist1.at(i).data(Qt::DisplayRole).toString());
}
for(int i = 1;i < mlist1.count();i+=2){
//Получаем комментарии
list_com.append(mlist1.at(i).data(Qt::DisplayRole).toString());
}

for(int i = 0; i < list.count();i++){
//Записываем отображаемое имя
list_pole += list.at(i) + ";";
}
for(int i = 0; i < list_com.count();i++){
//Записываем комментарии
list_pole_com += list_com.at(i) + ";";
}

int sum=0;
// проверка на сущестование --->>
    model->setQuery ("SELECT table_name FROM settings");
    sum=model->rowCount();
    QSqlRecord record;
    flag = 0;
    for(int i = 0; i < sum;i++){
    record = model->record(i);
    if (record.value("table_name").toString() == comboBox->currentText())
    flag = 1;
}
// проверка на сущестование ---<<
    if (flag==0){
    model->setQuery ("INSERT INTO settings (table_name, pole_name) VALUES ('"
                     +comboBox->currentText()
                     +"','"
                     +list_pole
                     +"')");
//comment
    for(int i = 0; i < list.count();i++){
    model->setQuery  ("COMMENT ON COLUMN "
                     +comboBox->currentText() // table
                     +"."
                     +list.at(i) // name of pole
                     +" IS '"
                     +list_com.at(i) // com for pole
                     +"';");
}
    //construct strings for trig fun--->>
    tmp_str = "retstr := retstr || mstr; ";
    sel_com = "tmp=(select description from pg_description "
              "join pg_class on pg_description.objoid = pg_class.oid "
              "where relname = '"
              +comboBox->currentText()
              +"' and objsubid = ";
    str_com = "retstr := retstr || tmp; retstr := retstr || ' ';";

    if (list.count()>0){
        for(int i = 0;i < list.count();i++){
        int ind=i*2;
        QString ii=QString::number(i);
        tmp_d = tmp_d
                +" astr_"
                +ii
                +" varchar(100);"
                +" astr_o_"
                +ii
                +" varchar(100);";
        tmp_n = tmp_n
                +" astr_"
                +ii
                +"= NEW."+list.at(i)+";";
        tmp_o = tmp_o
                +" astr_o_"
                +ii
                +"= OLD."+list.at(i)+";";
        tmp_if_1 = " if NEW."
                   +list.at(i)+
                   +" is not null then ";
        tmp_str_n = tmp_str_n + tmp_if_1+ tmp_str + sel_com + QString::number((mlist1.at(ind).row()+1))
                    + ");  if tmp is not null then "
                    + str_com
                    + " end if; retstr := retstr || astr_"
                    + ii
                    + "; end if;";
        tmp_if_2 = " if OLD."
                   +list.at(i)+
                   +" is not null then ";
        tmp_str_o = tmp_str_o + tmp_if_2+ tmp_str + sel_com + QString::number((mlist1.at(ind).row()+1))
                    + ");  if tmp is not null then "
                    + str_com
                    + " end if; retstr := retstr || astr_o_"
                    + ii
                    + "; end if;";
        tmp_if = "if (astr_"
                 +ii
                 +"<>"
                 +"astr_o_"
                 +ii
                 +") then ";
        tmp_str_u = tmp_str_u + tmp_if + tmp_str + sel_com + QString::number((mlist1.at(ind).row()+1))
                    + ");  if tmp is not null then "
                    + str_com
                    + " end if; retstr := retstr || '"+tr("с ")+"';"
                    + " retstr := retstr || astr_o_"
                    + ii
                    + ";"
                    + " retstr := retstr || '"+tr(" на ")+"';"
                    + " retstr := retstr || astr_"
                    + ii
                    + ";"
                    + "end if;";
        }
    }
    //construct strings for trig fun---<<
    //generete trig fun & trig--->>

   model->setQuery
       //   qDebug() <<
             (
             "CREATE OR REPLACE FUNCTION add_to_log_"
             //+QString::number(sum+1)
             +comboBox->currentText()
             +"() RETURNS TRIGGER AS $$ "
             "DECLARE "
             "mstr varchar(30);"
             +tmp_d
             +"tmp varchar(30);"
             "retstr varchar(254);"
             " BEGIN "
             " IF TG_OP = 'INSERT' THEN "             
             +tmp_n
             +"mstr := '"+tr(" Добавление нового: ")+"';"
             "retstr := ' ';"
             +tmp_str_n
             +"INSERT INTO logs(text,added) values (retstr,NOW());"
             "RETURN NEW;"
             "ELSIF TG_OP = 'UPDATE' THEN "
             +tmp_n
             +tmp_o
             +"mstr := '"+tr(" Изменение: ")+"';"
             "retstr := ' ';"
             +tmp_str_u
             +"INSERT INTO logs(text,added) values (retstr,NOW());"
             " RETURN NEW;"
             "ELSIF TG_OP = 'DELETE' THEN "
             +tmp_o
             +"mstr := '"+tr(" Удаление: ")+"';"
             "retstr := ' ';"
             +tmp_str_o
             +"INSERT INTO logs(text,added) values (retstr,NOW());"
             "RETURN OLD;"
             "END IF;"
             "END;"
             "$$ LANGUAGE plpgsql;");

    model->setQuery (
            "CREATE TRIGGER log "
            "AFTER INSERT OR UPDATE OR DELETE ON "
            +comboBox->currentText()
            +" FOR EACH ROW EXECUTE PROCEDURE add_to_log_"
            +comboBox->currentText()
            +"();");
    //generete trig fun & trig---<<
} else QMessageBox::critical(0, "Error", tr("Создание триггера невозможно! Триггер для выбранной таблицы уже существует. Для доавления необходимо удаление"));

}

void Pole::on_comboBox_currentIndexChanged(QString )
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT attname FROM pg_attribute, pg_type WHERE typname = '"
                    +comboBox->currentText()
                    +"' AND attrelid = typrelid AND attname NOT IN ('cmin', 'cmax', 'ctid', 'oid', 'tableoid', 'xmin', 'xmax')");

    tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));

    QTableWidgetItem *item_h_1 = new QTableWidgetItem;
    item_h_1->setText(tr("Выбор полей:"));
    tableWidget->setHorizontalHeaderItem(0, item_h_1);
    QTableWidgetItem *item_h_2 = new QTableWidgetItem;
    item_h_2->setText(tr("Комментарии:"));
    tableWidget->setHorizontalHeaderItem(1, item_h_2);

    tableWidget->setRowCount(model->rowCount());

    for(int i = 0;i < model->rowCount();i++){
    QTableWidgetItem *item = new QTableWidgetItem;
    QString name = model->record(i).value("attname").toString();
    item->setText(name);
    item->setFlags(item->flags() &= ~Qt::ItemIsEditable);
    tableWidget->setItem(i,0,item);
}
    tableWidget->verticalHeader()->hide();
    Pole::setMinimumHeight(25 * model->rowCount() + 130);
}

void  Pole::closeEvent( QCloseEvent * )
{}

void Pole::on_tableWidget_clicked(QModelIndex index)
{}
