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
        difficultyStrs[diffLevel] = reinterpret_cast<const char*>(DB->GetText(COL_DIFFICULTY_TEXT));
    }

    return true;
}

bool GeneralSettings::save()
{
	return false;
}

void GeneralSettings::setDefaults()
{
    soundEnabled = true;
    musicEnabled = true;
    difficulty = DL_NORMAL;
}
