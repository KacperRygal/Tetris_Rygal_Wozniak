#ifndef MAINWINDOWTETRIS_H
#define MAINWINDOWTETRIS_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include "gamewidget.h"

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

private:
    QColor colors[7] = {Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::magenta, Qt::cyan, Qt::black};
    Ui::MainWindowTetris *ui;
    QGridLayout *boardLayout;
    QLabel *boardLabels[Board::HeightBoard][Board::WidthBoard];
    GameWidget *gameWidget;
};
#endif // MAINWINDOWTETRIS_H
