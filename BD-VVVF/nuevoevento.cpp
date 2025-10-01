#include "nuevoevento.h"
#include "ui_nuevoevento.h"

//gilada
#include "databasehandler.h"
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

    ui->spinBoxNS->setMinimum(1);
    ui->spinBoxNS->setMaximum(9999);

}

NuevoEvento::~NuevoEvento()
{
    delete ui;
}
