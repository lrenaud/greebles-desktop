#include <sstream>

#include <GLFW/glfw3.h>

#include <Log.h>

#include "ControlSet.h"
#include "AllowedKeys.h"
#include "GreeblesDatabase.h"

using namespace std;
using namespace SOAR;

ControlSet::ControlSet(int controlSetId)
{
    this->id = controlSetId;

    if (!load(id))
    {
        setDefaults();
        LOG_RECOVERABLE << "Control Set #" << id << " failed to load";
    }
}

ControlSet::~ControlSet()
{

}

int ControlSet::LeftKey() const
{
    return directions[LEFT];
}

int ControlSet::RightKey() const
{
    return directions[RIGHT];
}

int ControlSet::UpKey() const
{
    return directions[UP];
}

int ControlSet::DownKey() const
{
    return directions[DOWN];
}

int ControlSet::PushKey() const
{
    return push;
}

bool ControlSet::SetLeftKey(int newKey)
{
    return setKey(LEFT, newKey);
}

bool ControlSet::SetRightKey(int newKey)
{
    return setKey(RIGHT, newKey);
}

bool ControlSet::SetUpKey(int newKey)
{
    return setKey(UP, newKey);
}

bool ControlSet::SetDownKey(int newKey)
{
    return setKey(DOWN, newKey);
}

bool ControlSet::SetPushKey(int newKey)
{
    if (!KEY_ALLOWED(newKey))
        return false;

    push = newKey;

    return true;
}

bool ControlSet::Save()
{
    stringstream query;
    query << "UPDATE `controlset` SET `left`=" << directions[LEFT] << ", ";
    query << "`right`=" << directions[RIGHT] << ", ";
    query << "`up`=" << directions[UP] << ", ";
    query << "`down`=" << directions[DOWN] << ", ";
    query << "`push`=" << push << " ";
    query << "WHERE `id`=" << id << ";";

    if (DB->Query(query.str().c_str()))
    {
        DB->Done();
        return true;
    }

    return false;
}

int ControlSet::getKey(Direction dir) const
{
    return directions[dir];
}

bool ControlSet::setKey(Direction dir, int newKey)
{
    if (!KEY_ALLOWED(newKey))
        return false;

    directions[dir] = newKey;

    return true;
}

bool ControlSet::load(int id)
{
    stringstream query;
    query << "SELECT * FROM `controlset` WHERE `id`=" << id << ";";

    if (DB->QueryData(query.str().c_str()) && DB->NextRow())
    {
        id = DB->GetInt(COL_ID);
        directions[LEFT] = DB->GetInt(COL_LEFT);
        directions[RIGHT] = DB->GetInt(COL_RIGHT);
        directions[UP] = DB->GetInt(COL_UP);
        directions[DOWN] = DB->GetInt(COL_DOWN);
        push = DB->GetInt(COL_PUSH);

        DB->Done();

        return true;
    }

    return false;
}

void ControlSet::setDefaults()
{
    directions[LEFT]    = GLFW_KEY_LEFT;
    directions[RIGHT]   = GLFW_KEY_RIGHT;
    directions[UP]      = GLFW_KEY_UP;
    directions[DOWN]    = GLFW_KEY_DOWN;
    push                = GLFW_KEY_SPACE;
}