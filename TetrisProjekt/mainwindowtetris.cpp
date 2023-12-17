#include "mainwindowtetris.h"
#include "./ui_mainwindowtetris.h"
#include "gamewidget.h""
#include <QString>

MainWindowTetris::MainWindowTetris(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowTetris)
{
    ui->setupUi(this);
    this->setWindowTitle("Projekt Tetris");

    gameWidget = new GameWidget(this);
    connect(gameWidget->getBoard(), SIGNAL(boardUpdated()), this, SLOT(onBoardUpdated()));
    gameWidget->setFocusPolicy(Qt::StrongFocus);
    boardLayout= new QGridLayout;
    ui->centralwidget->setLayout(boardLayout);

    boardLayout->setSpacing(0);
    boardLayout->setAlignment(Qt::AlignLeft);

    for (int row = 0; row < Board::HeightBoard; ++row) {
        for (int col = 0; col < Board::WidthBoard; ++col) {
            QLabel *label = new QLabel;
            label->setFrameShape(QFrame::Box);
            label->setMargin(1);
            label->setFixedSize(30,30);
            boardLabels[row][col] = label;
            boardLayout->addWidget(label, row, col);
        }
    }

}

MainWindowTetris::~MainWindowTetris()
{
    delete ui;
}

void MainWindowTetris::onBoardUpdated()
{

    for (int row = 0; row < Board::HeightBoard; ++row) {
        QDebug dbg(QtDebugMsg);
            for (int col = 0; col < Board::WidthBoard; ++col) {
                int cellValue = gameWidget->getBoard()->getValue(row, col);

                if(cellValue == 1||cellValue==2)
                {
                    QString color = QString("QLabel {background-color: %1;}").arg(colors[gameWidget->getBoard()->getColorBoard(row,col)].name());
                    //qInfo()<<color;
                    boardLabels[row][col]->setStyleSheet(color);
                }
                else if(cellValue == 0)
                {
                    boardLabels[row][col]->setStyleSheet("QLabel {background-color: white;}");
                }
                dbg<<"|"<<cellValue<<" : "<<gameWidget->getBoard()->getColorBoard(row,col);
            }
            dbg<<"|";
        }

}



void MainWindowTetris::on_pushButton_clicked()
{
    gameWidget->getBoard()->start();
}


void MainWindowTetris::on_pauseButton_clicked()
{
    gameWidget->getBoard()->pause();
}


void MainWindowTetris::on_clearButton_clicked()
{
    gameWidget->getBoard()->reset();
}

