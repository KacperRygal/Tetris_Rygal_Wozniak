#include "score.h"

Score::Score()
{
    actualScore=0;
    currentLevel=0;
}


void Score::addPointsByDeletedRows(int deletedRows)
{
    int temp=0;
    switch(deletedRows)
    {
        case 1:
            temp = 40 * (currentLevel + 1);
            break;
        case 2:
            temp = 100 * (currentLevel + 1);
            break;
        case 3:
            temp = 300 * (currentLevel + 1);
            break;
        case 4:
            temp = 1200 * (currentLevel + 1);
            break;
    }
    actualScore+=temp;
}

int Score::getScore()
{
    return actualScore;
}

int Score::getCurrentLevel()
{
    return currentLevel;
}

void Score::updateCurrentLevel()
{
    currentLevel++;
}
