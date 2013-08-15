#ifndef SCORE_HISTORY_H
#define SCORE_HISTORY_H

#include <vector>

using namespace std;

class ScoreHistory
{
private:

    /**
     * Constructor allocates memory for all the scores
     */
    ScoreHistory();

public:

    /**
     * Destructor cleans up memory
     */
    ~ScoreHistory();

    /**
     * Singleton Access Method
     */
    static ScoreHistory& GetInstance();

    /**
     * This method does a hard erase on all high scores. It will clear the 
     * highScores container, as well as erase all entries in the database.
     */
    void ZapHighScores();

private:

    /**
     * This method executes a database query to clear the high scores table
     */
    void eraseHighScoresTable();

};

#endif