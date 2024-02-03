#ifndef SAVE_H
#define SAVE_H

#include <QDialog>

namespace Ui {
class Save;
}

class Save : public QDialog
{
    Q_OBJECT
signals:
    void zapisaneClicked();

public:
    explicit Save(QWidget *parent = nullptr);
    void setWynik(int);
    ~Save();

private slots:
    void on_ZapiszBtn_clicked();



private:
    Ui::Save *ui;
    int wynik=0;
};

#endif // SAVE_H
