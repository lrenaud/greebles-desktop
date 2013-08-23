#include <string>
#include <sstream>

#include <math/Clamp.h>

#include "CustomSettings.h"
#include "GreeblesDatabase.h"

using namespace std;
using namespace SOAR;
using namespace Math;

CustomSettings::CustomSettings()
{
    if (!Refresh())
        setDefaults();
}

CustomSettings::~CustomSettings()
{

}

CustomSettings& CustomSettings::GetInstance()
{
    static CustomSettings instance;

    return instance;
}

bool CustomSettings::Save()
{
    stringstream query;
    query << "UPDATE `customsettings` SET `unlimitedlives`=" << unlimitedLives 
          << ", `startlevel`=" << startLevel << ", `timelimit`=" << timeLimit 
          << ", `playersremain`=" << playersRemaining << ", `advertise`=\"" << advertiseName << "\";";

    if (!GreeblesDB->Query(query.str().c_str()))
        return false;

    GreeblesDB->Done();

    return true;
}

bool CustomSettings::Refresh()
{
    if (!GreeblesDB->QueryData("SELECT * FROM `customsettings` WHERE `id`=1;"))
        return false;

    if (!GreeblesDB->NextRow())
        return false;

    unlimitedLives = GreeblesDB->GetBool(COL_UNLIMITED_LIVES);
    startLevel = GreeblesDB->GetInt(COL_START_LEVEL);
    timeLimit = GreeblesDB->GetInt(COL_TIME_LIMIT);
    playersRemaining = GreeblesDB->GetInt(COL_PLAYERS_REMAINING);
    advertiseName = GreeblesDB->GetString(COL_ADVERTISE);

    GreeblesDB->Done();

    return true;
}

bool CustomSettings::LivesAreUnlimited()const
{
    return unlimitedLives;
}

int CustomSettings::StartLevel()const
{
    return startLevel;
}

int CustomSettings::TimeLimit()const
{
    return timeLimit;
}

int CustomSettings::RemainingPlayers()const
{
    return playersRemaining;
}

const string& CustomSettings::AdvertiseName()const
{
    return advertiseName;
}

void CustomSettings::EnableUnlimitedLives()
{
    unlimitedLives = true;
}

void CustomSettings::DisableUnlimitedLives()
{
    unlimitedLives = false;
}

void CustomSettings::ChangeStartLevel(int newStartLevel)
{
    startLevel = newStartLevel;
    Clamp::Int(startLevel, MIN_START_LEVEL, MAX_START_LEVEL);
}

void CustomSettings::SetTimeLimit(int newTimeLimit)
{
    timeLimit = newTimeLimit;
    Clamp::Int(timeLimit, DISABLED_TIME_LIMIT, MAX_TIME_LIMIT);
}

void CustomSettings::SetRemainingPlayers(int newRemainingPlayers)
{
    playersRemaining = newRemainingPlayers;
    Clamp::Int(playersRemaining, DISABLED_REMAINING_PLAYERS, MAX_REMAINING_PLAYERS);
}

void CustomSettings::SetAdvertiseName(string newAdvertiseName)
{
    advertiseName = newAdvertiseName;
}

void CustomSettings::setDefaults()
{
    unlimitedLives = true;
    startLevel = 2;
    timeLimit = 0;
    playersRemaining = 0;
    advertiseName = "";
}
