#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT
signals:
    void zakonczClicked();
    void nowaGra();

public:
    explicit Menu(QWidget *parent = nullptr);

    void Wyswietl();

    ~Menu();

private slots:

    void on_NowaGraBtn_clicked();

    void on_ZakonczBtn_clicked();

    void on_SkasujBtn_clicked();


private:
    Ui::Menu *ui;
};

#endif // MENU_H
