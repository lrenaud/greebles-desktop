#include <string>
#include <sstream>

#include <util/Log.h>

#include "Score.h"
#include "Constants.h"
#include "GreeblesDatabase.h"

using namespace std;
using namespace SOAR;

Score::Score()
{
    Reset();
}

Score::~Score()
{

}

int Score::Save()
{
    stringstream query;
    if (id == -1)
    {
        query << "INSERT INTO `score`(`name`, `players`, `level`, `points`) VALUES('";
        query << name << "', '" << players << "', '" << level << "', '" << points << "');";

        if (GreeblesDB->Query(query.str().c_str()))
        {
            GreeblesDB->Done();

            return GreeblesDB->GetIdOfLastInsert();
        }
    }
    else
    {
        query << "UPDATE `score` SET `name`='" << name << "', `players`=" << players << ", ";
        query << "level=" << level << ", points=" << points << " ";
        query << "WHERE `id`=" << id << ";";

        if (GreeblesDB->Query(query.str().c_str()))
        {
            GreeblesDB->Done();

            return id;
        }
    }

    return -1;
}

bool Score::Load(int id)
{
    stringstream query;
    query << "SELECT * FROM `score` WHERE `id`=" << id << ";";

    if (GreeblesDB->Query(query.str().c_str()) && GreeblesDB->NextRow())
    {
        id = GreeblesDB->GetInt(COL_ID);
        name = GreeblesDB->GetString(COL_NAME);
        players = GreeblesDB->GetInt(COL_PLAYERS);
        level = GreeblesDB->GetInt(COL_LEVEL);
        points = GreeblesDB->GetLong(COL_POINTS);

        GreeblesDB->Done();

        return true;
    }

    return false;
}

void Score::Reset()
{
    id = -1;
    name = "";
    players = level = points = 0;
}

void Score::Initialize(int id, string& name, unsigned int players, unsigned int level, unsigned long points)
{
    this->id = id;
    this->name = name.substr(0, Constants::MAX_NAME_LENGTH);
    this->players = players;
    this->level = level;
    this->points = points;
}