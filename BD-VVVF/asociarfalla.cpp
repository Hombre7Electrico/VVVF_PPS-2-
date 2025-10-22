#include "asociarfalla.h"
#include "ui_asociarfalla.h"

#include <QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include<QDebug>

//constructor del formulario
asociarFalla::asociarFalla(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::asociarFalla)      //INICIALIZACIÓN VARIABLES
{
    ui->setupUi(this);

    //Inicializando widgets
    ui->comboBox_2DRIVERS_BCH->addItem("Seleccione",-1);
    ui->comboBox_2DRIVERS_BCH->addItem("0", 0);
    ui->comboBox_2DRIVERS_BCH->addItem("1", 1);
    ui->comboBox_2DRIVERS_BCH->addItem("2", 2);

    ui->comboBox_3DRIVERS_PW->addItem("Seleccione",-1);
    ui->comboBox_3DRIVERS_PW->addItem("0",0);
    ui->comboBox_3DRIVERS_PW->addItem("1",1);
    ui->comboBox_3DRIVERS_PW->addItem("2",2);
    ui->comboBox_3DRIVERS_PW->addItem("3",3);

    ui->dateEditBCH->setDate(QDate::currentDate());
    ui->dateEdit_2PW->setDate(QDate::currentDate());

    ui->spinBoxNotaS_BCH->setMinimum(0);
    ui->spinBoxNotaS_BCH->setMaximum(9999);
    ui->spinBox_2NotaS_PW->setMinimum(0);
    ui->spinBox_2NotaS_PW->setMaximum(9999);

    //pestañas de reparaciones
    ui->spinBoxNR_BCH->setMinimum(0);
    ui->spinBoxNR_BCH->setMaximum(9999);
    ui->spinBoxNR_PW->setMinimum(0);
    ui->spinBoxNR_PW->setMaximum(9999);

    //BCH
    ui->comboBoxIGBT_NEW->addItem("Seleccione",-1);
    ui->comboBoxIGBT_NEW->addItem("0",0);
    ui->comboBoxIGBT_NEW->addItem("1",1);
    ui->comboBoxIGBT_NEW->addItem("2",2);

    ui->comboBox_2IGBT_OLD->addItem("Seleccione",-1);
    ui->comboBox_2IGBT_OLD->addItem("0",0);
    ui->comboBox_2IGBT_OLD->addItem("1",1);
    ui->comboBox_2IGBT_OLD->addItem("2",2);

    ui->comboBox_3D_NEW->addItem("Seleccione",-1);
    ui->comboBox_3D_NEW->addItem("0",0);
    ui->comboBox_3D_NEW->addItem("1",1);
    ui->comboBox_3D_NEW->addItem("2",2);

    ui->comboBox_3D_NEW->addItem("Seleccione",-1);
    ui->comboBox_3D_NEW->addItem("0",0);
    ui->comboBox_3D_NEW->addItem("1",1);
    ui->comboBox_3D_NEW->addItem("2",2);

    ui->comboBox_4D_OLD->addItem("Seleccione",-1);
    ui->comboBox_4D_OLD->addItem("0",0);
    ui->comboBox_4D_OLD->addItem("1",1);
    ui->comboBox_4D_OLD->addItem("2",2);

    //carga ComboBox por fallas faltantes

    CargarEventosSinFallas();
    //generarTablaPW();

    ui->tabWidget->setCurrentIndex(0);
}

asociarFalla::~asociarFalla()
{
    delete ui;

}

void asociarFalla::on_pushButton_2_clicked()    //CANCELAR
{
    reject();
}

//COMBOBOX PARA MOSTRAR EVENTOS PENDIENTES DE FALLA O REPARACION
void asociarFalla::CargarEventosSinFallas(){

    ui->comboBoxEventoPendientes->clear();
    ui->comboBoxEventoPendientes->addItem("Seleccione un evento", -1);

    QSqlQuery query;

    QString consulta= "SELECT e.id, e.fecha_evento, e.formacion, e.coche, e.ramal, e.tipo_evento, "
                       "CASE WHEN fb.id IS NULL THEN 'NO' ELSE 'SÍ' END as tiene_BCH, "
                       "CASE WHEN fp.id IS NULL THEN 'NO' ELSE 'SÍ' END as tiene_PW, "
                       //Información de reparaciones
                       "CASE WHEN rb.id IS NULL THEN 'NO' ELSE 'SÍ' END as tiene_rep_BCH, "
                       "CASE WHEN rp.id IS NULL THEN 'NO' ELSE 'SÍ' END as tiene_rep_PW "
                       // === ERROR 1: COMA EXTRA ELIMINADA ===
                       "FROM eventos e "
                       "LEFT JOIN FALLA_BCH fb ON e.id = fb.evento_id "
                       "LEFT JOIN FALLA_PW fp ON e.id = fp.evento_id "
                       //joins tabla de reparacion
                       "LEFT JOIN REPARACION_BCH rb ON fb.id = rb.falla_id "
                       "LEFT JOIN REPARACION_PW rp ON fp.id = rp.falla_id "
                       //
                       // === ERROR 2: CONDICIÓN WHERE CORREGIDA ===
                       "WHERE (fb.id IS NULL OR fp.id IS NULL) OR (fb.id IS NOT NULL AND rb.id IS NULL) OR (fp.id IS NOT NULL AND rp.id IS NULL) "
                       "ORDER BY e.fecha_evento DESC, e.id DESC ";

    qDebug()<<"Ejecutando consulta:" <<consulta;

    if(query.exec(consulta)){
        int count=0;
        while(query.next()){

            int id = query.value(0).toInt();    //dato de la consulta que voy a usar como clave foranea para asociar el evento con la falla
            QString fecha= query.value(1).toString();
            QString formacion= query.value(2).toString();
            QString coche= query.value(3).toString();
            QString ramal= query.value(4).toString();
            QString tipoEvento= query.value(5).toString();
            QString tieneBCH= query.value(6).toString();
            QString tienePW= query.value(7).toString();
            //Info reparaciones
            QString tieneRepBCH = query.value(8).toString();
            QString tieneRepPW = query.value(9).toString();

            //texto descriptivo combobox que ve el usuario
            QString displayText= QString("ID: %1 | %2 | %3 | %4 | %5 | %6 | Fallas: BCH: %7 , PW: %8 | Reparación: BCH: %9 , PW: %10 " )
                                      .arg(id)
                                      .arg(fecha)
                                      .arg(formacion)
                                      .arg(coche)
                                      .arg(ramal)
                                      .arg(tipoEvento)
                                      .arg(tieneBCH)
                                      .arg(tienePW)
                                      .arg(tieneRepBCH)
                                      .arg(tieneRepPW);


            ui->comboBoxEventoPendientes->addItem(displayText, id);
            count++;
        }
        qDebug() << "Cargados" << (ui->comboBoxEventoPendientes->count() -1) << "eventos pendientes de asignación de fallas";
        if(count==0){
            QMessageBox::information(this, "Información","No hay eventos de carga de fallas");
        }
    }else{
        // === ERROR 3: AGREGAR DEBUG MÁS DETALLADO ===
        qDebug()<< "Error cargando eventos:" << query.lastError().text();
        qDebug()<< "Consulta SQL:" << consulta;
    }

}


void asociarFalla::on_comboBoxEventoPendientes_currentIndexChanged(int index)
{
    // if(index <=0){
    //     limpiarFormularios();
    //     return;
    // }
}

bool asociarFalla::validarPestañaBCH(){
    if(ui->lineEditNS_BCH->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Ingrese el número de serie del BCH");
        ui->lineEditNS_BCH->setFocus();
        return false;
    }//validacion 1

    if(ui->comboBox_2DRIVERS_BCH->currentData().toInt()==-1){
        QMessageBox::warning(this, "Error", "Ingrese la cantidad de drivers en falla");
        ui->comboBox_2DRIVERS_BCH->setFocus();
        return false;
    }//validacion 2

    if(ui->spinBoxNotaS_BCH->text().toInt()==0){
        QMessageBox::warning(this, "Error", "Ingrese la nota de servicio asociada");
        ui->spinBoxNotaS_BCH->setFocus();
        return false;
    }//validacion 3

    return true;
}

bool asociarFalla::validarPestañaPW(){
    if(ui->lineEdit_2NS_PW->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Ingrese el número de serie del PW");
        ui->lineEdit_2NS_PW->setFocus();
        return false;
    }//validacion 1

    if(ui->comboBox_3DRIVERS_PW->currentData().toInt()==-1){
        QMessageBox::warning(this, "Error", "Ingrese la cantidad de drivers en falla");
        ui->comboBox_3DRIVERS_PW->setFocus();
        return false;
    }//validacion 2

    if(ui->spinBox_2NotaS_PW->text().toInt()==0){
        QMessageBox::warning(this, "Error", "Ingrese la nota de servicio asociada");
        ui->spinBox_2NotaS_PW->setFocus();
        return false;
    }//validacion 3

        return true;
}

void asociarFalla::limpiarBCH(){
    ui->lineEditNS_BCH->clear();
    ui->dateEditBCH->setDate(QDate::currentDate());
    ui->spinBoxNotaS_BCH->setValue(0);
    ui->checkBoxIGB1->setChecked(false);
    ui->checkBox_2DB1->setChecked(false);
    ui->checkBox_3IGB2->setChecked(false);
    ui->checkBox_4DB2->setChecked(false);
    ui->comboBox_2DRIVERS_BCH->setCurrentIndex(-1);
    qDebug() <<"Pestaña BCH limpiada";
}

void asociarFalla::limpiarPW(){
    ui->lineEdit_2NS_PW->clear();
    ui->dateEdit_2PW->setDate(QDate::currentDate());
    ui->spinBox_2NotaS_PW->setValue(0);
    ui->checkBox_6IGU->setChecked(false);
    ui->checkBox_5IGX->setChecked(false);
    ui->checkBox_8IGV->setChecked(false);
    ui->checkBox_7IGY->setChecked(false);
    ui->checkBox_9IGW->setChecked(false);
    ui->checkBox_10IGZ->setChecked(false);
    ui->comboBox_3DRIVERS_PW->setCurrentIndex(-1);
    qDebug()<<"Pestaña PW limpiada";
}


void asociarFalla::on_pushButton_3BCH_clicked()
{
    qDebug() << "💾 Intentando guardar Falla BCH...";

    // Validar que hay un evento seleccionado
    if (ui->comboBoxEventoPendientes->currentData().toInt() == -1) {
        QMessageBox::warning(this, "Error", "Seleccione un evento primero");
        return;
    }

    // Validar datos específicos de BCH
    if (!validarPestañaBCH()) {
        return;
    }

    QSqlDatabase::database().transaction();

    QSqlQuery query;
    query.prepare("INSERT INTO FALLA_BCH (evento_id, numero_serie, fecha_reparacion, "
                  "NS_BCH_FALLA, IGB1, DB1, IGB2, DB2, DRIVER_BCH) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");

    // Obtener el ID del evento seleccionado
    int eventoId = ui->comboBoxEventoPendientes->currentData().toInt();

    //validacion para evitar un doble guardado sobre el mismo evento
    if(tieneFallaBCH(eventoId)){
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "Error", "Este evento ya tiene una falla de BCH asociada");
        return;
    }

    // Bind values para BCH
    query.addBindValue(eventoId);
    query.addBindValue(ui->lineEditNS_BCH->text());
    query.addBindValue(ui->dateEditBCH->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->spinBoxNotaS_BCH->value());
    query.addBindValue(ui->checkBoxIGB1->isChecked());
    query.addBindValue(ui->checkBox_2DB1->isChecked());
    query.addBindValue(ui->checkBox_3IGB2->isChecked());
    query.addBindValue(ui->checkBox_4DB2->isChecked());
    query.addBindValue(ui->comboBox_2DRIVERS_BCH->currentData().toInt());

    if (query.exec()) {
        QSqlDatabase::database().commit();
        qDebug() << "✅ Falla BCH guardada - ID:" << query.lastInsertId().toString();
        QMessageBox::information(this, "Éxito", "Falla BCH registrada correctamente");

        // Emitir señal para actualizar MainWindow
        emit fallaRegistrada();

        // Limpiar solo la pestaña BCH y recargar eventos
        limpiarBCH();
        CargarEventosSinFallas();  // Recargar porque este evento ya tiene falla BCH

        //ir a la pestaña de falla PW después de guardar
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);

    } else {
        QSqlDatabase::database().rollback();
        QString error = query.lastError().text();
        qDebug() << "❌ Error guardando Falla BCH:" << error;
        QMessageBox::critical(this, "Error", "No se pudo guardar la falla BCH:\n" + error);
    }

}

void asociarFalla::on_pushButton_4PW_clicked()
{
    // Validar que hay un evento seleccionado
    if (ui->comboBoxEventoPendientes->currentData().toInt() == -1) {
        QMessageBox::warning(this, "Error", "Seleccione un evento primero");
        return;
    }

    // Validar datos específicos de PW
    if (!validarPestañaPW()) {
        return;
    }
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.prepare("INSERT INTO FALLA_PW (evento_id, numero_serie, fecha_reparacion, "
                  "NS_PW_FALLA, IGU, IGX, IGV, IGY, IGW, IGZ, DRIVER_PW) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    // Obtener el ID del evento seleccionado
    int eventoId = ui->comboBoxEventoPendientes->currentData().toInt();

    if(tieneFallaPW(eventoId)){
        QMessageBox::warning(this, "Error", "Este evento ya tiene una falla de PW asignada");
        return;
    }

    // Bind values para BCH
    query.addBindValue(eventoId);
    query.addBindValue(ui->lineEdit_2NS_PW->text());
    query.addBindValue(ui->dateEdit_2PW->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->spinBox_2NotaS_PW->value());
    query.addBindValue(ui->checkBox_6IGU->isChecked());
    query.addBindValue(ui->checkBox_5IGX->isChecked());
    query.addBindValue(ui->checkBox_8IGV->isChecked());
    query.addBindValue(ui->checkBox_7IGY->isChecked());
    query.addBindValue(ui->checkBox_9IGW->isChecked());
    query.addBindValue(ui->checkBox_10IGZ->isChecked());
    query.addBindValue(ui->comboBox_3DRIVERS_PW->currentData().toInt());

    if (query.exec()) {
        QSqlDatabase::database().commit();
        qDebug() << "Falla PW guardada - ID:" << query.lastInsertId().toString();
        QMessageBox::information(this, "Éxito", "Falla PW registrada correctamente");

        // Emitir señal para actualizar MainWindow
        emit fallaRegistrada();

        // Limpiar solo la pestaña BCH y recargar eventos
        limpiarPW();
        CargarEventosSinFallas();  // Recargar porque este evento ya tiene falla BCH

        salir();


    } else {
        QSqlDatabase::database().rollback();
        QString error = query.lastError().text();
        qDebug() << "❌ Error guardando Falla PW:" << error;
        QMessageBox::critical(this, "Error", "No se pudo guardar la falla PW:\n" + error);
    }

}

void asociarFalla::salir(){
    QMessageBox::StandardButton reply;
    reply= QMessageBox::question(this,"Consulta","¿Desea terminar con la carga de información?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        this->reject();
    }
}

bool asociarFalla::tieneFallaBCH(int eventoID){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FALLA_BCH WHERE evento_id = ?");
    query.addBindValue(eventoID);
    return query.exec() && query.next() && query.value(0).toInt() > 0;

}

bool asociarFalla::tieneFallaPW(int eventoID){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FALLA_PW WHERE evento_id = ?");
    query.addBindValue(eventoID);
    return query.exec() && query.next() && query.value(0).toInt() > 0;
}

void asociarFalla::generarTablaPW(){
    QSqlQuery query;

    QStringList sqlCommands = {
        "CREATE TABLE IF NOT EXISTS FALLA_PW_2 ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "evento_id INTEGER NOT NULL,"
        "numero_serie VARCHAR(50) NOT NULL,"
        "fecha_reparacion DATE,"
        "NS_PW_FALLA INTEGER UNIQUE NOT NULL,"
        "IGU BOOLEAN DEFAULT 0,"
        "IGX BOOLEAN DEFAULT 0,"
        "IGV BOOLEAN DEFAULT 0,"
        "IGY BOOLEAN DEFAULT 0,"
        "IGW BOOLEAN DEFAULT 0,"
        "IGZ BOOLEAN DEFAULT 0,"
        "DRIVER_PW INTEGER CHECK(DRIVER_PW BETWEEN 0 AND 3), "
        "FOREIGN KEY (evento_id) REFERENCES eventos(id) ON DELETE CASCADE)"

        //"DROP TABLE IF EXISTS FALLA_PW",
        //"ALTER TABLE FALLA_PW_TEMP RENAME TO FALLA_PW"
    };//sql commands

    for(const QString &sql : sqlCommands ){
        if(!query.exec(sql)){
            qDebug()<<"Error ejecutando: "<< sql;
            qDebug()<<"Error: "<< query.lastError().text();
            return;
        }//if
    }//for
    qDebug()<<"Estructutra de FALLA_PW corregida exitosamente";
}//generar tabla pw
