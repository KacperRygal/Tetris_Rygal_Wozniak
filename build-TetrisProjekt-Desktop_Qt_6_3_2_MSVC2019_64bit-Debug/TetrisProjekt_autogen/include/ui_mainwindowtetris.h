/********************************************************************************
** Form generated from reading UI file 'mainwindowtetris.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWTETRIS_H
#define UI_MAINWINDOWTETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowTetris
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pauseButton;
    QPushButton *clearButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowTetris)
    {
        if (MainWindowTetris->objectName().isEmpty())
            MainWindowTetris->setObjectName(QString::fromUtf8("MainWindowTetris"));
        MainWindowTetris->resize(800, 600);
        centralwidget = new QWidget(MainWindowTetris);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 40, 75, 24));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(670, 110, 75, 24));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(670, 170, 75, 24));
        MainWindowTetris->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowTetris);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindowTetris->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowTetris);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowTetris->setStatusBar(statusbar);

        retranslateUi(MainWindowTetris);

        QMetaObject::connectSlotsByName(MainWindowTetris);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowTetris)
    {
        MainWindowTetris->setWindowTitle(QCoreApplication::translate("MainWindowTetris", "MainWindowTetris", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowTetris", "Start", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindowTetris", "Pause", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindowTetris", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowTetris: public Ui_MainWindowTetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWTETRIS_H
