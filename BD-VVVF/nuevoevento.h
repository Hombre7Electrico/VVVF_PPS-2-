#ifndef NUEVOEVENTO_H
#define NUEVOEVENTO_H

#include <QDialog>

namespace Ui {
class NuevoEvento;
}

class NuevoEvento : public QDialog
{
    Q_OBJECT

public:
    explicit NuevoEvento(QWidget *parent = nullptr);
    ~NuevoEvento();

private:
    Ui::NuevoEvento *ui;
};

#endif // NUEVOEVENTO_H
