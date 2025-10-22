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

    ui->comboBoxTipoEvento->addItem("FALLA");
    ui->comboBoxTipoEvento->addItem("INTERVENCION");
    ui->comboBoxTipoEvento->addItem("REPARACION_PENDIENTE");

    ui->comboBoxTipoEvento->setCurrentIndex(0);

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

}

void NuevoEvento::guardar_registro(){
    //validacion
    if(ui->comboBoxFormacion->currentText().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Debe seleccionar una formación");
        ui->comboBoxFormacion->setFocus();
        return;
    }//validacion formacion

    if(ui->comboBoxCoche->currentText().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Debe seleccionar un coche");
        ui->comboBoxCoche->setFocus();
        return;
    }//validacion coche

    if(ui->comboBoxGalpon->currentText().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Debe seleccionar un taller");
        ui->comboBoxGalpon->setFocus();
        return;
    }//validacion taller


    // Mostrar valores antes de insertar (para depuración)
    qDebug() << "Valores a insertar:";
    qDebug() << "Fecha:" << ui->dateEdit->date().toString("yyyy-MM-dd");
    qDebug() << "Formación:" << ui->comboBoxFormacion->currentText();
    qDebug() << "Coche:" << ui->comboBoxCoche->currentText();
    qDebug() << "Ramal:" << ui->comboBoxGalpon->currentText();
    qDebug() << "Tipo Evento:" << ui->comboBoxTipoEvento->currentText();

    // Verificar que el tipo de evento sea válido
    QString tipoEvento = ui->comboBoxTipoEvento->currentText();
    if (tipoEvento != "FALLA" && tipoEvento != "INTERVENCION" && tipoEvento != "REPARACION_PENDIENTE") {
        QMessageBox::warning(this, "Error", "Tipo de evento no válido");
        return;
    }

    // ✅ INICIAR TRANSACCIÓN AL PRINCIPIO
    if (!QSqlDatabase::database().transaction()) {
        qDebug() << "❌ Error al iniciar transacción:" << QSqlDatabase::database().lastError().text();
        QMessageBox::critical(this, "Error", "No se pudo iniciar la transacción con la base de datos");
        return;
    }

    //QSqlDatabase::database().transaction();

    //nuevo registro en la tabla
    QSqlQuery query;
    query.prepare("INSERT INTO eventos (fecha_evento, formacion, coche, ramal, tipo_evento) "
                  "VALUES (?, ?, ?, ?, ?)");

    // 🎯 ASIGNAR VALORES A LOS PARÁMETROS
    query.addBindValue(ui->dateEdit->date().toString("yyyy-MM-dd"));  // Fecha como YYYY-MM-DD
    query.addBindValue(ui->comboBoxFormacion->currentText());             // Formación seleccionada
    query.addBindValue(ui->comboBoxCoche->currentText());                 // Coche seleccionado
    query.addBindValue(ui->comboBoxGalpon->currentText());                 // Ramal seleccionado
    query.addBindValue(ui->comboBoxTipoEvento->currentText());            // Tipo de evento seleccionado

    // 🎯 EJECUTAR LA INSERCIÓN
    if (query.exec()) {
        QMessageBox::information(this, "Éxito", "Evento registrado correctamente");
        qDebug() << "Evento insertado - ID:" << query.lastInsertId().toString();
        qDebug() << "Número de filas afectadas:" << query.numRowsAffected();

        // ✅ FORZAR COMMIT MANUALMENTE
        QSqlDatabase::database().commit();
        qDebug() << "Commit ejecutado";

        if (QSqlDatabase::database().commit()) {
            qDebug() << "✅ Evento insertado - ID:" << query.lastInsertId().toString();

            // ✅ VERIFICAR INMEDIATAMENTE que el registro existe
            QSqlQuery verifyQuery;
            verifyQuery.prepare("SELECT COUNT(*) FROM eventos WHERE id = ?");
            verifyQuery.addBindValue(query.lastInsertId());

            if (verifyQuery.exec() && verifyQuery.next()) {
                int count = verifyQuery.value(0).toInt();
                qDebug() << "🔍 Verificación - Registros con ID" << query.lastInsertId() << ":" << count;

                if (count > 0) {
                    qDebug() << "✅ Registro confirmado en la base de datos";
                            } else {
                    qDebug() << "❌ Registro NO encontrado en la base de datos - PROBLEMA DE PERSISTENCIA";
                                     }
            }
        }

        //señal de refresh
        qDebug() << "🔊 Emitiendo señal eventoAgregado()";
        emit eventoAgregado();
        qDebug() << "🔊 Señal emitida";

        // ... código de inserción ...


        accept();
    } else {
        QString error = query.lastError().text();
        qDebug() << "❌ Error al insertar evento:" << error;
        QMessageBox::critical(this, "Error", "No se pudo registrar el evento:\n" + error);
    }



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

