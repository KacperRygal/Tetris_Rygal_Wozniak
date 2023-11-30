#include "gamewidget.h"
#include "qevent.h"

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    board = new Board(this);
    board->setParent(this);
}

Board* GameWidget::getBoard()
{
    return board;
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Left:
            board->moveCurrentPieceSides(-1);
            qInfo()<<"Lewo";
            break;
        case Qt::Key_Right:
            board->moveCurrentPieceSides(1);
            qInfo()<<"Prawo";
            break;
        case Qt::Key_Up:
            rotationToggle=!rotationToggle;
            board->rotateCurrentPiece(rotationToggle);
            qInfo()<<"Obrot";
            break;

    }
}
