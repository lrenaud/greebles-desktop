#ifndef SCORE_HISTORY_H
#define SCORE_HISTORY_H

#include <vector>

#include "Score.h"
#include "Constants.h"

using namespace std;

class ScoreHistory
{
private:

    /**
     * A container for the high scores
     */
    vector<Score>*         highScores;

    /**
     * A container for the scores from the last game
     */
    Score*                  lastScores[Constants::LAST_SCORES_COUNT];

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
     * This method will refetch the High Scores from the database and populate the
     * highScores container.
     */
    void ReloadHighScores();

    /**
     * This method does a hard erase on all high scores. It will clear the 
     * highScores container, as well as erase all entries in the database.
     */
    void ZapHighScores();

    void AddHighScore(int id, string& name, unsigned int players, unsigned int level, unsigned long points);

    bool SaveScores();

private:

    /**
     * This method executes a database query to clear the high scores table
     */
    void eraseHighScoresTable();

};

#endif