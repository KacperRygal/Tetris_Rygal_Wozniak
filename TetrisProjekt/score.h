#ifndef SCORE_H
#define SCORE_H


class Score
{
public:
    Score();
    void reset();
    void addPointsByDeletedRows(int deletedRows);
    int getScore();
    int getCurrentLevel();
    void updateCurrentLevel();
private:
    int actualScore;
    int currentLevel;
};

#endif // SCORE_H
