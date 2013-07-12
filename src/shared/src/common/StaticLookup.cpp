#include <map>
#include <string>
#include <sstream>

#include <Log.h>

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

    if (DB->QueryData(query.str().c_str()))
    {
        while (DB->NextRow())
            pairs[DB->GetInt(keyIdx)] = DB->GetString(valueIdx);

        DB->Done();
    }
    else
        LOG_RECOVERABLE << "StaticLookup query failed";
}