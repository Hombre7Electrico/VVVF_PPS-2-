#ifndef NUEVOEVENTO_H
#define NUEVOEVENTO_H

#include <QDialog>
#include <QSqlTableModel>



namespace Ui {
class NuevoEvento;
}

class NuevoEvento : public QDialog
{
    Q_OBJECT

public:
    explicit NuevoEvento(QWidget *parent = nullptr);
    ~NuevoEvento();

private slots:
    void on_pushButtonOK_clicked();

    void on_pushButtonNO_clicked();

signals:
    void eventoAgregado();  // ✅ Señal que se emitirá cuando se agregue un evento

private:
    Ui::NuevoEvento *ui;
    //detalle de las funciones que responden a eventos. (se conecta solo con .ui)
    void guardar_registro();
    void cancelar();
};

#endif // NUEVOEVENTO_H
