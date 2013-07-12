#include <sstream>
#include <string>

#include <Log.h>

#include "GeneralSettings.h"
#include "GreeblesDatabase.h"
#include "DifficultyLookup.h"

using namespace SOAR;

GeneralSettings::GeneralSettings()
{
	if (!Refresh())
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

    DB->Done();

    return true;
}

bool GeneralSettings::Refresh()
{
    if (!DB->QueryData("SELECT * FROM `generalsettings` WHERE `id`=1;"))
        return false;

    if (!DB->NextRow())
        return false;

    difficulty = (DifficultyLevel)DB->GetInt(COL_DIFFICULTY);
    soundEnabled = DB->GetBool(COL_SOUND);
    musicEnabled = DB->GetBool(COL_MUSIC);

    DB->Done();

    return true;
}

bool GeneralSettings::DifficultyIsEasy()const
{
    return difficulty == DL_EASY;
}

bool GeneralSettings::DifficultyIsNormal()const
{
    return difficulty == DL_NORMAL;
}

bool GeneralSettings::DifficultyIsHard()const
{
    return difficulty == DL_HARD;
}

bool GeneralSettings::DifficultyIsSuicidal()const
{
    return difficulty == DL_SUICIDAL;
}

int GeneralSettings::DifficultyLevelInt()const
{
    return (int)difficulty;
}

bool GeneralSettings::SoundEnabled()const
{
    return soundEnabled;
}

bool GeneralSettings::MusicEnabled()const
{
    return musicEnabled;
}

void GeneralSettings::ChooseDifficulty(int difficultyLevel)
{
    if (!DL->KeyExists(difficultyLevel))
    {
        LOG_WARNING << "Invalid difficulty level specified in ChooseDifficulty: " << difficultyLevel;
        return;
    }

    difficulty = (DifficultyLevel)difficultyLevel;
}

void GeneralSettings::EnableSound()
{
    soundEnabled = true;
}

void GeneralSettings::EnableMusic()
{
    musicEnabled = true;
}

void GeneralSettings::DisableSound()
{
    soundEnabled = false;
}

void GeneralSettings::DisableMusic()
{
    musicEnabled = false;
}

void GeneralSettings::setDefaults()
{
    soundEnabled = true;
    musicEnabled = true;
    ChooseDifficulty(DL_NORMAL);
}
