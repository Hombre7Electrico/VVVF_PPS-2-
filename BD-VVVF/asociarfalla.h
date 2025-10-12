#ifndef ASOCIARFALLA_H
#define ASOCIARFALLA_H

#include <QDialog>

namespace Ui {
class asociarFalla;
}

class asociarFalla : public QDialog
{
    Q_OBJECT

public:
    explicit asociarFalla(QWidget *parent = nullptr);
    ~asociarFalla();

private:
    Ui::asociarFalla *ui;
};

#endif // ASOCIARFALLA_H
