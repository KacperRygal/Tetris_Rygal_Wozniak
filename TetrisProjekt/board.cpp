#include "board.h"
#include <QDebug>
Board::Board(QObject *parent) : QObject(parent), timer(new QTimer(this)), board(HeightBoard, QVector<int>(WidthBoard, 0)),
    colorBoard(HeightBoard, QVector<Tetromino>(WidthBoard, Tetromino::emptyShape))
{
    currentPiece.setRandShape();
    connect(timer,&QTimer::timeout,this,&Board::updateBoard);
    timer->setInterval(500);
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
        {
            board[i][j]=0;
            colorBoard[i][j]=Tetromino::emptyShape;
        }
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
            colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = Tetromino::emptyShape;
        }
        currentPiece.moveBy(0, 1);
        for (int i = 0; i < 4; i++)
        {
            board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 1;
            colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = getCurrentTetromino();
        }
    }
    else
        handleCollision();
    emit boardUpdated();
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
            if(y < 0 && board[y][x] == 1);
            else
            {
                qInfo()<<"Nielegalny - poza zakresem tablicyY";
                isWall=false;
                return false;
            }
        }


        if (board[y][x] == 1 || board[y][x] == 2)
        {
            bool isCellOccupiedByCurrentPiece = false;
            for (int j = 0; j < 4; j++)
            {
                if (currentY + p.y(j) == y && currentX + p.x(j) == x && board[y][x] == 1)
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
    currentX = WidthBoard/2;
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
            colorBoard[y][x]=getCurrentTetromino();
        }
    }
    else
    {
        handleCollision();
        return;
    }

    emit boardUpdated();

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
            board[y][x]=2;
            colorBoard[y][x] = getCurrentTetromino();
            qInfo()<<colorBoard[y][x];
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
    for (int i = 0; i < fullRows.size(); i++)
        {
        qInfo()<<"Tutaj usuwa sie po raz:"<<i;
            int row = fullRows[i];
            board.remove(row);
            colorBoard.remove(row);
            board.prepend(QVector<int>(WidthBoard, 0));
            colorBoard.prepend(QVector<Tetromino>(WidthBoard, Tetromino::emptyShape));
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

Tetromino Board::getColorBoard(int row, int col)
{
    return colorBoard[row][col];
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
            colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = Tetromino::emptyShape;
        }
        currentPiece.moveBy(x, 0);
        for (int i = 0; i < 4; i++)
        {
            board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 1;
            colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = getCurrentTetromino();
        }
    }
    else
        handleCollision();
    emit boardUpdated();
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
                colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = Tetromino::emptyShape;
            }

            currentPiece=currentPiece.rotate();

            for (int i = 0; i < 4; i++)
            {
                board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 1;
                colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = getCurrentTetromino();
            }
        }
        else
        {
        handleCollision();
        }

    emit boardUpdated();
}


