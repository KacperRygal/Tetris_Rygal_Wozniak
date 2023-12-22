#include "piece.h"
#include <QRandomGenerator>
#include <QPoint>
#include <QVector>
#include <QDebug>
Piece::Piece()
{
    setRandShape();
}

int Piece::maxX() const
{
    int max = tabCoordinates[0][0];
    for(int i=1;i<4;i++)
        max = qMax(max, tabCoordinates[i][0]);
    return max;
}

int Piece::minX() const
{
    int min = tabCoordinates[0][0];
    for(int i=1;i<4;i++)
        min = qMin(min,tabCoordinates[i][0]);
    return min;
}

int Piece::maxY() const
{
    int max = tabCoordinates[0][1];
    for(int i=1;i<4;i++)
        max = qMax(max, tabCoordinates[i][1]);
    return max;
}

int Piece::minY() const
{
    int min = tabCoordinates[0][1];
    for(int i=1;i<4;i++)
        min = qMin(min,tabCoordinates[i][1]);
    return min;
}

void Piece::setRandShape()
{
    setShape(Tetromino(QRandomGenerator::global()->bounded(0,7)));
}

void Piece::setX(int index, int val)
{
    if(index>=0 && index<=3) tabCoordinates[index][0]=val;
}

void Piece::setY(int index, int val)
{
    if(index>=0 && index<=3) tabCoordinates[index][1]=val;
}

int Piece::x(int index) const
{
    return tabCoordinates[index][0];
}

int Piece::yn(int index) const
{
    return tabCoordinatesNext[index][1];
}

int Piece::xn(int index) const
{
    return tabCoordinatesNext[index][0];
}

int Piece::y(int index) const
{
    return tabCoordinates[index][1];
}

Tetromino Piece::shape() const
{
    return pieceShape;
}

Tetromino Piece::getNextShape()
{
    return nextShape;
}

void Piece::moveBy(int x, int y)
{
    //qInfo()<<"Ruszam";
    for(int i=0;i<4;i++)
    {
        setX(i,this->x(i)+x);
        setY(i,this->y(i)+y);
    }
}

void Piece::setShape(Tetromino shape)
{
    //qInfo() << shape;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
            tabCoordinates[i][j] = tabShapes[shape][i][j];
    }
    pieceShape=shape;
    setNextShape(Tetromino(QRandomGenerator::global()->bounded(0,7)));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
            tabCoordinatesNext[i][j] = tabShapes[getNextShape()][i][j];
    }
}



Piece Piece::rotate()
{
    //qInfo()<<"RotLewo";
    if (pieceShape == squareShape)
            return *this;

        Piece result(*this);

        int px = (result.maxX() + result.minX()) / 2;
        int py = (result.maxY() + result.minY()) / 2;
        //qInfo()<<"Px:"<<px<<" Py:"<<py;
        for (int i = 0; i < 4; i++)
        {
            int x = result.x(i);
            int y = result.y(i);

            int newX = px - (y - py);
            int newY = py + (x - px);

            result.setX(i, newX);
            result.setY(i, newY);
        }

        int xCor = px - (result.maxX() + result.minX()) / 2;
        int yCor = py - (result.maxY() + result.minY()) / 2;

        for (int i = 0; i < 4; i++)
        {
            result.setX(i, result.x(i) + xCor);
            result.setY(i, result.y(i) + yCor);
        }

        return result;
}

void Piece::setNextShape(Tetromino shape)
{
    nextShape=shape;
}

