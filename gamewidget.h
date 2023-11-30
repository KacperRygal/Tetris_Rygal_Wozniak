#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "board.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    Board* getBoard();
signals:

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Board* board;
    bool rotationToggle = true;
};

#endif // GAMEWIDGET_H
