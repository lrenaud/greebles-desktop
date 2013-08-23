#include <string>
#include <sstream>

#include "JoinSettings.h"
#include "GreeblesDatabase.h"

using namespace std;
using namespace SOAR;

JoinSettings::JoinSettings()
{
    if (!Refresh())
        setDefaults();
}

JoinSettings::~JoinSettings()
{

}

JoinSettings& JoinSettings::GetInstance()
{
    static JoinSettings instance;

    return instance;
}

bool JoinSettings::Save()
{
    stringstream query;
    query << "UPDATE `joinsettings` SET `host`=\"" << host << "\";";

    if (!GreeblesDB->Query(query.str().c_str()))
        return false;

    GreeblesDB->Done();

    return true;
}

bool JoinSettings::Refresh()
{
    if (!GreeblesDB->QueryData("SELECT * FROM `joinsettings` WHERE `id`=1;"))
        return false;

    if (!GreeblesDB->NextRow())
        return false;

    host = GreeblesDB->GetString(COL_HOST);

    GreeblesDB->Done();

    return true;
}

const string& JoinSettings::Host()const
{
    return host;
}

void JoinSettings::SetHost(string newHost)
{
    host = newHost;
}

void JoinSettings::setDefaults()
{
    host = "";
}
