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

signals:
    void fallaRegistrada();

private slots:
    void on_pushButton_2_clicked();

    void CargarEventosSinFallas();



    void on_comboBoxEventoPendientes_currentIndexChanged(int index);

private:
    Ui::asociarFalla *ui;
};

#endif // ASOCIARFALLA_H
