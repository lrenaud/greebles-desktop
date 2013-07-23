
#include <Macros.h>
#include <db/Database.h>
#include <util/Log.h>

#include "GreeblesDatabase.h"

using namespace SOAR;

GreeblesDatabase::GreeblesDatabase():Database("greebles.db", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE)
{
    if (QueryData("SELECT COUNT(*) FROM sqlite_master WHERE type='table';") && 
        NextRow() &&
        GetInt(0) == TABLE_COUNT + 1) // Add one for sqlite_sequence table.
        return;     // Database seems to be intact

    LOG_RECOVERABLE << "Database corruption detected. Table count was: " << GetInt(0) << ". Rebuilding database.";
    rebuild();
}

GreeblesDatabase::~GreeblesDatabase()
{

}

GreeblesDatabase* GreeblesDatabase::GetInstance()
{
    static GreeblesDatabase instance;

    return &instance;
}

bool GreeblesDatabase::rebuild()
{
    if (!ImportFile("database/create_schema.sql"))
        return false;

    if (!ImportFile("database/initial_data_insert.sql"))
        return false;

    return true;
}