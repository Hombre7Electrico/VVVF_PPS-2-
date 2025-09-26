#include "nuevoevento.h"
#include "ui_nuevoevento.h"

NuevoEvento::NuevoEvento(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NuevoEvento)
{
    ui->setupUi(this);
}

NuevoEvento::~NuevoEvento()
{
    delete ui;
}
