#include <sstream>
#include <string>

#include <Macros.h>

#include "ScoreHistory.h"
#include "Score.h"
#include "Constants.h"
#include "GreeblesDatabase.h"

ScoreHistory::ScoreHistory()
{
    highScores = new vector<Score>();
    highScores->clear();

    for (int s=0; s<Constants::LAST_SCORES_COUNT; s++)
        lastScores[s] = new Score();
}

ScoreHistory::~ScoreHistory()
{
    for (int s=0; s<Constants::LAST_SCORES_COUNT; s++)
        SAFE_DELETE(lastScores[s]);

    SAFE_DELETE(highScores);
}

ScoreHistory& ScoreHistory::GetInstance()
{
    static ScoreHistory instance;

    return instance;
}

void ScoreHistory::ReloadHighScores()
{

}

void ScoreHistory::ZapHighScores()
{
    highScores->clear();
    eraseHighScoresTable();
}

void ScoreHistory::AddHighScore(int id, string& name, unsigned int players, unsigned int level, unsigned long points)
{
    
}

bool ScoreHistory::SaveScores()
{

    return false;
}

void ScoreHistory::eraseHighScoresTable()
{
    stringstream query;
    query << "DELETE FROM `highscore`;";
    GreeblesDB->Query(query.str().c_str());
}