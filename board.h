#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
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
    int getValue(int row, int col);
    Tetromino getCurrentTetromino();
    Piece getCurrentPiece();
    void moveCurrentPieceSides(int x);
    void rotateCurrentPiece(bool toggle);
signals:
    void boardUpdated();

private slots:
    void updateBoard();

private:
    QTimer *timer;
    QVector<QVector<int>> board;
    Piece currentPiece;

    void clearBoard();
    void updateCurrentPiece();
    bool isLegalMove(int x, int y, const Piece &p);
    void placePiece();
    void checkFullRows();
    void handleCollision();
    bool isRowFull(int row);
    void moveCurrentPieceDown();
    bool isWall = false;
    int currentX;
    int currentY;
};


#endif // BOARD_H
