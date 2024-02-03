#ifndef PIECE_H
#define PIECE_H
#include <QPoint>
#include <QColor>
enum Tetromino
{
    IShape,TShape,squareShape,LShape,revLShape,ZShape,SShape, emptyShape
};


class Piece
{
public:
   Piece();
   void setRandShape();
   Tetromino shape() const;

   int x(int index) const;
   int y(int index) const;
   int xn(int index) const;
   int yn(int index) const;

   int minX() const;
   int maxX() const;
   int minY() const;
   int maxY() const;

   void setX(int index, int val);
   void setY(int index, int val);
   void moveBy(int x, int y);
   Piece rotate();
   Tetromino getNextShape();
   void setShape(Tetromino shape);

private:

   int tabShapes[8][4][2]{
       { {0,0}, {0,1}, {0,2}, {0,3} }, //IShape
       { {0,0}, {1,0}, {2,0}, {1,1} }, //TShape
       { {0,0}, {0,1}, {1,0}, {1,1} }, //squareShape
       { {0,0}, {0,1}, {0,2}, {1,2} }, //LShape
       { {1,0}, {1,1}, {1,2}, {0,2} }, //revLShape
       { {0,0}, {1,0}, {1,1}, {2,1} }, //ZShape
       { {0,1}, {1,1}, {1,0}, {2,0} }, //SShape
       { {0,0}, {0,0}, {0,0}, {0,0} }, //emptyShape
   };

   void setNextShape(Tetromino shape);
   Tetromino pieceShape;
   Tetromino nextShape;
   int tabCoordinates[4][2];
   int tabCoordinatesNext[4][2];
};

#endif // PIECE_H
