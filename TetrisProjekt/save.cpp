#include "save.h"
#include "ui_save.h"

#include <QFile>

Save::Save(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Save)
{
    ui->setupUi(this);
    this->setWindowTitle("Zapis");
}
Save::~Save()
{
    delete ui;
}

void Save::on_ZapiszBtn_clicked()
{
    if(!ui->nazwaTxt->toPlainText().isEmpty()){
    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly |QIODevice::Append| QIODevice::Text)) {

        QTextStream stream(&file);

        QString textToWrite =ui->nazwaTxt->toPlainText().first(3).toUpper()+ " "+ QString::number(wynik)+"\n";

        stream << textToWrite;

        file.close();
    }
    ui->ZapiszBtn->setDisabled(true);
    Wyswietl();
    }

}

void Save::Wyswietl()
{
    ui->ListaWynik->clear();

    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku.";
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        lines.append(line);
    }
    file.close();

    std::sort(lines.begin(), lines.end(), [](const QString &a, const QString &b) {
        QStringList partsA = a.split(" ");
        QStringList partsB = b.split(" ");
        int scoreA = partsA.size() > 1 ? partsA.last().toInt() : 0;
        int scoreB = partsB.size() > 1 ? partsB.last().toInt() : 0;
        return scoreA > scoreB;
    });


    for (const QString &line : lines) {
        QListWidgetItem *item = new QListWidgetItem(line);
        ui->ListaWynik->addItem(item);
    }
}

void Save::setWynik(int w)
{
    ui->ListaWynik->clear();
    wynik=w;
    ui->aktWynik->setText("Aktualny wynik = "+QString::number(w));

    Wyswietl();
}

void Save::on_MenuBtn_clicked()
{
    ui->ZapiszBtn->setEnabled(true);
    emit pokazMenu();
}


void Save::on_ZamknijBtn_clicked()
{
     emit zapisaneClicked();
}

void Save::closeEvent(QCloseEvent *event) {
    emit on_ZamknijBtn_clicked();
}
