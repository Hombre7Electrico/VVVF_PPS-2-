#include "asociarfalla.h"
#include "ui_asociarfalla.h"

asociarFalla::asociarFalla(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::asociarFalla)
{
    ui->setupUi(this);
}

asociarFalla::~asociarFalla()
{
    delete ui;
}
