#include <map>
#include <string>
#include <sstream>

#include <util/Log.h>

#include "StaticLookup.h"
#include "GreeblesDatabase.h"

using namespace std;
using namespace SOAR;

StaticLookup::StaticLookup(const char* tableName, int keyIdx, int valueIdx)
{
    initialize(tableName, keyIdx, valueIdx);
}

StaticLookup::~StaticLookup()
{
    pairs.clear();
}

string& StaticLookup::GetValue(int key)
{
    return pairs[key];
}

bool StaticLookup::KeyExists(int key)
{
    return pairs.find(key) != pairs.end();
}

void StaticLookup::initialize(const char* tableName, int keyIdx, int valueIdx)
{
    pairs.clear();

    stringstream query;
    query << "SELECT * FROM `" << tableName << "`;";

    if (GreeblesDB->QueryData(query.str().c_str()))
    {
        while (GreeblesDB->NextRow())
            pairs[GreeblesDB->GetInt(keyIdx)] = GreeblesDB->GetString(valueIdx);

        GreeblesDB->Done();
    }
    else
        LOG_RECOVERABLE << "StaticLookup query failed";
}