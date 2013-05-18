#include "../inc/GeneralSettings.h"
#include "../inc/GreeblesDatabase.h"
#include "../inc/Macros.h"

GeneralSettings::GeneralSettings()
{
	if (!refresh())
		setDefaults();
}

GeneralSettings::~GeneralSettings()
{

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

bool GeneralSettings::save()
{
    int diffValue = (int)difficulty;
    int soundValue = soundEnabled ? 1 : 0;
    int musicValue = musicEnabled ? 1 : 0;

    string query = "UPDATE `generalsettings` SET `difficultyid`=";
    query += diffValue;
    query += ", `sound`=";
    query += soundValue;
    query += ", `music`=";
    query += musicValue;
    query += ";";

	if (!DB->Query(query.c_str()))
        return false;

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
