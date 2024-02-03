/********************************************************************************
** Form generated from reading UI file 'save.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_H
#define UI_SAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Save
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *nazwaTxt;
    QLabel *aktWynik;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ZapiszBtn;
    QPushButton *MenuBtn;
    QPushButton *ZamknijBtn;
    QListWidget *ListaWynik;

    void setupUi(QDialog *Save)
    {
        if (Save->objectName().isEmpty())
            Save->setObjectName("Save");
        Save->resize(400, 300);
        horizontalLayoutWidget = new QWidget(Save);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 361, 281));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        nazwaTxt = new QTextEdit(horizontalLayoutWidget);
        nazwaTxt->setObjectName("nazwaTxt");

        verticalLayout->addWidget(nazwaTxt);

        aktWynik = new QLabel(horizontalLayoutWidget);
        aktWynik->setObjectName("aktWynik");

        verticalLayout->addWidget(aktWynik);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ZapiszBtn = new QPushButton(horizontalLayoutWidget);
        ZapiszBtn->setObjectName("ZapiszBtn");

        horizontalLayout_2->addWidget(ZapiszBtn);

        MenuBtn = new QPushButton(horizontalLayoutWidget);
        MenuBtn->setObjectName("MenuBtn");

        horizontalLayout_2->addWidget(MenuBtn);

        ZamknijBtn = new QPushButton(horizontalLayoutWidget);
        ZamknijBtn->setObjectName("ZamknijBtn");

        horizontalLayout_2->addWidget(ZamknijBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        ListaWynik = new QListWidget(horizontalLayoutWidget);
        ListaWynik->setObjectName("ListaWynik");

        horizontalLayout->addWidget(ListaWynik);


        retranslateUi(Save);

        QMetaObject::connectSlotsByName(Save);
    } // setupUi

    void retranslateUi(QDialog *Save)
    {
        Save->setWindowTitle(QCoreApplication::translate("Save", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Save", "Wpisz swoje inicja\305\202y (3 znaki)", nullptr));
        aktWynik->setText(QCoreApplication::translate("Save", "Aktualny wynik=", nullptr));
        ZapiszBtn->setText(QCoreApplication::translate("Save", "Zapisz ", nullptr));
        MenuBtn->setText(QCoreApplication::translate("Save", "Menu", nullptr));
        ZamknijBtn->setText(QCoreApplication::translate("Save", "Zamknij", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Save: public Ui_Save {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_H
