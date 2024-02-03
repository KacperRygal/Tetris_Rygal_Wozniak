
#include "mainwindowtetris.h"
#include "./ui_mainwindowtetris.h"
#include "gamewidget.h"
#include "save.h"
#include "menu.h"
#include <QString>



MainWindowTetris::MainWindowTetris(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowTetris)
{
    ui->setupUi(this);
    this->setWindowTitle("Projekt Tetris");

    save = new Save(this);
    connect(save,&Save::zapisaneClicked,this, &MainWindowTetris::zamknijZapisane);
    connect(save,&Save::pokazMenu,this, &MainWindowTetris::pokazMenu);
    save->hide();

    menu = new Menu(this);
    connect(menu, &Menu::zakonczClicked, this, &MainWindowTetris::zamknijOkno);
    connect(menu, &Menu::nowaGra, this, &MainWindowTetris::nowaGra);

    menu->setModal(true);
    menu->show();


    ui->pauseButton->setEnabled(false);
    ui->displayLevel->setEnabled(false);
    ui->displayRemovedLines->setEnabled(false);
    ui->displayScore->setEnabled(false);

    gameWidget = new GameWidget(this);

    connect(gameWidget->getBoard(), SIGNAL(koniec()), this, SLOT(on_ZapiszBtn_clicked()));
    connect(gameWidget->getBoard(), SIGNAL(boardUpdated()), this, SLOT(onBoardUpdated()));
    gameWidget->setFocusPolicy(Qt::StrongFocus);
    gameWidget->setFocus();




    QHBoxLayout *mainLayout = new QHBoxLayout(ui->centralwidget);

        QGridLayout *leftBoardLayout = new QGridLayout;
        leftBoardLayout->setSpacing(0);
        leftBoardLayout->setAlignment(Qt::AlignLeft);

        for (int row = 0; row < Board::HeightBoard; ++row) {
            for (int col = 0; col < Board::WidthBoard; ++col) {
                QLabel *label = new QLabel;
                label->setFrameShape(QFrame::Box);
                label->setMargin(1);
                label->setFixedSize(30, 30);
                boardLabels[row][col] = label;
                leftBoardLayout->addWidget(label, row, col);
            }
        }

        QGridLayout *rightBoardLayout = new QGridLayout;
        rightBoardLayout->setSpacing(0);
        rightBoardLayout->setAlignment(Qt::AlignLeft);

        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                QLabel *label = new QLabel;
                label->setFrameShape(QFrame::Box);
                label->setMargin(1);
                label->setFixedSize(30, 30);
                boardNextPieceLabels[row][col] = label;
                rightBoardLayout->addWidget(label, row, col);
            }
        }
        mainLayout->addLayout(leftBoardLayout);
        mainLayout->setSpacing(1);
        mainLayout->addLayout(rightBoardLayout);




}

MainWindowTetris::~MainWindowTetris()
{
    delete ui;
}

void MainWindowTetris::onBoardUpdated()
{
    for (int row = 0; row < Board::HeightBoard; ++row)
    {
        for (int col = 0; col < Board::WidthBoard; ++col)
        {
            int cellValue = gameWidget->getBoard()->getValue(row, col);
            if(cellValue == 1 || cellValue == 2)
            {
                QString color = QString("QLabel {background-color: %1;}").arg(colors[gameWidget->getBoard()->getColorBoard(row,col)].name());
                boardLabels[row][col]->setStyleSheet(color);
            }
            else if(cellValue == 0)
                boardLabels[row][col]->setStyleSheet("QLabel {background-color: white;}");
        }
    }
    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            int cellValue = gameWidget->getBoard()->getNextPieceValue(row, col);
            if(cellValue == 1)
            {
                QString color = QString("QLabel {background-color: %1;}").arg(colors[gameWidget->getBoard()->getNextPieceColor()].name());
                boardNextPieceLabels[row][col]->setStyleSheet(color);
            }
            else if(cellValue == 0)
                    boardNextPieceLabels[row][col]->setStyleSheet("QLabel {background-color: white;}");
        }
    }
    ui->displayLevel->setText(QString::number(gameWidget->getBoard()->getScore().getCurrentLevel()));
    ui->displayScore->setText(QString::number(gameWidget->getBoard()->getScore().getScore()));
    ui->displayRemovedLines->setText(QString::number(gameWidget->getBoard()->getRemovedLines()));
}



void MainWindowTetris::on_pushButton_clicked()
{
    gameWidget->getBoard()->start();
    ui->pushButton->setEnabled(false);
    ui->pauseButton->setEnabled(true);
}


void MainWindowTetris::on_pauseButton_clicked()
{
    gameWidget->getBoard()->pause();
    ui->pauseButton->setEnabled(false);
    ui->pushButton->setEnabled(true);
}


void MainWindowTetris::on_clearButton_clicked()
{
    gameWidget->getBoard()->reset();
}

void MainWindowTetris::zamknijOkno() {
    emit Zamknij();
   // menu->close();
  //  save->close();
  //  this->close();
}

void MainWindowTetris::on_ZapiszBtn_clicked()
{
    this->hide();
    save->setWynik(gameWidget->getBoard()->getScore().getScore());
    save->show();
}

void MainWindowTetris::zamknijZapisane()
{
    emit Zamknij();
  //  save->close();
  //  menu->close();
   // this->close();
}

void MainWindowTetris::pokazMenu()
{
    save->hide();
    gameWidget->getBoard()->reset();
    menu->Wyswietl();
    menu->show();
}

void MainWindowTetris::nowaGra()
{
    menu->hide();
    on_clearButton_clicked();
    this->show();
}


