#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "score.h"
#include <QTimer>
#include <QVector>

class Board : public QObject{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr);
    ~Board();
    static const int WidthBoard = 10;
    static const int HeightBoard = 20;

    void start();
    void pause();
    void reset();
    void end();

    void moveCurrentPieceSides(int x);
    void rotateCurrentPiece();
    void moveCurrentPieceInstantDown();

    Piece getCurrentPiece();
    int getValue(int row, int col);
    int getNextPieceValue(int row, int col);
    Tetromino getNextPieceColor();
    Tetromino getCurrentTetromino();
    Tetromino getColorBoard(int row, int col);
    void setTimerInterval(int time);
    Score getScore();
    int getRemovedLines();

signals:
    void boardUpdated();

private slots:
    void updateBoard();

private:
    QTimer *timer;
    QVector<QVector<int>> board;
    QVector<QVector<int>> nextPieceBoard;
    QVector<QVector<Tetromino>> colorBoard;
    Tetromino nextPieceColor;
    Piece currentPiece;
    bool isWall = false;
    bool isPause = false;
    int currentX;
    int currentY;
    int deletedRows = 0;
    int levelRows = 0;
    Score score;
    bool timerFlag = false;
    int LvlTimeInterval;

    void clearBoard();
    void updateCurrentPiece();
    void updateNextPiece();
    bool isLegalMove(int x, int y, const Piece &p);
    void placePiece();
    void checkFullRows();
    void handleCollision();
    bool isRowFull(int row);
    void moveCurrentPieceDown();

};


#endif // BOARD_H
