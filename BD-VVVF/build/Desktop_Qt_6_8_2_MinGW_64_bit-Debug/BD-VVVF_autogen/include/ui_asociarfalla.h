/********************************************************************************
** Form generated from reading UI file 'asociarfalla.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASOCIARFALLA_H
#define UI_ASOCIARFALLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_asociarFalla
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEditNS_BCH;
    QDateEdit *dateEditBCH;
    QSpinBox *spinBoxNotaS_BCH;
    QCheckBox *checkBoxIGB1;
    QCheckBox *checkBox_2DB1;
    QCheckBox *checkBox_3IGB2;
    QCheckBox *checkBox_4DB2;
    QComboBox *comboBox_2DRIVERS_BCH;
    QPushButton *pushButton_3BCH;
    QWidget *tab_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit_2NS_PW;
    QDateEdit *dateEdit_2PW;
    QSpinBox *spinBox_2NotaS_PW;
    QCheckBox *checkBox_6IGU;
    QCheckBox *checkBox_5IGX;
    QCheckBox *checkBox_8IGV;
    QCheckBox *checkBox_7IGY;
    QCheckBox *checkBox_9IGW;
    QCheckBox *checkBox_10IGZ;
    QComboBox *comboBox_3DRIVERS_PW;
    QPushButton *pushButton_4PW;
    QComboBox *comboBoxEventoPendientes;
    QPushButton *pushButton_2;

    void setupUi(QDialog *asociarFalla)
    {
        if (asociarFalla->objectName().isEmpty())
            asociarFalla->setObjectName("asociarFalla");
        asociarFalla->resize(562, 562);
        layoutWidget = new QWidget(asociarFalla);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 541, 531));
        verticalLayout_9 = new QVBoxLayout(layoutWidget);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 511, 391));
        verticalLayout_10 = new QVBoxLayout(layoutWidget1);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
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

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lineEditNS_BCH = new QLineEdit(layoutWidget1);
        lineEditNS_BCH->setObjectName("lineEditNS_BCH");

        verticalLayout_3->addWidget(lineEditNS_BCH);

        dateEditBCH = new QDateEdit(layoutWidget1);
        dateEditBCH->setObjectName("dateEditBCH");

        verticalLayout_3->addWidget(dateEditBCH);

        spinBoxNotaS_BCH = new QSpinBox(layoutWidget1);
        spinBoxNotaS_BCH->setObjectName("spinBoxNotaS_BCH");

        verticalLayout_3->addWidget(spinBoxNotaS_BCH);

        checkBoxIGB1 = new QCheckBox(layoutWidget1);
        checkBoxIGB1->setObjectName("checkBoxIGB1");

        verticalLayout_3->addWidget(checkBoxIGB1);

        checkBox_2DB1 = new QCheckBox(layoutWidget1);
        checkBox_2DB1->setObjectName("checkBox_2DB1");

        verticalLayout_3->addWidget(checkBox_2DB1);

        checkBox_3IGB2 = new QCheckBox(layoutWidget1);
        checkBox_3IGB2->setObjectName("checkBox_3IGB2");

        verticalLayout_3->addWidget(checkBox_3IGB2);

        checkBox_4DB2 = new QCheckBox(layoutWidget1);
        checkBox_4DB2->setObjectName("checkBox_4DB2");

        verticalLayout_3->addWidget(checkBox_4DB2);

        comboBox_2DRIVERS_BCH = new QComboBox(layoutWidget1);
        comboBox_2DRIVERS_BCH->setObjectName("comboBox_2DRIVERS_BCH");

        verticalLayout_3->addWidget(comboBox_2DRIVERS_BCH);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_10->addLayout(horizontalLayout_3);

        pushButton_3BCH = new QPushButton(layoutWidget1);
        pushButton_3BCH->setObjectName("pushButton_3BCH");

        verticalLayout_10->addWidget(pushButton_3BCH);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 10, 511, 391));
        verticalLayout_8 = new QVBoxLayout(layoutWidget2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName("label_9");

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName("label_10");

        verticalLayout_5->addWidget(label_10);

        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName("label_11");

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName("label_12");

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName("label_13");

        verticalLayout_5->addWidget(label_13);

        label_14 = new QLabel(layoutWidget2);
        label_14->setObjectName("label_14");

        verticalLayout_5->addWidget(label_14);

        label_15 = new QLabel(layoutWidget2);
        label_15->setObjectName("label_15");

        verticalLayout_5->addWidget(label_15);

        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName("label_16");

        verticalLayout_5->addWidget(label_16);

        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName("label_17");

        verticalLayout_5->addWidget(label_17);

        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName("label_18");

        verticalLayout_5->addWidget(label_18);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_4);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        lineEdit_2NS_PW = new QLineEdit(layoutWidget2);
        lineEdit_2NS_PW->setObjectName("lineEdit_2NS_PW");

        verticalLayout_7->addWidget(lineEdit_2NS_PW);

        dateEdit_2PW = new QDateEdit(layoutWidget2);
        dateEdit_2PW->setObjectName("dateEdit_2PW");

        verticalLayout_7->addWidget(dateEdit_2PW);

        spinBox_2NotaS_PW = new QSpinBox(layoutWidget2);
        spinBox_2NotaS_PW->setObjectName("spinBox_2NotaS_PW");

        verticalLayout_7->addWidget(spinBox_2NotaS_PW);

        checkBox_6IGU = new QCheckBox(layoutWidget2);
        checkBox_6IGU->setObjectName("checkBox_6IGU");

        verticalLayout_7->addWidget(checkBox_6IGU);

        checkBox_5IGX = new QCheckBox(layoutWidget2);
        checkBox_5IGX->setObjectName("checkBox_5IGX");

        verticalLayout_7->addWidget(checkBox_5IGX);

        checkBox_8IGV = new QCheckBox(layoutWidget2);
        checkBox_8IGV->setObjectName("checkBox_8IGV");

        verticalLayout_7->addWidget(checkBox_8IGV);

        checkBox_7IGY = new QCheckBox(layoutWidget2);
        checkBox_7IGY->setObjectName("checkBox_7IGY");

        verticalLayout_7->addWidget(checkBox_7IGY);

        checkBox_9IGW = new QCheckBox(layoutWidget2);
        checkBox_9IGW->setObjectName("checkBox_9IGW");

        verticalLayout_7->addWidget(checkBox_9IGW);

        checkBox_10IGZ = new QCheckBox(layoutWidget2);
        checkBox_10IGZ->setObjectName("checkBox_10IGZ");

        verticalLayout_7->addWidget(checkBox_10IGZ);

        comboBox_3DRIVERS_PW = new QComboBox(layoutWidget2);
        comboBox_3DRIVERS_PW->setObjectName("comboBox_3DRIVERS_PW");

        verticalLayout_7->addWidget(comboBox_3DRIVERS_PW);


        horizontalLayout_2->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_2);

        pushButton_4PW = new QPushButton(layoutWidget2);
        pushButton_4PW->setObjectName("pushButton_4PW");

        verticalLayout_8->addWidget(pushButton_4PW);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_9->addLayout(verticalLayout_4);

        comboBoxEventoPendientes = new QComboBox(layoutWidget);
        comboBoxEventoPendientes->setObjectName("comboBoxEventoPendientes");

        verticalLayout_9->addWidget(comboBoxEventoPendientes);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_9->addWidget(pushButton_2);


        retranslateUi(asociarFalla);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(asociarFalla);
    } // setupUi

    void retranslateUi(QDialog *asociarFalla)
    {
        asociarFalla->setWindowTitle(QCoreApplication::translate("asociarFalla", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("asociarFalla", "N\303\272mero de Serie", nullptr));
        label_2->setText(QCoreApplication::translate("asociarFalla", "Fecha de Reparaci\303\263n", nullptr));
        label_3->setText(QCoreApplication::translate("asociarFalla", "Nota de Servicio Falla", nullptr));
        label_4->setText(QCoreApplication::translate("asociarFalla", "IGB1", nullptr));
        label_5->setText(QCoreApplication::translate("asociarFalla", "DB1", nullptr));
        label_6->setText(QCoreApplication::translate("asociarFalla", "IGB2", nullptr));
        label_7->setText(QCoreApplication::translate("asociarFalla", "DB2", nullptr));
        label_8->setText(QCoreApplication::translate("asociarFalla", "Drivers quemados", nullptr));
        checkBoxIGB1->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        checkBox_2DB1->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        checkBox_3IGB2->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        checkBox_4DB2->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        pushButton_3BCH->setText(QCoreApplication::translate("asociarFalla", "Guardar Falla", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("asociarFalla", "Detalle falla BCH", nullptr));
        label_9->setText(QCoreApplication::translate("asociarFalla", "N\303\272mero de Serie", nullptr));
        label_10->setText(QCoreApplication::translate("asociarFalla", "Fecha de Reparaci\303\263n", nullptr));
        label_11->setText(QCoreApplication::translate("asociarFalla", "Nota de Servicio Falla", nullptr));
        label_12->setText(QCoreApplication::translate("asociarFalla", "IGU", nullptr));
        label_13->setText(QCoreApplication::translate("asociarFalla", "IGX", nullptr));
        label_14->setText(QCoreApplication::translate("asociarFalla", "IGV", nullptr));
        label_15->setText(QCoreApplication::translate("asociarFalla", "IGY", nullptr));
        label_16->setText(QCoreApplication::translate("asociarFalla", "IGW", nullptr));
        label_17->setText(QCoreApplication::translate("asociarFalla", "IGZ", nullptr));
        label_18->setText(QCoreApplication::translate("asociarFalla", "Drivers Quemados", nullptr));
        checkBox_6IGU->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        checkBox_5IGX->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        checkBox_8IGV->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        checkBox_7IGY->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        checkBox_9IGW->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        checkBox_10IGZ->setText(QCoreApplication::translate("asociarFalla", "Roto", nullptr));
        pushButton_4PW->setText(QCoreApplication::translate("asociarFalla", "Guardar Falla", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("asociarFalla", "Detalle falla PW", nullptr));
        pushButton_2->setText(QCoreApplication::translate("asociarFalla", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class asociarFalla: public Ui_asociarFalla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASOCIARFALLA_H
