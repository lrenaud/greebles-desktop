#include <algorithm>
#include <sstream>
#include <string>

#include <Macros.h>

#include "ScoreHistory.h"
#include "GreeblesDatabase.h"

using namespace std;

ScoreHistory::ScoreHistory()
{

}

ScoreHistory::~ScoreHistory()
{

}

ScoreHistory& ScoreHistory::GetInstance()
{
    static ScoreHistory instance;

    return instance;
}

void ScoreHistory::ZapHighScores()
{
    eraseHighScoresTable();
}

void ScoreHistory::eraseHighScoresTable()
{
    stringstream query;
    query << "DELETE FROM `highscore`;";
    GreeblesDB->Query(query.str().c_str());
}
