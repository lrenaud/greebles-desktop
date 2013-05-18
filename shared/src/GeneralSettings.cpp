#include <sstream>
#include <string>

#include <Log.h>

#include "GeneralSettings.h"
#include "GreeblesDatabase.h"
#include "Macros.h"

using namespace SOAR;

GeneralSettings::GeneralSettings()
{
	if (!refresh())
		setDefaults();
}

GeneralSettings::~GeneralSettings()
{

}

GeneralSettings* GeneralSettings::GetInstance()
{
    static GeneralSettings instance;

    return &instance;
}

bool GeneralSettings::Save()
{
    int diffValue = (int)difficulty;
    int soundValue = soundEnabled ? 1 : 0;
    int musicValue = musicEnabled ? 1 : 0;

    stringstream query;
    query << "UPDATE `generalsettings` SET `difficultyid`=" << diffValue << ", `sound`=" << soundValue << ", `music`=" << musicValue << ";";

    if (!DB->Query(query.str().c_str()))
        return false;

    return true;
}

bool GeneralSettings::refresh()
{
    if (!DB->QueryData("SELECT * FROM `generalsettings` WHERE `id`=1;"))
   		return false;

   	if (!DB->NextRow())
   		return false;

    difficulty = (DifficultyLevel)DB->GetInt(COL_DIFFICULTY);
    soundEnabled = DB->GetBool(COL_SOUND);
    musicEnabled = DB->GetBool(COL_MUSIC);

    if (!DB->QueryData("SELECT * FROM `difficulty`;"))
        return false;

    difficultyStrs.clear();
    while (DB->NextRow())
    {
        DifficultyLevel diffLevel = (DifficultyLevel)DB->GetInt(COL_DIFFICULTY_ID);

        // The reinterpret_cast here could chop off data if anything more than ASCII text 
        // was in the database, but greebles will not do that for difficulty levels.
        difficultyStrs[diffLevel] = reinterpret_cast<const char*>(DB->GetText(COL_DIFFICULTY_TEXT));
    }

    return true;
}

void GeneralSettings::setDefaults()
{
    soundEnabled = true;
    musicEnabled = true;
    difficulty = DL_NORMAL;

    difficultyStrs.clear();
    difficultyStrs[DL_EASY] = "Easy";
    difficultyStrs[DL_NORMAL] = "Normal";
    difficultyStrs[DL_HARD] = "Hard";
    difficultyStrs[DL_SUICIDAL] = "Suicidal";
}
