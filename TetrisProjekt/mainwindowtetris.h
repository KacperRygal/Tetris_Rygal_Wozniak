#ifndef MAINWINDOWTETRIS_H
#define MAINWINDOWTETRIS_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include "gamewidget.h"
#include "menu.h"
#include "save.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowTetris; }
QT_END_NAMESPACE

class MainWindowTetris : public QMainWindow
{
    Q_OBJECT



public:
    MainWindowTetris(QWidget *parent = nullptr);
    ~MainWindowTetris();


private slots:
    void onBoardUpdated();

    void on_pushButton_clicked();

    void on_pauseButton_clicked();

    void on_clearButton_clicked();

    void zamknijOkno();

    void on_ZapiszBtn_clicked();

    void zamknijZapisane();

private:
    Menu *menu;
    QColor colors[7] = {Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::magenta, Qt::cyan, Qt::black};
    Ui::MainWindowTetris *ui;
    QGridLayout *boardLayout;
    QGridLayout *nextPieceLayout;
    QLabel *boardLabels[Board::HeightBoard][Board::WidthBoard];
    QLabel *boardNextPieceLabels[4][4];
    GameWidget *gameWidget;
    Save *save;
};
#endif // MAINWINDOWTETRIS_H
