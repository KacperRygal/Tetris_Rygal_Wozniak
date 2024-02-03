#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "board.h"
#include <QElapsedTimer>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    Board* getBoard();
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:

private:
    Board* board;
    bool rotationToggle = true;
    QElapsedTimer keyPressTimer;
    QElapsedTimer keyDownTimer;
    const int delay = 400;
    QMap<int, int> keyDelays;

};

#endif // GAMEWIDGET_H
