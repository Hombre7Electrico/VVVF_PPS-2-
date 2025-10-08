#include "nuevoevento.h"
#include "ui_nuevoevento.h"

//gilada
#include "databasehandler.h" //para acceder a la base de datos
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

NuevoEvento::NuevoEvento(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NuevoEvento)
{
    ui->setupUi(this);

    //configuración de combobox y giladas
    ui->dateEdit->setDate(QDate::currentDate());

    ui->comboBoxGalpon->addItem("Suarez");
    ui->comboBoxGalpon->addItem("Victoria");

    ui->comboBoxTipoEvento->addItem("Falla");
    ui->comboBoxTipoEvento->addItem("Reparación Pendiente");
    ui->comboBoxTipoEvento->addItem("Preventivo");

    ui->comboBoxFormacion->addItem("M01");
    ui->comboBoxFormacion->addItem("M02");
    ui->comboBoxFormacion->addItem("M03");
    ui->comboBoxFormacion->addItem("M04");
    ui->comboBoxFormacion->addItem("M05");
    ui->comboBoxFormacion->addItem("M06");
    ui->comboBoxFormacion->addItem("M07");
    ui->comboBoxFormacion->addItem("M08");
    ui->comboBoxFormacion->addItem("M09");
    ui->comboBoxFormacion->addItem("M10");
    ui->comboBoxFormacion->addItem("M11");
    ui->comboBoxFormacion->addItem("M12");
    ui->comboBoxFormacion->addItem("M13");
    ui->comboBoxFormacion->addItem("M14");
    ui->comboBoxFormacion->addItem("M15");
    ui->comboBoxFormacion->addItem("M16");
    ui->comboBoxFormacion->addItem("M17");
    ui->comboBoxFormacion->addItem("M18");
    ui->comboBoxFormacion->addItem("M19");
    ui->comboBoxFormacion->addItem("M20");
    ui->comboBoxFormacion->addItem("M21");
    ui->comboBoxFormacion->addItem("M22");
    ui->comboBoxFormacion->addItem("M23");
    ui->comboBoxFormacion->addItem("M24");
    ui->comboBoxFormacion->addItem("M25");
    ui->comboBoxFormacion->addItem("M26");
    ui->comboBoxFormacion->addItem("M27");
    ui->comboBoxFormacion->addItem("M28");
    ui->comboBoxFormacion->addItem("M29");
    ui->comboBoxFormacion->addItem("M30");

    ui->comboBoxCoche->addItem("M1");
    ui->comboBoxCoche->addItem("M2");
    ui->comboBoxCoche->addItem("M3");
    ui->comboBoxCoche->addItem("M4");



    ui->spinBoxNS->setMinimum(1);
    ui->spinBoxNS->setMaximum(99999);


}

void NuevoEvento::guardar_registro(){
    //validacion
    if(ui->comboBoxTipoEvento->currentText()=="Falla" || ui->comboBoxTipoEvento->currentText()=="Preventivo"){
        if(ui->comboBoxFormacion->currentText().isEmpty()){
            QMessageBox::warning(this,"Error","Debe completar el campo Formación");
            ui->comboBoxFormacion->setFocus();
            return;
        }//formacion

        if(ui->comboBoxCoche->currentText().isEmpty()){
            QMessageBox::warning(this,"Error","Debe completar el campo Formación");
            ui->comboBoxCoche->setFocus();
            return;
        }//coche

/*        // if(ui->comboBoxGalpon->currentText().isEmpty()){
        //     QMessageBox::warning(this,"Error","Debe completar el campo Formación");
        //     ui->comboBoxGalpon->setFocus();
        //     return;

        }*///Galpon

        //registro
        QSqlQuery query;
        query.prepare("INSERT INTO eventos (fecha_evento, formacion, coche, ramal, tipo_evento)"
                      "VALUES (?, ?, ?, ?, ?)");
        query.addBindValue(ui->dateEdit->date().toString("yyyy-MM-dd"));
        query.addBindValue(ui->comboBoxFormacion->currentText());
        query.addBindValue(ui->comboBoxCoche->currentText());
        query.addBindValue(ui->comboBoxGalpon->currentText());
        query.addBindValue(ui->comboBoxTipoEvento->currentText());

        if(query.exec()){
            QMessageBox::information(this,"Éxito","Evento agregado correctamente");
            accept();
        } else{
            QMessageBox::critical(this,"Error","Error: "+ query.lastError().text());
        }//query exec()

    }//validacion por tipo de falla
}//guardar registro

void NuevoEvento::cancelar(){

    reject();

}

NuevoEvento::~NuevoEvento()
{
    delete ui;
}



void NuevoEvento::on_pushButtonOK_clicked()
{
    guardar_registro();
}


void NuevoEvento::on_pushButtonNO_clicked()
{
    cancelar();
}

