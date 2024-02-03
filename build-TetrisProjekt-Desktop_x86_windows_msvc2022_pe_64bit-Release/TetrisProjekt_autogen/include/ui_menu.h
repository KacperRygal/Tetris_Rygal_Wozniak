/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *NowaGraBtn;
    QPushButton *SkasujBtn;
    QPushButton *ZakonczBtn;
    QListWidget *ListaWynik;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(400, 300);
        horizontalLayoutWidget = new QWidget(Menu);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 341, 194));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        NowaGraBtn = new QPushButton(horizontalLayoutWidget);
        NowaGraBtn->setObjectName("NowaGraBtn");

        verticalLayout->addWidget(NowaGraBtn);

        SkasujBtn = new QPushButton(horizontalLayoutWidget);
        SkasujBtn->setObjectName("SkasujBtn");

        verticalLayout->addWidget(SkasujBtn);

        ZakonczBtn = new QPushButton(horizontalLayoutWidget);
        ZakonczBtn->setObjectName("ZakonczBtn");

        verticalLayout->addWidget(ZakonczBtn);


        horizontalLayout->addLayout(verticalLayout);

        ListaWynik = new QListWidget(horizontalLayoutWidget);
        ListaWynik->setObjectName("ListaWynik");

        horizontalLayout->addWidget(ListaWynik);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Menu", nullptr));
        NowaGraBtn->setText(QCoreApplication::translate("Menu", "Nowa Gra", nullptr));
        SkasujBtn->setText(QCoreApplication::translate("Menu", "Skasuj", nullptr));
        ZakonczBtn->setText(QCoreApplication::translate("Menu", "Zakoncz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
