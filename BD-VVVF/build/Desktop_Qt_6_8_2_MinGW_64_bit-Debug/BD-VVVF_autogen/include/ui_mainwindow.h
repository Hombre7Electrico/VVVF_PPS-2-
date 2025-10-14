/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableViewEventos;
    QWidget *tab_3;
    QTableView *tableViewFallasBCH;
    QWidget *tab_4;
    QTableView *tableViewFallasPW;
    QWidget *tab_5;
    QTableView *tableViewBCHR;
    QWidget *tab_2;
    QTableView *tableViewPWR;
    QPushButton *pushButton_NuevoEvento;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 20, 761, 381));
        tab = new QWidget();
        tab->setObjectName("tab");
        tableViewEventos = new QTableView(tab);
        tableViewEventos->setObjectName("tableViewEventos");
        tableViewEventos->setGeometry(QRect(15, 10, 731, 321));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableViewFallasBCH = new QTableView(tab_3);
        tableViewFallasBCH->setObjectName("tableViewFallasBCH");
        tableViewFallasBCH->setGeometry(QRect(15, 11, 731, 321));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tableViewFallasPW = new QTableView(tab_4);
        tableViewFallasPW->setObjectName("tableViewFallasPW");
        tableViewFallasPW->setGeometry(QRect(15, 11, 731, 321));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tableViewBCHR = new QTableView(tab_5);
        tableViewBCHR->setObjectName("tableViewBCHR");
        tableViewBCHR->setGeometry(QRect(10, 10, 741, 321));
        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableViewPWR = new QTableView(tab_2);
        tableViewPWR->setObjectName("tableViewPWR");
        tableViewPWR->setGeometry(QRect(10, 10, 741, 321));
        tabWidget->addTab(tab_2, QString());
        pushButton_NuevoEvento = new QPushButton(centralwidget);
        pushButton_NuevoEvento->setObjectName("pushButton_NuevoEvento");
        pushButton_NuevoEvento->setGeometry(QRect(20, 420, 121, 29));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 420, 101, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Evento", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "BCH_F", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "PW_F", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "BCH_R", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "PW_R", nullptr));
        pushButton_NuevoEvento->setText(QCoreApplication::translate("MainWindow", "Agregar evento", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Asociar Fallas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
