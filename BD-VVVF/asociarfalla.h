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

    void on_pushButton_3BCH_clicked();

    void on_pushButton_4PW_clicked();

private:
    Ui::asociarFalla *ui;

    //validaciones de pestañas
    bool validarPestañaBCH();
    bool validarPestañaPW();
    //limpiar pestañas
    void limpiarBCH();
    void limpiarPW();
    void salir();
    void generarTablaPW();
    //mostrar fallas
    bool tieneFallaBCH(int eventoID);
    bool tieneFallaPW(int eventoID);
};

#endif // ASOCIARFALLA_H
