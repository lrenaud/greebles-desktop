#include <sstream>

#include <Macros.h>
#include <util/Log.h>

#include "PlayerSettings.h"
#include "GreeblesDatabase.h"
#include "ControlSet.h"

using namespace std;
using namespace SOAR;

PlayerSettings::PlayerSettings(int id)
{
    this->id = id;

    if (!load(id))
        setDefaults();

    controlSet = new ControlSet(controlSetId);
}

PlayerSettings::~PlayerSettings()
{
    free();   
}

int PlayerSettings::PlayerTypeId()const
{
    return (int)playerType;
}

bool PlayerSettings::IsHuman()const
{
    return playerType == HUMAN;
}

bool PlayerSettings::IsFriendlyAI()const
{
    return playerType == FRIENDLY_AI;
}

bool PlayerSettings::IsNastyAI()const
{
    return playerType == NASTY_AI;
}

bool PlayerSettings::Enabled()const
{
    return enabled;
}

const string& PlayerSettings::Name()const
{
    return name;
}

ControlSet* PlayerSettings::Controls()
{
    return controlSet;
}

bool PlayerSettings::SetTypeById(int typeId)
{
    if (typeId < HUMAN || typeId > NASTY_AI)
        return false;

    playerType = (PlayerType)typeId;

    return true;
}

void PlayerSettings::Disable()
{
    enabled = false;
}

void PlayerSettings::Enable()
{
    enabled = true;
}

void PlayerSettings::ChangeName(const char* newName)
{
    name = newName;
}

bool PlayerSettings::Save()
{
    stringstream query;
    query << "UPDATE `player` SET `playertypeid`=" << (int)playerType << ", `controlsetid`=" << controlSetId << ", `enabled`=";
    query << enabled;
    query << ", `name`='" << name << "' WHERE `id`=" << id << ";";

    if (GreeblesDB->Query(query.str().c_str()))
    {
        GreeblesDB->Done();
        
        // Save this player's controls as well
        if (controlSet->Save())
            return true;
    }

    return false;
}

void PlayerSettings::free()
{
    SAFE_DELETE(controlSet);
}

bool PlayerSettings::load(int id)
{
    stringstream query;
    query << "SELECT * FROM `player` WHERE `id`=" << id << ";";

    if (GreeblesDB->QueryData(query.str().c_str()) && GreeblesDB->NextRow())
    {
        id = GreeblesDB->GetInt(COL_ID);
        playerType = (PlayerType)GreeblesDB->GetInt(COL_PLAYER_TYPE_ID);
        controlSetId = GreeblesDB->GetInt(COL_CONTROL_SET_ID);
        enabled = GreeblesDB->GetBool(COL_ENABLED);
        name = GreeblesDB->GetString(COL_NAME);

        GreeblesDB->Done();

        return true;
    }

    return false;
}

void PlayerSettings::setDefaults()
{
    id = -1;
    playerType = HUMAN;
    controlSetId = -1;
    enabled = false;
    name = "DEFAULT";
}