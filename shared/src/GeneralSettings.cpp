#include "../inc/GeneralSettings.h"
#include "../inc/GreeblesDatabase.h"
#include "../inc/Macros.h"

GeneralSettings::GeneralSettings()
{

}

GeneralSettings::~GeneralSettings()
{

}

bool GeneralSettings::refresh()
{
    GreeblesDatabase::GetInstance()->QueryData("SELECT * FROM `globalsettings` WHERE `id`=1;");
    
    return false;
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
    difficultyStr = "Normal";
}
