#include <sstream>
#include <string>

#include <util/Log.h>

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

    if (!GreeblesDB->Query(query.str().c_str()))
        return false;

    GreeblesDB->Done();

    return true;
}

bool GeneralSettings::Refresh()
{
    if (!GreeblesDB->QueryData("SELECT * FROM `generalsettings` WHERE `id`=1;"))
        return false;

    if (!GreeblesDB->NextRow())
        return false;

    difficulty = (DifficultyLevel)GreeblesDB->GetInt(COL_DIFFICULTY);
    soundEnabled = GreeblesDB->GetBool(COL_SOUND);
    musicEnabled = GreeblesDB->GetBool(COL_MUSIC);

    GreeblesDB->Done();

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
