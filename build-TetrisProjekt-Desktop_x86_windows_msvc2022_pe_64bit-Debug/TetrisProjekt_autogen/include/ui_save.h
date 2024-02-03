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
    QPushButton *ZapiszBtn;
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

        ZapiszBtn = new QPushButton(horizontalLayoutWidget);
        ZapiszBtn->setObjectName("ZapiszBtn");

        verticalLayout->addWidget(ZapiszBtn);


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
        ZapiszBtn->setText(QCoreApplication::translate("Save", "Zapisz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Save: public Ui_Save {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_H
