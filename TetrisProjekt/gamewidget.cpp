#include "gamewidget.h"
#include "qevent.h"


GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    board = new Board(this);
    board->setParent(this);
    installEventFilter(this);
    keyDelays[Qt::Key_Left] = 100;
    keyDelays[Qt::Key_Right] = 100;
    keyDelays[Qt::Key_Up] = 100;
    keyDelays[Qt::Key_Space] = 200;
    keyDelays[Qt::Key_Down] = 400;
}

//OBSLUGA ZDARZEN
bool GameWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

            int customDelay = keyDelays.value(keyEvent->key(), delay);

            if (keyPressTimer.isValid() && keyPressTimer.elapsed() < customDelay)
                return true;

            keyPressTimer.start();

            switch (keyEvent->key())
            {
                case Qt::Key_Left:
                    board->moveCurrentPieceSides(-1);
                    break;
                case Qt::Key_Right:
                    board->moveCurrentPieceSides(1);
                    break;
                case Qt::Key_Up:
                    board->rotateCurrentPiece();
                    break;
                case Qt::Key_Space:
                    board->moveCurrentPieceInstantDown();
                    break;
                case Qt::Key_Down:
                    board->setTimerInterval(100);
                    break;
            }
        }
        else if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

            switch (keyEvent->key())
            {
                case Qt::Key_Down:
                    if (!keyEvent->isAutoRepeat())
                        board->setTimerInterval(400);
                    break;
            }
        }
    }

    return QObject::eventFilter(obj, event);
}

//GETTERY
Board* GameWidget::getBoard()
{
    return board;
}
