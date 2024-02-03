/********************************************************************************
** Form generated from reading UI file 'mainwindowtetris.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWTETRIS_H
#define UI_MAINWINDOWTETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *displayScore;
    QLineEdit *displayLevel;
    QLineEdit *displayRemovedLines;
    QPushButton *ZapiszBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowTetris)
    {
        if (MainWindowTetris->objectName().isEmpty())
            MainWindowTetris->setObjectName("MainWindowTetris");
        MainWindowTetris->resize(800, 600);
        centralwidget = new QWidget(MainWindowTetris);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(670, 30, 75, 24));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(670, 120, 75, 24));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(670, 170, 75, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(680, 220, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(680, 280, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(660, 350, 81, 20));
        displayScore = new QLineEdit(centralwidget);
        displayScore->setObjectName("displayScore");
        displayScore->setGeometry(QRect(650, 250, 113, 24));
        displayLevel = new QLineEdit(centralwidget);
        displayLevel->setObjectName("displayLevel");
        displayLevel->setGeometry(QRect(650, 310, 113, 24));
        displayRemovedLines = new QLineEdit(centralwidget);
        displayRemovedLines->setObjectName("displayRemovedLines");
        displayRemovedLines->setGeometry(QRect(650, 380, 113, 24));
        ZapiszBtn = new QPushButton(centralwidget);
        ZapiszBtn->setObjectName("ZapiszBtn");
        ZapiszBtn->setGeometry(QRect(670, 80, 75, 24));
        MainWindowTetris->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowTetris);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindowTetris->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowTetris);
        statusbar->setObjectName("statusbar");
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
        label->setText(QCoreApplication::translate("MainWindowTetris", "Score", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowTetris", "Level", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowTetris", "Lines removed", nullptr));
        ZapiszBtn->setText(QCoreApplication::translate("MainWindowTetris", "Zapisz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowTetris: public Ui_MainWindowTetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWTETRIS_H
