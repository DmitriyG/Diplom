#include <QtGui>
#include "pole.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Pole::Pole(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}

void Pole::on_pushButton_clicked()
{
    QStringList list;
    QModelIndexList mlist = listView->selectionModel()->selectedIndexes();
    QString list_pole;
    QString tmp_n, tmp_o,tmp_d,tmp_str,tmp_str_n,tmp_str_o,tmp_str_u,tmp_if,tmp_if_1,tmp_if_2;
    QSqlQueryModel *model = new QSqlQueryModel();

    for(int i = 0;i < mlist.count();i++){
    //Получаем отображаемое имя
    list.append(mlist.at(i).data(Qt::DisplayRole).toString());
    }

    for(int i = 0; i < list.count();i++){
    //Записываем отображаемое имя
    list_pole += list.at(i) + ";";
    }

    model->setQuery ("INSERT INTO settings (table_name, pole_name) VALUES ('"
                     +comboBox->currentText()
                     +"','"
                     +list_pole
                     +"')");
    //construct strings for trig fun--->>
    tmp_str= "retstr := retstr || mstr";
    if (list.count()>0){
        for(int i = 0;i < list.count();i++){
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
        tmp_str_n = tmp_str_n + tmp_if_1+ tmp_str +";"+ " retstr := retstr || astr_"
                    + ii
                    + "; end if;";
        tmp_if_2 = " if OLD."
                   +list.at(i)+
                   +" is not null then ";
        tmp_str_o = tmp_str_o +tmp_if_2+ tmp_str +";"+ " retstr := retstr || astr_o_"
                    + ii
                    + "; end if;";
        tmp_if = "if (astr_"
                 +ii
                 +"<>"
                 +"astr_o_"
                 +ii
                 +") then ";
        tmp_str_u = tmp_str_u + tmp_if + tmp_str
                    + ";"
                    + " retstr := retstr || astr_"
                    + ii
                    + ";"
                    + " retstr := retstr || ' from ';"
                    + " retstr := retstr || astr_o_"
                    + ii
                    + ";"
                    + "end if;";
        }
    }
    //construct strings for trig fun---<<
    //generete trig fun & trig--->>
    model->setQuery(
           // qDebug() <<(
             "CREATE OR REPLACE FUNCTION add_to_log() RETURNS TRIGGER AS $$ "
             "DECLARE "
             "mstr varchar(30);"
             +tmp_d
             +"tab text;"
             "retstr varchar(254);"
             " BEGIN "
             " IF TG_OP = 'INSERT' THEN "
             "tab='';"
             +tmp_n
             +"mstr := ' Add new ';"
             "retstr := ' ';"
             +tmp_str_n
             +"INSERT INTO logs(text,added) values (retstr,NOW());"
             "RETURN NEW;"
             "ELSIF TG_OP = 'UPDATE' THEN "
             +tmp_n
             +tmp_o
             +"mstr := ' Update to ';"
             "retstr := ' ';"
             +tmp_str_u
             +"INSERT INTO logs(text,added) values (retstr,NOW());"
             " RETURN NEW;"
             "ELSIF TG_OP = 'DELETE' THEN "
             +tmp_o
             +"mstr := ' Remove ';"
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
            +" FOR EACH ROW EXECUTE PROCEDURE add_to_log();");
    //generete trig fun & trig---<<
}

void Pole::on_comboBox_currentIndexChanged(QString )
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT attname FROM pg_attribute, pg_type WHERE typname = '"
                    +comboBox->currentText()
                    +"' AND attrelid = typrelid AND attname NOT IN ('cmin', 'cmax', 'ctid', 'oid', 'tableoid', 'xmin', 'xmax')");
    listView->setModel(model);
}
