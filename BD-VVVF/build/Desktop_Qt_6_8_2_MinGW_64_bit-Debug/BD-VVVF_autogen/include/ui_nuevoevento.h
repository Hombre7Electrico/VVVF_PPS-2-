/********************************************************************************
** Form generated from reading UI file 'nuevoevento.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVOEVENTO_H
#define UI_NUEVOEVENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NuevoEvento
{
public:
    QLabel *label_7;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonNO;
    QPushButton *pushButtonOK;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QDateEdit *dateEdit;
    QComboBox *comboBoxFormacion;
    QComboBox *comboBoxCoche;
    QComboBox *comboBoxGalpon;
    QComboBox *comboBoxTipoEvento;
    QSpinBox *spinBoxNS;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *NuevoEvento)
    {
        if (NuevoEvento->objectName().isEmpty())
            NuevoEvento->setObjectName("NuevoEvento");
        NuevoEvento->resize(424, 384);
        label_7 = new QLabel(NuevoEvento);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(120, 20, 261, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_7->setFont(font);
        layoutWidget = new QWidget(NuevoEvento);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(219, 340, 189, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonNO = new QPushButton(layoutWidget);
        pushButtonNO->setObjectName("pushButtonNO");

        horizontalLayout->addWidget(pushButtonNO);

        pushButtonOK = new QPushButton(layoutWidget);
        pushButtonOK->setObjectName("pushButtonOK");

        horizontalLayout->addWidget(pushButtonOK);

        layoutWidget1 = new QWidget(NuevoEvento);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(29, 90, 119, 211));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        layoutWidget2 = new QWidget(NuevoEvento);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(279, 90, 127, 211));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        dateEdit = new QDateEdit(layoutWidget2);
        dateEdit->setObjectName("dateEdit");

        verticalLayout_2->addWidget(dateEdit);

        comboBoxFormacion = new QComboBox(layoutWidget2);
        comboBoxFormacion->setObjectName("comboBoxFormacion");

        verticalLayout_2->addWidget(comboBoxFormacion);

        comboBoxCoche = new QComboBox(layoutWidget2);
        comboBoxCoche->setObjectName("comboBoxCoche");

        verticalLayout_2->addWidget(comboBoxCoche);

        comboBoxGalpon = new QComboBox(layoutWidget2);
        comboBoxGalpon->setObjectName("comboBoxGalpon");

        verticalLayout_2->addWidget(comboBoxGalpon);

        comboBoxTipoEvento = new QComboBox(layoutWidget2);
        comboBoxTipoEvento->setObjectName("comboBoxTipoEvento");

        verticalLayout_2->addWidget(comboBoxTipoEvento);

        spinBoxNS = new QSpinBox(layoutWidget2);
        spinBoxNS->setObjectName("spinBoxNS");

        verticalLayout_2->addWidget(spinBoxNS);

        layoutWidget3 = new QWidget(NuevoEvento);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(180, 90, 91, 211));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_2);


        retranslateUi(NuevoEvento);

        QMetaObject::connectSlotsByName(NuevoEvento);
    } // setupUi

    void retranslateUi(QDialog *NuevoEvento)
    {
        NuevoEvento->setWindowTitle(QCoreApplication::translate("NuevoEvento", "Dialog", nullptr));
        label_7->setText(QCoreApplication::translate("NuevoEvento", "Nuevo Registro", nullptr));
        pushButtonNO->setText(QCoreApplication::translate("NuevoEvento", "Cancelar", nullptr));
        pushButtonOK->setText(QCoreApplication::translate("NuevoEvento", "Aceptar", nullptr));
        label->setText(QCoreApplication::translate("NuevoEvento", "Fecha:", nullptr));
        label_2->setText(QCoreApplication::translate("NuevoEvento", "Formaci\303\263n:", nullptr));
        label_3->setText(QCoreApplication::translate("NuevoEvento", "Coche:", nullptr));
        label_4->setText(QCoreApplication::translate("NuevoEvento", "Galp\303\263n", nullptr));
        label_5->setText(QCoreApplication::translate("NuevoEvento", "Tipo Evento", nullptr));
        label_6->setText(QCoreApplication::translate("NuevoEvento", "Nota de Servicio: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NuevoEvento: public Ui_NuevoEvento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVOEVENTO_H
