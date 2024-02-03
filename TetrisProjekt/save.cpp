#include "save.h"
#include "ui_save.h"

#include <QFile>

Save::Save(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Save)
{
    ui->setupUi(this);
    this->setWindowTitle("Zapis");
    QString fileName = "wynik.txt";

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
Save::~Save()
{
    delete ui;
}

void Save::on_ZapiszBtn_clicked()
{
    if(!ui->nazwaTxt->toPlainText().isEmpty()){
    QFile file("wynik.txt");

    if (file.open(QIODevice::WriteOnly |QIODevice::Append| QIODevice::Text)) {

        QTextStream stream(&file);

        QString textToWrite =ui->nazwaTxt->toPlainText().first(3).toUpper()+ " "+ QString::number(wynik)+"\n";

        stream << textToWrite;

        file.close();
    }
    emit zapisaneClicked();
    }
}

void Save::setWynik(int w)
{
    wynik=w;
    ui->aktWynik->setText("Aktualny wynik = "+QString::number(w));
}
