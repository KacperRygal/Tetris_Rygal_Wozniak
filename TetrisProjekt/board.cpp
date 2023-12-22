#include "board.h"
#include <QDebug>
Board::Board(QObject *parent) : QObject(parent), timer(new QTimer(this)), board(HeightBoard, QVector<int>(WidthBoard, 0)),
    nextPieceBoard(4, QVector<int>(4, 0)), colorBoard(HeightBoard, QVector<Tetromino>(WidthBoard, Tetromino::emptyShape))
{
    currentPiece.setRandShape();
    connect(timer,&QTimer::timeout,this,&Board::updateBoard);
    timer->setInterval(400);
    start();
}

//aktualizacja tablicy
void Board::updateBoard(){
    moveCurrentPieceDown();
    emit boardUpdated();
}

//destruktor
Board::~Board()
{
    delete timer;
}

//wyzwolenie startu
void Board::start()
{
    timer->start();
    updateCurrentPiece();
    placePiece();
}

//wyzwolenie resetu
void Board::reset()
{
    timer->stop();
    clearBoard();
    start();
}

//wyzwolenie pauzy
void Board::pause()
{
    timer->stop();
}

//
void Board::setTimerInterval(int time){
    if(timer->interval()!=time)
    {
        qInfo()<<"zmieniam czas";
        timer->setInterval(time);
    }
}

//wyczysc plansze
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

//przesuniecie klocka w dol
void Board::moveCurrentPieceDown()
{
    Piece movedPiece = currentPiece;
    movedPiece.moveBy(0,1);
    bool temp = isLegalMove(currentY,currentX,movedPiece);
    //qInfo() << "MoveDown";
    if(temp)
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

//przesuniecie klocka na dol instant
void Board::moveCurrentPieceInstantDown(){
    qInfo()<<"Zaczynam przesuwanie w dol";
    bool x=true;
    int m=1;
    while(x){
        qInfo()<<"Aktualne m:"<<m;
        Piece movedPiece = currentPiece;
        movedPiece.moveBy(0,m);
        bool temp = isLegalMove(currentY,currentX,movedPiece);
        if(temp)
        {
            qInfo()<<"Aktualizuje m";
            m++;
        }
        else
        {
            qInfo()<<"Wykrylem max";
            x=false;
        }
    }
    m--;
    for (int i = 0; i < 4; i++)
    {
        qInfo()<<"czyszcze";
        board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 0;
        colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = Tetromino::emptyShape;
    }
    currentPiece.moveBy(0, m);
    for (int i = 0; i < 4; i++)
    {
        qInfo()<<"rysuje nowe";
        board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 1;
        colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = getCurrentTetromino();
    }
    handleCollision();
    emit boardUpdated();

}

//aktualizacja klocka
void Board::updateCurrentPiece()
{
    isWall=false;
    currentPiece.setShape(currentPiece.getNextShape());
    nextPieceColor=currentPiece.getNextShape();
    updateNextPiece();
}

void Board::updateNextPiece()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        {
            nextPieceBoard[i][j]=0;
        }
    }
    for (int i=0;i<4;i++)
    {
        nextPieceBoard[currentPiece.yn(i)][currentPiece.xn(i)] = 1;
    }
}

//sprawdzenie legalnosci ruchu

/*
 * Funkcja dostaje obecny X i obecny Y przechowywany jako miejsce w board oraz instancje klasy Piece. Chodzi o to ze,
 * curY i curX mają za zadanie przechować pozycje startową klocka - czyli x to połowa szerokosci tablicy, a y to 0. Instancja klasy Piece odpowiada
 * nam za reprezentacje 4 punktow kazdego klocka. Teoretycznie mozna to zrobic w jednej klasie ale potrzebne nam klasy. Instancja Piece jest
 * za każdym razem przesyłana jako tymczasowa, żeby nie naruszać orginalnego polozenia klocka na planszy. Po przejsciu legalnosci danego ruchu
 * poszczegolne funkcje (ruch w bok, w dol, rotacja) ustawiaja currentPiece na wartosci po przeksztalceniu sprawdzonym funkcja isLegalMove.
 * Co robi funkcja w punktach(dopisane w odpowiednich miejscach komentarzem z liczebnikiem):
   1. Wszystko wykonuje sie w petli for do 4(tyle mamy poszczegolnych 4 kwadratow skladajacych sie na klocek.
   2. Tworzymy zmienna y i x - przechowują nam one obecne polozenie danego kwadratu (OBECNE CZYLI PO PRZEKSZTALCENIU)
   3. Sprawdzamy czy PRZEKSZTALCONE(np przez rotacje) x jest w granicach naszej tablicy, jedli nie to ustawiamy flage isWall na prawda i zwracamy
     brak legalnosci ruchu (flage wytlumaczona w funkcji handle collision)
   4. Sprawdzamy czy PRZEKSZTALCONE y jest w granicach, tutaj musimy rozdzielic to na sprawdzenie osobno gornej i dolnej granicy.
     Dzieki temu ustawiamy odpowiednio flage isWall i zwracamy false
   5. Sprawdzamy czy pozycja w tablicy PRZEKSZTALCONYCH x i y jest zajeta przez jakiś bloczek (1 - w ruchu, 2 - staly)
   6. Sprawdzamy czy blok jest staly(2) i czy klocek BEZ PRZEKSZTALCENIA(stad currentPiece, a nie przeslany do funkcji Piece p)
      ma maksymalna wartosc Y mniejsza badz rowna 19 - chodzi o sprawdzenie czy pod nim jest dostepne puste pole
   7. I tutaj mozna by uproscic, ale narazie mi sie nie chce. Sprawdzamy dla kazdego kwadratu(petla for do 4) czy tablica w miejscu ponizej klocka
      BEZ PRZEKSZTALCENIA jest zajeta, czy jest pusta
   8. Jesli cos jest to ustawiam flage isBlankSpaceBelow na false i breakuje całego for-a (skoro w jednym miejscu nie ma wolnego miejsca to reszta niewazna)
      A jesli wszystkie pola pod są dostepne to wtedy flaga jest true
   9. Analogicznie dzialajacy for - zamiast sprawdzac miejsce ponizej sprawdzam aktualne polozenie klocka. Sluzy to wykryciu czy klocek jest
      aktualnie w ruchu. Analogicznie ustawiam odpowiednia flage
   10. Sprawdzam czy pola ponizej puste, jesli tak flaga sciany na true, potem dosprawdzam czy to obecny klocek
   11. Jesli obie flagi to falsz to flaga isWall na false
   12. Jesli ruch legalny i przeszedl wszystkie punkty to zwracam true
 */
bool Board::isLegalMove(int curY, int curX, const Piece &p)
{
    for (int i=0;i<4;i++) //1.
    {
        int y = curY + p.y(i);  //2.
        int x = curX + p.x(i);

        if(x < 0 || x >= WidthBoard) //3.
        {
            isWall=true;
            return false;
        }
        if(y < 0 || y >= HeightBoard) //4.
        {
            if (y < 0) isWall = true;
            else isWall = false;

            return false;
        } 

        if (board[y][x] == 1 || board[y][x] == 2) //5.
        {
            bool isBlankSpaceBelow = false;
            if(board[y][x]==2 && currentPiece.maxY()+1<=19) //6.
            {
                for (int j = 0; j < 4; j++)
                {
                    if (board[currentY+currentPiece.y(j)+1][currentX+currentPiece.x(j)]==2) //7.
                    {
                        isBlankSpaceBelow = false;
                        break; //8.
                    }
                    isBlankSpaceBelow = true;
                }

            }
            bool isCellOccupiedByCurrentPiece = false;
            for (int j = 0; j < 4; j++)
            {
                if (currentY + p.y(j) == y && currentX + p.x(j) == x && board[y][x] == 1) //.9
                {
                    isCellOccupiedByCurrentPiece = true;
                    break;
                }

            }

            if(isBlankSpaceBelow) //10.
            {
                isWall=true;
                if(!isCellOccupiedByCurrentPiece) return false;
            }
            if (!isCellOccupiedByCurrentPiece && !isBlankSpaceBelow) //11.
            {
                    isWall=false;
                    return false;
            }
        }
    }
    return true; //12.
}

//polozenie klocka
void Board::placePiece()
{
    //qInfo() << "PlacePiece";
    currentX = WidthBoard/2;
    currentY = 0;

    //qInfo() << "X:"<<currentX ;
    //qInfo() << "Y:"<<currentY;
    if(isLegalMove(currentY,currentX,currentPiece))
    {
        for (int i=0;i<4;i++)
        {
            board[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = 1;
            nextPieceBoard[currentPiece.yn(i)][currentPiece.xn(i)] = 1;
            nextPieceColor=currentPiece.getNextShape();
            colorBoard[currentY + currentPiece.y(i)][currentX + currentPiece.x(i)] = getCurrentTetromino();
        }
    }
    else
    {
        handleCollision();
        return;
    }
    emit boardUpdated();
}

//wykrycie kolizji
void Board::handleCollision()
{
    //qInfo() << "HandleCollision";
    //Ta flaga jesli ustawiona na true nie wykrywa kolizji, dzieki temu ruch w sciane tablic, lub w sciane jakiegos bloku jesli pod spodem
    //jest pusta komorka pozwala na ruch - nie ustawia pol na 2, nie generuje nowego bloku etc.
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
        }
        checkFullRows();
        updateCurrentPiece();
    }

}

//sprawdzenie pelnych linii
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
        //qInfo()<<"Tutaj usuwa sie po raz:"<<i;
            int row = fullRows[i];
            board.remove(row);
            colorBoard.remove(row);
            board.prepend(QVector<int>(WidthBoard, 0));
            colorBoard.prepend(QVector<Tetromino>(WidthBoard, Tetromino::emptyShape));
        }
        emit boardUpdated();
}

//sprawdzenie czy linia pelna
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


//zwrocenie wartosci w tablicy
int Board::getValue(int row, int col)
{
    return board[row][col];
}

int Board::getNextPieceValue(int row, int col)
{
    return nextPieceBoard[row][col];
}

Tetromino Board::getNextPieceColor()
{
    return nextPieceColor;
}

//zwrocenie wartosci koloru w tablicy
Tetromino Board::getColorBoard(int row, int col)
{
    return colorBoard[row][col];
}

//zwrocenie aktualnego ksztaltu klocka
Tetromino Board::getCurrentTetromino()
{
    return currentPiece.shape();
}

//zwrocenie aktualnego klocka
Piece Board::getCurrentPiece()
{
    return currentPiece;
}

//przesuwanie klocka na boki
void Board::moveCurrentPieceSides(int x)
{
    Piece movedPiece = currentPiece;
    movedPiece.moveBy(x,0);
    bool temp = isLegalMove(currentY,currentX,movedPiece);
    //() << "MoveSide";
    if(temp)
    {
        if(!isWall)
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
    }
    else
        handleCollision();
    isWall=false;
    emit boardUpdated();
}

//obrot klocka
void Board::rotateCurrentPiece(bool toggle)
{
    //qInfo() << "Rotate";

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



