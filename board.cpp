#include "board.h"
#include <QDebug>
Board::Board(QObject *parent) : QObject(parent), timer(new QTimer(this)), board(HeightBoard, QVector<int>(WidthBoard, 0))
{
    currentPiece.setRandShape();
    connect(timer,&QTimer::timeout,this,&Board::updateBoard);
    timer->setInterval(200);
    start();
}

void Board::updateBoard(){
    moveCurrentPieceDown();
    emit boardUpdated();
}

Board::~Board()
{
    delete timer;
}

void Board::start()
{
    timer->start();
    updateCurrentPiece();
    placePiece();
}

void Board::reset()
{
    timer->stop();
    clearBoard();
    start();
}

void Board::pause()
{
    timer->stop();
}

void Board::clearBoard()
{
    for(int i=0;i<HeightBoard;i++){
        for(int j=0;j<WidthBoard;j++)
            board[i][j]=0;
    }
    emit boardUpdated();
}

void Board::moveCurrentPieceDown()
{
    qInfo() << "MoveDown";
    if(isLegalMove(currentY+1,currentX,currentPiece))
    {
        for (int i = 0; i < 4; i++)
        {
            board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 0;
        }
        currentPiece.moveBy(0, 1);
        for (int i = 0; i < 4; i++)
        {
            board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 1;
        }
    }
    else
        handleCollision();
}

void Board::updateCurrentPiece()
{
    isWall=false;
    currentPiece.setRandShape();

}

bool Board::isLegalMove(int curY, int curX, const Piece &p)
{
    for (int i=0;i<4;i++)
    {
        int y = curY + p.y(i);
        int x = curX + p.x(i);
        if(x < 0 || x >= WidthBoard)
        {
            qInfo()<<"Nielegalny - poza zakresem tablicyX";
            isWall=true;
            return false;
        }
        if(y < 0 || y >= HeightBoard)
        {
            qInfo()<<"Nielegalny - poza zakresem tablicyY";
            isWall=false;
            return false;
        }


        if (board[y][x] == 1)
        {
            bool isCellOccupiedByCurrentPiece = false;
            for (int j = 0; j < 4; j++)
            {
                if (currentY + p.y(j) == y && currentX + p.x(j) == x)
                {
                    isCellOccupiedByCurrentPiece = true;
                    break;
                }
            }
            if (!isCellOccupiedByCurrentPiece)
            {
                qInfo() << "Nielegalny - komórka zajęta";
                isWall=false;
                return false;
            }
        }
    }
    return true;
}

void Board::placePiece()
{
    qInfo() << "PlacePiece";
    currentX = 0;
    currentY = 0;

    qInfo() << "X:"<<currentX ;
    qInfo() << "Y:"<<currentY;
    if(isLegalMove(currentY,currentX,currentPiece))
    {
        for (int i=0;i<4;i++)
        {
            int y = currentY + currentPiece.y(i);
            int x = currentX + currentPiece.x(i);
            board[y][x]=1;
        }
    }
    else
    {
        handleCollision();
        return;
    }

    checkFullRows();

}

void Board::handleCollision()
{
    qInfo() << "HandleCollision";


    if(!isWall)
    {
        if(currentY + currentPiece.minY() <= 0)
            {
                reset();
                return;
            }
        for (int i=0;i<4;i++)
        {
            int y = currentY + currentPiece.y(i);
            int x = currentX + currentPiece.x(i);
            board[y][x]=1;
        }

        checkFullRows();
        updateCurrentPiece();
    }



}

void Board::checkFullRows()
{
    QVector<int> fullRows;
    for(int i=0;i<HeightBoard;i++)
    {
        if (isRowFull(i))
        {
            fullRows.append(i);
        }
    }
    for (int i = fullRows.size() - 1; i >= 0; i--)
        {
            int row = fullRows[i];
            board.remove(row);
            board.prepend(QVector<int>(WidthBoard, 0));
        }
        emit boardUpdated();
}

bool Board::isRowFull(int row)
{
    for (int col = 0; col < WidthBoard; col++)
        {
            if (board[row][col] == 0)
            {
                return false;
            }
        }
        return true;
}

int Board::getValue(int row, int col)
{
    return board[row][col];
}
Tetromino Board::getCurrentTetromino()
{
    return currentPiece.shape();
}

Piece Board::getCurrentPiece()
{
    return currentPiece;
}

void Board::moveCurrentPieceSides(int x)
{
    qInfo() << "MoveSide";
    if(isLegalMove(currentY,currentX+x,currentPiece))
    {
        for (int i = 0; i < 4; i++)
        {
            board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 0;
        }
        currentPiece.moveBy(x, 0);
        for (int i = 0; i < 4; i++)
        {
            board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 1;
        }
    }
    else
        handleCollision();
}
void Board::rotateCurrentPiece(bool toggle)
{
    qInfo() << "Rotate";

        Piece rotatedPiece = currentPiece;
        bool temp = isLegalMove(currentY,currentX,rotatedPiece.rotate());

        if(temp)
        {
            for (int i = 0; i < 4; i++)
            {
                board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 0;
            }

            currentPiece=currentPiece.rotate();

            for (int i = 0; i < 4; i++)
            {
                board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 1;
            }
        }
        else
        {
        handleCollision();
        }

    checkFullRows();
}
