#include <string>
#include <sstream>

#include "LocalHumanStringFormatter.h"

using namespace std;

string LocalHumanStringFormatter::GetInfoStr(int localPlayers, int humanPlayers)
{
    stringstream infoStream;
    infoStream << "There ";

    if (localPlayers == 1)
        infoStream << "is";
    else
        infoStream << "are";

    infoStream << " " << localPlayers << " local players (";

    if (humanPlayers == 0)
        infoStream << "none";
    else if (humanPlayers == localPlayers)
        infoStream << "all";
    else
        infoStream << humanPlayers;

    infoStream << " human)";

    return infoStream.str();
}