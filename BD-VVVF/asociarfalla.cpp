#include "asociarfalla.h"
#include "ui_asociarfalla.h"

#include <QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include<QDebug>

//constructor del formulario
asociarFalla::asociarFalla(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::asociarFalla)
{
    ui->setupUi(this);

    //Inicializando widgets
    ui->comboBox_2DRIVERS_BCH->addItem("0");
    ui->comboBox_2DRIVERS_BCH->addItem("1");
    ui->comboBox_2DRIVERS_BCH->addItem("2");
    ui->comboBox_2DRIVERS_BCH->setCurrentIndex(0);

    ui->comboBox_3DRIVERS_PW->addItem("0");
    ui->comboBox_3DRIVERS_PW->addItem("1");
    ui->comboBox_3DRIVERS_PW->addItem("2");
    ui->comboBox_3DRIVERS_PW->addItem("3");
    ui->comboBox_3DRIVERS_PW->setCurrentIndex(0);

    ui->dateEditBCH->setDate(QDate::currentDate());
    ui->dateEdit_2PW->setDate(QDate::currentDate());

    ui->spinBoxNotaS_BCH->setMinimum(0);
    ui->spinBoxNotaS_BCH->setMaximum(9999);
    ui->spinBox_2NotaS_PW->setMinimum(0);
    ui->spinBox_2NotaS_PW->setMaximum(9999);

    //carga ComboBox por fallas faltantes

    CargarEventosSinFallas();
}

asociarFalla::~asociarFalla()
{
    delete ui;

}

void asociarFalla::on_pushButton_2_clicked()
{
    reject();
}

void asociarFalla::CargarEventosSinFallas(){

    ui->comboBoxEventoPendientes->clear();
    ui->comboBoxEventoPendientes->addItem("Seleccione un evento", -1);

    QSqlQuery query;

   QString consulta= "SELECT e.id, e.fecha_evento, e.formacion, e.coche, e.ramal, e.tipo_evento "
                         "FROM eventos e "
                         "WHERE e.id NOT IN (SELECT evento_id FROM FALLA_BCH) "
                         "AND e.id NOT IN (SELECT evento_id FROM FALLA_PW) "
                         "ORDER BY e.fecha_evento DESC, e.id DESC ";

    qDebug()<<"Ejecutando consulta:" <<consulta;

    if(query.exec(consulta)){
        int count=0;
        while(query.next()){

            int id = query.value(0).toInt();
            QString fecha= query.value(1).toString();
            QString formacion= query.value(2).toString();
            QString coche= query.value(3).toString();
            QString ramal= query.value(4).toString();
            QString tipoEvento= query.value(5).toString();

            //texto descriptivo combobox
            QString displayText= QString("ID: %1 | %2 | %3 | %4 | %5 | %6 " )
            .arg(id)
            .arg(fecha)
            .arg(formacion)
            .arg(coche)
            .arg(ramal)
            .arg(tipoEvento);

            ui->comboBoxEventoPendientes->addItem(displayText, id);
            count++;
        }
        qDebug() << "Cargados" << (ui->comboBoxEventoPendientes->count() -1) << "eventos sin fallas asociadas";
        if(count==0){
            QMessageBox::information(this, "Información","No hay eventos de carga de fallas");
        }
    }else{
        qDebug()<< "Error cargando eventos" << query.lastError().text();
    }

}


void asociarFalla::on_comboBoxEventoPendientes_currentIndexChanged(int index)
{
    // if(index <=0){
    //     limpiarFormularios();
    //     return;
    // }
}

